#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int a[101][101];
int dp[101][101];
/*
int maxW(int x,int y){
    if(x==0 && y==0){
        return a[0][0];
    }else if( y==0){
        return a[x][0]+ maxW(x-1,0);
    }else if( x==0){
        return a[0][y]+ maxW(0,y-1);
    }else{
        return a[x][y]+max(maxW(x-1,y),maxW(x,y-1));
    }
}
*/
int maxW(int n){
    dp[0][0] = a[0][0];
    for(int i=1;i<n;i++ ){
        dp[0][i] = dp[0][i-1]+ a[0][i];
        dp[i][0] = dp[i-1][0]+ a[i][0];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = a[i][j]+max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n-1][n-1];
}


int main()
{
    int n;
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("%d\n",maxW(n));

    return 0;
}
