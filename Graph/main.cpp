#include <iostream>
#include "graph.h"
#include "myqueue.h"
#include <assert.h>
#include"limits.h"
#include<cstdlib>
extern "C"
using namespace std;
class graphm:public graph
{
private:
    int numv,nume;
    int** matrix;
    int* mark;
    int* d;
    int* pre;
public:
    graphm(int v);
    ~graphm();
    void setallmark(graphm* g,int mark);
    int getweight(int i,int j){return matrix[i][j];}
    void previsit(graphm* g,int v){cout<<v<<" is previsited\n";};
    void postvisit(graphm* g,int v){cout<<v<<" is postvisited\n";};
    void dfs(graphm* g,int v);
    void dfsall(graphm* g);
    void bfs(graphm* g,int start,myqueue* q);
    void bfsall(graphm* g,myqueue* q);
    int v(){return numv;};
    int e(){return nume;};
    int firstneibor(int);
    int nextneibor(int,int);
    void setedge(int,int,int);
    void deledge(int,int);
    int weight(int i,int j){return matrix[i][j];}
    int getmark(int i){return mark[i];}
    void setmark(int i,int j){mark[i]=j;}
    void topsort(graphm* g);
    void tophelp(graphm* g,int v);
    int minVertex(graphm* g);
    void printshortest(int s,int e);
    void dijkstra(graphm* g,int start);
};
int graphm::minVertex(graphm* g)
{
    int i=1,v=0;
    for(;i<g->v();i++)
    {
        if(g->getmark(i)==unvisited) {v=i;break;}
    }
    for(i++;i<g->v();i++)
    {
        if(g->getmark(i)==unvisited&&d[i]<d[v])
            v=i;
    }
    return v;
}
void graphm::printshortest(int s,int e)
{
    if(e==s) {cout<<s;return;}
    printshortest(s,pre[e]);
    cout<<"->"<<e;
}
void graphm::dijkstra(graphm* g,int start)
{
    int j=0,v;
    for(;j<g->v();j++)
    {
        if(g->getweight(start,j)==0) d[j]=INT_MAX;
        else d[j]=g->getweight(start,j);
        pre[j]=0;
    }
    d[start]=0;
    for(j=0;j<g->v();j++)
    {
        v=minVertex(g);
        if(v<g->v())
        {
        g->setmark(v,visited);
        printshortest(start,j);
        cout<<endl;
        if(d[v]==INT_MAX) return;
        for(int w=g->firstneibor(v);w<g->v();w=g->nextneibor(v,w))
        {
            if(d[w]>d[v]+g->getweight(v,w))
            {
                d[w]=d[v]+g->getweight(v,w);
                pre[w]=v;
            }
        }
        }
    }
}
void graphm::setallmark(graphm* g,int mark)
{
    for(int i=0;i<g->v();i++)
        g->setmark(i,mark);
}
void graphm::tophelp(graphm* g,int v)
{
    g->setmark(v,visited);
    for(int w=g->firstneibor(v);w<g->v();w=g->nextneibor(v,w))
    {
        if(g->getmark(w)==unvisited) tophelp(g,w);

    }
    g->postvisit(g,v);
}
void graphm::topsort(graphm* g)
{
    g->setallmark(g,unvisited);
    for(int v=0;v<g->v();v++)
    {
        if(g->getmark(v)==unvisited)
            tophelp(g,v);
    }
}
void graphm::bfs(graphm* g,int start,myqueue* q)
{
    int v,w;
    q->enqueue(start);
    g->setmark(start,visited);
    while(q->q_size()>0)
    {
        q->dequeue(v);
        g->previsit(g,v);
        for(w=g->firstneibor(v);w<g->v();w=g->nextneibor(v,w))
            if(g->getmark(w)==unvisited)
        {
            g->setmark(w,visited);
            q->enqueue(w);
        }
        g->postvisit(g,v);
    }
}
void graphm::bfsall(graphm* g,myqueue* q)
{
    for(int i=0;i<g->v();i++)
        bfs(g,i,q);
}
graphm::graphm(int v):graph()
{
    numv=v;
    nume=0;
    mark=new int[v];
    d=new int[v];
    pre=new int[v];
    while(v--) mark[v]=unvisited;
    matrix=(int**) new int*[numv];
    for(int i=0;i<numv;i++)
    {
        matrix[i]=new int[numv];
    }
    for(int i=0;i<numv;i++)
        for(int j=0;j<numv;j++)
        matrix[i][j]=0;
}
graphm::~graphm()
{
    delete []mark;
    delete []d;
    delete []pre;
    for(int i=0;i<numv;i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
}
int graphm::firstneibor(int v)
{
    int i=0;
    for(;i<numv;i++)
    {
        if(matrix[v][i]!=0)
            return i;
    }
    return i;
}
void graphm::setedge(int from,int to,int weight)
{
    assert(weight>0);
    if(matrix[from][to]==0) nume++;
    matrix[from][to]=weight;
}
void graphm::deledge(int from,int to)
{
    if(matrix[from][to]!=0) nume--;
    matrix[from][to]=0;
}
int graphm::nextneibor(int v,int i)
{
    int j=i+1;
    for(;j<numv;j++)
    {
        if(matrix[v][j]!=0) return j;
    }
    return j;
}
void graphm::dfs(graphm* g,int v)
{
    previsit(g,v);
    g->setmark(v,visited);
    for(int w=g->firstneibor(v);w<g->v();w=g->nextneibor(v,w))
    {
        if(g->getmark(w)==unvisited)
            dfs(g,w);
    }
    postvisit(g,v);
}
void graphm::dfsall(graphm* g)
{
    for(int i=0;i<g->v();i++)
    {
        if(mark[i]==unvisited)
            dfs(g,i);
    }
}
myqueue::myqueue(int qs):qsize(qs){head=tail=NULL;items=0;};
int myqueue::q_size() const {return items;};
bool myqueue::enqueue(type& it)
{
    if(isfull()) return false;
    node* add=new node;
    add->item=it;
    add->next=NULL;
    if(isempty()) head=add;
    else tail->next=add;
    tail=add;
    items++;
    return true;
}
bool myqueue::dequeue(type& it)
{
    if(isempty()) return false;
    it=head->item;
    node* temp=head;
    head=head->next;
    delete temp;
    items--;
    if(items==0) tail=NULL;
    return true;
}
myqueue::~myqueue()
{
    node* temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        delete temp;
    }
}
void myqueue::print()
{
    cout<<"print queue:";
    node* h=head;
    while(h!=NULL)
    {
        cout<<h->item<<" ";
        h=h->next;
    }
    cout<<endl;
}
int main()
{
    graphm g=graphm(100);
    myqueue q=myqueue(100);
    cout<<g.v()<<" vertexs\n";
    for(int i=0;i<100;i++)
        for(int j=rand()%100;j<100;j++)
    {
        g.setedge(i,j,rand()%100+1);
    }
    cout<<g.e()<<" edges\n";
    int n=rand()%100;
    cout<<"dfs from "<<n<<endl;
    g.dfs(&g,n);
    g.setallmark(&g,1);
    cout<<"bfs from "<<n<<endl;
    g.bfs(&g,n,&q);
    g.setallmark(&g,1);
    cout<<"tophelp from "<<n<<endl;
    g.tophelp(&g,n);
    cout<<"topsort from"<<n<<endl;
    g.topsort(&g);
    g.setallmark(&g,1);
    g.dijkstra(&g,0);
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
    {
        g.deledge(i,j);
    }
    cout<<"after delete remains "<<g.e()<<" edges\n";
    cout<<"dfs from "<<n<<endl;
    g.dfs(&g,n);
    cout<<endl;
    g.bfs(&g,n,&q);
    return 0;
}
