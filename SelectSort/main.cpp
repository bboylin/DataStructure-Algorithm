#include <iostream>

using namespace std;
void selectsort(int* a,int n)
{
    int item;
    for(int i=0;i<n-1;i++)
    {
        int lowindex=i;
        for(int j=n-1;j>i;--j)
        {
            if(a[j]<a[lowindex]) lowindex=j;
        }
        if(i!=lowindex)
        {
            item=a[lowindex];
            a[lowindex]=a[i];
            a[i]=item;
        }
    }
}
int main()
{
    int a[]={1,77,5,44,434,123,56,-4,65,34,13,6,75,333,23};
    int n=sizeof(a)/sizeof(a[0]);
    selectsort(a,n);
    while(n--) cout<<a[n]<<" ";
    return 0;
}
