#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;


int main()
{
    map<char,char> m1;
    int n;
    cin>>n;

    for(int j=0;j<26;j++){
        char c;
        cin>>c;
        m1[c]='a'+j;
    }


    for(int k=0;k<n;k++){
        string a ,b;
        cin>>a;
        cin>>b;
        for(int i=0;i<a.size();i++){
            a[i] = m1[a[i]];
        }
        for(int i=0;i<b.size();i++){
            b[i]=m1[b[i]];
        }
        if(a<b){
            cout<< "<" <<endl;
        }else if(a>b){
            cout<<">"<<endl;
        }else{
            cout<<"="<<endl;
        }
    }
    return 0;
}
