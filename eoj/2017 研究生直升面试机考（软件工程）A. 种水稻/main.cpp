#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n = 0;
        scanf("%d",&n);

        int cnt = 0;
        for(int i=0;i<n;i++){
            int temp;
            scanf("%d",&temp);
            if(temp <= 10){
                cnt++;
            }
        }
        printf("%d\n",cnt);

    }

    return 0;
}
