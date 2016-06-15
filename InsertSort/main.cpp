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
int main()
{
    enum{maxx=10};
    int a[maxx]={0,3,2,32,4,22,6,76,0,11};
    insertsort(a,maxx);
    int r=maxx;
    while(r--)
    {
        cout<<a[r]<<" ";
    }
    return 0;
}
