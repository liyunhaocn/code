#include <iostream>
#include <algorithm>
using namespace std;
void fun2(int a[],int n)
{
    if (n<=1)
    {
        return;
    }
    int low=0,high=n-1;
    while(low<high)
    {
         while(a[low]<0 && low<high)
        {
            low++;
        }
        while(a[high]>0 && low<high)
        {
           high--;
        }
        swap(a[low],a[high]);
    }

}

int main()
{
    int data[6]={5,6,7,1,2,4};
    fun2(data,6);
    for (int i=0;i<6;i++)
    {
        cout<<data[i]<<" ";
    }
    return 0;
}
