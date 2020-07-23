#include <iostream>
#include <stdio.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

int n,m;
int cases = 1;

int main()
{                   //hei   bai
    while( scanf("%d%d",&n,&m) != EOF ){
        float ret = 0;
        if( m+n<1 ){
            ret = 0;
        }else if( m == 0 && n > 1){
            ret = 1;
        }else if( m%2==1 ){
            ret = 0;
        }else if( m%2==0 ){
            ret = 1;
        }
        printf("Case#%d: %.2f\n",cases++,ret);
    }
    return 0;
}
