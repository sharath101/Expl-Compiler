%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "y.tab.h"
	#include "flow.h"

	int number;
	char var;

%}

%%

"begin" 	{return BEGIN1;}
"read"  	{return READ;}
"write" 	{return WRITE;}
"if"    	{return IF;}
"then"  	{return THEN;}
"else"  	{return ELSE;}
"endif" 	{return ENDIF;}
"while" 	{return WHILE;}
"do"    	{return DO;}
"endwhile" 	{return ENDWHILE;}
"break" 	{var='b'; yylval.no = makeleaf(var,7); return BREAK;}
"continue"	{var='c'; yylval.no = makeleaf(var,7); return CONTINUE;}
[a-z]   	{var= *yytext; yylval.no = makeleafvar(var); return ID;}
[0-9]+		{number = atoi(yytext); yylval.no = makeleafnum(number); return NUM;}
"+"			{return PLUS;}
"-"			{return MINUS;}
"*"			{return MUL;}
"/"			{return DIV;}
"="     	{return EQ;}
"<="		{return LESSEQ;}
"<"			{return LESS;}
">"			{return GREAT;}
">="		{return GREATEQ;}
"!="    	{return NOTEQ;}
"=="		{return EQEQ;}
"@"     	{return POW;}
";"     	{}
" "     	{}
[ \t]		{}
[()]		{return *yytext;}
[\n]		{}
"end"		{return END;}
.			{yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) {
	return 1;
}
