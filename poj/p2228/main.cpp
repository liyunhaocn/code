#include <iostream>
#include <stdio.h>
#include <string.h>
#include <limits.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

int N,B;
int a[3831];
int dp[2][3031][2];

void disp(){
    for(int i=0;i<=N;i++){
        for(int j=0;j<=B;j++){
            cout<<dp[i][j][0]<<" ";
            cout<<dp[i][j][1]<<" ";
            cout<<" ";
        }
        cout<<endl;
    }

}
int main()
{

    while( scanf("%d%d",&N,&B)!=EOF ){
        memset(dp,0x80,sizeof(dp));
        int ret = -1;
        for(int i=1;i <= N;i++){
            scanf("%d",&a[i]);
        }
        dp[1][0][1] = 0;
        dp[1][1][0] = 0;

        for( int i = 2;i <= N;i ++ ){
            for(int j = 0;j <= B;j ++){
                dp[i&1][j][1] = max(dp[(i+1)&1][j][0],dp[(i+1)&1][j][1]);
                if(j){
                    dp[i&1][j][0] = max(dp[(i+1)&1][j-1][0] + a[i],dp[(i+1)&1][j-1][1]);
                }
            }
        }

        //debug(111)
        ret = max(dp[N&1][B][0],dp[N&1][B][1]);


        memset(dp,0x80,sizeof(dp));
        dp[1][1][0] = a[1];
        for(int i=2;i<=N;i++){
            for(int j=0;j<=B;j++){
                dp[i&1][j][1] = max(dp[(i+1)&1][j][0],dp[(i+1)&1][j][1]);
                if(j){
                    dp[i&1][j][0] = max(dp[(i+1)&1][j-1][0]+a[i],dp[(i+1)&1][j-1][1]);
                }
            }
        }
        //disp();
        //ret = max(ret,dp[N&1][B][1]);
        ret = max(ret,dp[N&1][B][0]);

        cout<<ret<<endl;
    }
    return 0;
}
