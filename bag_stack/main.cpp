#include<iostream>
#include"stackbag.h"
int main()
{
    int stonenumber,bagsize;
    std::cout<<"input number of the stones:";
    std::cin>>stonenumber;
    std::cout<<"input the size of the bag:";
    std::cin>>bagsize;
    std::cout<<"input the volume and the value of the stone one by one\n";
    stone* stones=new stone[stonenumber];
    int vo,va;
    for(int i=0;i<stonenumber;i++)
    {
        std::cin>>vo>>va;
        stones[i].setparams(vo,va);
    }
    mystack sta=mystack(bagsize);
    sta.solution(stones,stonenumber);
    sta.bestsolution();
    delete stones;
    return 0;
}
