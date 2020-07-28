int k=-1,r=0,a[1000],ch=0,idaddr=4096,temp1[100],temp2[100];int whilenum=0;
struct Gsymbol *root=NULL;
int pos=1;        
                                                       //BRKP
void newid(char *nam, int type, int size){
	struct Gsymbol *temp1;
    temp1 = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    temp1->name = malloc(sizeof(char));
    strcpy(temp1->name,nam);
    temp1->type=type;
    temp1->size=size;
    temp1->binding=idaddr;
    temp1->next=NULL;
    idaddr+=size;
    if(root==NULL)
    	root=temp1;
    else{
    	struct Gsymbol *p;
    	p=root;
    	while(p->next!=NULL)
    		p=p->next;
    	p->next=temp1;
    }
}

struct Gsymbol *Lookup(char *name){
	struct Gsymbol *p;
	p=root;
	while(p->next!=NULL){
    	if(!strcmp(p->name,name))
    		break;
    	p=p->next;  
    }	
    if(!strcmp(p->name,name))
    	return p;
    else
    	return NULL;
}         

int checkvar(char *var){
	struct Gsymbol *p;
	p=root;
	int f=-1;
	while(p->next!=NULL){
    	if(!strcmp(p->name,var)){
    		f=1;
    		break;
    	}
    	p=p->next;  
    }
    if(!strcmp(p->name,var))
    	f=1;
    if(f==-1)
    	return 0;
    else
    	return 1;
}

void display(){
	struct Gsymbol *p;
	p=root;
	while(p->next!=NULL){
    	printf("%s-\n",p->name);
    	p=p->next;  
    }
    printf("%s-",p->name);
}

struct tnode* makeleaf(char c,int nt)
{
	struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    temp->type = 0;
    temp->val = 0;
	*(temp->varname) = c;
	temp->Gentry=NULL;
	temp->nodetype = nt;
    temp->left = NULL;
    temp->mid = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeleafnum(int n,char *text,int type)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->text = malloc(sizeof(char));
    if(text==NULL)
    	temp->text = NULL;                            //Type:
    else											  //2: Integer
    	strcpy(temp->text,text);					  //3: String
    temp->type = type;
    temp->val = n;
	temp->varname = NULL;
	temp->nodetype = 0;
	temp->Gentry=NULL;
    temp->left = NULL;
    temp->mid = NULL;
    temp->right = NULL;
    return temp;
}
struct tnode* makearraynode(char* var,int nt,struct tnode *l){
	struct tnode *temp;                            
    temp = (struct tnode*)malloc(sizeof(struct tnode));   
	temp->varname = malloc(sizeof(char));
	if(!checkvar(var)){
		printf("Variable not declared\n");
		exit(1);
	}
	if(l->type==booltype){
		printf("Type mismatch boolean-integer/string-integer\n");
		exit(1);
	}
	temp->Gentry=Lookup(var);
    if(temp->Gentry==NULL){
		printf("Variable Lookup error\n");
		exit(1);
	} 
	strcpy(temp->varname,var);
	temp->nodetype=9;
	temp->left=l;
	temp->mid = NULL;
    temp->right = NULL;
}

struct tnode* makeleafvar(char* var,int narg, int type, char* vararg)
{
    struct tnode *temp;                                        //Typearg:
    temp = (struct tnode*)malloc(sizeof(struct tnode));        //10: variable
	temp->varname = malloc(sizeof(char));                      //20: array with integer arg
	temp->arg = malloc(sizeof(char));						   //30: array with variable arg
    temp->type = type;                   //type;                 
    temp->val = narg;                    // For arrays
    if(vararg==NULL)
    	temp->arg=NULL;
    else
    	strcpy(temp->arg,vararg);
    temp->Gentry=Lookup(var);
    if(temp->Gentry==NULL){
		printf("Variable Lookup error\n");
		exit(1);
	} 
	strcpy(temp->varname,var);
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
			printf("Type mismatch boolean-integer/string-integer\n");
			exit(1);
		}
	}
	if(nt==5 || nt==6){
		if(l->type==inttype){
			printf("Type mismatch boolean/integer\n");
			exit(1);
		}
	}
    strcpy(temp->varname,c);
    temp->Gentry=NULL;
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
		if(t->left==NULL || t->right==NULL){
			printf("Connector children NULL ERROR\n");
			exit(0);
		}
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
			fprintf(target, "JMP L%d\n",temp2[whilenum]);
		else if(*(t->varname)=='c')
			fprintf(target, "JMP L%d\n",temp1[whilenum]);
		pos++;
		return -1;
	}
	else if(t->nodetype == 0){
		if(t->varname == NULL){
			if(t->text ==NULL){
				p=getreg();
				fprintf(target,"MOV R%d, %d\n",p,t->val);
				pos++;
				return p;
			}
			else{
				p=getreg();
				fprintf(target,"MOV R%d, %s\n",p,t->text);
				pos++;
				return p;
			}
		}
		else{
			//addr=*(t->varname)-'a' + 4096;
			addr=t->Gentry->binding;
			if(t->val!=-1){
				addr+=t->val;
			}
			if(t->type==30){
				printf("WRONG\n");
				exit(1);
				struct Gsymbol *p1;
				p1=Lookup(t->arg);
				int p2=getreg();
				p=getreg();
				q=getreg();
				fprintf(target,"MOV R%d, [%d]\n",q,p1->binding);
				fprintf(target,"MOV R%d, %d\n",p,addr);
				fprintf(target,"ADD R%d, R%d\n",p,q);
				fprintf(target,"MOV R%d, [R%d]\n",p2,p);
				pos+=4;
				freereg();
				freereg();
				return p2;
			}
			else{
				p=getreg();
				fprintf(target,"MOV R%d, [%d]\n",p,addr);
				pos++;
				return p;
			}
		}
	}		
	else if(t->nodetype == 1){
		p=getreg();
		q=getreg();
		//addr=*(t->left->varname)-'a' + 4096;
		addr=t->left->Gentry->binding;
		if(t->left->val!=-1){
			addr+=t->left->val;
		}
		if(t->left->nodetype==9){
			freereg();
			q=codegen(t->left->left,target);
			fprintf(target,"MOV R%d, %d\n",p,addr);
			fprintf(target,"ADD R%d, R%d\n",p,q);
			pos+=2;
		}
		else{
    		fprintf(target, "MOV R%d, %d\n", p, addr);
    		pos+=1;
    	}
    	fprintf(target, "MOV SP, %d\n", idaddr);
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
		pos+=14;
		freereg();
		freereg();
		return -1;
	}
	else if(t->nodetype == 2){
		if(t->left->nodetype != 0)
			p=codegen(t->left,target);
		else{
			p=getreg();
			if(t->left->varname == NULL){
				if(t->left->text ==NULL){
					fprintf(target,"MOV R%d, %d\n",p,t->left->val);
					pos++;
				}
				else{
					fprintf(target,"MOV R%d, %s\n",p,t->left->text);
					pos++;
				}
			}
			else{
				//addr=*(t->left->varname)-'a' + 4096;
				addr=t->left->Gentry->binding;
				if(t->left->val!=-1){
					addr+=t->left->val;
				}
				if(t->left->nodetype==9){
					int p2=getreg();
					q=codegen(t->left->left,target);
					fprintf(target,"MOV R%d, %d\n",p2,addr);
					fprintf(target,"ADD R%d, R%d\n",p2,q);
					fprintf(target,"MOV R%d, [R%d]\n",p,p2);
					freereg();
					freereg();
					pos+=3;
				}
				else{
					fprintf(target,"MOV R%d, [%d]\n",p,addr);
					pos++;
				}
			}
		}
		q=getreg();
		fprintf(target, "MOV SP, %d\n", idaddr);
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
			int temp,type;
			type=t->left->Gentry->type;
			if(t->right->nodetype==0){
				if(t->right->varname==NULL){
					//printf("%d: %d  %d\n",t->right->nodetype,type,t->right->type);
					if(t->right->type!=type){
						printf("Integer/String Type mismatch\n");
						exit(1);
					}
				}
				else{
					//printf("%d: %d  %d\n",t->right->nodetype,type,t->right->Gentry->type);
					if(t->right->Gentry->type!=type){
						printf("Integer/String Type mismatch\n");
						exit(1);
					}
				}
			}
			else{
				if(t->right->type==3){
					printf("Integer/String Type mismatch\n");
					exit(1);
				}
			}
			p=codegen(t->right,target);
			//addr=*(t->left->varname)-'a' + 4096;
			addr=t->left->Gentry->binding;
			if(t->left->val!=-1){
				addr+=t->left->val;
			}
			if(t->left->nodetype==9){
				int p2=getreg();
				q=codegen(t->left->left,target);
				fprintf(target,"MOV R%d, %d\n",p2,addr);
				fprintf(target,"ADD R%d, R%d\n",p2,q);
				fprintf(target,"MOV [R%d], R%d\n",p2,p);
				freereg();
				freereg();
				pos+=3;
			}
			else{
				fprintf(target,"MOV [%d], R%d\n",addr,p);
				pos++;
			}
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
			else if(!strcmp(t->varname,"%")){
				int tm=getreg();
				fprintf(target, "MOV R%d, R%d\n", tm, p);
				fprintf(target, "DIV R%d, R%d\n", p, q);
				fprintf(target, "MUL R%d, R%d\n", q, p);
				fprintf(target, "MOV R%d, R%d\n", p, tm);
				fprintf(target, "SUB R%d, R%d\n", p, q);
				freereg();
				pos+=5;
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
		int t1,t2;
		whilenum++;
		fprintf(target, "L%d:\n",r);
		temp1[whilenum]=r;
		t1=r;
		a[t1]=2*pos+2056;
		r++;
		p=codegen(t->left,target);
		fprintf(target, "JZ R%d, L%d\n",p,r); pos++;
		temp2[whilenum]=r;
		t2=r;
		r++;
		freereg();
		ch=1;
		p=codegen(t->right,target);
		if(whilenum==1)
			ch=0;
		fprintf(target, "JMP L%d\n",t1); pos++;
		fprintf(target, "L%d:\n",t2);
		a[t2]=2*pos+2056;
		whilenum--;
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
			r++;
		}
		freereg();
	}	
	else if(t->nodetype == 9){
		printf("entered\n");
		addr=t->Gentry->binding;
		q=codegen(t->left,target);
		p=getreg();
		fprintf(target,"MOV R%d, %d\n",p,addr);
		fprintf(target,"ADD R%d, R%d\n",p,q);
		fprintf(target,"MOV R%d, [R%d]\n",q,p);
		pos+=3;
		freereg();
		return q;
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
			
		















