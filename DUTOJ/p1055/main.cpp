#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int T;
    int n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n%2==1){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
