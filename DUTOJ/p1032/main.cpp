#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    float x1,y1,x2,y2,x3,y3,r2,a,b;
    while(scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF){

        if((x2-x1)*(x3-x1)+(y2-y1)*(y3-y1)<0)            //（x1，y1）是钝角
        {
            a=(x3+x2)/2.0,b=(y3+y2)/2.0;
            r2=(a-x2)*(a-x2)+(b-y2)*(b-y2);
        }
        else if((x1-x2)*(x3-x2)+(y1-y2)*(y3-y2)<0)        //（x2，y2）是钝角
        {
            a=(x3+x1)/2.0,b=(y3+y1)/2.0;
            r2=(a-x1)*(a-x1)+(b-y1)*(b-y1);
        }
        else if((x1-x3)*(x2-x3)+(y1-y3)*(y2-y3)<0)        //（x3，y3）是钝角
        {
            a=(x2+x1)/2.0,b=(y2+y1)/2.0;
            r2=(a-x1)*(a-x1)+(b-y1)*(b-y1);
        }
        else         //三角形是锐角三角形
        {
            a=((y2-y1)*(y3*y3-y1*y1+x3*x3-x1*x1)-(y3-y1)*(y2*y2-y1*y1+x2*x2-x1*x1))/(2.0*((x3-x1)*(y2-y1)-(x2-x1)*(y3-y1)));
            b=((x2-x1)*(x3*x3-x1*x1+y3*y3-y1*y1)-(x3-x1)*(x2*x2-x1*x1+y2*y2-y1*y1))/(2.0*((y3-y1)*(x2-x1)-(y2-y1)*(x3-x1)));
            r2=(x1-a)*(x1-a)+(y1-b)*(y1-b);
        }
        printf("%.4f\n",sqrt(r2 ));
    }
    return 0;
}
