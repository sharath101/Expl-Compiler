%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "expl.h"
	#include "expl.c"
	int yylex(void);
%}

%union{
	struct tnode *no;
	struct Paramstruct *pr;
	struct Gsymbol *gs;
	struct Lsymbol *ls;
	struct Typetable *ts;
	struct Fieldlist *fs;
	struct Classtable *cs;
}
%type <no> expr NUM TEXT ID Body END BEGIN1 Slist stmt input output asgn ifstmt whilestmt BREAK CONTINUE  
	       LDECL IDec Varlist LENDDECL var retstmt FdefBlock Fdef MainBlock LdeclBlock ArgList
	       GdeclBlock FID GENDDECL GDECL TYPE ENDTYPE TypeDefBlock TIDec Null initialize alloc Free
	       MIDec CFID CLASS ClassDefBlock Program SELF NEW
	  <gs> GidList Gid GIDec GDecl GdeclList
	  <ls> LidList LIDec LDecl LDecList
	  <pr> Param ParamList PID
	  <ts> Tname Type INT STR TID TypeDef TypeDefList CID MDecl MethodDecl Fld Fieldlists
	  <fs> FieldDecl FieldDeclList
	  <cs> Cname Classdef ClassDefList
	  
%token NUM TEXT ID PLUS MINUS MUL DIV MOD EQ BEGIN1 END READ WRITE POW IF ELSE THEN ENDIF WHILE DO ENDWHILE EQEQ 
	   NOTEQ GREAT GREATEQ LESS LESSEQ BREAK CONTINUE INT STR IDec Varlist LDECL LENDDECL GIDec MAIN RET PID
	   LIDec IdList GDeclBlock FID GDECL GENDDECL TID TYPE ENDTYPE Tname TIDec FDID Null initialize alloc FREE
	   CLASS ENDCLASS CID MIDec SELF CFID NEW EXTENDS
 
%left EQ EQEQ NOTEQ GREAT GREATEQ LESS LESSEQ
%left PLUS MINUS
%left MUL DIV
%left MOD
%left POW
%left '['

%%

Program :   TypeDefBlock ClassDefBlock GdeclBlock FdefBlock MainBlock	{printf("Program done\n");}
		  | TypeDefBlock ClassDefBlock GdeclBlock MainBlock				{printf("Program done\n");}
		  | TypeDefBlock GdeclBlock FdefBlock MainBlock					{printf("Program done\n");}
		  | TypeDefBlock ClassDefBlock MainBlock						{printf("Program done\n");}
		  | TypeDefBlock GdeclBlock MainBlock							{printf("Program done\n");}
		  | TypeDefBlock MainBlock										{printf("Program done\n");}
		  |	ClassDefBlock GdeclBlock FdefBlock MainBlock				{printf("Program done\n");}
		  | ClassDefBlock GdeclBlock MainBlock							{printf("Program done\n");}
		  | ClassDefBlock MainBlock										{printf("Program done\n");}
		  |	GdeclBlock FdefBlock MainBlock								{printf("Program done\n");}
		  | GdeclBlock MainBlock										{printf("Program done\n");}
		  | MainBlock													{printf("Program done\n");};
		  
TypeDefBlock  : TYPE TypeDefList ENDTYPE		{$$=$1;tdisplay();printf("--------------------Typedec done--------------------\n");}                
              ;

TypeDefList   : TypeDefList TypeDef
              | TypeDef
              ;

TypeDef       : Tname '{' FieldDeclList '}' 	{ 
													int size=GetSize($3);
													printf("%s: ",$1->name);
													fdisplay(froot);
													$1->size=size;
													$1->fields=froot;
													$$=$1;
													froot=NULL;
													fieldpos=1;
												}
              									;

FieldDeclList : FieldDeclList FieldDecl
              | FieldDecl					
              ;

FieldDecl    : Type TIDec ';' 					{$$= newfield($2->varname,$1);};

//--------------------------------------------------------------------------------------

ClassDefBlock 	: CLASS ClassDefList ENDCLASS
				;
ClassDefList 	: ClassDefList Classdef
               	| Classdef
				;
Classdef      	: Cname '{' LDECL Fieldlists MethodDecl LENDDECL FdefBlock '}'
											{
												if(fnum>8){
													printf("Class field limit exceeded\n");
													exit(1);
												}
												cfdisplay(cfroot);
												mdisplay(mroot);
												$$=Appendclass($1->name,cfroot,mroot,cnum,fnum,mnum);
												cnum++;
												fnum=0;
												mnum=0;
												cfroot=NULL;
												mroot=NULL;
												currclass=NULL;
												printf("-------------------------------Class %s done----------------------------\n",$1->name);
											}
				| Cname '{' LDECL MethodDecl LENDDECL FdefBlock '}'
											{
												mdisplay(mroot);
												$$=Appendclass($1->name,NULL,mroot,cnum,fnum,mnum);
												cnum++;
												fnum=0;
												mnum=0;
												cfroot=NULL;
												mroot=NULL;
												currclass=NULL;
												printf("-------------------------------Class %s done----------------------------\n",$1->name);
											}
				| Cname '{' LDECL Fieldlists LENDDECL FdefBlock '}'
											{
												if(fnum>8){
													printf("Class field limit exceeded\n");
													exit(1);
												}
												cfdisplay(cfroot);
												$$=Appendclass($1->name,cfroot,NULL,cnum,fnum,mnum);
												cnum++;
												fnum=0;
												mnum=0;
												cfroot=NULL;
												mroot=NULL;
												currclass=NULL;
												printf("-------------------------------Class %s done----------------------------\n",$1->name);
											}
				;
Cname         	: CID       				{Cptr = newclass($1->name,NULL); currclass=Cptr; $$=Cptr; classnum++;}      
				| CID EXTENDS CID			{Cptr = newclass($1->name,$3->name); currclass=Cptr; $$=Cptr; classnum++;}   
				;
Fieldlists 		: Fieldlists Fld
				| Fld   
				;     
Fld         	: Type MIDec ';'			{newcfield(Cptr,$1,$2->varname);}  
				;
MethodDecl 		: MethodDecl MDecl 
	   			| MDecl 
				;
MDecl      		: Type MIDec '(' ParamList ')' ';' 	{newcmethod(Cptr,$2->varname,$1,$4);lroot=NULL;} 	
				| Type MIDec '(' ')' ';'			{newcmethod(Cptr,$2->varname,$1,NULL);lroot=NULL;}							
				;

//--------------------------------------------------------------------------------------

GdeclBlock: GDECL GdeclList GENDDECL			{gdisplay();printf("--------------------Global done--------------------\n");$$=$1;}
		  | GDECL GENDDECL	;				

GdeclList : GdeclList GDecl | GDecl;

GDecl : 	Type GidList ';' {$$=$2;};

GidList : 	GidList ',' Gid | Gid;

Gid :  	 	GIDec							
		  | GIDec '(' ParamList ')' 		{$$= Appendgparam($1,$3);}  //also gives identity of function
		  | GIDec '(' ')'					{$$= Appendgparam($1,NULL);}
		  ;
//--------------------------------------------------------------------------------------

FdefBlock : FdefBlock Fdef | Fdef;

Fdef : Type FID '(' ParamList ')' '{' LdeclBlock Body '}' 
										{	
											struct Paramstruct *p;
											printf("Function name: %s\n",$2->text);
											if(currclass!=NULL){
												p=getmethodparam(currclass,$2->text);
												tLookup(currclass->name)->fields=cfroot;
											}
											else
												p=getparam($2->text);
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
											int f;
											if(currclass!=NULL)
												f=cmlookup(currclass,$2->text)->flabel;
											else
												f=getflabel($2->text);
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
											selflab=setlocalbinding($4,$8->Lentry);
											codegen($8,fptr);
											fclose(fptr);
											k=-1;
											lvar=0;
											selflab=0;
											printf("-------------------function %s done------------------\n",$2->text);
										}
	 | Type FID '(' ')' '{' LdeclBlock Body '}'
	 									{
											struct Paramstruct *p;
											printf("Function name: %s\n",$2->text);
											if(currclass!=NULL){
												p=getmethodparam(currclass,$2->text);
												tLookup(currclass->name)->fields=cfroot;
											}
											else
												p=getparam($2->text);
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
											int f;
											if(currclass!=NULL)
												f=cmlookup(currclass,$2->text)->flabel;
											else
												f=getflabel($2->text);
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
											selflab=setlocalbinding(NULL,$7->Lentry);
											codegen($7,fptr);
											fclose(fptr);
											k=-1;
											lvar=0;
											selflab=0;
											printf("-------------------function %s done------------------\n",$2->text);
										}
	 | Type FID '(' ParamList ')' '{' Body '}'
	 									{
											struct Paramstruct *p;
											printf("Function name: %s\n",$2->text);
											if(currclass!=NULL){
												p=getmethodparam(currclass,$2->text);
												tLookup(currclass->name)->fields=cfroot;
											}
											else
												p=getparam($2->text);
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
											int f;
											if(currclass!=NULL)
												f=cmlookup(currclass,$2->text)->flabel;
											else
												f=getflabel($2->text);
											fprintf(fptr,"F%d:\n",f);
											func[f]=2*pos+2056;
											fprintf(fptr, "PUSH BP\n");pos++;
											fprintf(fptr, "MOV BP, SP\n");pos++;
											selflab=setlocalbinding($4,$7->Lentry);
											codegen($7,fptr);
											fclose(fptr);
											k=-1;
											selflab=0;
											printf("-------------------function %s done------------------\n",$2->text);
										}
	 | Type FID '(' ')' '{' Body '}'
	 									{
											struct Paramstruct *p;
											printf("Function name: %s\n",$2->text);
											if(currclass!=NULL){
												p=getmethodparam(currclass,$2->text);
												tLookup(currclass->name)->fields=cfroot;
											}
											else
												p=getparam($2->text);
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
											int f;
											if(currclass!=NULL)
												f=cmlookup(currclass,$2->text)->flabel;
											else
												f=getflabel($2->text);
											fprintf(fptr,"F%d:\n",f);
											func[f]=2*pos+2056;
											fprintf(fptr, "PUSH BP\n");pos++;
											fprintf(fptr, "MOV BP, SP\n");pos++;
											selflab=-3;
											codegen($6,fptr);
											selflab=0;
											fclose(fptr);
											k=-1;
											printf("-------------------function %s done------------------\n",$2->text);
										}
										;

MainBlock : Type MAIN '(' ')' '{' LdeclBlock Body '}'
                                		{
                                			 printf("MAIN\n");
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
										     createvirtualtable(fptr);
											 fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
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
											 exitprogram(fptr);
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
                                			 printf("MAIN\n");
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
											 fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
											 fprintf(fptr, "MOV BP, SP\n");pos++;
											 codegen($6,fptr);
											 exitprogram(fptr);
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

          								
ParamList 	: ParamList ',' Param 				{$$ = Appendparam($1,$3);}
		  	| Param								{$$ = $1;}
		  	;
 
Param 		: Type PID							{$$=$2;};
	
LdeclBlock 	: LDECL LDecList LENDDECL 				
		   	| LDECL LENDDECL;

LDecList 	: LDecList LDecl | LDecl;

LDecl 		: Type LidList ';'	{$$=$2;};	

LidList 	: LidList ',' LIDec | LIDec;

Type       	: INT 								
	       	| STR
	       	| TID							
		   	;

//----------------------------------------------------------------------------------

Body 	: BEGIN1 Slist retstmt END 	{$$=makenode("filledlater",12,NULL,NULL,$2,NULL,$3);}
	    | BEGIN1 retstmt END 		{$$=makenode("filledlater",12,NULL,NULL,NULL,NULL,$2);printf("Nothing inside body\n");}
		                			;

Slist  	: Slist stmt					{$$ = makenode("connector",3,NULL,NULL,$1,NULL,$2);}
	 	| stmt     					;

stmt   	:  input ';' | output ';'| asgn ';'
		 | Free ';'  | ifstmt ';'| whilestmt ';'
		 | BREAK ';'				{$$=$1;}
	     | CONTINUE ';' 			{$$=$1;};

input  	: READ '(' var ')'        	{$$ = makenode("read",1,NULL,NULL,$3,NULL,NULL);};

output 	: WRITE '(' expr ')'       	{$$ = makenode("write",2,NULL,NULL,$3,NULL,NULL);}
		| WRITE '(' var ')'         {$$ = makenode("write",2,NULL,NULL,$3,NULL,NULL);};

asgn   	: var EQ expr            	{$$ = makenode("=",4,tint,NULL,$1,NULL,$3);}
		| var EQ var                {$$ = makenode("=",4,tint,NULL,$1,NULL,$3);}
		| var EQ initialize			{$$ = makenode("=",14,tint,NULL,$1,NULL,$3);}
		| var EQ NEW '(' ID ')' 	{$$ = makenode("=",4,tint,NULL,$1,$5,$3);}
		//| var EQ Null				{$$ = makenode("=",14,tint,NULL,$1,NULL,$3);}
		;

Free	: FREE '(' var ')'			{$$ = makenode("free",14,tint,NULL,$3,NULL,NULL);};
		
retstmt : RET expr ';'              {$$ = makenode("return",11,NULL,NULL,$2,NULL,NULL);}
		| RET var ';' 				{$$ = makenode("return",11,NULL,NULL,$2,NULL,NULL);};

ifstmt	: IF '(' expr ')' THEN Slist ELSE Slist ENDIF       {$$= makenode("ifelse",6,NULL,NULL,$3,$6,$8);}  
        | IF '(' expr ')' THEN Slist ENDIF		     		{$$= makenode("if",6,NULL,NULL,$3,$6,NULL);};

whilestmt: WHILE '(' expr ')' DO Slist ENDWHILE		    	{$$= makenode("while",5,NULL,NULL,$3,NULL,$6);};

ArgList	: var ',' var			{$$ = argconnect($1,$3);}
	   	| expr ',' var			{$$ = argconnect($1,$3);}
	   	| var ',' expr			{$$ = argconnect($1,$3);}
	   	| expr ',' expr			{$$ = argconnect($1,$3);}
	   	| ArgList ',' var		{$$ = argconnect($1,$3);}
	   	| ArgList ',' expr		{$$ = argconnect($1,$3);};

var		: ID 
		| CFID
		| var  '.' ID			{$$ = fieldconnect($1,$3);}
		//| var '.' CFID			{$$ = fieldconnect($1,$3);}
		//| CFID '.' ID			{printf("Variable of a class cannot access it's member fields\n");exit(1);}
		//| SELF '.' CFID			{$$ = makenode("self",15,$3->type,NULL,$3,NULL,NULL);}
		| SELF '.' ID			{$$ = makenode("self",15,$3->type,NULL,$3,NULL,NULL);}
	 	| var '[' var ']' 		{$$ = makearraynode($1->varname,$1->type,$3);}
	 	| var '[' expr ']'      {$$ = makearraynode($1->varname,$1->type,$3);};								

expr    : expr PLUS expr		{$$ = makenode("+",4,tint,NULL,$1,NULL,$3);}
	 	| expr MINUS expr  		{$$ = makenode("-",4,tint,NULL,$1,NULL,$3);}
		| expr MUL expr			{$$ = makenode("*",4,tint,NULL,$1,NULL,$3);}
	 	| expr DIV expr			{$$ = makenode("/",4,tint,NULL,$1,NULL,$3);}
	 	| expr MOD expr			{$$ = makenode("%",4,tint,NULL,$1,NULL,$3);}
	 	| expr POW expr        	{$$ = makenode("@",4,tint,NULL,$1,NULL,$3);}
	 	| expr LESS expr  		{$$ = makenode("<",4,tbool,NULL,$1,NULL,$3);}
	 	| expr GREAT expr		{$$ = makenode(">",4,tbool,NULL,$1,NULL,$3);}
	 	| expr LESSEQ expr		{$$ = makenode("<=",4,tbool,NULL,$1,NULL,$3);}
	 	| expr GREATEQ expr    	{$$ = makenode(">=",4,tbool,NULL,$1,NULL,$3);}
	 	| expr NOTEQ expr		{$$ = makenode("!=",4,tbool,NULL,$1,NULL,$3);}
	 	| expr EQEQ expr       	{$$ = makenode("==",4,tbool,NULL,$1,NULL,$3);}
	 	| '(' expr ')'			{$$ = $2;}
	 	| var PLUS expr			{$$ = makenode("+",4,tint,NULL,$1,NULL,$3);}
	 	| var MINUS expr  		{$$ = makenode("-",4,tint,NULL,$1,NULL,$3);}
		| var MUL expr			{$$ = makenode("*",4,tint,NULL,$1,NULL,$3);}
	 	| var DIV expr			{$$ = makenode("/",4,tint,NULL,$1,NULL,$3);}
	 	| var MOD expr			{$$ = makenode("%",4,tint,NULL,$1,NULL,$3);}
	 	| var POW expr        	{$$ = makenode("@",4,tint,NULL,$1,NULL,$3);}
	 	| var LESS expr  		{$$ = makenode("<",4,tbool,NULL,$1,NULL,$3);}
	 	| var GREAT expr		{$$ = makenode(">",4,tbool,NULL,$1,NULL,$3);}
	 	| var LESSEQ expr		{$$ = makenode("<=",4,tbool,NULL,$1,NULL,$3);}
	 	| var GREATEQ expr    	{$$ = makenode(">=",4,tbool,NULL,$1,NULL,$3);}
	 	| var NOTEQ expr		{$$ = makenode("!=",4,tbool,NULL,$1,NULL,$3);}
	 	| var EQEQ expr       	{$$ = makenode("==",4,tbool,NULL,$1,NULL,$3);}
	 	
	 	| expr PLUS var			{$$ = makenode("+",4,tint,NULL,$1,NULL,$3);}
	 	| expr MINUS var  		{$$ = makenode("-",4,tint,NULL,$1,NULL,$3);}
		| expr MUL var			{$$ = makenode("*",4,tint,NULL,$1,NULL,$3);}
	 	| expr DIV var			{$$ = makenode("/",4,tint,NULL,$1,NULL,$3);}
	 	| expr MOD var			{$$ = makenode("%",4,tint,NULL,$1,NULL,$3);}
	 	| expr POW var       	{$$ = makenode("@",4,tint,NULL,$1,NULL,$3);}
	 	| expr LESS var 		{$$ = makenode("<",4,tbool,NULL,$1,NULL,$3);}
	 	| expr GREAT var		{$$ = makenode(">",4,tbool,NULL,$1,NULL,$3);}
	 	| expr LESSEQ var		{$$ = makenode("<=",4,tbool,NULL,$1,NULL,$3);}
	 	| expr GREATEQ var    	{$$ = makenode(">=",4,tbool,NULL,$1,NULL,$3);}
	 	| expr NOTEQ var		{$$ = makenode("!=",4,tbool,NULL,$1,NULL,$3);}
	 	| expr EQEQ var       	{$$ = makenode("==",4,tbool,NULL,$1,NULL,$3);}
	 	
	 	| var PLUS var			{$$ = makenode("+",4,tint,NULL,$1,NULL,$3);}
	 	| var MINUS var  		{$$ = makenode("-",4,tint,NULL,$1,NULL,$3);}
		| var MUL var			{$$ = makenode("*",4,tint,NULL,$1,NULL,$3);}
	 	| var DIV var			{$$ = makenode("/",4,tint,NULL,$1,NULL,$3);}
	 	| var MOD var			{$$ = makenode("%",4,tint,NULL,$1,NULL,$3);}
	 	| var POW var       	{$$ = makenode("@",4,tint,NULL,$1,NULL,$3);}
	 	| var LESS var 			{$$ = makenode("<",4,tbool,NULL,$1,NULL,$3);}
	 	| var GREAT var			{$$ = makenode(">",4,tbool,NULL,$1,NULL,$3);}
	 	| var LESSEQ var		{$$ = makenode("<=",4,tbool,NULL,$1,NULL,$3);}
	 	| var GREATEQ var    	{$$ = makenode(">=",4,tbool,NULL,$1,NULL,$3);}
	 	| var NOTEQ var			{$$ = makenode("!=",4,tbool,NULL,$1,NULL,$3);}
	 	| var EQEQ var       	{$$ = makenode("==",4,tbool,NULL,$1,NULL,$3);}
	 	
	 	| var NOTEQ Null		{$$ = makenode("!=",14,tbool,NULL,$1,NULL,$3);}
	 	| var EQEQ Null			{$$ = makenode("==",14,tbool,NULL,$1,NULL,$3);}
	 	
	 	| ID '(' ')'            {$$ = makenode($1->varname,10,$1->type,NULL,NULL,NULL,NULL);}
	 	| ID '(' ArgList ')'	{$$ = makenode($1->varname,10,$1->type,$3,NULL,NULL,NULL);}
	 	| ID '(' var ')'		{$$ = makenode($1->varname,10,$1->type,$3,NULL,NULL,NULL);}
	 	| ID '(' expr ')'		{$$ = makenode($1->varname,10,$1->type,$3,NULL,NULL,NULL);}
	 	| var'.'ID'('ArgList')' {$$ = makemethodnode($1,$3->varname,10,$1->type,$5);}
	 	| var '.' ID '(' ')'    {$$ = makemethodnode($1,$3->varname,10,$1->type,NULL);}
	 	| var '.' ID '(' var ')'{$$ = makemethodnode($1,$3->varname,10,$1->type,$5);}
	 	| var'.'ID'(' expr ')'  {$$ = makemethodnode($1,$3->varname,10,$1->type,$5);}
	 	| SELF'.'ID'('ArgList')'{$$ = makemethodnode($1,$3->varname,10,$1->type,$5);}
	 	| SELF '.' ID '(' ')'   {$$ = makemethodnode($1,$3->varname,10,$1->type,NULL);}
	 	| SELF '.' ID '('var')' {$$ = makemethodnode($1,$3->varname,10,$1->type,$5);}
	 	| SELF'.'ID'(' expr ')' {$$ = makemethodnode($1,$3->varname,10,$1->type,$5);}
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
	TypeTableCreate();
	tint=tLookup("int");
	tbool=tLookup("bool");
	yyparse();	
	return 0;
}
