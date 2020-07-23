#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stack>

using namespace std;

#define debug(x) cout<<#x<<": "<<(x)<<endl;

int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        string s;
        cin>>s;
        stack<char> st;
        if(s[0]=='b'){
            cout<<"Dead Fang"<<endl;
            continue;
        }

        int pos =s.size()-1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='a'){
                pos --;
            }else{
                break;
            }
        }

        s = s.substr(0,pos+1);

        bool isS = false;
        for(int i = 0;i < s.size();i++){
            if(s[i]=='a'){
                st.push('a');
            }else if(s[i]=='b'){
                if(st.empty()){
                   cout<<"Dead Fang"<<endl;
                   isS = true;
                   break;
                }
                st.pop();
            }
        }
        if(!isS){
            if(!st.empty()){
                cout<<"Sad Fang"<<endl;
            }else{
                cout<<"Happy Fang"<<endl;
            }
        }
    }
    return 0;
}
