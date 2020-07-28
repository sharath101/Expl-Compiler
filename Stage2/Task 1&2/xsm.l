%{
  #include "y.tab.h"
  #include<stdlib.h>
  #include<stdio.h>
  #include "array.c"

  int f1=0,f2=0;
  //FILE *fptr = fopen("final.xsm", "w");
%}

num  [0-9]

%%

"L"{num}":\n"     {}
 
"JZ"           { f1=1; printf("%s",yytext);}

"JNZ"           { f1=1; printf("%s",yytext);}

"L"	        { if(f1==1) 
			f2=1;
		  else
			printf("%s",yytext);
		}
{num}  		{ if(f1==1 && f2==1){
			int b=atoi(yytext);
			printf("%d",a1[b]);
			f1=0;
			f2=0;
		  }
		  else
		  	printf("%s",yytext);
		}

"\n"            printf("\n");

<<EOF>>          {printf("done"); exit(1);}
			
.		printf("%s",yytext);

%%

int yywrap(void) {
	return 1;
}
