#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
long long cal(long long n){
    long long ou =0;
    long long ji =0;
    for(long long i=1;i<=n;i++){
        if((n/i)%2==0){
            ou += n/i;
        }else{
            ji += n/i;
        }
    }
    return abs(ji-ou);
}

long long cal1(long long n){
    long long ret = 0;
    long long sq = sqrt(n);
    for(long long i=1;i <= sq;i++){
        if((n/i)%2==0){
            ret += n/i;
        }else{
            ret -= n/i;
        }
    }
    if(n/sq == sq){
        sq--;
    }
    for(long long i=sq;i>=1;i--){
        if(i%2==0){
            ret += (n/i - n/(i+1))*i;
        }else{
            ret -= (n/i - n/(i+1))*i;
        }
    }
    return abs(ret);
}

int main()
{

    long long n;
    long long T;

    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        cout<<cal1(n)<<endl;
    }
    return 0;
}
