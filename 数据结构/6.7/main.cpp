#include <iostream>
/*
����� 2017.12.27 14:32 ��
����һ��ͬʱ�ҵ�n��Ԫ�����Ԫ������СԪ�ص���Ч�㷨����˵������
*/
using namespace std;

int FindMaxAndMin(int a[],int n,int &min,int & max)
{
    min=max=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
        }
        if(a[i]>max)
        {
            max=a[i];
        }
    }
}
int main()
{

    //cout << "Hello world!" << endl;
    int a[10]={5,6,7,8,9,10,1,2,3,4};
    int max;
    int min;
    FindMaxAndMin(a,10,max,min);
    cout<<"max"<<" "<<max<<endl;
    cout<<"min"<<" "<<min<<endl;
    return 0;
}
