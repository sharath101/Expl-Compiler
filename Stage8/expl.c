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
int cnum=0,fnum=0,mnum=0;
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

/*-------------------------------LOCAL END-------------------------------*/

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
	if(first==NULL && second==NULL)
		return 1;
	else if(first!=NULL && second==NULL)
		return 0;
	else if(first==NULL && second!=NULL)
		return 0;
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
	c->method=mroot;
	c->field=cfroot;
	idaddr+=8;
	struct Classtable *p=NULL;
	if(parentname!=NULL){
		if(cLookup(parentname)==NULL){
			printf("Class doesn't exist to extend\n");
			exit(1);
		}
		int m,f;
		p=cLookup(parentname);
		mnum=p->methodnum;
		fnum=p->fieldnum;
		m=copymethod(p->method);
		f=copyfield(p->field);
		c->method=mroot;
		c->field=cfroot;
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

void createvirtualtable(FILE *fptr){
	struct Classtable *c=croot;
	int c1=0;
	if(c==NULL)
		return;
	while(c->next!=NULL){
		struct Memberfunclist *m=c->method;
		if(m==NULL){
			c1++;
			continue;
		}
		while(m->next!=NULL){
			fprintf(fptr, "MOV [%d], F%d\n",4096+8*c1+m->fpos,m->flabel);pos++;
			m=m->next;
		}
		fprintf(fptr, "MOV [%d], F%d\n",4096+8*c1+m->fpos,m->flabel);pos++;
		c1++;
		c=c->next;
	}
	struct Memberfunclist *m=c->method;
	if(m==NULL){
		c1++;
		return;
	}
	while(m->next!=NULL){
		fprintf(fptr, "MOV [%d], F%d\n",4096+8*c1+m->fpos,m->flabel);pos++;
		m=m->next;
	}
	fprintf(fptr, "MOV [%d], F%d\n",4096+8*c1+m->fpos,m->flabel);pos++;
	return;
}

int copyfield(struct Fieldlist *par){
	cfroot=NULL;
	struct Fieldlist *p=par,*f1;
	int r=0;
	if(par==NULL)
		return 0;
	while(p->next!=NULL){
		struct Fieldlist *f=(struct Fieldlist *)malloc(sizeof(struct Fieldlist));
		f->name=(char *)malloc(sizeof(char));
		strcpy(f->name,p->name);
		f->fieldIndex=p->fieldIndex;
		f->type=p->type;
		f->Ctype=p->Ctype;
		f->next=NULL;
		if(r!=0)
			f1->next=f;
		else
			cfroot=f;
		f1=f;
		r++;
		p=p->next;
	}
	struct Fieldlist *f=(struct Fieldlist *)malloc(sizeof(struct Fieldlist));
	f->name=(char *)malloc(sizeof(char));
	strcpy(f->name,p->name);
	f->fieldIndex=p->fieldIndex;
	f->type=p->type;
	f->Ctype=p->Ctype;
	f->next=NULL;
	if(r!=0)
		f1->next=f;
	else
		cfroot=f;
	r++;
	return r;
}

int copymethod(struct Memberfunclist *par){
	mroot=NULL;
	struct Memberfunclist *p=par,*m1;
	int r=0;
	if(par==NULL)
		return 0;
	while(p->next!=NULL){
		struct Memberfunclist *m=(struct Memberfunclist *)malloc(sizeof(struct Memberfunclist));
		m->name=(char*)malloc(sizeof(char));
		strcpy(m->name,p->name);
		m->type=p->type;
		m->paramlist=p->paramlist;
		m->fpos=p->fpos;
		m->flabel=p->flabel;
		m->Ctype=p->Ctype;
		m->next=NULL;
		if(r!=0)
			m1->next=m;
		else
			mroot=m;
		m1=m;
		r++;
		p=p->next;
	}
	struct Memberfunclist *m=(struct Memberfunclist *)malloc(sizeof(struct Memberfunclist));
	m->name=(char*)malloc(sizeof(char));
	strcpy(m->name,p->name);
	m->type=p->type;
	m->paramlist=p->paramlist;
	m->fpos=p->fpos;
	m->flabel=p->flabel;
	m->Ctype=p->Ctype;
	m->next=NULL;
	if(r!=0)
		m1->next=m;
	else
		mroot=m;
	r++;
	return r;
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
	if(cLookup(type->name)!=NULL)
		fnum+=2;
	else
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
	cptr->field=cfroot;
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
	f->next=NULL;
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
	if(cptr->parentptr!=NULL){
		if(cmlookup(cptr->parentptr,name)!=NULL){
			if(!checkparamlist(cmlookup(cptr->parentptr,name)->paramlist,paramlist)){
				printf("Methods cannot be overloaded\n");
				exit(1);
			}
			struct Memberfunclist *m1=mroot,*m2=mroot;
			while(m1->next!=NULL){
				if(!strcmp(m1->name,name))
					break;
				m2=m1;
				m1=m1->next;
				
			}
			if(!strcmp(m1->name,name));
			else{
				printf("Fatal method deletion error\n");
				exit(1);
			}
			f->fpos=m1->fpos;
			mnum--;
			if(m2==m1)
				mroot=m1->next;
			else
				m2->next=m1->next;
			free(m1);
		}
	}
	cptr->method=mroot;
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
	int r=0;
	struct Memberfunclist *fs=m;
	while(fs->next!=NULL){
		r++;
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
    temp->cptr = NULL;
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
    temp->cptr = NULL;
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
    temp->cptr = NULL;
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
    temp->cptr = NULL;
}

struct tnode* makeleafvar(char* var,int narg, struct Typetable *type)
{
    struct tnode *temp;                                        
    temp = (struct tnode*)malloc(sizeof(struct tnode));        
	temp->varname = malloc(sizeof(char));                    
	temp->arg = malloc(sizeof(char));						   
    if(type==NULL){
    	printf("leafvartype NULL\n");
    	exit(1);
    }
    temp->type = type;                   //type;                 
    temp->val = narg;                    // For arrays
    if(!checklvar(var)){
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
    temp->cptr = NULL;
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
		c=cLookup(u->type->name);
	}
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
		if(l->cptr!=NULL && r->cptr!=NULL){
			struct Classtable *cp=l->cptr;
			struct Classtable *cc=r->cptr;
			int k1=0;
			while(cc->parentptr!=NULL){
				if(!strcmp(cp->name,cc->name)){
					k1=1;
					break;
				}
				cc=cc->parentptr;
			}
			if(!strcmp(cp->name,cc->name))
				k1=1;
			if(k1==0){
				printf("Class Type mismatch\n");
				exit(1);
			}
		}
		else if(l->type!=r->type && r->type->typen!=4){
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
	if(r!=NULL){
		if(r->varname!=NULL){
			if(!strcmp(r->varname,"new")){
				int k1=0;
				struct Classtable *cp=cLookup(l->type->name);
				struct Classtable *cc=cLookup(m->type->name);
				while(cc->parentptr!=NULL){
					if(!strcmp(cp->name,cc->name))
						k1=1;
					cc=cc->parentptr;
				}
				if(!strcmp(cp->name,cc->name))
					k1=1;
				if(k1==0){
					printf("%s is not a descendent of %s\n",m->type->name,cp->name);
					exit(1);
				}
			}	
		}
	}
    temp->val = 0;
	temp->nodetype = nt;
	temp->arglist = arg;
	temp->argp = NULL;
	temp->left = l;
    temp->right = r;
    temp->mid = m;
    temp->cptr = NULL;
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
		struct tnode *t1=t,*t3;
		struct Classtable *c1,*tt;
		struct Paramstruct *par;
		if(t1->left!=NULL){
			self=1;
			struct tnode *t2;
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
					t3=t1;
					par=cmlookup(cLookup(cflookup(currclass,t1->varname)->type->name),t1->left->varname)->paramlist;
					fprintf(target,"MOV R%d, %d\n",q,selflab); pos++;
					fprintf(target,"ADD R%d, BP\n",q); pos++;
					fprintf(target,"MOV R%d, [R%d]\n",p,q); pos++;
					int fla=cflookup(currclass,t1->varname)->fieldIndex;
					fprintf(target,"ADD R%d, %d\n",p,fla); pos++;
					fprintf(target,"MOV R%d, R%d\n",q,p); pos++;
					fprintf(target,"ADD R%d, %d\n",q,1); pos++;
					fprintf(target,"MOV R%d, [R%d]\n",q,q); pos++;
					fprintf(target,"PUSH R%d\n",q); pos++;
					fprintf(target,"PUSH R%d\n",p); pos++;
					t1=t1->left;
					c1=cLookup(t3->type->name);
					if(c1==NULL)
						c1=t1->cptr;
				}
				else{
					fprintf(target,"MOV R%d, %d\n",q,selflab-1); pos++;
					fprintf(target,"ADD R%d, BP\n",q); pos++;
					fprintf(target,"MOV R%d, [R%d]\n",p,q); pos++;
					fprintf(target,"PUSH R%d\n",p); pos++;
					fprintf(target,"MOV R%d, %d\n",q,selflab); pos++;
					fprintf(target,"ADD R%d, BP\n",q); pos++;
					fprintf(target,"MOV R%d, [R%d]\n",p,q); pos++;
					fprintf(target,"PUSH R%d\n",p); pos++;
					c1=currclass;
				}
				freereg();
				freereg();
			}
			else{
				c1=cLookup(t3->type->name);
				if(c1==NULL)
					c1=t1->cptr;
				if(t3->Lentry!=NULL){
					printf("Cannot declare class as local variable\n");
					exit(1);
				}
				else if(t3->Gentry!=NULL)
					addr=t3->Gentry->binding;
				else{
					printf("No adress found\n");
					exit(1);
				}
				p=getreg();
				fprintf(target, "MOV R%d, [%d]\n",p,addr+1); pos++;
				fprintf(target,"PUSH R%d\n",p); pos++;
				fprintf(target,"MOV R%d, [%d]\n",p,addr); pos++;
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
		if(self==1){
			int w=getreg();
			if(!strcmp(t->varname,"self")){
				if(t->left->left!=NULL){
					fprintf(target,"MOV R%d, %d\n",w,selflab); pos++;
					fprintf(target,"ADD R%d, BP\n",w); pos++;
					fprintf(target,"MOV R%d, [R%d]\n",w,w); pos++;
					int fla=cflookup(currclass,t3->varname)->fieldIndex+1;
					fprintf(target,"ADD R%d, %d\n",w,fla); pos++;
					fprintf(target,"MOV R%d, [R%d]\n",w,w); pos++;
					e=cmlookup(c1,t1->varname)->fpos;
					fprintf(target,"ADD R%d, %d\n",w,e); pos++;
					fprintf(target,"MOV R%d, [R%d]\n",w,w); pos++;
					fprintf(target, "CALL R%d\n",w); pos++;
				}
				else{
					fprintf(target,"MOV R%d, %d\n",w,selflab-1); pos++;
					fprintf(target,"ADD R%d, BP\n",w); pos++;
					fprintf(target,"MOV R%d, [R%d]\n",w,w); pos++;
					e=cmlookup(c1,t->left->varname)->fpos;
					fprintf(target,"ADD R%d, %d\n",w,e); pos++;
					fprintf(target,"MOV R%d, [R%d]\n",w,w); pos++;
					fprintf(target, "CALL R%d\n",w); pos++;
				}
			}										
			else{
				int addr=t3->Gentry->binding+1;
				e=cmlookup(c1,t1->varname)->fpos;
				fprintf(target, "MOV R%d, [%d]\n",w,addr); pos++;
				fprintf(target, "ADD R%d, %d\n",w,e); pos++;
				fprintf(target, "MOV R%d, [R%d]\n",w,w);pos++;
				fprintf(target, "CALL R%d\n",w); pos++;
			}
			freereg();
		}
		else{
			e=getflabel(t1->varname);
			fprintf(target, "CALL F%d\n",e);pos++;
		}
		p=getreg();
		fprintf(target, "POP R%d\n",p);pos++;
		q=getreg();
		for(int i=0;i<argnum;i++){
			fprintf(target, "POP R%d\n",q);
			pos++;
		}
		if(t->left!=NULL){	//self & vtable
			fprintf(target, "POP R%d\n",q);pos++;
			fprintf(target, "POP R%d\n",q); pos++;
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
		if(!strcmp(t->varname,"break")){
			fprintf(target, "JMP L%d\n",temp2[whilenum]);
		}
		else if(!strcmp(t->varname,"continue")){
			fprintf(target, "JMP L%d\n",temp1[whilenum]);
		}
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
			else if(!strcmp(t->text,"alloc()") || !strcmp(t->text,"new")){
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
    				fprintf(target, "INT 7\n"); pos++;var: n

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
			int ff=0;
			if(t->Lentry!=NULL){
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
				fprintf(target,"MOV R%d, [R%d]\n",p,q);pos++;
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
		int ff=0;
		if(t->left->Lentry!=NULL){
			addr=t->left->Lentry->binding;
			ff=1;
		}
		else if(t->left->Gentry!=NULL){
			addr=t->left->Gentry->binding;
		}
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
		else if(t->left->nodetype==13 || t->left->nodetype==15){
			if(t->left->nodetype==15){
				fprintf(target,"MOV R%d, %d\n",q,selflab); pos++;
				fprintf(target,"ADD R%d, BP\n",q); pos++;
				fprintf(target,"MOV R%d, R%d\n",p,q); pos++;
			}
			else{
				if(ff==1){
					fprintf(target,"MOV R%d, %d\n",q,addr); pos++;
					fprintf(target,"ADD R%d, BP\n",q); pos++;
					fprintf(target,"MOV R%d, R%d\n",p,q); pos++;
				}
				else{
					fprintf(target,"MOV R%d, %d\n",p,addr); pos++;
				}
			}
			int f1;
			struct tnode *t1=t->left;
			if(t1->left!=NULL){
				struct Typetable *typ;
				if(t->left->nodetype==15){
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
				fprintf(target,"MOV R%d, [R%d]\n",p,p); pos++;
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
			if(t1->left!=NULL){
				printf("Fatal Error\n");
				exit(1);
			}
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
			if(!strcmp(t->varname,">=")){
            	fprintf(target, "GE R%d, R%d\n",p,q);
            }
            else if(!strcmp(t->varname,">")){
            	fprintf(target, "GT R%d, R%d\n",p,q);
            }
            else if(!strcmp(t->varname,"<=")){
            	fprintf(target, "LE R%d, R%d\n",p,q);
            }
            else if(!strcmp(t->varname,"<")){
            	fprintf(target, "LT R%d, R%d\n",p,q);
            }
            else if(!strcmp(t->varname,"!=")){
            	fprintf(target, "NE R%d, R%d\n",p,q);
            }
            else if(!strcmp(t->varname,"==")){
            	fprintf(target, "EQ R%d, R%d\n",p,q);
            }
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
			p=codegen(t->right,target);
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
			int vadd=-1,q1=getreg();
			if(!strcmp(t->left->varname,"self") && t->mid!=NULL){
				fprintf(target,"MOV R%d, %d\n",q1,selflab); pos++;
				fprintf(target,"ADD R%d, BP\n",q1); pos++;
				fprintf(target,"MOV R%d, [R%d]\n",q1,q1); pos++;
				int pos1=cflookup(currclass,t->left->left->varname)->fieldIndex;
				fprintf(target,"ADD R%d, %d\n",q1,pos1+1); pos++;
				vadd=4096+cLookup(t->mid->type->name)->classindex*8;
				fprintf(target,"MOV [R%d], %d\n",q1,vadd); pos++;
			}
			else if(cLookup(t->left->type->name)!=NULL && cLookup(t->right->type->name)!=NULL && !strcmp(t->left->varname,"self")){
				if(strcmp(t->right->varname,"self")){
					printf("Cannot declare class as a local variable error\n");
					exit(1);
				}
				int p1=getreg();
				fprintf(target,"MOV R%d, %d\n",q1,selflab); pos++;
				fprintf(target,"ADD R%d, BP\n",q1); pos++;
				fprintf(target,"MOV R%d, [R%d]\n",q1,q1); pos++;
				int posl=cflookup(currclass,t->left->left->varname)->fieldIndex;
				int posr=cflookup(currclass,t->right->left->varname)->fieldIndex;
				fprintf(target,"MOV R%d, R%d\n",p1,q1); pos++;
				fprintf(target,"ADD R%d, %d\n",p1,posr+1); pos++;
				fprintf(target,"ADD R%d, %d\n",q1,posl+1); pos++;
				fprintf(target,"MOV R%d, R%d\n",q1,p1); pos++;
				freereg();
			}
			else if(t->mid!=NULL && !strcmp(fname,"main")){
				vadd=4096+cLookup(t->mid->type->name)->classindex*8;
				fprintf(target,"MOV R%d, %d\n",q1,addr+1); pos++;
				fprintf(target,"MOV [R%d], %d\n",q1,vadd); pos++;
			}
			else if(cLookup(t->left->type->name)!=NULL && cLookup(t->right->type->name)!=NULL && !strcmp(fname,"main")){
				if(t->left->left!=NULL || t->right->left!=NULL){
					printf("class child error\n");
					exit(1);
				}
				vadd=4096+cLookup(t->right->type->name)->classindex*8;
				int addr1=t->right->Gentry->binding;
				fprintf(target,"MOV R%d, [%d]\n",q1,addr1+1); pos++;
				fprintf(target,"MOV [%d], R%d\n",addr+1,q1); pos++;
			}
			freereg();
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

void exitprogram(FILE *target){
	int p=getreg();
	int q=getreg();
	fprintf(target, "MOV R%d, %d\n", q, 10);
    fprintf(target, "PUSH R%d\n", q);
    fprintf(target, "PUSH R%d\n", q);
    fprintf(target, "PUSH R%d\n", q);
    fprintf(target, "PUSH R%d\n", q);
    fprintf(target, "PUSH R%d\n", q);
    fprintf(target, "INT 10\n");
	fprintf(target, "POP R%d\n", q);
    fprintf(target, "POP R%d\n", q);
    fprintf(target, "POP R%d\n", q);
    fprintf(target, "POP R%d\n", q);
    fprintf(target, "POP R%d\n", q);
	pos+=13;
	freereg();
	freereg();
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



			
		















