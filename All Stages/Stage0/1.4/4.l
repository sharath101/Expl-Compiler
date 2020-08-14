%{
 
#include <stdlib.h>
#include <stdio.h>
 
int f=0;
int b=0;


 
%}
 
 
start "/*"
end "*/"
newline "\n"
comments "//"+


 
%%

{start}			{
				f=1;
			}

{end}			{
				f=0;
			}

{comments}		{
				b=1;
			}

{newline}		{
				if(b==1)
				  printf("\n");
				b=0;
			}

.                       {
				if(f==1 || b==1)
				  printf("%s",yytext);
			}

<<EOF>>                 {
				return 0;
			}
 

%%
 
int yywrap()
{
  return 1;
}
 
int main()
{
  printf("\nReading input from file\n");
  extern FILE *yyin, *yyout; 
  yyin = fopen("Input", "r"); 
  yylex();
  printf("\n");
  return 1;
}
