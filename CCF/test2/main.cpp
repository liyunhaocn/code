/*ʵ����ͼ�е�Shape��νṹ��ÿ��TwoDimensionalShape��Ӧ������Ա����getArea,�Լ����άͼ�ε������
ÿ��ThreeDimensionalShape�������Ա����getArea��getVolume,�ֱ������άͼ�εı�����������
��дһ��������һ�������Ÿ���ͼ������󣬲�����������Ӧ��Ϣ��
Ҫ���ж�ÿ��ͼ�ε�������TwoDimensionalShape��������ThreeDimenionalShape��
���ĳ��ͼ����TwoDimensionalShape����ʾ����������ĳ��ͼ����ThreeDimenionalShape,����ʾ������������*/
#include<iostream>
using namespace std;
class shape
{
public:
	virtual void show()
	{
	   cout<<"����һ��ͼ��"<<endl;
	}
};
class twodimensionalshape :public shape
{

public:
	double area;
    twodimensionalshape():area(0){};
	virtual void gets()
	{
	  area=0;
	}
	void show()
	{
	  cout<<"����һ����άͼ��"<<endl;
      cout<<"�����άͼ�ε������"<<area<<endl;
	}

};
class threedimensionalshape:public shape
{
public:
	double s,v;
	threedimensionalshape():s(0),v(0){}
    virtual void gets()
    {
     s=0;
    }
   virtual void getv()
   {
    v=0;
   }
};

class circle:public twodimensionalshape
{
public:
   double r;
   circle(double i):r(i){}
   void gets()
   {
	   area=3.1415926*r*r;
   }
   void show()
   {
      cout<<"����һ��Բ"<<endl;
      cout<<"���Բ�������"<<area<<endl;
   }
};
class square:public twodimensionalshape
{
public:
   double d;
   square(double i):d(i){}
   void gets()
   {
	   area=d*d;
   }
   void show()
   {
      cout<<"����һ��������"<<endl;
      cout<<"��������ε������"<<area<<endl;
   }
};
class triangle:public twodimensionalshape
{
public:
   double d;
   double h;
   triangle(double i,double j):d(i),h(j){}
   void gets()
   {
	   area=h*d/2;
   }
   void show()
   {
      cout<<"����������"<<endl;
      cout<<"��������ε������"<<area<<endl;
   }
};

class sphere:public threedimensionalshape
{
public:
   double r;
   sphere(double i):r(i){}
   void getv()
   {
	   v=4/3*3.1415926*r*r*r;
   }
   void gets()
   {
      s=4*3.1415926*r*r;
   }

   void show()
   {
      cout<<"������"<<endl;
      cout<<"�����ı���������"<<s<<endl;
      cout<<"�����������"<<v<<endl;
   }
};

class cube:public threedimensionalshape
{
public:
   double d;
   cube(double i):d(i){}
   void getv()
   {
	   v=d*d*d;
   }
   void gets()
   {
      s=d*d*6;
   }

   void show()
   {
      cout<<"����������"<<endl;
      cout<<"���������ı���������"<<s<<endl;
      cout<<"���������������"<<v<<endl;
   }
};
int main()
{
  circle a(4);
  a.gets();
  square b(4);
  b.gets();
  triangle c(3,4);
  c.gets();
  sphere d(6);
  d.gets();
  d.getv();
  cube e(7);
  e.gets();
  e.getv();
  shape *shows[5];
  shows[0]=&a;
  shows[1]=&b;
  shows[2]=&c;
  shows[3]=&d;
  shows[4]=&e;
  for(int i=0;i<5;i++)
  {
   shows[i]->show();
  }

	return 0;
}
