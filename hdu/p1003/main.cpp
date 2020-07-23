#include <iostream>
#include <stdio.h>
using namespace std;

int a[100001];


int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        int N;
        scanf("%d",&N);
        for(int j=0;j<N;j++){
            scanf("%d",&a[j]);
        }
        int maxs = 0;
        int maxe = 0;
        int maxsum = 0;
        int sum = 0;
        for(int e=0;e<N;e++){
            sum += a[e];
            if(sum > maxsum){
                maxsum = sum;
                maxe = e;
            }else if(sum < 0){
                maxs = e+1;
                sum = 0;
            }
        }
        cout<<"Case "<<i<<endl;
        cout<<maxsum<<" "<<maxs+1<<" "<<maxe+1<<endl;
        if(i<T){
            cout<<endl;
        }
    }
    return 0;
}
