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
#endif // MYQUEUE_H_
