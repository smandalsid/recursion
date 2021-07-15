
// in simple words, generate inputs of truth table

#include<iostream>
using namespace std;

void print(int ar[], int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<"\n";
}

void binstr(int ar[], int n, int i)
{
    if (i==n)
    {
        print(ar,n);
        return;
    }
    else
    {
        ar[i]=0;
        binstr(ar,n,i+1);
        ar[i]=1;
        binstr(ar,n,i+1);
    }
}

int main()
{
    int ar[4];
    binstr(ar,4,0);
    return 0;
}