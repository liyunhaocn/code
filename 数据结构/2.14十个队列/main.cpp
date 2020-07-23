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
   void Clear();           // 清空队列。
   void disp();           // 清空队列。
   bool IsEmpty();         // 判断队列是否为空。
   bool IsFull();          // 判断队列是否已满
   bool EnQueue(T item);   // 队列的尾部加入元素item。
   bool DeQueue(T& item);  // 取出队列的第一个元素。
   bool GetFront(T& item); // 返回队列的第一个元素，但不移去它
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
bool Queue<T>::IsEmpty()         // 判断队列是否为空。
{
   if(Front==Rear)
      return true;
   else
      return false;
}

template<class T>
bool Queue<T>::IsFull()          // 判断队列是否已满
{
   if(Front==(Rear+1)%MaxSize)
      return true;
   else
      return false;
}

template<class T>
bool Queue<T>::EnQueue(T item)   // 队列的尾部加入元素item。
{
   if(!IsFull())
   {
     que[Rear]=item;
     Rear=(Rear+1)%MaxSize;
     return true;
   }
   else
   {
       cout<<"队列已满不能插入元素"<<endl;
       return false;
   }
}

template<class T>
bool Queue<T>::DeQueue(T& item)  // 取出队列的第一个元素。
{
   if(!IsEmpty())
   {
    item=que[Front];
    Front=(Front+1)%MaxSize;
    return true;
   }
   else
   {
       cout<<"队列已空不能取出元素"<<endl;
       return false;
   }

}

template<class T>
bool Queue<T>::GetFront(T& item) //返回队列的第一个元素，但不移去它
{
  item=que[Front];
}

template<class T>
void Queue<T>::disp() //返回队列的第一个元素，但不移去它
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
      cout<<"队列为空"<<endl;
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
  cout<<"请输入要输入的数据个数"<<endl;
  cin>>n;
  cout<<"输入"<<n<<"个数据(十以内)"<<endl;
  for(int i=0;i<n;i++)
  {
      cin>>data;
      que[data].EnQueue(data);
  }
  for(int i=0;i<10;i++)
  {
         cout<<"队列"<<i<<endl;
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
