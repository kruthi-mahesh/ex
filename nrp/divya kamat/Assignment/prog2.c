#include<stdio.h>
#include<stdlib.h>

void main()
{
	int n,i,j,count=0;
	printf("\n ENter the number of rows and columns : ");
	scanf("%d",&n);
	int A[n][n];

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
//	int flag =1;

	i=j=0;
	while(i!=n/2 || j!= n/2)
	{
		for(j=count; j<n-count; j++)
			printf("%d ",A[i][j]);
		i++;
		j--;
		for(i; i<n-count; i++)
			printf("%d ",A[i][j]);
		i--;
		j--;
		for(j; j>count-1; j--)
			printf("%d ",A[i][j]);
		i--;
		j++;
		for(i; i>count; i--)
			printf("%d ",A[i][j]);
		i++;
		j++;
		count++;
	}
	printf("%d ",A[i][j]);
	printf("\n\n");
}
