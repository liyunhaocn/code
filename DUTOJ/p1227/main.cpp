#include <stdio.h>
#include <string.h>
typedef long long ll;
char s1[21];
char s2[21];
char s3[21];
int len[4];
ll xlen[105];
int allLen;
ll x,k;
void f(int n){
    if(n==0){
        return;
    }
    printf("1");
    f(n-1);
    printf("2");
        f(n-1);
    printf("3");
}
void Find(ll x,ll k){
    if(k <= len[1]){
        printf("%c\n",s1[k-1]) ;
        return;
    }
    k -= len[1];
    if(k <= xlen[x-1]){
        Find(x-1,k);
        return;
    }
    k -= xlen[x-1];
    if(k <= len[2]){
        printf("%c\n",s2[k-1]);
        return;
    }
    k -= len[2];
    if(k <= xlen[x-1]){
        Find(x-1,k);
        return;
    }
    k -= xlen[x-1];
    if(k<=len[3]){
        printf("%c\n",s3[k-1]) ;
        return;
    }
    printf("gg\n") ;

}
int main()
{
    scanf("%s%s%s",s1,s2,s3);
    len[1] = strlen(s1);
    len[2] = strlen(s2);
    len[3] = strlen(s3);
    allLen = len[1] + len[2] + len[3];

    scanf("%lld%lld",&x,&k);
    for(int i=1;i<101;i++){
        xlen[i] = xlen[i-1]*2 + allLen;
        if (xlen[i - 1] >= 1e18){xlen[i] = 3e18;}
    }

    Find(x,k);


return 0;
}
