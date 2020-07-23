#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXN 1000000
#define _match(a,b) ((a)==(b))
typedef char elem_t;
int fail[MAXN]={-1};
char aa[MAXN];
char bb[MAXN];
int pat_match(int st ,int ls,elem_t* str,int lp,elem_t* pat){
    int i=0,j;
    for(i=st,j=0;i<ls&&j<lp;i++){

        if(_match(str[i],pat[j])){
            j++;
        }else if(j){
            j = fail[j-1]+1;
            i--;
        }
    }
    return j==lp?(i-lp):-1;
}
int main()
{

    scanf("%s",aa);
    scanf("%s",bb);

    int i=0,j;
    int lp = strlen(bb);
    int ls = strlen(aa);
    for(j=1;j<lp;j++){
        for(i=fail[j-1];i>=0&&!_match(bb[i+1],bb[j]);i=fail[i]);
        fail[j]=(_match(bb[i+1],bb[j])?i+1:0);
    }

    i=0;
    int counter =0;
    while(i < ls){
        i = pat_match(i,ls,aa,lp,bb);
        if(i!=-1){
            counter++;
            i++;
        }else{
            break;
        }
    }

    cout<<counter<<endl;

    return 0;
}
