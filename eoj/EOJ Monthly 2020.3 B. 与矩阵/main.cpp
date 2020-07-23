#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
#define debug(x) cout<<#x<<(x)<<endl;

int arr[1000];

int main()
{
    int n;
    scanf("%d",&n);
    memset(arr,0,sizeof(arr));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int aij;
            scanf("%d",&aij);
            for(int w=0;w<32;w++){
                if( aij &(1<<w) ){
                    arr[i] |= (1<<w);
                    arr[j] |= (1<<w);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d%c",arr[i],i==n-1?'\n':' ');
    }
    return 0;
}

