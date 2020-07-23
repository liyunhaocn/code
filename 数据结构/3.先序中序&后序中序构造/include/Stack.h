#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;
template<class T>
class LinkNode
{
   public:
   T data;
   LinkNode<T>* Link;
};
//链式栈
template<class T>
class ArrayStack
{
    private:
     LinkNode<T> *head,*tail;  //表头和表尾指针
     LinkNode<T> *prevPtr,*currPtr;//记录表当前遍历位置的指针，由插入和删除操作更新
    public:
         ArrayStack(int size);
         ArrayStack();
         ~ArrayStack();
         void Clear();
         bool Push(const T item);
         bool Pop(T & item);
         T Top();
         bool isEmpty();       //判断栈是否为空
         bool isFull();        //判断栈是否已满
};
    template<class T>
    ArrayStack<T>::ArrayStack()
    {
        LinkNode<T>* ptemp;
        ptemp=new LinkNode<T>;
        ptemp->Link=0;
        ptemp->data=0;
        head=tail=ptemp;
    }
    template<class T>
    ArrayStack<T>::~ArrayStack()
    {
        ;
    }
    template<class T>
    bool ArrayStack<T>::Push(const T item)
    {
     LinkNode<T>* ptemp;
     ptemp=new LinkNode<T>;
     ptemp->data=item;
	 ptemp->Link=head->Link;
     head->Link=ptemp;
     return true;
    }
    template<class T>
    bool ArrayStack<T>::Pop(T & item)
    {
        LinkNode<T> *p;
        if(head->Link==NULL)
        {
            cout<<"栈为空，不能弹栈"<<endl;
            return false;
        }
        else
        {
          p=head->Link;
          head->Link=p->Link;
          item=p->data;
          delete p;
          return true;
        }
    }

template<class T>
    T ArrayStack<T>::Top()
    {

        if(head->Link==NULL)
        {
            cout<<"栈为空，不能弹栈"<<endl;
        }
        else
        {
          return head->Link->data;
        }
    }


 template<class T>
bool ArrayStack<T>::isEmpty()      //判断栈是否为空
{
     if(head->Link==NULL)
        return true;
      else
        return false;
}

#endif // STACK_H
