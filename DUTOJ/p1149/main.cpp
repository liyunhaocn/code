#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[500000][15];
char a[500000];


int main()
{
    int T;

    scanf("%d",&T);
    char b[15]="coderenxinxian";

    for(int i = 0; i < 500000; ++i){
        dp[i][0] = i;
    }

    for(int i = 0; i <= 14 ; ++i){
        dp[0][i] = i;
    }

    while(T--){
        scanf("%s",a);
        int alen = strlen(a);

        for(int i=1;i <= alen;i++){
            for(int j=1;j<= 14;j++){
                if(a[i-1]== b[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min( min(dp[i - 1][j - 1] + 2, dp[i][j - 1] + 1), dp[i - 1][j] + 1);
                }
            }
        }

        printf("%d\n",dp[alen][14]);
    }
    return 0;
}
