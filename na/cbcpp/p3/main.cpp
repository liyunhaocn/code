#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        k++;
        int an = n + (k-1)*m;

        printf("%d\n",k*(n+an)/2);
    }
    return 0;
}
