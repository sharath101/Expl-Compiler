int a[26];

struct tnode* makeleafnum(int n)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->type = 0;
    temp->val = n;
	temp->varname = NULL;
	temp->nodetype = 0;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeleafvar(char c)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->varname = malloc(sizeof(char));
    temp->type = 0;
    temp->val = 0;
	*(temp->varname) = c;
	temp->nodetype = 0;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makenode(char c,int nt,struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->varname = malloc(sizeof(char));
    *(temp->varname) = c;
	temp->type = 0;
    temp->val = 0;
	temp->nodetype = nt;
	if(nt==1 || nt==2){
		temp->left=l;
		temp->right=NULL;
	}
	else{
    	temp->left = l;
    	temp->right = r;
	}
    return temp;
}

int evaluate(struct tnode *t){
	int addr,p,q;
	if(t->nodetype == 3){
		p=evaluate(t->left);
		q=evaluate(t->right);
		return -1;
	}
	else if(t->nodetype == 0){
		if(t->varname == NULL)
			return t->val;
		else{
			addr=*(t->varname)-'a';
			return a[addr];
		}
	}		
	else if(t->nodetype == 1){
		addr=*(t->left->varname)-'a';
		int k;
		scanf("%d",&k);
		a[addr]=k;
		return -1;
	}
	else if(t->nodetype == 2){
		if(t->left->nodetype != 0){
			p=evaluate(t->left);
			printf("%d\n",p);
		}
		else
			printf("%d\n",t->left->val);
		return -1;	
	}
	else if(t->nodetype == 4){
		if(*(t->varname) == '='){
			int temp;
			p=evaluate(t->right);
			addr=*(t->left->varname)-'a';
			a[addr]=p;
			return -1;
		}
		else{
			p=evaluate(t->left);
			q=evaluate(t->right);
			if(*(t->varname)=='+')
				return p+q;
			else if(*(t->varname)=='-')
				return p-q;
			else if(*(t->varname)=='*')
				return p*q;
			else if(*(t->varname)=='/')
				return p/q;
		}
	}
	return -1;
}
			
		















