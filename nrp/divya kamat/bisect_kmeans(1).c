#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define num 4
#define csize 30

struct l
{
	int cluster[csize], size;
	struct l *next;
};
typedef struct l *node;

node getnode()
{
	node x;
	x = (node)malloc(sizeof(struct l));
	if(x == NULL)
	{
		printf("\n Insufficient Memory. ");
		exit(0);
	}
	int i;
	for(i=0; i<csize ; i++)
		x->cluster[i] = 0;
	return x;
}

//generates csize distinct values
void generate(int arr[])
{
	int i, j, n;
	for(i=0; i<csize ; i++)
	{
		generate : 
		n = random()%100;
		for(j = 0; j<csize; j++)
			if(n == arr[j])
				goto generate;
		arr[i] = n;
	}
		
}

node insert(node head, int arr[], int s)
{
	node newnode = getnode();
	node temp;
	int i, j;
//copy array elements to newnode
	for(i=0; i<s; i++)
		newnode->cluster[i] = arr[i];
	newnode->size = s;
	head->cluster[0]++;
//if list empty
	if(head->next == NULL)
	{
		head->next = newnode;
		return head;
	}
	else
	{
//insert rear
		temp = head->next;
		while(temp->next != NULL)
			temp = temp->next;
		
		temp->next = newnode;
		newnode->next = NULL;
		return head;
	}
}

node delete(node *head, int count)
{
//using double pointer to keep list updated 
	if((*head)->cluster[0] == 0)
	{
		printf("\n List Empty. ");
		exit(0);
	}
	else
	{
		(*head)->cluster[0]--;
		node prev, temp;
		temp = (*head)->next;
		prev = *head;
//node to be deleted is found by skipping 'count' nodes from beginning of list
		while(count != 0 && temp!=NULL)
		{
			prev = temp;
			temp = temp->next;
			count--;
		}
		prev->next = temp->next;
		return temp;
	}
}

//computes centroid of the cluster
int centroid(int arr[], int size)
{
	int i, sum=0;
	if(size == 0)
		return 0;
	for(i=0; i<size; i++)
		sum = sum + arr[i];
	i = sum/size;
	return i;
}

//used to display each cluster
void display(int arr[], int size)
{
	int i;
	for(i=0; i<size; i++)
		printf(" %d", arr[i]);
	printf("\n");
}

//main function
void main()
{
	int arr[csize], c=0, s, i, j, count, clus1[csize], clus2[csize], index1, index2;
	int k1, k2, c1, c2;
	generate(arr); //generate 'csize' random values

	node temp, head;
	head = getnode();
	head->cluster[0] = 0;

	head = insert(head, arr, csize);
	temp = head->next;
	count = 0;

	do
	{
		c = 0;
		i = 0;
		temp = head->next;
	//dequeue cluster with largest size
		while(temp!=NULL)
		{
			s = temp->size;
			if(s > c)
			{
				c = s;
				count = i;
			}
			i++;
			temp = temp->next;
		}
		temp = delete(&head, count);

	//perform basic k-means clustering
		index1 = index2 = 0;
		c1 = c2 = 0;

	//initial centroid values
		while(c1 == c2)
		{
			c1 = random()%100;
			c2 = random()%100;
		}

	//basic	k-means clustering
		do
		{
			index1 = index2 = 0;
			k1 = c1;
			k2 = c2;
			for(i=0; i<temp->size; i++)
			{
				if(abs(temp->cluster[i]-c1) < abs(temp->cluster[i]- c2))
					clus1[index1++] = temp->cluster[i];
				else
					clus2[index2++] = temp->cluster[i];
			}
			c1 = centroid(clus1, index1);
			c2 = centroid(clus2, index2);
		}while(k1!=c1 || k2!=c2);

		head = insert(head, clus1, index1);
		head = insert(head, clus2, index2);
	}while(head->cluster[0] < num);

//display
	printf("\n\n Original cluster : ");
	display(arr, csize);

	temp = head->next;
	i = 1;
	while(temp!= NULL)
	{
		printf("\n Cluster : %d \n", i);
		display(temp->cluster, temp->size);
		i++;
		temp = temp->next;
	}
}


