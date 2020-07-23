#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[100000];

bool t1(int a,int b){
    return a > b;
}
bool t0(int a,int b){
    return a < b;
}
int main()
{
    int n,q,k;
    scanf("%d%d%d",&n,&q,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<q;i++){
        int a,b,t;
        scanf("%d%d%d",&a,&b,&t);
        if(t==0){
            sort(arr+a-1,arr+b,t0);
        }else{
            sort(arr+a-1,arr+b,t1);
        }
    }
    printf("%d\n",arr[k-1]);
    return 0;
}
