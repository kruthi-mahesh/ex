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
	x->llink = x->rlink = NULL;
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

void inorderc(node r,int *i,int in[])
{
	if(r == NULL)
		return;
	inorderc(r->llink,i,in);
	printf(" %d",r->info);
	in[(*i)++] = r->info;
	inorderc(r->rlink,i,in);
}

void preorderc(node r,int *i,int pre[])
{
	if(r == NULL)
		return;
	printf(" %d",r->info);
	pre[(*i)++] = r->info;
	preorderc(r->llink,i,pre);
	preorderc(r->rlink,i,pre);
}

void inorder(node r)
{
	if(r == NULL)
		return;
	inorder(r->llink);
	printf(" %d",r->info);
//	in[(*i)++] = r->info;
	inorder(r->rlink);
}

void preorder(node r)
{
	if(r == NULL)
		return;
	printf(" %d",r->info);
	preorder(r->llink);
	preorder(r->rlink);
}

node recreate(int in[],int pre[], int *index, int start, int end)
{
	int search,i;
	node nn = getnode();
	if(start > end )
		return NULL;

	nn->info = pre[(*index)++];
	if(start == end)
		return nn;
	for(i = 0; i<10; i++)
	{
		if(in[i] == pre[(*index)-1])
		{
			search = i;
			break;
		}
	}
	if(search == 0)
		nn->llink = NULL;
	else
		nn->llink = recreate(in,pre,index,start,search-1);
	if(search+1 > end)
		nn->rlink = NULL;
	else
		nn->rlink = recreate(in,pre,index,search+1,end);
	return nn;
}

void main()
{
	node r = NULL,r1 = NULL;
	int k,i=0,num,j=0,index=0;
	printf("\n Enter the number of elements : ");
	scanf("%d",&k);
	int in[k],pre[k],tree[k];
	
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
	inorderc(r,&i,in);
	printf("\n\n Preorder traversal : ");
	preorderc(r,&j,pre);
	i = j = 0;
	r1 = recreate(in,pre,&index,0,k-1);	
	printf("\n\n For created tree : \n\n Inorder traversal : ");
	inorder(r1);
	printf("\n\n Preorder traversal : ");
	preorder(r1);
	printf("\n\n");	

}
