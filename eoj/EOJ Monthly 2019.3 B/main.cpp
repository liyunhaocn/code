#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long LL;

LL arr[1000001];

LL cal(LL l,LL r){

    if(l+1==r){
        if(arr[l]==arr[r]){
            return 0;
        }else{
            return 1;
        }
    }else if(l==r){
        return 0;
    }else{
        if(arr[l]<arr[r]){
            arr[l+1] +=arr[l];
            return 1+cal(l+1,r);
        }else if(arr[l]>arr[r]){
            arr[r-1] += arr[r];
            return 1+cal(l,r-1);
        }else{
            return cal(l+1,r-1);
        }
    }

}

LL cal1(LL n){
    LL i = 0;
    LL j = n-1;
    LL counter = 0;
    while(i<=j-2){
        if(arr[i]<arr[j]){
            arr[i+1] += arr[i];
            i++;
            counter++;
        }else if(arr[i]>arr[j]){
            arr[j-1] += arr[j];
            j--;
            counter++;
        }else{
            i++;
            j--;
        }
    }
    if(i==j){
        return counter;
    }else{
        if(arr[i]==arr[j]){
            return counter;
        }else{
            return counter+1;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    cout<<cal(0,n-1)<<endl;
    return 0;
}
