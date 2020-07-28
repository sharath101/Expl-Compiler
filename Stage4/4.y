%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "4.h"
	#include "4.c"
	int yylex(void);
%}

%union{
	struct tnode *no;
}
%type <no> expr NUM TEXT ID program END BEGIN1 Slist stmt input output asgn ifstmt whilestmt BREAK CONTINUE  
	       Declarations Type Decl DeclList INT STR DECL IDec Varlist ENDDECL var 
%token NUM TEXT ID PLUS MINUS MUL DIV MOD EQ BEGIN1 END READ WRITE POW IF ELSE THEN ENDIF WHILE DO ENDWHILE 
	   EQEQ NOTEQ GREAT GREATEQ LESS LESSEQ BREAK CONTINUE INT STR IDec Varlist DECL ENDDECL 

%left EQ EQEQ NOTEQ GREAT GREATEQ LESS LESSEQ
%left PLUS MINUS
%left MUL DIV
%left MOD
%left POW
%left '['

%%

program : BEGIN1 Slist END ';'		{
										$$=$2;
										printf("program done\n"); 
										FILE *fptr = fopen("target.xsm", "w");
										fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
										fprintf(fptr, "BRKP\n");
										int p=codegen($2,fptr);
										fprintf(fptr, "PASS");
										FILE *fptr2 = fopen("array.c", "w");
										fprintf(fptr2,"int a1[100]={");
										for(int i=0;i<r;i++){
											if(i==0)
												fprintf(fptr2,"%d",a[i]);
											else
												fprintf(fptr2,",%d",a[i]);
										}
										fprintf(fptr2,"};");
										printf("program done\n");
										exit(1);
									}
	    | BEGIN1 END ';'			{exit(1);}
		                			;

Slist  : Slist stmt					{$$ = makenode("connector",3,-1,$1,NULL,$2);}
	 	| stmt     					;

stmt   : input ';' | output ';' | asgn ';'
		 | ifstmt ';'| whilestmt ';'
		 | Declarations
		 | BREAK ';'					{$$=$1;}
	     | CONTINUE ';'				{$$=$1;};

input  : READ '(' var ')'        	{$$ = makenode("read",1,-1,$3,NULL,NULL);};

output : WRITE '(' expr ')'       	{$$ = makenode("write",2,-1,$3,NULL,NULL);}
		|WRITE '(' var ')'          {$$ = makenode("write",2,-1,$3,NULL,NULL);};

asgn   : var EQ expr            	{$$ = makenode("=",4,0,$1,NULL,$3);}
		|var EQ var                 {$$ = makenode("=",4,0,$1,NULL,$3);};
		

ifstmt:  IF '(' expr ')' THEN Slist ELSE Slist ENDIF        {$$= makenode("ifelse",6,-1,$3,$6,$8);}  
        |IF '(' expr ')' THEN Slist ENDIF		     		{$$= makenode("if",6,-1,$3,$6,NULL);};

whilestmt: WHILE '(' expr ')' DO Slist ENDWHILE		    	{$$= makenode("while",5,-1,$3,NULL,$6);};

Declarations: DECL DeclList ENDDECL 						{$$= makeleaf('d',8);}
			  | DECL ENDDECL 								{$$= makeleaf('d',8);};

DeclList : DeclList Decl | Decl ;

Decl : Type VarList ';' ;

Type : INT | STR  ;

VarList : VarList IDec | IDec ;

var: ID 
	 | var '[' var ']' 			{$$ = makearraynode($1->varname,0,$3);}
	 | var '[' expr ']'         {$$ = makearraynode($1->varname,0,$3);};								

expr   :  expr PLUS expr		{$$ = makenode("+",4,0,$1,NULL,$3);}
	 	| expr MINUS expr  		{$$ = makenode("-",4,0,$1,NULL,$3);}
		| expr MUL expr			{$$ = makenode("*",4,0,$1,NULL,$3);}
	 	| expr DIV expr			{$$ = makenode("/",4,0,$1,NULL,$3);}
	 	| expr MOD expr			{$$ = makenode("%",4,0,$1,NULL,$3);}
	 	| expr POW expr        	{$$ = makenode("@",4,0,$1,NULL,$3);}
	 	| expr LESS expr  		{$$ = makenode("<",4,1,$1,NULL,$3);}
	 	| expr GREAT expr		{$$ = makenode(">",4,1,$1,NULL,$3);}
	 	| expr LESSEQ expr		{$$ = makenode("<=",4,1,$1,NULL,$3);}
	 	| expr GREATEQ expr    	{$$ = makenode(">=",4,1,$1,NULL,$3);}
	 	| expr NOTEQ expr		{$$ = makenode("!=",4,1,$1,NULL,$3);}
	 	| expr EQEQ expr       	{$$ = makenode("==",4,1,$1,NULL,$3);}
	 	| '(' expr ')'			{$$ = $2;}                   
	 	| var PLUS expr			{$$ = makenode("+",4,0,$1,NULL,$3);}
	 	| var MINUS expr  		{$$ = makenode("-",4,0,$1,NULL,$3);}
		| var MUL expr			{$$ = makenode("*",4,0,$1,NULL,$3);}
	 	| var DIV expr			{$$ = makenode("/",4,0,$1,NULL,$3);}
	 	| var MOD expr			{$$ = makenode("%",4,0,$1,NULL,$3);}
	 	| var POW expr        	{$$ = makenode("@",4,0,$1,NULL,$3);}
	 	| var LESS expr  		{$$ = makenode("<",4,1,$1,NULL,$3);}
	 	| var GREAT expr		{$$ = makenode(">",4,1,$1,NULL,$3);}
	 	| var LESSEQ expr		{$$ = makenode("<=",4,1,$1,NULL,$3);}
	 	| var GREATEQ expr    	{$$ = makenode(">=",4,1,$1,NULL,$3);}
	 	| var NOTEQ expr		{$$ = makenode("!=",4,1,$1,NULL,$3);}
	 	| var EQEQ expr       	{$$ = makenode("==",4,1,$1,NULL,$3);}
	 	
	 	| expr PLUS var			{$$ = makenode("+",4,0,$1,NULL,$3);}
	 	| expr MINUS var  		{$$ = makenode("-",4,0,$1,NULL,$3);}
		| expr MUL var			{$$ = makenode("*",4,0,$1,NULL,$3);}
	 	| expr DIV var			{$$ = makenode("/",4,0,$1,NULL,$3);}
	 	| expr MOD var			{$$ = makenode("%",4,0,$1,NULL,$3);}
	 	| expr POW var       	{$$ = makenode("@",4,0,$1,NULL,$3);}
	 	| expr LESS var 		{$$ = makenode("<",4,1,$1,NULL,$3);}
	 	| expr GREAT var		{$$ = makenode(">",4,1,$1,NULL,$3);}
	 	| expr LESSEQ var		{$$ = makenode("<=",4,1,$1,NULL,$3);}
	 	| expr GREATEQ var    	{$$ = makenode(">=",4,1,$1,NULL,$3);}
	 	| expr NOTEQ var		{$$ = makenode("!=",4,1,$1,NULL,$3);}
	 	| expr EQEQ var       	{$$ = makenode("==",4,1,$1,NULL,$3);}
	 	
	 	| var PLUS var			{$$ = makenode("+",4,0,$1,NULL,$3);}
	 	| var MINUS var  		{$$ = makenode("-",4,0,$1,NULL,$3);}
		| var MUL var			{$$ = makenode("*",4,0,$1,NULL,$3);}
	 	| var DIV var			{$$ = makenode("/",4,0,$1,NULL,$3);}
	 	| var MOD var			{$$ = makenode("%",4,0,$1,NULL,$3);}
	 	| var POW var       	{$$ = makenode("@",4,0,$1,NULL,$3);}
	 	| var LESS var 			{$$ = makenode("<",4,1,$1,NULL,$3);}
	 	| var GREAT var			{$$ = makenode(">",4,1,$1,NULL,$3);}
	 	| var LESSEQ var		{$$ = makenode("<=",4,1,$1,NULL,$3);}
	 	| var GREATEQ var    	{$$ = makenode(">=",4,1,$1,NULL,$3);}
	 	| var NOTEQ var			{$$ = makenode("!=",4,1,$1,NULL,$3);}
	 	| var EQEQ var       	{$$ = makenode("==",4,1,$1,NULL,$3);}
	 	| NUM					{$$ = $1;}
	 	| TEXT                 	{$$ = $1;}
	 	;

%%

yyerror(char *s)
{
    printf("yyerror %s",s);
}


int main(void) {
	extern FILE *yyin;
  	yyin = fopen("Input", "r");
	yyparse();	
	return 0;
}
