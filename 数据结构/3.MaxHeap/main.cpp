#include <iostream>
#include <windows.h>
using namespace std;

template<class T>
class MaxHeap
{
    private:
        T * heapArray;
        int currentSize;
        int maxSize;
    public:
        MaxHeap(T *array,int num,int max);//���캯��
        virtual ~MaxHeap(){};
        void disp();
        void buildHeap();               //��������
        bool isLeaf(int pos)const;      //�ж��Ƿ�ΪҶ��
        int leftChild(int pos)const;    //�������ӵ�λ��
        int rightChild(int pos)const;   //�����Һ��ӵ�λ��
        int parent(int pos)const;       //���ظ��ڵ��λ��
        bool remove(int pos,T & node);  //ɾ�������±��Ԫ��
        void siftDown(int left);        //ɸѡ������������left��ʾ��ʼ����������±�
        void siftUp(int position);      //��position��ʼ���ϵ�����ʹ���г�Ϊ��
        bool insert(const T& newNode);  //����в�����Ԫ��newNode
        void moveMax();    // �ӶѶ��ƶ����Ԫ�ص�β��
        T & removeMax();   //�ӶѶ�ɾ�����Ԫ��

};

template<class T>
MaxHeap<T>::MaxHeap(T *array,int num,int max=20)//���캯��
{
    heapArray=new T [max];
    maxSize=max;
    for(int i=0;i<max;i++)
    {
        heapArray[i]=0;
    }
    for(int i=0;i<num;i++)
    {
        heapArray[i]=array[i];
    }
    currentSize=num;
}

template<class T>
void MaxHeap<T>::disp()
{
 for(int i=0;i<currentSize;i++)
        cout<<heapArray[i]<<" ";
 cout<<endl;
}

template<class T>
void MaxHeap<T>::buildHeap()             //��������
{
    for(int i=currentSize/2-1;i>=0;i--)
    {
        siftDown(i);
    }
}

template<class T>
bool MaxHeap<T>::isLeaf(int pos)const      //�ж��Ƿ�ΪҶ��
{
  if(pos>(currentSize-1/2))
  {
      return true;
  }
  else
    return false;
}

template<class T>
int MaxHeap<T>::leftChild(int pos)const    //�������ӵ�λ��
{
    return pos*2+1;
}

template<class T>
int MaxHeap<T>::rightChild(int pos)const          //�����Һ��ӵ�λ��
{
   return pos*2+2;
}

template<class T>
int MaxHeap<T>::parent(int pos)const       //���ظ��ڵ��λ��
{
   return (pos-1)/2;
}

template<class T>
bool MaxHeap<T>::remove(int pos,T & node)  //ɾ�������±��Ԫ��
{

}

template<class T>
void MaxHeap<T>::siftDown(int left)        //ɸѡ������������left��ʾ��ʼ����������±�
{
   int i=left;
   int j=2*i+1;
   T temp=heapArray[i];
   while(j<currentSize)
   {
       if( (i<currentSize-1) && (heapArray[j]<heapArray[j+1]))
        j++;
       if(temp<heapArray[j])
       {
           heapArray[i]=heapArray[j];
           i=j;
           j=2*j+1;
       }
       else
        break;
   }
   heapArray[i]=temp;
}

template<class T>
void MaxHeap<T>::siftUp(int i)      //��position��ʼ���ϵ�����ʹ���г�Ϊ��
{
    while(i>0){
        int parent = (i-1)/2;
        if(heapArray[i] > heapArray[parent]){
            T temp = heapArray[parent];
            heapArray[parent] = heapArray[i];
            heapArray[i] = temp;
            i = parent;
        }
        else break;
    }

}

template<class T>
bool MaxHeap<T>::insert(const T&newNode)  //����в�����Ԫ��newNode
{
  if(currentSize+1 > maxSize){
        cout<<"�����"<<endl;
        return false;
    }
    currentSize++;
    heapArray[currentSize - 1] = newNode;
    int i = currentSize - 1;
    siftUp(i);
    return true;
}

template<class T>
void MaxHeap<T>::moveMax()    // �ӶѶ��ƶ����Ԫ�ص�β��
{
    T temp = heapArray[0];
    heapArray[0] = heapArray[currentSize - 1];
    heapArray[currentSize - 1] = temp;

}

template<class T>
T & MaxHeap<T>::removeMax()   //�ӶѶ�ɾ�����Ԫ��
{
    moveMax();
    currentSize --;
    int i = 0;
    siftDown(i);
}


int main()
{

    int a[13]={11,10,2,8,9,12,7,1,2,3,4,5,6};
    cout<<"����"<<endl;
    MaxHeap<int> h(a,13);
    h.disp();
    h.buildHeap();
    h.disp();
    h.removeMax();
    h.disp();
    h.removeMax();
    h.disp();
    system("pause");
    return 0;
}
