typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	struct tnode *left,*right;	//left and right branches   
}tnode;
	
/*
Nodetype:
leaf: 0
read: 1
write: 2
connector: 3
operators: 4
*/
struct tnode* makeleafnum(int n);
struct tnode* makeleafvar(char c);
struct tnode* makenode(char c,int nt,struct tnode *l,struct tnode *r);
int evaluate(struct tnode *t);

