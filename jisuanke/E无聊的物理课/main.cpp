#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char a;
    int k;
    char out;
    scanf("%d",&k);
    getchar();
    while(k >= 0){
        scanf("%c",&a);
        if(k == 1){
             out = a;
        }
        if(a!=' '){
           k--;
        }


    }
    printf("%c\n",out);

}
