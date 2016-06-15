node* p=head;//store the value
node* q=NULL;
node* prev=NULL;
while(p!=NULL)
{
    q=p->next;
    p->next=prev;
    prev=p;
    p=q;
}
head=prev;
