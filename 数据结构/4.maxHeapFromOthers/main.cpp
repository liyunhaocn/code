#include<iostream>

#define LEFT(i)  (i<<2)
#define RIGHT(i)  ((i<<2)+1)

using namespace std;
void swap(int& small, int& big)
{
     int temp = small;
     small = big;
     big = temp;
}

void heap_adjust(int arr[], int root, int size)
{
	int leftchild = LEFT(root);
	int rightchild = RIGHT(root);
	int largest;

	if ( leftchild <= size && arr[leftchild] > arr[root])
		largest = leftchild;
	else
		largest = root;

	if ( rightchild <= size && arr[rightchild] > arr[root])
		largest = rightchild ;

	/*
	| 上面已经把父节点arr[root]和左右儿子节点做大小比较（arr[leftchild],arr[rightchild]）
	| 当arr[leftchild]或arr[rightchild]大于父节点时，就交换他们的位置，
	| 此时这棵树就是最大堆
	|
	|但还要确保以孩子节点为根的子树也是最大二叉树堆，所以依次比较，也就是递归比较
	*/
	if ( largest != root )
	{
		swap (arr[root], arr[largest]);
		heap_adjust(arr, largest, size);
	}
}

/*
 |序列中从arr[size/2+1]开始一直到arr[size-1]
 |在映射到完全二叉树的过程中都为叶子节点，即都为一颗独立的二叉树
 |且都是只包含一个节点（即自己本身）的完全二叉树
 |
 |所以在建树的时候，从arr[size/2 : 0]反向建树，
 |这样可以确保在对构建完整的二叉树从上至下，从左至右，所遵循的次序
 |与序列中从0 -> (size-1)的循序是对应的。
*/
void build_heap(int arr[], int size)
{
     for (int i = size/2; i >= 0; i-- )
         heap_adjust(arr, i, size);
}

//创建最大堆
int main()
{
    const int size = 10;
    int iarray[size] = {15,3,4,9,25,60,87,88,92,5};
    build_heap(iarray,size-1);

    for (int i = 0; i < size; i++ )
    cout << iarray[i] << " ";

    cin.get();
    return 0;
}
