#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    double a[1000];
    double s[1000];
    for(int i=1;i<1000;i++){
        a[i] = 1/(double)(i+1);
    }
    s[0] = 0;
    s[1] = a[1];
    for(int i = 2;i<1000;i++){
        s[i] = s[i-1] + a[i];
    }
    double t;

    while(scanf("%lf",&t)!=EOF){
        for(int i=0;i<1000;i++){
            if(s[i]<t && s[i+1]>t){
                printf("%d card(s)\n",i+1);
            }
        }
    }
}
