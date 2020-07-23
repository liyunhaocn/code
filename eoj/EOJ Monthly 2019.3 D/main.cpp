#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int n,m;
    int x1,y1,x2,y2;
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    int ret = 0;
    ret+= abs(x1-x2);
    ret+= abs(y1-y2);
    if(ret%2==0){
        cout<<"Win"<<endl;
    }else{
        cout<<"Lose"<<endl;
    }
    return 0;
}
