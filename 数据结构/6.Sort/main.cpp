#include <iostream>
/*
2017��12��22������ ���� ����� �����㷨

*/
using namespace std;
//������������λ�õ�Ԫ��,ǰ���Ǵ��������û��Խ��
template<class T>
void Swap(T data[],int i,int j)
{
    T temp;
    temp=data[i];
    data[i]=data[j];
    data[j]=temp;
}
//�����������
template<class T>
void disp(T data[],int n)
{
    for(int i=0;i<n;i++)
        cout<<data[i]<<" ";
    cout<<endl;
}

//ֱ�Ӳ�������
template<class T>
void InsertionSort(T Data[],int n)
{
    T temp;
    int j;
    for(int i=1;i<n;i++)
    {
       j=i;
       temp=Data[i];
       //cout<<"temp"<<temp<<endl;
       while(Data[j-1]> temp && j>0)
       {
           Data[j]=Data[j-1];
           j--;
       }
       Data[j]=temp;
    }
}

//�۰��������
template<class T>
void BinaryInsertionSort(T Data[],int n)
{
    T temp;
    int i,left,right,mid;
    for(int i=1;i<n;i++)
    {
       temp=Data[i];
       left=0;
       right=i-1;
       while(left<=right)
       {
           mid=(left+right)/2;
           if(Data[mid]<=temp)
           {
             left=mid+1;
           }
           else
           {
             right=mid-1;
           }
       }
       for(int j=i;j>left;j--)
       {
           Data[j]=Data[j-1];
       }
       Data[left]=temp;
    }
}


//ϣ������
template<class T>
void ShellSort(T Data[],int n)
{
    int d,j;
    T temp;
    d=n/2;
    while(d>=1)
    {
        for(int i=0;i<d;i++)
        {
            for(int k=i+d;k<n;k+=d)
            {
                temp=Data[k];
                j=k-d;
                while(Data[j]>temp && j>=i)
                {
                 Data[j+d]=Data[j];
                 j-=d;
                }
                Data[j+d]=temp;
            }
        }
        d/=2;
    }
}

//ð������
template<class T>
void BubbleSort(T Data[],int n)
{
    for(int i=0;i<n-1;i++)
    {
       for(int j=n-1;j>i;j--)
       {
           if(Data[j]<Data[j-1])
           {
               Swap(Data,j,j-1);
           }
       }
    }
}

//��������

template<class T>//�ָ����һ
int PartitionOne(T Data[],int start,int end)
{
   T temp=Data[start];
   while(start<end)
   {
     //cout<<"start"<<start<<endl;
     //cout<<"end"<<end<<endl;
     while(Data[end]>temp && start<end)
     {
       end--;
     }
     Data[start]=Data[end];
     while(Data[start]<=temp && start<end)
     {
       start++;
     }
     Data[end]=Data[start];
   }
   Data[start]=temp;
   //disp(Data,10);
   return start;
}


template<class T>//�ָ���Զ�
int PartitionTwo(T Data[],int start,int end)
{
   int left=start;
   int right=end;
   T temp=Data[start];

   while(left<=right)
   {
     //cout<<"left"<<left<<rightl;
     //cout<<"right"<<right<<rightl;
     while(Data[left]<=temp && left<=right)
     {
       left++;
     }
     while(Data[right]>temp && left<=right)
     {
       right--;
     }
     if(left<right)
     {
       Swap(Data,right,left);
       left++;
       right--;
     }

     //disp(Data,10);
   }
   //Data[right]=temp;
   Swap(Data,right,start);
   disp(Data,9);
   return right;



}
template<class T>
void QuickSortwihPartitionOne(T Data[],int start,int end)
{
    if(start<end)
    {
     int mid=PartitionOne(Data,start,end);
     //cout<<"111111"<<endl;
     //disp(Data,10);
     QuickSortwihPartitionOne(Data,start,mid-1);
     QuickSortwihPartitionOne(Data,mid+1,end);
   }
}

template<class T>
void QuickSortwihPartitionTwo(T Data[],int start,int end)
{
    if(start<end)
    {
     int mid=PartitionTwo(Data,start,end);
     //cout<<"111111"<<endl;
     disp(Data,9);
     QuickSortwihPartitionTwo(Data,start,mid-1);
     QuickSortwihPartitionTwo(Data,mid+1,end);
   }
}
//��ѡ������
template<class T>
void SelectionSort(T Data[],int n)
{
    int Currentmin;
    for(int i=0;i<n-1;i++)
    {
       Currentmin=i;
       for(int j=i+1;j<n;j++)
       {
           if(Data[j]<Data[Currentmin])
           {
               Currentmin=j;
           }
       }
       if(Currentmin!=i)
       {
           Swap(Data,i,Currentmin);
       }
    }
}


//�鲢����
template<class T>//�ϲ������Ӵ�
void Merge(T Data[],int start,int mid,int end)
{
   int len1=mid-start+1;
   int len2=end-mid;
//   cout<<"start"<<start<<endl;
//   cout<<"end"<<end<<endl;
//   cout<<"len1"<<len1<<endl;
//   cout<<"len2"<<len2<<endl;

   int *a1=new T [len1];
   int *a2=new T [len2];
   for(int i=0;i<len1;i++)
   {
       a1[i]=Data[i+start];
   }
   for(int i=0;i<len2;i++)
   {
       a2[i]=Data[i+len1+start];
   }
//   cout<<"a1"<<endl;
//   disp(a1,1);
//   cout<<"a2"<<endl;
//   disp(a2,1);
   int i=0;
   int j=0;
   int k;
   for(k=start;k<=end;k++)
   {
       if(i==len1 || j==len2)
       {
           //cout<<"break֮ǰ"<<k<<endl;
          break;
       }

       else if(a1[i]<=a2[j])
       {
           Data[k]=a1[i];
           i++;
       }
       else
       {
           Data[k]=a2[j];
           j++;
       }
   }
   //cout<<"break֮��"<<k<<endl;
   if(i==len1)
   {
       for(;k<=end;k++)
       {
           Data[k]=a2[j];
           j++;
       }
   }
   else
   {
       for(;k<=end;k++)
       {
           Data[k]=a1[i];
           i++;
       }
   }
}
int i=0;
//�鲢����
template<class T>
void MergeSort(T Data[],int left,int right)
{
    int mid;

    if(left<right)
    {
        mid=(left+right)/2;
        MergeSort(Data,left,mid);
        MergeSort(Data,mid+1,right);
        Merge(Data,left,mid,right);
        //disp(Data,10);
    }

}
int main()
{

    int n=9;//����Ԫ�ظ���
    for (int i = 1; i <= 8; ++i)
	{
	    //cout<<"--------------------------------------------------"<<endl;
	    //cout<<"�����ʼ��"<<endl;
	    int a[]={60,40,120,185,20,135,150,130,45};
        //disp(a,n);
		switch (i)
		{

		    /*
		case 1:
		    cout<<"ֱ�Ӳ�������"<<endl;
			InsertionSort(a, n);
			disp(a,n);
			cout<<endl;
			break;
		case 2:
            cout<<"�۰��������"<<endl;
			BinaryInsertionSort(a, n);
			disp(a,n);
			cout<<endl;
			break;
		case 3:
            cout<<"ϣ������"<<endl;
			ShellSort(a, n);
			disp(a,n);
			cout<<endl;
			break;
		case 4:
			cout<<"ð������"<<endl;
			BubbleSort(a, n);
			disp(a,n);
			cout<<endl;
			break;
		case 5:
			cout<<"��������&��һ�ַָ����"<<endl;
			QuickSortwihPartitionOne(a,0,n-1);
			disp(a,n);
			cout<<endl;
			break;
			*/
		case 6:
			cout<<"��������&�ڶ��ַָ����"<<endl;
			QuickSortwihPartitionTwo(a,0,n-1);
			disp(a,n);
			cout<<endl;
			break;
			/*
		case 7:
			cout<<"��ѡ������"<<endl;
			SelectionSort(a, n);
			disp(a,n);
			cout<<endl;
			break;
		case 8:
			cout<<"�鲢����"<<endl;
			MergeSort(a,0,9);
			disp(a,10);
			cout<<endl;
			break;*/
		default:
			break;
		}

	}
    return 0;
}
