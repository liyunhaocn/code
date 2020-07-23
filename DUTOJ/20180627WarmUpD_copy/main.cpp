#include <iostream>
#include <string.h>
using namespace std;
char a[1001][1001];
bool isVisited[1001][1001];
bool DFS(int x,int y,int N){
    if(isVisited[x][y])
        return false;
    isVisited[x][y]=true;
    if(x<0||y<0||x==N||y==N)
        return false;
    else if(a[x][y]=='H')
        return true;
    else if(a[x][y]=='x')
        return false;
    else return DFS(x-1,y,N)+DFS(x,y-1,N)+DFS(x+1,y,N)+DFS(x,y+1,N);
}
int main()
{
    int T;
    ios::sync_with_stdio(false);
    cin>>T;
    int x,y;
    while(T--){
        memset(isVisited,0,sizeof(isVisited));
        int N;
        cin>>N;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>a[i][j];
                if(a[i][j]=='M'){
                    x=i;y=j;
                }
            }
        }
        if(DFS(x,y,N))
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;
    }
}
