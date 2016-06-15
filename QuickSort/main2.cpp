#include<iostream>
using namespace std;
int partition1(int* a,int p,int r)
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
int qsort(int* a,int p,int r)
{
    int k=qsort(a,p,r);
    qsort(a,p,k-1);
    qsort(a,k+1,r);
}
int main()
{
    enum{maxx=10};
    int a[maxx]={0,3,2,32,4,22,6,76,0,11};
    int p=0,r=maxx-1;
    qsort(a,p,r);
    for(int i=0;i<maxx;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
