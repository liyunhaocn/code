/*实现下图中的Shape层次结构。每个TwoDimensionalShape类应包括成员函数getArea,以计算二维图形的面积。
每个ThreeDimensionalShape类包含成员函数getArea和getVolume,分别计算三维图形的表面积和体积。
编写一个程序，用一个数组存放各种图形类对象，并输出对象得相应信息，
要能判断每个图形到底属于TwoDimensionalShape还是属于ThreeDimenionalShape。
如果某个图形是TwoDimensionalShape就显示其面积，如果某个图形是ThreeDimenionalShape,则显示其面积和体积。*/
#include<iostream>
using namespace std;
class shape
{
public:
	virtual void show()
	{
	   cout<<"这是一个图形"<<endl;
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
	  cout<<"这是一个二维图形"<<endl;
      cout<<"这个二维图形的面积是"<<area<<endl;
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
      cout<<"这是一个圆"<<endl;
      cout<<"这个圆的面积是"<<area<<endl;
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
      cout<<"这是一个正方形"<<endl;
      cout<<"这个正方形的面积是"<<area<<endl;
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
      cout<<"这是三角形"<<endl;
      cout<<"这个三角形的面积是"<<area<<endl;
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
      cout<<"这是球"<<endl;
      cout<<"这个球的表面积面积是"<<s<<endl;
      cout<<"这个球的体积是"<<v<<endl;
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
      cout<<"这是正方体"<<endl;
      cout<<"这个正方体的表面积面积是"<<s<<endl;
      cout<<"这个正方体的体积是"<<v<<endl;
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
