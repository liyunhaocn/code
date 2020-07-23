#ifndef EDGE_H
#define EDGE_H


class Edge
{
public:
    int from;
    int to;
    public:
        Edge():from(-1),to(-1){};
        Edge(int from,int to):from(from),to(to){};
        virtual ~Edge(){};
    protected:
    private:
};

#endif // EDGE_H
