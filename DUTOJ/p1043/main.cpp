#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int findstr(char str[],char aim[],int n){
     bool flag = true;
     int strLen=strlen(str);
     int aimLen=strlen(aim);
     for(int i=n;i<strLen;i++){
        flag = true;
        for(int j=0;j<aimLen;j++){
            if(aim[j]!=str[i+j]){
                flag = false;
                break;
            }
        }
        if(flag){
            return i;
        }
     }
     return -1;
}
int main()
{
    char str[100000]="hahahahahahah";
    char aim[3][5] ={"0-0","haha","frog"};
    int strLen;
    int counter;
    while(gets(str)!=NULL){
        counter = 0;
        strLen =  strlen(str);
        for(int i=0;i<strLen;){
            if(findstr(str,aim[0],i)==i){
                counter ++;
                i += 2;
            }else if(findstr(str,aim[1],i)==i){
                counter ++;
                i += 2;
            }else if(findstr(str,aim[2],i)==i){
                counter ++;
                i += 4;
            }else{
                i++;
            }
        }
        printf("+%ds\n", counter);
    }


    return 0;
}
