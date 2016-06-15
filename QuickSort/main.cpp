#include <iostream>
using namespace std;

int q_partition(int a[],int p,int r)
{
    int x=a[r];
    int i=p-1;
    for(int j=p;j<r;j++)
    {
        if(a[j]<x)
        {
            swap(a[++i],a[j]);
        }
    }
    swap(a[++i],a[r]);
    return i;
}
void quicksort(int a[],int p,int r)
{
    if(p<r)
    {
        int q=q_partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
int main()
{
    enum{maxx=10};
    int a[maxx]={0,3,2,32,4,22,6,76,0,11};
    int p=0,r=maxx-1;
    quicksort(a,p,r);
    for(int i=0;i<maxx;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}


