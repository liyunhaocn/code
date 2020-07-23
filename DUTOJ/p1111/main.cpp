#include <iostream>
#include <stdio.h>
#include<set>
using namespace std;
int a[100001];
int main()
{
    int n;
    int q;
    int L;
    int R;
    int ret;
    cout<<(7^1^6)<<endl;
    cout<<(6^7^1^6^1^6)<<endl;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i] = a[i]^a[i-1];
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&L);
        scanf("%d",&R);
        int ret  = a[R]^a[L-1];
        printf("%d\n",ret);
    }

    return 0;
}
