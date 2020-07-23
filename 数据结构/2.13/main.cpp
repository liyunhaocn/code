
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
         bool PopAll();
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
           cout<<"ȱ��������"<<endl;
            return false;
        }
        else
       {
           item= st[top--];
           return true;
       }
    }

    template<class T>
    bool ArrayStack<T>::PopAll()
    {
        T a;
        while(!isEmpty())
        {
         Pop(a);
         cout<<a<<" ";
        }
    }

template<class T>
    bool ArrayStack<T>::Top(T & item)
    {
        if(top==-1)
        {
            cout<<"ȱ��������"<<endl;
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

void peidui()
{
    ArrayStack<char> stack1(40);
    char temp;
    char a;
    cout<<"��������ʽ"<<endl;
    do
    {
       cin>>temp;
       if(temp=='{' || temp=='[' || temp=='(' || temp==')'|| temp==']'|| temp=='}')
       {
             if(temp=='{' || temp=='[' || temp=='(')
             stack1.Push(temp);
             else if(temp==')' )
             {
                 if(stack1.isEmpty())
                {
                  cout<<"ȱ��������"<<endl;
                  break;
                 }
                 else
                 {
                     stack1.Top(a);
                     if(a=='(')
                       stack1.Pop(a);
                     else
                       cout<<"���ʽ����"<<endl;
                 }

             }
             else if(temp==']' )
             {
                  if(stack1.isEmpty())
                 {
                  cout<<"ȱ��������"<<endl;
                  break;
                 }
                 else
                 {
                   stack1.Top(a);
                   if(a=='[')
                    stack1.Pop(a);
                   else
                    cout<<"���ʽ����"<<endl;
                 }
             }
             else if(temp=='}' )
             {
                  if(stack1.isEmpty())
                  {
                    cout<<"ȱ��������"<<endl;
                    break;
                  }
                  else
                 {
                   stack1.Top(a);
                    if(a=='{')
                      stack1.Pop(a);
                    else
                      cout<<"���ʽ����"<<endl;
                }
             }
       }
       else if(temp=='#')
       {
           if(stack1.isEmpty())
           {
             cout<<"���ʽ������ȷ"<<endl;
             break;
           }
           else
           {
                cout<<"ȱ��������"<<endl;
                break;
           }
       }
       else
       {
           cout<<"�������"<<endl;
           goto jieshu;
           break;
       }
    }while(1);

   jieshu:;
}


int main()
{
  peidui();
  return 0;
}
