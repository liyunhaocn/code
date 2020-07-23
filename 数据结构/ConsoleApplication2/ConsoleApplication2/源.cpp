#include <iostream>
#include <queue>
using namespace std;
const int INFINIT = 999;
const int VISITED = 1;
const int UNVISITED = 0;
template<class EdgeType>
class Edge
{
public:
	int start, end;//�ߵ���ʼ�ڵ㣬��ֹ�ڵ�
	EdgeType weight;//�ߵ�Ȩ�أ�Ӧ�ÿ��Զ���Ϊint��
	Edge()
	{
		start = 0;
		end = 0;
		weight = 0;
	}
	Edge(int st, int en, int w)
	{
		start = st;
		end = en;
		weight = w;
	}
	bool operator > (Edge oneEdge)
	{
		if (weight>oneEdge.weight)
			return true;
		else
			return false;
	}
	bool operator < (Edge oneEdge)
	{
		if (weight<oneEdge.weight)
			return true;
		else
			return false;
	}
};

template<class EdgeType>
class Graph
{
public:
	int vertexNum; //ͼ�нڵ����
	int edgeNum;   //ͼ�бߵĸ���
	int * Mark;    //���ĳ�ڵ��Ƿ񱻷���
	Graph(int verNum)
	{
		this->vertexNum = verNum;
		edgeNum = 0;
		Mark = new int[vertexNum];
		for (int i = 0; i<vertexNum; i++)
		{
			Mark[i] = 0; //��û�б����ʹ�
		}
	}
	~Graph()
	{
		delete[] Mark;
	}
	//virtual Edge<EdgeType> FirstEdge(int oneVertex)=0;
	//virtual Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge)=0;
	int verticesNum()
	{
		return vertexNum;
	}
	int EdgesNum()
	{
		return edgeNum;
	}
	bool isEdge(Edge<EdgeType> oneEdge)
	{
		if (oneEdge.end >= 0 && oneEdge.start >= 0 && oneEdge.weight>0 && oneEdge.start != oneEdge.end)//�ж������������
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int startOfVertex(Edge<EdgeType> oneEdge)
	{
		return oneEdge.start;
	}
	int endOfVertex(Edge<EdgeType> oneEdge)
	{
		return oneEdge.end;
	}
	EdgeType weight(Edge<EdgeType> oneEdge) //����oneEdge��Ȩ��
	{
		return oneEdge.weight;
	}
	//virtual void setEdge(int start,int end,int weight)=0;
	//virtual void deleteEdge(int start,int end)=0;
};

template<class EdgeType>
class AdjGraph : public Graph<EdgeType >
{
private:
	int ** matrix;
public:
	AdjGraph(int verNum) :Graph<EdgeType>(verNum)
	{
		matrix = new int *[verNum];
		for (int i = 0; i<verNum; i++)
		{
			matrix[i] = new int[verNum];
		}
		for (int i = 0; i<verNum; i++)
			for (int j = 0; j<verNum; j++)
			{
				matrix[i][j] = 999;
			}
	}

	AdjGraph(int verNum, int **  a) :Graph<EdgeType>(verNum)
	{
		matrix = new int *[verNum];
		for (int i = 0; i<verNum; i++)
		{
			matrix[i] = new int[verNum];
		}
		for (int i = 0; i<verNum; i++)
			for (int j = 0; j<verNum; j++)
			{

				matrix[i][j] = a[i][j];
			}
	}

	EdgeType getIJ(int i, int j)
	{
		if (i<this->vertexNum && j<this->vertexNum)
			return matrix[i][j];
		else
		{
			cout << "�ڽӾ���Խ��" << endl;
			return 0;
		}

	}
	int EdgesNum()
	{
		int edgeNum = 0;
		for (int i = 0; i<this->vertexNum; i++)
		{
			for (int j = 0; j<this->vertexNum; j++)
				if (matrix[i][j]<999)
					edgeNum++;
		}
		this->edgeNum = edgeNum;
		return edgeNum;
	}
	void disp()
	{
		cout << endl;
		cout << "��ͼ����Ӿ���Ϊ" << endl;
		for (int i = 0; i<this->vertexNum; i++)
		{
			for (int j = 0; j<this->vertexNum; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	~AdjGraph()
	{
		for (int i = 0; i<this->vertexNum; i++)
		{
			matrix[i] = new int[this->vertexNum];
		}
		delete[] matrix;
	}
	Edge<EdgeType> FirstEdge(int oneVer) //���ض���ĵ�һ����
	{
		Edge<EdgeType> tem;
		tem.start = oneVer;
		for (int i = 0; i<this->vertexNum; i++)
		{
			if (matrix[oneVer][i]<999)
			{
				tem.end = i;
				tem.weight = matrix[oneVer][i];
				return tem;
				//break;
			}
		}
		//cout<<"û�з��������ı�"<<endl;
		return;
	}
	Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge)//������oneEdg����ͬ������һ����
	{
		Edge<EdgeType> tem;
		tem.start = oneEdge.start;
		for (int i = oneEdge.end + 1; i<this->vertexNum; i++)
		{
			if (matrix[oneEdge.start][i]<999)
			{
				tem.end = i;
				tem.weight = matrix[oneEdge.start][i];
				return tem;
			}
		}
		//cout<<"û�з��������ı�"<<endl;
		return;
	}
	void visit(int i)
	{
		cout << i + 1 << " ";
	}

	//�����������
	void DFS(int i)//��i�Žڵ㿪ʼ�����������
	{
		this->Mark[i] = 1;
		visit(i);
		for (Edge<EdgeType> e = FirstEdge(i); this->isEdge(e); e = NextEdge(e))
		{
			if (this->Mark[e.end] == 0)
			{
				DFS(e.end);
			}
		}

	}
	void DFSGraph()//��ͼ���������������
	{
		for (int i = 0; i<this->vertexNum; i++)
			this->Mark[i] = 0;  //��Ƕ�δ����
		for (int i = 0; i<this->vertexNum; i++)
		{
			if (this->Mark[i] == 0)
			{
				DFS(i);
			}
		}

	}
	//�����������
	void BFS(int i)//��i�Žڵ㿪ʼ�����������
	{
		queue<int> que;
		que.push(i);
		visit(i);
		this->Mark[i] = 1;
		int p;
		while (!que.empty())
		{
			p = que.front();
			que.pop();
			this->Mark[p] = 1;
			for (Edge<EdgeType> e = FirstEdge(p); this->isEdge(e); e = NextEdge(e))
			{
				if (this->Mark[e.end] == 0)
				{//�˴�Ҫע�⣬�ڽڵ����ʱ���Ҫ��Mark��Ϊ�ѷ��ʣ�������ܻᵼ��ͬһ�ڵ������
					visit(e.end);
					this->Mark[e.end] = 1;
					que.push(e.end);
				}
			}
		}
	}

	void BFSGraph()//��ͼ���й����������
	{
		for (int i = 0; i<this->vertexNum; i++)
			this->Mark[i] = 0;  //��Ƕ�δ����
		for (int i = 0; i<this->vertexNum; i++)
		{
			if (this->Mark[i] == 0)
			{
				BFS(i);
			}
		}
		cout << endl;
	}

};

//Floyed�㷨
template<class EdgeType>
void Floyed(AdjGraph<EdgeType>& G, EdgeType ** Adj, int **Path)
{
	int n = G.verticesNum();
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (i == j)
			{
				Adj[i][j] = 0;
				Path[i][j] = i;
			}
			else
			{
				Adj[i][j] = INFINITY;
				Path[i][j] = -1;
				cout << "000000000" << endl;
			}
		}
	}
	for (int v = 0; v<n; v++)
	{
		for (Edge<EdgeType> e = G.FirstEdge(v); G.isEdge(e); e = G.NextEdge(e))
		{
			Adj[v][e.end] = G.weight(e);
		}
	}

	for (int v = 0; v<n; v++)
	{
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<n; j++)
			{
				if (Adj[i][j]>(Adj[i][v] + Adj[v][j]))
				{
					Adj[i][j] = Adj[i][v] + Adj[v][j];
					Path[i][j] = v;
				}
			}
		}
	}

}


int main()
{
	//�α�p163ҳ��ͼ
	int tem[3][3] = {
		{ 999, 5, 10 },
		{ 2,999,13 },
		{ 9,13,999 },
	};
	int n = 3;
	int ** a = new int *[n];
	for (int i = 0; i<n; i++)
	{
		a[i] = new int[n];
	}
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
		{
			a[i][j] = tem[i][j];
		}

	AdjGraph<int> p(n,a);
	p.disp();
	cout << "�����������" << endl;
	p.DFSGraph();
	cout << endl;
	cout << "�����������" << endl;
	p.BFSGraph();
	//Floyed�㷨
	int **Adj, **Path;
	Adj = new int *[n];
	Path = new int *[n];
	for (int i = 0; i<n; i++)
	{
		Adj[i] = new int[n];
		Path[i] = new int[n];
	}
	Floyed(p, Adj, Path);
	cout << "Adj" << endl;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
			cout << Adj[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	cout << "Path" << endl;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
			cout << Path[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	return 0;
}
