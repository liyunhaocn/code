#include<iostream>
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
   void disp();
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
     que=new T[10];
     Front=Rear=0;
     MaxSize=10;
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
     cout<<item<<"�Ѳ������"<<endl;
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
void Queue<T>::disp() //��������
{
  for(int i=Front;(i%MaxSize)<Rear;i++)
  {
       i=i%MaxSize;
       cout<<que[i]<<" ";
  }

  cout<<endl;
}
int main()
{
  cout<<"����"<<endl;
  Queue<int> que1(7);
  int a;
  for(int i=0;i<7;i++)
  que1.EnQueue(i);
  que1.DeQueue(a);
  cout<<a<<endl;
  que1.DeQueue(a);
  cout<<a<<endl;
  que1.DeQueue(a);
  cout<<a<<endl;
  que1.EnQueue(1);
  return 0;
}
