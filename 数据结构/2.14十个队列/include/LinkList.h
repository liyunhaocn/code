#ifndef LINKLIST_H
#define LINKLIST_H
#include<iostream>
using namespace std;
template<class T1>
class LinkNode
{
public:
   T1 data;
   LinkNode<T1>* Link;
};
template<class T1>
class LinkList
{
    public:
     LinkNode<T1> *head,*tail;  //��ͷ�ͱ�βָ��
     LinkNode<T1> *prevPtr,*currPtr;//��¼��ǰ����λ�õ�ָ�룬�ɲ����ɾ����������
     int position;

    int length;
     LinkList();
     //~LinkList();
     void disp();        //�����������
     int getSize(LinkNode<T1>*p);  //���������е�Ԫ�ظ���
     bool isEmpty()const; //�����Ƿ�Ϊ��
     void reset(int Pos=0);//��ʼ��ָ���λ�ã�����һλ����λ������Ϊ�㣩
     void next();          //ʹָ���ƶ�����һ���ڵ�
     bool endOfList()const;//ָ���Ƿ�����β
     int  currentPosition(void);//����ָ�뵱ǰ��λ��
     void insertHead(const T1&item);//�ڱ�ͷ����ڵ�
     void insertTail(const T1&item);//�ڱ�β����ڵ�
     void inserAt(const T1&item);   //�ڵ�ǰ�ڵ�֮ǰ����ڵ�
     void insertAfter(const T1&item);//�ڵ�ǰ�ڵ�֮�����ڵ�
     T1 deleteHead();                //ɾ��ͷ�ڵ�
     void deleteCurrent();          //ɾ����ǰ�ڵ�
     T1 & data();                    //���ضԵ�ǰ�ڵ��Ա���ݵ�����
     const T1 &data()const;     //���ضԵ�ǰ�ڵ��Ա���ݵĳ�����
     void clear();            //��������ͷ����нڵ�����ݿռ�
     LinkNode<T1> *setPos(int Pos);//����ָ��λ��pos��ָ��
     bool insertPos(const int i,const T1 value);//��ָ��λ�ò���ڵ�
     bool deletePos(const int i); //ɾ��ָ��λ�õĽڵ�
     void daozhi();  //��������
     T1 getMaxMember(LinkNode<T1>*p);
     T1 getAverage();
     int sum(LinkNode<T1>*p);


};

template<class T1>
LinkList<T1>::LinkList()
{
    cout<<"�����б�"<<endl;
    head=tail=NULL;
}

template<class T1>
void LinkList<T1>::insertTail(const T1&item)
{
    LinkNode<T1>* ptemp;
     ptemp=new LinkNode<T1>;
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


template<class T1>
int LinkList<T1>::getSize(LinkNode<T1>*p)
{
    LinkNode<T1> *temp;
    temp=p;
    if(temp->Link==NULL)
        return 1;
    else
    {
        temp=temp->Link;
        return getSize(temp)+1;
    }
}


template<class T1>
int LinkList<T1>::sum(LinkNode<T1>*p)
{
   LinkNode<T1> *temp=p;
    if(temp->Link==NULL)
        return temp->data;
    else
    {
        return sum(temp->Link)+temp->data;
    }
}


template<class T1>
void LinkList<T1>::daozhi()
{
  LinkNode<T1>*p1,*p2,*p3;
  cout<<"������"<<endl;
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



template<class T1>
T1 LinkList<T1>::getMaxMember(LinkNode<T1>*p)
{
    LinkNode<T1> * temp=p;
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

template<class T1>
T1 LinkList<T1>::getAverage()
{
  T1 sum=0;
   LinkNode<T1>*p=head;
   while(p)
   {
     sum+=p->data;
     p=p->Link;
   }
 return sum/length;
}

template<class T1>
void LinkList<T1>::disp()
{
   LinkNode<T1> *p;
   p=head;
   cout<<"��������"<<endl;
   while(p)
   {
      (p->data).disp();
      p=p->Link;
   }
  cout<<endl<<endl;
}

#endif // LINKLIST_H
