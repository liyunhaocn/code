#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;



int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int tt;
        scanf("%d",&tt);
        int arr[201];
        int sum[201];
        fill(arr,arr+201,0);
        fill(sum,sum+201,0);
        for(int j=0;j<tt;j++){
            int a,b;
            scanf("%d%d",&a,&b);
            if(a>b)swap(a,b);
            if(a%2==1){
                a = a/2+1;
            }else{
                a= a/2;
            }
            if(b%2==1){
                b = b/2+1;
            }else{
                b= b/2;
            }
            arr[a]++;
            arr[b+1]--;
        }
        sum[1] = arr[1];
        int max1 = sum[1];
        for(int i=2;i<201;i++){
            sum[i] = sum[i-1] + arr[i];
            max1 = max(max1,sum[i]);
        }
        cout<<max1*10<<endl;
    }
    return 0;
}
