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

ll fac[2001];
void exgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
    if(!b) { d = a; x = 1; y = 0; }
    else{ exgcd(b, a%b, d, y, x); y -= x*(a/b); }
}

ll inv2(ll a)
{
    ll d, x, y;
    exgcd(a, mod, d, x, y);
    return d == 1 ? (x+mod)%mod : -1;
}
ll POW(ll num,ll k){

    ll ans=1;

    num = num % mod;
    while(k>0)
    {
        if(k&1){
            num = num % mod;
            ans*=num;
            ans%=mod;

        }
        num=num*num % mod;
        k>>=1;

    }
    return ans;
}


ll C(ll n,ll m){
    return (fac[n]*inv2(fac[n-m])*inv2(fac[m])%mod+mod)%mod;
}

ll A(ll n,ll m){
    return (fac[n]*inv2(fac[n-m])%mod+mod)%mod;

}
ll ktl(ll n){
    return (C(2*n,n)*inv2(n+1)%mod+mod)%mod;
}




int main()
{
    ll n,m;
    fac[0]=1;
    for(int i=1;i<=2000;i++){
        fac[i]= (fac[i-1]*i%mod+mod)%mod;
    }

    scanf("%lld",&n);
    if(n%2==1){
        cout<<"0"<<endl;
    }else{
        ll a = (ktl(n/2)*inv2(POW(2,n)))%mod;
        a+=mod;
        a%=mod;
        //ll a = ktl(n);
        cout<<a<<endl;

    }



    return 0;
}
