#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    int n;
    string a = "hellodutacm";
    scanf("%d",&n);
    for(int j=0;j<11;j++){
        for(int i=0;i<n;i++){
            printf("%c",a[j]);
        }
        printf("\n");
    }


    return 0;
}
