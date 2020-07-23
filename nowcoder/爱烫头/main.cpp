#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n==0){
        cout<<"None"<<endl;
    }else if(n==1){
        cout<<"XiZhiTang"<<endl;
    }else if(n==2){
        cout<<"YingHuaTang"<<endl;
    }else{
        cout<<"BigBoLang"<<endl;
    }
    return 0;
}
