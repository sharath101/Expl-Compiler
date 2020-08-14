#define inttype 2
#define booltype 1

typedef struct tnode { 
	int val;						// value of a number for NUM nodes.
	char *text;						// text for string type;
	struct Typetable *type;			//type of variable
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
	struct Typetable *type;
	struct Paramstruct *next;
};

struct Gsymbol {
	char* name;						// name of the variable
	struct Typetable *type;			// type of the variable
	int size;						// size of the type of the variable
	int binding;					// stores the static memory address allocated to the variable
	struct Paramstruct *paramlist;	//pointer to the head of the formal parameter list in the case of functions
	int flabel;						//a label for identifying the starting address of a function's code
	struct Gsymbol *next;
};

struct Lsymbol{
	char *name;				//name of the variable
	struct Typetable *type; //type of the variable:(Integer / String)
	int binding;			//local binding of the variable
	struct Lsymbol *next;	//points to the next Local Symbol Table entry
}; 

struct Typetable{
    char *name;					//type name
    int size;					//size of the type
    int typen;					//Type number
    struct Fieldlist *fields;	//pointer to the head of fields list
    struct Typetable *next;		// pointer to the next type table entry
};

struct Fieldlist{
  char *name;				//name of the field
  int fieldIndex;			//the position of the field in the field list
  struct Typetable *type;	//pointer to type table entry of the field's type
  struct Fieldlist *next;	//pointer to the next field
};

struct Gsymbol *gLookup(char * name);
struct Gsymbol *newgid(char *name, struct Typetable *type, int size);
struct Gsymbol *Appendgparam(struct Gsymbol *gs,struct Paramstruct *ps);
int checkgvar();
int getflabel(char* name);
void gdisplay();

struct Lsymbol *newlid(char *nam, struct Typetable *type);
struct Lsymbol *lLookup(char *name);
void setlocalbinding(struct Paramstruct *param,struct Lsymbol *lsym);
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

struct tnode* argconnect(struct tnode *first,struct tnode *second);
struct tnode* fieldconnect(struct tnode *first,struct tnode *second);
struct tnode* makearraynode(char* var,struct Typetable *type,struct tnode *l);
struct tnode* makeleaf(char *c,int nt);
struct tnode* makeleafnum(int n,char *text,struct Typetable *type);
struct tnode* makeleafvar(char *c,int arg,struct Typetable *type);    // arg is for arrays
struct tnode* makenode(char *c,int nt,struct Typetable *t,struct tnode *arg,struct tnode *l,struct tnode *m,struct tnode *r);

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
Userdefined types continue from 5
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
field      13
dynmemstmt 14
*/

