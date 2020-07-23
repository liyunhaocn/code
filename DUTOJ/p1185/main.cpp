#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(string a,string b){
    if(a+b>b+a){
        return true;
    }else{
        return false;
    }
}
string str[100];
string ret="";
int main()
{
    int t;
    int n;
    //ios::sync_with_stdio(false);
    scanf("%d",&t);

    for(int i=0;i<t;i++){
        scanf("%d",&n);
        ret = "";
        for(int j=0;j<n;j++){
            cin>>str[j];
        }
        sort(str,str+n,cmp);
        for(int j=0;j<n;j++){
            ret += str[j];
        }
        cout<<ret<<endl;
    }

    return 0;
}
