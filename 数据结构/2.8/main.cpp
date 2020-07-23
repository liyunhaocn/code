
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
     bool delete_Pheadofcricle(); //ɾ��ѭ������ĵ�һ���ڵ�
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
   cout<<"�����������"<<endl;
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
  counter1=0;
  link1.delete_Pheadofcricle();

  link1.disp();

  return 0;
}
