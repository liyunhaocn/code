#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;


int main()
{
    int n;
    int a[200];

    while( scanf("%d",&n) != EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}
