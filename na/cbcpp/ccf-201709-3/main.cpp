#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d\n ",&m);
    getchar();
    cout<<m<<endl;
    string in_str = "";
    for(int i = 0;i < n ;i ++){
        cout<<"000000000 "<<endl;
        char c = getchar();
        while(c != '\n'){
            in_str += c;
            c = getchar();
        }
        cout<<"111111 "<<in_str<<endl;
    }
    return 0;
}
