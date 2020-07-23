#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
long long power(long long a,long long k){
    long long ret = 1;
    while(k>0){
        ret *= a;
        ret %= 1000000007;
        k--;
    }
    return ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    long long a,b,k;
    long long sum = 0;
    for(int i=0;i<t;i++){
        scanf("%lld",&a);
        scanf("%lld",&b);
        scanf("%lld",&k);
        if(a>b){
            swap(a,b);
        }
        for(int j=a;j<=b;j++){
            sum += power(j,k);
            sum %= 1000000007;
        }

    }
    printf("%lld\n",sum);
    return 0;
}
