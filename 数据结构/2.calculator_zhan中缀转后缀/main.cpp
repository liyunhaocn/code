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
    else
    {
       cout<<"未知的运算符"<<endl;
       return 0;
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
  int cal_hou();
  void zhong_hou();
};

Calculator::Calculator(string e)
{
    zhong_exp=e;
    hou_exp="";
    cout<<zhong_exp<<endl;
}

void Calculator:: zhong_hou()
{
   char a;
   int i=0;
   char oper;
   while(i<zhong_exp.size()-1)
   {
       a=zhong_exp[i];
       if(a>=48 && a<=57)
       {
         hou_exp+=a;
         i++;
       }
       else if(a=='(' )
       {
          opertor.Push(a);
             i++;
       }
       else if(a==')')
       {
           while(1)
           {
             opertor.Pop(oper);
             if(oper!='(')
             {
                 hou_exp+=oper;
             }
             else
                break;
           }
          i++;

       }
       else
       {
           while(!opertor.isEmpty() && opertor.Top()!='(' && youxianji(a)<=youxianji(opertor.Top()))
           {
             opertor.Pop(oper);
             hou_exp+=oper;
           }
           opertor.Push(a);
           i++;
       }

   }
   while(!opertor.isEmpty())
   {
       opertor.Pop(oper);
       hou_exp+=oper;
   }
cout<<"后缀表达式为"<<hou_exp<<endl;
}

int Calculator::cal_hou()
{
   char a;
   int i=0;
   char n;
   int num;
   int num1,num2,result;
   while(i<hou_exp.size())
   {
       a=hou_exp[i];
       if(a>=48 && a<=57)
       {
           num=hou_exp[i]-48;
           number.Push(num);
           i++;
       }
       else if(a=='+')
       {
           number.Pop(num2);
           number.Pop(num1);
           result=num1+num2;
           number.Push(result);
           i++;
       }
       else if(a=='-')
       {
           number.Pop(num2);
           number.Pop(num1);
           result=num1-num2;
           number.Push(result);
           i++;
       }
       else if(a=='*')
       {
           number.Pop(num2);
           number.Pop(num1);
           result=num1*num2;
           number.Push(result);
           i++;
       }
       else if(a=='/')
       {
           number.Pop(num2);
           number.Pop(num1);
           result=num1/num2;
           number.Push(result);
           i++;
       }
   }
   number.Push(result);
   cout<<"结果为"<<result<<endl;
}

int main()
{
  /*
  Calculator a("(3+5)*5+3-3*5+3*5=");
  a.zhong_hou();
  a.cal_hou();
  */
  //cout<<StringtoInt("34234")<<endl;
  char * str="351534";
  int a=atoi(str);
   cout<<a<<endl;
   cout<<++a<<endl;
  return 0;
}
