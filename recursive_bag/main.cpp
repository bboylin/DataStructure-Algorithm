#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int t,n,sum=0,value=0;
int va=0;
int* a,*b;
vector<int> q;
void print()
{
    cout<<"get a solution:";
    sum++;
    for(int i=0;i<q.size();i++)
    {
        cout<<a[q[i]]<<" ";
    }
    cout<<endl;
}
void dfs(int x)
{
    if(x>n-1) return;
    if(sum>t) return;
    q.push_back(x);
    sum+=a[x];
    va+=b[x];
    if(sum==t)
    {
        print();
        value=value>va?value:va;
    }
    dfs(x+1);
    q.pop_back();
    sum-=a[x];
    va-=b[x];
    dfs(x+1);
}
int main()
{
    scanf("%d",&t);//total
    scanf("%d",&n);//sum of bags
    a=new int[n];//volume
    b=new int[n];//value
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        scanf("%d",&b[i]);
    }
    dfs(0);
    cout<<"max value:"<<value;
    delete[] a;
    delete[] b;
    return 0;
}
