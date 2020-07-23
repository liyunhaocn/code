#include <iostream>
#include <stdio.h>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;


int a[1000][1000];
int colpos[1000];
int target = 0;
int n;
bool val(int row,int k){
    for(int i=0;i<row;i++){
        if(colpos[i]==k){
            return false;
        }
    }
    return true;
}
bool findans(int curRow,int curSum){
    if(curRow>=n || curSum>target){
        return false;
    }
    for(int i=0;i<n;i++){
        if(val(curRow,i)){
           if(a[curRow][i]==curSum || curRow==n-1){
                return true;
           }else{
                return findans(curRow+1,curSum-a[curRow][i]);
           }
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d",&n);
        target = 0 ;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
            }
            target += a[i][i];
        }
        //debug(target);
        cout<<findans(0,0)<<endl;
    }
    return 0;
}
