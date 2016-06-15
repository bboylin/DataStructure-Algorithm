#include <iostream>
#include"arraylist.h"
using namespace std;
ArrayList::ArrayList():length(0){};
bool ArrayList::isempty() const {return length==0;};
bool ArrayList::isfull() const {return length==max;};
int ArrayList::Find(type target){
int n;
if(length){n=length;}
while(--n){
if(a[n]==target) return n;
}
cout<<"cannot find "<<target<<endl;
return -1;
}
bool ArrayList::Insert(type target){
if(length==max) {cout<<"array is full"<<endl;return false;}
a[length++]=target;
return true;
}
bool ArrayList::Insert(int id,type target){
if(length==max) {cout<<"array is full"<<endl;return false;}
int n=length;
do{
a[n]=a[n-1];
n--;
}while(n>id);
a[id]=target;
++length;
return true;
}
type ArrayList::getvalueat(int id){
if(length){return a[id];}
cout<<"array is empty,cannot get value at "<<id<<endl;
return -1;
}
bool ArrayList::Delete(type target){
int id=ArrayList::Find(target);
if(id!=-1){
while(id<length-1){
a[id]=a[id+1];
id++;
}
--length;
return true;
}
cout<<"array is empty";
return false;
}
int main()
{
    ArrayList al;
    int i=20;
    while(i--){
    al.Insert(i);
    }
    al.Insert(20);
    for(int i=0;i<al.getlength();i++){
    cout<<i<<"-->value:"<<al.getvalueat(i)<<endl;
    }
    cout<<"8 at:"<<al.Find(8)<<endl;
    cout<<al.getvalueat(al.Find(8))<<" at:"<<al.Find(8)<<endl;
    if(al.Delete(1)){
    for(int i=0;i<al.getlength();i++){
    cout<<i<<"-->value:"<<al.getvalueat(i)<<endl;
    }
    }
    al.Delete(1);
    return 0;
}
