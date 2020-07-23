#ifndef LINKLIST_H
#define LINKLIST_H
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
     LinkNode<T> *head,*tail;  //��ͷ�ͱ�βָ��
     LinkNode<T> *prevPtr,*currPtr;//��¼��ǰ����λ�õ�ָ�룬�ɲ����ɾ����������
     int position;
public:
    int length;
     LinkList();
     //~LinkList();
     void disp();        //�����������
     int getSize();  //���������е�Ԫ�ظ���
     bool isEmpty()const; //�����Ƿ�Ϊ��
     void reset(int Pos=0);//��ʼ��ָ���λ�ã�����һλ����λ������Ϊ�㣩
     void next();          //ʹָ���ƶ�����һ���ڵ�
     bool endOfList()const;//ָ���Ƿ�����β
     int  currentPosition(void);//����ָ�뵱ǰ��λ��
     void insertHead(const T&item);//�ڱ�ͷ����ڵ�
     void insertTail(const T&item);//�ڱ�β����ڵ�
     void inserAt(const T&item);   //�ڵ�ǰ�ڵ�֮ǰ����ڵ�
     void insertAfter(const T&item);//�ڵ�ǰ�ڵ�֮�����ڵ�
     T deleteHead();                //ɾ��ͷ�ڵ�
     void deleteCurrent();          //ɾ����ǰ�ڵ�
     T & data();                    //���ضԵ�ǰ�ڵ��Ա���ݵ�����
     const T &data()const;     //���ضԵ�ǰ�ڵ��Ա���ݵĳ�����
     void clear();            //��������ͷ����нڵ�����ݿռ�
     LinkNode<T> *setPos(int Pos);//����ָ��λ��pos��ָ��
     bool insertPos(const int i,const T value);//��ָ��λ�ò���ڵ�
     bool deletePos(const int i); //ɾ��ָ��λ�õĽڵ�
     void daozhi();  //��������
     T getMaxMember();
     T getAverage();
};

template<class T>
LinkList<T>::LinkList()
{
    cout<<"�����б�"<<endl;
    LinkNode<T>* ptemp;
    T tmp;
    ptemp=new LinkNode<T>;
    ptemp->Link=0;
    ptemp->data=tmp;
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
   cout<<"��������"<<endl;
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
   LinkList<T>link;
   LinkNode<T>*p11,*p22,*p33;
   p11=p1.head;
   p22=p2.head;
   p33=link.head;
   T data1;
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

#endif // LINKLIST_H
