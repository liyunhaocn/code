#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <stack>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

vector<string> split(string s,char sp){
    vector<string> ret;
    for(int i=0;i<s.size();){
        int j=i;
        j = s.find(sp,j);
        if(j==i){
            i++;
        }else if(j>i){
            ret.push_back(s.substr(i,j-i));
            i=j+1;
        }else{

            ret.push_back(s.substr(i,s.size()-i));
            break;
        }
    }
    return ret;
}

string query(string s,string t,int cen){
    string ret="";
    s.pop_back();
    s=s.substr(1);
    vector<string> tt = split(t,'.');
    //debug(cen);
    //debug(tt.size());
    string nextfind = '\"' + tt[cen] + '\"'+':';
    //debug(nextfind);
    int start = s.find(nextfind);
    //debug(start);
    if(start==string::npos){
        debug(start);
        cout<<(start<0)<<endl;
        return "NOTEXIST";
    }

    int mao = s.find(":",start);
    if(s[mao+1] == '"'){
        int dou = s.find("\"," ,mao);

        string tempstr = s.substr( mao+1, dou-mao);
        tempstr.pop_back();
        tempstr = tempstr.substr(1);
        return "STRING " + tempstr;
    }else if(s[mao+1] == '{'){
        if( cen == tt.size()-1){
            return "OBJECT";
        }
        int xias = mao+1;
        int cnt = 0;

        int k = s.find("},",xias);
        string xiass = s.substr(xias,k-mao);
        //debug(xiass);
        //xiass = '\"' + xiass + '\"'+':';
        return query(xiass,t,cen+1);
        //query(s)
    }

    return ret;
}

int main()
{

    char c;
    int n,m;
    string s="";

    scanf("%d%d",&n,&m);
    n++;
    char pre;
    while( n ){

        c = getchar();
        if(c=='\n'){
            n--;
        }else{
            if(c == ' ' ){
             ;
            }else if(c=='\\'){
                if(pre=='\\')
                    s += c;
            }else{
                s += c;
            }

        }
        pre = c;
    }
    //cout<<s<<endl;
    for(int i=0;i<m;i++){
       string sin;
       cin>>sin;
       cout<<query(s,sin,0)<<endl;
    }

    return 0;
}
