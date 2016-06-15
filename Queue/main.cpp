#include <iostream>
#include"myqueue.h"
#include<cstdlib>
using namespace std;
int main()
{
    myqueue q(20);
    int n=20;
    while(n--) { int it=rand()%100+1;q.enqueue(it);}
    cout<<"随机插入20个数后队列为：\n";
    q.print();
    n=10;
    int it;
    while(n--) q.dequeue(it);
    cout<<"队首10个元素出列后队列元素为：\n";
    q.print();
    return 0;
}
