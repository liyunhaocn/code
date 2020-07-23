#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int ChuYiTwo(string & num){
    int jie=0;
    int len = num.size();
    int temp;
    int yushu;
    if( (num[len-1]-'0') % 2 == 0 ){
        yushu = 0;
    }else{
        yushu = 1;
    }
    for(int i=0;i<len;i++){
        temp = num[i] - '0';
        temp += jie*10;
        jie = temp % 2;
        temp = temp/2;
        num[i]= temp + '0';
    }
return yushu;

}
int main()
{
    int t;
    string num;
    int flag = 1;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        flag = 1;
        cin>>num;
        while(ChuYiTwo(num)==0){
            flag *= 2;
            flag = flag % 1000000007;
        }
        printf("%d\n",flag);
    }

    return 0;
}
