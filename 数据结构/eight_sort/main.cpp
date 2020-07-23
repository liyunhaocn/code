#include <iostream>

using namespace std;

template<class T>
void swap_value(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

//��������ʱ�临�Ӷ�o(n^2)
template<class T>
void insert_sort(T a[], int n)
{
	for (int i = 1; i < n; ++i)
	{
		T temp = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = temp;
	}
}

//ð������ʱ�临�Ӷ�o(n^2)
template<class T>
void bubble_sort(T a[], int n)
{
	for (int i = n - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap_value(a[j], a[j + 1]);
			}
		}
	}
}

//ѡ������ʱ�临�Ӷ�o(n^2)
template<class T>
void select_sort(T a[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		T min = a[i];
		int index = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[j] < min)
			{
				min = a[j];
				index = j;
			}
		}
		a[index] = a[i];
		a[i] = min;
	}
}

//ϣ������ʱ�临�ӶȽ���o(n^2)��o(nlgn)֮��
template<class T>
void shell_sort(T a[], int n)
{
	for (int gap = n / 2; gap >= 1; gap /= 2)
	{
		for (int i = gap; i < n; ++i)
		{
			T temp = a[i];
			int j = i - gap;
			while (j >= 0 && a[j] > temp)
			{
				a[j + gap] = a[j];
				j -= gap;
			}
			a[j + gap] = temp;
		}
	}
}

//��������ʱ�临�Ӷ�o(nlgn)
template<class T>
int _partition(T a[], int left, int right);

template<class T>
void _quick_sort(T a[], int left, int right);

template<class T>
void quick_sort(T a[], int n)
{
	_quick_sort(a, 0, n - 1);
}
template<class T>
void _quick_sort(T a[], int left, int right)
{
	if (left < right)
	{
		int q = _partition(a, left, right);//һ�λ��ֵõ�����λ����λ��
		_quick_sort(a, left, q - 1);//����߽��еݹ����
		_quick_sort(a, q + 1, right);//���ұ߽��еݹ����
	}
}
template<class T>
int _partition(T a[], int left, int right)
{
	T pivot = a[left];//���õ�һ����Ϊ��λ��
	while (left < right)
	{
		while (left < right && a[right] >= pivot)
		{
			--right;
		}
		a[left] = a[right];//���ҵ���Ѱ��һ������λ��С����������������λ��������λ��
		while (left < right && a[left] <= pivot)
		{
			++left;
		}
		a[right] = a[left];//������Ѱ��һ������λ�����������������ղſ�ȱ��λ��
	}
	a[left] = pivot;//����λ�������ȱλ��
	return left;
}

//�鲢����ʱ�临�Ӷ�o(nlgn)
template<class T>
void _merge_sort(T a[], int left, int right);
template<class T>
void _merge(T a[], int left, int mid, int right);

template<class T>
void merge_sort(T a[], int n)
{
	_merge_sort(a, 0, n - 1);
}
template<class T>
void _merge_sort(T a[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		_merge_sort(a, left, mid);//����ߵݹ�鲢����
		_merge_sort(a, mid + 1, right);//���ұߵݹ�鲢����
		_merge(a, left, mid, right);//�����ҹ鲢����
	}
}
template<class T>
void _merge(T a[], int left, int mid, int right)
{
	int length = right - left + 1;
	T *newA = new T[length];//�����ݴ�ԭʼ����
	for (int i = 0, j = left; i <= length - 1; ++i, ++j)
	{
		*(newA + i) = a[j];
	}
	int i = 0;
	int j = mid - left + 1;
	int k = left;
	for (; i <= mid - left && j <= length - 1; ++k)
	{
		if (*(newA + i) < *(newA + j))
		{
			a[k] = *(newA + i);
			++i;
		}
		else
		{
			a[k] = *(newA + j);
			++j;
		}
	}
	//����߻����ұ߶��������������
	while (i <= mid - left)
	{
		a[k++] = *(newA + i);
		++i;
	}
	while (j <= right - left)
	{
		a[k++] = *(newA + j);
		++j;
	}
	delete[] newA;
}

//������ʱ�临�Ӷ�o(nlgn)

template<class T>
void built_max_heap(T a[], int n);
template<class T>
void up_adjust(T a[], int n);
template<class T>
void adjust_node(T a[], int n, int i);

template<class T>
void heap_sort(T a[], int n)
{
	built_max_heap(a, n);//������ʼ�����
	//������βԪ�أ����Խ������ų�βԪ�ص��������һ���ϵ���
	for (int i = n - 1; i >= 1; --i)
	{
		swap_value(a[0], a[i]);
		up_adjust(a, i);
	}
}
//����һ������Ϊn�Ĵ����
template<class T>
void built_max_heap(T a[], int n)
{
	up_adjust(a, n);
}
//�Գ���Ϊn���������һ���ϵ���
template<class T>
void up_adjust(T a[], int n)
{
	//��ÿ��������Ů�ڵ��Ԫ�ر��������Ӻ󵽸��ڵ�λ��
	for (int i = n / 2; i >= 1; --i)
	{
		adjust_node(a, n, i);
	}
}
//�������Ϊi�Ľڵ��ֵ
template<class T>
void adjust_node(T a[], int n, int i)
{
	//�ڵ������Һ���
	if (2 * i + 1 <= n)
	{
		//�Һ��ӵ�ֵ���ڽڵ��ֵ����������
		if (a[2 * i] > a[i - 1])
		{
			swap_value(a[2 * i], a[i - 1]);
		}
		//���ӵ�ֵ���ڽڵ��ֵ����������
		if (a[2 * i - 1] > a[i - 1])
		{
			swap_value(a[2 * i - 1], a[i - 1]);
		}
		//�Խڵ�����Һ��ӵĸ��ڵ���е���
		adjust_node(a, n, 2 * i);
		adjust_node(a, n, 2 * i + 1);
	}
	//�ڵ�ֻ�����ӣ�Ϊ���һ�������Һ��ӵĽڵ�
	else if (2 * i == n)
	{
		//���ӵ�ֵ���ڽڵ��ֵ����������
		if (a[2 * i - 1] > a[i - 1])
		{
			swap_value(a[2 * i - 1], a[i - 1]);
		}
	}
}

//���������ʱ�临�Ӷ�Ϊo(distance(n+radix)),distanceΪλ����nΪ���������radixΪ����
//����������LST�������л�������MST��������������
//���в���radixΪ������һ��Ϊ10��distance��ʾ�������������������λ����nΪ����ĳ���
template<class T>
void lst_radix_sort(T a[], int n, int radix, int distance)
{
	T* newA = new T[n];//�����ݴ�����
	int* count = new int[radix];//���ڼ������򣬱�����ǵ�ǰλ��ֵΪ0 �� radix-1��Ԫ�س��ֵĵĸ���
	int divide = 1;
	//�ӵ�����һλ������һλ
	for (int i = 0; i < distance; ++i)
	{
		//�������鿽����newA������
		for (int j = 0; j < n; ++j)
		{
			*(newA + j) = a[j];
		}
		//������������0
		for (int j = 0; j < radix; ++j)
		{
			*(count + j) = 0;
		}
		for (int j = 0; j < n; ++j)
		{
			int radixKey = (*(newA + j) / divide) % radix; //�õ�����Ԫ�صĵ�ǰ����λ��ֵ
			(*(count + radixKey))++;
		}
		//��ʱcount[]��ÿ��Ԫ�ر������radixKeyλ���ֵĴ���
		//����ÿ��radixKey�������еĽ���λ�ã�λ����ŷ�ΧΪ1-n
		for (int j = 1; j < radix; ++j)
		{
			*(count + j) = *(count + j) + *(count + j - 1);
		}
		//���ü��������ԭ��ʵ��һ���������������������a[]
		for (int j = n - 1; j >= 0; --j)
		{
			int radixKey = (*(newA + j) / divide) % radix;
			a[*(count + radixKey) - 1] = newA[j];
			--(*(count + radixKey));
		}
		divide = divide * radix;
	}
	delete[] newA;
	delete[] count;
}

template<class T>
void printArray(T a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	for (int i = 1; i <= 8; ++i)
	{
		int arr[] = { 5,6,7,8,9,1,2,3,4 };
		cout<<"����ǰ"<<endl;
		printArray(arr, sizeof(arr) / sizeof(arr[0]));
		switch (i)
		{
		case 1:
			insert_sort(arr, sizeof(arr) / sizeof(arr[0]));
			break;
		case 2:
			bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));
			break;
		case 3:
			select_sort(arr, sizeof(arr) / sizeof(arr[0]));
			break;
		case 4:
			shell_sort(arr, sizeof(arr) / sizeof(arr[0]));
			break;
		case 5:
			quick_sort(arr, sizeof(arr) / sizeof(arr[0]));
			break;
		case 6:
			merge_sort(arr, sizeof(arr) / sizeof(arr[0]));
			break;
		case 7:
			heap_sort(arr, sizeof(arr) / sizeof(arr[0]));
			break;
		case 8:
			lst_radix_sort(arr, sizeof(arr) / sizeof(arr[0]), 10, 4);
			break;
		default:
			break;
		}
		cout<<"�����"<<endl;
		printArray(arr, sizeof(arr) / sizeof(arr[0]));
	}
	return 0;
}
