#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
bool isSuShu(int x){
    int sqrtx = sqrt(x);
    bool flag = 1;
    for(int i=2;i<=sqrtx;i++){
        if(x % i == 0){
            flag = 0;
        }
    }
    return flag;
}
int main()
{
    int t,x;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&x);
        if(isSuShu(x)){
            printf("yes\n");
        }else {
            printf("no\n");
        }
    }
    return 0;
}
