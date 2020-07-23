#include <iostream>
#include <stdio.h>
#include <math.h>
#define PI 3.1415926

using namespace std;

int main()
{
    int N;

    scanf("%d",&N);
    for(int i = 0;i < N;i++){
        double a,b;
        scanf("%lf%lf",&a,&b);
        double r = sqrt(a*a + b*b);
        cout<<"Property "<<i+1<<": This property will begin eroding in year "<<ceil(PI*r*r/2/50)<<"."<<endl;

    }
    cout<<"END OF OUTPUT."<<endl;
}
