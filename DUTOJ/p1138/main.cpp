#include <iostream>
#include <stdio.h>
using namespace std;
int a[100000];
int main()
{
    int T;
    int n,k;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&n);
        scanf("%d",&k);
        for(int j=0;j<n;j++){
            scanf("%d",&a[j]);
        }
        int num = 0;
        for(int ii = 0;ii<n;ii++){
            int sum = a[ii];
            for(int jj=ii+1;jj<n;jj++){
                sum+= a[jj];
                if(sum<k){
                   continue;
                }else if(sum>k){

                    break;
                }else{
                    num++;
                }
            }
        }

        printf("%d\n",num);
    }
    return 0;
}

