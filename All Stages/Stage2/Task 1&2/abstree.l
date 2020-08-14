%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h"
	#include "abstree.h"

	int number;
	char var;

%}

%%

"begin" {return BEGIN1;}
"read"  {return READ;}
"write" {return WRITE;}
[a-z]   {var= *yytext; yylval.no = makeleafvar(var); return ID;}
[0-9]+	{number = atoi(yytext); yylval.no = makeleafnum(number); return NUM;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"="     {return EQ;}
"@"     {return POW;}
";"     {}
" "     {}
[ \t]	{}
[()]	{return *yytext;}
[\n]	{}
"end"	{return END;}
.	{yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) {
	return 1;
}
