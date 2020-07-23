/*

��ÿ����(i,j)���ĸ�����ȥ��
���ĳһ������(a,b)����ֵ�ȵ�ǰλ��С
�����(a,b)������룬֮���1����
���صĵݹ��ظ�����˺ܶ������⣬����ÿ�����һ��������Ľ⣬�㽫�����д洢�������Ϳ��Դ�����ʱ�䡣


#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int a[101][101];
int dp[101][101];
int R,C;

int findw(int i,int j){
    int ret = 1;
    if( i>=0 && i<R && j>=0 && j<C ){
        if( dp[i][j]>0 ){
            //ֱ�ӵ���������Ľ�
            return dp[i][j];
        }
        if( i+1 < R && a[i][j] > a[i+1][j]){
            ret = max(ret,1+findw( i+1,j ) );
        }
        if( i-1 >=0 && a[i][j] > a[i-1][j]){
            ret = max(ret,1+findw( i-1,j ) );
        }
        if( j+1 < C && a[i][j] > a[i][j+1]){
            ret = max(ret,1+findw( i,j+1 ) );
        }
        if( j-1 >= 0 && a[i][j] > a[i][j-1]){
            ret = max(ret,1+ findw( i,j-1 ) );
        }
    }
    //��¼������Ľ�
    dp[i][j] = ret;
    return ret;
}
int main()
{
    while(scanf("%d%d",&R,&C)!=EOF){
        memset(dp,0,sizeof(dp));
        int ret = -1;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                ret = max(ret, findw(i,j));
            }
        }
        cout<<ret<<endl;
    }
    return 0;
}
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

int a[101][101];
int dp[101][101];
int du[101][101];
int R,C;

struct point{
    int x;
    int y;
    point():x(0),y(0){}
    point(int x,int y):x(x),y(y){}
};

int solve(){
    int ret = 0;
    queue<point> qu;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){

            if( i+1 < R && a[i][j] > a[i+1][j]){
                du[i][j]++;
            }
            if( i-1 >=0 && a[i][j] > a[i-1][j]){
                du[i][j]++;
            }
            if( j+1 < C && a[i][j] > a[i][j+1]){
                du[i][j]++;
            }
            if( j-1 >= 0 && a[i][j] > a[i][j-1]){
                du[i][j]++;
            }
            if( du[i][j] ==0 ){
                qu.push( point(i,j) );
            }
        }
    }
    /*
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
          cout<<du[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    while( !qu.empty() ){
        //debug(qu.size())
        point p = qu.front();
        qu.pop();
        int i = p.x;
        int j = p.y;
        //debug(a[i][j])
        if( i+1 < R && a[i][j] < a[i+1][j]){
            dp[i+1][j] = max(dp[i+1][j] ,1 + dp[i][j]) ;
            ret = max(ret,dp[i+1][j]);

            du[i+1][j]--;
            if(du[i+1][j]==0){
                qu.push(point(i+1,j));
            }
        }



        if( i-1 >=0 && a[i][j] < a[i-1][j]){
            dp[i-1][j] = max(dp[i-1][j] ,1 + dp[i][j]) ;
            ret = max(ret,dp[i-1][j]);
            du[i-1][j]--;
            if(du[i-1][j]==0){
                qu.push(point(i-1,j));
            }
        }


        if( j+1 < C && a[i][j] < a[i][j+1]){
            dp[i][j+1] = max(dp[i][j+1] ,1 + dp[i][j]) ;
            ret = max(ret,dp[i][j+1]);
            du[i][j+1]--;
            if(du[i][j+1]==0){
                qu.push(point(i,j+1));
            }
        }


        if( j-1 >= 0 && a[i][j] < a[i][j-1]){
            dp[i][j-1] = max(dp[i][j-1] ,1 + dp[i][j]) ;
            ret = max(ret,dp[i][j-1]);
            du[i][j-1]--;
            if(du[i][j-1]==0){
                qu.push(point(i,j-1));
            }
        }


    }
    return ret+1;

}

int main()
{
    while(scanf("%d%d",&R,&C)!=EOF){
        if(R==0 || C==0){
            cout<<0<<endl;
            continue;
        }
        memset(dp,0,sizeof(dp));
        memset(du,0,sizeof(du));

        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                scanf("%d",&a[i][j]);
            }
        }
        int ret = solve();
        cout<<ret<<endl;
    }
    return 0;
}
