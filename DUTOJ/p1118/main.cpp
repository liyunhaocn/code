#include <iostream>
#include <stdio.h>
using namespace std;
int dis(int a1,int b1,int c1,int a2,int b2,int c2){
    int sum = 0;
    sum += (a1-a2)*(a1-a2);
    sum += (b1-b2)*(b1-b2);
    sum += (c1-c2)*(c1-c2);
    return sum;
}
int point[200][3];
int main()
{
    int n;
    int a,b,c;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&point[i][j]);
        }
    }
    int Max=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(dis(point[i][0],point[i][1],point[i][2],point[j][0],point[j][1],point[j][2])>Max){
                Max = dis(point[i][0],point[i][1],point[i][2],point[j][0],point[j][1],point[j][2]);
            }
        }
    }
    printf("%d\n",Max);
    return 0;
}
