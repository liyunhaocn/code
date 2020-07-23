#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int T;
    int n;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&n);
        if(n>0 && n%3==0){
            printf("Xiaohong\n");
        }else{
            printf("Xiaoming\n");
        }
    }
    return 0;
}
