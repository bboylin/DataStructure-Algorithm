#include <iostream>
#include"myqueue.h"
#include<cstdlib>
using namespace std;
int main()
{
    myqueue q(20);
    int n=20;
    while(n--) { int it=rand()%100+1;q.enqueue(it);}
    cout<<"�������20���������Ϊ��\n";
    q.print();
    n=10;
    int it;
    while(n--) q.dequeue(it);
    cout<<"����10��Ԫ�س��к����Ԫ��Ϊ��\n";
    q.print();
    return 0;
}
