#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void generate(int arr[])
{
	int i,n;
	for(i=0; i<100; i++)
		arr[i] = 35 + random()%15;
}

void print(int csize[], int height[])
{
	int i=0;
	printf("\n\t CHEST SIZE \t HEIGHT ");
	printf("\n\t ---------- \t ------ ");
	for(i=0 ; i<100; i++)
		printf("\n \t %d \t\t %d ",csize[i],height[i]);
}

int centroid(int arr[],int i)
{
	int p,sum = 0;
	for(p = 0 ; p<i; p++)
		sum += arr[p];
	p = sum/i;
	return p;
}

void k_means(int a[],int size[])
{
	int i,c1,c2,c3,k1,k2,k3,cluster1[100],cluster2[100],cluster3[100],j,k,l;
	generate : 
		c1 = 35 + random()%15;
		c2 = 35 + random()%15;
		c3 = 35 + random()%15;
		
		if(c1 == c2 || c2 == c3 || c1 == c3)
			goto generate;
	
	do
	{
		j = k = l = 0;
		k1 = c1; k2 = c2; k3 = c3;
//		printf("\n Chosen centroids : %d %d %d \n",k1,k2,k3);
		for(i=0; i<100; i++)
		{
			if(abs(a[i]-c1) < abs(a[i]-c2))
			{
				if(abs(a[i]-c1) < abs(a[i]-c3))
					cluster1[j++] = a[i];
				else
					cluster3[l++] = a[i];
			}
			else
			{
				if(abs(a[i]-c2) < abs(a[i]-c3))
					cluster2[k++] = a[i];
				else
					cluster3[l++] = a[i];
			}
		}
		c1 = centroid(cluster1,j);
		c2 = centroid(cluster2,k);
		c3 = centroid(cluster3,l);
	}while(k1!=c1 || k2!=c2 || k3!=c3);
	size[0] = k1;
	size[1] = k2;
	size[2] = k3;
}		

void main()
{
	int csize[100],height[100],finalcsize[3],finalheight[3],i;
	generate(csize);
	generate(height);
	print(csize,height);
	k_means(csize,finalcsize);
	k_means(height,finalheight);

	printf("\n The final chosen sizes are : \n \t CHEST SIZE \t HEIGHT \n \t ---------- \t ------ \n");
	for(i=0; i<3; i++)
		printf("\n \t %d \t\t %d ",finalcsize[i],finalheight[i]);
	printf("\n");
}
