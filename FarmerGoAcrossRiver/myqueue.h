#ifndef MYQUEUE_H_
#define MYQUEUE_H_
typedef int type;
class myqueue
{
private:
    enum{mqsize=10};
    const int qsize;
    struct node{type item;struct node* next;};
    node* head;
    node* tail;
    int items;
public:
    bool isempty() const {return items==0;};
    bool isfull() const {return items==qsize;};
    myqueue(int qs=mqsize);
    ~myqueue();
    bool enqueue(type& it);
    bool dequeue(type&);
    int q_size() const;
    void print();
};
myqueue::myqueue(int qs):qsize(qs){head=tail=NULL;items=0;};
int myqueue::q_size() const {return items;};
bool myqueue::enqueue(type& it)
{
    if(isfull()) return false;
    node* add=new node;
    add->item=it;
    add->next=NULL;
    if(isempty()) head=add;
    else tail->next=add;
    tail=add;
    items++;
    return true;
}
bool myqueue::dequeue(type& it)
{
    if(isempty()) return false;
    it=head->item;
    node* temp=head;
    head=head->next;
    delete temp;
    items--;
    if(items==0) tail=NULL;
    return true;
}
myqueue::~myqueue()
{
    node* temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        delete temp;
    }
}
#endif // MYQUEUE_H_
