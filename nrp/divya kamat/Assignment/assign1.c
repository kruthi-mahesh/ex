#include<stdio.h>
#include<stdlib.h>

void main()
{
	int n,i=1;
	while(i!=100)
	{
		n = 1200 + random()%100;
		i++;
		printf("%d\n\n",n);
	}	

}
