#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long LL;

int a[5000001];
int main()
{
    int n;
    while( scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        bool is = false;
        for(int i =0;i<=n-3;i++){
            if(a[i]+a[i+1]>a[i+2]){
                printf("YES\n");
                is  = true;
                break;
            }
        }
        if(!is)
        printf("NO\n");
    }

    return 0;
}
