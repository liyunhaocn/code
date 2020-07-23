#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{

    int n;
    double ai;
    double xi;
    double sumAi = 0;
    double sumXi = 0;
    double ret;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&ai);
        scanf("%lf",&xi);
        sumAi += ai*xi;
        sumXi += xi;
    }
    ret = sumAi/sumXi;
    printf("%.1lf\n",ret);
    return 0;
}
