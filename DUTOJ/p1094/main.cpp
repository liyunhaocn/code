#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#define inf 0x3f3f3f3f
#define met(a,b) memset(a,b,sizeof a)
#define pb push_back
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
const int N = 1e5+5;
const int M = 18;
int mn[N][M],mx[N][M],pre[N][M],gcd[N][M];
int mm[N],n,q;
int mat[N*10];
void init() {
    for(int j=1; j<=mm[n]; ++j) {
        for(int i=1; i+(1<<j)-1<=n; ++i) {
            mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
            mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
            pre[i][j]=max(pre[i][j-1],pre[i+(1<<(j-1))][j-1]);
            gcd[i][j]=__gcd(gcd[i][j-1],gcd[i+(1<<(j-1))][j-1]);
        }
    }
}
int getmx(int l,int r) {
    int k = mm[r-l+1];
    return max(mx[l][k],mx[r-(1<<k)+1][k]);
}
int getmn(int l,int r) {
    int k = mm[r-l+1];
    return min(mn[l][k],mn[r-(1<<k)+1][k]);
}
int getpre(int l,int r) {
    int k = mm[r-l+1];
    return max(pre[l][k],pre[r-(1<<k)+1][k]);
}
int getgcd(int l,int r) {
    int k = mm[r-l+1];
    return __gcd(gcd[l][k],gcd[r-(1<<k)+1][k]);
}
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int main() {
    mm[0]=-1;
    for(int i=1; i<N; ++i)mm[i]=(i&(i-1))?mm[i-1]:mm[i-1]+1;
    while(~scanf("%d%d",&n,&q)) {
        for(int i=1; i<=1000000; ++i)mat[i] = 0;
        for(int i=1; i<=n; ++i) {
            mn[i][0]=read();
            mx[i][0]=mn[i][0];
            pre[i][0]=mat[mn[i][0]];
            mat[mn[i][0]]=i;
            if(i>1)gcd[i-1][0] = abs(mn[i][0]-mn[i-1][0]);
        }
        init();
        while(q--) {
            int l=read(),r=read();
            if(l==r) {
                printf("Yes\n");
                continue;
            }
            int x=getmn(l,r),y=getmx(l,r);
            if(x==y) {
                printf("Yes\n");
                continue;
            }
            if(getpre(l,r)>=l) {
                printf("No\n");
                continue;
            }
            int d = getgcd(l,r-1);
            if(x+1ll*(r-l)*d==y)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
