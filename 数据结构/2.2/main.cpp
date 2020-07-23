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
      void clear()   //���˳��ջ
      {
        delete [] arrayList;
        curLen=0;
        position=0;
        arrayList=new T[maxSize];
      }
      void show()   //���˳��ջ
      {
        for(int i=0;i<curLen;i++)
        {
          cout<<arrayList[i]<<" ";
        }
        cout<<endl;
      }
      int Length();
      bool Append(const T value);           //�ڱ��ĩβ���value������һ
      bool Insert(const int p, T & value);  //��pλ�ò���Ԫ��value������һ
      bool Delete(const int p);             //ɾ��λ��p�ϵ�Ԫ��
      T Deletemin();//ϰ��2.1 ɾ��˳����е���СԪ�أ��ɺ������ر�ɾ��Ԫ�ص�ֵ���ճ���λ��������Ԫ���
      bool Deletex(const int x);             //ɾ�����е�ֵΪxԪ��
      bool Delete_st(const int s,const int t);             //ɾ�����е�ֵΪxԪ��
      bool GetValue(const int p,T& value);//��λ��p�ϵ�Ԫ�ط��ص�value��
      bool SetValue(const int p,const T value);//��λ��p�ϵ�Ԫ���޸�Ϊvalue��
      bool GetPos(int &p,const T value);   //��valueԪ�ص�λ�÷��ص�Ԫ��p��

   private:
       T * arrayList;
       int maxSize;
       int curLen;
       int position;
};

template<class T>
    bool ArrayList<T>:: Delete(const int p) //ɾ��λ��p�ϵ�Ԫ��
    {
       if(curLen<=0)
        {
          cout<<"û��Ԫ�ؿɹ�ɾ��"<<endl;
          return false;
        }
        if(p<0 || p>curLen-1)
        {
          cout<<"ɾ����Ԫ��Խ��"<<endl;
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
    T ArrayList<T>:: Deletemin()//ϰ��2.1 ɾ��˳����е���СԪ�أ��ɺ������ر�ɾ��Ԫ�ص�ֵ���ճ���λ��������Ԫ���
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
    bool ArrayList<T>::Deletex(const int x) //ɾ�����е�ֵΪxԪ��
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
          cout<<"ɾ���ɹ�"<<endl;
          return true;
        }
        else
        {
          cout<<"û�и�Ԫ��"<<endl;
          return false;
        }
    }

  template<class T>
    bool ArrayList<T>::Delete_st(const int s,const int t) //ɾ��Ԫ��ֵΪ��s��t������Ԫ��
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
    int ArrayList<T>::Length() //�õ�˳��ջ�ĳ���
    {
       return curLen;
    }

    template<class T>
    bool ArrayList<T>:: Append(const T value)//�ڱ��ĩβ���value������һ
    {
       if( curLen<=maxSize )
        {
            arrayList[curLen]=value;
            curLen++;
            return true;
        }
       else
       {
          cout<<"������󳤶ȣ�����ʧ��"<<endl;
          return false;
       }
    }

template<class T>
    bool ArrayList<T>:: Insert(const int p, T & value)//��pλ�ò���Ԫ��value������һ
    {

       if( curLen<=maxSize )
        {
            if(p<0 || p>curLen-1)
            {
              cout<<"����λ��Խ��"<<endl;
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
           cout<<"������󳤶ȣ�����ʧ��"<<endl;
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


