%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "y.tab.h"
	#include "expl.h"

	int number,size;
	char *var;
	//Flags:
	int paramf=0,typef=0,globalf=1,localf=0,utypef=0,decf=0,dot=0,freef=0,classf=0,sepclassf=0,classdecf=0;
	struct Typetable *type=NULL ,*typetemp=NULL;
	struct tnode *previd;

%}
/*
2: int
3: str
*/
alph [A-Za-z][A-Za-z0-9_]*

%%

"begin" 				{typef=0; return BEGIN1;}
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
"break" 				{yylval.no = makeleaf(yytext,7); return BREAK;}
"continue"				{yylval.no = makeleaf(yytext,7); return CONTINUE;}
"null"					{yylval.no = maketext(0,yytext,tLookup("void")); return TEXT;}
"initialize()"			{yylval.no = makeleaf(yytext,14); return initialize;}
"alloc()"				{yylval.no = maketext(0,yytext,tLookup("void")); return TEXT;}
"free"					{freef=1; return FREE;}
"class"					{classf=1; return CLASS;}
"endclass"				{globalf=1; classf=0; return ENDCLASS;}
"new("{alph}")"			{yylval.no = maketext(0,"alloc()",tLookup("void")); return TEXT;}
"self"					{
							if(classf==0){
								printf("Invalid call of self outside a class\n");
								exit(1);
							}
							yylval.no = makeleafnum(0,yytext,tLookup("void"));
							return SELF;	
						}		
"decl"                  {	
							decf=1;
							if(sepclassf==1)
								classdecf=1;
							if(globalf==1)			
								return GDECL;
							else
								return LDECL;
						}
"enddecl"   			{
							decf=0;
							classdecf=0;
							sepclassf=0;
							type=NULL;
							if(globalf==1)	{	
								globalf=0;					
								return GENDDECL;
							}
							else
								return LENDDECL;
						}
"type"					{utypef=1; return TYPE;}
"endtype"				{globalf=1; utypef=0; return ENDTYPE;}
"main"					{return MAIN;}
"int"					{typef=1; type=tLookup("int"); yylval.ts=tLookup("int"); return INT;}
"str"					{typef=1; type=tLookup("str"); yylval.ts=tLookup("str"); return STR;}
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
												if(type==NULL){
													printf("Variable with no type\n");
													exit(1);
												}
												yylval.gs=newgid(va,type,num);
												printf("New global: %s(%s)\n",yytext,type->name);
												return GIDec;
											}
											else{
												printf("Already declared variable: %s\n",yytext);
												exit(1);
											}
										}
										else if(localf==1 && typef==1){
											printf("Cannot declare array locally\n");
											exit(1);
										}
										else{
											struct Typetable *type1;
											if(!checkgvar(va)){
												type=gLookup(va)->type;
												yylval.no = makeleafvar(va,num,type1);
												return ID;
											}
											else{
												printf("Undeclared variable: %s\n",yytext);
												exit(1);
											}
										}		
									}
									
[A-Za-z][A-Za-z0-9_]* 	{
							/*-------------UType Definitions--------------*/
							if(utypef==1 && globalf==1){
								//printf("entertname\n");
								yylval.ts=newtype(yytext);
								return Tname;
							}
							else if(classf==1 && localf==0 && type==NULL && tLookup(yytext)==NULL){
								//printf("entercid %s\n",yytext);
								if(tLookup(yytext)==NULL)
									yylval.ts=newtype(yytext);
								sepclassf=1;
								return CID;
							}
							else if((utypef==1 || decf==1 || localf==0 || classdecf==1) && type==NULL){
								//printf("entertid %s\n",yytext);
								if(tLookup(yytext)==NULL){
									printf("Type not found\n");
									exit(1);
								}
								yylval.ts=tLookup(yytext);
								type=tLookup(yytext);
								typef=1;
								return TID;
							}
							else if(utypef==1 && localf==1){
								//printf("entertidec %s\n",yytext);
								yylval.no = makeleaf(yytext,0);       //only for name
								return TIDec;
							}
							else if(classf==1 && classdecf==1 && paramf==0){
								//printf("entermidec %s\n",yytext);
								yylval.no = makeleaf(yytext,0);       //only for name
								return MIDec;
							}
							/*-------------Global type Definitions--------------*/
							else if(typef==1 && paramf==1 && globalf==1){
								//printf("enterpidec\n");
								if(type==NULL){
									printf("Variable with no type\n");
									exit(1);
								}
								yylval.pr=newparam(yytext,type);	
								return PID;
							}
							else if(typef==1 && paramf==1){
								//printf("enterpidec\n");
								struct Lsymbol *l;
								if(type==NULL){
									printf("Variable with no type\n");
									exit(1);
								}
								l=newlid(yytext,type);
								yylval.pr=newparam(yytext,type);
								return PID;
							}
							else if(typef==1 && globalf==1){
								//printf("entergidec\n");
								if(checkgvar(yytext)){
									if(type==NULL){
										printf("Variable with no type\n");
										exit(1);
									}
									yylval.gs=newgid(yytext,type,1);                  //REPLACE WITH SIZE?
									//printf("New global: %s(%s)\n",yytext,type->name);
									return GIDec;
								}
								else{
									printf("Already declared variable: %s\n",yytext);
									exit(1);
								}
							}
							/*-------------Local type Definitions--------------*/
							else if(typef==1 && (localf==0 || classf==1) && decf==0){
								//printf("enterfid %s\n",yytext);
								yylval.no = makeleafnum(-1,yytext,tLookup("bool")); //only for name
								return FID;
							}
							else if(typef==1 && localf==1){
								//printf("enterlidec\n");
								if(checklvar(yytext)){
									if(type==NULL){
										printf("Variable with no type\n");
										exit(1);
									}
									yylval.ls=newlid(yytext,type);
									//printf("New local: %s(%s)\n",yytext,type->name);
									return LIDec;
								}
								else{
									printf("Already declared variable: %s\n",yytext);
									exit(1);
								}
							}
							else if(dot==1){
								//printf("enter dot\n");
								yylval.no = makeleaf(yytext,13);
								dot=0;
								if(cflookup(NULL,yytext)!=NULL){
									yylval.no->type=cflookup(NULL,yytext)->type;
									//return CFID;
								}
								return ID;
							}
							else{
								//printf("var: %s\n",yytext);
								struct Typetable *type1;
								if(!checkgvar(yytext) || !checklvar(yytext)){
									if(!checklvar(yytext))
										type1=lLookup(yytext)->type;
									else
										type1=gLookup(yytext)->type;
									yylval.no = makeleafvar(yytext,-1,type1);
									if(cLookup(type1->name)!=NULL){
										yylval.no->cptr=cLookup(type1->name);
										return CFID;
									}
									return ID;
								}
								else{
									printf("Undeclared variable: %s\n",yytext);
									exit(1);
								}
							}		
						}

[0-9]+					{number = atoi(yytext); yylval.no = makeleafnum(number,NULL,tLookup("int")); return NUM;}
\".*\"					{yylval.no = maketext(0,yytext,tLookup("str")); return TEXT;}
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
";"     				{type=NULL; return *yytext;}
" "     				{}
"{"						{localf=1; globalf=0; return *yytext;}
"}"						{localf=0; if(utypef==1) globalf=1; return *yytext;}
","						{if(paramf==1) type=NULL; return *yytext;}
"."						{dot=1; return *yytext;}
[ \t]					{}
"["                     {return *yytext;}
"]"                     {return *yytext;}
"("						{if(freef!=1){typetemp=type;type=NULL; paramf=1;}return *yytext;}
")"						{freef=0; type=typetemp; paramf=0;return *yytext;}
[\n]					{type=NULL; typef=0;}
.						{printf("Unknown character: %s\n",yytext);exit(1);}

%%

int yywrap(void) {
	return 1;
}
