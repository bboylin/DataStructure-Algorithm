#include <iostream>
#include "Graphm.h"

int main()
{
    std::cout<<"ǰ��λ�������α�ʾũ���ǣ��򣬲ˣ�0��ʾ���ϰ���1��ʾ�ڱ���\n";
    graphm g;
    g.dfs(0);//�������
    g.setallunvisited();
    myqueue* q=new myqueue(n);
    g.bfs(0,q);//�������
    return 0;
}
