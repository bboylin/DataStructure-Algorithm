#include <iostream>
#include "Graphm.h"

int main()
{
    std::cout<<"前四位数字依次表示农夫，狼，羊，菜，0表示在南岸，1表示在北岸\n";
    graphm g;
    g.dfs(0);//深度优先
    g.setallunvisited();
    myqueue* q=new myqueue(n);
    g.bfs(0,q);//广度优先
    return 0;
}
