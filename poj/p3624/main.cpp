#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

int N, M;

int W[3403];
int D[3403];

int dp[2][12881];
// N 3402
// M 12881

void disp(){
    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    while( scanf("%d%d",&N,&M) != EOF ){
        memset(dp,0,sizeof(dp));
        for(int i=0 ; i<N; i ++){
            scanf("%d%d",&W[i+1],&D[i+1]);
        }
        int i = 1;
        for(int ii=1;ii<=N;ii++){
            //debug(ii)
            for(int j=0;j<=M;j++){
                if(j >= W[ii]){
                    dp[i][j] = max( dp[ (i+1)%2 ][j-W[ii]] + D[ii], dp[(i+1)%2][j] );
                }else{
                    dp[i][j] = dp[(i+1)%2][j];
                }
            }
            //for(int j=0;j<=M;j++){
            //    cout<<dp[i][j]<<" ";
            //}
            //cout<<endl;
            i++;
            i %= 2;
        }
        //disp();
        cout<<dp[(i+1)%2][M]<<endl;
    }
    return 0;
}
