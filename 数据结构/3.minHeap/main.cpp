#include <iostream>
#include <windows.h>
using namespace std;

template<class T>
class minHeap
{
    private:
        T * heapArray;
        int currentSize;
        int maxSize;
    public:
        minHeap(T *array,int num,int max);//���캯��
        virtual ~minHeap(){};
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
        void moveMin();    // �ӶѶ��ƶ����Ԫ�ص�β��
        T & removeMin();   //�ӶѶ�ɾ�����Ԫ��

};

template<class T>
minHeap<T>::minHeap(T *array,int num,int max=20)//���캯��
{
    heapArray=new T [max];
    maxSize=max;

    for(int i=0;i<num;i++)
    {
        heapArray[i]=array[i];
    }
    currentSize=num;
}

template<class T>
void minHeap<T>::disp()
{
 for(int i=0;i<currentSize;i++)
        cout<<heapArray[i]<<" ";
 cout<<endl;
}

template<class T>
void minHeap<T>::buildHeap()             //��������
{
    for(int i=(currentSize-1)/2;i>=0;i--)
    {
        siftDown(i);
    }
}

template<class T>
bool minHeap<T>::isLeaf(int pos)const      //�ж��Ƿ�ΪҶ��
{
  if(pos>(currentSize-1/2))
  {
      return true;
  }
  else
    return false;
}

template<class T>
int minHeap<T>::leftChild(int pos)const    //�������ӵ�λ��
{
    return pos*2+1;
}

template<class T>
int minHeap<T>::rightChild(int pos)const          //�����Һ��ӵ�λ��
{
   return pos*2+2;
}

template<class T>
int minHeap<T>::parent(int pos)const       //���ظ��ڵ��λ��
{
   return (pos-1)/2;
}

template<class T>
bool minHeap<T>::remove(int pos,T & node)  //ɾ�������±��Ԫ��
{

}

template<class T>
void minHeap<T>::siftDown(int i)        //ɸѡ������������left��ʾ��ʼ����������±�
{
   while(1){
        int leftchild = 2*i + 1;
        int rightchild = 2*i + 2;
        if(leftchild < currentSize){
            if(rightchild < currentSize && heapArray[leftchild] > heapArray[rightchild]){
                if(heapArray[i] > heapArray[rightchild]){
                T temp = heapArray[i];
                heapArray[i] = heapArray[rightchild];
                heapArray[rightchild] = temp;
                i = rightchild;
                }
                else break;
            }
            else{
                if(heapArray[i] > heapArray[leftchild]){
                T temp = heapArray[i];
                heapArray[i] = heapArray[leftchild];
                heapArray[leftchild] = temp;
                i = leftchild;
                }
                else break;
            }
        }
        else break;
    }

}

template<class T>
void minHeap<T>::siftUp(int i)      //��position��ʼ���ϵ�����ʹ���г�Ϊ��
{
    while(i>0){
        int parent = (i-1)/2;
        if(heapArray[i] < heapArray[parent]){
            T temp = heapArray[parent];
            heapArray[parent] = heapArray[i];
            heapArray[i] = temp;
            i = parent;
        }
        else break;
    }

}

template<class T>
bool minHeap<T>::insert(const T&newNode)  //����в�����Ԫ��newNode
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
void minHeap<T>::moveMin()    // �ӶѶ��ƶ����Ԫ�ص�β��
{
    T temp = heapArray[0];
    heapArray[0] = heapArray[currentSize - 1];
    heapArray[currentSize - 1] = temp;

}

template<class T>
T & minHeap<T>::removeMin()   //�ӶѶ�ɾ�����Ԫ��
{
    moveMin();
    currentSize --;
    int i = 0;
    siftDown(i);
}


int main()
{

    int a[10]={10,9,8,7,6,5,4,3,2,1};
    cout<<"��С��"<<endl;
    minHeap<int> h(a,10);
    h.disp();
    h.buildHeap();

    h.disp();

    h.removeMin();
    h.disp();
    h.removeMin();
    h.disp();
    system("pause");
    return 0;
}
