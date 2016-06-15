#include <iostream>
using namespace std;
void maxheapify(int *a,int i,int imax)
    {
        int l=2*i+1;
        int r=2*i+2;
        int largest=i;
        if(l<=imax) largest=a[l]>a[i]?l:i;
        if(r<=imax) largest=a[r]>a[largest]?r:largest;
        if(largest!=i)
        {
            swap(a[i],a[largest]);
            maxheapify(a,largest,imax);
        }

    }
void buildmaxheap(int *a,int imax)
    {
        for(int j=imax/2;j>-1;j--) maxheapify(a,j,imax);
    }
void heapsort(int *a,int imax)
    {
        buildmaxheap(a,imax);
        for(int j=imax;j>0;j--)
        {
            swap(a[0],a[j]);
            --imax;
            maxheapify(a,0,imax);
        }
    }

int main()
{
    int a[]={1,77,5,44,434,123,56,-4,65,34,13,6,75,333,23};
    int n=sizeof(a)/sizeof(a[0]);
    heapsort(a,n-1);
    while(n--) cout<<a[n]<<" ";
    return 0;
}
