#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string.h>
using namespace std;
char atr[1001][1001];
bool visit[1001][1001];
int N;
bool print(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<visit[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}



bool find(int x,int y,int N){
    if(x<0 || x>=N || y<0 || y>=N){
        return false;
    }else if(visit[x][y]){
        return false;
    }
    visit[x][y] = true;
    print();
    if(atr[x][y]=='H'){
       return true;
    }else if(atr[x][y]=='x' ){
        return false;
    }else{
        return find(x+1,y,N)||find(x,y+1,N)||find(x-1,y,N)||find(x,y-1,N);
    }

}


int main()
{
    int T;
    ios::sync_with_stdio(false);
    cin>>T;
    for(int i=0;i<T;i++){

        int mx,my;
        memset(visit,0,sizeof(visit));
        cin>>N;
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                cin>>atr[j][k];
                if(atr[j][k]=='M'){
                    mx = j;
                    my= k;
                }
            }
        }
         if(find(mx,my,N)){
            printf("Y\n");
         }else{
            printf("N\n");
         }

    }
    return 0;
}
