#include <iostream>
#include <Queue.h>
#include <stack>
#include <minHeap.h>
using namespace std;

template<class EdgeType>
class Edge
{
public:
    int start,end;//�ߵ���ʼ�ڵ㣬��ֹ�ڵ�
    EdgeType weight;//�ߵ�Ȩ�أ�Ӧ�ÿ��Զ���Ϊint��
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
    int vertexNum; //ͼ�нڵ����
    int edgeNum;   //ͼ�бߵĸ���
    int * Mark;    //���ĳ�ڵ��Ƿ񱻷���
    Graph(int verNum)
    {
        this->vertexNum=verNum;
        edgeNum=0;
        Mark=new int[vertexNum];
        for(int i=0;i<vertexNum;i++)
        {
            Mark[i]=0; //��û�б����ʹ�
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
    int startOfEdge(Edge<EdgeType> oneEdge)
    {
        return oneEdge.start;
    }
    int endOfEdge(Edge<EdgeType> oneEdge)
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
        cout<<"��ͼ����Ӿ���Ϊ"<<endl;
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
    Edge<EdgeType> FirstEdge(int oneVer) //���ض���ĵ�һ����
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
        //cout<<"û�з��������ı�"<<endl;
        //return;
    }
    Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge)//������oneEdg����ͬ������һ����
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
        //cout<<"û�з��������ı�"<<endl;
        //return;
    }
    void visit(int i)
    {
        cout<<i+1<<" ";
    }

    //�����������
    void DFS(int i)//��i�Žڵ㿪ʼ�����������
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
    void DFSGraph()//��ͼ���������������
    {
        for(int i=0;i<this->vertexNum;i++)
        this->Mark[i]=0;  //��Ƕ�δ����
        for(int i=0;i<this->vertexNum;i++)
        {
            if(this->Mark[i]==0)
            {
                DFS(i);
            }
        }

    }
    void DFSGraphNoReverse()//��ͼ���������������,�ǵݹ�ʵ��
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

    //�����������
    void BFS(int i)//��i�Žڵ㿪ʼ�����������
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
                {//�˴�Ҫע�⣬�ڽڵ����ʱ���Ҫ��Mark��Ϊ�ѷ��ʣ�������ܻᵼ��ͬһ�ڵ������
                  visit(e.end);
                  this->Mark[e.end]=1;
                  que.EnQueue(e.end);
                }
            }
        }
    }

    void BFSGraph()//��ͼ���й����������
    {
        for(int i=0;i<this->vertexNum;i++)
        this->Mark[i]=0;  //��Ƕ�δ����
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
    //�α�p160ҳ��ͼ

    AdjGraph<int> p1(8);
    p1.disp();
    cout<<"�����"<<endl;
    p1.setEdge(0,1,1);
    p1.setEdge(0,2,1);
    p1.setEdge(0,3,1);
    p1.setEdge(0,4,1);
    p1.disp();
    cout<<"ɾ����"<<endl;
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
    cout<<"�����������"<<endl;
    p.DFSGraph();
    cout<<endl;
    cout<<"�ǵݹ�"<<endl;
    p.DFSGraphNoReverse();
    cout<<endl;
    cout<<"�����������"<<endl;
    p.BFSGraph();
    cout<<endl;
    return 0;
}
