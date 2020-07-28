%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "flow.h"
	#include "flow.c"
	int yylex(void);
%}

%union{
	struct tnode *no;
	
}
%type <no> expr NUM ID program END BEGIN1 Slist stmt input output asgn ifstmt whilestmt BREAK CONTINUE
%token NUM ID PLUS MINUS MUL DIV EQ BEGIN1 END READ WRITE POW IF ELSE THEN ENDIF WHILE DO ENDWHILE EQEQ NOTEQ GREAT GREATEQ LESS LESSEQ BREAK CONTINUE 

%left EQ EQEQ NOTEQ GREAT GREATEQ LESS LESSEQ
%left PLUS MINUS
%left MUL DIV
%left POW

%%

program : BEGIN1 Slist END         {
										$$=$2;
										//printf("program done\n"); 
										FILE *fptr = fopen("target.xsm", "w");
										fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
										int p=codegen($2,fptr);
										fprintf(fptr, "PASS");
										FILE *fptr2 = fopen("array.c", "w");
										fprintf(fptr2,"int a1[1000]={");
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
	  | BEGIN1 END					{exit(1);}
		                			;

Slist  : Slist stmt					{$$ = makenode("connector",3,-1,$1,NULL,$2);}
	 	| stmt     					;

stmt   : input | output | asgn
		 | ifstmt | whilestmt 
		 | BREAK					{$$=$1;}
	     | CONTINUE 				{$$=$1;};

input  : READ '(' expr ')'        	{if($3->left!=NULL || $3->right!=NULL){printf("Error reading\n");exit(1);}
				   					 $$ = makenode("read",1,-1,$3,NULL,NULL);};

output : WRITE '(' expr ')'       	{$$ = makenode("write",2,-1,$3,NULL,NULL);};

asgn   : expr EQ expr            	{if($1->left!=NULL || $1->right!=NULL) {printf("Error assigning\n");exit(1);}
				  					 $$ = makenode("=",4,0,$1,NULL,$3);};

ifstmt:  IF '(' expr ')' THEN Slist ELSE Slist ENDIF         {$$= makenode("ifelse",6,-1,$3,$6,$8);}  
        |IF '(' expr ')' THEN Slist ENDIF		     		 {$$= makenode("if",6,-1,$3,$6,NULL);};

whilestmt: WHILE '(' expr ')' DO Slist ENDWHILE		    	 {$$= makenode("while",5,-1,$3,NULL,$6);};

expr   : expr PLUS expr		{$$ = makenode("+",4,0,$1,NULL,$3);}
	 | expr MINUS expr  	{$$ = makenode("-",4,0,$1,NULL,$3);}
	 | expr MUL expr		{$$ = makenode("*",4,0,$1,NULL,$3);}
	 | expr DIV expr		{$$ = makenode("/",4,0,$1,NULL,$3);}
	 | expr POW expr        {$$ = makenode("@",4,0,$1,NULL,$3);}
	 | expr LESS expr  		{$$ = makenode("<",4,1,$1,NULL,$3);}
	 | expr GREAT expr		{$$ = makenode(">",4,1,$1,NULL,$3);}
	 | expr LESSEQ expr		{$$ = makenode("<=",4,1,$1,NULL,$3);}
	 | expr GREATEQ expr    {$$ = makenode(">=",4,1,$1,NULL,$3);}
	 | expr NOTEQ expr		{$$ = makenode("!=",4,1,$1,NULL,$3);}
	 | expr EQEQ expr       {$$ = makenode("==",4,1,$1,NULL,$3);}
	 | '(' expr ')'			{$$ = $2;}                   // will affect read?
	 | NUM					{$$ = $1;}
	 | ID	                {$$ = $1;}
	 ;

%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}


int main(void) {
	extern FILE *yyin;
  	yyin = fopen("Input", "r");
	yyparse();	
	return 0;
}
