#include <iostream>
#include<assert.h>
#include"stack.h"
using namespace std;
mystack::mystack():top(0){};
int mystack::length() const {return top;};
bool mystack::isempty() const{return top==0;};
bool mystack::isfull()const {return top==max;};
type mystack::getvalueat(int id)
{
    assert(id>-1&&id<length()&&length()>0);
    return items[id];
}
bool mystack::pop(type& it)
{
    if(!isempty())
    {
        it=items[--top];
        return true;
    }
    cout<<"stack is full\n";
    return false;
}
bool mystack::push(type it)
{
    if(!isfull())
    {
        items[top++]=it;
        return true;
    }
    return false;
}
int main()
{
    mystack s;
    int i=s.getmax()+1;
    while(i--) s.push(i);
    for(i=s.length()-1;i>-1;i--)
    {
        cout<<s.getvalueat(i)<<endl;
    }
    cout<<"now stack contains "<<s.length()<<" elements\n";
    type it;
    i=s.length();
    while(i--)
    {
        s.pop(it);
        cout<<it<<endl;
    }
    cout<<"now stack contains "<<s.length()<<" elements\n";
    return 0;
}
