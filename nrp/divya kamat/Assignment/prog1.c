#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i,j,n,spaces = 40, sp,k;
	printf("\n Enter the number of rows : ");
	scanf("%d", &n);
	
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=i; j++)
			printf("%d ",j);
		printf("\n");
	}

	for(i=1; i<=n; i++)
	{
		k=i-1;
		for(sp=1 ; sp<= spaces; sp++)
			printf(" ");
	
		for(j=1; j<= 2*i-1; j++)
			if(j<=i)
				printf("%d ",j);
			else
				printf("%d ",k--);
		spaces-=2;
		printf("\n");

	}

	printf("\n\n");
	if(n%2 == 0)
	printf("\n Diamond not possible");
	else
	{
		spaces = 40;
		for(i=1; i<= n/2 + 1; i++)
		{
			k = i-1;
			for(sp=1; sp<=spaces; sp++)
				printf(" ");
			for(j=1; j<= 2*i-1; j++)
				if(j<=i)
					printf("%d ",j);
				else
					printf("%d ",k--);
			spaces-=2;
			printf("\n");
		}
		spaces+=4;
		for(i=n/2; i>=1; i--)
		{
			k = i-1;
			for(sp=1; sp<=spaces; sp++)
				printf(" ");
			for(j=1; j<=2*i-1; j++)
				if(j<=i)
					printf("%d ",j);
				else
					printf("%d ",k--);
			spaces+=2;
			printf("\n");
		}
	}
}
