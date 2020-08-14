#define inttype 0
#define booltype 1

typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	char *text; // text for string type;
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	char* arg;      //for array with variable arguments
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	struct Gsymbol *Gentry;		//pointer to GST entry for global variables and functions
	struct tnode *left,*mid,*right;	//left and right branches   
}tnode;

struct Gsymbol {
	char* name;		// name of the variable
	int type;		// type of the variable
	int size;		// size of the type of the variable
	int binding;	// stores the static memory address allocated to the variable
	struct Gsymbol *next;
};

struct Gsymbol *Lookup(char * name);
void newid(char *name, int type, int size);
int checkvar();
void display();
struct tnode* makearraynode(char* var,int nt,struct tnode *l);
struct tnode* makeleaf(char c,int nt);
struct tnode* makeleafnum(int n,char *text,int type);
struct tnode* makeleafvar(char *c,int arg,int type, char* vararg);    // arg is for arrays
struct tnode* makenode(char *c,int nt,int t,struct tnode *l,struct tnode *m,struct tnode *r);
void freereg();
int getreg();
int codegen(struct tnode *t,FILE *target);

/*
Type:
0: integer
1: logical
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
*/

