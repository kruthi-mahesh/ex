#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct n
{
	int info,bf;
	struct n *llink,*rlink;
};
typedef struct n *node;

int val;

node getnode()
{
	node x;
	x = (node)malloc(sizeof(struct n));
	if(x == NULL)
	{
		printf("\n Insufficient Memory. ");
		exit(0);
	}
	x->bf = 0;
	x->rlink = x->llink = NULL;
	return x;
}

node update(node t,node x)
{
	node temp;
	temp = t;
	while(temp != x)
	{
		if(x->info > temp->info)
		{
			temp->bf = -1;
			temp = temp->rlink;
		}
		else
		{
			temp->bf = +1;
			temp = temp->llink;
		}
	}
	return t;
}

node LLrotate(node A, node B)
{
	node temp;
	temp = B->rlink;	
	B->rlink = A;
	A->llink = temp;
	return B;
}

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;
	else
		return n2;
}

node RRrotate(node A, node B)
{
	node temp;
	temp = B->llink;
	B->llink = A;
	A->rlink = temp;
	return B;
}

node LRrotate(node A, node B, node C)
{
	node temp1,temp2;
	temp1 = C->llink;
	temp2 = C->rlink;
	C->llink = B;
	C->rlink = A;
	B->rlink = temp1;
	A->llink = temp2;
	return C;
}

node RLrotate(node A, node B, node C)
{
	node temp1,temp2;
	temp1 = C->llink;
	temp2 = C->rlink;
	C->llink = A;
	C->rlink = B;
	B->llink = temp2;
	A->rlink = temp1;
	return C;
}

int height(node A)
{
	node cn = A;
	int h=0,h1=0,h2=0;

	if(A == NULL)
		return 0;
	while(cn != NULL)
	{
		if(cn->llink == NULL)
			cn = cn->rlink;
		else
		{
			if(cn->rlink == NULL)
				cn = cn->llink;
			else
			{
				h1 = height(cn->llink);
				h2 = height(cn->rlink);
				if(h1 == h2)
					h = h1;
				else
					if(h1 > h2)
						h = h1;
					else
						h = h2;
				h++;
				break;
			}
		}
		h++;
	}
	return h;
}

node updatetree(node A)
{
	int left = 0, right = 0;

	left = height(A->llink);
	right = height(A->rlink);
	A->bf = left - right;
	if(A->llink != NULL)
	A->llink = updatetree(A->llink);
	if(A->rlink != NULL)
	A->rlink = updatetree(A->rlink);
	return A;
}

node insert(int num,node r)
{
	node cn,pn,A,B,pA,nn = getnode();
	nn->info = num;
	
	pn = A = pA = NULL;
	cn = r;
	if(r == NULL)
		return nn;

//regular insertion as in binary search tree
	while(cn!=NULL)
	{
		pn = cn;
		if(cn->bf == -1 || cn->bf == +1)
			A = cn;
		if(cn->info == num)
		{
			val--;
			return r;
		}
		if(nn->info < cn->info)
			cn = cn->llink;
		else
			cn = cn->rlink;
	}
	if(nn->info < pn->info)
		pn->llink = nn;
	else
		pn->rlink = nn;

//if tree is balanced, update bf for all nodes from root to nn
	if(A == NULL)
		r = update(r,nn);

	if(A != NULL)
	{
		if(A->bf == 1 && nn->info > A->info || A->bf == -1 && nn->info < A->info)
		{
			A->bf = 0;
			if(nn->info > A->info)
				A->rlink = update(A->rlink,nn);
			else
				A->llink = update(A->llink,nn);
		}
		else
		{
//tree is unbalanced => identify LL,RR,LR or RL imbalance and correct accordingly
			pA = A;
			if(nn->info < A->info)
			{
				B = A->llink;
				if(nn->info < B->info)
					A = LLrotate(A,B);
				else
					A = LRrotate(A,B,B->rlink);
			}
			else
			{
				B = A->rlink;
				if(nn->info < B->info)
					A = RLrotate(A,B,B->llink);
				else
					A = RRrotate(A,B);
			}
//update the rotated tree .. how?
			A = updatetree(A);

//check where A is located at and update from the root itself
			pn = NULL;
			cn = r;
			while(cn != pA)
			{
				pn = cn;
				if(cn->info > pA->info)
					cn = cn->llink;
				else
					cn = cn->rlink;
			}
			if(pn == NULL)
				r = A;
			else
			{
				if(pA->info < pn->info)
					pn->llink = A;
				else
					pn->rlink = A;
			}

		}
	}
	return r;
}

int verify(node r)
{
	int t1,t2,t;
	if(r == NULL)
		return 0;
	t1 = verify(r->llink);
	t2 = verify(r->rlink);
	if(t1 == -1 || t2 == -1)
		return -1;
	else
	{
		t1 = height(r->llink);
		t2 = height(r->rlink);
		if(abs(t2-t1) > 1)
			return -1;
		else
			return 1+max(t1,t2);
	}
}

void inorder(node r)
{
	if(r == NULL)
		return;
	inorder(r->llink);
	printf(" %d",r->info);
	inorder(r->rlink);
}

void randomvalues(node r)
{
	val = 0;
	int num;
	while(val < 1000)
	{
		num = random()%1000;
		printf("\n %d",num);
		r = insert(num,r);
		num = verify(r);
		if(num == -1)
		{
			printf("\n Tree is invalid. ");
			printf("\n This is the %d th iteration. ",val);
			exit(0);
		}	
		else
		printf("\n Tree is valid. ");	
		val++;
	}
}

void main()
{
	int choice,t;
	node r = NULL,r1 = NULL;
	while(1)
	{
		printf("\n 1) Insert an element \n 2) Display inorder form \n 3) Print root value \n 4) Verify AVL tree \n 5) Enter 1000 random values to new tree and verify \n 6) Exit \n Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : printf("\n Enter the element to insert : ");
				 scanf("%d",&t);
				 r = insert(t,r);
				 break;
			case 2 : printf("\n Inorder form is : ");
				 inorder(r);
				 break;
			case 3 : printf("\n The value of the root is : %d",r->info);
				 break;
			case 4 : t = verify(r);
				 if(t != 0)
					printf("\n Tree is invalid. ");
				 else
					printf("\n Tree is valid. ");
				 break;
			case 5 : randomvalues(r1);
				 break;					
			case 6 : exit(0);
			default : printf("\n Invalid Choice. ");
		}
		printf("\n");
	}
}
