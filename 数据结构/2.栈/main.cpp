
#include<iostream>
using namespace std;
template<class T>
class Stack
{
    public:
        void Clear();  //清空栈
        bool Push(const T item);//栈的压入操作
        bool Pop(T & item);    //读取栈顶的元素并删除
        bool Top(T & item);    //读取栈顶的元素并不删除
        bool isEmpty();       //判断栈是否为空
        bool isFull();        //判断栈是否已满
};
template<class T>
class ArrayStack:public Stack<T>
{
    private:
        int maxSize;
        int top;
        T * st;
    public:
         ArrayStack(int size);
         ArrayStack();
         ~ArrayStack();
         void Clear();
         bool Push(const T item);
         bool Pop(T &item);
         bool Top(T & item);
};

    template<class T>
    ArrayStack<T>::ArrayStack(int size)
    {
        maxSize=size;
        top=-1;
        st=new T[maxSize];
    }

    template<class T>
    ArrayStack<T>::ArrayStack()
    {
        top=-1;
    }

    template<class T>
    ArrayStack<T>::~ArrayStack()
    {
        delete []st;
    }
    template<class T>
    void ArrayStack<T>::Clear()
    {
        top=-1;
    }
    template<class T>
    bool ArrayStack<T>::Push(const T item)
    {
        if(top==maxSize-1)
        {
            cout<<"栈满溢出"<<endl;
            return false;
        }
        else
        {
            st[++top]=item;
            return true;
        }
    }
    template<class T>
    bool ArrayStack<T>::Pop(T &item)
    {
        if(top==-1)
        {
            cout<<"栈为空，不能进行弹栈操作"<<endl;
            return false;
        }
        else
       {
           item= st[top--];
           return true;
       }
    }

    template<class T>
    bool ArrayStack<T>::Top(T & item)
    {
        if(top==-1)
        {
            cout<<"栈为空，不能读取栈顶的元素"<<endl;
            return false;
        }
        else
        {
            item =st[top];
            return true;
        }
    }


int main()
{
  cout<<"栈"<<endl;
  ArrayStack<int> stack1(20);
  stack1.Push(1);
  stack1.Push(2);
  stack1.Push(3);
  stack1.Push(4);
  stack1.Push(5);
  stack1.Push(6);
  stack1.Push(7);
  stack1.Push(8);
  stack1.Push(9);
  stack1.Push(10);
  cout<<""<<endl;
  return 0;
}
