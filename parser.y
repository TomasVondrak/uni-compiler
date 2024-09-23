%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "lex.yy.c"

    #define SYMBOL_TABLE_MAX 1000
    #define RANGE_MAX_COUNT 500
    #define MAX_MESSAGES_COUNT 100
    #define MAX_MESSAGE_LENGTH 200
    #define ICG_LINE_LENGTH 1000
    #define ICG_LINE_COUNT 10000

    void yyerror(const char *s);
    int yylex();
    int yywrap();

    // symbol table

    struct symbol {
        char *id_name;
        char *datatype;
        char *type;
        int line_number;
        int array_size;
    } symbol_table[SYMBOL_TABLE_MAX];

    int count = 0;
    char datatype[20];
    extern int count_n;

    void add_to_table(char, const char *);
    void insert_datatype(const char *);
    int search(const char *);
    void print_symbol_table();
    void free_symbol_table();

    // help table to store ranges in symbol table
    int scope_symbol_array[RANGE_MAX_COUNT] = {0};
    int scope_symbol_array_top = 0;
    void new_scope();
    void end_of_scope();

    // abstract syntax tree

    struct node {
        struct node *left;
        struct node *right;
        char *token;
    };

    struct node *head;
    struct node * mknode(struct node *, struct node *, const char *);
    void print_inorder(struct node *);
    void print_tree(struct node* tree);
    void free_tree(struct node *tree);

    // semantics analysis

    char reserved_words[12][10] = {"int", "float", "char", "void", "if", "else", "while", "for", "return", "TRUE", "FALSE", "putchar"};
    int sem_errors = 0;
    char errors[MAX_MESSAGES_COUNT][MAX_MESSAGE_LENGTH];
    int sem_warnings = 0;
    char warnings[MAX_MESSAGES_COUNT][MAX_MESSAGE_LENGTH];
    int check_declaration(const char *);
    const char *get_type(const char *);
    const char *get_datatype(const char *);
    int check_types(const char *, const char *);
    int check_pointer_types(const char *, const char *, const char *);
    void check_return_datatype(const char *);
    const char *get_datatype_of_current_function();
    const char *get_id_of_current_function();
    struct node *handle_type_cast(int, struct node *, struct node *, const char *node_name);

    // intermediate code generation

    int ic_idx = 0;
    char icg[ICG_LINE_LENGTH][ICG_LINE_COUNT];
    int temp_var = 0;
    int label = 0;
    int is_for = 0;

    void print_line_to_icg(const char *);
    void print_str_to_icg(const char *);
    void new_line_to_icg();
    const char *datatype_to_icg(const char *);
    const char *pointer_to_icg_name_datatype(const char *);
    char *load_from_pointer(const char *, const char *, const char *);
    void print_icg();
    int get_array_size(const char *);
    void set_array_size(const char *, int);

%}

%union {
    struct var_name {
        char name[100];
        struct node *nd;
    } nd_obj;

    struct var_name2 {
        char name[100];
        struct node* nd;
        char datatype[20];
        char type[20];
    } nd_obj2;

    struct var_name3 {
        char name[100];
        struct node* nd;
        char if_body[10];
        char else_body[10];
        char next_body[10];
        char increment_body[10];
    } nd_obj3;

    struct var_name4 {
        char name[100];
        char icg_result[500];
        struct node* nd;
        char datatype[20];
        char type[20];
    } nd_obj4;
}

%token <nd_obj> INT FLOAT CHAR VOID RETURN FOR WHILE IF ELSE LT GT LE GE EQ NE AND OR ADD SUB DIV MUL TRUE FALSE PUTCHAR NUMBER FLOAT_NUM ID CHARACTER

%type <nd_obj> program declarations declaration function_declaration function_definition arguments_definition_section arguments_definition argument_definition datatype compound_statement block item else statement arithmetic relop return

%type <nd_obj2> init expression

%type <nd_obj3> condition

%type <nd_obj4> value argument_expression_section arguments_expression

%start program

%%

program
    : declarations {
        $$.nd = mknode(NULL, $1.nd, "program");
        head = $$.nd;
      }
    ;

declarations
    : declaration {
        $$.nd = mknode($1.nd, NULL, "declarations");
      }
    | declarations declaration {
        $$.nd = mknode($1.nd, $2.nd, "declarations");
      }
    ;

declaration
    : function_definition {
        $$.nd = $1.nd;
      }
    ;

function_definition
    : function_declaration {
        sprintf(icg[ic_idx++], " nounwind uwtable {\nentry:\n");
      } compound_statement {
        sprintf(icg[ic_idx++], "}\n");
        $$.nd = mknode($1.nd, $3.nd, "function_definition");
        end_of_scope();
      }
    ;

function_declaration
    : datatype ID {
        add_to_table('F', $2.name);
        sprintf(icg[ic_idx++], "\ndefine %s @%s", $1.name, $2.name);
      }
      '(' {
        sprintf(icg[ic_idx++], "(");
        new_scope();
      }
      arguments_definition_section ')' {
        sprintf(icg[ic_idx++], ")");
        $$.nd = mknode($1.nd, $6.nd, $2.name);
      }
    ;

arguments_definition_section
    : arguments_definition {
        $$.nd = mknode($1.nd, NULL, "arguments_definition_section");
      }
    | {
        $$.nd = mknode(NULL, NULL, "arguments_definition_section");
      }
    ;

arguments_definition
    : argument_definition {
        $$.nd = mknode($1.nd, NULL, "arguments_definition");
      }
    | arguments_definition ',' {
        sprintf(icg[ic_idx++], ", ");
      } argument_definition {
        $$.nd = mknode($1.nd, $4.nd, "arguments_definition");
      }
    ;

argument_definition
    : datatype ID {
        add_to_table('A', $2.name);
        sprintf(icg[ic_idx++], "%s %%%s", $1.name, $2.name);
        $2.nd = mknode(NULL, NULL, $2.name);
        $$.nd = mknode($1.nd, $2.nd, "argument_definition");
      }
    | datatype MUL ID {
        add_to_table('P', $3.name);
        sprintf(icg[ic_idx++], "%s* %%%s", $1.name, $3.name);
        $2.nd = mknode(NULL, NULL, $3.name);
        $$.nd = mknode($1.nd, $2.nd, "argument_definition");
      }
    ;

datatype
    : INT {
        insert_datatype(NULL);
        $$.nd = mknode(NULL, NULL, $1.name);
        strcpy($$.name, "i32");
      }
    | FLOAT {
        insert_datatype(NULL);
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | CHAR {
        insert_datatype(NULL);
        $$.nd = mknode(NULL, NULL, $1.name);
        strcpy($$.name, "i8");
      }
    | VOID {
        insert_datatype(NULL);
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    ;

compound_statement
    : '{' block '}' {
        $$.nd = $2.nd;
      }
    ;

block
    : item {
        $$.nd = mknode($1.nd, NULL, "block");
      }
    | block item {
        $$.nd = mknode($1.nd, $2.nd, "block");
      }
    ;

item
    : FOR {
        add_to_table('K', $1.name);
        new_scope();
        is_for = 1;
      } '(' statement ';' condition ';' {
        sprintf(icg[ic_idx++], "\n%s:\n", $6.increment_body);
      } statement ')' {
        sprintf(icg[ic_idx++], "\tbr label %%%s\n", $6.else_body);
        sprintf(icg[ic_idx++], "\n%s:\n", $6.if_body);
      } compound_statement {
        struct node *temp = mknode($6.nd, $9.nd, "CONDITION");
        struct node *temp2 = mknode($4.nd, temp, "CONDITION");
        $$.nd = mknode(temp2, $12.nd, $1.name);
        sprintf(icg[ic_idx++], "\tbr label %%%s\n", $6.increment_body);
        sprintf(icg[ic_idx++], "\n%s:\n", $6.next_body);
        end_of_scope();
      }
    | WHILE {
        add_to_table('K', $1.name);
        new_scope();
        is_for = 1;
      } '(' condition ')' {
        sprintf(icg[ic_idx++], "\n%s:\n", $4.if_body);
      } compound_statement {
        $$.nd = mknode($4.nd, $7.nd, $1.name);
        sprintf(icg[ic_idx++], "\tbr label %%%s\n", $4.else_body);
        sprintf(icg[ic_idx++], "\n%s:\n", $4.next_body);
        end_of_scope();
      }
    | IF {
        add_to_table('K', $1.name);
        new_scope();
        is_for = 0;
      } '(' condition ')' {
        sprintf(icg[ic_idx++], "\n%s:\n", $4.if_body);
      } compound_statement {
        sprintf(icg[ic_idx++], "\tbr label %%%s\n", $4.next_body);
        sprintf(icg[ic_idx++], "\n%s:\n", $4.else_body);
      } else {
        struct node *iff = mknode($4.nd, $7.nd, $1.name);
        $$.nd = mknode(iff, $9.nd, "if-else");
        sprintf(icg[ic_idx++], "\tbr label %%%s\n", $4.next_body);
        sprintf(icg[ic_idx++], "\n%s:\n", $4.next_body);
        end_of_scope();
      }
    | statement ';' {
        $$.nd = $1.nd;
    }
    | return {
        $$.nd = $1.nd;
      }
    ;

else
    : ELSE { add_to_table('K', $1.name); new_scope(); } compound_statement {
        $$.nd = mknode($3.nd, NULL, $1.name);
        end_of_scope();
      }
    | {
        $$.nd = NULL;
      }
    ;

condition
    : expression relop expression {
        $$.nd = mknode($1.nd, $3.nd, $2.name);
        char *loaded_var_1;
        char *loaded_var_2;
        if (is_for) {
            sprintf($$.else_body, "L%d", label++);
            sprintf(icg[ic_idx++], "\tbr label %%%s\n", $$.else_body);
            sprintf(icg[ic_idx++], "\n%s:\n", $$.else_body);
            sprintf($$.if_body, "L%d", label);
            loaded_var_1 = load_from_pointer($1.name, $1.type, $1.datatype);
            loaded_var_2 = load_from_pointer($3.name, $3.type, $3.datatype);
            sprintf(icg[ic_idx++], "\t%%t%d = icmp %s %s %s, %s\n", temp_var, $2.name, $1.datatype, loaded_var_1, loaded_var_2);
            sprintf(icg[ic_idx++], "\tbr i1 %%t%d, label %%L%d, label %%L%d\n", temp_var, label, label + 1);
            temp_var++;
            label++;
            sprintf($$.next_body, "L%d", label++);
            sprintf($$.increment_body, "L%d", label++);
        } else {
            loaded_var_1 = load_from_pointer($1.name, $1.type, $1.datatype);
            loaded_var_2 = load_from_pointer($3.name, $3.type, $3.datatype);
            sprintf(icg[ic_idx++], "\t%%t%d = icmp %s %s %s, %s\n", temp_var, $2.name, $1.datatype, loaded_var_1, loaded_var_2);
            sprintf(icg[ic_idx++], "\tbr i1 %%t%d, label %%L%d, label %%L%d\n", temp_var, label, label + 1);
            temp_var++;
            sprintf($$.if_body, "L%d", label++);
            sprintf($$.else_body, "L%d", label++);
            sprintf($$.next_body, "L%d", label++);
        }
        free(loaded_var_1);
        free(loaded_var_2);
      }
    | TRUE { add_to_table('K', $1.name);
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | FALSE { add_to_table('K', $1.name);
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    ;

statement
    : datatype ID {
        add_to_table('V', $2.name);
        sprintf(icg[ic_idx++], "\t%%%s = alloca %s\n", $2.name, $1.name);
      } init {
        $2.nd = mknode(NULL, NULL, $2.name);
        int type_exception = check_types($1.name, $4.datatype);
        if (!strcmp($4.type, "Pointer")) {
            sprintf(warnings[sem_warnings], "Line %d: assigning pointer to non-pointer variable.\n", count_n);
            sem_warnings++;
        }
        $$.nd = handle_type_cast(type_exception, $1.nd, $4.nd, "definition");
        if (strcmp($4.name, "NULL")) {
            sprintf(icg[ic_idx++], "\tstore %s %s, %s* %%%s\n", $4.datatype, $4.name, $1.name, $2.name);
        }
      }
    | datatype MUL ID {
        add_to_table('P', $3.name);
        sprintf(icg[ic_idx++], "\t%%%s = alloca %s*\n", $3.name, $1.name);
      } init {
        check_pointer_types($1.name, $5.datatype, $5.type);
        struct node *id = mknode(NULL, NULL, $3.name);
        struct node *pointer = mknode($1.nd, id, "pointer_name");
        $$.nd = mknode(pointer, $5.nd, "pointer_definition");
        if (strcmp($5.name, "NULL")) {
            sprintf(icg[ic_idx++], "\tstore %s %s, %s* %%%s\n", $5.datatype, $5.name, $1.name, $3.name);
        }
      }
    | ID { check_declaration($1.name); } '=' expression {
        $1.nd = mknode(NULL, NULL, $1.name);
        const char *id_datatype = get_datatype($1.name);
        int type_exception = check_types(id_datatype, $4.datatype);
        $$.nd = handle_type_cast(type_exception, $1.nd, $4.nd, "assignement");
        sprintf(icg[ic_idx++], "\tstore %s %s, %s* %%%s\n", get_datatype($1.name), $4.name, get_datatype($1.name), $1.name);
      }
    | MUL '(' expression ')' '=' expression {
        if (strcmp($3.type, "Pointer") || strcmp($3.datatype, $6.datatype)) {
            sprintf(warnings[sem_warnings], "Line %d: implicit cast to pointer.\n", count_n);
            sem_warnings++;
        }
        $$.nd = mknode($3.nd, $6.nd, "dereference_assignement");
        sprintf(icg[ic_idx++], "\tstore %s %s, %s** %s\n", $6.datatype, $6.name, $3.datatype, $3.name);
      }
    | ID { check_declaration($1.name); } '[' value ']' '=' expression {
    // TODO: tady všude chybí předání name, atd dovyšších pater
        const char *id_datatype = get_datatype($1.name);
        const char *id_type = get_type($1.name);
        if (strcmp(id_type, "Pointer") || strcmp(id_datatype, $7.datatype)) {
            sprintf(warnings[sem_warnings], "Line %d: implicit cast.\n", count_n);
            sem_warnings++;
        }
        struct node *dereference = mknode($1.nd, $4.nd, "dereference");
        $$.nd = mknode(dereference, $7.nd, "dereference_assignement");
        char *loaded_value = load_from_pointer($4.icg_result, $4.type, $4.datatype);
        int array_size = get_array_size($1.name);
        int new_temp_var = temp_var++;
        sprintf(icg[ic_idx++], "\t%%t%d = getelementptr inbounds [%d x %s], [%d x %s]* %%%s, %s 0, %s %s\n", new_temp_var, array_size, id_datatype, array_size, id_datatype, $1.name, $7.datatype, $7.datatype, loaded_value);
        free(loaded_value);
        char *loaded_expression = load_from_pointer($7.name, $7.type, $7.datatype);
        sprintf(icg[ic_idx++], "\tstore %s %s, %s* %%t%d\n", $7.datatype, loaded_expression, id_datatype, new_temp_var);
        free(loaded_expression);
        temp_var++;
      }
     | ID '(' argument_expression_section ')' { //TODO udělat specialní kategorii function_application a neduplikovat
        check_declaration($1.name);
        const char *id_datatype = get_datatype($1.name);
        const char *id_type = get_type($1.name);
        if (strcmp(id_type, "Function")) {
            sprintf(errors[sem_errors], "Line %d: Name \"%s\" is not a function!\n", count_n, $1.name);
            sem_errors++;
        }
        strcpy($$.name, $1.name);
        if (!strcmp(get_datatype($1.name), "void")) {
            sprintf(icg[ic_idx++], "call %s @%s(%s)", get_datatype($1.name), $1.name, $3.icg_result);
        } else {
            sprintf(icg[ic_idx++], "\t%%t%d = call %s @%s(%s)", temp_var, get_datatype($1.name), $1.name, $3.icg_result);
            temp_var++;
        }
        $$.nd = mknode($3.nd, NULL, $1.name);
      }
    | PUTCHAR { add_to_table('K', $1.name); } '(' value ')' {
        if (strcmp($4.datatype, "i8")) {
            sprintf(errors[sem_errors], "Line %d: putchar accepts char.\n", count_n);
            sem_errors++;
        }
        $$.nd = mknode($4.nd, NULL, $1.name);
        char *loaded_var = load_from_pointer($4.icg_result, $4.type, $4.datatype);
        sprintf(icg[ic_idx++], "\t%%t%d = getelementptr inbounds [2 x i8], [2 x i8]* @.special_printf_format_char, i32 0, i32 0\n", temp_var);
        sprintf(icg[ic_idx++], "\tcall i32 (i8*, ...) @printf(i8* %%t%d, i8 %s)\n", temp_var, loaded_var);
        free(loaded_var);
        temp_var++;
      }
    | datatype ID { add_to_table('P', $2.name); } '[' value ']' {
        set_array_size($2.name, atoi($5.name));
        if (strcmp($5.datatype, "i32")) {
            sprintf(errors[sem_errors], "Line %d: array position qualificator needs to be int.\n", count_n);
            sem_errors++;
        }
        if (strcmp(get_type($2.name), "Pointer")) {
            sprintf(errors[sem_errors], "Line %d: array qualificator not used to pointer. %s %s\n", count_n, get_type($2.name), "Pointer");
            sem_errors++;
        }
        struct node *id = mknode(NULL, NULL, $2.name);
        struct node *pointer = mknode($1.nd, id, "pointer_name");
        $$.nd = mknode(pointer, $5.nd, "array");
        sprintf(icg[ic_idx++], "\t%%%s = alloca [%s x %s]\n", $2.name, $5.name, $1.name);
      }
    ;

init
    : '=' expression { // TODO, zde by se to mělo loadovat ta expression, a v epxression by se to tím pádem mělo ukládat do pointru, aby dávalo smysl to loadovat, takhle to není stejné u value a epxression a pak je v tom bordel
        $$.nd = $2.nd;
        strcpy($$.type, $2.type);
        strcpy($$.datatype, $2.datatype);
        strcpy($$.name, $2.name);
      }
    | {
        $$.nd = mknode(NULL, NULL, "NULL");
        strcpy($$.type, "null");
        strcpy($$.datatype, "null");
        strcpy($$.name, "NULL");
      }
    ;

expression
    : expression arithmetic expression {
        int type_exception = check_types($1.datatype, $3.datatype);
        $$.nd = handle_type_cast(type_exception, $1.nd, $3.nd, $2.name);
        strcpy($$.type, $1.type);
        strcpy($$.datatype, $1.datatype);
        sprintf($$.name, "%%t%d", temp_var++);
        char *loaded_var_1 = load_from_pointer($1.name, $1.type, $1.datatype);
        char *loaded_var_2 = load_from_pointer($3.name, $3.type, $3.datatype);
        sprintf(icg[ic_idx++], "\t%s = %s %s %s, %s\n",  $$.name, $2.name, $1.datatype, loaded_var_1, loaded_var_2);
        free(loaded_var_1);
        free(loaded_var_2);
      }
    | value {
        $$.nd = $1.nd;
        strcpy($$.type, $1.type);
        strcpy($$.datatype, $1.datatype);
        strcpy($$.name, $1.icg_result);
      }
    ;

arithmetic
    : ADD {
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | SUB {
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | MUL {
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | DIV {
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    ;

relop
    : LT {
        $$.nd = mknode(NULL, NULL, $1.name);
        strcpy($$.name, "slt");
      }
    | GT {
        $$.nd = mknode(NULL, NULL, $1.name);
        strcpy($$.name, "sgt");
      }
    | LE {
        $$.nd = mknode(NULL, NULL, $1.name);
        strcpy($$.name, "sle");
      }
    | GE {
        $$.nd = mknode(NULL, NULL, $1.name);
        strcpy($$.name, "sge");
      }
    | EQ {
        $$.nd = mknode(NULL, NULL, $1.name);
        strcpy($$.name, "eq");
      }
    | NE {
        $$.nd = mknode(NULL, NULL, $1.name);
        strcpy($$.name, "ne");
      }
    ;

value
    : NUMBER {
        insert_datatype("i32");
        add_to_table('C', $1.name);
        $$.nd = mknode(NULL, NULL, $1.name);
        strcpy($$.name, $1.name);
        strcpy($$.icg_result, $1.name);
        strcpy($$.type, "Constant");
        strcpy($$.datatype, "i32");
      }
    | FLOAT_NUM {
        insert_datatype("float");
        add_to_table('C', $1.name);
        $$.nd = mknode(NULL, NULL, $1.name);
        strcpy($$.name, $1.name);
        strcpy($$.icg_result, $1.name);
        strcpy($$.type, "Constant");
        strcpy($$.datatype, "float");
      }
    | CHARACTER {
        insert_datatype("i8");
        add_to_table('C', $1.name);
        $$.nd = mknode(NULL, NULL, $1.name);
        strcpy($$.name, $1.name);
        sprintf($$.icg_result, "%d", (int) $1.name[1]);
        strcpy($$.type, "Constant");
        strcpy($$.datatype, "i8");
      }
    | ID {
        check_declaration($1.name);
        const char *id_datatype = get_datatype($1.name);
        strcpy($$.datatype, id_datatype);
        const char *id_type = get_type($1.name);
        strcpy($$.type, id_type);
        strcpy($$.name, $1.name);
        strcpy($$.icg_result, "%");
        strcat($$.icg_result, $1.name);
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | ID '(' argument_expression_section ')' {
        check_declaration($1.name);
        const char *id_datatype = get_datatype($1.name);
        strcpy($$.datatype, id_datatype);
        const char *id_type = get_type($1.name);
        if (strcmp(id_type, "Function")) {
            sprintf(errors[sem_errors], "Line %d: Name \"%s\" is not a function!\n", count_n, $1.name);
            sem_errors++;
        }
        strcpy($$.type, id_type);
        strcpy($$.name, $1.name);
        if (!strcmp(get_datatype($1.name), "void")) {
            sprintf(icg[ic_idx++], "call %s @%s(%s)", get_datatype($1.name), $1.name, $3.icg_result);
            strcpy($$.icg_result, "");
        } else {
            sprintf(icg[ic_idx++], "\t%%t%d = call %s @%s(%s)", temp_var, get_datatype($1.name), $1.name, $3.icg_result);
            sprintf($$.icg_result, "%%t%d", temp_var);
            temp_var++;
        }
        $$.nd = mknode($3.nd, NULL, $1.name);
      }
    | '&' ID {
        strcpy($$.name, $2.name);
        strcpy($$.icg_result, "* %");
        strcat($$.icg_result, $2.name);
        const char *id_datatype = get_datatype($2.name);
        strcpy($$.datatype, id_datatype);
        strcpy($$.type, "Pointer");
        check_declaration($2.name);
        struct node *id = mknode(NULL, NULL, $2.name);
        $$.nd = mknode(id, NULL, "address");
      }
    | MUL '(' expression ')' {
        strcpy($$.name, $3.name);
        char *loaded_var = load_from_pointer($3.name, $3.type, $3.datatype);
        sprintf($$.icg_result, "%s", loaded_var);
        free(loaded_var);

        strcpy($$.datatype, $3.datatype);
        strcpy($$.type, "Variable");
        $$.nd = mknode($3.nd, NULL, "dereference");
      }
    | ID '[' value ']' {
        check_declaration($1.name);
        // check id
        const char *id_datatype = get_datatype($1.name);
        const char *id_type = get_type($1.name);
        if (strcmp(id_type, "Pointer")) {
            sprintf(errors[sem_errors], "Line %d: Name \"%s\" is not a pointer!\n", count_n, $1.name);
            sem_errors++;
        }
        int array_size = get_array_size($1.name);
        // check value TODO
        const char *value_datatype = get_datatype($3.name);
        const char *value_type = get_type($3.name);
        // get pointer to array field
        char *loaded_value = load_from_pointer($3.icg_result, $3.type, $3.datatype);
        sprintf(icg[ic_idx++], "\t%%t%d = getelementptr inbounds [%d x %s], [%d x %s]* %%%s, %s 0, %s %s\n", temp_var, array_size, id_datatype, array_size, id_datatype, $1.name, value_datatype, value_datatype, loaded_value);
        free(loaded_value);
        // load
        char new_ptr[5];
        sprintf(new_ptr, "%%t%d", temp_var);
         temp_var++;
        sprintf(icg[ic_idx++], "\t%%t%d = load %s, %s* %s\n", temp_var, id_datatype, id_datatype, new_ptr);
        // set node vars
        sprintf($$.icg_result, "%%t%d", temp_var);
        sprintf($$.name, "t%d", temp_var);
        strcpy($$.type, "Pointer");
        strcpy($$.datatype, id_datatype);
        temp_var++;
        $$.nd = mknode($3.nd, NULL, "array_dereference");
      }
    | SUB value {
        if (strcmp($2.datatype, "i32") && strcmp($2.datatype, "float")) {
            sprintf(errors[sem_errors], "Line %d: unary minus on non number type\n", count_n);
            sem_errors++;
        }
        strcpy($$.datatype, $2.datatype);
        strcpy($$.type, $2.type);
        $$.nd = mknode($2.nd, NULL, "unary_minus");
        sprintf($$.name, "t%d", temp_var);
        sprintf($$.icg_result, "%%t%d", temp_var++);
        char *loaded_var = load_from_pointer($2.icg_result, $2.type, $2.datatype);
        sprintf(icg[ic_idx++], "\t%s = sub %s 0, %s\n", $$.icg_result, $2.datatype, loaded_var);
        free(loaded_var);
      }
    ;

argument_expression_section
    : arguments_expression {
        $$.nd = $1.nd;
        strcpy($$.icg_result, $1.icg_result);
      }
    | {
        $$.nd = NULL;
        strcpy($$.icg_result, "");
      }
    ;

arguments_expression
    : value {
        $$.nd = mknode($1.nd, NULL, "arguments_expression");
        char *loaded_var = load_from_pointer($1.icg_result, $1.type, $1.datatype);
        sprintf($$.icg_result, "%s %s", $1.datatype, loaded_var);
        free(loaded_var);
      }
    | arguments_expression ',' value {
        $$.nd = mknode($1.nd, $3.nd, "arguments_expression");
        char *loaded_var = load_from_pointer($3.icg_result, $3.type, $3.datatype);
        sprintf($$.icg_result, "%s, %s %s", $1.icg_result, $3.datatype, loaded_var);
        free(loaded_var);
      }
    ;

return
    : RETURN { add_to_table('K', "return"); } value ';' {
        check_return_datatype($3.name);
        $1.nd = mknode(NULL, NULL, "return");
        $$.nd = mknode($1.nd, $3.nd, "RETURN");
        sprintf(icg[ic_idx++], "\tret %s %s\n",  $3.datatype, $3.icg_result);
      }
    | RETURN { add_to_table('K', "return"); } ';' {
        $$.nd = mknode(NULL, NULL, "RETURN");
        sprintf(icg[ic_idx++], "\tret void\n");
      }
    ;

%%

int check_declaration(const char *name) {
    if (search(name)) return 0;
    sprintf(errors[sem_errors], "Line %d: Name \"%s\" not declared before usage!\n", count_n, name);
    sem_errors++;
    return 1;
}

const char *get_type(const char *var) {
  for (int i = 0; i < count; i++) {
      if (!strcmp(symbol_table[i].id_name, var)) {
          return symbol_table[i].type;
      }
  }
  return "null";
}

const char *get_datatype(const char *var) {
  for (int i = 0; i < count; i++) {
      if (!strcmp(symbol_table[i].id_name, var)) {
          return symbol_table[i].datatype;
      }
  }
  return "null";
}

int check_types(const char *type1, const char *type2) {
    // declaration with no init
    if (!strcmp(type2, "null"))
        return -1;
    // both datatypes are same
    if (!strcmp(type1, type2))
        return 0;
    // both datatypes are different
    if (!strcmp(type1, "i32") && !strcmp(type2, "float"))
        return 1;
    if (!strcmp(type1, "float") && !strcmp(type2, "i32"))
        return 2;
    if (!strcmp(type1, "i32") && !strcmp(type2, "i8"))
        return 3;
    if (!strcmp(type1, "i8") && !strcmp(type2, "i32"))
        return 4;
    if (!strcmp(type1, "float") && !strcmp(type2, "i8"))
        return 5;
    if (!strcmp(type1, "i8") && !strcmp(type2, "float"))
        return 6;
    return -2;
}

struct node *handle_type_cast(int type_exception, struct node *left, struct node *right, const char *node_name) {
    if (type_exception > 0) {
        struct node *temp;
        switch (type_exception) {
            case 1:
                sprintf(warnings[sem_warnings], "Line %d: implicit float to int cast\n", count_n);
                temp = mknode(NULL, right, "floattoint");
                break;
            case 2:
                sprintf(warnings[sem_warnings], "Line %d: implicit int to float cast\n", count_n);
                temp = mknode(NULL, right, "inttofloat");
                break;
            case 3:
                sprintf(warnings[sem_warnings], "Line %d: implicit char to int cast\n", count_n);
                temp = mknode(NULL, right, "chartoint");
                break;
            case 4:
                sprintf(warnings[sem_warnings], "Line %d: implicit int to char cast\n", count_n);
                temp = mknode(NULL, right, "inttochar");
                break;
            case 5:
                sprintf(warnings[sem_warnings], "Line %d: implicit char to float cast\n", count_n);
                temp = mknode(NULL, right, "chartofloat");
                break;
            default:
                sprintf(warnings[sem_warnings], "Line %d: implicit float to char cast. %s %s\n", count_n, left->token, right->token);
                temp = mknode(NULL, right, "floattochar");
                break;
        }
        sem_warnings++;
        return mknode(left, temp, node_name);
    }
    return mknode(left, right, node_name);
}

int check_pointer_types(const char *datatype1,
                        const char *datatype2,
                        const char *type2) {
    // declaration with no init
    if (!strcmp(datatype2, "null"))
        return -1;
    // both datatypes are correct
    if ((!strcmp(type2, "Pointer") && !strcmp(datatype1, datatype2)) || (!strcmp(type2, "Constant") && !strcmp("i32", datatype2)))
        return 0;
    // both datatypes are different
    sprintf(errors[sem_errors], "Line %d: attempt to init pointer type with something else then pointer variable with correct type or address.\n", count_n);
    sem_errors++;
    return 1;
}

const char *get_datatype_of_current_function() {
    for (int i = count-1; i >= 0; i--) {
        if (!strcmp(symbol_table[i].type, "Function")) {
            return symbol_table[i].datatype;
        }
    }
}

const char *get_id_of_current_function() {
    for (int i = count - 1; i >= 0; i--) {
        if (!strcmp(symbol_table[i].type, "Function")) {
            return symbol_table[i].id_name;
        }
    }
}

void set_array_size(const char *name, int size) {
    for (int i = count - 1; i >= 0; i--) {
        if (!strcmp(symbol_table[i].id_name, name)) {
            symbol_table[i].array_size = size;
            return;
        }
    }
}

int get_array_size(const char *name) {
    for (int i = count - 1; i >= 0; i--) {
        if (!strcmp(symbol_table[i].id_name, name)) {
            return symbol_table[i].array_size;
        }
    }
}

void check_return_datatype(const char *value) {
    const char *func_datatype = get_datatype_of_current_function();
    const char *return_datatype = get_datatype(value);
    if (strcmp(func_datatype, return_datatype)) {
        sprintf(errors[sem_errors], "Line %d: Return type mismatch\n", count_n);
		sem_errors++;
    }
}

void new_scope() {
    scope_symbol_array[scope_symbol_array_top] = count;
    scope_symbol_array_top++;
}

void end_of_scope() {
    scope_symbol_array_top--;
    int new_count = scope_symbol_array[scope_symbol_array_top];
    for (int i = count - 1; i >= new_count; i--) {
        free(symbol_table[i].id_name);
		free(symbol_table[i].type);
    }
    count = new_count;
}

struct node *mknode(struct node *left, struct node *right, const char *token) {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    char *newstr = (char *) malloc(strlen(token) + 1);
    strcpy(newstr, token);
    newnode->left = left;
    newnode->right = right;
    newnode->token = newstr;
    return(newnode);
}

void print_tree(struct node* tree) {
    printf("\n\nInorder traversal of the Parse Tree is: \n\n");
    print_inorder(tree);
    printf("KONEC\n");
}

void print_inorder(struct node *tree) {
    int i;
    if (tree->left) {
        print_inorder(tree->left);
    }
    printf("%s, ", tree->token);
    if (tree->right) {
        print_inorder(tree->right);
    }
}

void insert_datatype(const char *const_datatype) {
        if (!const_datatype) {
            char temp[5];
            strcpy(temp, yytext);
            if (!strcmp(yytext, "int")) strcpy(temp, "i32");
            if (!strcmp(yytext, "char")) strcpy(temp, "i8");
            strcpy(datatype, temp);
        } else {
            strcpy(datatype, const_datatype);
        }
}

int search(const char *name) {
    for (int i = count - 1; i >= 0; i--) {
        if (strcmp(symbol_table[i].id_name, name) == 0) {
            return -1;
            break;
        }
    }
    return 0;
}

void add_to_table(char symbol, const char *id_name) {
    print_symbol_table();
    if (search(id_name)) return;
    symbol_table[count].id_name = strdup(id_name);
    symbol_table[count].line_number = count_n;
    symbol_table[count].array_size = 0;
    switch (symbol) {
        case 'K':
            symbol_table[count].datatype = strdup("N/A");
            symbol_table[count].type = strdup("Keyword");
            break;
        case 'V':
            symbol_table[count].datatype = strdup(datatype);
            symbol_table[count].type = strdup("Variable");
            break;
        case 'C':
            symbol_table[count].datatype = strdup(datatype);
            symbol_table[count].type = strdup("Constant");
            break;
        case 'F':
            symbol_table[count].datatype = strdup(datatype);
            symbol_table[count].type = strdup("Function");
            break;
        case 'P':
            symbol_table[count].datatype = strdup(datatype);
            symbol_table[count].type = strdup("Pointer");
            symbol_table[count].array_size = 1;
            break;
        case 'A':
            symbol_table[count].datatype = strdup(datatype);
            symbol_table[count].type = strdup("Argument");
            break;
        default:
            yyerror("bad symbol");
            return;
    }
    count++;
}

void print_icg() {
    for (int i = 0; i <= ic_idx; i++) {
        printf("%s", icg[i]);
    }
}

void print_icg_in_file() {
    FILE *f = fopen("o.ll", "w");
    for (int i = 0; i <= ic_idx; i++) {
        fprintf(f, "%s", icg[i]);
    }
    fclose(f);
}

char *load_from_pointer(const char *var_name, const char *type, const char *datatype) {
    char *new_var = malloc (sizeof (char) * 5);
    if (!strcmp("Variable", type) || !strcmp("Pointer", type)) {
        sprintf(new_var, "%%t%d", temp_var);
        temp_var++;
        sprintf(icg[ic_idx++], "\t%s = load %s, %s* %s\n", new_var, datatype, datatype, var_name);
        return new_var;
    }
    sprintf(new_var, "%s", var_name);
    return new_var;
}

void print_symbol_table() {
    printf("\nSYMBOL\t\t\t\tDATATYPE\t\t\tTYPE\t\t\tARRAY_SIZE\t\t\tLINE NUMBER \n");
    printf("_________________________________________________________________________________________________________________________________\n\n");

	for(int i = 0; i < count; i++) {
		printf("%s\t\t\t\t%s\t\t\t%s\t\t\t%d\t\t\t%d\t\t\t\n", symbol_table[i].id_name, symbol_table[i].datatype, symbol_table[i].type, symbol_table[i].array_size, symbol_table[i].line_number);
	}

	printf("\n");
}

void free_symbol_table() {
    for(int i = 0; i < count; i++) {
        free(symbol_table[i].id_name);
        free(symbol_table[i].type);
    }
}

void free_tree(struct node *tree) {
    if (tree->left) {
        free_tree(tree->left);
        free(tree->left);
    }
    if (tree->right) {
        free_tree(tree->right);
        free(tree->right);
    }
    free(tree->token);
}

int main() {
    sprintf(icg[ic_idx++], "declare i32 @printf(i8*, ...)\n");
    sprintf(icg[ic_idx++], "@.special_printf_format_char = constant [2 x i8] c\"%%c\"\n");
    yyparse();
    printf("\n\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
    print_symbol_table();
    printf("\n\t\t\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
    print_tree(head);
    free_symbol_table();
    free_tree(head);
    free(head);
    printf("\n\t\t\t\t\t\t\t\t PHASE 3: SEMANTIC ANALYSIS \n");
	if(sem_errors > 0) {
		printf("Semantic analysis completed with %d errors\n", sem_errors);
		for(int i = 0; i < sem_errors; i++){
			printf("\t - %s", errors[i]);
		}
	} else {
		printf("Semantic analysis completed with no errors");
	}
	printf("\n\n");
	if(sem_warnings > 0) {
		printf("Semantic analysis completed with %d warnings\n", sem_warnings);
		for(int i = 0; i < sem_warnings; i++){
			printf("\t - %s", warnings[i]);
		}
	} else {
		printf("Semantic analysis completed with no warnings");
	}
	printf("\n\n");
	printf("\n\t\t\t\t\t\t\t\t PHASE 4: INTERMEDIATE CODE GENERATION \n");
	printf("\n");
	// print_icg();
	print_icg_in_file();
	printf("\n");
}

void yyerror(const char *msg) {
    fprintf(stderr, "line %d: %s, %s\n", count_n, yytext, msg);
}
