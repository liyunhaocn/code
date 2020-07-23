#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;

int main()
{
    int N;
    int len;
    int temp;
    int min;
    int maxLen;
    while(scanf("%d",&N)!=EOF){
        len = 0;
        min = INT_MIN;
        maxLen = 1;
        for(int i=0;i<N;i ++){
            scanf("%d",&temp);
            if(temp > min){
                len ++;
                maxLen = max(len,maxLen);
            }else{
                len = 1;
            }
            min = temp;
        }
        cout<<(int)maxLen<<endl;
    }

    return 0;
}
