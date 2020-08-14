%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "y.tab.h"
	#include "4.h"

	int number,type,flag=0;
	char *var;
	char v;
	//int idnum=0;

%}
/*
2: int
3: str
*/

%%

"begin" 				{return BEGIN1;}
"end"					{return END;}
"read"  				{return READ;}
"write" 				{return WRITE;}
"if"    				{return IF;}
"then"  				{return THEN;}
"else"  				{return ELSE;}
"endif" 				{return ENDIF;}
"while" 				{return WHILE;}
"do"    				{return DO;}
"endwhile" 				{return ENDWHILE;}
"break" 				{v='b'; yylval.no = makeleaf(v,7); return BREAK;}
"continue"				{v='c'; yylval.no = makeleaf(v,7); return CONTINUE;}
"decl"                  {return DECL;}
"enddecl"   			{return ENDDECL;}
"int"					{flag=1; type=2; return INT;}
"str"					{flag=1; type=3; return STR;}

[A-Za-z][A-Za-z0-9]*"["[0-9]+"]" 	{
										char *t,*va=malloc(sizeof(char));
										int i=0,s;
										t=strdup(yytext);
										for(i=0;*(t+i)!='[';i++);
										strncpy(va,t,i);
										*(va+i)='\0';
										//printf("%s\n",va);
										s=i+1;
										char *numv=malloc(sizeof(char));
										for(i=s;*(t+i)!=']';i++);
										strncpy(numv,t+s,i-s);
										*(numv+i)='\0';
										int num=atoi(numv);
										//printf("%d\n",num);
										//printf("-------\n");
										if(num>1000){
											printf("Memory Full\n");
											exit(1);
										}
										if(flag==1){
											newid(va,type,num);
											return IDec;
										}
										else{
											if(checkvar(va)){
												yylval.no = makeleafvar(va,num,20,NULL);
												return ID;
											}
											else{
												printf("Undeclared character: %s\n",yytext);
												exit(1);
											}
										}		
									}
									
[A-Za-z][A-Za-z0-9]* 	{
							if(flag==1){
								newid(yytext,type,1);
								return IDec;
							}
							else{
								if(checkvar(yytext)){
									yylval.no = makeleafvar(yytext,-1,10,NULL);
									return ID;
								}
								else{
									printf("Undeclared character: %s\n",yytext);
									exit(1);
								}
							}		
						}

[0-9]+					{number = atoi(yytext); yylval.no = makeleafnum(number,NULL,2); return NUM;}
\".*\"					{yylval.no = makeleafnum(0,yytext,3); return TEXT;}
"+"						{return PLUS;}
"-"						{return MINUS;}
"*"						{return MUL;}
"/"						{return DIV;}
"%"                     {return MOD;}
"="     				{return EQ;}
"<="					{return LESSEQ;}
"<"						{return LESS;}
">"						{return GREAT;}
">="					{return GREATEQ;}
"!="    				{return NOTEQ;}
"=="					{return EQEQ;}
"@"     				{return POW;}
";"     				{flag=0; return *yytext;}
" "     				{}
","						{}
[ \t]					{}
"["                     {return *yytext;}
"]"                     {return *yytext;}
[()]					{return *yytext;}
[\n]					{}
.						{printf("Unknown character: %s\n",yytext);exit(1);}

%%

int yywrap(void) {
	return 1;
}
