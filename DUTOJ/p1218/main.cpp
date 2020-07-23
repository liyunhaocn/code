#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstring>
using namespace std;

int CNM(int n,int m){
    int ret=1;
    for(int k=1;k<=m;k++)
    {
        ret=(ret*(n-m+k))/k;//先算乘法，避免先算（m-n+k）/k除不尽带来误差
        ret%=1000000007;
    }
return ret%1000000007;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",CNM(8*n-2,4*n-1)/2);


    return 0;
}
