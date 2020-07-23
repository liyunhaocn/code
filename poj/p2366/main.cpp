#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdlib>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int n,m,vis[1000000]={0},t,ff=0;

int main()
{

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        vis[t+40000]=1;
    }
    scanf("%d",&m);
    for(int j=0;j<m;j++)
    {
        scanf("%d",&t);
        if(vis[50000-t])
            ff=1;
    }
    if(ff)
        puts("YES");
    else
        puts("NO");
}
