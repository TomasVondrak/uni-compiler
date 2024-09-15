%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "lex.yy.c"

    #define SYMBOL_TABLE_MAX 100
    #define RANGE_MAX_COUNT 50
    #define MAX_MESSAGES_COUNT 50
    #define MAX_MESSAGE_LENGTH 200
    #define ICG_LINE_LENGTH 200
    #define ICG_LINE_COUNT 300

    void yyerror(const char *s);
    int yylex();
    int yywrap();

    // symbol table

    struct symbol {
        char *id_name;
        char *datatype;
        char *type;
        int line_number;
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
    void print_line_to_icg(const char *);
    void print_str_to_icg(const char *);
    void new_line_to_icg();
    const char *datatype_to_icg(const char *);
    const char *pointer_to_icg_name_datatype(const char *);

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
        char icg_local[10000];
    } nd_obj2;

    struct var_name3 {
        char name[100];
        struct node* nd;
        char icg_local[10000];
    } nd_obj3;
}

%token <nd_obj> INT FLOAT CHAR VOID RETURN FOR WHILE IF ELSE LT GT LE GE EQ NE AND OR ADD SUB DIV MUL TRUE FALSE PUTCHAR NUMBER FLOAT_NUM ID CHARACTER

%type <nd_obj> program declarations declaration function_declaration function_definition arguments_definition_section arguments_definition argument_definition datatype

%type <nd_obj2> init value expression

%type <nd_obj3> compound_statement block item else condition statement arithmetic relop argument_expression_section arguments_expression return

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
    : function_declaration {print_str_to_icg(" nounwind uwtable {"); new_line_to_icg(); print_line_to_icg("entry:"); } compound_statement {
        printf("%s", $3.icg_local);
        print_line_to_icg("}\n");
        end_of_scope();
        $$.nd = mknode($1.nd, $3.nd, "function_definition");
      }
    ;

function_declaration
    : datatype ID {
        add_to_table('F', $2.name);
        print_str_to_icg("define ");
        print_str_to_icg(pointer_to_icg_name_datatype($2.name);
        print_str_to_icg(" @");
        print_str_to_icg($2.name);
      }
      '(' {
        print_str_to_icg("(");
        new_scope();
      }
      arguments_definition_section ')' {
        print_str_to_icg(")");
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
    | arguments_definition ',' { print_str_to_icg(", "); } argument_definition {
        $$.nd = mknode($1.nd, $4.nd, "arguments_definition");
      }
    ;

argument_definition
    : datatype ID {
        print_str_to_icg(pointer_to_icg_name_datatype($2.name));
        print_str_to_icg(" %");
        print_str_to_icg($2.name);
        add_to_table('V', $2.name);
        $2.nd = mknode(NULL, NULL, $2.name);
        $$.nd = mknode($1.nd, $2.nd, "argument_definition");
      }
    ;

datatype
    : INT {
        insert_datatype(NULL);
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | FLOAT {
        insert_datatype(NULL);
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | CHAR {
        insert_datatype(NULL);
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | VOID {
        insert_datatype(NULL);
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    ;

compound_statement
    : '{' block '}' {
        $$.nd = $2.nd;
        $$.icg_local = $2.icg_local;
      }
    ;

block
    : item {
        $$.nd = mknode($1.nd, NULL, "block");
        strcat($$.icg_local, $1.icg_local);
      }
    | block item {
        $$.nd = mknode($1.nd, $2.nd, "block");
        strcat($$.icg_local, $1.icg_local);
        strcat($$.icg_local, $2.icg_local);
      }
    ;

item
    : FOR { add_to_table('K', $1.name); new_scope(); } '(' statement ';' condition ';' statement ')' compound_statement {
        struct node *temp = mknode($6.nd, $8.nd, "CONDITION");
        struct node *temp2 = mknode($4.nd, temp, "CONDITION");
        $$.nd = mknode(temp2, $10.nd, $1.name);
        end_of_scope();
      }
    | WHILE { add_to_table('K', $1.name); new_scope(); } '(' condition ')' compound_statement {
        $$.nd = mknode($4.nd, $6.nd, $1.name);
        end_of_scope();
      }
    | IF { add_to_table('K', $1.name); new_scope(); } '(' condition ')' compound_statement else {
        struct node *iff = mknode($4.nd, $6.nd, $1.name);
        $$.nd = mknode(iff, $7.nd, "if-else");
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
    : expression relop expression { // TODO: dodělat kontrolu a and, or
        $$.nd = mknode($1.nd, $3.nd, $2.name);
        strcat($$.icg_local, $1.icg_local);
        strcat($$.icg_local, $2.name);
        strcat($$.icg_local, $3.icg_local);
      }
    | TRUE { add_to_table('K', $1.name);
        $$.nd = mknode(NULL, NULL, $1.name);
        strcat($$.icg_local, "True");
      }
    | FALSE { add_to_table('K', $1.name);
        $$.nd = mknode(NULL, NULL, $1.name);
        strcat($$.icg_local, "False");
      }
    ;

statement
    : datatype ID { add_to_table('V', $2.name); } init {
        $2.nd = mknode(NULL, NULL, $2.name);
        int type_exception = check_types($1.name, $4.datatype);
        if (!strcmp($4.type, "Pointer")) {
            sprintf(warnings[sem_warnings], "Line %d: assigning pointer to non-pointer variable.\n", count_n);
            sem_warnings++;
        }
        $$.nd = handle_type_cast(type_exception, $1.nd, $4.nd, "definition");

        const char *init_icg = "";
        if (!strcmp($4.name, "NULL")) {
            sprintf(init_icg, "store %s %s, %s %s.addr", pointer_to_icg_name_datatype($4.name), $4.name, $1.name, $2.name);
        }
        const char *temp;
        sprintf(temp, "\%%s.addr = alloca %s\n\t%s", $2.name, $1.name, init_icg);
        strcat($$.icg_local, temp);
      }
    | datatype MUL ID { add_to_table('P', $3.name); } init {
        check_pointer_types($1.name, $5.datatype, $5.type);
        struct node *id = mknode(NULL, NULL, $3.name);
        struct node *pointer = mknode($1.nd, id, "pointer_name");
        $$.nd = mknode(pointer, $5.nd, "pointer_definition");
      }
    | ID { check_declaration($1.name); } '=' expression {
        $1.nd = mknode(NULL, NULL, $1.name);
        const char *id_datatype = get_datatype($1.name);
        int type_exception = check_types(id_datatype, $4.datatype);
        $$.nd = handle_type_cast(type_exception, $1.nd, $4.nd, "assignement");
      }
    | MUL '(' expression ')' '=' expression {
        if (strcmp($3.type, "Pointer") || strcmp($3.datatype, $6.datatype)) {
            sprintf(warnings[sem_warnings], "Line %d: implicit cast to pointer.\n", count_n);
            sem_warnings++;
        }
        $$.nd = mknode($3.nd, $6.nd, "dereference_assignement");
      }
    | expression {
        $$.nd = $1.nd;
      }
    | PUTCHAR { add_to_table('K', $1.name); } '(' value ')' {
        if (strcmp($4.datatype, "char")) {
            sprintf(errors[sem_errors], "Line %d: putchar accepts char. %s %s\n", count_n, $4.datatype, "char");
            sem_errors++;
        }
        $$.nd = mknode($4.nd, NULL, $1.name);
      }
    | datatype ID { add_to_table('P', $2.name); } '[' value ']' {
        if (strcmp($5.datatype, "int")) {
            sprintf(errors[sem_errors], "Line %d: array position qualificator needs to be int. %s %s\n", count_n, $5.datatype, "int");
            sem_errors++;
        }
        if (strcmp(get_type($2.name), "Pointer")) {
            sprintf(errors[sem_errors], "Line %d: array qualificator not used to pointer. %s %s\n", count_n, get_type($2.name), "Pointer");
            sem_errors++;
        }
        struct node *id = mknode(NULL, NULL, $2.name);
        struct node *pointer = mknode($1.nd, id, "pointer_name");
        $$.nd = mknode(pointer, $5.nd, "array");
      }
    ;

init
    : '=' expression {
        $$.nd = $2.nd;
        strcpy($$.type, $2.type);
        strcpy($$.datatype, $2.datatype);
        strcpy($$.name, $2.name);
        strcat($$.icg_local, $2.icg_local);
      }
    | {
        $$.nd = mknode(NULL, NULL, "NULL");
        strcpy($$.type, "null");
        strcpy($$.datatype, "null");
        strcpy($$.name, "NULL");
        strcpy($$.icg_local, "");
      }
    ;

expression
    : expression arithmetic expression {
        int type_exception = check_types($1.datatype, $3.datatype);
        $$.nd = handle_type_cast(type_exception, $1.nd, $3.nd, $2.name);
        strcpy($$.type, $1.type);
        strcpy($$.datatype, $1.datatype);
      }
    | '(' expression ')' {
        $$.nd = $2.nd;
        strcpy($$.type, $2.type);
        strcpy($$.datatype, $2.datatype);
        strcpy($$.name, $2.name);
      }
    | value {
        $$.nd = $1.nd;
        strcpy($$.type, $1.type);
        strcpy($$.datatype, $1.datatype);
        strcpy($$.name, $1.name);
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
      }
    | GT {
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | LE {
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | GE {
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | EQ {
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | NE {
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    ;

value
    : NUMBER {
        insert_datatype("int");
        add_to_table('C', $1.name);
        $$.nd = mknode(NULL, NULL, $1.name);
        strcpy($$.name, $1.name);
        strcpy($$.type, "Constant");
        strcpy($$.datatype, "int");
      }
    | FLOAT_NUM {
        insert_datatype("float");
        add_to_table('C', $1.name);
        $$.nd = mknode(NULL, NULL, $1.name);
        strcpy($$.name, $1.name);
        strcpy($$.type, "Constant");
        strcpy($$.datatype, "float");
      }
    | CHARACTER {
        insert_datatype("char");
        add_to_table('C', $1.name);
        $$.nd = mknode(NULL, NULL, $1.name);
        strcpy($$.name, $1.name);
        strcpy($$.type, "Constant");
        strcpy($$.datatype, "char");
      }
    | ID {
        check_declaration($1.name);
        const char *id_datatype = get_datatype($1.name);
        strcpy($$.datatype, id_datatype);
        const char *id_type = get_type($1.name);
        strcpy($$.type, id_type);
        strcpy($$.name, $1.name);
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | ID '(' argument_expression_section ')' { // TODO: semantická analýza jestli jsou správný argumenty podle definice
        check_declaration($1.name);
        const char *id_datatype = get_datatype($1.name);
        strcpy($$.datatype, id_datatype);
        const char *id_type = get_type($1.name);
        strcpy($$.type, id_type);
        strcpy($$.name, $1.name);
        $$.nd = mknode($3.nd, NULL, $1.name);
      }
    | '&' ID {
        strcpy($$.name, $2.name);
        const char *id_datatype = get_datatype($2.name);
        strcpy($$.datatype, id_datatype);
        strcpy($$.type, "Pointer");
        check_declaration($2.name);
        struct node *id = mknode(NULL, NULL, $2.name);
        $$.nd = mknode(id, NULL, "address");
      }
    | MUL '(' expression ')' { // insert type, co je na adrese expression ? ale jak to udělat - nutnost mít nějakou tabulku s tím co je na nějaké adrese - teď bude asi každej pointer na int zjednodušeně
        strcpy($$.name, $1.name);
        strcpy($$.datatype, $3.datatype);
        strcpy($$.type, "Variable");
        $$.nd = mknode($3.nd, NULL, "dereference");
      }
    | SUB value {
        if (strcmp($2.datatype, "int") && strcmp($2.datatype, "float")) {
            sprintf(errors[sem_errors], "Line %d: unary minus on non number type\n", count_n);
            sem_errors++;
        }
        strcpy($$.datatype, $2.datatype);
        strcpy($$.type, $2.type);
        $$.nd = mknode($2.nd, NULL, "unary_minus");
      }
    ;

argument_expression_section
    : arguments_expression {
        $$.nd = $1.nd;
      }
    | {
        $$.nd = NULL;
      }
    ;

arguments_expression
    : value {
        $$.nd = mknode($1.nd, NULL, "arguments_expression");
      }
    | arguments_expression ',' value {
        $$.nd = mknode($1.nd, $3.nd, "arguments_expression");
      }
    ;

return
    : RETURN { add_to_table('K', "return"); } value ';' {
        check_return_datatype($3.name);
        $1.nd = mknode(NULL, NULL, "return");
        $$.nd = mknode($1.nd, $3.nd, "RETURN");
      }
    | RETURN { add_to_table('K', "return"); } ';' {
        $$.nd = mknode(NULL, NULL, "RETURN");
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
    if (!strcmp(type1, "int") && !strcmp(type2, "float"))
        return 1;
    if (!strcmp(type1, "float") && !strcmp(type2, "int"))
        return 2;
    if (!strcmp(type1, "int") && !strcmp(type2, "char"))
        return 3;
    if (!strcmp(type1, "char") && !strcmp(type2, "int"))
        return 4;
    if (!strcmp(type1, "float") && !strcmp(type2, "char"))
        return 5;
    if (!strcmp(type1, "char") && !strcmp(type2, "float"))
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
    if ((!strcmp(type2, "Pointer") && !strcmp(datatype1, datatype2)) || (!strcmp(type2, "Constant") && !strcmp("int", datatype2)))
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
    for (int i = count-1; i >= 0; i--) {
        if (!strcmp(symbol_table[i].type, "Function")) {
            return symbol_table[i].id_name;
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
            strcpy(datatype, yytext);
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
            break;
        default:
            yyerror("bad symbol");
            return;
    }
    count++;
}

void print_line_to_icg(const char *line) {
    strcpy(icg[ic_idx], line);
    ic_idx++;
}

void print_str_to_icg(const char *str) {
    strcat(icg[ic_idx], str);
}

void new_line_to_icg() {
    ic_idx++;
}

void print_icg() {
    for (int i = 0; i <= ic_idx; i++) {
        printf("%s\n", icg[i]);
    }
}

const char *pointer_to_icg_name_datatype(const char *name) {
    const char *type = get_type(name);
    const char *datatype[10];
    strcat(datatype, get_datatype(name));
    if (!strcmp(type, "Pointer")) {
        strcat(datatype, "*");
    }
    return datatype;
}

void print_symbol_table() {
    printf("\nSYMBOL\t\t\tDATATYPE\t\tTYPE\t\t\tLINE NUMBER \n");
    printf("____________________________________________________________________________________________\n\n");

	for(int i = 0; i < count; i++) {
		printf("%s\t\t\t%s\t\t\t%s\t\t\t%d\t\t\t\n", symbol_table[i].id_name, symbol_table[i].datatype, symbol_table[i].type, symbol_table[i].line_number);
	}

	printf("\n");
}

void free_symbol_table() {
  for(int i = 0; i < count; i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
}

int main() {
    yyparse();
    printf("\n\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
    print_symbol_table();
    printf("\n\t\t\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
    print_tree(head);
    free_symbol_table();
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
	print_icg();
	printf("\n");
}

void yyerror(const char *msg) {
    fprintf(stderr, "%s\n", msg);
}
