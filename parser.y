%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "lex.yy.c"

    #define SYMBOL_TABLE_MAX 100
    #define RANGE_MAX_COUNT 50

    void yyerror(const char *s);
    int yylex();
    int yywrap();

    // symbol table

    struct symbol {
        char * id_name;
        char * data_type;
        char * type;
        int line_number;
    } symbol_table[SYMBOL_TABLE_MAX]; // dynamically store later

    int count = 0;
    char type[10];
    extern int count_n;

    void add_to_table(char, const char *);
    void insert_type();
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
    struct node * mknode(struct node *, struct node *, char *);
    void printInorder(struct node *);

    // semantics analysis

    void check_declaration(const char *name, const char *datatype, const char *type);
    char *get_type(const char *var);
    int check_types(const char *type1, const char *type2);
    void check_return_type(const char *defined_return_type, const char *real_return_type);


%}

%union {
    struct var_name {
        char name[100];
        struct node *nd;
    } nd_obj;
}

%token <nd_obj> INT FLOAT CHAR VOID RETURN FOR WHILE IF ELSE LT GT LE GE EQ NE AND OR ADD SUB DIV MUL TRUE FALSE PUTCHAR NUMBER FLOAT_NUM ID CHARACTER

%type <nd_obj> program declarations declaration function_declaration function_definition arguments_definition_section arguments_definition argument_definition datatype compound_statement block item else condition statement init expression arithmetic relop value argument_expression_section arguments_expression return

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
    : function_declaration compound_statement {
        end_of_scope();
        $$.nd = mknode($1.nd, $2.nd, "function_definition");
      }
    ;

function_declaration
    : datatype ID { add_to_table('F', $2.name); } '(' { new_scope(); } arguments_definition_section ')' {
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
    | arguments_definition ',' argument_definition {
        $$.nd = mknode($1.nd, $3.nd, "arguments_definition");
      }
    ;

argument_definition
    : datatype ID {
        add_to_table('V', $2.name);
        $2.nd = mknode(NULL, NULL, $2.name);
        $$.nd = mknode($1.nd, $2.nd, "argument_definition");
      }
    ;

datatype
    : INT {
        insert_type();
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | FLOAT {
        insert_type();
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | CHAR {
        insert_type();
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | VOID {
        insert_type();
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
    : FOR { add_to_table('K', $1.name); } '(' statement ';' condition ';' statement ')' compound_statement {
        struct node *temp = mknode($6.nd, $8.nd, "CONDITION");
        struct node *temp2 = mknode($4.nd, temp, "CONDITION");
        $$.nd = mknode(temp2, $10.nd, $1.name);
      }
    | WHILE { add_to_table('K', $1.name); } '(' condition ')' compound_statement {
        $$.nd = mknode($4.nd, $6.nd, $1.name);
      }
    | IF { add_to_table('K', $1.name); } '(' condition ')' compound_statement else {
        struct node *iff = mknode($4.nd, $6.nd, $1.name);
        $$.nd = mknode(iff, $7.nd, "if-else");
      }
    | statement ';' {
        $$.nd = $1.nd;
    }
    | return {
        $$.nd = $1.nd;
      }
    ;

else
    : ELSE { add_to_table('K', $1.name); } compound_statement {
        $$.nd = mknode($3.nd, NULL, $1.name);
      }
    | {
        $$.nd = NULL;
      }
    ;

condition
    : expression relop expression {
        $$.nd = mknode($1.nd, $3.nd, $2.name);
      }
    | TRUE { add_to_table('K', $1.name);
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | FALSE { add_to_table('K', $1.name);
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    ;

statement
    : datatype ID { add_to_table('V', $2.name); } init {
        $$.nd = mknode($2.nd, $4.nd, $2.name);
      }
    | datatype MUL ID { add_to_table('P', $3.name); } init {
        struct node *id = mknode(NULL, NULL, $3.name);
        struct node *pointer = mknode($1.nd, id, "pointer_name");
        $$.nd = mknode(pointer, $5.nd, "pointer_definition");
      }
    | ID '=' expression {
        $$.nd = mknode($1.nd, $3.nd, "assignement");
      }
    | MUL '(' expression ')' '=' expression {
        $$.nd = mknode($3.nd, $6.nd, "dereference_assignement");
      }
    | expression {
        $$.nd = $1.nd;
      }
    | PUTCHAR { add_to_table('K', $1.name); } '(' value ')' {
        $$.nd = mknode($4.nd, NULL, $1.name);
      }
    | datatype ID { add_to_table('P', $2.name); } '[' value ']' {
        struct node *id = mknode(NULL, NULL, $2.name);
        struct node *pointer = mknode($1.nd, id, "pointer_name");
        $$.nd = mknode(pointer, $5.nd, "array");
      }
    ;

init
    : '=' expression {
        $$.nd = $2.nd;
      }
    | {
        $$.nd = mknode(NULL, NULL, "NULL");
      }
    ;

expression
    : expression arithmetic expression {
        $$.nd = mknode($1.nd, $3.nd, $2.name);
      }
    | '(' expression ')' {
        $$.nd = $2.nd;
      }
    | value {
        $$.nd = $1.nd;
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
        add_to_table('C', $1.name);
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | FLOAT_NUM {
        add_to_table('C', $1.name);
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | CHARACTER {
        add_to_table('C', $1.name);
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | ID {
        $$.nd = mknode(NULL, NULL, $1.name);
      }
    | ID '(' argument_expression_section ')' {
        $$.nd = mknode($3.nd, NULL, $1.name);
      }
    | '&' ID {
        struct node *id = mknode(NULL, NULL, $2.name);
        $$.nd = mknode(id, NULL, "address");
      }
    | MUL '(' expression ')' {
        $$.nd = mknode($3.nd, NULL, "dereference");
      }
    | SUB value {
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
        $1.nd = mknode(NULL, NULL, "return");
        $$.nd = mknode($1.nd, $3.nd, "RETURN");
      }
    | RETURN { add_to_table('K', "return"); } ';' {
        $$.nd = mknode(NULL, NULL, "RETURN");
      }
    ;

%%

void check_declaration(const char *name, const char *datatype, const char *type) {

}

char *get_type(const char *var) {

}

int check_types(const char *type1, const char *type2) {

}

void check_return_type(const char *defined_return_type, const char *real_return_type) {

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

struct node * mknode(struct node *left, struct node *right, char *token) {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    char *newstr = (char *) malloc(strlen(token) + 1);
    strcpy(newstr, token);
    newnode->left = left;
    newnode->right = right;
    newnode->token = newstr;
    return(newnode);
}

void printInorder(struct node *tree) {
    int i;
    if (tree->left) {
        printInorder(tree->left);
    }
    printf("%s, ", tree->token);
    if (tree->right) {
        printInorder(tree->right);
    }
}

void insert_type() {
        strcpy(type, yytext);
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
            symbol_table[count].data_type = strdup("N/A");
            symbol_table[count].type = strdup("Keyword");
            break;
        case 'V':
            symbol_table[count].data_type = strdup(type);
            symbol_table[count].type = strdup("Variable");
            break;
        case 'C':
            symbol_table[count].data_type = strdup("CONST");
            symbol_table[count].type = strdup("Constant");
            break;
        case 'F':
            symbol_table[count].data_type = strdup(type);
            symbol_table[count].type = strdup("Function");
            break;
        case 'P':
            symbol_table[count].data_type = strdup(type);
            symbol_table[count].type = strdup("Pointer");
            break;
        default:
            yyerror("bad symbol");
            return;
    }
    count++;
}

void print_symbol_table() {
    printf("\nSYMBOL\t\t\tDATATYPE\t\tTYPE\t\t\tLINE NUMBER \n");
	printf("____________________________________________________________________________________________\n\n");

	for(int i = 0; i < count; i++) {
		printf("%s\t\t\t%s\t\t\t%s\t\t\t%d\t\t\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_number);
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
    print_symbol_table();
    printInorder(head);
    free_symbol_table();
}

void yyerror(const char *msg) {
    fprintf(stderr, "%s\n", msg);
}
