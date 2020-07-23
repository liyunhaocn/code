#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int aa[26];
int bb[26];
int main()
{
    string a,b;

    cin>>a;
    cin>>b;
    for(int i=0;i<a.size();i++){
        int index1 = a[i]-'A';
        int index2 = b[i]-'A';
        aa[index1]++;
        bb[index2]++;
    }
    sort(aa,aa+26);
    sort(bb,bb+26);
    for(int i=0;i<26;i++){
        if(aa[i]!=bb[i]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
