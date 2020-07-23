#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n%2==0 && m%2==0){
            printf("Yes\n");
        }else if(n%2==0 && m%2==1){
            printf("Yes\n");
        }else if(n%2==1 && m%2==0){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }

    return 0;
}
