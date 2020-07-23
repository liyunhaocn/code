#include <iostream>

using namespace std;

template<class EdgeType>
class Edge
{
public:
    int start,end;//边的起始节点，终止节点
    EdgeType weight;//边的权重（应该可以定义为int）
    Edge();
    Edge(int st,int en,int w);
    bool operator > (Edge oneEdge);
    bool operator < (Edge oneEdge);
};

template<class EdgeType>
class Graph
{
    int vertexNum; //图中节点个数
    int edgeNum;   //图中边的个数
    int * Mark;    //标记某节点是否被访问
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
        if(oneEdge.end>=0 && oneEdge.start>=0 && oneEdge.weight>0)//判断条件还不清楚
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
