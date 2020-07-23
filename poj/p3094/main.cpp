#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    string a;
    while(1){
        char a[256];
        int sum = 0;
        gets(a);
        if(a[0]=='#')break;
        for(int i=0;i<strlen(a);i++){
            if(a[i]==' '){
                ;
            }else{
                sum += (a[i]-'A'+1)*(i+1);
            }

        }
        cout<<sum<<endl;
    }
    return 0;
}
