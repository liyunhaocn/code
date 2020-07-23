
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

int str_int(string s){
    stringstream ss;
    ss<<s;
    int a;
    ss>>a;
    return a;
}
int main(){
    string s;
    cin >> s;
    int start = 0;
    for(int i = 0;i < s.size();i++){
        string temp = "";
        if(s[i] == '.'){
            temp = s.substr(start,i-start);
            start = i+1;
        }else if(i == s.size() - 1){
            temp = s.substr(start,i-start+1);
        }else{
            continue;
        }
        int tt = str_int(temp);
        //cout<<tt<<endl;
        if( !( tt >= 0 && tt <= 255) ){
            cout<<"No!"<<endl;
            return 0;
        }
    }
    cout<<"Yes!"<<endl;
    return 0;
}

