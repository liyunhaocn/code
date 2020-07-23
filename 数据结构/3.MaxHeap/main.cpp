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
        MaxHeap(T *array,int num,int max);//构造函数
        virtual ~MaxHeap(){};
        void disp();
        void buildHeap();               //建立最大堆
        bool isLeaf(int pos)const;      //判断是否为叶子
        int leftChild(int pos)const;    //返回左孩子的位置
        int rightChild(int pos)const;   //返回右孩子的位置
        int parent(int pos)const;       //返回父节点的位置
        bool remove(int pos,T & node);  //删除给定下标的元素
        void siftDown(int left);        //筛选法函数，参数left表示开始处理的数组下标
        void siftUp(int position);      //从position开始向上调整，使序列成为堆
        bool insert(const T& newNode);  //向堆中插入新元素newNode
        void moveMax();    // 从堆顶移动最大元素到尾部
        T & removeMax();   //从堆顶删除最大元素

};

template<class T>
MaxHeap<T>::MaxHeap(T *array,int num,int max=20)//构造函数
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
void MaxHeap<T>::buildHeap()             //建立最大堆
{
    for(int i=currentSize/2-1;i>=0;i--)
    {
        siftDown(i);
    }
}

template<class T>
bool MaxHeap<T>::isLeaf(int pos)const      //判断是否为叶子
{
  if(pos>(currentSize-1/2))
  {
      return true;
  }
  else
    return false;
}

template<class T>
int MaxHeap<T>::leftChild(int pos)const    //返回左孩子的位置
{
    return pos*2+1;
}

template<class T>
int MaxHeap<T>::rightChild(int pos)const          //返回右孩子的位置
{
   return pos*2+2;
}

template<class T>
int MaxHeap<T>::parent(int pos)const       //返回父节点的位置
{
   return (pos-1)/2;
}

template<class T>
bool MaxHeap<T>::remove(int pos,T & node)  //删除给定下标的元素
{

}

template<class T>
void MaxHeap<T>::siftDown(int left)        //筛选法函数，参数left表示开始处理的数组下标
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
void MaxHeap<T>::siftUp(int i)      //从position开始向上调整，使序列成为堆
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
bool MaxHeap<T>::insert(const T&newNode)  //向堆中插入新元素newNode
{
  if(currentSize+1 > maxSize){
        cout<<"堆溢出"<<endl;
        return false;
    }
    currentSize++;
    heapArray[currentSize - 1] = newNode;
    int i = currentSize - 1;
    siftUp(i);
    return true;
}

template<class T>
void MaxHeap<T>::moveMax()    // 从堆顶移动最大元素到尾部
{
    T temp = heapArray[0];
    heapArray[0] = heapArray[currentSize - 1];
    heapArray[currentSize - 1] = temp;

}

template<class T>
T & MaxHeap<T>::removeMax()   //从堆顶删除最大元素
{
    moveMax();
    currentSize --;
    int i = 0;
    siftDown(i);
}


int main()
{

    int a[13]={11,10,2,8,9,12,7,1,2,3,4,5,6};
    cout<<"最大堆"<<endl;
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
