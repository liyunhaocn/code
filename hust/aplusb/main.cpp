#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;


int main()
{
    string a;
    string b;
    while(cin>>a && cin>>b ){
        if( a.size() < b.size() ){
            swap(a,b);
        }
        int ap = a.size()-1;
        int bp = b.size()-1;
        int jin = 0;
        while(ap>=0 && bp>=0 ){
            a[ap] += ( b[bp] -'0' + jin);
            if(a[ap]>'9'){
                a[ap] -= 10;
                jin = 1;
            }else{
                jin = 0;
            }
            ap--;
            bp--;
        }
        while(jin){
            a[ap] += 1;
            if( ap>=0 ){
                if(a[ap]>'9'){
                    a[ap] -= 10;
                    jin = 1;
                }else{
                    jin = 0;
                }
                ap--;
            }else{
                a.insert(a.begin(),'1');
                jin = 0;
            }
        }
        cout<<a<<endl;
    }
    return 0;
}
