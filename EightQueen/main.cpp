#include<stdio.h>
#include<cmath>
using namespace std;
enum{n=8};
static int sum=0;
bool place(int a[],int i)//is the choice suitable or not
{
    for(int j=0;j<i;j++)
    {
        if(a[j]==a[i]||abs(a[j]-a[i])==abs(j-i))
            return false;
    }
    return true;
}
void backtrack(int a[],int t)
{
    if(t>n-1)//a solution has been found
    {
        sum++;
        for(int i=0;i<n;i++)
            printf("(%d,%d) ",i,a[i]);
        printf("\n");
    }
    else
    {
        for(int i=0;i<n;i++)//figure out column t can hold which row in turns
        {
            a[t]=i;
            if(place(a,t)) backtrack(a,t+1);
        }
    }
}
int main()
{
    int a[n]={0};//i means column,a[i] means row
    backtrack(a,0);
    printf("%d solutions in total",sum);
    return 0;
}
