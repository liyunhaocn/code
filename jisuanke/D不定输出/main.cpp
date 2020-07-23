#include <iostream>
#include <string.h>
using namespace std;
int num[1001][1001];
int index_1[1001];
int main(){
    int n;
    cin >> n;
    int k;
    int index_2=0;
    int ks=n;
    while(ks--){
        cin>>k;
        index_2++;
        num[k][index_1[k]]=index_2;
        index_1[k]++;
    }
    for(int i=0;i<=1000;i++){
        if(index_1[i]>0){
                cout<<i<<" ";
            for(int j=0;j<index_1[i];j++){
                cout<<num[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
