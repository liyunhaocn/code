  /*ʵ����ģ�壺
  ������ģ��Array��
  ��1�����а���������������򡢲��Һ���Ԫ�غ͵ķ�����
  ��2��Ȼ���ɴ˲���ģ����Array<int>��Array<Box>��Box��Ҫ��ɱ�Ҫ����������أ���*/
#include<iostream>
#include<string.h>
using namespace std;
class box
{
public:
	double chang,kuan,gao,v;
public:
	box(double a=0,double b=0,double c=0):chang(a),kuan(b),gao(c)
	{
	  v=a*b*c;
	}
	void set(double a,double b,double c)
	{
	  chang=a;
	  kuan=b;
	  gao=c;
	  v=a*b*c;
	}
    void show()
	{
	  cout<<"����һ�����Ϊ"<<v<<"��box"<<endl;
	}
	bool operator<(box t)
	{
	  return v<t.v;
	}
	friend double operator+(double a,box t)
	{
	  return a+t.v;
	}
};
template<class T>
class array
{
public:
	int n;
	T *a;
public:

	array(T b[],int d):a(b),n(d)
	{
	
	}
	void sort(T a[],int n)
	{
	   T temp;
	   int j;
	   for(int i=0;i<n;i++)
	   {
		if(a[i]<a[i-1])
		{
		  temp=a[i];
		  j=i;
		  while(j>0 && temp<a[j-1])
		  {
		    a[j]=a[j-1];
			j--;
		  }
		  a[j]=temp;
		}
	   }
	} 
	T operator [](int k)
	{
	  return a[k];
	}
	double sum()
	{
	      double s=0;
		for(int k=0;k<n;k++)
		{
	        s=s+a[k];
		}
		return s;
	}
};

int main()
{
	int i;
	int a[10]={5,6,7,8,1,2,3,4,10,9};
	box d[10];
	for( i=0;i<10;i++)
	{
	  d[i].set(20-i,19-i,18-i);
	}
	array<int>aa(a,10);
    aa.sort(a,10);
		for(i=0;i<10;i++)
	{
	  cout<<a[i]<<' ';
	}
	cout<<endl;
	cout<<endl;
	cout<<"�����Ԫ��֮��Ϊ"<<aa.sum()<<endl;
	cout<<endl;
	cout<<"�������ĵ�����Ԫ��"<<aa[5]<<endl;
	cout<<endl<<endl<<endl<<endl;
	array<box>dd(d,10);
	dd.sort(d,10);
	for( i=0;i<10;i++)
	{
	   d[i].show();
	}
	cout<<endl;
	cout<<"���ӵ����֮��Ϊ"<<dd.sum()<<endl;
	cout<<endl;
	cout<<"�������ĵ���������Ϊ"<<dd[5].v<<endl;
	
return 0;
}