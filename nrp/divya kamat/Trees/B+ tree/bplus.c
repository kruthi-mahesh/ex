#include<stdio.h>
#include<stdlib.h>
#define size 3

struct Node
{
	int info[size];
	struct Node *link[size],*next;
	int leaf, count;
};
typedef struct Node *node;

/*
leaf is flag variable to check whether or not the node is a leaf node or not. 
count is a variable to check how many values in a node are filled.
info is the array of data - used for insertion of values in the node.
next is a pointer to next leaf node -- this will be set in the split function
*/

node getnode()
{
	node x;
	int i;
	x = (node)malloc(sizeof(struct Node));
	if(x == NULL)
	{
		printf("\n Insufficient Memory. ");
		exit(0);
	}
	x->next = NULL;
	for(i = 0; i<size ; i++)
		x->link[i] = NULL;
	x->count = -1;
	x->leaf = -1;
	return x;
}

node insertinleaf(node lnode, int data)
{
//insert by order here
	int pos,i;
	if(lnode->count == 0)
	{
		lnode->info = data;
		return lnode;
	}
	for(i=1; i<=lnode->count; i++)
	{
		if(lnode->info[i] > data)
			pos = i;
	}
	for(i = lnode->count; i >= pos ; i--)
		lnode->info[i+1] = lnode->info[i];
	lnode->info[pos] = data;
	lnode->count++;
	return lnode;
}

node split(node ln,int data)
{
//stuck in this function	
}

node insert(node r)
{
	int data,checkflag = 0;
	printf("\n Enter the element to insert : ");
	scanf("%d",&data);
	node cn,pn,ln,nn = getnode();
	cn = r, pn = ln = NULL;

//if empty then return nn as leaf node
	if(r == NULL)
	{
		nn->leaf = 1;
		nn->count++;
		nn->info[0] = data;
		return nn;
	}
	else
	{
/* otherwise find the leaf node to insert -> 
To do this  : Traverse through each required node on the path and check it's leaf flag. If it is a leaf node and it's unfilled then add data to leaf 			node.
		Mark it as ln. The most recently visited ln will be used while splitting the leaf node if it is filled.  */
		while(cn != NULL)
		{
			pn = cn;
			if(cn->count < size)
			{
				ln = cn;
				if(cn->leaf == 1)
				{
					checkflag = 1;
					cn = insertinleaf(cn,data);
					return r;
				}
			}
			else
			{
				if(data < cn->info[0])
					cn = cn->link[0];
				else
					cn = cn->link[size-1];
			}
		}
/* If we have inserted in the leaf node , then the flag variable is set to 1. But while we traverse, if we haven't found any empty leaf node then it means that the previously found ln will have to be used for splitting */
		if(!checkflag)
		{
			ln = split(ln,data);
			return r;
		}
	}
}

void main()
{
	int choice;
	node root = NULL;
	while(1)
	{
		printf("\n 1) Insert an element \n 2) Display \n Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : root = insert(root);
				 break;
			case 2 : display(root);
				 break;
			default : exit(0);
		}
	}
}
