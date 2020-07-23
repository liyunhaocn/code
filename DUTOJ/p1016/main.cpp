#include<iostream>
#include<cstring>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;
#define N 100+5
int dx[]={1,0};
int dy[]={0,1};
int n;
int arr[N][N];
int MAX[N][N];
int vis[N][N];
int bfs(){
    pair<int,int>p;
    p.first=1,p.second=1;
    vis[1][1]=1;
    MAX[1][1]=arr[1][1];
    queue<pair<int,int> >q;
    q.push(p);
    while(!q.empty()){
        pair<int,int>t;
        t=q.front();q.pop();vis[t.first][t.second]=0;
        for(int i=0;i<2;i++){
            int x=dx[i]+t.first;
            int y=dy[i]+t.second;
            if(x<=n&&y<=n){
                if(!vis[x][y]){
                    vis[x][y]=1;
                    pair<int,int > s;
                    s.first=x,s.second=y;
                    q.push(s);
               }
                MAX[x][y]=max(MAX[x][y],MAX[t.first][t.second]+arr[x][y]);
            }
        }
    }
    return MAX[n][n];
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        scanf("%d",&arr[i][j]);
    cout<<bfs()<<endl;
}
