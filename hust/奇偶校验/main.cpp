#include <iostream>
#include <stack>
using namespace std;

string sbit(int a){
    stack<char> st;
    while( a > 0){
        st.push( a%2 + '0');
        a /= 2;
    }
    string ret = "";
    int ocnt = 0;
    while( !st.empty() ){
        if( st.top() == '1'){
            ocnt++;
        }
        ret.append( string( 1,st.top()) );
        st.pop();
    }
    int rlen = ret.length();
    for(int i=0;i<7-rlen;i++){
        ret.insert(ret.begin(),'0');
    }
    if(ocnt%2==1){
        ret.insert(ret.begin(),'0');
    }else{
        ret.insert(ret.begin(),'1');
    }
    return ret;
}
int main()
{
    string s;
    while( cin>>s ){
        for(int i=0;i<s.size();i++){
            cout<<sbit(s[i])<<endl;
        }
    }
    return 0;
}
