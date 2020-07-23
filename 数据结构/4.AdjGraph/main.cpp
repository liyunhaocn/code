#include <iostream>
#include <Queue.h>
#include <stack>
#include <minHeap.h>
using namespace std;

template<class EdgeType>
class Edge
{
public:
    int start,end;//边的起始节点，终止节点
    EdgeType weight;//边的权重（应该可以定义为int）
    Edge()
    {
       start=0;
        end=0;
        weight=0;
    }
    Edge(int st,int en,int w)
    {
        start=st;
        end=en;
        weight=w;
    }
    bool operator > (Edge oneEdge)
    {
        if(weight>oneEdge.weight)
            return true;
        else
            return false;
    }
    bool operator < (Edge oneEdge)
    {
        if(weight<oneEdge.weight)
            return true;
        else
            return false;
    }
};

template<class EdgeType>
class Graph
{
    public:
    int vertexNum; //图中节点个数
    int edgeNum;   //图中边的个数
    int * Mark;    //标记某节点是否被访问
    Graph(int verNum)
    {
        this->vertexNum=verNum;
        edgeNum=0;
        Mark=new int[vertexNum];
        for(int i=0;i<vertexNum;i++)
        {
            Mark[i]=0; //都没有被访问过
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
    int startOfEdge(Edge<EdgeType> oneEdge)
    {
        return oneEdge.start;
    }
    int endOfEdge(Edge<EdgeType> oneEdge)
    {
        return oneEdge.end;
    }

    EdgeType weight(Edge<EdgeType> oneEdge) //返回oneEdge的权重
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
    AdjGraph(int verNum):Graph<EdgeType>(verNum)
    {
        matrix =new int * [verNum];
        for(int i=0;i<verNum;i++)
        {
            matrix[i]=new int [verNum];
        }
        for(int i=0;i<verNum;i++)
          for(int j=0;j<verNum;j++)
        {
            matrix[i][j]=0;
        }
    }

    AdjGraph(int verNum,int **  a):Graph<EdgeType>(verNum)
    {
        matrix =new int * [verNum];
        for(int i=0;i<verNum;i++)
        {
            matrix[i]=new int [verNum];
        }
        for(int i=0;i<verNum;i++)
          for(int j=0;j<verNum;j++)
          {

            matrix[i][j]=a[i][j];
          }
    }
    void disp()
    {
        cout<<endl;
        cout<<"此图的领接矩阵为"<<endl;
        for(int i=0;i<this->vertexNum;i++)
        {
           for(int j=0;j<this->vertexNum;j++)
           {
             cout<<matrix[i][j]<<" ";
           }
            cout<<endl;
         }
    }
    ~AdjGraph()
    {
        for(int i=0;i<this->vertexNum;i++)
        {
            matrix[i]=new int [this->vertexNum];
        }
        delete [] matrix;
    }
    Edge<EdgeType> FirstEdge(int oneVer) //返回顶点的第一条边
    {
        Edge<EdgeType> tem;
        tem.start=oneVer;
        for(int i=0;i<this->vertexNum;i++)
        {
            if(matrix[oneVer][i]!=0)
            {
                tem.end=i;
                tem.weight=matrix[oneVer][i];
                return tem;
                //break;
            }
        }
        //cout<<"没有符合条件的边"<<endl;
        //return;
    }
    Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge)//返回与oneEdg有相同起点的下一条边
    {
        Edge<EdgeType> tem;
        tem.start=oneEdge.start;
        for(int i=oneEdge.end+1;i<this->vertexNum;i++)
        {
              if(matrix[oneEdge.start][i]!=0)
              {
                 tem.end=i;
                 tem.weight=matrix[oneEdge.start][i];
                 return tem;
              }
        }
        //cout<<"没有符合条件的边"<<endl;
        //return;
    }
    void visit(int i)
    {
        cout<<i+1<<" ";
    }

    //深度优先搜索
    void DFS(int i)//从i号节点开始深度优先搜索
    {
        this->Mark[i]=1;
        visit(i);
        for(Edge<EdgeType> e=FirstEdge(i);this->isEdge(e);e=NextEdge(e))
        {
             if(this->Mark[e.end]==0)
             {
               DFS(e.end);
             }
        }

    }
    void DFSGraph()//对图进行深度优先搜索
    {
        for(int i=0;i<this->vertexNum;i++)
        this->Mark[i]=0;  //标记都未访问
        for(int i=0;i<this->vertexNum;i++)
        {
            if(this->Mark[i]==0)
            {
                DFS(i);
            }
        }

    }
    void DFSGraphNoReverse()//对图进行深度优先搜索,非递归实现
    {
        int i,v,u;
        stack<int> s;
        Edge<EdgeType> e;
        for(i=0;i<this->verticesNum();i++)
        {
            this->Mark[i]=0;
        }
        for(i=0;i<this->verticesNum();i++)
        {
            if(this->Mark[i]==0)
            {
                s.push(i);
                visit(i);
                v=s.top();
                this->Mark[i]=1;
                while(!s.empty())
                {
                    v=s.top();
                    int flag=0;
                    int j;
                    for(j=0;j<this->vertexNum;j++)
                    {
                        if(matrix[v][j]>0 && this->Mark[j]==0)
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag)
                    {
                        visit(j);
                        s.push(j);
                        this->Mark[j]=1;
                    }
                    else
                    {
                        s.pop();
                    }

                }
            }
        }
    }

    //广度优先搜索
    void BFS(int i)//从i号节点开始广度优先搜索
    {
        Queue<int> que;
        que.EnQueue(i);
        visit(i);
        this->Mark[i]=1;
        int p;
        while(!que.IsEmpty())
        {
            que.DeQueue(p);
            this->Mark[p]=1;
            for(Edge<EdgeType> e=FirstEdge(p);this->isEdge(e);e=NextEdge(e))
            {
                if(this->Mark[e.end]==0)
                {//此处要注意，在节点入队时候就要将Mark置为已访问，否则可能会导致同一节点多次入队
                  visit(e.end);
                  this->Mark[e.end]=1;
                  que.EnQueue(e.end);
                }
            }
        }
    }

    void BFSGraph()//对图进行广度优先搜索
    {
        for(int i=0;i<this->vertexNum;i++)
        this->Mark[i]=0;  //标记都未访问
        for(int i=0;i<this->vertexNum;i++)
        {
            if(this->Mark[i]==0)
            {
                BFS(i);
            }
        }

    }
    void setEdge(int s,int e,int w)
    {
       matrix[s][e]=w;
    }
    void delPoint(int p)
    {
        int n=this->verticesNum();
        for(int i=0;i<n;i++)
        {
            matrix[p][i]=0;
            matrix[i][p]=0;
        }
        this->vertexNum--;
    }
    void delEdge(int s,int e)
    {
        matrix[s][e]=0;
    }
};

int main()
{
    //课本p160页的图

    AdjGraph<int> p1(8);
    p1.disp();
    cout<<"插入边"<<endl;
    p1.setEdge(0,1,1);
    p1.setEdge(0,2,1);
    p1.setEdge(0,3,1);
    p1.setEdge(0,4,1);
    p1.disp();
    cout<<"删除边"<<endl;
    p1.delEdge(0,4);
    p1.delEdge(0,3);
    p1.delEdge(0,2);
    p1.delEdge(0,1);
    p1.disp();
    int tem[8][8]={
        {0,1,1,0,0,0,0,0},
        {1,0,0,1,1,0,0,0},
        {1,0,0,0,0,1,1,0},
        {0,1,0,0,0,0,0,1},
        {0,1,0,0,0,0,0,1},
        {0,0,1,0,0,0,1,0},
        {0,0,1,0,0,1,0,0},
        {0,0,0,1,1,0,0,0},
    };
    int ** a=new int *[8];
    for(int i=0;i<8;i++)
    {
        a[i]=new int [8];
    }
    for(int i=0;i<8;i++)
      for(int j=0;j<8;j++)
    {
        a[i][j]=tem[i][j];
    }

    AdjGraph<int> p(8,a);
    p.disp();
    cout<<"深度优先搜索"<<endl;
    p.DFSGraph();
    cout<<endl;
    cout<<"非递归"<<endl;
    p.DFSGraphNoReverse();
    cout<<endl;
    cout<<"广度优先搜索"<<endl;
    p.BFSGraph();
    cout<<endl;
    return 0;
}
