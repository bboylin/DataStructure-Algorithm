#ifndef _STACKBAG_H
#define _STACKBAG_H
#include<iostream>
#include<map>
class stone{
public:
    int volume;
    int value;
    stone(){};
    void setparams(int vo,int va){volume=vo;value=va;};
};
class mystack{
private:
std::map<int,int> valuesmap;
enum{max=20};
stone items[max];
int numofsolution;
int t;
int top;
public:
mystack(int T):top(0){t=T;numofsolution=0;};
bool isempty() const{return top==0;};
bool isfull() const{return top==max;};
bool pop(stone&);
bool push(stone);
void solution(stone* a,int n);
int sum();
void clearstack() {top=0;};
void print();
void bestsolution();
};
int mystack::sum()
{
    int s=0,n=top;
    while(n--) s+=items[n].volume;
    return s;
}
bool mystack::pop(stone& it)
{
    if(!isempty())
    {
        it=items[--top];
        return true;
    }
    std::cout<<"stack is full\n";
    return false;
}
bool mystack::push(stone it)
{
    if(!isfull())
    {
        items[top++]=it;
        return true;
    }
    return false;
}

void mystack::print()
{
    int allvalue=0;
    std::cout<<"get an answer:";
    for(int i=0;i<top;i++)
    {
        std::cout<<items[i].volume<<" ";
        allvalue+=items[i].value;
    }
    std::cout<<std::endl<<"sum of the value is:"<<allvalue<<std::endl;
    numofsolution++;
    valuesmap.insert(std::pair<int,int>(allvalue,numofsolution));
}
void mystack::solution(stone* b,int n)
{
    stone it;
    int j;
    for(int i=0;i<n;i++)
    {
        push(b[i]);
        j=i+1;
        while(top<n+1&&top>0)
        {
            if(j<n)
            {
                if(sum()+b[j].volume<t) push(b[j]);
            else if(sum()+b[j].volume==t)
            {
                push(b[j]);
                print();
                pop(it);
            }
            j++;
            }
            else
            {
                pop(it);
                for(j=i+1;j<n;j++)
                {
                    if(b[j].value!=it.value||b[j].volume!=it.volume)
                    {
                        j++;
                    }
                    else break;
                }
                j++;
            }
        }
        clearstack();
    }
}
void mystack::bestsolution()
{
    std::cout<<"the best solution is number "<<valuesmap.rbegin()->second<<"\nthe max value is:"<<valuesmap.rbegin()->first;
}
#endif // _STACKBAG_H
