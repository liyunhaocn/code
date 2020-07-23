#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

int fan(int a){
    int ret =0;
    for(int i=0;i<8;i++){
        if( a& (1<<(7-i) ))
        ret |= (1<<i);
    }
    return ret;
}

int main()
{
    string s;
    while(cin>>s){
        for(int i=0; i<= s.size()-3; i+=3){

            int a = int(s[i])&0xff;
            int b = int(s[i+1])&0xff;
            int c = int(s[i+2])&0xff;

            a = fan(a);
            b = fan(b);
            c = fan(c);

            int r1 = ((a&0xfc)>>2);
            int r2 = ((a&0x3)<<4) | ((b&0xf0)>>4);
            int r3 = ((b&0x0f)<<2) | ((c&0xc0)>>6);
            int r4 = (c&0x3f);

            printf("%d %d %d %d ",r1,r2,r3,r4);

        }
    }
    return 0;
}
