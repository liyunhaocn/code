/*
  ����� 2017.12.26  23:10
  ��Ʋ�ʵ��һ����Ч�Ķ�n���������ŵ��㷨��
  ʹ�����и���λ�ڷǸ���֮ǰ�������㷨���ܵķ�����

  ˼·�����������һ�ַָ���ԣ�leftɨ����Ԫ�ض�ҪС�ڣ�
  �����С���㣬�ʹ��ұߵ�right��һ����֮������
  ֱ��left=right;
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
