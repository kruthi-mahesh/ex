#include<stdio.h>
#include<stdlib.h>

int A[10][10];
void displayspiral(int,int,int);

void main()
{
	int n,i,j,count=0;
	printf("\n ENter the number of rows and columns : ");
	scanf("%d",&n);

	printf("\n Enter the elements in order : ");
	for(i=0; i<n ; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("\n ENter %d,%d element : ",i,j);
			scanf("%d",&A[i][j]);
		}
	}

	for(i=0 ; i<n; i++)
	{
		for(j=0 ; j<n; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}		

	displayspiral(n,0,0);
	printf("\n\n");
}

void displayspiral(int n,int i,int j)
{
	if(n==0)
		return;

	for(j; j<n; j++)
		printf("%d ",A[i][j]);
	i++;
	j--;
	for(i; i<n; i++)
		printf("%d ",A[i][j]);
	i--;
	j--;
	for(j = 0; j<n-2; j--)
		printf("%d ",A[i][n-2-j]);
	i--;
	j++;
	for(i = 0; i<n-2; i--)
		printf("%d ",A[n-i-2][j]);
	i++;
	j++;

	displayspiral(n-1,i,j);
}

/*	printf("%d ",A[i][j]);
	printf("\n\n");
}*/
