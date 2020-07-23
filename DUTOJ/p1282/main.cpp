#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
³¬¿Õ¼ä
int main()
{
    int n;
    map<int,bool> mp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        mp[temp] = 1;
    }
    int c;
    scanf("%d",&c);
    map<int,bool>::iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        if( mp[c - (it->first) ] ){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
*/

bitset<100000001> bs;
int main (){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        bs[temp] = 1;
    }
    int c;
    scanf("%d",&c);
    for(int i=1;i<=100000000;i++){
        if(bs[i] && c-i >=0 && c-i<=100000000 && bs[c-i]){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;

}

