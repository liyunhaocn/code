#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
struct matrix
{
    ll m[3][3];
    matrix(){
        memset(this->m,0,sizeof(this->m));
    }
};
matrix r4;
matrix mul(matrix A,matrix B)
{
    matrix ret;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            ret.m[i][j]=0;
            for(int k=0;k<3;k++)
                ret.m[i][j]+=A.m[i][k]*B.m[k][j]%mod;
        }
    return ret;
}
matrix pow(matrix A,long long n)
{
    matrix ret;
    ret.m[0][0]=1;ret.m[1][1]=1;ret.m[2][2]=1;
    while(n)
    {
        if(n&1)
            ret=mul(ret,A);
        A=mul(A,A);
        n>>=1;
    }
    return ret;
}
int main()
{
    long long si[5]={0,1,0,-1};
    int n;ll a,b,c,aans;long long ans2,ans1,tmp;
    r4.m[0][0]=5; r4.m[0][1]=3; r4.m[1][0]=3; r4.m[1][1]=2; r4.m[2][1]=-1; r4.m[2][0]=-1; r4.m[2][2]=1;
    while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF)
    {
   if(c==1){
    printf("%lld\n",a);continue;
   }
   if(c==2){
    printf("%lld\n",b);continue;
   }
   if(c==3){
    printf("%lld\n",(a+b)%mod);continue;
   }
   if(c==4){
    printf("%lld\n",(b+a+b-1)%mod);continue;
   }
    matrix ans;
    ans.m[0][0]=b;   ans.m[0][1]=a;   ans.m[0][2]=1;
    ans=mul(ans,pow(r4,(c-2)/4));
    ans2=ans.m[0][0]%mod;
    ans1=ans.m[0][1]%mod;
    for(int i=2+4*((c-2)/4);i<c;i++)
    {
            tmp=ans2;
            ans2+=ans1+si[i%4];
            ans2%=mod;
            ans1=tmp;
    }
    printf("%lld\n",((ans2%mod)+mod)%mod);
    }

    return 0;
}
