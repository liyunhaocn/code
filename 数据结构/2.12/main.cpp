
#include<iostream>
using namespace std;
template<class T>
class Stack
{
    public:
        void Clear();  //���ջ
        bool Push(const T item);//ջ��ѹ�����
        bool Pop(T & item);    //��ȡջ����Ԫ�ز�ɾ��
        bool Top(T & item);    //��ȡջ����Ԫ�ز���ɾ��
        bool isEmpty();       //�ж�ջ�Ƿ�Ϊ��
        bool isFull();        //�ж�ջ�Ƿ�����
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
         bool isEmpty();       //�ж�ջ�Ƿ�Ϊ��
         bool isFull();        //�ж�ջ�Ƿ�����
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
            cout<<"ջ�����"<<endl;
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
            cout<<"ջΪ�գ����ܽ��е�ջ����"<<endl;
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
            cout<<"ջΪ�գ����ܶ�ȡջ����Ԫ��"<<endl;
            return false;
        }
        else
        {
            item =st[top];
            return true;
        }
    }


 template<class T>
    bool ArrayStack<T>::isEmpty()      //�ж�ջ�Ƿ�Ϊ��
    {
           if(top==-1)
            return true;
           else
            return false;
    }



    template<class T>
    bool ArrayStack<T>::isFull()       //�ж�ջ�Ƿ�����
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
