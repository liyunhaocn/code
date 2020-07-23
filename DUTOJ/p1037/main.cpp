#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int haveX(string str,char x){
    int len = str.size();
    for(int i=0;i<len;i++){
        if(str[i]==x){
            return 1;
        }
    }
    return 0;
}
int main()
{

    int n;
    char a;
    char b;
    int num=0;
    string str[7]={"c","java","php","html","phython","javascript","mysql"};
    scanf("%d",&n);
    string ret[n];
    for(int i = 0;i < n;i++){
       cin>>a;
       cin>>b;

       for(int i=0;i<7;i++){
            if(haveX(str[i],a) && haveX(str[i],b)){
                ret[num] = str[i];
                num++;
                break;
            }
       }
    }
    for(int i=0 ;i<num;i++){
        cout<<ret[i]<<endl;
    }
    return 0;
}
