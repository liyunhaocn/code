
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
   cout<<"�ϲ���������������"<<endl;
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
    cout<<"�ϲ���������������"<<endl;
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
  cout<<"������"<<endl;
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
  cout<<"������"<<endl;
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
