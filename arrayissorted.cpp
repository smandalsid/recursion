
// check if the array is sorted using recursion

#include<iostream>
using namespace std;

int issorted(int ar[], int n)
{
    if (n==0)
    {
        return 1;
    }
    else if(ar[n]>ar[n-1])
    {
        return issorted(ar,n-1);
    }
    else
    {
        return 0;
    }
}

int main()
{
    int ar[5]={1,2,3,4,5};
    cout<<issorted(ar,4);
    return 0;
}