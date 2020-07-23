#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int T;
    int n;
    int temp;
    int jiou;
    scanf("%d",&T);
    int flag;
    for(int i=0;i<T;i++){
        scanf("%d",&n);
        scanf("%d",&temp);
        flag = 1;
        jiou = temp % 2;
        for(int j=0;j<n-1;j++){
            scanf("%d",&temp);
            if(temp % 2 == jiou){
                continue;
            }else{
                flag = 0;
            }
        }
        if(flag){
            printf("YES\n");
        }else{
            printf("NO\n");
        }

    }

    return 0;
}
