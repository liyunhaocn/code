
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
    public:
     LinkNode<T> *head,*tail;  //表头和表尾指针
     LinkNode<T> *prevPtr,*currPtr;//记录表当前遍历位置的指针，由插入和删除操作更新
     int position;

    int length;
     LinkList();
     //~LinkList();
     void disp();        //遍历输出链表
     int getSize(LinkNode<T>*p);  //返回链表中的元素个数
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
     T getMaxMember(LinkNode<T>*p);
     T getAverage();


     int sum(LinkNode<T>*p);


};

template<class T>
LinkList<T>::LinkList()
{
    cout<<"创建列表"<<endl;
    head=tail=NULL;
}

template<class T>
void LinkList<T>::insertTail(const T&item)
{
    LinkNode<T>* ptemp;
     ptemp=new LinkNode<T>;
     ptemp->data=item;
	 ptemp->Link=0;
	 if(head==NULL)
     {
        head=tail=ptemp;
	 }

	 else
	 {
         tail->Link=ptemp;
         ptemp->Link=0;
         tail=ptemp;
	 }
     length++;
}


template<class T>
int LinkList<T>::getSize(LinkNode<T>*p)
{
    LinkNode<T> *temp;
    temp=p;
    if(temp->Link==NULL)
        return 1;
    else
    {
        temp=temp->Link;
        return getSize(temp)+1;
    }
}


template<class T>
int LinkList<T>::sum(LinkNode<T>*p)
{
   LinkNode<T> *temp=p;
    if(temp->Link==NULL)
        return temp->data;
    else
    {
        return sum(temp->Link)+temp->data;
    }
}


template<class T>
void LinkList<T>::daozhi()
{
  LinkNode<T>*p1,*p2,*p3;
  cout<<"链表倒置"<<endl;
  if(length==1)
  {
      ;
  }
  else if(length==2)
  {
    tail->Link=head;
    head->Link=0;
    p1=tail;
    tail=head;
    head=p1;
  }
  else if(length>=3)
  {
    p1=head;
    p2=p1->Link;
    p3=p2->Link;
    p2->Link=p1;
    p1->Link=0;
    tail=p1;
    while(p1 && p2 && p3)
    {
     p1=p2;
     p2=p3;
     p3=p3->Link;
     p2->Link=p1;
    }
    head=p2;
  }
}



template<class T>
T LinkList<T>::getMaxMember(LinkNode<T>*p)
{
    LinkNode<T> * temp=p;
    if(temp->Link==NULL)
        return temp->data;
    else
    {
        int a=temp->data;
        temp=temp->Link;
        int b=getMaxMember(temp);
        return a>b?a:b;
    }
}

template<class T>
T LinkList<T>::getAverage()
{
  T sum=0;
   LinkNode<T>*p=head;
   while(p)
   {
     sum+=p->data;
     p=p->Link;
   }
 return sum/length;
}

template<class T>
void LinkList<T>::disp()
{
   LinkNode<T> *p;
   p=head;
   cout<<"遍历链表"<<endl;
   while(p)
   {
      cout<<p->data<<" ";
      p=p->Link;
   }
  cout<<endl<<endl;
}


int main()
{
  LinkList<int> link1;
  link1.insertTail(1);
  link1.insertTail(2);
  link1.insertTail(3);
  link1.insertTail(4);
  link1.insertTail(5);
  link1.insertTail(6);
  link1.insertTail(7);
  link1.insertTail(8);
  link1.disp();
  cout<<"第三题"<<endl;
  link1.daozhi();
  link1.disp();
  cout<<"第四题"<<endl;
  cout<<"链表中最大的元素为"<<link1.getMaxMember(link1.head)<<endl;
  cout<<"链表中元素个数为"<<link1.getSize(link1.head)<<endl;
  cout<<"链表中元素的平均数和为"<<link1.sum(link1.head)<<endl;
  cout<<"链表中元素的平均数为"<<link1.sum(link1.head)/link1.getSize(link1.head)<<endl;
  return 0;
}

