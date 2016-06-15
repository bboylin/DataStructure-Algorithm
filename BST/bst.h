#ifndef BST_H_
#define BST_H_
typedef int type;
class bst
{
private:
    struct node{
       struct node* lc;struct node* rc;struct node* p;type elem;int h;
public:
    node(type& it,int t=0){elem=it;lc=NULL;rc=NULL;p=NULL;h=t;}
    node(){lc=NULL;rc=NULL;p=NULL;elem=0;h=0;};
    };
    const int num;
    int searchlength;
    int elems;
    enum{maxn=20};
    node* root;
    node* temp;
public:
    bst(int n=maxn);
    ~bst();
    int elemsnum() {return elems;}
    node* getroot() const {return root;};
    node* Find(type it);
    node* successor(node*);
    void transplant(node* u,node* v);
    bool Insert(type it);
    bool Delete(type it);
    void cleartree(node* it);
    bool isempty() const;
    bool isfull() const;
    void print(node*);
    void calculate(node*);
    int getlength(){return searchlength;};
};
bst::bst(int n):num(n){root =NULL;elems=0;searchlength=0;}
bool bst::isempty() const {return elems==0;}
bool bst::isfull() const {return elems==num;}
bool bst::Insert(type it)
{
    if(isfull()) {std::cout<<"tree is full,so "<<it<<" cannot be inserted\n";return false;}
    if(Find(it)!=NULL) {std::cout<<it<<" already exists in the tree,insert failed\n";return false;}
    if(isempty())
    {
        root=new node(it);
        root->h++;
    }
    else
    {
        temp=root;
        node* q=NULL;
        int t=1;
        while(temp!=NULL)
        {
            q=temp;
            if(it<temp->elem) temp=temp->lc;
            else temp=temp->rc;
            t++;
        }
        temp=new node(it,t);
        temp->p=q;
        if(q->elem<it) q->rc=temp;
        else q->lc=temp;

    }
    elems++;
    return true;
}
bst::node* bst::Find(type it)
{
    if(isempty()) {return NULL;}
    temp=root;
    while(temp!=NULL)
    {
        if(temp->elem==it) return temp;
        else if(temp->elem>it) temp=temp->lc;
        else temp=temp->rc;
    }
    return NULL;
}
bst::node* bst::successor(node* it)
{
    temp=it->rc;
    if(temp==NULL)
        return (node*)NULL;
    while(temp->lc!=NULL) temp=temp->lc;
    return temp;
}
void bst::transplant(node* u,node* v)//may need overload=
{
    if(u!=v)
    {
        if(u->p==NULL)
    {
        root=v;
    }
    else if(u==u->p->lc) u->p->lc=v;
    else u->p->rc=v;
    if(v!=NULL) v->p=u->p;
    }
}
bool bst::Delete(type it)
{
    temp=Find(it);
    if(temp==NULL) {std::cout<<"delete failed,target not found.\n";return false;}
    if(temp->lc==NULL)
        transplant(temp,temp->rc);
    else if(temp->rc==NULL)
        transplant(temp,temp->lc);
    else
    {
        node* s=successor(temp);
        if(s->p!=temp)
        {
            transplant(s,s->rc);
            s->rc=temp->rc;
            s->rc->p=s;
        }
        transplant(temp,s);
        s->lc=temp->lc;
        s->lc->p=s;
    }
    node* t=temp;
    temp=NULL;
    delete t;
    elems--;
    return true;
}
void bst::print(node* Node)
{
    if(Node==NULL) return;
    print(Node->lc);
    std::cout<<Node->elem<<" ";
    print(Node->rc);
}
bst::~bst()
{
    cleartree(root);
}
void bst::cleartree(node* it)
{
    if(it==NULL) return;
    cleartree(it->lc);
    cleartree(it->rc);
    delete it;
}
void bst::calculate(node* r)
{
    if(r!=NULL)
    {
        searchlength+=r->h;
        calculate(r->lc);
        calculate(r->rc);
    }
}
#endif // BST_H_
