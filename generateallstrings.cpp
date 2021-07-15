#include<iostream>
using namespace std;

void generatestrings(int n, int k, int ar[])
{
    if (n<1)
    {
        for (int i=0;i<k;i++)
        {
            cout<<ar[i]<<" ";
        }
        cout<<"\n";
    }
    else
    {
        for (int j=0;j<k;j++)
        {
            ar[k-1]=j;
            generatestrings(n-1,k,ar);
        }
    }
}

int main()
{
    int ar[2]={1,2};
    generatestrings(3,2,ar);
    return 0;
}