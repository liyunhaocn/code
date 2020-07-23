#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

int monDay[2][13]={
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};
int isrun(int y){
    if(y%100 ==0 ){
        return ( y%400 == 0);
    }else{
        return ( y%4 == 0);
    }
}

int main()
{
    int y;
    int n;
    while(scanf("%d%d" , &y,&n) != EOF){
        int ry = isrun(y);
        for(int i=0;i<13;i++){
            n -= monDay[ry][i];
            if( n <= 0 ){
                printf("%04d-%02d-%02d\n",y,i,n + monDay[ry][i]);
                break;
            }
        }
    }
    return 0;
}
