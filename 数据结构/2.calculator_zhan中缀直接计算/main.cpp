/*
  只能计算十以内包括括号的加减乘除
  后续完善大数计算
*/

#include<iostream>
#include<string.h>
 #include <stdlib.h>
using namespace std;
//字符串转换为数字，递归实现
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
//判断优先级
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
        cout<<"未知的运算符"<<endl;
        return -1;
    }
}
//链式栈的节点
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

//计算器类
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
   cout<<"中缀表达式为"<<zhong_exp<<endl;
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
   cout<<"计算结果为"<<result<<endl;
}


int main()
{
    string zhong;
    cout<<"请输入中缀表达式"<<endl;
    cin>>zhong;  //测试字符串  1+2+(3-1)*2+3*3+4/2+3*2-1
    Calculator a(zhong);
    a.cal();
 return 0;
}




