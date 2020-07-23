#include <iostream>
#include <stdio.h>
using namespace std;
int a[500][500];
int b[500][500];
int main()
{
    int n,p,m;
    scanf("%d%d%d",&n,&p,&m);
    for(int i = 0 ;i< n;i++){
        for(int j=0;j< p;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i = 0 ;i< p;i++){
        for(int j = 0;j< m;j++){
            scanf("%d",&b[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            long long int sum = 0;
            for(int k=0;k < p;k ++){
                long long int temp = (long long int)a[i][k]*b[k][j];
                temp = temp%1000000007;
                sum += temp;
                sum += 1000000007;
                sum %= 1000000007;
            }
            printf("%lld ",sum);
        }
        printf("\n");
    }
    return 0;
}
