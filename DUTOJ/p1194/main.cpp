#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int T;
    double x;
    double s;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%lf",&x);
        scanf("%lf",&s);
        printf("%.2lf\n",s/x*3.6);
    }
    return 0;
}
