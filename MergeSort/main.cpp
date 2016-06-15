/*
#include <iostream>
//has a problem
using namespace std;
void Merge(int a[],int temp[],int leftpos,int rightpos,int rightend)
{
    int n=rightend-leftpos+1;
    if(rightpos<rightend)
    {
    int leftend=rightpos-1;
    int temppos=leftpos;

    while(leftpos<=leftend&&rightpos<=rightend)
    {
        if(a[leftpos]<a[rightpos]) temp[temppos++]=a[leftpos++];
        else temp[temppos++]=a[rightpos++];
    }
    while(leftpos<=leftend) {temp[temppos++]=a[leftpos++];}
    while(rightpos<=rightend) {temp[temppos++]=a[rightpos++];}
    }
    for(int i=0;i<n;i++,rightend--) a[i]=temp[rightend];
}
void mergesort(int a[],int temparray[],int left,int right)
    {
        if(left<right)
        {
            int mid=(left+right)/2;
            mergesort(a,temparray,left,mid);
            mergesort(a,temparray,mid+1,right);
            Merge(a,temparray,left,mid+1,right);
        }
    }
void mergesort(int a[],int l)
{
    int temparray[l];
    mergesort(a,temparray,0,l-1);
}
int main()
{
    int a[]={10,3,2,55,4,22,6,76,0,11,45,33,-1,23};
    int l=sizeof(a)/sizeof(a[0]);
    mergesort(a,l);
    while(l--)
    {
        cout<<a[l]<<" ";
    }
    return 0;
}
*/
#include<iostream>
using namespace std;
void Merge(int a[],int left,int mid,int right)
    {
        int ln=mid-left+1;
        int rn=right-mid;
        int l[ln],r[rn],i,j,k=left;
        for(i=0;i<ln;i++)
            l[i]=a[left+i];
        for(j=0;j<rn;++j)
            r[j]=a[mid+1+j];
        i=0;
        j=0;
        while(i<ln&&j<rn)
        {
            if(l[i]<r[j]) a[k++]=l[i++];
            else a[k++]=r[j++];
        }
        while(i<ln) a[k++]=l[i++];
        while(j<rn) a[k++]=r[j++];
    }
void mergesort(int a[],int left,int right)
    {
        if(left<right)
        {
        int mid=(left+right)/2;
        mergesort(a,left,mid);
        mergesort(a,mid+1,right);
        Merge(a,left,mid,right);
        }
    }
int main()
{
    int a[]={10,3,2,55,4,22,6,76,0,11,45,33,-1,23};
    int l=sizeof(a)/sizeof(a[0]);
    mergesort(a,0,l-1);
    while(l--)
    {
        cout<<a[l]<<" ";
    }
    return 0;
}
