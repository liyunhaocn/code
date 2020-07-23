
#include<iostream>
using namespace std;
template<class T>
class DLLNode
{
public:
   T data;
   DLLNode<T>* next;
   DLLNode<T>* prev;
};
template<class T>
class LinkList
{

   public:
     DLLNode<T> *head,*tail;  //表头和表尾指针
     DLLNode<T> *prevPtr,*currPtr;//记录表当前遍历位置的指针，由插入和删除操作更新
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
     DLLNode<T> *setPos(int Pos);//返回指定位置pos的指针
     bool insertPos(const int i,const T value);//在指定位置插入节点
     bool deletePos(const int i); //删除指定位置的节点
     bool delete_Pheadofcricle(); //删除循环链表的第一个节点
     void daozhi();  //倒置链表
     void jiou();  //奇偶相分离2.7
     T getMaxMember();
     T getAverage();
};

template<class T>
LinkList<T>::LinkList()
{
    cout<<"创建列表"<<endl;
    DLLNode<T>* ptemp;
    ptemp=new DLLNode<T>;
    ptemp->next=ptemp;
    ptemp->prev=ptemp;
    ptemp->data=0;
    head=tail=ptemp;
}

template<class T>
void LinkList<T>::insertTail(const T&item)
{
     DLLNode<T>* ptemp;
     ptemp=new DLLNode<T>;
     ptemp->data=item;
     ptemp->prev=tail;
	 ptemp->next=head->next;
     tail->next=ptemp;
     tail=ptemp;
     head->next->prev=ptemp;
     length++;
}

template<class T>
void LinkList<T>:: insertHead(const T&item)
{
     DLLNode<T>* ptemp;
     ptemp=new DLLNode<T>;
     ptemp->data=item;
	 ptemp->next=head->next;
	 ptemp->prev=head;
	 head->next->prev=ptemp;
     head->next=ptemp;
     length++;
}


template<class T>
int LinkList<T>::getSize()
{
   int counter=0;
   DLLNode<T> *currPtr1;
   currPtr1=head->next;
   while(currPtr1)
   {
     counter++;
     currPtr1=currPtr1->next;
   }
   length=counter;
   return counter;
}


template<class T>
bool LinkList<T>::delete_Pheadofcricle()
{
    DLLNode<T>*p;
    p=head->next;
    tail->next=p->next;
    delete p;
    tail->next->prev=tail;
    head->next=tail->next;
}


  static int counter1=0;
template<class T>
void LinkList<T>::disp()
{
   DLLNode<T> *p;
   p=head->next;
   cout<<"正向遍历链表"<<endl;
   while(p)
   {
      cout<<p->data<<" ";
      p=p->next;
      counter1++;
      if(counter1==495)
     {
       return;
     }
   }
  cout<<endl<<endl;

}

int main()
{
  cout<<"第七题"<<endl;
  LinkList<int> link1,link2;
  link1.insertTail(1);
  link1.insertTail(2);
  link1.insertTail(3);
  link1.insertTail(4);
  link1.insertTail(5);
  link1.insertTail(6);
  link1.insertTail(7);
  link1.insertTail(8);
  link1.insertTail(9);
  link1.disp();
  counter1=0;
  link1.delete_Pheadofcricle();

  link1.disp();

  return 0;
}
