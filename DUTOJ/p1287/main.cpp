#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
typedef long long LL;
#define maxN  101
#define mod 1000000007
#define debug(x) cout<<#x<<": "<<x<<endl;


struct mat{

    LL m;
    LL n;
    LL a[101][101];
    mat(){}
    mat(LL m,LL n):m(m),n(n){memset(a,0,sizeof(a));}

    void disp(){
        for(LL i=0;i<this->m;i++){
            for(LL j=0;j<this->n;j++){
                 cout<<this->a[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

mat mul(mat aa,mat bb){
    mat ret(aa.m,bb.n);
    for(LL i=0;i<aa.m;i++){
        for(LL j=0;j<bb.n;j++){
            for(LL k=0;k<bb.m;k++){
                ret.a[i][j] += aa.a[i][k] * bb.a[k][j] + mod;
                //debug(this->a[i][k] * b.a[k][j]);
                ret.a[i][j] = (ret.a[i][j]+mod)%mod;
            }
        }
    }
    return ret;
}

LL powmat(mat m1,LL n){
    mat ret(m1.m,m1.m);
    memset(ret.a,0,sizeof(ret.a));
    for(LL i=0;i<m1.m;i++){
        ret.a[i][i] = 1;
    }
    while(n){
        if(n&1){
            ret = mul(ret,m1);
        }
        m1 = mul(m1,m1);
        n>>=1;
    }
    return ret.a[0][0];
}



int main()
{
    LL m;
    LL n;
    while(~scanf("%lld%lld",&m,&n)){

        mat m1(m,m);
        for(LL i=0;i<m;i++){
            //m1.a[i][i] = 1;
            m1.a[i][ (i+1)%m ] = 1;
            m1.a[i][ (i+m-1)%m ] = 1;
            m1.a[(i+1)%m][i] = 1;
            m1.a[(i+m-1)%m][i] = 1;
        }
        mat ret(m1.m,m1.m);
        for(LL i=0;i<m1.m;i++){
            ret.a[i][i] = 1;
        }
        //ret.disp();
        //for(int i=0;i<n;i++){
        //    ret = ret*m1;
            //m1.disp();
        //    ret.disp();
        //}
        printf("%lld\n",(powmat(m1,n)+mod)%mod);

    }
    return 0;
}
