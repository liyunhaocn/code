/*���á���Ȧ��������Ȩ��ͨ����ͼ��һ����С������������
��ν����Ȧ�������ǡ���ȡһȦ��ȥ��Ȧ��Ȩ���ıߡ�������
ִ����һ���裬ֱ��û��ȦΪֹ��������á���Ȧ��������
���Ĵ�Ȩ��ͨ����ͼ��һ����С��������������ϸ�㷨��
���ó���ʵ�������������㷨��ע��Ȧ���ǻ�·��*/


/*˼·:
  �ٽ����еı߽�������,����ʵ��
  ��ȡ���Ѷ�Ԫ�أ�ɾ������һ���㿪ʼ�������ڱ����Ĺ�����ͳ�Ʊ����Ķ��������
      if �����Ľڵ����==ͼ�Ľڵ����  ˵������ͼ������ͨ�ģ�˵��ɾ����ȷ
      else �����Ľڵ����<ͼ�Ľڵ����  ɾ���ߴ��󣬰Ѹղŵĵı��ټӻ�ȥ
        ֱ�����еı߶�ִ���ꡣ

*/
#include <iostream>
#include <queue>
using namespace std;
template<class T>
class MaxHeap
{
private:
	T * heapArray;
	int CurrentSize;
	int MaxSize;
public:
	MaxHeap(int N);
	void BuildHeap();
	bool Insert(T N);
	void RemoveMax();
	void SiftDown(int left);
	void SiftUp(int position);
	bool IsEmpty();
	T GetMax();
};
template<class T>
MaxHeap<T>::MaxHeap(int N)
{
	MaxSize = N;
	heapArray = new T[MaxSize];
	CurrentSize = 0;
}
template<class T>
T MaxHeap<T>::GetMax()
{
	return heapArray[0];
}
template<class T>
bool MaxHeap<T>::IsEmpty()
{
	if(CurrentSize == 0)
		return 1;
	else
		return 0;
}
template<class T>
void MaxHeap<T>::RemoveMax()
{
	if (CurrentSize>0)
	{
		CurrentSize--;
		heapArray[0] = heapArray[CurrentSize];
		SiftDown(0);
	}
	else
	{
		cout<<"�ѿ�"<<endl;
	}
}
template<class T>
void MaxHeap<T>::BuildHeap()
{
	for (int i = CurrentSize/2-1 ; i >=0 ; i--)
	{
		SiftDown(i);
	}
}

template<class T>
void MaxHeap<T>::SiftDown(int left)
{
	int i = left;
	int j = 2*i +1;
	T temp = heapArray[i];
	while (j < CurrentSize)
	{
		if ((j < CurrentSize-1)&&(heapArray[j].weight< heapArray[j+1].weight))
		{
			j++;
		}
		if (temp.weight<heapArray[j].weight)
		{
			heapArray[i] = heapArray[j];
			heapArray[j] = temp;
			i = j;
			j = 2*j + 1;
		}
		else
			break;
	}
	heapArray[i] = temp;
}
template<class T>
void MaxHeap<T>::SiftUp(int position)
{
	int i = position;
	int j = (i-1)/2;
	T temp = heapArray[i];
	while (heapArray[j].weight < heapArray[i].weight)
	{
		temp = heapArray[i];
		heapArray[i] = heapArray[j];
		heapArray[j] = temp;
		i = j;
		j = (i-1)/2;
	}
	heapArray[i] = temp;
}
template<class T>
bool MaxHeap<T>::Insert(T N)
{
	if (CurrentSize<MaxSize)
	{
		CurrentSize++;
		heapArray[CurrentSize-1] = N;
		SiftUp(CurrentSize-1);
		return 1;
	}
	else
	{
		cout<<"Ԫ������"<<endl;
		return 0;
	}
}
template<class T>
class Edge
{
public:
	int start ;
	int over;
	T weight;
	Edge(){start = over = weight =0;}
	Edge(int s,int o,T w){start = s;over = o; weight = w;}
};
template<class T>
class Graph
{
public:
	int vertexNum;
	int edgeNum;
	int * Mark;
	Graph(int verticesNum);
	~Graph();
	//virtual void Create() = 0;
	virtual Edge<T> FirstEdge(int oneVertex) = 0 ;
	virtual Edge<T> NextEdge(Edge<T> oneEdge) = 0;
	virtual int BFS(int v) = 0;
	int VerticesNum(){return vertexNum;}
	int EdgesNum(){return edgeNum;}
	bool IsEdge(Edge<T> oneEdge);
	int StartVertex(Edge<T> oneEdge){return oneEdge.start;}
	int EndVertwx(Edge<T> oneEdge){return oneEdge.over;}
	T Weight(Edge<T> oneEdge){return oneEdge.weight;}
	virtual void SetEdge(int start ,int over ,int weight) = 0;
	virtual void DelEdge(int start ,int over ) = 0 ;
	virtual void Initialize() = 0;
};
template<class T>
Graph<T>::Graph(int verticesNum)
{
	vertexNum = verticesNum;
	edgeNum = 0;
	Mark = new int[vertexNum];
	for (int i = 0 ;i<vertexNum;i++)
	{
		Mark[i] = 0;
	}
}
template<class T>
Graph<T>::~Graph()
{
	delete [] Mark;
}
template<class T>
class AdjGraph:public Graph<T>
{
private:
	int **matrix;
public:

    AdjGraph(int verticesNum):Graph<int>(verticesNum)
    {
	int i , j ;
	matrix = (int **) new int * [this->vertexNum];
	for (i = 0 ; i<this->vertexNum;i++)
	{
		matrix[i] = new int[this->vertexNum];
	}
	for (i = 0 ;i<this->vertexNum;i++)
	{
		for (j = 0 ; j<this->vertexNum;j++)
		{
			matrix[i][j] = 0;//��ʼ��
		}
	}
}
	~AdjGraph();
	Edge<T> FirstEdge(int oneVertex);
	Edge<T> NextEdge(Edge<T> oneEdge);
	void SetEdge(int start ,int over ,int weight);
	void DelEdge(int start ,int over );
	bool IsEdge(Edge<T> oneEdge);
	int BFS(int v);
	void Create(int ** tem,int point,int counter);
	void Initialize();
};
template<class T>
Edge<T> AdjGraph<T>::FirstEdge(int oneVertex)
{
	Edge<T> tmpEdge;
	tmpEdge.start = oneVertex;
	for (int i = 0 ;i<this->vertexNum;i++)
	{
		if (matrix[oneVertex][i]!=0)
		{
			tmpEdge.over = i;
			tmpEdge.weight = matrix[oneVertex][i];
			break;
		}
	}
	return tmpEdge;
}
template<class T>
void  AdjGraph<T>::Initialize()
{
	for (int i =0;i<this->VerticesNum();i++)
	{
		this->Mark[i] = 0;
	}
}
template<class T>
void AdjGraph<T>::Create(int ** tem,int point,int counter)
{
	int m = 0;
	int n = 0;
	int w = 0;
	int count = 0;
	//cout<<"���������"<<endl;
	count=counter;


    int N=point;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(tem[i][j]>0)
            {
                m=i;
		        n=j;
		        w=tem[i][j];
		        SetEdge(m,n,w);
            }
        }
    }
        /*
	for(int i = 0;i<count;i++)
	{
		cin>>m;
		cin>>n;
		cin>>w;
		SetEdge(m,n,w);
	}
	*/
}
template<class T>
int AdjGraph<T>::BFS(int v)
{
	int m = 0;
	queue<int > q;
	this->Mark[v] = 1;
	q.push(v);
	m++;
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		for (Edge<T> e = FirstEdge(v);IsEdge(e);e = NextEdge(e))
		{

			int u = this->Mark[this->EndVertwx(e)];
			if (u == 0)
			{
				m++;
				this->Mark[this->EndVertwx(e)] = 1;
				q.push(this->EndVertwx(e));
			}
		}
	}
	return m;
}
template<class T>
Edge<T> AdjGraph<T>::NextEdge(Edge<T> oneEdge)
{
	Edge<T> tmpEdge;
	tmpEdge.start = oneEdge.start;
	for (int i = oneEdge.over+1;i<this->vertexNum;i++)
	{
		if (matrix[oneEdge.start][i]!=0)
		{
			tmpEdge.over = i;
			tmpEdge.weight = matrix[oneEdge.start][i];
			break;
		}
	}
	return tmpEdge;
}
template<class T>
void AdjGraph<T>::SetEdge(int start ,int over ,int weight)
{
	if (matrix[start][over]==0&&matrix[over][start]==0)
	{
		this->edgeNum++;
	}
	matrix[start][over] = weight;
	matrix[over][start] = weight;
}
template<class T>
bool AdjGraph<T>::IsEdge(Edge<T> oneEdge)
{
	if (oneEdge.weight>0&&oneEdge.weight<9999&&oneEdge.over>=0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
template<class T>
AdjGraph<T>::~AdjGraph()
{
	for (int i = 0;i < this->vertexNum;i++)
	{
		delete [] matrix[i];
	}
	delete [] matrix;
}

template<class T>
void AdjGraph<T>::DelEdge(int start ,int over )
{
	if (matrix[start][over]!=0&&matrix[over][start]!=0)
	{
		this->edgeNum--;
	}
	matrix[start][over] = 0;
	matrix[over][start] = 0;
}
template<class T>
Edge<T> *DestroyCircle(AdjGraph<T> & G)
{
	int n = G.VerticesNum();
	MaxHeap<Edge<T> > q(G.EdgesNum());
	G.Initialize();
	Edge<T> e;
	Edge<T> * MST = new Edge<T>[n-1];
	for (int i =0;i<n;i++)
	{
		for (e = G.FirstEdge(i);G.IsEdge(e);e = G.NextEdge(e))
		{
			if (G.StartVertex(e)<G.EndVertwx(e))
			{
				q.Insert(e);
			}
		}
	}
	while (1)
	{
		if (G.BFS(0) != n)
		{
			G.SetEdge(e.start,e.over,e.weight);
			if (q.IsEmpty())
			{
				break;
			}
		}
		else
		{
			e = q.GetMax();
			G.DelEdge(e.start,e.over);
			q.RemoveMax();
		}
		G.Initialize();
	}
	int count = 0;
	for (int i =0;i<n;i++)
	{
		for (e = G.FirstEdge(i);G.IsEdge(e);e = G.NextEdge(e))
		{
			if (G.StartVertex(e)<G.EndVertwx(e))
			{
				MST[count] = e;
				count++;
			}
		}
	}
	return MST;
}
int main()
{
	int n=6;
	AdjGraph<int >a(n);
	int tem[6][6]={
        {0,6,1,5,0,0},
        {6,0,5,0,3,0},
        {1,5,0,5,6,4},
        {5,0,5,0,0,2},
        {0,3,6,0,0,6},
        {0,0,4,2,6,0},
    };
    int ** pp=new int *[n];
    for(int i=0;i<n;i++)
    {
        pp[i]=new int [n];
    }
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
    {
        pp[i][j]=tem[i][j];
    }
	a.Create(pp,6,10);
	Edge<int > *p = DestroyCircle(a);
	for (int i=0;i<n-1;i++)
	{
		cout<<"start "<<p->start<<endl;
		cout<<"end "<<p->over<<endl;
		cout<<"weight "<<p->weight<<endl<<endl;
		p++;
	}
	return 0;
}
