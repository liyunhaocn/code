#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <cstdio>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

int n,m,r;

int p1[201];
int p2[201];
vector<int> danp[201];

bool visit[401];

bool dp[201][201];

int pcnt = 0;
int xi=0;
int yi=0;

void dfs(int a){
    //debug(n)
    visit[a] = 1;
    if( a<=m ){
        p1[pcnt] ++;
    }else{
        p2[pcnt] ++;
    }
    vector<int>&v = danp[a];
    for(int i=0;i < v.size();i++){
        if( visit[ v[i] ] == 0 ){
            dfs(v[i]);
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int nn = 0;nn < n; nn ++){
        scanf("%d%d",&m,&r);

        for(int i=0;i<= m*2;i++){
            danp[i].clear();
        }

        memset(visit,0,sizeof(visit));
        memset(p1,0,sizeof(p1));
        memset(p2,0,sizeof(p2));
        memset(dp,0,sizeof(dp));



        pcnt = 0;
        //debug(000)

        for(int rr=0;rr<r;rr++){

            scanf("%d%d",&xi,&yi);
            danp[xi].push_back(m+yi);
            danp[m+yi].push_back(xi);
        }

        //debug(111)

        for(int i=1;i <= 2*m;i ++){
            if( visit[i] == 0 ){
                dfs(i);
                pcnt++;

            }
        }

        int ret = 0;
        dp[0][0] = 1;
        for(int i = 0;i < pcnt;i++){
            for(int j = m/2;j >=p1[i] ;j--){
                for(int k = m/2;k >= p2[i];k--){
                    if( dp[ j-p1[i] ] [ k-p2[i] ] == 1 ){
                        dp[j][k] = 1;
                    }
                }
            }
        }
        for(int i = m/2;i >=0;i--){
            if( dp[i][i] == 1 ){
                ret = i;
                break;
            }
        }

        cout<<ret<<endl;
    }
    return 0;
}

