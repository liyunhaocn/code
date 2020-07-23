#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstring>
using namespace std;
int n,m;
int grap[1001][1001];
//int cost[1001][1001];


int len[1001];      //d[i]表示源点到i这个点的距离
int visit[1001];  //节点是否被访问

int dijkstra(int from, int to){ //从源点到目标点

    int i;

    for(i = 1 ; i <= n ; i ++){  //初始化
        visit[i] = 0;   //一开始每个点都没被访问
        len[i] = grap[from][i];  //先假设源点到其他点的距离
    }

    int j;
    for(i = 1 ; i < n ; ++i){    //对除源点的每一个点进行最短计算
        int min = 0x3f3f3f3f;  //记录最小len[i]
        int pos;  //记录小len[i] 的点

        for(j = 1 ; j <= n ; ++j){
            if(!visit[j] && min > len[j]){
                pos = j;
                min = len[j];
            }
        }
        visit[pos] = 1;

        for(j = 1 ; j <= n ; ++j){
            if(!visit[j] && (len[j] > (len[pos] +grap[pos][j]))){ //如果j节点没有被访问过&&j节点到源节点的最短路径>pos节点到源节点的最短路径+pos节点到j节点的路径
                len[j] = len[pos] + grap[pos][j];    //更新j节点到源节点的最短路径
            }
        }
    }

    return len[to];
}

void Floyd(int n){
    for(int v=1;v<=n;v++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(grap[i][j]>grap[i][v]+grap[v][j]){
                    grap[i][j] = grap[i][v]+grap[v][j];
                }
            }
        }
    }
}
int main()
{

    int x,y,q;
    scanf("%d",&n);
    scanf("%d",&m);
    memset(grap,0x3F3F3F3F,sizeof(grap));
    for(int i=0;i<=n;i++){
        grap[i][i]=0;
    }

    for(int i=0;i<m;i++)
    {
        scanf("%d",&x);
        scanf("%d",&y);
        grap[x][y] = 0;
        grap[y][x] = 1;
    }
    //Floyd(n);
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&x);
        scanf("%d",&y);
        printf("%d\n",dijkstra(x,y));
    }


    return 0;

}
