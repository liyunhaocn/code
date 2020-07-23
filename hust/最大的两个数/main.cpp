#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct num{
    int n;
    int row;
    num(int n,int row){
        this->n = n;
        this->row = row;
    }
    num(){}

};
bool cmp(num a,num b){
    return a.n > b.n;
}
int main()
{
    int nums[4][5];
    int ret[5][2];
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            scanf("%d",&nums[i][j]);
        }
    }
    for(int i=0;i<5;i++){
        vector<num> ve;
        for(int j=0;j<4;j++){
            ve.push_back( num(nums[j][i],j) );
        }
        sort(ve.begin(),ve.end(),cmp);
        if(ve[0].row > ve[1].row ){
            swap(ve[0],ve[1]);
        }
        ret[i][0] = ve[0].n;
        ret[i][1] = ve[1].n;
    }
    for(int i=0;i<5;i++){
        cout<<ret[i][0]<<" ";
    }
    cout<<endl;
    for(int i=0;i<5;i++){
        cout<<ret[i][1]<<" ";
    }
    cout<<endl;
    return 0;
}
