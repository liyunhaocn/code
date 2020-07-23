/*
  ֻ�ܼ���ʮ���ڰ������ŵļӼ��˳�
  �������ƴ�������
*/

#include<iostream>
#include<string.h>
 #include <stdlib.h>
using namespace std;
//�ַ���ת��Ϊ���֣��ݹ�ʵ��
int StringtoInt(string str)
{
    if(str.size()==1)
    {
        return str[0]-48;
    }
    else
    {
      int low=str[str.size()-1]-48;
      str.erase(str.size()-1);
      return low+StringtoInt(str)*10;
    }
}
//�ж����ȼ�
int youxianji(char a)
{
    if(a=='('||a==')')
        return 1;
    else if(a=='+'||a=='-')
        return 2;
    else if(a=='*'||a=='/')
        return 3;
    else if(a=='#')
    {
       return 0;
    }
    else
    {
        cout<<"δ֪�������"<<endl;
        return -1;
    }
}
//��ʽջ�Ľڵ�
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

//��������
class Calculator
{
public:
  ArrayStack<char>opertor;
  ArrayStack<int>number;
  string zhong_exp;
  string hou_exp;
  Calculator(string e);
  int cal();
};

Calculator::Calculator(string e)
{
    zhong_exp=e;
    hou_exp="";
}



int Calculator::cal()
{
   char a;
   int i=0;
   char oper;
   char n;
   int num1,num2,result;
   zhong_exp='#'+zhong_exp+'#';
   cout<<"��׺���ʽΪ"<<zhong_exp<<endl;
   while(i<zhong_exp.size())
   {
       a=zhong_exp[i];
       //cout<<a<<endl;
       if(a=='#')
       {
            //cout<<"000000"<<endl;
           if(opertor.isEmpty())
           {
            opertor.Push(a);
            //cout<<"11111"<<endl;
           }
           else
           {
             while(!opertor.isEmpty() && opertor.Top()!='#')
             {
                 //cout<<"222222"<<endl;
                   opertor.Pop(oper);
                   number.Pop(num2);
                   number.Pop(num1);
                   if(oper=='+')
                   {
                       //cout<<"bbbbbb"<<endl;
                       number.Push(num1+num2);
                   }
                   else if(oper=='-')
                   {
                       //cout<<"ccccc"<<endl;
                       number.Push(num1-num2);
                   }
                   else if(oper=='*')
                   {
                       //cout<<"dddddd"<<endl;
                       number.Push(num1*num2);
                   }
                   else
                   {
                       //cout<<"eeeeee"<<endl;
                       number.Push(num1/num2);
                   }
             }
           }
           i++;
       }
       else if(a>=48 && a<=57)
       {
           //cout<<"44444"<<endl;
         a=a-48;
         number.Push(a);
         i++;
       }
       else if(a=='(')
       {
           //cout<<"55555"<<endl;
          opertor.Push(a);
          i++;
       }
       else if(a==')')
       {
           //cout<<"6666666"<<endl;
           while(1)
           {
               //cout<<"777777"<<endl;
             oper=opertor.Top();
             if(oper!='(')
             {
                 //cout<<"88888"<<endl;
                 opertor.Pop(oper);
                 number.Pop(num2);
                 number.Pop(num1);
                 if(oper=='+')
                   {
                       //cout<<"bbbbbb"<<endl;
                       number.Push(num1+num2);
                   }
                   else if(oper=='-')
                   {
                       //cout<<"ccccc"<<endl;
                       number.Push(num1-num2);
                   }
                   else if(oper=='*')
                   {
                       //cout<<"dddddd"<<endl;
                       number.Push(num1*num2);
                   }
                   else
                   {
                       //cout<<"eeeeee"<<endl;
                       number.Push(num1/num2);
                   }
             }
             else
             {
                opertor.Pop(oper);
                break;
             }

           }
          i++;
       }
       else
       {
           if(youxianji(a)>youxianji(opertor.Top()))
           {
               //cout<<"999999"<<endl;
               opertor.Push(a);
               i++;
           }
           else
           {
               while(youxianji(a)<=youxianji(opertor.Top()) && opertor.Top()!='#')
               {
                   //cout<<"aaaaaa"<<endl;
                   opertor.Pop(oper);
                   number.Pop(num2);
                   number.Pop(num1);
                   if(oper=='+')
                   {
                       //cout<<"bbbbbb"<<endl;
                       number.Push(num1+num2);
                   }
                   else if(oper=='-')
                   {
                       //cout<<"ccccc"<<endl;
                       number.Push(num1-num2);
                   }
                   else if(oper=='*')
                   {
                       //cout<<"dddddd"<<endl;
                       number.Push(num1*num2);
                   }
                   else
                   {
                       //cout<<"eeeeee"<<endl;
                       number.Push(num1/num2);
                   }
               }
               opertor.Push(a);
               i++;
           }
       }
  }
   //cout<<"ccccc"<<endl;
  number.Pop(result);
   cout<<"������Ϊ"<<result<<endl;
}


int main()
{
    string zhong;
    cout<<"��������׺���ʽ"<<endl;
    cin>>zhong;  //�����ַ���  1+2+(3-1)*2+3*3+4/2+3*2-1
    Calculator a(zhong);
    a.cal();
 return 0;
}




