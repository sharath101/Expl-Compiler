#define inttype 2
#define booltype 1

typedef struct tnode { 
	int val;						// value of a number for NUM nodes.
	char *text;						// text for string type;
	struct Typetable *type;			//type of variable
	char* varname;					//name of a variable for ID nodes  
	char* arg;						//for array with variable arguments
	int nodetype;					// information about non-leaf nodes - read/write/connector/+/* etc.  
	struct Classtable *cptr;		//pointer to the class table
	struct Gsymbol *Gentry;			//pointer to GST entry for global variables and functions
	struct Lsymbol *Lentry;			//pointer to the function's LST for local variables and arguements
	struct tnode *argp;				//each argument points to the next one using this pointer
	struct tnode *arglist;			//Funtion points to the list of arguments using this pointer
	struct tnode *left,*mid,*right;	//left and right branches   
}tnode;

struct Classtable {
 	char *name;						//name of the class
	struct Fieldlist *field;		//pointer to Fieldlist
	struct Memberfunclist *method;	//pointer to Memberfunclist
	struct Classtable *parentptr;	//pointer to the parent's class table
	int classindex;					//position of the class in the virtual function table
	int fieldnum;					//count of fields
  	int methodnum;					//count of methods
	struct Classtable *next;		//pointer to next class table entry
};

struct Paramstruct{
	char* name;
	struct Typetable *type;
	struct Paramstruct *next;
};

struct Gsymbol {
	char* name;						// name of the variable
	struct Typetable *type;			// type of the variable
	int size;						// size of the type of the variable
	int binding;					// stores the static memory address allocated to the variable
	struct Classtable *cptr;		//pointer to the class table
	struct Paramstruct *paramlist;	//pointer to the head of the formal parameter list in the case of functions
	int flabel;						//a label for identifying the starting address of a function's code
	struct Gsymbol *next;
};

struct Lsymbol{
	char *name;						//name of the variable
	struct Typetable *type; 		//type of the variable:(Integer / String)
	int binding;					//local binding of the variable
	struct Lsymbol *next;			//points to the next Local Symbol Table entry
}; 

struct Typetable{
    char *name;						//type name
    int size;						//size of the type
    int typen;						//Type number
    struct Fieldlist *fields;		//pointer to the head of fields list
    struct Typetable *next;			// pointer to the next type table entry
};

struct Fieldlist{
  char *name;						//name of the field
  int fieldIndex;					//the position of the field in the field list
  struct Typetable *type;			//pointer to type table entry of the field's type
  struct Classtable *Ctype; 		//pointer to the class containing the field
  struct Fieldlist *next;			//pointer to the next field
};

struct Memberfunclist {
 	char *name;						//name of the member function in the class
	struct Typetable *type;			//pointer to typetable
	struct Paramstruct *paramlist;	//pointer to the head of the formal parameter list
	int fpos;						//positioIN
 	int flabel;						//A label to identify the starting address of the function's code
 	struct Classtable *Ctype; 		//pointer to the class containing the field
	struct Memberfunclist *next;	//pointer to next Memberfunclist entry
};

struct Gsymbol *gLookup(char * name);
struct Gsymbol *newgid(char *name, struct Typetable *type, int size);
struct Gsymbol *Appendgparam(struct Gsymbol *gs,struct Paramstruct *ps);
int checkgvar();
int getflabel(char* name);
void gdisplay();

struct Lsymbol *newlid(char *nam, struct Typetable *type);
struct Lsymbol *lLookup(char *name);
int setlocalbinding(struct Paramstruct *param,struct Lsymbol *lsym);
int checklvar();
void ldisplay();

struct Paramstruct *newparam(char* name, struct Typetable *type);
struct Paramstruct *Appendparam(struct Paramstruct *first, struct Paramstruct *second);
struct Paramstruct *getparam(char* name);
int checkparamlist(struct Paramstruct *first, struct Paramstruct *second);
int checkarg(struct tnode *arg, struct Paramstruct *par);
int argdisplay(struct tnode *arg);

void TypeTableCreate();
struct Typetable *newtype(char *name);
struct Typetable *tLookup(char *name);
struct Fieldlist *newfield(char *name,struct Typetable *t);
struct Fieldlist *fLookup(struct Typetable *type, char *name);
int GetSize (struct Fieldlist* f);
void tdisplay();
void fdisplay(struct Fieldlist* f);

struct Classtable* newclass(char *name,char *parentname);
struct Classtable* Appendclass(char *name,struct Fieldlist *flist,struct Memberfunclist *mlist,int cnum,int fnum,int mnum);
struct Classtable* cLookup(char *name);
void newcfield(struct Classtable *cptr, struct Typetable *type, char *name); 
void newcmethod(struct Classtable *cptr, char *name, struct Typetable *type, struct Paramstruct *paramlist);
struct Paramstruct *getmethodparam(struct Classtable* c,char* name);
struct Memberfunclist* cmlookup (struct Classtable* ctype,char* name);
struct Fieldlist* cflookup(struct Classtable* ctype,char* name);
int copyfield(struct Fieldlist *par);
int copymethod(struct Memberfunclist *par);
void cfdisplay(struct Fieldlist *f);
void mdisplay(struct Memberfunclist *m);

struct tnode* argconnect(struct tnode *first,struct tnode *second);
struct tnode* fieldconnect(struct tnode *first,struct tnode *second);
struct tnode* makearraynode(char* var,struct Typetable *type,struct tnode *l);
struct tnode* makeleaf(char *c,int nt);
struct tnode* makeleafnum(int n,char *text,struct Typetable *type);
struct tnode* maketext(int n,char *text,struct Typetable *type);
struct tnode* makeleafvar(char *c,int arg,struct Typetable *type);    // arg is for arrays
struct tnode* makemethodnode(struct tnode *ct,char *fname,int nt,struct Typetable *t,struct tnode *arg);
struct tnode* makenode(char *c,int nt,struct Typetable *t,struct tnode *arg,struct tnode *l,struct tnode *m,struct tnode *r);

void freereg();
int getreg();
void createvirtualtable(FILE *target);
void pusharg(struct tnode *targ,FILE *target);
int codegen(struct tnode *t,FILE *target);
void exitprogram(FILE *target);

/*
Type:
1: logical
2: integer
3: string
4: void
Userdefined types continue from 5


Nodetype
0:  leaf       
1:  read       
2:  write      
3:  connector  
4:  operators  
5:  while     
6:  if        
7:  br/cont    
8:  decl       
9:  id[expr]   
10: fcall	    
11: return      
12: body        
13: field       
14: dynmemstmt  
15: self	    
*/

