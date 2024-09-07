%{
    #include "y.tab.h"

    int count_n = 1;
%}

%option yylineno

alpha [a-zA-Z]
digit [0-9]

%%

"putchar"                           { return PUTCHAR; }

"int"                               { return INT; }
"float"                             { return FLOAT; }
"char"                              { return CHAR; }
"void"                              { return VOID; }

"return"                            { return RETURN; }
"for"                               { return FOR; }
"while"                             { return WHILE; }
"if"                                { return IF; }
"else"                              { return ELSE; }

"<"                                 { return LT; }
">"                                 { return GT; }
"<="                                { return LE; }
">="                                { return GE; }
"=="                                { return EQ; }
"!="                                { return NE; }
"&&"                                { return AND; }
"||"                                { return OR; }
"+"                                 { return ADD; }
"-"                                 { return SUB; }
"/"                                 { return DIV; }
"*"                                 { return MUL; }

"true"                              { return TRUE; }
"false"                             { return FALSE; }

[-]?{digit}+                        { yylval.number = atoi(yytext); return NUMBER; }
[-]?{digit}+\.{digit}{1,6}          { yylval.float_num = atof(yytext); return FLOAT_NUM; }
{alpha}({alpha}|{digit}|\_|\-)*     { yylval.string = strdup(yytext); return ID; }

\/\/.*                              { ; }
\/\*(.*\n)*.*\*\/                   { ; }
[ \t]*                              { ; }
[\n]                                { count_n++; }
.                                   { return *yytext; }

['].[']                             { yylval.character = *yytext; return CHARACTER; }

%%

int yywrap() {
    return 1;
}
