#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int T;
    int temp;
    int n;
    int ret;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&n);
        scanf("%d",&temp);
        ret = temp;
        for(int j=0;j< n-1;j++){
            scanf("%d",&temp);
            ret ^= temp;

        }
        printf("%d\n",ret);
    }
    return 0;
}
