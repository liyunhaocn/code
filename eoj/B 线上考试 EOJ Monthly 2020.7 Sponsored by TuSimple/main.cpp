#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>

using namespace std;

#define debug(x) cout<<#x<<(x)<<endl;
int mat[20][20];

int combinat(int m, int n) {
    int i, j;

    if(n == 0 || m == n)
        return 1;

    for(j = 0; j <= n; j++) { // 只要计算n列就行了，不用计算后面的
        mat[j][j] = 1;
        for(i = j+1; i <= m; i++) {
            if(j == 0)
                mat[i][j] = 1;
            else
                mat[i][j] = mat[i-1][j-1] + mat[i-1][j];
        } // 计算Cmn
    }
    for(int i=1;i<=10;i++){
        mat[i][i] = 1 ;
    }
    return mat[m][n];
}

int main() {
    // insert code here...

    combinat(10,9);
    int n;
    scanf("%d",&n);
    int ret=-1;


    for(int nn=0;nn<n;nn++){
        char c;
        int cnt;
        //scanf("%c",&c);
        //scanf("%d",&cnt);
        cin>>c;
        cin>>cnt;
        int r=0;
        if(c=='S'){
            ret = max(ret,cnt);
        }else{
            for(int j=1;j<=cnt;j++){
                r += mat[cnt][j];
            }
            ret = max(ret,r);
        }
    }
    printf("%d\n",ret);
    return 0;
}


