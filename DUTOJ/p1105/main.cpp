#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    long long n;
    int height_Min=0;
    int height_Max=0;
    int Min;
    int Max;
    int temp;
    scanf("%lld",&n);
    scanf("%d",&temp);
    Min = Max = temp;
    for(long long i=0;i<n-1;i++){
        scanf("%d",&temp);
        if(temp<Min){
            Min = temp;
            height_Min ++;
        }
        if(temp>Max){
            Max = temp;
            height_Max ++;
        }
    }
    int ret = fabs(height_Min-height_Max);
    printf("%d\n",ret);
    return 0;
}
