#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

string int_str(int a){
    stringstream ss;
    ss<<a;
    return ss.str();
}
int main()
{
    int N;
    //printf("%.5f\n",pow(25,2));
    while(scanf("%d", &N) != EOF ){
        int pN = N*N;
        //debug(pN);
        string pNs = int_str(pN);
        string Ns = int_str(N);
        pNs = pNs.substr(  pNs.size()-Ns.size() ,Ns.size());
        if( pNs == Ns){
            cout<<"Yes!"<<endl;
        }else{
            cout<<"No!"<<endl;
        }
    }
    return 0;
}
