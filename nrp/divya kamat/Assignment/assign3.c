#include<stdio.h>
#include<stdlib.h>

struct n
{
	int info;
	struct n *link;
};
typedef struct n *node;

node getnode()
{
	node x;
	x = (node)malloc(sizeof(struct n));
	if(x == NULL)
	{
		printf("\n Insufficient Memory. ");
		exit(0);
	}
	x->link = NULL;
	return x;
}

node insertrear(node f)
{
	node nn,tn;
	nn = getnode();
	printf("\n Enter the element to enter : ");
	scanf("%d",&nn->info);
	if(f == NULL)
		return nn;
	tn = f;
	while(tn->link != NULL)
		tn = tn->link;
	tn->link = nn;
	return f;
}

node deletefront(node f)
{
	node tn;
	if(f == NULL)
	{
		printf("\n List Empty. ");
		free(tn);
		return NULL;
	}
	tn = f;
	f = f->link;
	free(tn);
	return f;
}

node reverse(node f)
{
	if(f == NULL)
	{
		printf("\n List Empty. ");
		return NULL;
	}
	node cn, ln = NULL;
	cn = f;
	while(f!=NULL)
	{
		cn = f;
		f = f->link;
		cn->link = ln;
		ln = cn;
	}
	return ln;
}

void display(node f)
{
	if(f == NULL)
	{
		printf("\n List Empty. ");
		return;
	}
	node tn;
	tn = f;
	printf("\n The elements are : ");
	while(tn!=NULL)
	{
		printf(" %d ",tn->info);
		tn = tn->link;
	}
	printf("\n");
}

void main()
{
	node f = NULL;
	int choice;
	while(1)
	{
		printf("\n 1) Insert an element \n 2) Delete an element \n 3) Reverse the list \n 4) Display \n 5) Exit \n Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : f = insertrear(f); break;
			case 2 : f = deletefront(f); break;
			case 3 : f = reverse(f); break;
			case 4 : display(f); break;
			case 5 : exit(0);
			default : printf("\n Invalid choice. ");
		}
	}
}
