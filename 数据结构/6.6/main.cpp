/*
  李云皓 2017.12.26  23:10
  设计并实现一个有效的对n个整数重排的算法，
  使得所有负数位于非负数之前，给出算法性能的分析。

  思路：快速排序的一种分割策略，left扫过的元素都要小于，
  如果不小于零，就从右边的right找一个与之交换。
  直到left=right;
*/
#include <iostream>
//#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

void moveMinus(int a[],int n)
{
    int left=0;
    int right=n-1;
    while(left<right)
    {
        while(a[left]<0 && left<right)
            left++;
        while(a[right]>=0 && left<right)
            right--;
         swap(a[left],a[right]);
    }
}
void disp(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{

    int a[10]={1,2,3,4,5,6,7,-3,-9,-10};
    moveMinus(a,10);
    disp(a,10);
    return 0;
}
