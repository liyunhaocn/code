
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
         bool isEmpty();       //判断栈是否为空
         bool isFull();        //判断栈是否已满
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


 template<class T>
    bool ArrayStack<T>::isEmpty()      //判断栈是否为空
    {
           if(top==-1)
            return true;
           else
            return false;
    }



    template<class T>
    bool ArrayStack<T>::isFull()       //判断栈是否已满
    {
        if(top==maxSize-1)
            return true;
           else
            return false;
    }
template<class T>
void changeJinZhi(T h,T k)
{
    T a;
    ArrayStack<int> stack1(40);
    while(h/k!=0)
    {
      stack1.Push(h%k);
      h=h/k;
    }
    //if(h%k!=0)
    stack1.Push(h%k);
   while(!stack1.isEmpty())
   {
       stack1.Pop(a);
       cout<<a<<" ";
   }
}

int main()
{

  changeJinZhi(10,3);
  return 0;
}
