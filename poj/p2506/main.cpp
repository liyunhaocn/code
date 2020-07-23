#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

string ret[251];
int n;

string mul(string s,int a){
    s.insert(s.begin(),'0');
    int jin = 0;
    for(int i = s.size()-1;i>=0;i--){
        //debug(s)
        int temp = a*(s[i]-'0')+jin;
        s[i] = temp%10 + '0';
        jin = temp/10;
    }

    if( s[0]=='0' ){
        s = s.substr(1);
    }
    return s;
}

string add(string a,string b){
    int jin = 0 ;
    if( a.size() < b.size() ){
        swap(a,b);
    }
    int i = a.size()-1;
    int j = b.size()-1;
    while( i>=0 && j>=0 ){
        int temp = a[i]-'0'+b[j]-'0'+jin;
        jin = temp/10;
        a[i] = temp%10+'0';
        i--;
        j--;
    }
    while(i>=0 && jin!=0 ){
        int temp = a[i]-'0' + jin;
        jin = temp/10;
        a[i] = temp%10+'0';
        i--;
    }
    if( jin!=0 ){
        a.insert(a.begin(),'1');
    }
    return a;
}
int main()
{

    ret[0] = "1";
    ret[1] = "1";
    ret[2] = "3";
    for(int i=3;i<=250;i++){
        ret[i] = add( ret[i-1] , mul( ret[i-2],2)) ;
    }
    while( scanf("%d",&n)!=EOF ){
    //for(int n=0;n<=250;n++){

        cout<<ret[n]<<endl;
    //}

    }

    return 0;
}
