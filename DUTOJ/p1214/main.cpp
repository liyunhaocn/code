#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstring>
using namespace std;
int n,m;
int grap[1001][1001];
//int cost[1001][1001];


int len[1001];      //d[i]��ʾԴ�㵽i�����ľ���
int visit[1001];  //�ڵ��Ƿ񱻷���

int dijkstra(int from, int to){ //��Դ�㵽Ŀ���

    int i;

    for(i = 1 ; i <= n ; i ++){  //��ʼ��
        visit[i] = 0;   //һ��ʼÿ���㶼û������
        len[i] = grap[from][i];  //�ȼ���Դ�㵽������ľ���
    }

    int j;
    for(i = 1 ; i < n ; ++i){    //�Գ�Դ���ÿһ���������̼���
        int min = 0x3f3f3f3f;  //��¼��Сlen[i]
        int pos;  //��¼Сlen[i] �ĵ�

        for(j = 1 ; j <= n ; ++j){
            if(!visit[j] && min > len[j]){
                pos = j;
                min = len[j];
            }
        }
        visit[pos] = 1;

        for(j = 1 ; j <= n ; ++j){
            if(!visit[j] && (len[j] > (len[pos] +grap[pos][j]))){ //���j�ڵ�û�б����ʹ�&&j�ڵ㵽Դ�ڵ�����·��>pos�ڵ㵽Դ�ڵ�����·��+pos�ڵ㵽j�ڵ��·��
                len[j] = len[pos] + grap[pos][j];    //����j�ڵ㵽Դ�ڵ�����·��
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
