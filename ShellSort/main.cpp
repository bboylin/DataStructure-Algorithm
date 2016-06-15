#include <iostream>

using namespace std;
void insertsort(int A[],int n)
    {
        for(int i=1;i<n;++i)
            for(int j=i;(j>0)&&A[j]<A[j-1];--j)
        {
            swap(A[j-1],A[j]);
        }
    }
void shellsort(int *a,int n)
    {
        int k,i,j,temp;
        if(a==NULL||n<2) return;
        for(i=n/2;i>1;i=i/2)
            for(j=i;j<n;++j)
            {
              temp=a[j];
              for(k=j;k>=i&&temp<a[k-i];k-=i)
                    a[k]=a[k-i];
              a[k]=temp;
            }
        insertsort(a,n);
    }
int main()
{

    int a[]={1,77,5,44,434,123,56,-4,65,34,13,6,75,333,23};
    int n=sizeof(a)/sizeof(a[0]);
    shellsort(a,n);
    while(n--) cout<<a[n]<<" ";
    return 0;
}
