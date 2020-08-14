int k=-1;

struct tnode* makeLeafNode(int n)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = malloc(sizeof(char));
    *(temp->op) = c;
    temp->left = l;
    temp->right = r;
    return temp;
}

int evaluate(struct tnode *t){
    if(t->op == NULL)
    {
        return t->val;
    }
    else{
        switch(*(t->op)){
            case '+' : return evaluate(t->left) + evaluate(t->right);
                       break;
            case '-' : return evaluate(t->left) - evaluate(t->right);
                       break;
            case '*' : return evaluate(t->left) * evaluate(t->right);
                       break;
            case '/' : return evaluate(t->left) / evaluate(t->right);
                       break;
        }
    }
}
int codegen(struct tnode *t,FILE *target){
	int p,q;
	if(t->left->op==NULL){
		p=getreg();
		fprintf(target,"MV R%d, %d\n",p,t->left->val);
	}
	else{
		p=codegen(t->left,target);
	}
	if(t->right->op==NULL){
		q=getreg();
		fprintf(target,"MV R%d, %d\n",q,t->right->val);
	}
	else{
		q=codegen(t->right,target);
	}
	if(*(t->op)=='+')
		fprintf(target, "ADD R%d, R%d\n", p, q);
	else if(*(t->op)=='-')
		fprintf(target, "SUB R%d, R%d\n", p, q);
	else if(*(t->op)=='*')
		fprintf(target, "MUL R%d, R%d\n", p, q);
	else if(*(t->op)=='/')
		fprintf(target, "DIV R%d, R%d\n", p, q);
	freereg();
	return p;
}

void freereg(){
	k--;
}

int getreg(){
	k++;
	return k;
}

void store(int i, FILE *target){
	int p = getreg();
    int q = getreg();
    fprintf(target, "MOV SP, %d\n", 4096);
    fprintf(target, "MOV [%d], R%d\n", 4095, i);
    fprintf(target, "MOV R%d, [%d]\n", p, 4095);
    fprintf(target, "MOV R%d, %d\n", q, 5);
    fprintf(target, "PUSH %d\n", q);
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
    freereg();
    freereg();
}
	

	
		




















		
	
