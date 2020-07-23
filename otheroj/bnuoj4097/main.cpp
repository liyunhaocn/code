#include <iostream>
#include <stdio.h>

using namespace std;
typedef long long LL;

LL cal(LL n,LL k){

    LL  num,i,t=0;
    if(n==0&&k==0){
        return -1;
    }else if(n==1){
        return k+1;
    }else if(k==1){
        return 2;
    }
    for(long long int j=1;;j++){
        num=j*k+1;
        for(i=0;i<n;i++ ){
            if(num%(k-1)==0){
                num=num/(k-1)*k+1;
            }else break;

            if(i==n-2){
                return num;
                t=1;
                break;
            }
        }
        if(t) break;
    }


}
int main()
{
    for(LL i=1;i<=10;i++){
        cout<<"{";
        for(LL j=1;j<=10;j++){

            //cout<<cal(i,j)<<"\t"<<", ";
            printf("%12lld %c",cal(i,j),j<10?',':' ');
        }

        cout<<"},"<<endl;
    }
    return 0;
}
//上面的程序打表

//提交

#include <iostream>
#include <stdio.h>
#include <string>
#include <typeinfo>
#include <stack>
#include <vector>
#include <sstream>
#include <string.h>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;
typedef long long LL;

int main()
{
    long long ret[11][11] = {
{           2 ,           3 ,           4 ,           5 ,           6 ,           7 ,           8 ,           9 ,          10 ,          11  },
{           2 ,           7 ,           7 ,          13 ,          21 ,          31 ,          43 ,          57 ,          73 ,          91  },
{           2 ,          15 ,          25 ,          61 ,         121 ,         211 ,         337 ,         505 ,         721 ,         991  },
{           2 ,          31 ,          79 ,         253 ,         621 ,        1291 ,        2395 ,        4089 ,        6553 ,        9991  },
{           2 ,          63 ,         241 ,        1021 ,        3121 ,        7771 ,       16801 ,       32761 ,       59041 ,       99991  },
{           2 ,         127 ,         727 ,        4093 ,       15621 ,       46651 ,      117643 ,      262137 ,      531433 ,      999991  },
{           2 ,         255 ,        2185 ,       16381 ,       78121 ,      279931 ,      823537 ,     2097145 ,     4782961 ,     9999991  },
{           2 ,         511 ,        6559 ,       65533 ,      390621 ,     1679611 ,     5764795 ,    16777209 ,    43046713 ,    99999991  },
{           2 ,        1023 ,       19681 ,      262141 ,     1953121 ,    10077691 ,    40353601 ,   134217721 ,   387420481 ,   999999991  },
{           2 ,        2047 ,       59047 ,     1048573 ,     9765621 ,    60466171 ,   282475243 ,  1073741817 ,  3486784393 ,  9999999991  }
};
    while(1)
    {
        int n,k;
        long long int num=1;
        cin>>n>>k;
        if(n==0&&k==0) break;
        else if(n==2&&k==2){cout<<7<<endl;}
        else if(n==1){cout<<k+1<<endl;}
        else if(k==1){cout<<2<<endl;}
        else
        {
            cout<<ret[n-1][k-1]<<endl;
        }
    }
    return 0;
}

