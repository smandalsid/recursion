
// towers of hanoi

#include<iostream>
using namespace std;

void towerofhanoi(int n, char source, char helper, char destination)
{
    if (n==0)
    {
        return;
    }
    else
    {
        towerofhanoi(n-1,source,destination,helper);
        cout<<"Move disk from "<<source<<" to "<<destination<<"\n";
        towerofhanoi(n-1,helper,source,destination);
    }
}

int main()
{
    int n;
    cout<<"Enter number of disks to move:\n";
    cin>>n;
    towerofhanoi(n,'A','B','C');
    return 0;
}