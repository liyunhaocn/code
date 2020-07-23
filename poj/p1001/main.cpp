#include <iostream>
#include <string>
using namespace std;


#define debug(x) cout<<#x<<": "<<x<<endl;

string cheng(string a,string b){
    string ret(a.size()+b.size(),'0');
    for( int i=a.size()-1;i>=0; i-- ){
        for( int j=b.size()-1;j>=0;j-- ){
            int temp = (a[i]-'0')*(b[j]-'0') + ret[i+j+1]-'0';
            ret[i+j+1] = temp%10+'0' ;
            ret[i+j] += temp/10;
        }
    }
    return ret;
}

string quickPow( string a,int n ){
    string ret = "1";
    while( n>0 ){
        if( n&1 ){
            ret = cheng(ret,a);
        }
        n >>= 1;
        a = cheng(a,a);
    }
    return ret;

}

int main()
{
    string s="0.4321";
    int a=20;
    while( cin >> s >>a ){
        int pos = s.find('.');

        string qian = s.substr(0,pos);
        string hou = s.substr( pos+1 );
        if(pos==-1){
            hou = "";
        }
        string ret = quickPow(qian+hou,a);
        int i = 0;
        int houSize = hou.size()*a;
        qian = ret.substr(0,ret.size()-houSize);
        hou = ret.substr(ret.size()-houSize);
        while( i < qian.size() && qian[i] == '0' ){
            i ++;
        }
        qian = qian.substr(i);
        i = hou.size()-1;
        while(i>=0 && hou[i]=='0'){
            i--;
        }
        hou = hou.substr(0,i+1);
        if(hou.size()==0){
            cout<< qian << endl;
        }else{
            cout<< qian <<"."<< hou <<endl;
        }

    }
    return 0;
}
