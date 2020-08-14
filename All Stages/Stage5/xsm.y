%{
    #include <stdio.h>
    #include <stdlib.h>
    //#include "array.c"
    int yyerror();
%}

%token END

%%

start : END	{printf("\nComplete");exit(1);};

%%

int yyerror()
{
	printf("Error");
}

int main()
{
  extern FILE *yyin,*yyout;
  yyin = fopen("target.xsm", "r");
  yyout = fopen("final.xsm","w");
  yyparse();
  return 1;
}
