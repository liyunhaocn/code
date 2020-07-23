#include <iostream>
#include <string>
#include <stdio.h>
#include <malloc.h>
using namespace std;
string & ClearHeadTailSpace(string &str){
    if (str.empty()){
        return str;
    }
    str.erase(0,str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
return str;
}

int main()
{

    char str[10000];

    gets(str);

    string x = str;
    x = ClearHeadTailSpace(x);

    if(x.length()==0){
        cout<<"0"<<endl;
    }
    else if(x.rfind(" ")>=x.length()){

        cout<<x.length()<<endl;
    }else{
        int pos = x.rfind(" ");
        cout<<x.substr(pos+1).length()<<endl;

    }
    return 0;
}
