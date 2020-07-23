
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
main()
{
	struct Poi{
		int x,y;
	}a[1000];
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
		}
		//int flag=0;
		double max=40000.0;
		for(int i=1;i<201;i++)
		 for(int j=1;j<201;j++){
		  int flag=0;
		  for(int k=0;k<n;k++)
		  {
  		 	if(j*a[k].y>a[k].x*i*-1+i*j)
  		 	{
	 		  	flag=1;
	 		  	break;
	 		  }
  		  }
  		  if(!flag)
  		  {
 		  	max=min(max,i*j/2.0);
  		  }
  		 }
  		  printf("%.1f\n",max);
	}
}
