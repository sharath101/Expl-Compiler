%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "ex1.h"
	#include "ex1.c"
	int yylex(void);
%}

%union{
	struct tnode *no;
	
}
%type <no> expr NUM ID program END BEGIN1 Slist stmt input output asgn
%token NUM ID PLUS MINUS MUL DIV EQ BEGIN1 END READ WRITE
%left EQ
%left PLUS MINUS
%left MUL DIV

%%

program : BEGIN1 Slist END       {
					$$=$2;
					int p=evaluate($2);
					printf("program done\n");
					exit(1);
				}
	  | BEGIN1 END		{exit(1);}
		                ;

Slist  : Slist stmt		{$$ = makenode('c',3,$1,$2);}
	 | stmt     		;

stmt   : input | output | asgn;	

input  : READ '(' expr ')'        	{if($3->left!=NULL || $3->right!=NULL) {printf("Error1\n");exit(1);}
				   	$$ = makenode('r',1,$3,$3);};

output : WRITE '(' expr ')'       	{$$ = makenode('w',2,$3,$3);};

asgn   : expr EQ expr            	{if($1->left!=NULL || $1->right!=NULL) {printf("Error2\n");exit(1);}
				  	$$ = makenode('=',4,$1,$3);};

expr   : expr PLUS expr		{$$ = makenode('+',4,$1,$3);}
	 | expr MINUS expr  	{$$ = makenode('-',4,$1,$3);}
	 | expr MUL expr	{$$ = makenode('*',4,$1,$3);}
	 | expr DIV expr	{$$ = makenode('/',4,$1,$3);}
	 //| '(' expr ')'		{$$ = $2;}                   // will affect read?
	 | NUM			{$$ = $1;}
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
