int k=-1,r=0,pos=0,a[1000],ch=0;

struct tnode* makeleaf(char c,int nt)
{
	struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    temp->type = 0;
    temp->val = 0;
	*(temp->varname) = c;
	temp->nodetype = nt;
    temp->left = NULL;
    temp->mid = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeleafnum(int n)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->type = 0;
    temp->val = n;
	temp->varname = NULL;
	temp->nodetype = 0;
    temp->left = NULL;
    temp->mid = NULL;
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
    temp->mid = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makenode(char *c,int nt,int t,struct tnode *l,struct tnode *m,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->varname = malloc(sizeof(char));
	if(nt==4 && t==inttype){
		if(l->type==booltype || r->type==booltype){
			printf("Type mismatch 1\n");
			exit(1);
		}
	}
	if(nt==5 || nt==6){
		if(l->type==inttype){
			printf("Type mismatch 2\n");
			exit(1);
		}
	}
    temp->varname = c;
	temp->type = t;
    temp->val = 0;
	temp->nodetype = nt;
	temp->left = l;
    temp->right = r;
    temp->mid = m;
    return temp;
}

int codegen(struct tnode *t,FILE *target){
	int p=-1,q=-1,addr;
	if(t->nodetype == 3){
		p=codegen(t->left,target);
		q=codegen(t->right,target);
		if(p!=-1 || q!=-1){
			printf("connector error\n");
			exit(1);
		}
		return -1;
	}
	else if(t->nodetype ==7 && ch==1){
		if(*(t->varname)=='b')
			fprintf(target, "JMP L%d\n",r-1);
		else if(*(t->varname)=='c')
			fprintf(target, "JMP L%d\n",r-2);
		pos++;
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
		if(t->type == booltype){
			p=codegen(t->left,target);
			q=codegen(t->right,target);
			if(!strcmp(t->varname,">="))
            	fprintf(target, "GE R%d, R%d\n",p,q);
            else if(!strcmp(t->varname,">"))
            	fprintf(target, "GT R%d, R%d\n",p,q);
            else if(!strcmp(t->varname,"<="))
            	fprintf(target, "LE R%d, R%d\n",p,q);
            else if(!strcmp(t->varname,"<"))
            	fprintf(target, "LT R%d, R%d\n",p,q);
            else if(!strcmp(t->varname,"!="))
            	fprintf(target, "NE R%d, R%d\n",p,q);
            else if(!strcmp(t->varname,"=="))
            	fprintf(target, "EQ R%d, R%d\n",p,q);
            pos++;
            freereg();
            return p;
        }
		if(!strcmp(t->varname,"=")){
			int temp;
			p=codegen(t->right,target);
			addr=*(t->left->varname)-'a' + 4096;
			fprintf(target,"MOV [%d], R%d\n",addr,p);
			pos++;
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
	else if(t->nodetype == 5){
		int temp1,temp2;
		fprintf(target, "L%d:\n",r);
		temp1=r;
		a[temp1]=2*pos+2056;
		r++;
		p=codegen(t->left,target);
		fprintf(target, "JZ R%d, L%d\n",p,r); pos++;
		temp2=r;
		r++;
		freereg();
		ch=1;
		p=codegen(t->right,target);
		ch=0;
		fprintf(target, "JMP L%d\n",temp1); pos++;
		fprintf(target, "L%d:\n",temp2);
		a[temp2]=2*pos+2056;
	}
	else if(t->nodetype == 6){
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
			pos++;
			r++;
		}
		freereg();
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
			
		















