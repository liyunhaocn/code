#ifndef QUEUE_H
#define QUEUE_H
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
    if(!IsEmpty)
    {
        item=que[Front];
        return true;
    }
    else
    {
        cout<<"队列为空"<<endl;
        return false;
    }

}

template<class T>
void Queue<T>::disp()
{
  for(int i=Front;(i%MaxSize)<Rear;i++)
  {
       i=i%MaxSize;
       cout<<que[i]<<" ";
  }

  cout<<endl;
}

#endif // QUEUE_H
