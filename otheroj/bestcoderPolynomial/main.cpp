#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;


int maxyue(int a,int b){
    int ret =1;
    for(int i=1;i<=min(a,b);i++){
        if( a%i==0 && b%i ==0){
            ret = i;
        }
    }
    return ret;
}

int yuefen(int &a,int &b){
    int yue = maxyue(a,b);
    a/=yue;
    b/=yue;
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        vector<int> zi;
        vector<int> mu;
        int temp;
        for(int j=0;j<n;j++){
            scanf("%d",&temp);
            zi.push_back(temp);
        }
        for(int j=0;j<n;j++){
            scanf("%d",&temp);
            mu.push_back(temp);
        }
        for(int j=n-1;j>=0;j--){
            if(zi[j] ==0 && mu[j] ==0){
                //debug(1111);
                continue;

            }else if(mu[j]==0  && zi[j]!=0){
                cout<<"1/0"<<endl;
                break;
            }else if(mu[j]!=0  && zi[j]==0){
                cout<<"0/1"<<endl;
                break;
            }else{
                yuefen(zi[j],mu[j]);
                cout<<zi[j]<<"/"<<mu[j]<<endl;
                break;
            }
        }
    }
    return 0;
}
