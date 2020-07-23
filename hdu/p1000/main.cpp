#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long LL;
int main()
{
    LL a,b;
    cout<<scanf("%lld%lld",&a,&b)<<endl;
    while( scanf("%lld%lld",&a,&b)!=EOF){
        printf("%lld\n",a+b);
    }

    return 0;
}
