#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    float a,b;
    char c;
    cin>>a;
    cin>>c;
    cin>>b;
    float ret = 0;
    if(c=='+'){
        ret = a + b;
        printf("%.0f%c%.0f=%.0f\n",a,c,b,ret);
    }else if(c=='-'){
        ret = a - b;
        printf("%.0f%c%.0f=%.0f\n",a,c,b,ret);
    }else if(c=='*'){
        ret = a * b;
        printf("%.0f%c%.0f=%.0f\n",a,c,b,ret);
    }else if(c=='/'){
        ret = a / b;
        printf("%.0f%c%.0f=%.2f\n",a,c,b,ret);
    }

    return 0;
}
