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
//��ʽջ
template<class T>
class ArrayStack
{
    private:
     LinkNode<T> *head,*tail;  //��ͷ�ͱ�βָ��
     LinkNode<T> *prevPtr,*currPtr;//��¼��ǰ����λ�õ�ָ�룬�ɲ����ɾ����������
    public:
         ArrayStack(int size);
         ArrayStack();
         ~ArrayStack();
         void Clear();
         bool Push(const T item);
         bool Pop(T & item);
         T Top();
         bool isEmpty();       //�ж�ջ�Ƿ�Ϊ��
         bool isFull();        //�ж�ջ�Ƿ�����
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
            cout<<"ջΪ�գ����ܵ�ջ"<<endl;
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
            cout<<"ջΪ�գ����ܵ�ջ"<<endl;
        }
        else
        {
          return head->Link->data;
        }
    }


 template<class T>
bool ArrayStack<T>::isEmpty()      //�ж�ջ�Ƿ�Ϊ��
{
     if(head->Link==NULL)
        return true;
      else
        return false;
}

#endif // STACK_H
