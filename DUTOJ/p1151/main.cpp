#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    int k;
    double ret;
    for(int i=0;i<T;i++){
        scanf("%d",&k);
        ret = pow(2,k)-1;
        printf("%.2lf\n",ret);
    }

    return 0;
}
