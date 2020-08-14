int k=-1,r=0,ch=0,idaddr=4096,temp1[100],temp2[100];
int whilenum=0,flabel=1;
struct Gsymbol *groot=NULL;
struct Lsymbol *lroot=NULL;
struct Paramstruct *proot=NULL;
char *fname;
int pos=1;    
int beginflag=1;   
int a[1000],func[1000],mainl;      //for label translation
int lvar=0;
     
/*------------------------------GLOBAL START-----------------------------*/
struct Gsymbol *newgid(char *nam, int type, int size){
	struct Gsymbol *temp1;
    temp1 = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    temp1->name = malloc(sizeof(char));
    strcpy(temp1->name,nam);
    temp1->type=type;
    temp1->size=size;
    temp1->binding=idaddr;
    temp1->next=NULL;
    idaddr+=size;
    if(groot==NULL)
    	groot=temp1;
    else{
    	struct Gsymbol *p;
    	p=groot;
    	while(p->next!=NULL)
    		p=p->next;
    	p->next=temp1;
    }
    return temp1;
}

struct Gsymbol *Appendgparam(struct Gsymbol *gs,struct Paramstruct *ps){
	idaddr--;
	gs->size=-1;
	gs->binding=-1;
	if(ps!=NULL)
		gs->paramlist=ps;	
	else
		gs->paramlist=NULL;
	gs->flabel=flabel;
	flabel++;
	return gs;
}

struct Gsymbol *gLookup(char *name){
	struct Gsymbol *p;
	p=groot;
	while(p->next!=NULL){
    	if(!strcmp(p->name,name))
    		break;
    	p=p->next;  
    }	
    if(!strcmp(p->name,name))
    	return p;
    else
    	return NULL;
}         

int checkgvar(char *var){
	struct Gsymbol *p;
	if(groot==NULL)
		return 1;
	p=groot;
	int f=1;
	while(p->next!=NULL){
    	if(!strcmp(p->name,var)){
    		f=0;
    		break;
    	}
    	p=p->next;  
    }
    if(!strcmp(p->name,var))
    	f=0;
    return f;
}

int getflabel(char* name){
	struct Gsymbol *p;
	p=groot;
	while(p->next!=NULL){
		if(!strcmp(p->name,name)){
			if(p->flabel==0){
				printf("Function was declared as a variable\n");
				exit(1);
			}
			return p->flabel;
		}
		p=p->next;
	}
	if(strcmp(p->name,name)){
		printf("function not found in getflabel\n");
		exit(1);
	}
	if(p->flabel==0){
		printf("Function was declared as a variable\n");
		exit(1);
	}
	return p->flabel;
}

void gdisplay(){
	struct Gsymbol *p;
	if(groot==NULL){
		printf("Local Variables: No elements\n");
		return;	
	}
	p=groot;
	printf("Global Variables: ");
	while(p->next!=NULL){
    	printf("%s->",p->name);
    	p=p->next;  
    }
    printf("%s\n",p->name);
}

/*------------------------------GLOBAL END-----------------------------*/

/*------------------------------LOCAL START-----------------------------*/

struct Lsymbol *newlid(char *nam, int type){
	struct Lsymbol *temp1;
    temp1 = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));
    temp1->name = malloc(sizeof(char));
    strcpy(temp1->name,nam);
    temp1->type=type;
    temp1->binding=0;
    temp1->next=NULL;
    if(lroot==NULL)
    	lroot=temp1;
    else{
    	struct Lsymbol *p;
    	p=lroot;
    	while(p->next!=NULL)
    		p=p->next;
    	p->next=temp1;
    }
    return temp1;
}

struct Lsymbol *Appendlocal(struct Lsymbol *first, struct Lsymbol *second){
	struct Lsymbol *p;
	p=first;
	while(p->next!=NULL)
		p=p->next;
	p->next=second;
	return first;	
}

int checklvar(char *var){
	struct Lsymbol *p;
	if(lroot==NULL)
		return 1;
	p=lroot;
	int f=1;
	while(p->next!=NULL){
    	if(!strcmp(p->name,var)){
    		f=0;
    		break;
    	}
    	p=p->next;  
    }
    if(!strcmp(p->name,var))
    	f=0;	
    return f;
}

struct Lsymbol *lLookup(char *name){
	struct Lsymbol *p;
	p=lroot;
	while(p->next!=NULL){
    	if(!strcmp(p->name,name))
    		break;
    	p=p->next;  
    }	
    if(!strcmp(p->name,name))
    	return p;
    else
    	return NULL;
}   

void setlocalbinding(struct Paramstruct *param,struct Lsymbol *lsym){
	int i;
	if(lsym==NULL){
		return;
	}
	struct Paramstruct *p;
	struct Lsymbol *l;
	if(param==NULL){
		p=NULL;
		l=lsym;
		goto a9;
	}
	else
		p=param;
	l=lsym;
	i=-3;
	while(p->next!=NULL){
		l->binding=i;
		p=p->next;
		l=l->next;
		--i;
	}
	l->binding=i;
	if(l->next==NULL){
		printf("No Local variables\n");
		return;
	}
	l=l->next;
a9:	i=1;
	while(l->next!=NULL){
		l->binding=i;
		l=l->next;
		++i;
	}
	l->binding=i;
	return;
}

void ldisplay(){
	struct Lsymbol *p;
	if(lroot==NULL){
		printf("Local Variables: No elements\n");
		return;	
	}
	p=lroot;
	printf("Local Variables: ");
	while(p->next!=NULL){
    	printf("%s->",p->name);
    	p=p->next;  
    }
    printf("%s\n",p->name);
}

/*------------------------------LOCAL END-----------------------------*/

/*------------------------------PARAM START------------------------------*/

struct Paramstruct *newparam(char* name, int type){
	struct Paramstruct *temp;
    temp = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
    temp->name = malloc(sizeof(char));	
    strcpy(temp->name, name);
    temp->type=type;
    temp->next=NULL;
    return temp;
}

struct Paramstruct *Appendparam(struct Paramstruct *first, struct Paramstruct *second){
	struct Paramstruct *p=first;
	while(p->next!=NULL)
		p=p->next;
	p->next=second;
	return first;	
}

struct Paramstruct *getparam(char* name){
	struct Gsymbol *p;
	p=groot;
	while(p->next!=NULL){
		if(!strcmp(p->name,name)){
			if(p->paramlist==NULL){
				printf("nothing in paramlist\n");
				return NULL;
			}
			return p->paramlist;
		}
		p=p->next;
	}
	if(strcmp(p->name,name)){
		printf("function not found in getparam\n");
		exit(1);
	}
	if(p->paramlist==NULL){
		printf("nothing in paramlist\n");
		return NULL;
	}
	return p->paramlist;
}

int checkparamlist(struct Paramstruct *first, struct Paramstruct *second){
	int f=1;
	struct Paramstruct *f1=first;
	struct Paramstruct *r=second;
	while(f1->next!=NULL && r->next!=NULL){
		if(f1->next==NULL || r->next==NULL){
			f=0;
			break;
		}
		if(strcmp(f1->name,r->name) || f1->type!=r->type){
			f=0;
			break;
		}
		f1=f1->next;
		r=r->next;
	}
	if(strcmp(f1->name,r->name) || f1->type!=r->type)
		f=0;
	return f;
}

int checkarg(struct tnode *arg, struct Paramstruct *par){
	if((arg==NULL && par!=NULL) || (arg!=NULL && par==NULL))
		return 0;
	if(arg==NULL && par==NULL)
		return 1;
	struct tnode *t=arg;
	struct Paramstruct *p=par;
	while(t->argp!=NULL || p->next!=NULL){
		if(t->argp==NULL || p->next==NULL)
			return 0;
		if(t->type!=p->type){
			return 0;
		}
		t=t->argp;
		
		p=p->next;
	}
	if(t->type!=p->type)
		return 0;
	return 1;
}
	
int argdisplay(struct tnode *arg){
	int sum=0;
	struct tnode *p;
	if(arg==NULL){
		printf("NO arguments\n");
		return 0;	
	}
	p=arg;
	printf("arguments: ");
	while(p->argp!=NULL){
		if(p->varname==NULL)
    		{printf("num->");sum++;}
    	else
    		{printf("%s->",p->varname);sum++;}
    	p=p->argp;  
    }
    if(p->varname==NULL)
    	{printf("num\n");sum++;}
    else
    	{printf("%s\n",p->varname);sum++;}
    return sum;
}
/*------------------------------PARAM END------------------------------*/

/*------------------------------NODE START------------------------------*/

struct tnode* makeleaf(char c,int nt)
{
	struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    temp->type = 0;
    temp->val = 0;
	*(temp->varname) = c;
	temp->Gentry=NULL;
	temp->nodetype = nt;
    temp->left = NULL;
    temp->mid = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeleafnum(int n,char *text,int type)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->text = malloc(sizeof(char));
    if(text==NULL)
    	temp->text = NULL;                            //Type:
    else											  //2: Integer
    	strcpy(temp->text,text);					  //3: String
    temp->type = type;
    temp->val = n;
	temp->varname = NULL;
	temp->nodetype = 0;
	temp->Gentry=NULL;
	temp->argp=NULL;
    temp->left = NULL;
    temp->mid = NULL;
    temp->right = NULL;
    return temp;
}
struct tnode* makearraynode(char* var,int nt,int type,struct tnode *l){
	struct tnode *temp;                            
    temp = (struct tnode*)malloc(sizeof(struct tnode));   
	temp->varname = malloc(sizeof(char));
	if(checkgvar(var)){
		printf("Variable not declared\n");
		exit(1);
	}
	if(l->type==booltype){
		printf("Type mismatch boolean-integer/string-integer\n");
		exit(1);
	}
	temp->Gentry=gLookup(var);
    if(temp->Gentry==NULL){
		printf("Variable Lookup error\n");
		exit(1);
	} 
	strcpy(temp->varname,var);
	temp->type=type;
	temp->nodetype=9;
	temp->left=l;
	temp->mid = NULL;
    temp->right = NULL;
}

struct tnode* makeleafvar(char* var,int narg, int type)
{
    struct tnode *temp;                                        //Typearg:
    temp = (struct tnode*)malloc(sizeof(struct tnode));        //10: variable
	temp->varname = malloc(sizeof(char));                      //20: array with integer arg
	temp->arg = malloc(sizeof(char));						   //30: array with variable arg
    temp->type = type;                   //type;                 
    temp->val = narg;                    // For arrays
    if(!checklvar(var)){
    	//printf("enter1\n");
    	temp->Lentry=lLookup(var);
    	if(temp->Lentry==NULL){
    		printf("Error finding variable\n");
    		exit(1);
    	}
    	temp->Gentry=NULL;
    }
    else{
		//printf("enter2\n");
		temp->Gentry=gLookup(var); 
		if(temp->Gentry==NULL){
    		printf("Error finding variable\n");
    		exit(1);
    	}
		temp->Lentry=NULL;
	}
	strcpy(temp->varname,var);
	temp->nodetype = 0;
	temp->arglist = NULL;
	temp->argp = NULL;
    temp->left = NULL;
    temp->mid = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* argconnect(struct tnode *first,struct tnode *second){
	struct tnode* p;	
	p=first;
	while(p->argp!=NULL)
		p=p->argp;
	p->argp=second;
	return first;
}

struct tnode* makenode(char *c,int nt,int t,struct tnode *arg,struct tnode *l,struct tnode *m,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->varname = malloc(sizeof(char));
	if(nt==4 && t==inttype){
		if(l->type==booltype || r->type==booltype){
			printf("Type mismatch boolean-integer/string-integer\n");
			exit(1);
		}
	}
	if(nt==4){
		if(l->type!=r->type){
			printf("Type mismatch string-integer\n");
			exit(1);	
		}
	}	
	if(nt==5 || nt==6){
		if(l->type==inttype){
			printf("Type mismatch boolean/integer\n");
			exit(1);
		}
	}
    strcpy(temp->varname,c);
    temp->Gentry=NULL;
	temp->type = t;
    temp->val = 0;
	temp->nodetype = nt;
	temp->arglist = arg;
	temp->argp = NULL;
	temp->left = l;
    temp->right = r;
    temp->mid = m;
    return temp;
}

/*------------------------------NODE END------------------------------*/

/*------------------------------CODEGEN-------------------------------*/

void pusharg(struct tnode *targ,FILE *target){
	if(targ->argp==NULL){
		int i;
		i=codegen(targ,target);		
		fprintf(target, "PUSH R%d\n",i);pos++;
		freereg();
		return;
	}                                                // check for more than 1 arg function
	pusharg(targ->argp,target);
	int i;
	i=codegen(targ,target);		
	fprintf(target, "PUSH R%d\n",i);pos++;
	freereg();
	return;
}
	
int codegen(struct tnode *t,FILE *target){
	int p=-1,q=-1,addr;	
	if(t->nodetype == 12){                                            //BODY
		if(t->left==NULL )
			printf("No body\n");
		if(t->right==NULL)
			printf("No return\n");
		p=codegen(t->left,target);
		q=codegen(t->right,target);
		if(p!=-1 || q!=-1){
			printf("body error\n");
			exit(1);
		}
		return -1;
	}
	
	else if(t->nodetype == 10){											   //FCALL
		int regs=k;
		for(int i=0;i<=regs;i++){
			fprintf(target, "PUSH R%d\n",i);
			pos++;
		}
		printf("%s:---", t->varname);
		int argnum= argdisplay(t->arglist);
		struct Paramstruct *par=getparam(t->varname);
		if(!checkarg(t->arglist,par)){
			printf("Arguments don't match function definition\n");
			exit(1);	
		}
		if(t->arglist!=NULL)
			pusharg(t->arglist,target);
		int y=getreg();
		fprintf(target, "PUSH R%d\n",y);pos++; //return value
		freereg();
		int e=getflabel(t->varname);
		fprintf(target, "CALL F%d\n",e);pos++;
		p=getreg();
		fprintf(target, "POP R%d\n",p);pos++;
		q=getreg();
		for(int i=0;i<argnum;i++){
			fprintf(target, "POP R%d\n",q);
			pos++;
		}
		freereg();
		for(int i=regs;i>=0;i--){           //new reg declared 
			fprintf(target, "POP R%d\n",i);
			pos++;
		}
		return p;
	}
	
	else if(t->nodetype == 11){											   //RETURN
		if(!strcmp(fname,"main")){
			if(t->left== NULL || t->left->type!=inttype){
				printf("Return type mismatch\n");
				exit(1);
			}
			for(int i=0;i<lvar;i++)
				{fprintf(target,"POP R%d\n",q);pos++;}
			return -1;
		}	
		int type;
		type=gLookup(fname)->type;
		if(t->left== NULL || t->left->type!=type){
			printf("Return type mismatch\n");
			exit(1);
		}
		q=getreg();
		p=codegen(t->left,target);
		for(int i=0;i<lvar;i++)
			{fprintf(target,"POP R%d\n",q);pos++;}
		fprintf(target,"MOV R%d, -2\n",q);pos++;	
		fprintf(target,"ADD R%d, BP\n",q);pos++;	
		fprintf(target,"MOV [R%d], R%d\n",q,p);pos++;
		fprintf(target,"MOV BP, [BP]\n");pos++;
		fprintf(target,"POP R%d\n",p);pos++;
		fprintf(target,"RET\n");pos++;
		freereg();
		return -1;
	}
	
	else if(t->nodetype == 3){                                             //CONNECTOR
		if(t->left==NULL || t->right==NULL){
			printf("Connector children NULL ERROR\n");
			exit(0);
		}
		p=codegen(t->left,target);
		q=codegen(t->right,target);
		if(p!=-1 || q!=-1){
			printf("connector error\n");
			exit(1);
		}
		return -1;
	}
	
	else if(t->nodetype ==7 && ch==1){                                //BREAK/CONTINUE
		if(*(t->varname)=='b')
			fprintf(target, "JMP L%d\n",temp2[whilenum]);
		else if(*(t->varname)=='c')
			fprintf(target, "JMP L%d\n",temp1[whilenum]);
		pos++;
		return -1;
	}
	
	else if(t->nodetype == 0){                                        //LEAFNODES
		if(t->varname == NULL){
			if(t->text ==NULL){
				p=getreg();
				fprintf(target,"MOV R%d, %d\n",p,t->val);
				pos++;
				return p;
			}
			else{
				p=getreg();
				fprintf(target,"MOV R%d, %s\n",p,t->text);
				pos++;
				return p;
			}
		}
		else{
			//addr=*(t->varname)-'a' + 4096;
			int ff=0;
			if(t->Lentry!=NULL){
				//printf("%s_%d\n",t->varname,t->Lentry->binding);
				addr=t->Lentry->binding;
				ff=1;
			}
			else
				addr=t->Gentry->binding;
			if(t->val!=-1){
				addr+=t->val;
			}
			if(t->type==30){
				printf("WRONG\n");
				exit(1);
				/*struct Gsymbol *p1;
				p1=gLookup(t->arg);
				int p2=getreg();
				p=getreg();
				q=getreg();
				fprintf(target,"MOV R%d, [%d]\n",q,p1->binding);
				fprintf(target,"MOV R%d, %d\n",p,addr);
				fprintf(target,"ADD R%d, R%d\n",p,q);
				fprintf(target,"MOV R%d, [R%d]\n",p2,p);
				pos+=4;
				freereg();
				freereg();
				return p2;*/
			}
			else{
				p=getreg();
				if(ff==1){
					q=getreg();
					fprintf(target,"MOV R%d, %d\n",q,addr); pos++;
					fprintf(target,"ADD R%d, BP\n",q); pos++;
					fprintf(target,"MOV R%d, [R%d]\n",p,q); pos++;
					freereg();
				}
				else{
					fprintf(target,"MOV R%d, [%d]\n",p,addr); pos++;
				}
				return p;
			}
		}
	}	
		
	else if(t->nodetype == 1){                                         //READ
		p=getreg();
		q=getreg();
		//addr=*(t->left->varname)-'a' + 4096;
		int ff=0;
		if(t->left->Lentry!=NULL){
			addr=t->left->Lentry->binding;
			ff=1;
		}
		else
			addr=t->left->Gentry->binding;
		if(t->left->val!=-1){
			addr+=t->left->val;
		}
		if(t->left->nodetype==9){
			freereg();
			q=codegen(t->left->left,target);
			fprintf(target,"MOV R%d, %d\n",p,addr);
			fprintf(target,"ADD R%d, R%d\n",p,q);
			pos+=2;
		}
		else{
    		fprintf(target, "MOV R%d, %d\n", p, addr);pos++;
    		if(ff==1){
				fprintf(target,"ADD R%d, BP\n",p);pos++;
			}
    	}
    	//fprintf(target, "MOV SP, %d\n", idaddr);
    	fprintf(target, "MOV R%d, %d\n", q, 7);
    	fprintf(target, "PUSH R%d\n", q);
    	fprintf(target, "MOV R%d, %d\n", q, -1);
    	fprintf(target, "PUSH R%d\n", q);
    	fprintf(target, "PUSH R%d\n", p);
    	fprintf(target, "PUSH R%d\n", p);
    	fprintf(target, "PUSH R%d\n", p);
    	fprintf(target, "INT 6\n");
		fprintf(target, "POP R%d\n", q);
    	fprintf(target, "POP R%d\n", q);
    	fprintf(target, "POP R%d\n", q);
    	fprintf(target, "POP R%d\n", q);
    	fprintf(target, "POP R%d\n", q);
		pos+=13;
		freereg();
		freereg();
		return -1;
	}
	
	else if(t->nodetype == 2){                                         //WRITE
		if(t->left->nodetype != 0)
			p=codegen(t->left,target);
		else{
			p=getreg();
			if(t->left->varname == NULL){
				if(t->left->text ==NULL){
					fprintf(target,"MOV R%d, %d\n",p,t->left->val);
					pos++;
				}
				else{
					fprintf(target,"MOV R%d, %s\n",p,t->left->text);
					pos++;
				}
			}
			else{
				//addr=*(t->left->varname)-'a' + 4096;
				int ff=0;
				if(t->left->Lentry!=NULL){
					addr=t->left->Lentry->binding;
					ff=1;
				}
				else
					addr=t->left->Gentry->binding;
				if(t->left->val!=-1){
					addr+=t->left->val;
				}
				if(t->left->nodetype==9){
					int p2=getreg();
					q=codegen(t->left->left,target);
					fprintf(target,"MOV R%d, %d\n",p2,addr);
					fprintf(target,"ADD R%d, R%d\n",p2,q);
					fprintf(target,"MOV R%d, [R%d]\n",p,p2);
					freereg();
					freereg();
					pos+=3;
				}
				else{
					if(ff==1){
						q=getreg();
						fprintf(target,"MOV R%d, %d\n",q,addr); pos++;
						fprintf(target,"ADD R%d, BP\n",q); pos++;
						fprintf(target,"MOV R%d, [R%d]\n",p,q); pos++;
						freereg();
					}
					else{
						fprintf(target,"MOV R%d, [%d]\n",p,addr); pos++;
					}
				}
			}
		}
		q=getreg();
		//fprintf(target, "MOV SP, %d\n", idaddr);
    	fprintf(target, "MOV R%d, %d\n", q, 5);
    	fprintf(target, "PUSH R%d\n", q);
    	fprintf(target, "MOV R%d, %d\n", q, -2);
    	fprintf(target, "PUSH R%d\n", q);
    	fprintf(target, "PUSH R%d\n", p);
    	fprintf(target, "PUSH R%d\n", p);
    	fprintf(target, "PUSH R%d\n", p);
    	fprintf(target, "INT 7\n");
		fprintf(target, "POP R%d\n", q);
    	fprintf(target, "POP R%d\n", q);
    	fprintf(target, "POP R%d\n", q);
    	fprintf(target, "POP R%d\n", q);
    	fprintf(target, "POP R%d\n", q);
		pos+=13;
		freereg();
		freereg();
		return -1;	
	}
	
	else if(t->nodetype == 4){                                         //OPERATORS
		if(t->type == booltype){
			p=codegen(t->left,target);
			q=codegen(t->right,target);
			if(!strcmp(t->varname,">="))
            	fprintf(target, "GE R%d, R%d\n",p,q);
            else if(!strcmp(t->varname,">"))
            	fprintf(target, "GT R%d, R%d\n",p,q);
            else if(!strcmp(t->varname,"<="))
            	fprintf(target, "LE R%d, R%d\n",p,q);
            else if(!strcmp(t->varname,"<"))
            	fprintf(target, "LT R%d, R%d\n",p,q);
            else if(!strcmp(t->varname,"!="))
            	fprintf(target, "NE R%d, R%d\n",p,q);
            else if(!strcmp(t->varname,"=="))
            	fprintf(target, "EQ R%d, R%d\n",p,q);
            pos++;
            freereg();
            return p;
        }
		if(!strcmp(t->varname,"=")){
			int temp,type;
			/*if(t->left->Lentry!=NULL){
				type=t->left->Lentry->type;
			}
			else{
				type=t->left->Gentry->type;
			}
			//if(t->right->nodetype==0){
				if(t->right->varname==NULL){*/
					//printf("%d: %d  %d\n",t->right->nodetype,t->left->type,t->right->type);
					if(t->right->type!=t->left->type){
						printf("Integer/String Type mismatch\n");
						exit(1);
					}
				/*}	
				else{
					//printf("%d: %d  %d\n",t->right->nodetype,type,t->right->Gentry->type);
					int type2;
					if(t->right->Lentry!=NULL)
						type2=t->right->Lentry->type;
					else
						type2=t->right->Gentry->type;
					if(type2!=type){
						printf("Integer/String Type mismatch\n");
						exit(1);
					}
				}
			}
			else{
				if(t->right->type==3){
					printf("Integer/String Type mismatch\n");
					exit(1);
				}
			}*/
			p=codegen(t->right,target);
			//addr=*(t->left->varname)-'a' + 4096;
			int ff=0;
			if(t->left->Lentry!=NULL){
				addr=t->left->Lentry->binding;
				ff=1;
			}
			else{
				addr=t->left->Gentry->binding;
			}
			if(t->left->val!=-1){
				addr+=t->left->val;
			}
			if(t->left->nodetype==9){
				int p2=getreg();
				q=codegen(t->left->left,target);
				fprintf(target,"MOV R%d, %d\n",p2,addr);
				fprintf(target,"ADD R%d, R%d\n",p2,q);
				fprintf(target,"MOV [R%d], R%d\n",p2,p);
				freereg();
				freereg();
				pos+=3;
			}
			else{
				if(ff==1){
					q=getreg();
					fprintf(target,"MOV R%d, %d\n",q,addr); pos++;
					fprintf(target,"ADD R%d, BP\n",q); pos++;
					fprintf(target,"MOV [R%d], R%d\n",q,p); pos++;
					freereg();
				}
				else{
					fprintf(target,"MOV [%d], R%d\n",addr,p); pos++;
				}
			}
			freereg();
			return -1;
		}
		else{
			p=codegen(t->left,target);
			q=codegen(t->right,target);
			if(!strcmp(t->varname,"+")){
				fprintf(target, "ADD R%d, R%d\n", p, q);
				pos++;
			}
			else if(!strcmp(t->varname,"-")){
				fprintf(target, "SUB R%d, R%d\n", p, q);
				pos++;
			}
			else if(!strcmp(t->varname,"*")){
				fprintf(target, "MUL R%d, R%d\n", p, q);
				pos++;
			}
			else if(!strcmp(t->varname,"/")){
				fprintf(target, "DIV R%d, R%d\n", p, q);
				pos++;
			}
			else if(!strcmp(t->varname,"%")){
				int tm=getreg();
				fprintf(target, "MOV R%d, R%d\n", tm, p);
				fprintf(target, "DIV R%d, R%d\n", p, q);
				fprintf(target, "MUL R%d, R%d\n", q, p);
				fprintf(target, "MOV R%d, R%d\n", p, tm);
				fprintf(target, "SUB R%d, R%d\n", p, q);
				freereg();
				pos+=5;
			}
			else if(!strcmp(t->varname,"@")){
				fprintf(target, "DCR R%d\n",q);
				pos++;
				fprintf(target, "L%d:\n", r);
				a[r]=2*pos+2056;
				fprintf(target, "MUL R%d, R%d\n", p, p);
				fprintf(target, "DCR R%d\n",q);
				fprintf(target, "JNZ R%d, L%d\n",q,r);
				r++;
				pos+=3;
			} 
			freereg();
			return p;
		}
		
	}
	
	else if(t->nodetype == 5){                                        //WHILE
		int t1,t2;
		whilenum++;
		fprintf(target, "L%d:\n",r);
		temp1[whilenum]=r;
		t1=r;
		a[t1]=2*pos+2056;
		r++;
		p=codegen(t->left,target);
		fprintf(target, "JZ R%d, L%d\n",p,r); pos++;
		temp2[whilenum]=r;
		t2=r;
		r++;
		freereg();
		ch=1;
		p=codegen(t->right,target);
		if(whilenum==1)
			ch=0;
		fprintf(target, "JMP L%d\n",t1); pos++;
		fprintf(target, "L%d:\n",t2);
		a[t2]=2*pos+2056;
		whilenum--;
	}
	
	else if(t->nodetype == 6){                                        //IF,IFELSE
		p=codegen(t->left,target);
		int temp1,temp2;
		if(!strcmp(t->varname, "ifelse")){
			fprintf(target, "JZ R%d, L%d\n",p,r);
			temp1=r;
			r++;
			pos++;
			p=codegen(t->mid,target);
			fprintf(target, "JMP L%d\n",r);
			temp2=r;
			r++;
			pos++;
			fprintf(target, "L%d:\n",temp1);
			a[temp1]=2*pos+2056;
			p=codegen(t->right,target);
			fprintf(target, "L%d:\n",temp2);
			a[temp2]=2*pos+2056;
		}
		else if(!strcmp(t->varname, "if")){
			fprintf(target, "JZ R%d, L%d\n",p,r);
			temp1=r;
			r++;
			pos++;
			p=codegen(t->mid,target);
			fprintf(target, "L%d:\n",temp1);
			a[temp1]=2*pos+2056;
			r++;
		}
		freereg();
	}	
	
	else if(t->nodetype == 9){                                         //ID[EXPR]
		addr=t->Gentry->binding;
		q=codegen(t->left,target);
		p=getreg();
		fprintf(target,"MOV R%d, %d\n",p,addr);
		fprintf(target,"ADD R%d, R%d\n",p,q);
		fprintf(target,"MOV R%d, [R%d]\n",q,p);
		pos+=3;
		freereg();
		return q;
	}
	return -1;
}
	
void freereg(){
	k--;
}

int getreg(){
	k++;
	return k;
}	


			
		















