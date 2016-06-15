#include <iostream>
#include "bst.h"
using namespace std;
int main()
{
    bst tree=bst(100);
    int value;
    cout<<"请输入数列建立树(回车结束)：\n";
    do
    {
        cin>>value;
        tree.Insert(value);
    }while(cin.get()!='\n');
    tree.print(tree.getroot());
    tree.calculate(tree.getroot());
    cout<<"平均查找长度："<<tree.getlength()<<endl;
    cout<<"输入你要查找的关键字(回车结束)：\n";
    do{
        cin>>value;
        if(tree.Find(value)!=NULL)
        {
            tree.Delete(value);
            tree.print(tree.getroot());
            cout<<endl;
        }
        else cout<<"无"<<value<<endl;
    }while(cin.get()!='\n');

    return 0;
}
