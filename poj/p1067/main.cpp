#include<iostream>

#include<math.h>

using namespace std;

int main(){


    double x = (1.0 + sqrt(5.0))/2.0;
    int ak;
    int bk;
    while(cin>>ak>>bk){
        if(ak > bk){//½»»»ak,bk
            ak ^= bk;
            bk ^= ak;
            ak ^= bk;
        }
        int k = bk - ak;
        if(ak == (int)(k*x))
          cout<<0<<endl;
         else
           cout<<1<<endl;
    }
    //system("pause");
    return 0;
}
