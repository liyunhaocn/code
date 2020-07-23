/*带头节点的链表， */
#include<iostream>
using namespace std;
template<class T>
class LinkNode
{
   public:
   T data;          //数据
   LinkNode<T>*link;//指向后继指针的节点
   LinkNode(const T &el,LinkNode<T>*ptr=0)//构造函数
   {
      data=el;
      link=ptr;
   }
};

template<class T>
class LinkList
{
   private:
     LinkNode<T> *head,*tail;  //表头和表尾指针
     LinkNode<T> *prevPtr,*currPtr;//记录表当前遍历位置的指针，由插入和删除操作更新
     int position;

   public:
     LinkList();
     ~LinkList();
     int getSize()const;  //返回链表中的元素个数
     bool isEmpty()const; //链表是否为空
     void reset(int Pos=0);//初始化指针的位置，（第一位数的位置设置为零）
     void next();          //使指针移动到下一个节点
     bool endOfList()const;//指针是否到了链尾
     int  currentPosition(void);//返回指针当前的位置
     void insertHead(const T&item);//在表头插入节点
     void insertTail(const T&item);//在表尾插入节点
     void inserAt(const T&item);   //在当前节点之前插入节点
     void insertAfter(const T&item);//在当前节点之后插入节点
     T deleteHead();                //删除头节点
     void deleteCurrent();          //删除当前节点
     T & data();                    //返回对当前节点成员数据的引用
     const T &data()const;     //返回对当前节点成员数据的常引用
     void clear();            //清空链表，释放所有节点的数据空间
     LinkNode<T> *setPos(int Pos);//返回指定位置pos的指针
     bool insertPos(const int i,const T value);//在指定位置插入节点
     bool deletePos(const int i); //删除指定位置的节点
};

template<class T>
LinkNode<T> * LinkList<T>::setPos(int pos)
{
    if(pos==-1)
    {
      return head;
    }
    int count =0;
    LinkNode<T> *p=head->link;
}

int main()
{
    return 0;
}
