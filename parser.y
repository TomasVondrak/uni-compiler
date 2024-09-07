%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "lex.yy.c"

    void yyerror(const char *s);
    int yylex();
    int yywrap();

    // symbol table

    struct symbol {
        char * id_name;
        char * data_type;
        char * type;
        int line_number;
    } symbol_table[100]; // dynamically store later

    int count = 0;
    char type[10];
    extern int count_n;

    void add_to_table(char, const char *);
    void insert_type();
    int search(const char *);

    // abstract syntax tree

    struct node {
        struct node *left;
        struct node *right;
        char *token;
    };

    struct var_name {
        char name[100];
        struct node *nd;
    } nd_obj;

%}

%union {
    int number;
    float float_num;
    char *string;
    char character;
}

%token <number> NUMBER
%token <float_num> FLOAT_NUM
%token <string> ID
%token <character> CHARACTER

%token <nd_obj> INT FLOAT CHAR VOID RETURN FOR WHILE IF ELSE LT GT LE GE EQ NE AND OR ADD SUB DIV MUL TRUE FALSE PUTCHAR

%type <string> value datatype argument_definition init expression
// %type <nd_obj> program declaration function_definition arguments_definition_section arguments_definition argument_definition datatype compound_statement block item else condition statement init expression arithmetic relop value argument_expression_section arguments_expression return

%start program

%%

program
    : declaration
    | program declaration
    ;

declaration
    : function_definition
    ;

function_definition
    : datatype ID { add_to_table('F', $2); } '(' arguments_definition_section ')' compound_statement
    ;

arguments_definition_section
    : arguments_definition
    |
    ;

arguments_definition
    : argument_definition
    | arguments_definition ',' argument_definition
    ;

argument_definition
    : datatype ID { add_to_table('V', $2); }
    ;

// add pointers
datatype
    : INT { insert_type(); $$ = strdup(yytext); }
    | FLOAT { insert_type(); $$ = strdup(yytext); }
    | CHAR { insert_type(); $$ = strdup(yytext); }
    | VOID { insert_type(); $$ = strdup(yytext); }
    ;

compound_statement
    : '{' block '}'
    ;

block
    : item
    | block item
    ;

item
    : FOR { add_to_table('K', yytext); } '(' statement ';' condition ';' statement ')' compound_statement
    | WHILE { add_to_table('K', yytext); } '(' condition ')' compound_statement
    | IF { add_to_table('K', yytext); } '(' condition ')' compound_statement else
    | statement ';'
    | return
    ;

else
    : ELSE { add_to_table('K', yytext); } compound_statement
    |
    ;

condition
    : expression relop expression
    | TRUE { add_to_table('K', yytext); }
    | FALSE { add_to_table('K', yytext); }
    ;

statement
    : datatype ID { add_to_table('V', $2); } init
    | datatype MUL ID { add_to_table('P', $3); } init
    | ID '=' expression
    | MUL '(' expression ')' '=' expression
    | expression
    | PUTCHAR { add_to_table('K', yytext); } '(' value ')'
    | datatype ID { add_to_table('P', $2); } '[' value ']'
    ;

init
    : '=' expression
    |
    ;

expression
    : expression arithmetic expression
    | '(' expression ')'
    | value
    ;

arithmetic
    : ADD
    | SUB
    | MUL
    | DIV
    ;

relop
    : LT
    | GT
    | LE
    | GE
    | EQ
    | NE
    ;

value
    : NUMBER { add_to_table('C', yytext); $$ = yytext; }
    | FLOAT_NUM { add_to_table('C', yytext); $$ = yytext; }
    | CHARACTER { add_to_table('C', yytext); $$ = yytext; }
    | ID { $$ = yytext; }
    | ID '(' argument_expression_section ')' { $$ = strdup($1); }
    | '&' ID { $$ = $2; }
    | MUL '(' expression ')' { $$ = $3; }
    | SUB value { $$ = $2; }
    ;

argument_expression_section
    : arguments_expression
    |
    ;

arguments_expression
    : value
    | arguments_expression ',' value
    ;

return
    : RETURN { add_to_table('K', "return"); } value ';'
    | RETURN { add_to_table('K', "return"); } ';'
    ;

%%

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

	for(int i = 0; i < count; i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}

	printf("\n");
}

int main() {
    yyparse();
    print_symbol_table();
}

void yyerror(const char *msg) {
    fprintf(stderr, "%s\n", msg);
}
