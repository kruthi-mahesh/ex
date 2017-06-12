#include<stdio.h>
#include<stdlib.h>

void main()
{
	int n,m,i,j;
	printf("\n ENter the number of rows and columns : ");
	scanf("%d%d", &m,&n);
	int A[m][n];

	printf("\n Enter the elements in order : ");
	for(i=0; i<m ; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("\n ENter %d,%d element : ",i,j);
			scanf("%d",&A[i][j]);
		}
	}

//	int flag =1;

	i=j=0;
	while(i!=m/2 && j!= n/2)
	{
		for(j; j<m-j; j++)
		{
			if(flag == 1)
				printf("%d",A[i][j]);
			else
				printf("%d",A[i][n-j-1]);
		}
		j--;
		i++;
		for(i; i<n-i; i++)
		{
			if(flag== 1)
				printf("%d",A[i][j]);
			else
				printf("%d",A[i][n-j-1]);
		}
		i--;
		j++;
		flag *= -1;
	}
}
