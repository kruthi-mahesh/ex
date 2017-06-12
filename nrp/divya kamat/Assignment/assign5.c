#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void generate(int arr[])
{
	int i;
	for(i = 0; i<10 ; i++)
		arr[i] = random()%100;
}

void calculatedistance(int x[], int y[], int dis[][10])
{
	int i,j;
	for(i=0; i<10; i++)
	{
		for(j = i+1; j<10; j++)
		{
			dis[i][j] = sqrt(pow(x[i]-x[j],2) + pow(y[i]-y[j],2));
			printf("\n The distance between (%d,%d) and (%d,%d) is %d. ",x[i],y[i],x[j],y[j],dis[i][j]);
		}
	}
}

void min_max(int dis[][10],int x[],int y[])
{
	int large,small,i,j,ps1,ps2,pl1,pl2;
	large = small = dis[0][1];
	for(i = 0; i<10; i++)
	{
		for(j = i+1; j<10 ; j++)
		{
			if(dis[i][j]<small)
			{
				small = dis[i][j];
				ps1 = i;
				ps2 = j;
			}
			if(dis[i][j]>large)
			{
				large = dis[i][j];
				pl1 = i;
				pl2 = j;
			}
		}
	}
	printf("\n The least distance is %d. The nearest points are : (%d,%d) and (%d,%d). ",small,x[ps1],y[ps1],x[ps2],y[ps2]);
	printf("\n The biggest distance is %d. The farthest points are : (%d,%d) and (%d,%d). \n",large,x[pl1],y[pl1],x[pl2],y[pl2]);
}

void centroid(int x[],int y[])
{
	int i, xsum,ysum;
	xsum = ysum = 0;
	for(i=0; i<10; i++)
	{
		xsum += x[i];
		ysum += y[i];
	}
	printf("\n The centroid of these 10 points is : (%d,%d) \n",xsum/10,ysum/10);
}

void main()
{
	int x[10],y[10],dis[10][10],i;
	generate(x);
	generate(y);
	printf("\n The points are : ");
	for(i=0; i<10; i++)
		printf(" (%d,%d)",x[i],y[i]);
	printf("\n");
	calculatedistance(x,y,dis);
	min_max(dis,x,y);
	centroid(x,y);
}
