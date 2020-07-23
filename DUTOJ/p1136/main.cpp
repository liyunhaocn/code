#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
double cosOfTwovector(double x1,double y1,double z1,double x2,double y2,double z2){
    double neiji=0;
    double lengthofa=0;
    double lengthofb=0;
    neiji += (x1*x2);
    neiji += (y1*y2);
    neiji += (z1*z2);
    lengthofa = x1*x1+y1*y1 +z1*z1;
    lengthofa = sqrt(lengthofa);
    lengthofb = x2*x2+y2*y2 +z2*z2;
    lengthofb = sqrt(lengthofb);
    neiji = neiji/lengthofa;
    neiji = neiji/lengthofb;
    return neiji;
}
int main()
{
    int T;
    double x0,y0,z0,r0;
    double x1,y1,z1;
    double x2,y2,z2,r1;
    double x3,y3,z3;
    double angle1;
    double angle2;
    scanf("%d",&T);

    for(int i = 0;i < T;i ++){
        scanf("%lf",&x0);
        scanf("%lf",&y0);
        scanf("%lf",&z0);
        scanf("%lf",&r0);

        scanf("%lf",&x1);
        scanf("%lf",&y1);
        scanf("%lf",&z1);

        scanf("%lf",&x2);
        scanf("%lf",&y2);
        scanf("%lf",&z2);
        scanf("%lf",&r1);

        scanf("%lf",&x3);
        scanf("%lf",&y3);
        scanf("%lf",&z3);
        angle1 = cosOfTwovector(x1-x0,y1-y0,z1-z0,x2-x0,y2-y0,z2-z0);
        angle2 = cosOfTwovector(x3-x2,y3-y2,z3-z2,x0-x2,y0-y2,z0-z2);
        angle1 = acos(angle1);
        angle2 = acos(angle2);

        angle1 = angle1 * r0;
        angle2 = angle2 * r1;
        printf("%.4f\n",angle1 + angle2);
    }
    return 0;
}
