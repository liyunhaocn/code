#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

int main()
{
    LL a[90];
    a[0] = a[1] = 1;
    for(int i=2;i<90;i++){
        a[i] = a[i-1] + a[i-2];
    }
    int N;
    while( scanf("%d",&N) != EOF){
        printf("%lld\n",a[N]);
    }
    return 0;
}
