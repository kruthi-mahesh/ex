#include<stdio.h>
#include<stdlib.h>

struct n
{
	int info;
	struct n *llink,*rlink;
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
	x->rlink = x->llink = NULL;
	return x;
}

node createtree(node r,int n)
{
	node nn,cn,pn;
	nn = getnode();
	nn->info = n;

	if(r == NULL)
		return nn;
	pn = NULL;
	cn = r;

	while(cn!=NULL)
	{
		pn = cn;
		if(nn->info > cn->info)
			cn = cn->llink;
		else
			cn = cn->rlink;
	}
	if(nn->info > pn->info)
		pn->llink = nn;
	else
		pn->rlink = nn;

	return r;
}

void inorder(node r,int *i,int in[])
{
	if(r == NULL)
		return;
	inorder(r->llink,i,in);
	printf(" %d",r->info);
	in[(*i)++] = r->info;
	inorder(r->rlink,i,in);
}

void preorder(node r,int *i,int pre[])
{
	if(r == NULL)
		return;
	printf(" %d",r->info);
	pre[(*i)++] = r->info;
	preorder(r->llink,i,pre);
	preorder(r->rlink,i,pre);
}

/*
node fixtree(int in[], int pre[],int *index,int start, int end)
{
	node nn = getnode();
	int search,i;	
	if(start > end)
		return NULL;
	nn->info = pre[*(index)];
	*index = *index + 1;
	if(start == end)
		return nn;
	
	for(i = 0; i<=end; i++)
	{
		if(in[i] == pre[*(index)-1])
		{
			search = i;
			break;
		}
	}

	nn->rlink = fixtree(in,pre,index,start,search-1);
	nn->llink = fixtree(in,pre,index,search+1,end);
	return nn;
}
*/
	
void fixtree(node r)
{
	if(r == NULL)
		return;
	node cn;
	cn = r->llink;
	r->llink= r->rlink;
	r->rlink = cn;
	fixtree(r->llink);
	fixtree(r->rlink);
}

void main()
{
	node r = NULL;
	int k,i=0,num,index = 0;
	printf("\n Enter the number of elements : ");
	scanf("%d",&k);
	int in[k],pre[k];
	
	while(i<k)
	{
		num = random()%80;
		r = createtree(r,num);
		printf("\n %d node : %d value added. ",i,num);
		i++;
	}
	i=0;

	printf("\n Tree created. ");
	printf("\n\n Inorder traversal : ");
	inorder(r,&i,in);
	i=0;
	printf("\n\n Preorder traversal : ");
	preorder(r,&i,pre);
	i=0;
	fixtree(r);
	printf("\n\n Inorder traversal : ");
	inorder(r,&i,in);
	i = 0;
	printf("\n\n Preorder traversal : ");
	preorder(r,&i,pre);
	printf("\n\n");	
}
