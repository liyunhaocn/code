
/*
#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

int a[101][101];
int N;
int ret = INT_MIN;

void disp(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{

    while(cin>>N){
        for(int i=0;i<N*N;i++){
            scanf("%d",&a[i/N][i%N]);
        }
        ret = INT_MIN;
        for(int i=1;i<N;i++){
            a[i][0] = a[i-1][0] + a[i][0];
            a[0][i] = a[0][i-1] + a[0][i];
        }
        for(int i=1;i<N;i++){
            for(int j=1;j<N;j++){
                a[i][j] = a[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
                ret = max(ret,a[i][j]);
                //debug(i)
                //debug(j)
                for(int ii=0;ii<i;ii++){
                    ret = max(ret, a[i][j] -a[ii][j]);
                }
                for(int jj=0;j<j;jj++){
                    ret = max(ret, a[i][j] -a[i][jj]);
                }
                for(int ii=0;ii<=i;ii++){
                    for(int jj=0;jj<=j;jj++){
                        //debug(ii)
                        //debug(jj)
                        ret = max(ret, a[i][j] + a[ii][jj] - a[i][jj] - a[ii][j]);
                        //debug(a[i][j] + a[ii][jj] - a[i][jj] - a[ii][j])
                    }
                }
            }
        }
        //disp();
        cout<<ret<<endl;
    }
    return 0;
}
*/

#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <string.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

int a[101][101];
int N;
int ret = INT_MIN;
int dp[101];

void disp(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    while(cin>>N){
        ret = INT_MIN;
        //memset(a,0,sizeof(a));
        for(int i=0;i<N*N;i++){
            scanf("%d",&a[i/N][i%N]);
        }

        for(int i=0;i<N;i++){
            memset(dp,0,sizeof(dp));
            for(int j=i;j<N;j++){
                for( int k=0;k<N;k++ ){
                    dp[k] += a[ j ][k];
                }
                int temp = 0;
                for( int k=0;k<N;k++ ){
                    temp += dp[k];
                    ret = max(ret,temp);
                    if( temp < 0 ){
                        temp = 0;
                    }

                }
            }
        }
        cout<<ret<<endl;
    }

}
