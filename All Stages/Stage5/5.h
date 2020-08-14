#define inttype 2
#define booltype 1

typedef struct tnode { 
	int val;						// value of a number for NUM nodes.
	char *text;						// text for string type;
	int type;						//type of variable
	char* varname;					//name of a variable for ID nodes  
	char* arg;						//for array with variable arguments
	int nodetype;					// information about non-leaf nodes - read/write/connector/+/* etc.  
	struct Gsymbol *Gentry;			//pointer to GST entry for global variables and functions
	struct Lsymbol *Lentry;			//pointer to the function's LST for local variables and arguements
	struct tnode *argp;				//each argument pointd to the next one using this pointer
	struct tnode *arglist;			//Funtion points to the list of arguments using this pointer
	struct tnode *left,*mid,*right;	//left and right branches   
}tnode;

struct Paramstruct{
	char* name;
	int type;
	struct Paramstruct *next;
};

struct Gsymbol {
	char* name;						// name of the variable
	int type;						// type of the variable
	int size;						// size of the type of the variable
	int binding;					// stores the static memory address allocated to the variable
	struct Paramstruct *paramlist;	//pointer to the head of the formal parameter list in the case of functions
	int flabel;						//a label for identifying the starting address of a function's code
	struct Gsymbol *next;
};

struct Lsymbol{
	char *name;				//name of the variable
	int type;				//type of the variable:(Integer / String)
	int binding;			//local binding of the variable
	struct Lsymbol *next;	//points to the next Local Symbol Table entry
}; 


struct Gsymbol *gLookup(char * name);
struct Gsymbol *newgid(char *name, int type, int size);
struct Gsymbol *Appendgparam(struct Gsymbol *gs,struct Paramstruct *ps);
int checkgvar();
int getflabel(char* name);
void gdisplay();

struct Lsymbol *newlid(char *nam, int type);
struct Lsymbol *lLookup(char *name);
void setlocalbinding(struct Paramstruct *param,struct Lsymbol *lsym);
int checklvar();
void ldisplay();

struct Paramstruct *newparam(char* name, int type);
struct Paramstruct *Appendparam(struct Paramstruct *first, struct Paramstruct *second);
struct Paramstruct *getparam(char* name);
int checkparamlist(struct Paramstruct *first, struct Paramstruct *second);
int checkarg(struct tnode *arg, struct Paramstruct *par);
int argdisplay(struct tnode *arg);

struct tnode* argconnect(struct tnode *first,struct tnode *second);
struct tnode* makearraynode(char* var,int nt,int type,struct tnode *l);
struct tnode* makeleaf(char c,int nt);
struct tnode* makeleafnum(int n,char *text,int type);
struct tnode* makeleafvar(char *c,int arg,int type);    // arg is for arrays
struct tnode* makenode(char *c,int nt,int t,struct tnode *arg,struct tnode *l,struct tnode *m,struct tnode *r);

void freereg();
int getreg();
void pusharg(struct tnode *targ,FILE *target);
int codegen(struct tnode *t,FILE *target);

/*
Type:
1: logical
2: integer
3: string
4: void
*/
	
/*
Nodetype:
leaf:      0
read:      1
write:     2
connector: 3
operators: 4
while:     5
if :       6
br/cont    7
decl       8
id[expr]   9
fcall	   10
return     11
body       12
*/

