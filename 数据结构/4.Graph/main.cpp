#include <iostream>

using namespace std;

template<class EdgeType>
class Edge
{
public:
    int start,end;//�ߵ���ʼ�ڵ㣬��ֹ�ڵ�
    EdgeType weight;//�ߵ�Ȩ�أ�Ӧ�ÿ��Զ���Ϊint��
    Edge();
    Edge(int st,int en,int w);
    bool operator > (Edge oneEdge);
    bool operator < (Edge oneEdge);
};

template<class EdgeType>
class Graph
{
    int vertexNum; //ͼ�нڵ����
    int edgeNum;   //ͼ�бߵĸ���
    int * Mark;    //���ĳ�ڵ��Ƿ񱻷���
    Graph(int vertexNum)
    {
        this->vertexNum=vertexNum;
        edgeNum=0;
        Mark=new int[vertexNum];
        for(int i=0;i<vertexNum;i++)
        {
            Mark[i]=0;
        }
    }
    ~Graph()
    {
        delete [] Mark;
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
        if(oneEdge.end>=0 && oneEdge.start>=0 && oneEdge.weight>0)//�ж������������
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
    EdgeType endOfVertex(Edge<EdgeType> oneEdge)
    {
        return oneEdge.weight;
    }
    //virtual void setEdge(int start,int end,int weight)=0;
    //virtual void deleteEdge(int start,int end)=0;
};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
