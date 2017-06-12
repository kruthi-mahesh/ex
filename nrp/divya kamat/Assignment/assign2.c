#include<stdio.h>
#include<stdlib.h>
#define size 20
struct n
{
	int info;
	struct n *llink,*rlink;
};
typedef struct n *node;

struct st
{
	node items[size];
	int top;
};
typedef struct st stack;


void push(stack *s, node nn)
{
	if(s->top == size-1)
	{
		printf("\n Stack Overflow. ");
		return;
	}
	s->items[++s->top] = nn;	
}

node pop(stack *s)
{
	if(s->top == -1)
	{
		printf("\n Stack Underflow ");
		return NULL;
	}
	node tn;
	tn = s->items[s->top--];
	return tn;
}

node getnode()
{
	node x;
	x = (node)malloc(sizeof(struct n));
	if(x == NULL)
	{
		printf("\n Insufficient Memory. ");
		exit(0);
	}
	x->llink = x->rlink = NULL;
	return x;
}

node createtree(node r)
{
	node nn,cn,pn;
	nn = getnode();
	printf("\n Enter the element you want to insert : ");
	scanf("%d",&nn->info);

	if(r == NULL)
		return nn;
	pn = NULL;
	cn = r;

	while(cn!=NULL)
	{
		pn = cn;
		if(nn->info < cn->info)
			cn = cn->llink;
		else
			cn = cn->rlink;
	}
	if(nn->info < pn->info)
		pn->llink = nn;
	else
		pn->rlink = nn;

	return r;
}

void preorder(node r)
{
	if(r == NULL)
		return;
	printf("%d ",r->info);
	preorder(r->llink);
	preorder(r->rlink);
}

void inorder(node r,stack *s)
{
	if(r == NULL)
		return;
	inorder(r->llink,s);
	push(s,r);
	inorder(r->rlink,s);
}	

int sumoftwo(node r, int k)
{
	node cn,tn,pn;
	int t;
	stack s;
	s.top = -1;
	if(r == NULL)
	{
		printf("\n Tree doesn't exist. ");
		exit(0);
	}
	pn = NULL;
	cn = r;

	inorder(r,&s);		

	while(s.top != -1)
	{
		pn = pop(&s);
		t = s.top;
		while(t>=0)
		{
			cn = s.items[t];
			if(cn->info + pn->info == k)
			{
				printf("\n The elements are : %d and %d. \n",pn->info,cn->info);
				return 1;
			}
			t--;
		}
	}
	return 0;
}

void main()
{
	node r = NULL;
	int choice,k,t;

	while(1)
	{
		printf("\n 1) Insert element \n 2) Find the pair with sum K \n 3) Preorder display \n 4) Exit \n Enter your choice : ");
		scanf("%d",&choice); 
		switch(choice)
		{
			case 1 : r = createtree(r);
				 break;
			case 2 : printf("\n Enter the value of K : ");
				 scanf("%d",&k);
				 t = sumoftwo(r,k);
				 if(t)
				 	printf("\n Pair exists and shown above. ");
				 else
				 	printf("\n Pair doesn't exist. ");
				 break;
			case 3 : printf("\n Elements are : ");
				 preorder(r);
				 break;
			case 4 : printf("\n");
				 exit(0);
			default : printf("\n Invalid Choice. ");
		}
	}
}
