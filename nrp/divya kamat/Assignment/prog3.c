#include<stdio.h>
#include<stdlib.h>
int spaces = 40;
void pr1(int n)
{
	int i;
	if(n==0)
		return;
	pr1(n-1);
	for(i=1; i<=n; i++)
		printf("%d ",i);
	printf("\n");
}

void pr2(int n)
{
	int i,k,sp;
	if(n==0)
		return;
	pr2(n-1);
	k = n-1;
	for(sp = 1; sp<= spaces; sp++)
		printf(" ");
	spaces-=2;
	for(i=1; i<=2*n-1; i++)
		if(i<=n)
			printf("%d ",i);
		else
			printf("%d ",k--);
	printf("\n");

}

void pr3(int n)
{
	int i,k,sp;
	if(n==0)
		return;
	k = n-2;
	for(sp = 1; sp<= spaces; sp++)
		printf(" ");
	spaces+=2;
	for(i=1; i<=2*n-3; i++)
		if(i<=n-1)
			printf("%d ",i);
		else
			printf("%d ",k--);
	printf("\n");
	pr3(n-1);	

}

void main()
{
	int n;
	printf("\n ENter the max number to be printed : ");
	scanf("%d",&n);
	pr1(n);
	pr2(n);
	spaces=40;
	printf("\n\n");
	if(n%2 == 0)
		printf("\n Diamond can't be printed. \n");
	else
	{
		pr2(n);
		spaces+=4;
		pr3(n);
	}
}
