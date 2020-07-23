#include <iostream>

using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;


string RemHeadSpace(string s){
    int pos = 0;
    while(pos < s.size() && s[pos]==' '){
        pos++;
    }
    return s.substr(pos);
}
int main()
{

    string line;
    while(getline(cin,line)){
        //cout<<line.length()<<endl;
        if(line.size()==0){
            continue;
        }
        if(line[0]== '#'){
            line = line.substr(1);
            int cnt = 1;
            while(line[0]=='#'){
                line = line.substr(1);
                cnt++;
            }
            cout<<"<h"<< cnt <<">";
            cout<<RemHeadSpace(line);
            cout<<"</h"<< cnt <<">"<<endl;
        }else if(line[0]=='*'){
            cout<<"</ul>"<<endl;
            cout<<"<li>"<<RemHeadSpace(line.substr(1))<<"</li>"<<endl;
            getline(cin,line);
            while(line.size()>0){
                cout<<"<li>"<<RemHeadSpace(line.substr(1))<<"</li>"<<endl;
                getline(cin,line);
            }
            cout<<"</ul>"<<endl;
        }else{
            cout<<"<p>";
            cout<<RemHeadSpace(line);
            getline(cin,line);
            while(line.size()>0){
                cout<<RemHeadSpace(line);
                getline(cin,line);
            }
            cout<<"</p>"<<endl;

        }
    }
    return 0;
}
