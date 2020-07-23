#include <iostream>
#include <algorithm>
using namespace std;

int Sum(int a[],int n)
{
    if(n==1)
        return a[0];
    else
        return a[n-1]+Sum(a,n-1);
}

int main()
{
   int a[10]={6,7,8,9,10,1,2,3,4,5};
   int m;
   m=Sum(a,10);
   cout<<m<<endl;
   return 0;
}
