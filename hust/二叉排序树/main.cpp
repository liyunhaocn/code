#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

int main()
{
    int a[100000];
    int N;
    while(scanf("%d",&N) != EOF){
        fill(a,a+100000,-1);
        int pos = 0;
        for(int i = 0;i < N;i ++){
            int temp;
            scanf("%d", &temp);
            int father = 0;
            pos = 0;
            if(pos == 0 && a[pos] == -1){
                a[pos] = temp;
                printf("-1\n");
                continue;
            }
            while(a[pos] != -1){
                father = pos;
                if(a[pos] < temp){
                    pos = pos*2+2;
                }else if(a[pos] > temp){
                    pos = pos = pos*2+1;
                }else{

                }
            }
            a[pos] = temp;
            printf("%d\n",a[father]);
        }
    }
    return 0;
}
