#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

int cntdou(string  s){
    int cnt = 0;
    if(s.find(',')==string::npos){
        return 0;
    }else{
        int pos = 0;
        while( (pos=s.find(',',pos))!=-1 ){
            cnt++;
            pos ++;
        }
    }
    return cnt;
}
int main()
{
    int T;
    map<string,int>mp;
    map<string,int>::iterator it;
    mp["double_"]=64;
    mp["long_double_"]=128;
    mp["long_long_"]=64;
    mp["int_"]=32;
    mp["char_"]=8;
    mp["bool_"]=8;

    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int N;
        scanf("%d",&N);
        int cnt = 0;
        for(int i=0;i<N;i++){
            string line;
            cin>>line;
            for(it = mp.begin();it!=mp.end();it++){
                if(line.find(it->first)!=string::npos){
                    cnt += it->second* (cntdou(line)+1);
                    //debug(line);
                    //debug(cntdou(line)+1 )
                }
            }
        }
        printf("%d\n",cnt/8);

    }
    return 0;
}
