#include <iostream>
#include "bst.h"
using namespace std;
int main()
{
    bst tree=bst(100);
    int value;
    cout<<"���������н�����(�س�����)��\n";
    do
    {
        cin>>value;
        tree.Insert(value);
    }while(cin.get()!='\n');
    tree.print(tree.getroot());
    tree.calculate(tree.getroot());
    cout<<"ƽ�����ҳ��ȣ�"<<tree.getlength()<<endl;
    cout<<"������Ҫ���ҵĹؼ���(�س�����)��\n";
    do{
        cin>>value;
        if(tree.Find(value)!=NULL)
        {
            tree.Delete(value);
            tree.print(tree.getroot());
            cout<<endl;
        }
        else cout<<"��"<<value<<endl;
    }while(cin.get()!='\n');

    return 0;
}
