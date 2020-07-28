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
int f=-1;
int ans=0;

 
%}
 
 
character [a-zA-Z,.]
space " "+
newline "\n"
comments "//"+


 
%%

{character}		{
				if(f==1)
				  word++;
				if(word==0){
				  if(*yytext=='A'){
				    f=1;
				    word++;
				  }
				}
			}

{space}			{
				if(word==3)
				  ans++;
				word=0;
				f=-1;
			}

{newline}		{
				if(word==3)
				  ans++;
				word=0;
				f=-1;
			}
 

<<EOF>>                 {
				printf("3 letter words starting with A: %d\n",ans);
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
