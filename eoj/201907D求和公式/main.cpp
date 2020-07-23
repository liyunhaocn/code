#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;
typedef long long LL;
LL n,q;

struct point{
    LL x;
    LL y;
    point(LL x,LL y){
        this->x = x;
        this->y = y;
    }
};

//是否在y=x同侧
//大于0就是同侧 小于零是异测 等于零就是一个点在线上
LL isSameyx(point a,point b){
    LL a1 = 1;
    LL a2 = 1;
    if( a.x-a.y < 0){
        a1 = -1;
    }else if(a.x-a.y == 0){
        a1 = 0;
    }

    if( b.x-b.y < 0){
        a2 = -1;
    }else if(b.x-b.y == 0){
        a2 = 0;
    }
    return a1*a2;
}

//是否在y=-x+n-1同侧
LL isSameyxn1(point a,point b){

    LL a1 = 1;
    LL a2 = 1;
    if( a.x+a.y-n+1 < 0){
        a1 = -1;
    }else if( a.x+a.y-n+1 == 0){
        a1 = 0;
    }

    if( b.x+b.y-n+1 < 0){
        a2 = -1;
    }else if( b.x+b.y-n+1 == 0){
        a2 = 0;
    }
    return a1*a2;
}

LL baoCnt(LL a,LL b,LL c,LL d){
    LL cnt = 0;
    for(int i = a ;i<= c;i ++){
        for(int j = b;j <= d;j++){
            if( i==j || i+j==n-1){
                cnt++;
            }
        }
    }
    return cnt;
}

LL myAbs(LL a){
    if(a<0){
        a = -a;
    }
    return a;
}

LL myCnt(LL a,LL b,LL c,LL d){

        point A(a,b);
        point C(c,d);
        point B(c,b);
        point D(a,d);

        LL cntxy = 0;
        LL cntxyn1 = 0;
        //cout<<baoCnt(A,C)<<endl;
        //continue;
        if( A.x == C.x || A.y == C.y) {

            if( isSameyx(A,C) <= 0 ){
                cntxy =1;
            }else if(isSameyx(A,C) > 0){
                cntxy  = 0;
            }

            if( isSameyxn1(A,C) <= 0 ){
                cntxyn1 = 1;
            }else if(isSameyxn1(A,C)>0){
                cntxyn1  = 0;
            }

        }else{
            //debug(A.x);
            //debug(A.y);
            //debug(B.x);
            //debug(B.y);
            //debug(C.x);
            //debug(C.y);

            if( isSameyx( B,D)==0 ){
                cntxy = 1;
            }else if( isSameyx( B,D) > 0 ){
                //cout<<"11111"<<endl;
                cntxy = 0;
            }else{
                if( (isSameyx( A, B) >=0 && isSameyx(C, D) >= 0) || (isSameyx( A, D) >=0 && isSameyx(C, B)>=0 ) ){
                    cntxy = min( myAbs( C.x - A.x ),myAbs( C.y - A.y) ) + 1;
                }else if( isSameyx( B,C) < 0){
                    cntxy = myAbs(B.x - B.y) + 1;
                    //debug(111)
                }else if( isSameyx( A,D) < 0 ) {
                    cntxy = myAbs(D.x - D.y) + 1 ;
                    //debug(2222)
                }
            }

            if( isSameyxn1( A, C) == 0 ){
                cntxyn1 = 1;
            }else if(isSameyxn1( A,C) > 0){
                cntxyn1 = 0;
            }else{
                if( (isSameyxn1( A, B) >=0 && isSameyxn1(C, D) >= 0) || (isSameyxn1( A, D) >=0 && isSameyxn1(C, B)>=0 )){
                    //debug(00000)
                    //debug(isSameyxn1( A, B));
                    //debug(isSameyxn1( C, D));
                    //debug(isSameyxn1( A, D));
                    //debug(isSameyxn1( C, B));
                    cntxyn1 = min( myAbs(C.x - A.x),myAbs( C.y - A.y )) + 1;
                } else if( isSameyxn1( A, D) < 0 ){
                    cntxyn1 = myAbs( n-1-A.x - A.y) + 1;
                    //debug(22222)
                }else if( isSameyxn1( B, C) < 0 ){
                    cntxyn1 = myAbs( n-1-C.x - C.y) + 1;
                    //debug(1111)
                }
            }

        }

        //debug(cntxy);
        //debug(cntxyn1);

        if( n%2 == 0 ){

            return cntxy+cntxyn1 ;
        }else{
            // debug(1111);
            if( A.x <= n/2 && A.y <= n/2 && C.x >= n/2 && C.y >= n/2 ){
                return cntxy+cntxyn1-1 ;
            }else{
                return cntxy+cntxyn1 ;
            }
        }

}

int main()
{
    //freopen("test.txt","r",stdin);
    //LL te = -1000000000000000000;
    //cout<<abs(te)<<endl;
    //n =4;
    //cout<<myCnt(0,0,2,2)<<endl;
    //cout<<baoCnt(0,0,2,2)<<endl;

    scanf("%lld%lld",&n,&q);
    LL a,b,c,d;

    for(LL i=0;i<q;i++){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        cout<<myCnt(a,b,c,d)<<endl;
        /*
        for(LL i1 = 0;i1< n;i1++){
            for(LL i2 = 0;i2 < n;i2++){
                    for(int j1 = i1;j1 < n;j1++){
                        for(int j2 = i2;j2 < n;j2 ++){
                            if( myCnt(i1,i2,j1,j2) == baoCnt(i1,i2,j1,j2)){
                                cout<<"11"<<endl;
                            }else{
                                debug(myCnt(i1,i2,j1,j2));
                                debug(baoCnt(i1,i2,j1,j2));
                                cout<<i1<<" "<<i2<<" "<<j1<<" "<<j2<<" "<<endl;
                                return 0;
                            }
                        }
                    }

            }
        }
        */
        //for(int i=0;;)



    }
    return 0;
}
