%{
  #include<stdlib.h>
  #include<stdio.h>
  #include "array.c"

  int f1=0,f2=0,funcf=0,funcf2=0;
%}

num  [0-9]
num2 [0-9]+

%%

"L"{num2}":\n"     {}

"F"{num2}":\n"     {}
 
"J"         {f1=1; fprintf(yyout,"%s",yytext);}

"CALL"      {funcf=1; fprintf(yyout,"%s",yytext);}

"L"	        { 	if(f1==1) 
					f2=1;
				else
					fprintf(yyout,"%s",yytext);
			}

"F"	        { 	if(funcf==1) 
					funcf2=1;
				else
					fprintf(yyout,"%s",yytext);
			}
			
{num2}  		{ 	if(f1==1 && f2==1){
					int b=atoi(yytext);
					fprintf(yyout,"%d",a[b]);
					f1=0;
					f2=0;
		  		}
		  		else if(funcf==1 && funcf2==1){
					int b=atoi(yytext);
					fprintf(yyout,"%d",f[b]);
					funcf=0;
					funcf2=0;
		  		}
		  		else
		  			fprintf(yyout,"%s",yytext);
			}

"MAIN"		{
				if(f1==1){
					fprintf(yyout,"%d",mainl);
					f1=0;
					f2=0;
		  		}
		  	}
		  	
"MAIN:\n"	{}

"\n"        fprintf(yyout,"\n");

<<EOF>>     {exit(1);}
			
.			fprintf(yyout,"%s",yytext);

%%

int yywrap(void) {
	return 1;
}

int main()
{
  extern FILE *yyin, *yyout; 
  yyin = fopen("target.xsm", "r"); 
  yyout = fopen("/home/sharath/Desktop/xsm/xsm_expl/prog.xsm","w");
  yylex();
  return 1;
}

