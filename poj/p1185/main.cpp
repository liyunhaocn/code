
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <string>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

char tempG[11];
int bitG[101];
int cntSol[101];
int sol[70];
int maxSol = 0;
int dp[101][70];
int chuan1[60][60];
int chuan2[60][60];
int **c_2_1;
int N,M;


int cnt1(int a){
    int ret = 0;
    while( a>0 ){
        ret++;
        a&=(a-1);
    }
    return ret;
}

void disp(){

    for(int i=0;i<N;i++){
        for(int j=0;j<maxSol;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

int findw(){
    int ret = 0;
    for(int i = 0; i<(1<<M);i++){
        if( i&(i<<1) || i&(i<<2) ){
            continue;
        }
        sol[maxSol] = i;
        cntSol[maxSol] = cnt1(i);
        maxSol++;
    }

    if( N>0 ){

        for(int i=0;i<maxSol;i++){

            if( bitG[0]&sol[i] )continue;

            dp[0][i] = cntSol[i];
            ret = max(ret,dp[0][i]);
        }
    }

    if(N>1){
        for(int i=0;i<maxSol;i++){
            for(int j=0;j<maxSol;j++){
                if( bitG[0]&sol[j] )continue;
                if( bitG[1]&sol[i] ) continue;
                if( sol[i]&sol[j] ) continue;
                dp[1][i] = max(dp[1][i], dp[0][j] + cntSol[i]);
                ret = max(ret,dp[1][i]);
            }
        }
    }

    for(int r = 2; r < N; r ++){



        for(int i=0;i<maxSol;i++){

            for(int ii=0;ii<maxSol;ii++){
                //dp[r-1][ii] = 0;
                //dp[r-2][ii] = 0;
            }

            if(bitG[r]&sol[i])continue;



            for(int j = 0;j < maxSol;j ++){

                if(bitG[r-1]&sol[j])continue;
                if(sol[i]&sol[j])continue;



                for(int k = 0;k < maxSol;k ++){

                    if(bitG[r-2]&sol[k])continue;

                    if(sol[i]&sol[k])continue;
                    if(sol[k]&sol[j])continue;

                    //dp[r][i]= max (dp[r][i], dp[r-1][j]+dp[r-2][k]) + cntSol[i];

                    //dp[r][i] = max(dp[r][i], dp[r-2][k] + cntSol[j]+ cntSol[i]);

                    dp[r-1][j] = max(dp[r-1][j],dp[r-2][k] + cntSol[j]);

                    dp[r][i] = max(dp[r][i], dp[r-1][j] + cntSol[i]);

                    ret = max(ret,dp[r][i]);

                }



            }
        }
    }
    //disp();
    return ret;
}


int main()
{

    while(scanf("%d%d",&N,&M) != EOF){
        //scanf("%d%d",&N,&M);
        memset(bitG,0,sizeof(bitG));
        memset(dp,0,sizeof(dp));
        memset(cntSol,0,sizeof(cntSol));
        maxSol = 0;

        for(int i=0;i<N;i++){
            scanf("%s",tempG);
            for(int j=0;j<M;j++){
                if( tempG[j]=='H' ){
                    bitG[i] += (1<<j);
                }
            }
        }

        int ret = findw();
        //disp();

        printf("%d\n",ret);
    }
    return 0;
}

/*
5 4
HHHH
HHHH
HHHH
HHHH
HHHH

5 4
PHHH
HHHP
HHHH
PHHH
HHHP

5 4
PPPP
PPPP
PPPP
PPPP
PPPP

5 4
PHPP
PPHH
PPPP
PHPP
PHHP

1 4
PPPP

0 0

1 10
PPPPPPPPPP

3 10
PPPPPPPPPP
PPPPPPPPPP
PPPPPPPPPP

8 10
PPPPPPPPPP
PPPPPPPPPP
PPPPPPPPPP
PPPPPPPPPP
PPPPPPPPPP
PPPPPPPPPP
PPPPPPPPPP
PPPPPPPPPP

*/

