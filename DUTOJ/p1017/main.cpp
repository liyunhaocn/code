#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    int temp;
    int sum_100;
    int sum_50;
    int sum_10;
    int sum_5;
    int sum_2;
    int sum_1;
    while(scanf("%d",&n)!=EOF){

        sum_100 = 0;
        sum_50 = 0;
        sum_10 = 0;
        sum_5 = 0;
        sum_2 = 0;
        sum_1 = 0;
        for(int i = 0;i < n;i ++){
            scanf("%d",&temp);
            sum_100 += temp/100;
            temp %= 100;
            sum_50 += temp/50;
            temp %= 50;
            sum_10 += temp/10;
            temp %= 10;
            sum_5 += temp/5;
            temp %= 5;
            sum_2 += temp/2;
            temp %= 2;
            sum_1 += temp;
        }
        printf("%d ",sum_100);
        printf("%d ",sum_50);
        printf("%d ",sum_10);
        printf("%d ",sum_5);
        printf("%d ",sum_2);
        printf("%d\n",sum_1);

    }
    return 0;
}
