
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
private:
   public:
     DLLNode<T> *head,*tail;  //��ͷ�ͱ�βָ��
     DLLNode<T> *prevPtr,*currPtr;//��¼��ǰ����λ�õ�ָ�룬�ɲ����ɾ����������
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
     DLLNode<T> *setPos(int Pos);//����ָ��λ��pos��ָ��
     bool insertPos(const int i,const T value);//��ָ��λ�ò���ڵ�
     bool deletePos(const int i); //ɾ��ָ��λ�õĽڵ�
     void daozhi();  //��������
     void jiou();  //��ż�����2.7
     T getMaxMember();
     T getAverage();
};

template<class T>
LinkList<T>::LinkList()
{
    cout<<"�����б�"<<endl;
    DLLNode<T>* ptemp;
    ptemp=new DLLNode<T>;
    ptemp->next=0;
    ptemp->prev=0;
    ptemp->data=0;
    head=tail=ptemp;
}

template<class T>
void LinkList<T>::insertTail(const T&item)
{
    DLLNode<T>* ptemp;
     ptemp=new DLLNode<T>;
     ptemp->data=item;
	 ptemp->next=0;
     tail->next=ptemp;
     ptemp->prev=tail;
     ptemp->next=0;
     tail=ptemp;
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
void LinkList<T>::jiou()
{
    DLLNode<T> *p;
  if(getSize()%2==0)
  {
      p=head->next;
      while(p->next!=tail)
      {
        p->next=p->next->next;
        p=p->next;
      }
      p=tail;
      p->next=p->prev->prev;
      p=p->next;
      while(p->prev->prev!=head)
      {
         p->next=p->prev->prev;
         p=p->next;
      }
      p->next=0;
      tail=p;
      p=head->next;
      while(p->next)
      {
          p->next->prev=p;
          p=p->next;
      }
  }
  else
  {
      p=head->next;
      while(p->next->next!=tail)
      {
        p->next=p->next->next;
        p=p->next;
      }
      p->next=p->next->next;
      p=p->next;
      tail->next=tail->prev;
      p=tail->prev;
      while(p->prev->prev!=head)
      {
         p->next=p->prev->prev;
         p=p->next;
      }
      p->next=0;
      tail=p;
      p=head->next;
      while(p->next)
      {
          p->next->prev=p;
          p=p->next;
      }

  }

}

template<class T>
void LinkList<T>::disp()
{
   DLLNode<T> *p;
   p=head->next;
   cout<<"�����������"<<endl;
   while(p)
   {
      cout<<p->data<<" ";
      p=p->next;
   }
  cout<<endl<<endl;

  cout<<"�������������"<<endl;
  p=tail;
   while(p->prev)
   {
      cout<<p->data<<" ";
      p=p->prev;
   }
  cout<<endl<<endl;

}

int main()
{
  cout<<"������"<<endl;
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
  link1.jiou();
  link1.disp();
  link2.insertTail(1);
  link2.insertTail(2);
  link2.insertTail(3);
  link2.insertTail(4);
  link2.insertTail(5);
  link2.insertTail(6);
  link2.insertTail(7);
  link2.insertTail(8);
  link2.insertTail(9);
  link2.insertTail(10);
  link2.disp();
  link2.jiou();
  link2.disp();
  return 0;
}
