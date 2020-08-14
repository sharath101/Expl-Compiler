%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "codegen.h"
	#include "codegen.c"
	int yylex(void);
%}

%union{
	struct tnode *no;
	
}
%type <no> expr NUM program END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END	{
						$$ = $2;
                        FILE *fptr = fopen("target.xsm", "w");
                        fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0); 
                        int i = codegen($1, fptr);
                        store(i, fptr);
                        printf("Answer : %d\n", evaluate($1));
                        exit(1);
			}
		;

expr : expr PLUS expr		{$$ = makeOperatorNode('+',$1,$3);}
	 | expr MINUS expr  	{$$ = makeOperatorNode('-',$1,$3);}
	 | expr MUL expr		{$$ = makeOperatorNode('*',$1,$3);}
	 | expr DIV expr		{$$ = makeOperatorNode('/',$1,$3);}
	 | '(' expr ')'			{$$ = $2;}
	 | NUM					{$$ = $1;}
	 ;

%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}


int main(void) {
	yyparse();
	
	return 0;
}
