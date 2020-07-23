#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define foreach(ve) for(auto i:ve){cout<<i<<" ";}cout<<endl;

bool cmp(int a,int b){

    return a<b;
}
int main(){
    priority_queue<int,vector<int>,less<int> > q1;//使用priority_queue<int> q1;一样
    for(int i=0;i<10;i++)
        q1.push(i);
    while(!q1.empty()){
        cout<<q1.top()<< endl;
        q1.pop();
    }


    return 0;
}
