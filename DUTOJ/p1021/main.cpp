#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstring>
using namespace std;
int n,m;
int grap[1001][1001];
bool DFS(int c,int d)
{
    bool flag = false;
    if(grap[c][d]==1)return true;
    else{
        for(int i=0;i<n;i++){
            if(grap[c][i]==1 && i!=c){
                flag = DFS(i,d);
                if(flag)
                    return flag;
            }
        }
       return flag;
    }
}
int main()
{

    int x,y;
    while(scanf("%d",&n)!= EOF){
        scanf("%d",&m);
        memset(grap,0,sizeof(grap));

        for(int i=0;i<m;i++)
        {
            scanf("%d",&x);
            scanf("%d",&y);
            grap[x-1][y-1] = 1;
        }
        scanf("%d",&x);
        scanf("%d",&y);
        if(DFS(x-1,y-1))
            printf("first\n");
        else if(DFS(y-1,x-1))
            printf("second\n");
        else
            printf("unknown\n");

    }
    return 0;

}
