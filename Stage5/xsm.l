%{
  #include<stdlib.h>
  #include<stdio.h>
  #include "array.c"

  int f1=0,f2=0,funcf=0,funcf2=0;
  //FILE *fptr4 = fopen("final.xsm", "w");
%}

num  [0-9]

%%

"L"{num}":\n"     {}

"F"{num}":\n"     {}
 
"J"         {f1=1; printf("%s",yytext);}

"CALL"      {funcf=1; printf("%s",yytext);}

"L"	        { 	if(f1==1) 
					f2=1;
				else
					printf("%s",yytext);
			}

"F"	        { 	if(funcf==1) 
					funcf2=1;
				else
					printf("%s",yytext);
			}
			
{num}  		{ 	if(f1==1 && f2==1){
					int b=atoi(yytext);
					printf("%d",a[b]);
					f1=0;
					f2=0;
		  		}
		  		else if(funcf==1 && funcf2==1){
					int b=atoi(yytext);
					printf("%d",f[b]);
					funcf=0;
					funcf2=0;
		  		}
		  		else
		  			printf("%s",yytext);
			}

"MAIN"		{
				if(f1==1){
					printf("%d",mainl);
					f1=0;
					f2=0;
		  		}
		  	}
		  	
"MAIN:\n"	{}

"\n"        printf("\n");

<<EOF>>     {printf("done"); exit(1);}
			
.			printf("%s",yytext);

%%

int yywrap(void) {
	return 1;
}

