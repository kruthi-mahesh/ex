#include<stdio.h>
#include<stdlib.h>
#define size 10
#define maximum 5

struct n
{
	int data[10];
	struct n *link[10],*next;
	int leaf,count,maxsize;
};
typedef struct n *node;
node root = NULL;

node getnode(int max)
{
	node x;
	int i;
	x = (node)malloc(sizeof(struct n));
	if(x == NULL)
	{
		printf("\n Insufficient Memory. ");
		exit(0);
	}
	for(i=0; i<maximum; i++)
	{
		x->data[i] = 0;
		x->link[i] = NULL;
	}
	x->leaf = x->count = 0;
	x->next = NULL;
	x->maxsize = max;
	return x;
}

// Returns leaf node where element has to be inserted
node find(int value)
{
	node c=root;
	int i;
	while(!c->leaf)
	{
		i=0;
		while(i<c->count)
		{
			if(c->data[i]>value)
				break;
			i++;
		}
		c=c->link[i];
	} 	 	
	return c;
}


node insertinleaf(node lnode, int value)
{
//insert by order here
	int pos=0,i;
	lnode->leaf = 1;
	if(lnode->count == 0)
		lnode->data[0] = value;
	else
	{
		for(i=0; i<lnode->count; i++)
		{
			if(lnode->data[i] < value)
				pos = i+1;
		}
		for(i = (lnode->count-1) ; i >= pos  ; i--)
			lnode->data[i+1] = lnode->data[i];
		lnode->data[pos] = value;
	}
	lnode->count++;
	return lnode;
}

node insertinparent(node leafNode, int value, node newLeaf)
{
	if(leafNode == root)
	{
		node R = getnode(maximum);
		R->data[0] = value;
		R->link[0] = leafNode;
		R->link[1] = newLeaf;
		R->count++;
		root = R;
		return root;
	}
	else
	{
		node curNode,parentNode,prevNode;
		curNode = root;
		prevNode = parentNode = NULL;
		int pos,i,val,k;
		//finding parentNode
		while(curNode != NULL)
		{
			parentNode = prevNode;
			prevNode = curNode;
			for(i=0 ; i<curNode->count; i++)
			{
				if(curNode->data[i] < value)
					pos = i;
			}
			curNode = curNode->link[pos];
		}
		//if parentNode is not full 
		if(parentNode->count < parentNode->maxsize)
		{
			parentNode->data[parentNode->count++] = value;
			parentNode->link[parentNode->count] = newLeaf;
			return parentNode;
		}
		else
		{
		//if parentNode is full
			node T;
			T = getnode(parentNode->maxsize + 1);

			//copying P to T
			for(i=0; i<parentNode->maxsize; i++)
			{
				T->data[i] = parentNode->data[i];
				T->link[i] = parentNode->link[i];
			}
			T->next = parentNode->next;
			T->count = parentNode->count;
			T->leaf = parentNode->leaf;

			//copying value and newLeaf to T
			T->data[i] = value;
			T->link[i] = newLeaf;

			//erasing entries of parentNode
			for(i=0; i<parentNode->maxsize ; i++)
			{
				parentNode->data[i] = 0;
				parentNode->link[i] = NULL;
			}

			node newParent = getnode(maximum);

			//splitting T into parentNode and newParent
			for(i=0; i <= T->maxsize/2 ; i++)
			{
				parentNode->data[i] = T->data[i];
				parentNode->link[i] = T->link[i];
			}
			val = T->data[T->maxsize/2];
			for(i=T->maxsize/2,k=0 ; i<= T->maxsize ; i++,k++)
			{
				newParent->data[k] = T->data[i];
				newParent->link[k] = T->link[i];
			}
			insertinparent(parentNode,val,newParent);
		}
	}
}

void insert(int value)
{		
	if(root == NULL)
	{
		node newNode = getnode(maximum);
		newNode = insertinleaf(newNode,value);
		root = newNode;
		//.. return was here
	}
	else
	{
		node leafNode = getnode(maximum);
		leafNode = find(value);

		//if leafNode has less than 'size' values (not completely filled)
		if(leafNode->count < leafNode->maxsize) 
		{
			leafNode = insertinleaf(leafNode,value);
			//.. return was here
		}
		else
		{
		//if leafNode is full
			node newLeaf = getnode(maximum);	//L' node
			node T = getnode(maximum+1);
			int least,i,k;

			//copying values
			for(i=0 ; i<leafNode->maxsize; i++)
			{
				T->data[i] = leafNode->data[i];
				T->link[i] = leafNode->link[i];
			}
			T->next = leafNode->next;
			T->count = leafNode->count;
			T->leaf = leafNode->leaf;

			T = insertinleaf(T,value);
			newLeaf->next = leafNode->next;
			leafNode->next = newLeaf;
			newLeaf->leaf = 1;

			//erasing entries of leafNode
			for(i=0; i<leafNode->maxsize ; i++)
			{
				leafNode->data[i] = 0;
				leafNode->link[i] = NULL;
			}
			leafNode->count = 0;

			//splitting the node T
			for(i=0; i<T->maxsize/2 ; i++)
			{
				leafNode->data[i] = T->data[i];
				leafNode->link[i] = T->link[i];
				leafNode->count++;
			}
			for(i=T->maxsize/2,k=0 ; i<T->maxsize ; i++,k++)
			{
				newLeaf->data[k] = T->data[i];
				newLeaf->link[k] = T->link[i];
				newLeaf->count++;
			}
			least = newLeaf->data[0];
			insertinparent(leafNode,least,newLeaf);
		}
	}
}

void display()
{
;
}

void main()
{
	int choice,value;
	FILE *pipe;
	while(1)
	{
		printf("\n 1) Insert Elements \n 2) Display \n 3) Exit \n Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : printf("\n Enter value to insert : ");
				 scanf("%d",&value);
				 insert(value);
				 break;
			case 2 : display();
				 break;
			case 3 : exit(0);
			default : printf("\n Invalid Choice. ");
		}
	}
}
