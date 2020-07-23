#include<iostream>
#include"LinkList.h"
using namespace std;
template<class T>
class Queue
{
private:
    T * que;
    int MaxSize;
    int Rear,Front;
public:
   Queue(int size);
   Queue();
   ~Queue();
   void Clear();           // ��ն��С�
   void disp();           // ��ն��С�
   bool IsEmpty();         // �ж϶����Ƿ�Ϊ�ա�
   bool IsFull();          // �ж϶����Ƿ�����
   bool EnQueue(T item);   // ���е�β������Ԫ��item��
   bool DeQueue(T& item);  // ȡ�����еĵ�һ��Ԫ�ء�
   bool GetFront(T& item); // ���ض��еĵ�һ��Ԫ�أ�������ȥ��
};

template<class T>
Queue<T>::Queue(int size)
{
    MaxSize=size;
    que=new T[MaxSize];
    Front=Rear=0;
}

template<class T>
Queue<T>::Queue()
{
     que=new T[20];
     MaxSize=20;
     Front=Rear=0;
}

template<class T>
Queue<T>::~Queue()
{
     delete []que;
}
template<class T>
void Queue<T>::Clear()
{
     Front=Rear=0;
}

template<class T>
bool Queue<T>::IsEmpty()         // �ж϶����Ƿ�Ϊ�ա�
{
   if(Front==Rear)
      return true;
   else
      return false;
}

template<class T>
bool Queue<T>::IsFull()          // �ж϶����Ƿ�����
{
   if(Front==(Rear+1)%MaxSize)
      return true;
   else
      return false;
}

template<class T>
bool Queue<T>::EnQueue(T item)   // ���е�β������Ԫ��item��
{
   if(!IsFull())
   {
     que[Rear]=item;
     Rear=(Rear+1)%MaxSize;
     return true;
   }
   else
   {
       cout<<"�����������ܲ���Ԫ��"<<endl;
       return false;
   }
}

template<class T>
bool Queue<T>::DeQueue(T& item)  // ȡ�����еĵ�һ��Ԫ�ء�
{
   if(!IsEmpty())
   {
    item=que[Front];
    Front=(Front+1)%MaxSize;
    return true;
   }
   else
   {
       cout<<"�����ѿղ���ȡ��Ԫ��"<<endl;
       return false;
   }

}

template<class T>
bool Queue<T>::GetFront(T& item) //���ض��еĵ�һ��Ԫ�أ�������ȥ��
{
  item=que[Front];
}

template<class T>
void Queue<T>::disp() //���ض��еĵ�һ��Ԫ�أ�������ȥ��
{
  if(!IsEmpty())
  {
      for(int i=Front;(i%MaxSize)<Rear;i++)
      {
       i=i%MaxSize;
       cout<<que[i]<<" ";
      }
  }
  else
  {
      cout<<"����Ϊ��"<<endl;
  }


  cout<<endl;
}
void f()
{
  Queue<int> que[10];
  int a;
  int n;
  int data;
  LinkList<Queue<int> > aa;
  cout<<"������Ҫ��������ݸ���"<<endl;
  cin>>n;
  cout<<"����"<<n<<"������(ʮ����)"<<endl;
  for(int i=0;i<n;i++)
  {
      cin>>data;
      que[data].EnQueue(data);
  }
  for(int i=0;i<10;i++)
  {
         cout<<"����"<<i<<endl;
         que[i].disp();
         if(!que[i].IsEmpty())
         {
             aa.insertTail(que[i]);
         }
  }
  aa.disp();
}
int main()
{
  f();
  return 0;
}
