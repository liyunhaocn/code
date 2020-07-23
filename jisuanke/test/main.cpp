#include <iostream>
#include <stdio.h>
#include <string.h>
int a[55];
using namespace std;

int main()
{
    a[0]=1;
    a[1]=1;
    for(int i=2;i<55;i++){
        a[i] = a[i-1] + a[i-2];
    }
    int n;
    scanf("%d",&n);
    printf("%d\n",a[n]);
    return 0;

}
