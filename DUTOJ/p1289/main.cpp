
#include <iostream>
#include <stdio.h>
#include <cstring>

#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>

#define INF 0x7fffffff
#define EPS 1e-12
#define mod 1000000007
#define PI 3.141592653579798
typedef long long ll;

using namespace std;

ll POW(ll num,ll k){

    ll ans=1;

    num = num % mod;
    while(k>0)
    {
        if(k&1){
            num = num % mod;
            ans*=num;

        }
        num=num*num % mod;
        k>>=1;

    }
    return ans;
}

ll fac(ll n){
    ll ans = 1;
    while(n>=2){
        ans *= n;
        n--;
    }
return ans;
}
ll C(ll n,ll m){
    return fac(n)/fac(n-m)/fac(m);

}

ll A(ll n,ll m){
    return fac(n)/fac(n-m);

}
ll ktl(ll n){
    return C(2*n,n)/(n+1);
}



void exgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
    if(!b) { d = a; x = 1; y = 0; }
    else{ exgcd(b, a%b, d, y, x); y -= x*(a/b); }
}

ll inv2(ll a, ll p)
{
    ll d, x, y;
    exgcd(a, p, d, x, y);
    return d == 1 ? (x+p)%p : -1;
}


int main()
{
    ll n;
    scanf("%lld",&n);
    ll a =(ktl(n/2)*inv2(POW(2,n),mod)) % mod;
    cout<<a<<endl;
    return 0;
}
