#include <iostream>

using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;
typedef long long LL;
LL r,y,g;
LL n;
LL dengtime(LL k,LL t){
    if(k==1){
        return t;
    }else if(k==2){
        return t+r;
    }else if(k==3){
        return 0;
    }
}

LL deng(LL t){
    if(0<=t && t< r){
        return 1;
    }else if(t>=r && t<r+g){
        return 3;
    }else if(t>=r+g && t < r+g+y){
        return 2;
    }
}

LL deng_time[4];
int main()
{



    while(cin>>r>>y>>g){

        cin>>n;
        deng_time[1] = r;
        deng_time[2] = g+y+r;
        deng_time[3] = g+r;

        LL sum = 0;
        LL mod = r+y+g;
        for(LL i = 0;i < n; i++){
            LL k,t;
            cin>>k>>t;
            if(k==0){
                sum += t;
                //debug(t);
                continue;
            }else if(k==1){
                t = r - t;
            }else if(k==2){
                t = y - t;
                t += g+r;
            }else if(k==3){
                t = g - t;
                t += r;
            }

            t += sum;
            t %= mod;
            LL den = deng(t);
            //debug(den);
            sum += dengtime(den,deng_time[den]-t);

        }
        cout<<sum<<endl;
    }
    return 0;
}
