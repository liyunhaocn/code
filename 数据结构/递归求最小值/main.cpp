#include <iostream>
#include <algorithm>
using namespace std;

int Min(int a[],int n)
{
    if(n==0)
    {
        return a[0];
    }
    else
        return a[n-1]<Min(a,n-1)?a[n-1]:Min(a,n-1);
}

int main()
{
   int a[10]={6,7,8,9,10,1,2,3,4,0};
   int m;
   m=Min(a,10);
   cout<<m<<endl;
   return 0;
}
