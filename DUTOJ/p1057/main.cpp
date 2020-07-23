#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int T;
    int n;
    scanf("%d",&T);
    //所有的可能都在这里了。最长为4
    //int a[23]={1,6,8,9,10,11,16,18,19,60,61,66,68,69,80,81,86,88,89,90,91,96,98,99};

    for(int i=0;i<T;i++){
        scanf("%d",&n);
        if(n<=4){
            printf("YES\n");
        }else{
            printf("Orz\n");
        }
    }
    return 0;
}
