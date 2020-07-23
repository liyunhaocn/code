#include <iostream>
#include <stdio.h>
using namespace std;


int main()
{
    double t;
    double sum = 0;
    for(int i =0;i<12;i++){
        scanf("%lf",&t);
        sum += t;
    }
    printf("$%.2f\n",sum/12);

}
/*
int main()
{
    double t;
    while(scanf("%lf",&t)!=EOF){

        double sum = 0;
        sum += t;
        for(int i =0;i<11;i++){
            scanf("%lf",&t);
            sum += t;
        }
        printf("$%.2f\n",sum/12);
    }
}
*/
