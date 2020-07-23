#include <iostream>
#include <stdio.h>
using namespace std;

void eight(int n){
    if(n/8){
        eight( n/8);
    }
    printf("%d",n%8);

}
int main()
{
    int n;
    while(scanf("%d",&n) != EOF){
        eight(n);
        cout<<endl;
    }

    return 0;
}
