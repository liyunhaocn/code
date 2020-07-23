#include<stdio.h>

int a[1000002];
int b[1000002];
int d[1000002];
int sum[1000002];
int main(){

    int m,n;
    int l,r;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }

    for(int i=0;i<m;i++){
        scanf("%d%d",&l,&r);
        d[l-1]++;
        d[r]--;
    }
    sum[0]=d[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+d[i];
    }
    for(int i=0;i<n;i++){
        printf("%d%c", a[i] + b[i] * sum[i], i == n-1 ? '\n' : ' ');
    }
return 0;
}
