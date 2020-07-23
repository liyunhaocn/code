#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;

    while(scanf("%d",&n)!=EOF){
        if(n==3){
            printf("1 2 3\n");
        }
        else{
            int a[21]={1,2,6,9};
            for(int i=0;i< n-4;i++){
                for(int j=20;j>2;j--){
                    a[j]=a[j-1];
                    a[j]*=2;
                }
                a[2]=3;
            }
            for(int j=0;j< n;j++){
                printf("%d%c",a[j],j==n-1?'\n':' ');
            }
        }
    }
    return 0;
}
