
// this program is to find the maximum length of connected 1's in a matrix of 1's and 0's
// they can be connected diagonally horizontally or vertically

#include<bits/stdc++.h>
using namespace std;

#define ROW 4
#define COL 5


// we are using DFS in this approach
// we are keeping a hash map to keep track of visited elements and 
// also keep track of visited 1's and update maximum length accordingly


// to check if the element in the position can be included in the DFS

int isSafe(int M[][COL],int row, int col, bool visited[][COL])
{
    return (row>=0) && (row<ROW) && (col>=0) && (col<COL) && (M[row][col] && !visited[row][col]);
}

// the function to do the DFS search on the matrix and considers max of 8 elements as adjacent
void DFS(int M[][COL],int row, int col, bool visited[][COL], int &count)
{
    // these two arrays are used to check the adjacent elements in 8 directions
    static int rowNbr[]={-1,-1,-1,0,0,1,1,1};
    static int colNbr[]={-1,0,1,-1,1,-1,0,1};

    // mark the cell as visited
    visited[row][col]=true;

    for (int k = 0; k < 8; k++)
    {
        if (isSafe(M,row+rowNbr[k],col+colNbr[k],visited))
        {
            // increment the length by 1
            count++;
            // recursively call it for the adjacent cells too;
            DFS(M,row+rowNbr[k],col+colNbr[k],visited,count);
        }
    }
    

}

// the main function that returns the largest length region of the 2D matrix

int largestRegion(int M[][COL])
{

    // make a bool array to mark the visited places and initially set all to 0
    bool visited[ROW][COL];
    memset(visited,0,sizeof(visited));

    // initialising final answer
    int result=INT_MIN;
    int i,j;

    for (i=0;i<ROW;i++)
    {
        for (j=0;j<COL;j++)
        {
            // if the position has 1 and has not been visited
            if (M[i][j] && !visited[i][j])
            {
                // new region found
                int count=1;
                DFS(M,i,j,visited,count);

                // if this region has greater length than older regions than store the length
                result=max(result,count);
            }
        }
    }
    return result;

}


int main()
{
    int M[][COL] = {{0,0,1,1,0},
                    {0,0,1,1,0},
                    {0,0,0,0,0},
                    {0,0,0,0,1}};
    
    cout<<largestRegion(M);

    return 0;
}