#include<bits/stdc++.h>
using namespace std;

struct node{
	int x,y;
}point[105];

int main()
{
	int m;
	while(~scanf("%d",&m))
	{
		int maxX=-1,maxY=-1;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&point[i].x,&point[i].y);
			maxX=max(maxX,point[i].x);
			maxY=max(maxY,point[i].y);
		}
		int h0=(maxX+maxY)*(maxX+maxY)/maxX;
		int ans=1<<20;
		for(int h=maxY+1;h<=h0;h++)
		{
			int maxWid=0;
			for(int i=0;i<m;i++)
				maxWid=max((int)ceil(1.0*point[i].x*h/(h-point[i].y)),maxWid);
			ans=min(ans,maxWid*h);
		}
		printf("%.1lf\n",ans/2.0);
	}
	return 0;
}
