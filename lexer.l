%{
    #include "y.tab.h"

    int count_n = 1;
%}

%option yylineno

alpha [a-zA-Z]
digit [0-9]

%%

"putchar"                           { strcpy(yylval.nd_obj.name,(yytext)); return PUTCHAR; }

"int"                               { strcpy(yylval.nd_obj.name,(yytext)); return INT; }
"float"                             { strcpy(yylval.nd_obj.name,(yytext)); return FLOAT; }
"char"                              { strcpy(yylval.nd_obj.name,(yytext)); return CHAR; }
"void"                              { strcpy(yylval.nd_obj.name,(yytext)); return VOID; }

"return"                            { strcpy(yylval.nd_obj.name,(yytext)); return RETURN; }
"for"                               { strcpy(yylval.nd_obj.name,(yytext)); return FOR; }
"while"                             { strcpy(yylval.nd_obj.name,(yytext)); return WHILE; }
"if"                                { strcpy(yylval.nd_obj.name,(yytext)); return IF; }
"else"                              { strcpy(yylval.nd_obj.name,(yytext)); return ELSE; }

"<"                                 { strcpy(yylval.nd_obj.name,(yytext)); return LT; }
">"                                 { strcpy(yylval.nd_obj.name,(yytext)); return GT; }
"<="                                { strcpy(yylval.nd_obj.name,(yytext)); return LE; }
">="                                { strcpy(yylval.nd_obj.name,(yytext)); return GE; }
"=="                                { strcpy(yylval.nd_obj.name,(yytext)); return EQ; }
"!="                                { strcpy(yylval.nd_obj.name,(yytext)); return NE; }
"&&"                                { strcpy(yylval.nd_obj.name,(yytext)); return AND; }
"||"                                { strcpy(yylval.nd_obj.name,(yytext)); return OR; }
"+"                                 { strcpy(yylval.nd_obj.name,("add")); return ADD; }
"-"                                 { strcpy(yylval.nd_obj.name,("sub")); return SUB; }
"/"                                 { strcpy(yylval.nd_obj.name,("udiv")); return DIV; }
"*"                                 { strcpy(yylval.nd_obj.name,("mul")); return MUL; }

"true"                              { strcpy(yylval.nd_obj.name,(yytext)); return TRUE; }
"false"                             { strcpy(yylval.nd_obj.name,(yytext)); return FALSE; }

[-]?{digit}+                        { strcpy(yylval.nd_obj.name,(yytext)); return NUMBER; }
[-]?{digit}+\.{digit}{1,6}          { strcpy(yylval.nd_obj.name,(yytext)); return FLOAT_NUM; }
{alpha}({alpha}|{digit}|\_|\-)*     { strcpy(yylval.nd_obj.name,(yytext)); return ID; }

\/\/.*                              { ; }
\/\*(.*\n)*.*\*\/                   { ; }
[ \t]*                              { ; }
[\n]                                { count_n++; }
.                                   { return *yytext; }

['].[']                             { strcpy(yylval.nd_obj.name,(yytext)); return CHARACTER; }

%%

int yywrap() {
    return 1;
}
