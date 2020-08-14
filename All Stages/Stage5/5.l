%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "y.tab.h"
	#include "5.h"

	int number,type;
	char *var;
	char v;
	//Flags:
	int paramf=0,typef=0,globalf=1,localf=0;

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
"decl"                  {
							if(globalf==1)						
								return GDECL;
							else
								return LDECL;
						}
"enddecl"   			{
							if(globalf==1)	{	
								globalf=0;					
								return GENDDECL;
							}
							else
								return LENDDECL;
						}
"main"					{return MAIN;}
"int"					{typef=1; type=2; return INT;}
"str"					{typef=1; type=3; return STR;}
"return"				{return RET;}

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
										if(typef==1 && globalf==1){
											if(checkgvar(va)){
												yylval.gs=newgid(va,type,num);
												printf("New global: %s\n",yytext);
												return GIDec;
											}
											else{
												printf("Already declared variable: %s\n",yytext);
												exit(1);
											}
										}
										else if(localf==1 && typef==1){
											printf("Cannot declare array in a function\n");
											exit(1);
										}
										else{
											int type1;
											if(!checkgvar(va)){
												type1=gLookup(va)->type;
												yylval.no = makeleafvar(va,num,type1);
												return ID;
											}
											else{
												printf("Undeclared variable: %s\n",yytext);
												exit(1);
											}
										}		
									}
									
[A-Za-z][A-Za-z0-9]* 	{
							if(typef==1 && paramf==1 && globalf==1){
								//printf("enterpidec\n");
								yylval.pr=newparam(yytext,type);	
								return PID;
							}
							else if(typef==1 && paramf==1){
								//printf("enterpidec\n");
								struct Lsymbol *l;
								l=newlid(yytext,type);
								yylval.pr=newparam(yytext,type);
								return PID;
							}
							else if(typef==1 && globalf==1){
								//printf("entergidec\n");
								if(checkgvar(yytext)){
									yylval.gs=newgid(yytext,type,1);
									printf("New global: %s\n",yytext);
									return GIDec;
								}
								else{
									printf("Already declared variable: %s\n",yytext);
									exit(1);
								}
							}
							else if(typef==1 && localf==1){
								//printf("enterlidec\n");
								if(checklvar(yytext)){
									yylval.ls=newlid(yytext,type);
									printf("New local: %s\n",yytext);
									return LIDec;
								}
								else{
									printf("Already declared variable: %s\n",yytext);
									exit(1);
								}
							}
							else if(typef==1 && localf==0){
								//printf("enterfid\n");
								yylval.no = makeleafnum(-1,yytext,10);
								return FID;
							}
							else{
								//printf("var: %s\n",yytext);
								int type1;
								if(!checkgvar(yytext) || !checklvar(yytext)){
									if(!checklvar(yytext))
										type1=lLookup(yytext)->type;
									else
										type1=gLookup(yytext)->type;
									yylval.no = makeleafvar(yytext,-1,type1);
									return ID;
								}
								else{
									printf("Undeclared variable: %s\n",yytext);
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
";"     				{typef=0; return *yytext;}
" "     				{}
"{"						{localf=1; globalf=0; return *yytext;}
"}"						{localf=0;  return *yytext;}
","						{return *yytext;}
[ \t]					{}
"["                     {return *yytext;}
"]"                     {return *yytext;}
"("						{paramf=1;return *yytext;}
")"						{paramf=0;return *yytext;}
[\n]					{typef=0;}
.						{printf("Unknown character: %s\n",yytext);exit(1);}

%%

int yywrap(void) {
	return 1;
}
