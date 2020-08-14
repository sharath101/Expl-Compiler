%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "5.h"
	#include "5.c"
	int yylex(void);
%}
													//reading from string
%union{
	struct tnode *no;
	struct Paramstruct *pr;
	struct Gsymbol *gs;
	struct Lsymbol *ls;
}
%type <no> expr NUM TEXT ID Body END BEGIN1 Slist stmt input output asgn ifstmt whilestmt BREAK CONTINUE  
	       Type INT STR LDECL IDec Varlist LENDDECL var retstmt FdefBlock Fdef MainBlock LdeclBlock ArgList
	       GdeclBlock GdeclList GDecl LDecList LDecl FID GENDDECL GDECL
	  <gs> GidList Gid GIDec
	  <ls> LidList LIDec
	  <pr> Param ParamList PID
%token NUM TEXT ID PLUS MINUS MUL DIV MOD EQ BEGIN1 END READ WRITE POW IF ELSE THEN ENDIF WHILE DO ENDWHILE 
	   EQEQ NOTEQ GREAT GREATEQ LESS LESSEQ BREAK CONTINUE INT STR IDec Varlist LDECL LENDDECL GIDec MAIN
	   RET PID LIDec IdList GDeclBlock FID GDECL GENDDECL

%left EQ EQEQ NOTEQ GREAT GREATEQ LESS LESSEQ
%left PLUS MINUS
%left MUL DIV
%left MOD
%left POW
%left '['

%%

Program : 	GdeclBlock FdefBlock MainBlock		{printf("Program done\n");}
		  | GdeclBlock MainBlock				{printf("Program done\n");}
		  | MainBlock							{printf("Program done\n");};

GdeclBlock: GDECL GdeclList GENDDECL			{gdisplay();printf("--------------------Global done--------------------\n");$$=$1;}
		  | GDECL GENDDECL	;				

GdeclList : GdeclList GDecl | GDecl;

GDecl : 	Type GidList ';' ;

GidList : 	GidList ',' Gid | Gid;

Gid :  	 	GIDec							
		  | GIDec '(' ParamList ')' 		{$$= Appendgparam($1,$3);}  //also gives identity of function
		  | GIDec '(' ')'					{$$= Appendgparam($1,NULL);}
		  ;
//--------------------------------------------------------------------------------------

FdefBlock : FdefBlock Fdef | Fdef;

Fdef : Type FID '(' ParamList ')' '{' LdeclBlock Body '}' 
										{	
											struct Paramstruct *p=getparam($2->text);
											if(!checkparamlist($4,p)){
												printf("Function parameters don't match with the declaration\n");
												exit(1);
											}
											$8->Lentry=lroot;
											proot=$4;
											fname=(char*)malloc(sizeof(char));
											strcpy(fname,$2->text);
											strcpy($8->varname,$2->text);
											$8->right->Lentry=lroot;
											ldisplay();
											lroot=NULL;
											$$=$8;
											printf("Codegen start\n");
											FILE *fptr = fopen("target.xsm", "a");
											if(beginflag==1){
												fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
												fprintf(fptr, "JMP MAIN\n");pos++;
												beginflag=0;
											}
											int f=getflabel($2->text);
											fprintf(fptr,"F%d:\n",f);
											func[f]=2*pos+2056;
											fprintf(fptr, "PUSH BP\n");pos++;
											fprintf(fptr, "MOV BP, SP\n");pos++;
											struct Lsymbol *l=$8->Lentry;
											struct Paramstruct *par=$4;
											int y=getreg();
											if(par==NULL || l==NULL){
												printf("Parameterlist is NULL\n");
												exit(1);
											}
											else if(par!=NULL && l!=NULL){
												while(p->next!=NULL){
													p=p->next;
													l=l->next;
												}
												if(l->next==NULL){
													printf("Nothing in local declaration block\n");
													exit(1);
												}
												else
													l=l->next;
												while(l->next!=NULL){
													fprintf(fptr, "PUSH R%d\n",y);pos++;lvar++; 
													l=l->next;
												}
												fprintf(fptr, "PUSH R%d\n",y);pos++;lvar++;
											}
											freereg();
											setlocalbinding($4,$8->Lentry);
											codegen($8,fptr);
											fclose(fptr);
											k=-1;
											lvar=0;
											printf("-------------------function %s done------------------\n",$2->text);
										}
	 | Type FID '(' ')' '{' LdeclBlock Body '}'
	 									{
											struct Paramstruct *p=getparam($2->text);
											if(p!=NULL){
												printf("Function parameters don't match with the declaration\n");
												exit(1);
											}
											$7->Lentry=lroot;
											proot=NULL;
											fname=(char*)malloc(sizeof(char));
											strcpy(fname,$2->text);
											strcpy($7->varname,$2->text);
											$7->right->Lentry=lroot;
											ldisplay();
											lroot=NULL;
											$$=$7;
											printf("Codegen start\n");
											FILE *fptr = fopen("target.xsm", "a");
											if(beginflag==1){
												fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
												fprintf(fptr, "JMP MAIN\n");pos++;
												beginflag=0;
											}
											int f=getflabel($2->text);
											fprintf(fptr,"F%d:\n",f);
											func[f]=2*pos+2056;
											fprintf(fptr, "PUSH BP\n");pos++;
											fprintf(fptr, "MOV BP, SP\n");pos++;
											if($7->Lentry!=NULL){
												struct Lsymbol *l=$7->Lentry;
												int y=getreg();
												while(l->next!=NULL){
													fprintf(fptr, "PUSH R%d\n",y);pos++;lvar++; //empty space
													l=l->next;
												}
												fprintf(fptr, "PUSH R%d\n",y);pos++;lvar++; 
												freereg();
											}
											setlocalbinding(NULL,$7->Lentry);
											codegen($7,fptr);
											fclose(fptr);
											k=-1;
											lvar=0;
											printf("-------------------function %s done------------------\n",$2->text);
										}
	 | Type FID '(' ParamList ')' '{' Body '}'
	 									{
											struct Paramstruct *p=getparam($2->text);
											if(!checkparamlist($4,p)){
												printf("Function parameters don't match with the declaration\n");
												exit(1);
											}
											$7->Lentry=lroot;
											proot=$4;
											fname=(char*)malloc(sizeof(char));
											strcpy(fname,$2->text);
											strcpy($7->varname,$2->text);
											$7->right->Lentry=lroot;
											ldisplay();
											lroot=NULL;
											$$=$7;
											printf("Codegen start\n");
											FILE *fptr = fopen("target.xsm", "a");
											if(beginflag==1){
												fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
												fprintf(fptr, "JMP MAIN\n");pos++;
												beginflag=0;
											}
											int f=getflabel($2->text);
											fprintf(fptr,"F%d:\n",f);
											func[f]=2*pos+2056;
											fprintf(fptr, "PUSH BP\n");pos++;
											fprintf(fptr, "MOV BP, SP\n");pos++;
											setlocalbinding($4,$7->Lentry);
											codegen($7,fptr);
											fclose(fptr);
											k=-1;
											printf("-------------------function %s done------------------\n",$2->text);
										}
	 | Type FID '(' ')' '{' Body '}'
	 									{
											struct Paramstruct *p=getparam($2->text);
											if(p!=NULL){
												printf("Function parameters don't match with the declaration\n");
												exit(1);
											}
											$6->Lentry=NULL;
											proot=NULL;
											fname=(char*)malloc(sizeof(char));
											strcpy(fname,$2->text);
											strcpy($6->varname,$2->text);
											$6->right->Lentry=lroot;
											ldisplay();
											lroot=NULL;
											$$=$6;
											printf("Codegen start\n");
											FILE *fptr = fopen("target.xsm", "a");
											if(beginflag==1){
												fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
												fprintf(fptr, "JMP MAIN\n");pos++;
												beginflag=0;
											}
											int f=getflabel($2->text);
											fprintf(fptr,"F%d:\n",f);
											func[f]=2*pos+2056;
											fprintf(fptr, "PUSH BP\n");pos++;
											fprintf(fptr, "MOV BP, SP\n");pos++;
											codegen($6,fptr);
											fclose(fptr);
											k=-1;
											printf("-------------------function %s done------------------\n",$2->text);
										}
										;

MainBlock : Type MAIN '(' ')' '{' LdeclBlock Body '}'
                                		{
                     						 $7->Lentry=lroot;
                     						 fname=(char*)malloc(sizeof(char));
                     						 strcpy(fname,"main");
                                   			 $$=$7;
                                   			 ldisplay();
                                   			 printf("Codegen start\n");
											 FILE *fptr = fopen("target.xsm", "a");
											 if(beginflag==1){
												 fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
												 beginflag=0;
											 }
											 fprintf(fptr,"MAIN:\n");
											 mainl=2*pos+2056;
											 fprintf(fptr, "MOV BP, SP\n");pos++;
											 if($7->Lentry!=NULL){
											 	struct Lsymbol *l=$7->Lentry;
											 	int y=getreg();
											 	while(l->next!=NULL){
													 fprintf(fptr, "PUSH R%d\n",y);pos++;lvar++; //empty space
												 	l=l->next;
											 	}
											 	fprintf(fptr, "PUSH R%d\n",y);pos++;lvar++; 
											 	freereg();
											 }
											 setlocalbinding(NULL,$7->Lentry);
											 codegen($7,fptr);
											 fprintf(fptr, "PASS");pos++;
											 fclose(fptr);
											 k=-1;
											 FILE *fptr2 = fopen("array.c", "w");
											 fprintf(fptr2,"int a[100]={");
											 for(int i=0;i<r;i++){
												 if(i==0)
												 	 fprintf(fptr2,"%d",a[i]);
												 else
													 fprintf(fptr2,",%d",a[i]);
											 }
											 fprintf(fptr2,"};\n");
											 fprintf(fptr2,"int f[100]={0");
											 for(int i=1;i<flabel;i++)
												 fprintf(fptr2,",%d",func[i]);
											 fprintf(fptr2,"};\n");
											 fprintf(fptr2,"int mainl=%d;",mainl);
                                   			 printf("--------------------Main done-----------------------\n");
                                		}
          									
          | Type MAIN '(' ')' '{' Body '}'
                                		{
                     						 $6->Lentry=lroot;
                     						 fname=(char*)malloc(sizeof(char));
                     						 strcpy(fname,"main");
                                   			 $$=$6;
                                   			 ldisplay();
                                   			 printf("Codegen start\n");
											 FILE *fptr = fopen("target.xsm", "a");
											 if(beginflag==1){
												 fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
											 	 beginflag=0;
											 }
											 fprintf(fptr,"MAIN:\n");
											 mainl=2*pos+2056;
											 fprintf(fptr, "MOV BP, SP\n");pos++;
											 codegen($6,fptr);
											 fprintf(fptr, "PASS");pos++;
											 fclose(fptr);
											 k=-1;
											 FILE *fptr2 = fopen("array.c", "w");
											 fprintf(fptr2,"int a[100]={");
											 for(int i=0;i<r;i++){
												 if(i==0)
												 	 fprintf(fptr2,"%d",a[i]);
												 else
													 fprintf(fptr2,",%d",a[i]);
											 }
											 fprintf(fptr2,"};\n");
											 fprintf(fptr2,"int f[100]={0");
											 for(int i=1;i<flabel;i++)
												 fprintf(fptr2,",%d",func[i]);
											 fprintf(fptr2,"};\n");
											 fprintf(fptr2,"int mainl=%d;",mainl);
                                   			 printf("--------------------Main done-----------------------\n");
                                		}	
                                		;						

          								
ParamList : ParamList ',' Param 			{$$ = Appendparam($1,$3);}
		  | Param							{$$ = $1;}
		  ;
 
Param : 	Type PID						{$$=$2;};
	
LdeclBlock : LDECL LDecList LENDDECL 				
		   | LDECL LENDDECL;

LDecList : LDecList LDecl | LDecl;

LDecl : Type LidList ';' ;

LidList : LidList ',' LIDec | LIDec;

Type : INT 								
	| STR							
		;

//----------------------------------------------------------------------------------

Body : BEGIN1 Slist retstmt END 	{$$=makenode("filledlater",12,-1,NULL,$2,NULL,$3);}
	    | BEGIN1 retstmt END 		{printf("Nothing inside body\n");exit(1);}
		                			;

Slist  : Slist stmt					{$$ = makenode("connector",3,-1,NULL,$1,NULL,$2);}
	 	| stmt     					;

stmt   : input ';' | output ';'| asgn ';'
		 | ifstmt ';'| whilestmt ';'
		 | BREAK ';'				{$$=$1;}
	     | CONTINUE ';' 			{$$=$1;};

input  : READ '(' var ')'        	{$$ = makenode("read",1,-1,NULL,$3,NULL,NULL);};

output : WRITE '(' expr ')'       	{$$ = makenode("write",2,-1,NULL,$3,NULL,NULL);}
		|WRITE '(' var ')'          {$$ = makenode("write",2,-1,NULL,$3,NULL,NULL);};

asgn   : var EQ expr            	{$$ = makenode("=",4,2,NULL,$1,NULL,$3);}
		|var EQ var                 {$$ = makenode("=",4,2,NULL,$1,NULL,$3);};
		
retstmt : RET expr ';'              {$$ = makenode("return",11,2,NULL,$2,NULL,NULL);}	
		| RET var ';' 				{$$ = makenode("return",11,2,NULL,$2,NULL,NULL);};

ifstmt:  IF '(' expr ')' THEN Slist ELSE Slist ENDIF        {$$= makenode("ifelse",6,-1,NULL,$3,$6,$8);}  
        |IF '(' expr ')' THEN Slist ENDIF		     		{$$= makenode("if",6,-1,NULL,$3,$6,NULL);};

whilestmt: WHILE '(' expr ')' DO Slist ENDWHILE		    	{$$= makenode("while",5,-1,NULL,$3,NULL,$6);};

ArgList: var ',' var			{$$ = argconnect($1,$3);}
	   | expr ',' var			{$$ = argconnect($1,$3);}
	   | var ',' expr			{$$ = argconnect($1,$3);}
	   | expr ',' expr			{$$ = argconnect($1,$3);}
	   | ArgList ',' var		{$$ = argconnect($1,$3);}
	   | ArgList ',' expr		{$$ = argconnect($1,$3);};

var: ID 
	 | var '[' var ']' 			{$$ = makearraynode($1->varname,2,$1->type,$3);}
	 | var '[' expr ']'         {$$ = makearraynode($1->varname,2,$1->type,$3);};								

expr   :  expr PLUS expr		{$$ = makenode("+",4,2,NULL,$1,NULL,$3);}
	 	| expr MINUS expr  		{$$ = makenode("-",4,2,NULL,$1,NULL,$3);}
		| expr MUL expr			{$$ = makenode("*",4,2,NULL,$1,NULL,$3);}
	 	| expr DIV expr			{$$ = makenode("/",4,2,NULL,$1,NULL,$3);}
	 	| expr MOD expr			{$$ = makenode("%",4,2,NULL,$1,NULL,$3);}
	 	| expr POW expr        	{$$ = makenode("@",4,2,NULL,$1,NULL,$3);}
	 	| expr LESS expr  		{$$ = makenode("<",4,1,NULL,$1,NULL,$3);}
	 	| expr GREAT expr		{$$ = makenode(">",4,1,NULL,$1,NULL,$3);}
	 	| expr LESSEQ expr		{$$ = makenode("<=",4,1,NULL,$1,NULL,$3);}
	 	| expr GREATEQ expr    	{$$ = makenode(">=",4,1,NULL,$1,NULL,$3);}
	 	| expr NOTEQ expr		{$$ = makenode("!=",4,1,NULL,$1,NULL,$3);}
	 	| expr EQEQ expr       	{$$ = makenode("==",4,1,NULL,$1,NULL,$3);}
	 	| '(' expr ')'			{$$ = $2;}                   
	 	| var PLUS expr			{$$ = makenode("+",4,2,NULL,$1,NULL,$3);}
	 	| var MINUS expr  		{$$ = makenode("-",4,2,NULL,$1,NULL,$3);}
		| var MUL expr			{$$ = makenode("*",4,2,NULL,$1,NULL,$3);}
	 	| var DIV expr			{$$ = makenode("/",4,2,NULL,$1,NULL,$3);}
	 	| var MOD expr			{$$ = makenode("%",4,2,NULL,$1,NULL,$3);}
	 	| var POW expr        	{$$ = makenode("@",4,2,NULL,$1,NULL,$3);}
	 	| var LESS expr  		{$$ = makenode("<",4,1,NULL,$1,NULL,$3);}
	 	| var GREAT expr		{$$ = makenode(">",4,1,NULL,$1,NULL,$3);}
	 	| var LESSEQ expr		{$$ = makenode("<=",4,1,NULL,$1,NULL,$3);}
	 	| var GREATEQ expr    	{$$ = makenode(">=",4,1,NULL,$1,NULL,$3);}
	 	| var NOTEQ expr		{$$ = makenode("!=",4,1,NULL,$1,NULL,$3);}
	 	| var EQEQ expr       	{$$ = makenode("==",4,1,NULL,$1,NULL,$3);}
	 	
	 	| expr PLUS var			{$$ = makenode("+",4,2,NULL,$1,NULL,$3);}
	 	| expr MINUS var  		{$$ = makenode("-",4,2,NULL,$1,NULL,$3);}
		| expr MUL var			{$$ = makenode("*",4,2,NULL,$1,NULL,$3);}
	 	| expr DIV var			{$$ = makenode("/",4,2,NULL,$1,NULL,$3);}
	 	| expr MOD var			{$$ = makenode("%",4,2,NULL,$1,NULL,$3);}
	 	| expr POW var       	{$$ = makenode("@",4,2,NULL,$1,NULL,$3);}
	 	| expr LESS var 		{$$ = makenode("<",4,1,NULL,$1,NULL,$3);}
	 	| expr GREAT var		{$$ = makenode(">",4,1,NULL,$1,NULL,$3);}
	 	| expr LESSEQ var		{$$ = makenode("<=",4,1,NULL,$1,NULL,$3);}
	 	| expr GREATEQ var    	{$$ = makenode(">=",4,1,NULL,$1,NULL,$3);}
	 	| expr NOTEQ var		{$$ = makenode("!=",4,1,NULL,$1,NULL,$3);}
	 	| expr EQEQ var       	{$$ = makenode("==",4,1,NULL,$1,NULL,$3);}
	 	
	 	| var PLUS var			{$$ = makenode("+",4,2,NULL,$1,NULL,$3);}
	 	| var MINUS var  		{$$ = makenode("-",4,2,NULL,$1,NULL,$3);}
		| var MUL var			{$$ = makenode("*",4,2,NULL,$1,NULL,$3);}
	 	| var DIV var			{$$ = makenode("/",4,2,NULL,$1,NULL,$3);}
	 	| var MOD var			{$$ = makenode("%",4,2,NULL,$1,NULL,$3);}
	 	| var POW var       	{$$ = makenode("@",4,2,NULL,$1,NULL,$3);}
	 	| var LESS var 			{$$ = makenode("<",4,1,NULL,$1,NULL,$3);}
	 	| var GREAT var			{$$ = makenode(">",4,1,NULL,$1,NULL,$3);}
	 	| var LESSEQ var		{$$ = makenode("<=",4,1,NULL,$1,NULL,$3);}
	 	| var GREATEQ var    	{$$ = makenode(">=",4,1,NULL,$1,NULL,$3);}
	 	| var NOTEQ var			{$$ = makenode("!=",4,1,NULL,$1,NULL,$3);}
	 	| var EQEQ var       	{$$ = makenode("==",4,1,NULL,$1,NULL,$3);}
	 	
	 	| var '(' ')'           {$$ = makenode($1->varname,10,2,NULL,NULL,NULL,NULL);}
	 	| var '(' ArgList ')'	{$$ = makenode($1->varname,10,2,$3,NULL,NULL,NULL);}
	 	| var '(' var ')'		{$$ = makenode($1->varname,10,2,$3,NULL,NULL,NULL);}
	 	| var '(' expr ')'		{$$ = makenode($1->varname,10,2,$3,NULL,NULL,NULL);}
	 	| NUM					{$$ = $1;}
	 	| TEXT                 	{$$ = $1;}
	 	;

%%

yyerror(char *s)
{
    printf("yyerror %s\n",s);
}


int main(void) {
	extern FILE *yyin;
  	yyin = fopen("Input", "r");
  	FILE *fptr = fopen("target.xsm", "w");
  	fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
	fprintf(fptr, "BRKP\n");
	fclose(fptr);
	yyparse();	
	return 0;
}
