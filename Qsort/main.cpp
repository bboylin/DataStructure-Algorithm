#include<iostream>
using namespace std;
//sort in decreasing order
int partition1(int a[],int p,int r)
{
    int k=a[p];
    while(p<r)
    {
        if(p<r&&k>a[r]) r--;
        a[p]=a[r];
        if(p<r&&k<a[p]) p++;
        a[r]=a[p];
    }
    a[p]=k;
    return p;
}
void qsort(int a[],int p,int r)
{
    if(p<r)
    {
        int k=partition1(a,p,r);
        qsort(a,p,k-1);
        qsort(a,k+1,r);
    }
}
int main()
{
    enum{maxx=10};
    int a[maxx]={1,5,33,7,88,6,44,23,65,32};
    int p=0;
    int r=maxx-1;
    qsort(a,p,r);
    for(int i=0;i<maxx;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
