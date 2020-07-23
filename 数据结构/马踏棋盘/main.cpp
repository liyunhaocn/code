#include<stdio.h>
#define n 8
#define m 8
int movex[8]= {-2,-1,1,2,2,1,-1,-2};
int movey[8]= {1,2,2,1,-1,-2,-2,-1};
int qp[n][m];
typedef struct
{
	int x;
	int y;
}pos;
typedef struct
{
	pos a[n*m];
	int top;
}stack;
void initstack(stack&s)
{
	s.top=-1;
}
void push(stack&s,pos e)
{
	s.a[++s.top]=e;
}
int pop(stack&s,pos&e)
{
	if(s.top==-1)return 0;
	e=s.a[s.top--];
	return 1;
}
int waynum(int x,int y) {
	int x1,y1,t=0;
	for (int i=0; i<8; i++)
	{
		x1=x+movex[i];
	    y1=y+movey[i];
		if (x1>=0&&x1<n&&y1>=0&&y1<m&&qp[x1][y1]==0)
		{
			t++;
		}
	}
	return t ;
}
void findway(stack &s)
{
	pos p;
	int x,y,x1,y1,min,minx,miny,i;
	int num[8];
	min=9;
	x=s.a[s.top].x;
	y=s.a[s.top].y;

	for (i=0; i<8; i++)
	{
		x1=x+movex[i];
        y1=y+movey[i];
		if (x1>=0&&x1<n&&y1>=0&&y1<m&&qp[x1][y1]==0)
		{
			num[i]=waynum(x1,y1);
			if (num[i]<min)
			{
				min=num[i];
				minx = x+movex[i];
				miny = y+movey[i];
			}
		}
	}
	if(min==9)
	{
		pop(s,p);
		qp[p.x][p.y]=0;
	}
	else
	{
		p.x=minx;
		p.y=miny;
		push(s,p);
		qp[minx][miny]=s.top+1;
	}

	if(s.top<n*m-1)findway(s);
}
void print()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%-4d",qp[i][j]);
		}
		printf("\n");
	}
}
main()
{
	pos first;
	stack s;
	printf("ÊäÈë³õÊ¼Î»ÖÃ\n");
	scanf("%d%d",&first.x,&first.y);
	initstack(s);
	push(s,first);
	qp[first.x][first.y]=1;
	findway(s);
	print();

}
