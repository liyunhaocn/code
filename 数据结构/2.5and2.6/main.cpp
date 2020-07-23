
#include<iostream>
using namespace std;
template<class T>
class LinkNode
{
public:
   T data;
   LinkNode<T>* Link;
};
template<class T>
class LinkList
{
private:
   public:
     LinkNode<T> *head,*tail;  //表头和表尾指针
     LinkNode<T> *prevPtr,*currPtr;//记录表当前遍历位置的指针，由插入和删除操作更新
     int position;
public:
    int length;
     LinkList();
     //~LinkList();
     void disp();        //遍历输出链表
     int getSize();  //返回链表中的元素个数
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
     void daozhi();  //倒置链表
     T getMaxMember();
     T getAverage();
};

template<class T>
LinkList<T>::LinkList()
{
    cout<<"创建列表"<<endl;
    LinkNode<T>* ptemp;
    ptemp=new LinkNode<T>;
    ptemp->Link=0;
    ptemp->data=0;
    head=tail=ptemp;
}

template<class T>
void LinkList<T>::insertTail(const T&item)
{
     LinkNode<T>* ptemp;
     ptemp=new LinkNode<T>;
     ptemp->data=item;
	 ptemp->Link=0;
     tail->Link=ptemp;
     ptemp->Link=0;
     tail=ptemp;
     length++;
}

template<class T>
void LinkList<T>:: insertHead(const T&item)
{
     LinkNode<T>* ptemp;
     ptemp=new LinkNode<T>;
     ptemp->data=item;
	 ptemp->Link=head->Link;
     head->Link=ptemp;
     length++;
}


template<class T>
int LinkList<T>::getSize()
{
   int counter=0;
   LinkNode<T> *currPtr1;
   currPtr1=head->Link;
   while(currPtr1)
   {
     counter++;
     currPtr1=currPtr1->Link;
   }
   length=counter;
  return counter;
}


template<class T>
void LinkList<T>::disp()
{
   LinkNode<T> *p;
   p=head->Link;
   cout<<"遍历链表"<<endl;
   while(p)
   {
      cout<<p->data<<" ";
      p=p->Link;
   }
  cout<<endl<<endl;
}

template<class T>
LinkList<T>* Merge(LinkList<T>&p1,LinkList<T>&p2)
{
   cout<<"合并链表生成新链表"<<endl;
   LinkList<T>link;
   LinkNode<T>*p11,*p22,*p33;
   p11=p1.head->Link;
   p22=p2.head->Link;
   p33=link.head;
   while(p11 && p22)
   {
      if(p11->data<p22->data)
      {
          link.insertHead(p11->data);
          p11=p11->Link;
      }
      else if(p11->data>p22->data)
      {
          link.insertHead(p22->data);
          p22=p22->Link;
      }
      else if(p11->data==p22->data)
      {
          link.insertHead(p22->data);
          link.insertHead(p22->data);
          p22=p22->Link;
          p11=p11->Link;
      }
   }
  link.disp();
}



template<class T>
LinkList<T>* Merge2(LinkList<T>&p1,LinkList<T>&p2)
{
    cout<<"合并链表不生成新链表"<<endl;
   LinkNode<T>*pa,*pb,*pCur;
   pa=p1.head->Link;
   pb=p2.head->Link;
   if(pa->data<pb->data)
   {
       pCur=p1.head;
   }
   else
   {
       pCur=p2.head;
   }
   while(pa && pb)
   {
      if(pa->data<pb->data)
      {
          pCur->Link=pa;
          pCur=pa;
          pa=pa->Link;

      }
      else if(pa->data>pb->data)
      {
          pCur->Link=pb;
          pCur=pb;
          pb=pb->Link;

      }
      else if(pa->data==pb->data)
      {
          pCur->Link=pb;
          pCur=pb;
          pb=pb->Link;
          pCur->Link=pa;
          pCur=pa;
          pa=pa->Link;
      }
   }
   pCur->Link=(pa==NULL)?pb:pa;
  if(p1.getSize()>p2.getSize())
  {
      p1.disp();
  }
  else
  {
      p2.disp();
  }
}


int main()
{
  cout<<"第五题"<<endl;
  LinkList<int> link1,link2;
  link1.insertTail(1);
  link1.insertTail(2);
  link1.insertTail(3);
  link1.insertTail(4);
  link1.disp();
  link2.insertTail(1);
  link2.insertTail(2);
  link2.insertTail(3);
  link2.insertTail(4);
  link2.disp();
  Merge(link1,link2);
  cout<<"第六题"<<endl;
  LinkList<int> link3,link4;
  link3.insertTail(1);
  link3.insertTail(3);
  link3.insertTail(5);
  link3.insertTail(10);
  link3.disp();
  link4.insertTail(3);
  link4.insertTail(6);
  link4.insertTail(8);
  link4.insertTail(10);
  link4.disp();
  Merge2(link3,link4);
  return 0;
}
