#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int T;
    int n;
    long long int a[500000];
    scanf("%d",&T);
    long long  max1;
    long long  temp;
    for(int i=0;i<T;i++){
        max1=0;
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            scanf("%lld",&a[i]);
            //printf("%lld ",a[i]);
        }
        for(int m=0;m<n;m++){
            for(int k=m+1;k<n;k++){
                printf("m %d\n",m);
                printf("k %d\n",k);
                printf("am %d\n",a[m]);
                printf("ak %d\n",a[k]);
                temp = a[m]+ a[k];

                if(temp > max1){
                    max1 = temp;
                }
            }

        }
        printf("%lld\n",max1);
    }
    return 0;
}
