#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    long long n;
    long long M;
    while(scanf("%lld",&n)!=EOF){

        if(n%2==0){
            M = (n+2)*n/4;
            M %=1000000007;
        }else{
            M=(n/2 +1 )*(1+n)/2;
            M %=1000000007;
        }
        printf("%lld\n",M);
    }

    return 0;
}
//要用long long 否则超过M范围
