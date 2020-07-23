#include <bits/stdc++.h>

using namespace std;

int main()
{

    char s[200];
    cin.getline(s,200);
    for(int i=0;i<200;i++){
        if(s[i] == '\0'){
            break;
        }else if(s[i]!=' '){
            cout<<s[i];
        }
    }
    cout<<endl;
    return 0;
}
