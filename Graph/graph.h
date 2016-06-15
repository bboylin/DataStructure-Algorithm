#ifndef GRAPH_H_
#define GRAPH_H_
class graph
{
protected:
    enum{visited=0,unvisited=1};
public:
    graph(){};
    virtual int v()=0;
    virtual int e()=0;
    virtual int firstneibor(int)=0;
    virtual int nextneibor(int,int)=0;
    virtual void setedge(int,int,int)=0;
    virtual void deledge(int,int)=0;
    virtual int weight(int,int)=0;
    virtual int getmark(int)=0;
    virtual void setmark(int,int)=0;
};
#endif // GRAPH_H_
