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
	| �����Ѿ��Ѹ��ڵ�arr[root]�����Ҷ��ӽڵ�����С�Ƚϣ�arr[leftchild],arr[rightchild]��
	| ��arr[leftchild]��arr[rightchild]���ڸ��ڵ�ʱ���ͽ������ǵ�λ�ã�
	| ��ʱ�������������
	|
	|����Ҫȷ���Ժ��ӽڵ�Ϊ��������Ҳ�����������ѣ��������αȽϣ�Ҳ���ǵݹ�Ƚ�
	*/
	if ( largest != root )
	{
		swap (arr[root], arr[largest]);
		heap_adjust(arr, largest, size);
	}
}

/*
 |�����д�arr[size/2+1]��ʼһֱ��arr[size-1]
 |��ӳ�䵽��ȫ�������Ĺ����ж�ΪҶ�ӽڵ㣬����Ϊһ�Ŷ����Ķ�����
 |�Ҷ���ֻ����һ���ڵ㣨���Լ���������ȫ������
 |
 |�����ڽ�����ʱ�򣬴�arr[size/2 : 0]��������
 |��������ȷ���ڶԹ��������Ķ������������£��������ң�����ѭ�Ĵ���
 |�������д�0 -> (size-1)��ѭ���Ƕ�Ӧ�ġ�
*/
void build_heap(int arr[], int size)
{
     for (int i = size/2; i >= 0; i-- )
         heap_adjust(arr, i, size);
}

//��������
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
