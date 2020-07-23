#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
//int to string 倒序转换
string to_String(int n){
    int m = n;
    char s[21];
    char ss[21];
    int i=0,j=0;
    if(n==0){
        ss[0]='0';
        ss[1]='\0';
        return ss;
    }
    if (n < 0)// 处理负数
    {
     m = 0 - m;
     j = 1;
     ss[0] = '-';
    }

    while (m>0)
    {
     s[i++] = m % 10 + '0';
     m /= 10;
    }
    s[i] = '\0';
    i = i - 1;
    while (i >= 0)
    {
     ss[j++] = s[i--];
    }
    ss[j] = '\0';
return ss;
}




int main()
{
    int a,b;
    char c;
    int T;
    scanf("%d",&T);
    string ret;
    for(int i=0;i<T;i++){
        ret="";
        cin>>a;
        ret = to_String(a);
        ret += " ";
        cin>>c;
        ret += c;
        ret += " ";
        cin>>b;
        ret += to_String(b);
        ret += " ";
        ret += '=';
        ret += " ";
        switch(c){
            case '+':
                ret += to_String(a+b);
                //ret[i] += " ";
            break;
            case '-':
                ret += to_String(a-b);
                //ret[i] += " ";
            break;
            case '*':
                ret += to_String(a*b);
                //ret[i] += " ";
            break;

        }
        cout<<ret<<endl;

    }

    return 0;
}
