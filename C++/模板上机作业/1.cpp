  /*用函数模板方式设计一个函数模板sort<T>，
   采用插入排序方式对数据进行排序
   可对整数序列、字符序列进行排序。
   可对盒子数组、字符串数组进行排序。*/
#include<iostream>
#include<string.h>
using namespace std;
class box
{
private:
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
	  cout<<"这是一个体积为"<<v<<"的box"<<endl;
	}
	bool operator<(box t)
	{
	  return v<t.v;
	}
};
template<class T>
void sort(T *a,int n)
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
template<>void sort(char a[][20],int n)
{
    char temp[20];
	int j;
	for(int i=0;i<n;i++)
	{
		if(strcmp(a[i],a[i-1])<0)
		{
		  strcpy(temp,a[i]);
		  j=i;
		  while(j>0 && strcmp(temp,a[j-1])<0)
		  {
		    strcpy(a[j],a[j-1]);
			j--;
		  }
		  strcpy(a[j],temp);
		}
	}
}
template<>void sort(box a[],int n)
{
    box temp;
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
int main()
{
	int i;
	int a[10]={5,6,7,8,1,2,3,4,10,9};
	char b[10]={'v','a','c','b','d','e','f','g','z','m'};
	char c[10][20]={"sdjfhlkjhas","sdfdasvc","abcsd","cdef","gihj","mong","skdfj","dfsdc","dfscsdf","dsfcszdf"};
	box d[10];
    for( i=0;i<10;i++)
	{
	  d[i].set(20-i,19-i,18-i);
	}
	sort(a,10);
	sort(b,10);
	sort(c,10);
	sort(d,10);
	for( i=0;i<10;i++)
	{
	  cout<<a[i]<<' ';
	}
	cout<<endl;
    for( i=0;i<10;i++)
	{
	  cout<<b[i]<<' ';
	}
	cout<<endl;
	for( i=0;i<10;i++)
	{
	  cout<<c[i]<<endl;
	}
	cout<<endl;
	for( i=0;i<10;i++)
	{
	   d[i].show();
	}
	cout<<endl;
return 0;
}