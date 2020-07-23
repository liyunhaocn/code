#include <iostream>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <limits>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

struct node{
    double x;
    double y;
    node(double x,double y):x(x),y(y){}
    node():x(0),y(0){}
};

double dis(node& a, node& b){
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

node nodes[100000];

double findw(int N){

    double ret = 1e100;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            double temp = dis(nodes[i] ,nodes[j+N]);
            ret = min(ret,temp);
        }
    }
    return ret;
}
int main()
{
    int T;

    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int N;
        scanf("%d",&N);
        for(int n = 0;n < 2*N;n++){
            scanf("%lf",&nodes[n].x);
            scanf("%lf",&nodes[n].y);
        }
        double ret = findw(N);

        printf("%.3f\n",ret);
    }
    return 0;
}
