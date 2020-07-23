
#include<iostream>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int Max = 1e5+5;
int dp_max[Max][33];
int dp_min[Max][33];
int main( )
{
    //freopen("input.txt","r",stdin);
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &dp_max[i][0]);
        dp_min[i][0] = dp_max[i][0];
    }
    //初始化（注意按照列优先的规则进行初始化）,复杂度O(nlogn)
    int k = (int)log2(n);
    for(int j=1; j<=k; j++)
        for(int i=1; i<=n; i++)
            if(i+(1<<(j-1)) <= n)//注意i+2^(j-1)可能大于n
            {
                dp_max[i][j] = max(dp_max[i][j-1], dp_max[i+(1<<(j-1))][j-1]);
                dp_min[i][j] = min(dp_min[i][j-1], dp_min[i+(1<<(j-1))][j-1]);
            }
    int m;
    scanf("%d", &m);
    while(m--)
    {
        int a,b;
        scanf("%d%d", &a,&b);
        //通过稀疏表进行查询任意区间的最值，复杂度O(1)
        int length = (int)log2(b-a+1);
        int high = max(dp_max[a][length], dp_max[b-(1<<length)+1][length]);
        int low = min(dp_min[a][length], dp_min[b-(1<<length)+1][length]);
        if(high-low == b-a)
            printf("YES\n");
        else
            printf("NO\n");
    }
   return 0;
}

