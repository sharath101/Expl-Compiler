int k=-1,r=0,pos=0,a[1000];

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

int codegen(struct tnode *t,FILE *target){
	int p=-1,q=-1,addr;
	if(t->nodetype == 3){
		p=codegen(t->left,target);
		q=codegen(t->right,target);
		return -1;
	}
	else if(t->nodetype == 0){
		if(t->varname == NULL){
			p=getreg();
			fprintf(target,"MOV R%d, %d\n",p,t->val);
			pos++;
			return p;
		}
		else{
			addr=*(t->varname)-'a' + 4096;
			p=getreg();
			fprintf(target,"MOV R%d, [%d]\n",p,addr);
			pos++;
			return p;
		}
	}		
	else if(t->nodetype == 1){
		p=getreg();
		q=getreg();
		addr=*(t->left->varname)-'a' + 4096;
		fprintf(target, "MOV SP, %d\n", 4122);
    	fprintf(target, "MOV R%d, %d\n", p, addr);
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
		pos+=15;
		freereg();
		freereg();
		return -1;
	}
	else if(t->nodetype == 2){
		if(t->left->nodetype != 0)
			p=codegen(t->left,target);
		p=getreg();
		if(t->left->varname == NULL){
			fprintf(target,"MOV R%d, %d\n",p,t->left->val);
			pos++;
		}
		else{
			addr=*(t->left->varname)-'a' + 4096;
			fprintf(target,"MOV R%d, [%d]\n",p,addr);
			pos++;
		}
		q=getreg();
		fprintf(target, "MOV SP, %d\n", 4122);
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
		pos+=14;
		freereg();
		return -1;	
	}
	else if(t->nodetype == 4){
		if(*(t->varname) == '='){
			int temp;
			p=codegen(t->right,target);
			addr=*(t->left->varname)-'a' + 4096;
			fprintf(target,"MOV [%d], R%d\n",addr,p);
			pos++;
			return -1;
		}
		else{
			p=codegen(t->left,target);
			q=codegen(t->right,target);
			if(*(t->varname)=='+'){
				fprintf(target, "ADD R%d, R%d\n", p, q);
				pos++;
			}
			else if(*(t->varname)=='-'){
				fprintf(target, "SUB R%d, R%d\n", p, q);
				pos++;
			}
			else if(*(t->varname)=='*'){
				fprintf(target, "MUL R%d, R%d\n", p, q);
				pos++;
			}
			else if(*(t->varname)=='/'){
				fprintf(target, "DIV R%d, R%d\n", p, q);
				pos++;
			}
			else if(*(t->varname)=='@'){
				fprintf(target, "DCR R%d\n",q);
				pos++;
				fprintf(target, "L%d:\n", r);
				a[r]=2*pos+2056-2*r;
				fprintf(target, "MUL R%d, R%d\n", p, p);
				fprintf(target, "DCR R%d\n",q);
				fprintf(target, "JNZ R%d, L%d\n",q,r);
				r++;
				pos+=4;
			} 
			freereg();
			return p;
		}
	}
	return -1;
}
	
void freereg(){
	k--;
}

int getreg(){
	k++;
	return k;
}	
			
		















