#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int aa,bb,cc;
        scanf("%d%d%d",&aa,&bb,&cc);
        int a=0 ,b=0;

        printf("fill B\n");
        b = bb;

        while(b>0){
            printf("pour B A\n");
            if(a+b>=aa){
                b-=aa-a;
                if(b==cc){
                    break;
                }
                a=aa;
                printf("empty A\n");
                a = 0;
            }else{
                a+=b;
                b=0;
                printf("fill B\n");
                b = bb;
            }

        }

        printf("success\n");

    }
    return 0;
}
