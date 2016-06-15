#include <iostream>
#include<stdio.h>
using namespace std;
class node
{
public:
    int id;
    int value;
    node* next;
};
int main()
{
    int n,m;
    scanf("%d",&n);//num of nodes
    scanf("%d",&m);//max value
    node* p=new node[n];
    printf("the value of every nodes are as follows:\n");
    for(int i=0;i<n-1;i++)
    {
        cin>>p[i].value;
        p[i].id=i+1;
        p[i].next=&p[i+1];
    }
    cin>>p[n-1].value;
    p[n-1].id=n;
    p[n-1].next=&p[0];
    node* fence;
    fence=&p[0];
    node* pre;
    if(m==1)
    {
        cout<<"1 ";
        pre=fence;
        fence=fence->next;
        p[--n].next=fence;
        m=pre->value;
        node* temp=pre;
        delete temp;
    }
    while(n)
    {
        while(--m)
        {
            pre=fence;
            fence=fence->next;
        }
        printf("%d ",fence->id);
        m=fence->value;
        pre->next=fence->next;
        node* temp=fence;
        fence=fence->next;
        delete temp;
        n--;
    }
    return 0;
}
