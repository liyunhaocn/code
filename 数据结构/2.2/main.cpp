#include <iostream>
using namespace std;
template <class T>
class ArrayList
{
  public:
      ArrayList(const int size)
      {
          maxSize=size;
          arrayList=new T[maxSize];
          curLen=0;
          position=0;
      }
      ~ArrayList()
      {
        delete [] arrayList;
      }
      void clear()   //清空顺序栈
      {
        delete [] arrayList;
        curLen=0;
        position=0;
        arrayList=new T[maxSize];
      }
      void show()   //输出顺序栈
      {
        for(int i=0;i<curLen;i++)
        {
          cout<<arrayList[i]<<" ";
        }
        cout<<endl;
      }
      int Length();
      bool Append(const T value);           //在表的末尾添加value，表长加一
      bool Insert(const int p, T & value);  //在p位置插入元素value，表长加一
      bool Delete(const int p);             //删除位置p上的元素
      T Deletemin();//习题2.1 删除顺序表中的最小元素，由函数返回被删除元素的值，空出的位置由最后的元素填补
      bool Deletex(const int x);             //删除所有的值为x元素
      bool Delete_st(const int s,const int t);             //删除所有的值为x元素
      bool GetValue(const int p,T& value);//把位置p上的元素返回到value中
      bool SetValue(const int p,const T value);//把位置p上的元素修改为value中
      bool GetPos(int &p,const T value);   //把value元素的位置返回到元素p中

   private:
       T * arrayList;
       int maxSize;
       int curLen;
       int position;
};

template<class T>
    bool ArrayList<T>:: Delete(const int p) //删除位置p上的元素
    {
       if(curLen<=0)
        {
          cout<<"没有元素可供删除"<<endl;
          return false;
        }
        if(p<0 || p>curLen-1)
        {
          cout<<"删除的元素越界"<<endl;
          return false;
        }
        if(p==curLen-1)
        {

         curLen--;
        }
        else
        {
            for(int i=p;i<curLen;i++)
            {
                arrayList[i]=arrayList[i+1];
            }
           curLen--;
        }

        return true;
    }

template<class T>
    T ArrayList<T>:: Deletemin()//习题2.1 删除顺序表中的最小元素，由函数返回被删除元素的值，空出的位置由最后的元素填补
    {
       int flag=0;
       T min;
        for(int i=0;i<curLen-1;i++)
        {
            if(arrayList[i]<arrayList[flag])
            {
              flag=i;
            }
        }
        min=arrayList[flag];
        for(int i=0;i<curLen-1;i++)
        {
          if(arrayList[i]==min)
          {
            arrayList[i]=arrayList[curLen-1];
          }
        }
        return min;

    }

  template<class T>
    bool ArrayList<T>::Deletex(const int x) //删除所有的值为x元素
    {
        int flag=0;
        for(int i=0;i<curLen;i++)
        {
          if(arrayList[i]==x)
          {
            Delete(i);
            i--;
            flag=1;
          }
        }
        if(flag)
        {
          cout<<"删除成功"<<endl;
          return true;
        }
        else
        {
          cout<<"没有该元素"<<endl;
          return false;
        }
    }

  template<class T>
    bool ArrayList<T>::Delete_st(const int s,const int t) //删除元素值为从s到t的所有元素
    {
       int flag=0;
        for(int i=0;i<curLen-1;i++)
        {
          if(arrayList[i]>s && arrayList[i]<t)
          {
            Delete(i);
            i--;
            flag=1;
          }
        }
        if(flag)
        {
         return true;
        }
        else
        {
          return false;
        }
    }

template<class T>
    int ArrayList<T>::Length() //得到顺序栈的长度
    {
       return curLen;
    }

    template<class T>
    bool ArrayList<T>:: Append(const T value)//在表的末尾添加value，表长加一
    {
       if( curLen<=maxSize )
        {
            arrayList[curLen]=value;
            curLen++;
            return true;
        }
       else
       {
          cout<<"超过最大长度，插入失败"<<endl;
          return false;
       }
    }

template<class T>
    bool ArrayList<T>:: Insert(const int p, T & value)//在p位置插入元素value，表长加一
    {

       if( curLen<=maxSize )
        {
            if(p<0 || p>curLen-1)
            {
              cout<<"插入位置越界"<<endl;
              return false;
            }
            else
            {
              for(int i=p+1;i<curLen;i++)
              {
                arrayList[i]=arrayList[i+1];
              }
              arrayList[p]=value;
            }
        }
        else
        {
           cout<<"超过最大长度，插入失败"<<endl;
           return false;
        }

    }
int main()
{
   ArrayList<int>Array1(20);
   Array1.show();
   Array1.Append(1);
   Array1.Append(1);
   Array1.Append(3);
   Array1.Append(4);
   Array1.Append(5);
   Array1.Append(6);
   Array1.Append(7);
   Array1.Append(8);
   Array1.Append(9);
   Array1.Append(10);
   Array1.Append(11);
   Array1.Append(12);
   Array1.show();
   Array1.Deletemin();
   Array1.show();
   Array1.Deletex(12);
   Array1.show();
   Array1.Delete_st(4,7);
   Array1.show();

}


