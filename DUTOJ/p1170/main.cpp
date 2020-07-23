#include <iostream>
#include <stdio.h>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n,k;
        scanf("%d%d",&n,&k);
        string s;
        cin>>s;
        int cnt = 0;
        bool flag = false;
        for(int i = n-1;i>=0;i--){
            //debug(cnt);
            //debug(k)
            if(cnt==k){
                s = s.substr(0,i+1);
                if(s.find('1')!= string::npos){
                    printf("Yes\n");
                }else{
                    printf("No\n");
                }
                flag = true;
                break;
            }

            if(s[i]=='0'){
                cnt++;
            }
        }
        //debug(cnt)
        //debug(k)
        if(!flag)
        printf("No\n");

    }
    return 0;
}
