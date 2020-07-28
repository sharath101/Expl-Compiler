%{
 
/*
1.Request input of an even and an odd number
2.indicate input characteristic : Even/Odd
3.check for input's correctness and print result
*/
 
#include <stdlib.h>
#include <stdio.h>
 
int line=0;
int chara=0;
int word=0;


 
%}
 
 
character [a-zA-Z,.]
space " "+
newline "\n"
comments "//"+


 
%%

{character}		{
				chara++;
			}

{space}			{
				word++;
			}

{newline}		{
				line++;
				word++;
			}
 

<<EOF>>                 {
				printf("lines: %d\n",line);
				printf("words: %d\n",word);
				printf("characters: %d\n",chara);
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
