#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
typedef long long LL;
#define debug(x) cout<<#x<<": "<<x<<endl;
int main()
{

    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        string a;
        string b;
        cin>>a;
        cin>>b;
        bool huan = false;
        string paa = a;
        string pbb = b;
        if(a.size()<b.size()){
            swap(a,b);
        }
        int ai = a.size()-1;
        int bi = b.size()-1;
        int jin = 0;
        while(ai>=0 && bi>=0){
            a[ai] = a[ai] -'0' + b[bi] -'0' + jin + '0';
            if( a[ai] - '0' > 9){
                jin = 1;
                a[ai] = ( a[ai]-'0')%10+ '0';
            }else{
                jin = 0;
            }
            ai--;
            bi--;
        }
        while(jin && ai>=0){
            a[ai]++;
            if(a[ai]-'0' > 9){
                jin = 1;
                a[ai]='0';
            }else{
                jin = 0;
            }
            ai--;
        }
        if(ai==-1 && jin){
            a.insert(a.begin(),'1');
        }
        //去掉前导零
        int pos =0;
        while(a[pos]=='0'){
            pos++;
        }
        a = a.substr(pos);
        //如果本来就是0
        if(a.size()==0){
            a = "0";
        }
        cout<<"Case "<<i<<":"<<endl;
        cout<<paa<<" + "<<pbb<<" = "<<a<<endl;
        //最后一次只用一个空行
        if(i<T){
            cout<<endl;
        }
    }

    return 0;
}
