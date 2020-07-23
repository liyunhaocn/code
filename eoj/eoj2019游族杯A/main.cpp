#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;
int str_int(string s){
    stringstream ss;
    ss<<s;
    int ret;
    ss>>ret;
    return ret;
}
int main()
{
    string ss;
    cin>>ss;
    int day = ss[ss.size()-1] - '0';
    ss = ss.substr(0,ss.size()-1);
    //debug(ss);
    int s,t;
    if(ss[0]=='1' && ( ss[1] == '1' || ss[1] == '0') ){
        s = str_int( ss.substr(0,2) );
        t = str_int(ss.substr(2) );
    }else{
        s = ss[0] - '0';
        t = str_int(ss.substr(1) );
    }

    cout<<(12-s+t)*day<<endl;
    return 0;
}
