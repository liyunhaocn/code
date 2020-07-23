#include <iostream>
#include <stdio.h>

using namespace std;
int a[100001][3];
int n,q;
int  order[3] = {0,1,2};
int col_offset[3] = {0,0,0};

void disp(int corrpos){
    for(int i=0;i<3*n;i++){
        int row = ( corrpos/3 + col_offset[order[corrpos%3]])%n;
        int col = order[corrpos %3];
        printf("%d%c",a[row][col],i==(3*n-1)?'\n':' ');
        corrpos++;
        corrpos %= 3*n;
    }
}

int main()
{

    int corrpos = 0;

    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i][0]);
        scanf("%d",&a[i][1]);
        scanf("%d",&a[i][2]);
    }
    for(int i=0;i<q;i++){
        //cout<<"corrpos "<<corrpos<<endl;
        //cout<<"fang "<<fang<<endl;
        int chose;
        scanf("%d",&chose);
        if(chose == 1){
            scanf("%d",&chose);
            corrpos -= chose;
            corrpos %= 3*n;
            corrpos += 3*n;
            corrpos %= 3*n;
        }else if(chose==2){
            int cur_col = corrpos%3;
            int t_col = (cur_col+2)%3;
            swap(order[cur_col],order[t_col]);
            if(cur_col>0){
                col_offset[order[cur_col]] = (col_offset[order[cur_col]]+1)%n;
                col_offset[order[t_col]] = (col_offset[order[t_col]]-1 + n)%n;
            }
        }

    }
    disp(corrpos);

    return 0;
}
