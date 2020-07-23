#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a;
    scanf("%d",&a);
    int sum = 0;
    int last = 0;
    int cur = 0;
    while(a!= 0){

        if(a==1){
            cur = 1;
            sum += cur;
            last = cur;
        }else if(a==2 && last ==1){
            cur = 2;
            sum += cur;
            last = cur;
        }else if(a==2){
            cur = last + 2;
            sum += cur;
            last = cur;
        }

        scanf("%d",&a);
    }
    printf("%d\n",sum);
    return 0;
}
