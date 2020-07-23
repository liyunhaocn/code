#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    int T;

    double rate[8] = {0,0.03,0.1,0.2,0.25,0.3,0.35,0.45};
    double mon[8] = {0,36000,144000,300000,420000,660000,960000,1e10};
    scanf("%d",&T);
    while(T--){
        double x;
        scanf("%lf",&x);
        double sum = 0;
        for(int i=1;i < 8; i++){
            double temp = 0;
            if(x-mon[i]<=0){
               temp = x - mon[i-1];
               sum += temp * rate[i];
               break;
            }else{
                temp = mon[i]-mon[i-1];
                sum += temp * rate[i];
            }

        }
        double ret = 1e8/(x-sum);
        ret = ceil(ret);

        printf("%.0lf \n", ret);

    }

    return 0;
}
