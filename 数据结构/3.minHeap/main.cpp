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
        minHeap(T *array,int num,int max);//构造函数
        virtual ~minHeap(){};
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
        void moveMin();    // 从堆顶移动最大元素到尾部
        T & removeMin();   //从堆顶删除最大元素

};

template<class T>
minHeap<T>::minHeap(T *array,int num,int max=20)//构造函数
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
void minHeap<T>::buildHeap()             //建立最大堆
{
    for(int i=(currentSize-1)/2;i>=0;i--)
    {
        siftDown(i);
    }
}

template<class T>
bool minHeap<T>::isLeaf(int pos)const      //判断是否为叶子
{
  if(pos>(currentSize-1/2))
  {
      return true;
  }
  else
    return false;
}

template<class T>
int minHeap<T>::leftChild(int pos)const    //返回左孩子的位置
{
    return pos*2+1;
}

template<class T>
int minHeap<T>::rightChild(int pos)const          //返回右孩子的位置
{
   return pos*2+2;
}

template<class T>
int minHeap<T>::parent(int pos)const       //返回父节点的位置
{
   return (pos-1)/2;
}

template<class T>
bool minHeap<T>::remove(int pos,T & node)  //删除给定下标的元素
{

}

template<class T>
void minHeap<T>::siftDown(int i)        //筛选法函数，参数left表示开始处理的数组下标
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
void minHeap<T>::siftUp(int i)      //从position开始向上调整，使序列成为堆
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
bool minHeap<T>::insert(const T&newNode)  //向堆中插入新元素newNode
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
void minHeap<T>::moveMin()    // 从堆顶移动最大元素到尾部
{
    T temp = heapArray[0];
    heapArray[0] = heapArray[currentSize - 1];
    heapArray[currentSize - 1] = temp;

}

template<class T>
T & minHeap<T>::removeMin()   //从堆顶删除最大元素
{
    moveMin();
    currentSize --;
    int i = 0;
    siftDown(i);
}


int main()
{

    int a[10]={10,9,8,7,6,5,4,3,2,1};
    cout<<"最小堆"<<endl;
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
