#include <stdio.h>
#include <math.h>
int ispingfangshu(long long n){
    double sqndouble;
    int sqnint;
    sqndouble = sqrt(n);
    sqnint = (int)sqndouble;
    if(sqnint<sqndouble){
        return 0;
    }else{
        return 1;
    }

}
int main()
{
    long long n;

    while(scanf("%lld",&n)!=EOF){
        if(ispingfangshu(n)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}
