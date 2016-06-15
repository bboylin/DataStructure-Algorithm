#ifndef _GRAPHM_
#define _GRAPHM_
#include<iostream>
#include "myqueue.h"
const int n=16;
enum{unvisited=0,visited=1};
/*
farmer
wolf
sheep
cabbage
*/
class graphm
{
private:
    int node[n];//state of nodes
    bool matrix[n][n];//state of edges
public:
    graphm();
    int firstneibor(int v);
    int nextneibor(int w,int v);
    void dfs(int v);
    void bfs(int,myqueue*);
    void previsit(int v);
    bool secure(int);
    void setallunvisited()
    {
        for(int i=0;i<n;i++)
            node[i]=unvisited;
    }
};
graphm::graphm()
{
    int j,k;
    for(int i=0;i<n;i++)
    {
        node[i]=unvisited;
        for(j=0;j<n;j++)
            matrix[i][j]=false;
        k=i^8;
        matrix[i][k]=true;//only farmer move
        matrix[i][k^4]=true;//farmer and wolf move
        matrix[i][k^2]=true;//farmer and sheep move
        matrix[i][k^1]=true;//farmer and cabbage move
    }
}
int graphm::firstneibor(int v)
{
    int i=0;
    for(;i<n;i++)
    {
        if(matrix[v][i])
            return i;
    }
    return i;
}
int graphm::nextneibor(int w,int v)
{
    int i=v+1;
    for(;i<n;i++)
    {
        if(matrix[w][i])
            return i;
    }
    return i;
}
void graphm::previsit(int v)
{
    std::cout<<v/8<<(v%8)/4<<(v%4)/2<<v%2<<std::endl;//print the decimal number V by binary system
}
bool graphm::secure(int v)//is the state secure or not
{
    if((v/8)==(v%4)/2)//farmer and sheep in the same side
        return true;
    else if(v==13||v==2)//only sheep in one side
        return true;
    return false;
}
void graphm::dfs(int v)
{
    previsit(v);
    node[v]=visited;
    if(v==15) {std::cout<<"\nget a solution"<<std::endl;return;}
    else
    {
        for(int i=firstneibor(v);i<n;i=nextneibor(v,i))
        {
            if(node[i]==unvisited&&secure(i))
                dfs(i);
        }
    }
}
void graphm::bfs(int start,myqueue* q)
{
    int v,w;
    q->enqueue(start);
    node[start]=visited;
    while(q->q_size()>0)
    {
        q->dequeue(v);
        previsit(v);
        for(w=firstneibor(v);w<n;w=nextneibor(v,w))
            if(node[w]==unvisited&&secure(w))
        {
            node[w]=visited;
            q->enqueue(w);
        }
    }
    std::cout<<"\nget a solution\n";
}
#endif // _GRAPHM_
