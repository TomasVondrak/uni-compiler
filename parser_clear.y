%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "lex.yy.c"

    void yyerror(const char *s);
    int yylex();
    int yywrap();

    struct symbol {
        char * id_name;
        char * data_type;
        char * type;
        int line_number;
    } symbol_table[100]; // dynamically store later

    int count = 0;
    char name[10];
    extern int count_n;

    void add_to_table(char);
    void insert_type();
    int search(char *);
%}

%token INT FLOAT CHAR VOID RETURN FOR WHILE IF ELSE LT GT LE GE EQ NE AND OR ADD SUB DIV MUL TRUE FALSE NUMBER FLOAT_NUM ID CHARACTER PUTCHAR

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
    : datatype ID '(' arguments_definition_section ')' compound_statement
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
    : datatype ID
    ;

// add pointers
datatype
    : INT
    | FLOAT
    | CHAR
    | VOID
    ;

compound_statement
    : '{' block '}'
    ;

block
    : item
    | block item
    ;

item
    : FOR '(' statement ';' condition ';' statement ')' compound_statement
    | WHILE '(' condition ')' compound_statement
    | IF '(' condition ')' compound_statement else
    | statement ';'
    | return
    ;

else
    : ELSE compound_statement
    |
    ;

condition
    : expression relop expression
    | TRUE
    | FALSE
    ;

statement
    : datatype ID init
    | datatype MUL ID init
    | ID '=' expression
    | MUL '(' expression ')' '=' expression
    | expression
    | PUTCHAR '(' value ')'
    | datatype ID '[' value ']'
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
    : NUMBER
    | FLOAT_NUM
    | CHARACTER
    | ID
    | ID '(' argument_expression_section ')'
    | '&' ID
    | MUL '(' expression ')'
    | SUB value
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
    : RETURN value ';'
    | RETURN ';'
    ;

%%

void insert_type() {
        strcpy(type, yytext);
}

int search(char *name) {
    for (int i = count - 1; i >= 0; i--) {
        if (strcmp(symbol_table[i].id_name, name) == 0) {
            return -1;
            break;
        }
    }
    return 0;
}

void add_to_table(char symbol) {
    if (search(yytext)) return;
    symbol_table[count].id_name = strdup(yytext);
    symbol_table[count].line_number = count_n;
    switch (symbol) {
        case 'K':
            symbol_table[count].data_type = strdup("N/A");
            symbol_table[count].type = strdup("Keyword\t");
        case 'V':
            symbol_table[count].data_type = strdup(type);
            symbol_table[count].type = strdup("Variable");
        case 'C':
            symbol_table[count].data_type = strdup("CONST");
            symbol_table[count].type = strdup("Constant");
        case 'F':
            symbol_table[count].data_type = strdup(type);
            symbol_table[count].type = strdup("Function");
    }
    count++;
}

void print_symbol_table() {
    printf("\nSYMBOL   DATATYPE   TYPE   LINE NUMBER \n");
	printf("_______________________________________\n\n");

	for(int i = 0; i < count; i++) {
		printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_number);
	}

	for(i = 0; i < count; i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}

	printf("\n\n");
}

int main() {
    yyparse();
    print_symbol_table();
}

void yyerror(const char *msg) {
    fprintf(stderr, "%s\n", msg);
}
