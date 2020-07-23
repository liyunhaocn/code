
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
     LinkNode<T> *head,*tail;  //��ͷ�ͱ�βָ��
     LinkNode<T> *prevPtr,*currPtr;//��¼��ǰ����λ�õ�ָ�룬�ɲ����ɾ����������
     int position;

    int length;
     LinkList();
     //~LinkList();
     void disp();        //�����������
     int getSize(LinkNode<T>*p);  //���������е�Ԫ�ظ���
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
     T getMaxMember(LinkNode<T>*p);
     T getAverage();


     int sum(LinkNode<T>*p);


};

template<class T>
LinkList<T>::LinkList()
{
    cout<<"�����б�"<<endl;
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
   cout<<"��������"<<endl;
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
  cout<<"������"<<endl;
  link1.daozhi();
  link1.disp();
  cout<<"������"<<endl;
  cout<<"����������Ԫ��Ϊ"<<link1.getMaxMember(link1.head)<<endl;
  cout<<"������Ԫ�ظ���Ϊ"<<link1.getSize(link1.head)<<endl;
  cout<<"������Ԫ�ص�ƽ������Ϊ"<<link1.sum(link1.head)<<endl;
  cout<<"������Ԫ�ص�ƽ����Ϊ"<<link1.sum(link1.head)/link1.getSize(link1.head)<<endl;
  return 0;
}

