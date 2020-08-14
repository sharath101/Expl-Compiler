#define inttype 0
#define booltype 1
typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	struct tnode *left,*mid,*right;	//left and right branches   
}tnode;

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
*/

struct tnode* makeleaf(char c,int nt);
struct tnode* makeleafnum(int n);
struct tnode* makeleafvar(char c);
struct tnode* makenode(char *c,int nt,int t,struct tnode *l,struct tnode *m,struct tnode *r);
void freereg();
int getreg();
int codegen(struct tnode *t,FILE *target);

