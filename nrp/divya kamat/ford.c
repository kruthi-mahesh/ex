//header files
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//number of vertices
int size;

struct n
{
	int data; //vertex
	struct n *next;//pointer to the next node
};
typedef struct n *node;

//return node
node getnode()
{
	node x;
	x = (node)malloc(sizeof(struct n));
	if(x == NULL)
	{
		printf("\n Insufficient Memory. ");
		exit(0);
	}
	x->data = 0;
	x->next = NULL;
	return x;
}

//insert to queue (at rear)
node enqueue(node front, int item)
{
	if(front==NULL)
	{
		node newnode = getnode();
		newnode->data = item;
		return newnode;
	}
	else
	{
		node newnode = getnode();
		newnode->data = item;
		node temp = front;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
		return front;
	}
}

//delete front from queue
node dequeue(node *front)
{
	if(*front == NULL)
	{
		printf("\n Queue Empty. ");
		return *front;
	}
	node temp = *front;
	*front = (*front)->next;
	return temp;
}

//if queue is empty
int isempty(node front)
{
	if(front == NULL)
		return 1;
	else
		return 0;
}

int BFS(int graph[][size], int source, int sink, int path[])
{
	node front = NULL, u;
	int visited[size], i;
	//initially mark put visited= 0 and path = -1
	for(i=0; i<size; i++)
	{
		visited[i] = 0;
		path[i] = -1;
	}

	//insert source vertex
	front = enqueue(front, source);
	visited[source] = 1;

	//continue till queue has a node
	while(!isempty(front))
	{
		u = dequeue(&front);//dequeue front and visit all the adjacent nodes
		for(i=0; i<size; i++)
		{
			if(visited[i]==0 && graph[u->data][i]!=0)//if each node adjacent is not visited , add to queue
			{
				front = enqueue(front, i);
				path[i] = u->data;
				visited[i] = 1;
			}
		}
	}
	if(visited[sink] == 1)
		return 1;
	else
		return 0;

}

int ffalgorithm(int graph[][size], int vertices[], int source, int sink)
{
	int flow[size][size], rgraph[size][size], i, j, stop = 0, b, u, v, sum = 0;

	printf("\n Graph is :  \n ");
	for(i=0; i<size ; i++)
	{
		for(j=0; j<size ; j++)
		{
			printf(" %d", graph[i][j]);
			flow[i][j] = 0;
			rgraph[i][j] = graph[i][j];
		}
		printf("\n ");
	}
	int path[size], c=1;


	while(BFS(rgraph, source, sink, path))
	{

		printf("\n The path variable is : ");
		for(i=0; i<size; i++)
			printf("\n index %d : %d ", i, path[i]);


	//bottleneck capacity 'b' is computed
		b = INT_MAX;
		for(v=sink; v!=source ; v=path[v])
		{
			u = path[v];
			if( rgraph[u][v] < b)
				b = rgraph[u][v];
		}

		for(v=sink; v!=source ; v=path[v])
		{
			u = path[v];
			flow[u][v] += b; //increment flow by bottleneck capacity of forward edge
			flow[v][u] -= b; //decrement bottleneck capacity of reverse edge
			rgraph[u][v] -= b; //decrement residual capacity of forward edge
			rgraph[v][u] += b; //increment residual capacity of backward edge
		}

		sum += b; //increment maximum flow
	}
	printf("\n\n Flow Matrix  :  \n");
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
			printf(" %d ", flow[i][j]);
		printf("\n");
	}

	printf("\n\n Residual Matrix  :  \n");
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
			printf(" %d ", rgraph[i][j]);
		printf("\n");
	}

	return sum;
}


void main()
{
	int source, sink;
	printf("\n Enter the number of vertices : ");
	scanf("%d", &size);

	int graph[size][size], vertices[size], i, j, max_flow;
	printf("\n Enter the vertices : ");
	for(i=0; i<size ; i++)
	{
		printf("\n Vertex %d : ", i);
		scanf("%d", &vertices[i]);
	}

	source = sink = 0;
	while(source == sink)
	{
		printf("\n Enter the source vertex : ");
		scanf("%d", &source);
		printf("\n Enter the sink vertex : ");
		scanf("%d", &sink);
	}
	
	printf("\n Enter -1 if no direct path between the two vertices . ");
	for(i=0; i<size ; i++)
	{
		for(j=0; j<size ; j++)
		{
			if(i==j)
				graph[i][j] = 0;
			else
			{
				printf("\n Enter c(%d,%d) : ", vertices[i], vertices[j]);
				scanf("%d", &graph[i][j]);
			}
		}
	}

	max_flow = ffalgorithm(graph, vertices, source, sink);
	printf("\n Maximum flow of the algorithm is : %d \n", max_flow);
}
