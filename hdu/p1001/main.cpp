#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long LL;
int main()
{
    LL n;
    while(scanf("%lld",&n)!=EOF){
        printf("%lld\n\n",n*(n+1)/2);
    }
    return 0;
}
