/*��ͷ�ڵ������ */
#include<iostream>
using namespace std;
template<class T>
class LinkNode
{
   public:
   T data;          //����
   LinkNode<T>*link;//ָ����ָ��Ľڵ�
   LinkNode(const T &el,LinkNode<T>*ptr=0)//���캯��
   {
      data=el;
      link=ptr;
   }
};

template<class T>
class LinkList
{
   private:
     LinkNode<T> *head,*tail;  //��ͷ�ͱ�βָ��
     LinkNode<T> *prevPtr,*currPtr;//��¼��ǰ����λ�õ�ָ�룬�ɲ����ɾ����������
     int position;

   public:
     LinkList();
     ~LinkList();
     int getSize()const;  //���������е�Ԫ�ظ���
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
