#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdio.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

void disp(string qian,string zhong){
    //debug(qian)
    //debug(zhong)
    if(zhong.size() == 0){
        return;
    }else if(zhong.size() == 1){
        cout<<zhong[0];
    }else{
        int pos = zhong.find(qian[0]);
        //debug(pos)
        if(  pos > 0 ){
            disp(qian.substr(1,pos),zhong.substr(0,pos) );
        }
        if( pos < zhong.size() -1 ){
            disp( qian.substr(pos+1) , zhong.substr(pos+1));
        }
        cout<<qian[0];
    }
}

int main()
{
    string qian="EKPRZHAYQNMDIBCXUJFTVSLGWO";
    string zhong = "ZRHPAKNMQDIYCUXBFJVTSEGWOL";
    //cin>>zhong;
    //cin>>hou;
    while(cin>>qian && cin>>zhong ){
    //debug(qian.size())
        disp(qian ,zhong);
        cout<<endl;
    }

    return 0;
}
