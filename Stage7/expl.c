int k=-1,r=0,ch=0,idaddr=4096,temp1[100],temp2[100];
int whilenum=0,flabel=1;
struct Gsymbol *groot=NULL;
struct Lsymbol *lroot=NULL;
struct Paramstruct *proot=NULL;
struct Typetable *troot=NULL;
struct Fieldlist *froot=NULL;
struct Classtable *croot=NULL;
struct Fieldlist *cfroot=NULL;
struct Memberfunclist *mroot=NULL;
struct Typetable *tint;
struct Typetable *tbool;
struct Classtable *Cptr;
struct Classtable *currclass=NULL;
int classnum=0;
char *fname;
int pos=1;    
int beginflag=1;   
int a[1000],func[1000],mainl;      //for label translation
int lvar=0;
int fieldpos=1,typenum=5;
int cnum=0,fnum=1,mnum=1;
int selflab=0,rr=0;
     
/*------------------------------GLOBAL START-----------------------------*/
struct Gsymbol *newgid(char *nam, struct Typetable *type, int size){
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
    	printf("%s(%s)->",p->name,p->type->name);
    	p=p->next;  
    }
    printf("%s(%s)\n",p->name,p->type->name);
}

/*------------------------------GLOBAL END-----------------------------*/

/*------------------------------LOCAL START-----------------------------*/

struct Lsymbol *newlid(char *nam, struct Typetable *type){
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

int setlocalbinding(struct Paramstruct *param,struct Lsymbol *lsym){
	int i=-3,k=-3;
	if(lsym==NULL){
		return k;
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
	while(p->next!=NULL){
		l->binding=i;
		p=p->next;
		l=l->next;
		--i;
	}
	l->binding=i;
	i--;
	k=i;
	if(l->next==NULL){
		printf("No Local variables\n");
		return k;
	}
	l=l->next;
a9:	i=1;
	while(l->next!=NULL){
		l->binding=i;
		l=l->next;
		++i;
	}
	l->binding=i;
	return k;
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
    	printf("%s(%s)->",p->name,p->type->name);
    	p=p->next;  
    }
    printf("%s(%s)\n",p->name,p->type->name);
}

/*------------------------------LOCAL END-----------------------------*/

/*------------------------------PARAM START------------------------------*/

struct Paramstruct *newparam(char* name, struct Typetable *type){
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
	if(r==NULL){
		f=0;
		return f;
	}
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
	if(f1->next!=NULL || r->next!=NULL)
		f=0;
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

/*-----------------------------UTYPE START------------------------------*/

void TypeTableCreate(){
	struct Typetable *t1,*t2,*t3,*t4;
	t1= (struct Typetable*)malloc(sizeof(struct Typetable));
	t2= (struct Typetable*)malloc(sizeof(struct Typetable));
	t3= (struct Typetable*)malloc(sizeof(struct Typetable));
	t4= (struct Typetable*)malloc(sizeof(struct Typetable));
	t1->name= malloc(sizeof(char));	
	t2->name= malloc(sizeof(char));
	t3->name= malloc(sizeof(char));
	t4->name= malloc(sizeof(char));
	strcpy(t1->name,"bool");
	strcpy(t2->name,"int");
	strcpy(t3->name,"str");
	strcpy(t4->name,"void");
	t2->size=1;
	t3->size=1;
	t1->typen=1;
	t2->typen=2;
	t3->typen=3;
	t4->typen=4;
	troot=t1;
	t1->next=t2;
	t2->next=t3;
	t3->next=t4;
	t4->next=NULL;
}

struct Typetable *newtype(char *name){
	struct Typetable *t,*temp;
	temp= (struct Typetable*)malloc(sizeof(struct Typetable));
	temp->name= malloc(sizeof(char));	
	strcpy(temp->name,name);
	temp->typen=typenum;
	typenum++;
	temp->next= NULL;
	t=troot;
	while(t->next!=NULL)
		t=t->next;
	t->next=temp;
	return temp;
}

struct Typetable *tLookup(char *name){
	if(troot==NULL){
		//printf("No Type in tLookup\n");
		return NULL;
	}
	//printf("%s\n",name);
	struct Typetable *t=troot;
	while(t->next!=NULL){
		if(!strcmp(t->name,name))
			return t;
		t=t->next;
	}
	if(!strcmp(t->name,name))
		return t;
	//printf("Type not found in tLookup\n");
	return NULL;
}

void tdisplay(){
	printf("Types: ");
	struct Typetable *t=troot;
	while(t->next!=NULL){
		printf("%s->",t->name);
		t=t->next;
	}
	printf("%s\n",t->name);
}

struct Fieldlist *newfield(char *name,struct Typetable *t){
	struct Fieldlist * f;
	f=(struct Fieldlist *)malloc(sizeof(struct Fieldlist));
	f->name=malloc(sizeof(char));
	strcpy(f->name,name);
	f->fieldIndex=fieldpos;
	fieldpos++;
	f->type=t;
	if(froot==NULL){
		froot=f;
		return froot;
	}
	struct Fieldlist *ft;
	ft=froot;
	while(ft->next!=NULL)
		ft=ft->next;
	ft->next=f;
	return froot;	
}

struct Fieldlist *fLookup(struct Typetable *type, char *name){
	if(type->fields==NULL){
		printf("No field in fLookup\n");
		return NULL;
	}
	struct Fieldlist *f=type->fields;
	while(f->next!=NULL){
		if(!strcmp(f->name,name))
			return f;
		f=f->next;	
	}
	if(!strcmp(f->name,name))
		return f;
	return NULL;
}

void fdisplay(struct Fieldlist* f){
	printf("Field elements: ");
	if(f==NULL){
		printf("Empty\n");
		return;
	}
	struct Fieldlist *fs=f;
	while(fs->next!=NULL){
		printf("%s(%s)->",fs->name,fs->type->name);
		fs=fs->next;
	}
	printf("%s(%s)\n",fs->name,fs->type->name);
}

int GetSize (struct Fieldlist* f){
	if(f==NULL){
		printf("Field list is empty\n");
		exit(1);
	}
	int size=0;
	struct Fieldlist *ft=f;
	while(ft->next!=NULL){
		size+=ft->type->size;
		ft=ft->next;
	}
	size+=ft->type->size;
	return size;
}

/*------------------------------UTYPE END-------------------------------*/

/*------------------------------CLASS START-----------------------------*/

struct Classtable* newclass(char *name,char *parentname){
	struct Classtable *c;
	c=(struct Classtable*)malloc(sizeof(struct Classtable));
	c->name = malloc(sizeof(char));
	strcpy(c->name,name);
	c->method=NULL;
	c->field=NULL;
	struct Classtable *p=NULL;
	if(parentname!=NULL){
		if(cLookup(parentname)==NULL){
			printf("Class doesn't exist to extend\n");
			exit(1);
		}
		p=cLookup(parentname);
	}
	if(croot==NULL){
		croot=c;
		c->parentptr=p;
		c->next=NULL;
		return c;
	}
	struct Classtable *t;
	t=croot;
	while(t->next!=NULL)
		t=t->next;
	t->next=c;
	c->parentptr=p;
	c->next=NULL;
	return c;
}

struct Classtable* Appendclass(char *name,struct Fieldlist *flist,struct Memberfunclist *mlist,int cnum,int fnum,int mnum){
	struct Classtable *c;
	if(cLookup(name)==NULL){
		printf("Error in looking up class\n");
		exit(1);
	}
	c=cLookup(name);
	c->field=flist;
	c->method=mlist;
	c->classindex=cnum;
	c->fieldnum=fnum;
	c->methodnum=mnum;
	return c;
}

struct Classtable* cLookup(char *name){
	struct Classtable *p;
	if(croot==NULL || classnum==0){
		//printf("No class in lookup\n");
		return NULL;
	}
	p=croot;
	int i=0;
	while(1){
    	if(!strcmp(p->name,name))
    		return p;
    	p=p->next; 
    	i++;
    	if(i==classnum)
    		break; 
    }	
    return NULL;
}

void newcfield(struct Classtable *cptr, struct Typetable *type, char *name){
	struct Fieldlist * f;
	f=(struct Fieldlist *)malloc(sizeof(struct Fieldlist));
	f->name=malloc(sizeof(char));
	strcpy(f->name,name);
	f->fieldIndex=fnum;
	fnum++;
	f->type=type;
	f->Ctype=cptr;
	if(cfroot==NULL){
		cfroot=f;
		f->next=NULL;
		return;
	}
	struct Fieldlist *ft;
	ft=cfroot;
	while(ft->next!=NULL)
		ft=ft->next;
	ft->next=f;
	f->next=NULL;
	return;
}

void newcmethod(struct Classtable *cptr, char *name, struct Typetable *type, struct Paramstruct *paramlist){
	struct Memberfunclist *f;
	f=(struct Memberfunclist *)malloc(sizeof(struct Memberfunclist));
	f->name=malloc(sizeof(char));
	strcpy(f->name,name);
	f->fpos=mnum;
	mnum++;
	f->type=type;
	f->Ctype=cptr;
	f->paramlist=paramlist;
	f->flabel=flabel;
	flabel++;
	if(mroot==NULL){
		mroot=f;
		mroot->next=NULL;
		return;
	}
	struct Memberfunclist *ft;
	ft=mroot;
	while(ft->next!=NULL)
		ft=ft->next;
	ft->next=f;
	f->next=NULL;
	return;
}

struct Paramstruct *getmethodparam(struct Classtable* c,char* name){
	struct Paramstruct *p;
	if(cmlookup(c,name)==NULL){
		printf("Method %s not defined in the class %s\n",name,c->name);
		exit(1);
	}
	p=cmlookup(c,name)->paramlist;
	return p;
}

struct Memberfunclist* cmlookup (struct Classtable* ctype,char* name){
	struct Memberfunclist *m;
	if(ctype==NULL){
		m=mroot;
		goto a1;
	}
	if(ctype->method==NULL && mroot==NULL){
		printf("Class has no member functions\n");
		return NULL;
	}
	if(ctype->method!=NULL)
		m=ctype->method;
	else 
		m=mroot;
a1: if(m==NULL)
		return NULL;	
	while(m->next!=NULL){
		if(!strcmp(m->name,name))
    		return m;
    	m=m->next;  
    }	
    if(!strcmp(m->name,name))
    	return m;
    else
    	return NULL;
}

struct Fieldlist* cflookup(struct Classtable* ctype,char* name){
	struct Fieldlist *m;
	if(ctype==NULL){
		m=cfroot;
		goto a1;
	}
	if(ctype->field==NULL && cfroot==NULL){
		printf("Class has no field variables\n");
		return NULL;
	}
	if(ctype->field!=NULL){
		m=ctype->field;
	}
	else
		m=cfroot;
a1:	if(m==NULL)
		return NULL;
	while(m->next!=NULL){
		if(!strcmp(m->name,name))
    		return m;
    	m=m->next;  
    }	
    if(!strcmp(m->name,name))
    	return m;
    else
    	return NULL;
}

void cfdisplay(struct Fieldlist *f){
	printf("Class Field elements: ");
	if(f==NULL){
		printf("Empty\n");
		return;
	}
	struct Fieldlist *fs=f;
	while(fs->next!=NULL){
		printf("%s(%s)->",fs->name,fs->type->name);
		fs=fs->next;
	}
	printf("%s(%s)\n",fs->name,fs->type->name);
}

void mdisplay(struct Memberfunclist *m){
	printf("Class method elements: ");
	if(m==NULL){
		printf("Empty\n");
		return;
	}
	struct Memberfunclist *fs=m;
	while(fs->next!=NULL){
		printf("%s(%s)->",fs->name,fs->type->name);
		fs=fs->next;
	}
	printf("%s(%s)\n",fs->name,fs->type->name);
}


/*------------------------------CLASS END-------------------------------*/

/*------------------------------NODE START------------------------------*/


struct tnode* maketext(int n,char *text,struct Typetable *type){
	struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->text = malloc(sizeof(char));
    temp->varname = malloc(sizeof(char));
    if(text==NULL)
    	temp->text = NULL;                           
    else
    	strcpy(temp->text,text);
    if(type==NULL){
    	printf("texttype NULL\n");
    	exit(1);
    }				  
    temp->type = type;
    temp->val = n;
	temp->nodetype = 0;
	temp->Gentry=NULL;
	temp->varname=NULL;
	temp->argp=NULL;
    temp->left = NULL;
    temp->mid = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeleaf(char *c,int nt)
{
	struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    temp->type = NULL;
    temp->val = 0;
	strcpy(temp->varname, c);
	temp->Gentry=NULL;
	temp->nodetype = nt;
    temp->left = NULL;
    temp->mid = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeleafnum(int n,char *text,struct Typetable *type)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->text = malloc(sizeof(char));
    temp->varname = malloc(sizeof(char));
    if(text==NULL){
    	temp->text = NULL;    
    	temp->varname = NULL;
    }                       
    else{	
    	strcpy(temp->text,text);
    	strcpy(temp->varname,text);	
    }
    if(type==NULL){
    	printf("Leafnumtype NULL\n");
    	exit(1);
    }				  
    temp->type = type;
    temp->val = n;
	temp->nodetype = 0;
	temp->Gentry=NULL;
	temp->argp=NULL;
    temp->left = NULL;
    temp->mid = NULL;
    temp->right = NULL;
    return temp;
}
struct tnode* makearraynode(char* var,struct Typetable *type,struct tnode *l){
	struct tnode *temp;                            
    temp = (struct tnode*)malloc(sizeof(struct tnode));   
	temp->varname = malloc(sizeof(char));
	if(checkgvar(var)){
		printf("Variable not declared\n");
		exit(1);
	}
	if(!strcmp(l->type->name,"bool")){
		printf("Type mismatch boolean-integer/string-integer\n");
		exit(1);
	}
	temp->Gentry=gLookup(var);
    if(temp->Gentry==NULL){
		printf("Variable Lookup error\n");
		exit(1);
	} 
	strcpy(temp->varname,var);
	if(type==NULL){
    	printf("arraytype NULL\n");
    	exit(1);
    }
	temp->type=type;
	temp->nodetype=9;
	temp->left=l;
	temp->mid = NULL;
    temp->right = NULL;
}

struct tnode* makeleafvar(char* var,int narg, struct Typetable *type)
{
    struct tnode *temp;                                        //Typearg:
    temp = (struct tnode*)malloc(sizeof(struct tnode));        //10: variable
	temp->varname = malloc(sizeof(char));                      //20: array with integer arg
	temp->arg = malloc(sizeof(char));						   //30: array with variable arg
    if(type==NULL){
    	printf("leafvartype NULL\n");
    	exit(1);
    }
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

struct tnode* fieldconnect(struct tnode *first,struct tnode *second){
	struct tnode* p;
	struct Fieldlist *f;
	p=first;
	if(strcmp("self",p->varname))
		p->nodetype=13;
	while(p->left!=NULL)
		p=p->left;
	//printf("%s: %s\n",first->varname,second->varname);
	f=fLookup(p->type,second->varname);
	if(f==NULL){
		printf("%s is not a field of %s\n",second->varname,p->varname);
		exit(1);
	}
	second->type=f->type;
	p->left=second;
	second->left=NULL;
	first->type=second->type;
	return first;
}
struct tnode* makemethodnode(struct tnode *ct,char *fname,int nt,struct Typetable *t,struct tnode *arg){
	if(strcmp(ct->varname,"self")){
		if(cLookup(t->name)==NULL){
			printf("Class not found in method\n");
			exit(1);
		}
	}	
	struct Classtable *c;
	struct tnode *u;
	u=ct;
	ct->nodetype=10;
	if(ct->left!=NULL){
		u=ct;
		while(u->left!=NULL)
			u=u->left;
		//fname=u->varname;
		c=cLookup(u->type->name);
	}
	//else if(!strcmp("self",ct->varname))
	//	c=currclass;
	else
		c=cLookup(t->name);
	if(cmlookup(c,fname)==NULL){
		printf("Method %s not part of class %s\n",fname,c->name);
		exit(1);
	}
	struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->varname = malloc(sizeof(char));
	strcpy(temp->varname,fname);
	ct->type = cmlookup(c,fname)->type;
	temp->type = cmlookup(c,fname)->type;
	temp->nodetype=nt;
	temp->arglist=arg;
	temp->cptr=c;
	temp->left=NULL;
	u->left=temp;
	return ct;
}

struct tnode* makenode(char *c,int nt,struct Typetable *t,struct tnode *arg,struct tnode *l,struct tnode *m,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->varname = malloc(sizeof(char));
	if(nt==4){
		if(!strcmp(l->type->name,"bool") || !strcmp(r->type->name,"bool")){
			printf("Type mismatch boolean\n");
			exit(1);
		}
	}
	if(nt==4){
		if(l->type!=r->type && r->type->typen!=4){
			printf("Type mismatch\n");
			exit(1);	
		}
	}	
	if(nt==5 || nt==6){
		if(!strcmp(l->type->name,"int")){
			printf("Type mismatch boolean\n");
			exit(1);
		}
	}
    strcpy(temp->varname,c);
    temp->Gentry=NULL;
    if(currclass!=NULL && !strcmp("self",c)){
    	if(cflookup(currclass,l->varname)!=NULL){
			temp->type=cflookup(currclass,l->varname)->type;
		}
		else if(cmlookup(currclass,l->varname)!=NULL){
			temp->type=cmlookup(currclass,l->varname)->type;
		}
		else{
			printf("%s is not a field/method of class %s\n",l->varname,currclass->name);
			exit(1);
		}
    }
    else if(t==NULL){
    	temp->type = NULL;
    }
    else
		temp->type = t;
	//printf("%s-%s\n",l->varname,r->varname);
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
	if(targ->varname!=NULL)
		if(!strcmp(targ->varname,"self"))
			return;
	if(targ->argp==NULL){
		int i;
		//printf("%d\n",targ->nodetype);
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
		if(t->left==NULL ){
			printf("No body\n");
			q=codegen(t->right,target);
		}
		else if(t->right==NULL){
			printf("No return\n");
			exit(1);
		}
		else{
			p=codegen(t->left,target);
			q=codegen(t->right,target);
		}
		if(p!=-1 || q!=-1){
			printf("body error\n");
			exit(1);
		}
		return -1;
	}
	
	else if(t->nodetype == 10){											   //FCALL
		int regs=k;
		int self=0,addr=-1,ff=0;
		for(int i=0;i<=regs;i++){
			fprintf(target, "PUSH R%d\n",i);
			pos++;
		}
		struct tnode *t1=t;
		struct Classtable *c1,*tt;
		struct Paramstruct *par;
		if(t1->left!=NULL){
			self=1;
			struct tnode *t2,*t3;
			t2=(struct tnode *)malloc(sizeof(struct tnode));
			t2->varname=(char*)malloc(sizeof(char));
			t3=t1;
			t1=t1->left;
			if(currclass==NULL){
				tt=cLookup(gLookup(t3->varname)->type->name);
				if(t1->left==NULL)
					par=cmlookup(tt,t1->varname)->paramlist;
			}
			else{
				if(t1->left==NULL)
					par=cmlookup(currclass,t1->varname)->paramlist;
			}
			if(!strcmp(t3->varname,"self")){
				p=getreg();
				q=getreg();
				if(t1->left!=NULL){
					par=cmlookup(cLookup(cflookup(currclass,t1->varname)->type->name),t1->left->varname)->paramlist;
					fprintf(target,"MOV R%d, %d\n",q,selflab); pos++;
					fprintf(target,"ADD R%d, BP\n",q); pos++;
					fprintf(target,"MOV R%d, [R%d]\n",p,q); pos++;
					int fla=cflookup(currclass,t1->varname)->fieldIndex;
					fprintf(target,"ADD R%d, %d\n",p,fla); pos++;
					fprintf(target,"PUSH R%d\n",p); pos++;
					t1=t1->left;
				}
				else{
					fprintf(target,"MOV R%d, %d\n",q,selflab); pos++;
					fprintf(target,"ADD R%d, BP\n",q); pos++;
					fprintf(target,"MOV R%d, [R%d]\n",p,q); pos++;
					fprintf(target,"PUSH R%d\n",p); pos++;
				}
				freereg();
				freereg();
				c1=currclass;
				//strcpy(t2->varname,"self");
				//t3->argp=t1->arglist;
				//t1->arglist=t3;
			}
			else{
				c1=cLookup(t3->type->name);
				if(t3->Lentry!=NULL){
					//printf("%s_%d\n",t3->varname,t3->Lentry->binding);
					addr=t3->Lentry->binding;
					ff=1;
				}
				else
					addr=t3->Gentry->binding;
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
				fprintf(target,"PUSH R%d\n",p); pos++;
				freereg();
			}
		}
		printf("Function call %s:---", t1->varname);
		int argnum=argdisplay(t1->arglist);
		if(self==1){
			if(!checkarg(t1->arglist,par)){
				printf("Arguments don't match function definition\n");
				exit(1);
			}
		}
		else{
			par=getparam(t1->varname);
			if(!checkarg(t1->arglist,par)){
				printf("Arguments don't match function definition\n");
				exit(1);
			}
		}
		if(t1->arglist!=NULL)
			pusharg(t1->arglist,target);
		int y=getreg(); 
		fprintf(target, "PUSH R%d\n",y);pos++; //return value
		freereg();
		int e;
		if(self==1)
			e=cmlookup(t1->cptr,t1->varname)->flabel;
		else
			e=getflabel(t1->varname);
		fprintf(target, "CALL F%d\n",e);pos++;
		p=getreg();
		fprintf(target, "POP R%d\n",p);pos++;
		q=getreg();
		if(t->left!=NULL){
			fprintf(target, "POP R%d\n",q); pos++;
		}
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
			if(t->left== NULL || strcmp(t->left->type->name,"int")){
				printf("Return type mismatch\n");
				exit(1);
			}
			q=getreg();
			for(int i=0;i<lvar;i++)
				{fprintf(target,"POP R%d\n",q);pos++;}
			freereg();
			return -1;
		}	
		struct Typetable *type;
		if(currclass!=NULL)
			type=cmlookup(currclass,fname)->type;
		else
			type=gLookup(fname)->type;
		if(t->left== NULL || strcmp(t->left->type->name,type->name)){
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
		if(!strcmp(t->varname,"break"))
			fprintf(target, "JMP L%d\n",temp2[whilenum]);
		else if(!strcmp(t->varname,"continue"))
			fprintf(target, "JMP L%d\n",temp1[whilenum]);
		else{
			printf("Invalid break/continue statement\n");
			exit(1);
		}
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
			else if(!strcmp(t->text,"alloc()")){
				int k2=k>2?2:k;
				p=getreg();
				q=getreg();
				for(int i=0;i<=k2;i++)
					{fprintf(target,"PUSH R%d\n",i); pos++;}
				fprintf(target,"MOV R%d, \"Alloc\"\n",p); pos++;
				fprintf(target,"PUSH R%d\n",p); pos++;
				fprintf(target,"MOV R%d, 8\n",p); pos++;
				fprintf(target,"PUSH R%d\n",p); pos++;
				fprintf(target,"PUSH R%d\n",p); pos++;
				fprintf(target,"PUSH R%d\n",p); pos++;
				fprintf(target,"PUSH R%d\n",p); pos++;
				fprintf(target,"CALL 0\n"); pos++;
				fprintf(target, "POP R%d\n", p); pos++;
    			fprintf(target, "POP R%d\n", q); pos++;
    			fprintf(target, "POP R%d\n", q); pos++;
    			fprintf(target, "POP R%d\n", q); pos++;
    			fprintf(target, "POP R%d\n", q); pos++;
    			for(int i=k2;i>=0;i--)
    				{fprintf(target, "POP R%d\n", i); pos++;}
    			freereg();
    //------------------------------------------------------------------------------------------
    			/*int p2=getreg();
    			int q2=getreg();
    			for(int i=1024;i<=1056;i+=8){
    				fprintf(target, "MOV R%d, [%d]\n", p2,i);pos++;	
    				fprintf(target, "MOV R%d, %d\n", q2, 5); pos++;
    				fprintf(target, "PUSH R%d\n", q2); pos++;
    				fprintf(target, "MOV R%d, %d\n", q2, -2); pos++;
    				fprintf(target, "PUSH R%d\n", q2); pos++;
    				fprintf(target, "PUSH R%d\n", p2); pos++;
    				fprintf(target, "PUSH R%d\n", p2); pos++;
    				fprintf(target, "PUSH R%d\n", p2); pos++;
    				fprintf(target, "INT 7\n"); pos++;
					fprintf(target, "POP R%d\n", q2); pos++;
    				fprintf(target, "POP R%d\n", q2); pos++;
    				fprintf(target, "POP R%d\n", q2); pos++;
    				fprintf(target, "POP R%d\n", q2); pos++;
    				fprintf(target, "POP R%d\n", q2); pos++;
    			}
    			fprintf(target, "MOV R%d, \"-----------------------------\"\n", p2);pos++;	
    			fprintf(target, "MOV R%d, %d\n", q2, 5); pos++;
    			fprintf(target, "PUSH R%d\n", q2); pos++;
    			fprintf(target, "MOV R%d, %d\n", q2, -2); pos++;
    			fprintf(target, "PUSH R%d\n", q2); pos++;
    			fprintf(target, "PUSH R%d\n", p2); pos++;
    			fprintf(target, "PUSH R%d\n", p2); pos++;
    			fprintf(target, "PUSH R%d\n", p2); pos++;
    			fprintf(target, "INT 7\n"); pos++;
				fprintf(target, "POP R%d\n", q2); pos++;
    			fprintf(target, "POP R%d\n", q2); pos++;
    			fprintf(target, "POP R%d\n", q2); pos++;
    			fprintf(target, "POP R%d\n", q2); pos++;
    			fprintf(target, "POP R%d\n", q2); pos++;
    			fprintf(target, "BRKP\n"); pos++;
    			freereg();
    			freereg();*/
    //-------------------------------------------------------------------------------------------
				return p;
			}
			else if(!strcmp(t->text,"null")){
				p=getreg();
				fprintf(target,"MOV R%d, \"null\"\n",p);
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
		if(t->left->nodetype != 0 || t->left->nodetype==13)
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
		if(!strcmp(t->type->name,"bool")){
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
            else{
            	printf("Invalid operator\n");
            	exit(1);
            }
            pos++;
            freereg();
            return p;
        }
		if(!strcmp(t->varname,"=")){
			int temp;
			struct Typetable *type;
			//printf("%s  %s\n",t->left->varname,t->right->varname);
			/*if(t->left->Lentry!=NULL){
				type=t->left->Lentry->type;
			}
			else{
				type=t->left->Gentry->type;
			}
			//if(t->right->nodetype==0){
				if(t->right->varname==NULL){*/
					//printf("%d: %d  %d\n",t->right->nodetype,t->left->type,t->right->type);
					if(t->right->type!=t->left->type && t->right->type->typen!=4){
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
			if(t->left->nodetype!=15){
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
			else if(t->left->nodetype==13 || t->left->nodetype==15){
				int p2=getreg();
				if(t->left->nodetype==15){
					q=getreg();
					fprintf(target,"MOV R%d, %d\n",q,selflab); pos++;
					fprintf(target,"ADD R%d, BP\n",q); pos++;
					fprintf(target,"MOV R%d, R%d\n",p2,q); pos++;
					freereg();
				}
				else{
					if(ff==1){
						q=getreg();
						fprintf(target,"MOV R%d, %d\n",q,addr); pos++;
						fprintf(target,"ADD R%d, BP\n",q); pos++;
						fprintf(target,"MOV R%d, R%d\n",p2,q); pos++;
						freereg();
					}
					else{
						fprintf(target,"MOV R%d, %d\n",p2,addr); pos++;
					}
				}
				int f1;
				struct tnode *t1=t->left;
				if(t1->left!=NULL){
					struct Typetable *typ;
					if(t->left->nodetype==15){
						//printf("%s\n",tLookup(currclass->name)->name);
						f1=fLookup(tLookup(currclass->name),t1->left->varname)->fieldIndex;
					}
					else{
						if(t1->Lentry!=NULL)
							typ=t1->Lentry->type;
						else
							typ=t1->Gentry->type;	
						f1=fLookup(typ,t1->left->varname)->fieldIndex;
					}
					t1=t1->left;
					fprintf(target,"MOV R%d, [R%d]\n",p2,p2); pos++;
					fprintf(target,"ADD R%d, %d\n",p2,f1); pos++;
					if(t1->left!=NULL)
						{fprintf(target,"MOV R%d, [R%d]\n",p2,p2); pos++;}		
				}
				while(t1->left!=NULL){
					f1=fLookup(t1->type,t1->left->varname)->fieldIndex;
					t1=t1->left;
					fprintf(target,"ADD R%d, %d\n",p2,f1); pos++;
					if(t1->left==NULL)
						break;
					fprintf(target,"MOV R%d, [R%d]\n",p2,p2); pos++;
				}
				if(t1->left!=NULL){
					printf("Fatal Error\n");
					exit(1);
				}
				fprintf(target,"MOV [R%d], R%d\n",p2,p); pos++;
				freereg();
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
	else if(t->nodetype == 13){										  //Field
		int ff=0,r1;
		r1=getreg();
		if(t->Lentry!=NULL){
			addr=t->Lentry->binding;
			ff=1;
		}
		else{
			addr=t->Gentry->binding;
		}
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
		if(t->left==NULL){
			fprintf(target,"MOV R%d, R%d\n",r1,p); pos++;
			freereg();
			return r1;
		}
		int f1;
		struct tnode *t1=t;
		if(t1->left!=NULL){
			struct Typetable *typ;
			if(t1->Lentry!=NULL)
				typ=t1->Lentry->type;
			else
				typ=t1->Gentry->type;	
			f1=fLookup(typ,t1->left->varname)->fieldIndex;
			t1=t1->left;
			fprintf(target,"ADD R%d, %d\n",p,f1); pos++;
			if(t1->left!=NULL)
				{fprintf(target,"MOV R%d, [R%d]\n",p,p); pos++;}		
		}
		while(t1->left!=NULL){
			f1=fLookup(t1->type,t1->left->varname)->fieldIndex;
			t1=t1->left;
			fprintf(target,"ADD R%d, %d\n",p,f1); pos++;
			if(t1->left==NULL)
				break;
			fprintf(target,"MOV R%d, [R%d]\n",p,p); pos++;
		}
		fprintf(target,"MOV R%d, [R%d]\n",r1,p); pos++;
		freereg();
		return r1;
	}
	else if(t->nodetype == 14){
		if(!strcmp(t->varname,"free")){
			int k2=k>2?2:k;
			q=codegen(t->left,target);
			p=getreg();
			for(int i=0;i<=k2;i++)
				{fprintf(target,"PUSH R%d\n",i); pos++;}
			fprintf(target,"MOV R%d, \"free\"\n",p); pos++;
			fprintf(target,"PUSH R%d\n",p); pos++;
			fprintf(target,"MOV R%d, R%d\n",p,q); pos++;
			fprintf(target,"PUSH R%d\n",p); pos++;
			fprintf(target,"PUSH R%d\n",p); pos++;
			fprintf(target,"PUSH R%d\n",p); pos++;
			fprintf(target,"PUSH R%d\n",p); pos++;
			fprintf(target,"CALL 0\n"); pos++;
			fprintf(target, "POP R%d\n", p); pos++;
    		fprintf(target, "POP R%d\n", p); pos++;
    		fprintf(target, "POP R%d\n", p); pos++;
    		fprintf(target, "POP R%d\n", p); pos++;
    		fprintf(target, "POP R%d\n", p); pos++;
    		for(int i=k2;i>=0;i--)
    			{fprintf(target, "POP R%d\n", i); pos++;}
    		freereg();
    		freereg();
    //------------------------------------------------------------------------------------------
    		/*p=getreg();
    		q=getreg();
    		for(int i=1024;i<=1056;i+=8){
    			fprintf(target, "MOV R%d, [%d]\n", p,i);pos++;	
    			fprintf(target, "MOV R%d, %d\n", q, 5); pos++;
    			fprintf(target, "PUSH R%d\n", q); pos++;
    			fprintf(target, "MOV R%d, %d\n", q, -2); pos++;
    			fprintf(target, "PUSH R%d\n", q); pos++;
    			fprintf(target, "PUSH R%d\n", p); pos++;
    			fprintf(target, "PUSH R%d\n", p); pos++;
    			fprintf(target, "PUSH R%d\n", p); pos++;
    			fprintf(target, "INT 7\n"); pos++;
				fprintf(target, "POP R%d\n", q); pos++;
    			fprintf(target, "POP R%d\n", q); pos++;
    			fprintf(target, "POP R%d\n", q); pos++;
    			fprintf(target, "POP R%d\n", q); pos++;
    			fprintf(target, "POP R%d\n", q); pos++;
    		}
    		fprintf(target, "MOV R%d, \"-----------------------------\"\n", p);pos++;
    		fprintf(target, "MOV R%d, %d\n", q, 5); pos++;
    		fprintf(target, "PUSH R%d\n", q); pos++;
    		fprintf(target, "MOV R%d, %d\n", q, -2); pos++;
    		fprintf(target, "PUSH R%d\n", q); pos++;
    		fprintf(target, "PUSH R%d\n", p); pos++;
    		fprintf(target, "PUSH R%d\n", p); pos++;
    		fprintf(target, "PUSH R%d\n", p); pos++;
    		fprintf(target, "INT 7\n"); pos++;
			fprintf(target, "POP R%d\n", q); pos++;
    		fprintf(target, "POP R%d\n", q); pos++;
    		fprintf(target, "POP R%d\n", q); pos++;
    		fprintf(target, "POP R%d\n", q); pos++;
    		fprintf(target, "POP R%d\n", q); pos++;
    		fprintf(target, "BRKP\n"); pos++;
    		freereg();
    		freereg();*/
    //-------------------------------------------------------------------------------------------
    		return -1;
		}
		else if(!strcmp(t->right->varname,"initialize()")){
			int k2=k>2?2:k;
			p=getreg();
			for(int i=0;i<=k2;i++)
				{fprintf(target,"PUSH R%d\n",i); pos++;}
			fprintf(target,"MOV R%d, \"Heapset\"\n",p); pos++;
			fprintf(target,"PUSH R%d\n",p); pos++;
			fprintf(target,"PUSH R%d\n",p); pos++;
			fprintf(target,"PUSH R%d\n",p); pos++;
			fprintf(target,"PUSH R%d\n",p); pos++;
			fprintf(target,"PUSH R%d\n",p); pos++;
			fprintf(target,"CALL 0\n"); pos++;
			fprintf(target,"BRKP\n"); pos++;
			fprintf(target, "POP R%d\n", p); pos++;
    		fprintf(target, "POP R%d\n", p); pos++;
    		fprintf(target, "POP R%d\n", p); pos++;
    		fprintf(target, "POP R%d\n", p); pos++;
    		fprintf(target, "POP R%d\n", p); pos++;
    		for(int i=k2;i>=0;i--)
    			{fprintf(target, "POP R%d\n", i); pos++;}
    		freereg();
    		return -1;
		}
		else if(!strcmp(t->right->varname,"null")){
			p=codegen(t->left,target);
			q=getreg();
			fprintf(target,"MOV R%d, \"null\"\n",q); pos++;
			if(!strcmp(t->varname,"!=")){
				fprintf(target, "NE R%d, R%d\n",p,q); pos++;
				freereg();
			}
			else if(!strcmp(t->varname,"==")){
				fprintf(target, "EQ R%d, R%d\n",p,q); pos++;
				freereg();
			}
			else{
				printf("Invalid null operation\n");
				exit(1);
			}
			return p;
		}
		else{
			printf("Invalid\n");
			exit(1);
		}
	}
	else if(t->nodetype==15){
		if(selflab==0){
			printf("Node15 error\n");
			exit(1);
		}
		int r1=getreg();
		p=getreg();
		q=getreg();
		fprintf(target,"MOV R%d, %d\n",q,selflab); pos++;
		fprintf(target,"ADD R%d, BP\n",q); pos++;
		fprintf(target,"MOV R%d, [R%d]\n",p,q); pos++;
		freereg();
		if(t->left==NULL){
			fprintf(target,"MOV R%d, R%d\n",r1,p); pos++;
			freereg();
			return r1;
		}
		int f1;
		struct tnode *t1=t;
		if(t1->left!=NULL){
			f1=fLookup(tLookup(currclass->name),t1->left->varname)->fieldIndex;
			t1=t1->left;
			fprintf(target,"ADD R%d, %d\n",p,f1); pos++;
			if(t1->left!=NULL)
				{fprintf(target,"MOV R%d, [R%d]\n",p,p); pos++;}		
		}
		while(t1->left!=NULL){
			f1=fLookup(t1->type,t1->left->varname)->fieldIndex;
			t1=t1->left;
			fprintf(target,"ADD R%d, %d\n",p,f1); pos++;
			if(t1->left==NULL)
				break;
			fprintf(target,"MOV R%d, [R%d]\n",p,p); pos++;
		}
		fprintf(target,"MOV R%d, [R%d]\n",r1,p); pos++;
		freereg();
		return r1;
	}
	return -1;
}
	
void freereg(){
	k--;
	if(k==-2){
		printf("Freereg error\n");
		exit(1);
	}
}

int getreg(){
	k++;
	return k;
}	


			
		















