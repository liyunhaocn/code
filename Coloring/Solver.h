#ifndef SOLVER_H
#define SOLVER_H

#include <bits/stdc++.h>

#include "Edge.h"
#include "Reader.h"
#include "MyString.h"

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solver
{
    public:
        string sourceFile;
        vector<Edge> edges;
        int K;     //求解的K值
        int pcnt;  //点数
        int ecnt;  //边数
        int fsVal; // s的冲突值
        //int ** graph;
        int **M;
        MyString myStr;
        map<int,int> X;   //染色
        map<int,vector<int>> neighbors;
        set<int> confPoints;

        //记录besmove的结构体
        struct node{
            int u;
            int i;
            int j;
            int cost;
            node(){};
            node(int u,int i,int j,int cost):u(u),i(i),j(j),cost(cost){};
        };

        Solver(){K=0;sourceFile="DSJC125.1.col"; };
        Solver(string source ):sourceFile(source){};

        // f 函数
        int fFunc(){
            fsVal = 0;
            for(auto i : edges){
                if( X[i.from] == X[i.to] ){
                    fsVal ++;
                    //debug(fsVal);
                    confPoints.insert(i.from);
                    confPoints.insert(i.to);
                }
            }
            return fsVal;
        }

        //初始化染色
        bool initCol(){


            if( K == 3 ){

                X[1] = 0 ;
                X[3] = 0 ;
                X[4] = 0 ;

                X[2] = 1 ;
                X[7] = 1 ;
                X[8] = 1 ;

                X[5] = 2 ;
                X[6] = 2 ;
                X[9] = 2 ;

            }else{
                srand(time(0));
                for(int i=1;i<=pcnt;i++){
                    int col = rand() % K+1;
                    //debug(col);
                    X[i] = col;
                }
            }
            return true;
        }

        bool initGraph(){
            vector<string> readfileContent;//从文件读取的内容
            Reader Reader1;
            //edges.clear();
            readfileContent = Reader1.read(sourceFile);
            for(auto i:readfileContent){
                //cout<<i<<endl;
                vector<string>temp;
                if(i[0] == 'p'){
                    temp = myStr.split(i," ");
                    pcnt = myStr.str_int(temp[2]);
                    //debug(111111);
                    //debug(pcnt);

                    //K = pcnt;
                    ecnt = myStr.str_int(temp[3]);

                    //生成领接矩阵
                    //graph = new int* [ pcnt+1 ];
                    //for(int i=0;i<pcnt+1;i++){
                    //    graph[i] = new int [pcnt+1];
                    //}
                    //for(int i=0;i<pcnt+1;i++){
                    //    for(int j=0;j<pcnt+1;j++){
                    //        graph[i][j]=0;
                    //    }
                    //}

                }else if(i[0] == 'e'){
                    temp = myStr.split(i," ");
                    int from = myStr.str_int(temp[1]);
                    int to = myStr.str_int(temp[2]);
                    //graph[from][to] = 1;
                    //graph[to][from] = 1;
                    //构造边集合
                    edges.push_back(Edge(from,to));
                    //构造邻点映射
                    neighbors[from].push_back(to);
                    neighbors[to].push_back(from);
                    //debug(from);
                    //debug(to);
                }
            }
            return true;
        }
        /*
        void dispGraph(){
            for(int i=0;i<pcnt+1;i++){
                for(int j=0;j<pcnt+1;j++){
                    cout<<graph[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        */
        bool isSucceed(){
            if(fsVal==0){
                return true;
            }else{
                return false;
            }
        }

        int moveFunc (int u,int i, int j){
            return M[u][j] - M[u][i];
        }

        node bestMove(){

            int min1 = 0x3f3f3f3f;
            node retNode;
            for(int u = 1;u <= pcnt;u++){
                int i = X[u];
                for(int j = 1;j <= K;j++){
                    if(j != i){
                        if( moveFunc(u,i,j ) < min1 ){
                            min1 = moveFunc(u,i,j );
                            retNode.i = i;
                            retNode.j = j;
                            retNode.u = u;
                            retNode.cost = min1;
                        }
                    }
                }
            }
            return retNode;
        }

        bool moveBest( node t){
            vector<int> nei = neighbors[ t.u ];
            for(int i=0;i<nei.size();i++){
                M [ nei[i] ][ t.i ] -= 1;
                M [ nei[i] ][ t.j ] += 1;
            }
            X[t.u] = t.j;
        }

        bool initAdjM(){
            M = new int*[pcnt+1];
            for(int i=0;i<=pcnt;i++){
                M[i] = new int [pcnt+1];
            }

            for(int i=1;i <= pcnt;i++){
                for(int j=1;j <= pcnt;j++){
                    M[i][j] = 0;
                }
            }
            for(int i=1;i <= pcnt;i++){
                vector<int> nv = neighbors[i];
                for(int j = 1;j <= K;j++){
                    for( int i1 = 0;i1 < nv.size();i1++){
                        if(X[ nv[i1] ] == j){
                            //debug(i)
                            //debug(j)
                            //debug(M[i][j]);
                            M[i][j] ++;
                        }
                    }
                }
            }

            return true;
        }

        void dispAdjM(){
            for(int i=1;i<=pcnt;i++){
                for(int j = 1;j <= K;j++){
                    cout<<M[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        bool simpleLocalSearch(int kk){
            K = kk;

            initCol();
            //计算 f(s)
            fFunc();

            debug(11111111111)
            debug(fsVal);
            initAdjM();
            //debug(K);

            node bestM = bestMove();
            while( bestM.cost < 0){
                moveBest(bestM);

                //debug(bestM.u);
                //debug(bestM.i);
                //debug(bestM.j);
                //debug(bestM.cost)
                //debug(fsVal);
                //debug( fFunc());

                //dispAdjM();

                fsVal += bestM.cost;
                bestM = bestMove();
            }
            debug(fsVal);

            if( isSucceed() ){
                return true;
            }else{
                return false;
            }
        }
        void dispX(){
            //debug(X.size());
            for(int i=1;i <= pcnt ;i++){
                cout<< i <<" "<< X[i] <<endl;
            }
        }
        int run(){
            //初始化graph
            initGraph();
            //显示Graph
            //dispGraph();

            debug(pcnt);



            //K = pcnt;
            K = 3;
            int s = 1;
            int e = K;

            int mid = 0;

            initCol();
            debug(000000000000)
            fFunc();
            debug(fsVal)

            while( s < e){
                mid = (s+e)/2;
                debug(mid);
                bool sm_1 = simpleLocalSearch(mid-1);
                bool sm = simpleLocalSearch(mid);
                if( sm && sm_1  ){
                    e = mid-1;
                }else if( sm && !sm_1 ){
                    return mid;
                }else if( !sm ){
                    s = mid+1;
                }else{
                    cout<<"zzzzzzzzzzzzzzzzzzz"<<endl;
                    debug(mid)
                    debug(sm)
                    debug(sm_1)
                }
            }
            debug(s)
            debug(e)
            mid = (s+e)/2;
            K = mid;
            return K;
        }

        virtual ~Solver(){};
    protected:
    private:
};

#endif // SOLVER_H

