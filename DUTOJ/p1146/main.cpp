#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int a[100000][2];

struct student{
    int a;
    int b;
    int sum;
}stu[100000];
bool cmp(student aa,student bb){
    return aa.sum  > bb.sum ;
}
int main()
{
    int n;
    long long sum = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&stu[i].a);
        scanf("%d",&stu[i].b);
        stu[i].sum = abs(stu[i].b - stu[i].a);
    }
    sort(stu,stu+n,cmp);
    int acnt = n/2;
    int bcnt = n/2;
    for(int i=0;i<n;i++){
        if( (bcnt ==0) || (acnt>0 && stu[i].a > stu[i].b) ){
            sum += stu[i].a;
            //cout<<stu[i].a<<endl;
            acnt--;
         }else{
            sum += stu[i].b;
            //cout<<stu[i].b<<endl;
            bcnt --;
         }
    }
    printf("%lld\n",sum);
    return 0;
}
