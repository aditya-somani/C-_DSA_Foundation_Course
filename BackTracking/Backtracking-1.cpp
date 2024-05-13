/*

-These Questions were just amazing and the way they employed concepts and the way Sanket Sir taught them them were just amazibg
-This time I have make sure that i wrote the code down and did complete dry run of code to get its full essence , so if you are learning
it make sure to do both of them thoroughly in these lecture we solved Permutation , Rat in a Maze and N Queen problem , 
rest problem are in next lecture , Have a great Day Ahead!!

-Backtracking is just like recursion just the main idea here involves here pruning of possibilities which doesn't provide answer

-Changes made in states should be REVERTED back

-1.Write a program to print all permutations of the given string s in lexicographically sorted order.

-Time compelexity -> O(n!) 

#include <iostream>
using namespace std;

void permutation(string &str,int i){
    //base-case 
    int n=str.size();
    if (i==n)
    {
        cout<<str<<endl;
        return;
    }
    for (int j = i; j < n;j++)
    {
        swap(str[i],str[j]);
        permutation(str,i+1);
        swap(str[i],str[j]);
    }
    
}

int main(){
    cout<<"Enter the string : ";
    string s;
    cin>>s;
    cout<<"Permutatuion are : "<<endl;
    permutation(s,0);
    return 0;
}

// Output:-
// Enter the string : abc
// Permutatuion are : 
// abc
// acb
// bac
// bca
// cba
// cab

-2.Rat in a Maze Problem:

A maze is represented as an N*N binary matrix of blocks where the upper-left block is known as the source block,
and the lower-rightmost block is known as the destination block. If we consider the maze, then maze[0][0] is the source, 
and maze[N-1][N-1] is the destination. Our main task is to reach the destination from the source. 
We have considered a rat as a character that can move either forward or downwards.

In the maze matrix, a few blocks are denoted by 0, representing dead blocks, and active blocks are denoted by 1. 
A rat can move only in the active blocks.

-Time complexity :- O(2^(N^2))

#include<iostream>
#include<vector>
using namespace std;

bool canWeGo(int a,int b,vector<vector<int>> &grid){
    return (a<grid.size() and b<grid.size() and a>=0 and b>=0) and grid[a][b]==1;
}

int f(int i,int j,vector<vector<int>> &grid){
    int n=grid.size();
    int ans=0;
    //base-case
    if (i==n-1 && j==n-1) {
        for (int i = 0; i < n; i++)
        {
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"*******"<<endl;
        return 1;
    }

    grid[i][j]=2;
    //right
    if(canWeGo(i,j+1,grid)) 
        ans+=f(i,j+1,grid);

    //bottom
    if (canWeGo(i+1,j,grid))
    {
        ans+=f(i+1,j,grid);
    }
    //left
    if (canWeGo(i,j-1,grid))
    {
        ans+=f(i,j-1,grid);
    }
    //up
    if (canWeGo(i-1,j,grid))
    {
        ans+=f(i-1,j,grid);
    }
    grid[i][j]=1;

    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of grid : ";
    cin>>n;
    vector<vector<int>> v(n,vector<int> (n));
    cout<<"Enter the grid : ";
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    cout<<"Number of possible solutions to solve grid is : "<<f(0,0,v);
    return 0;
}

// Output:-
// Enter the size of grid : 4
// Enter the grid : 1 1 1 1 0 1 0 1 0 1 1 1 0 1 1 1          
// 2 2 2 2 
// 0 1 0 2
// 0 1 1 2
// 0 1 1 1
// *******
// 2 2 2 2
// 0 1 0 2
// 0 1 2 2
// 0 1 2 1
// *******
// 2 2 2 2
// 0 1 0 2
// 0 2 2 2
// 0 2 2 1
// *******
// 2 2 1 1
// 0 2 0 1
// 0 2 2 2 
// 0 1 1 1
// *******
// 2 2 1 1
// 0 2 0 1
// 0 2 2 1
// 0 1 2 1
// *******
// 2 2 1 1
// 0 2 0 1
// 0 2 1 1
// 0 2 2 1
// *******
// 2 2 1 1
// 0 2 0 1
// 0 2 2 2
// 0 2 2 1
// *******
// Number of possible solutions to solve grid is : 7

-3.N-Queen - Consider an N*N chessboard. N Queen Problem is to accommodate N queens on the N*N chessboard such that
no 2 queens can attack each other.

-Time complexity :- O(N!)

#include<iostream>
#include<vector>
using namespace std;

bool canWePlace(int row,int col,vector<vector<char>> &grid){
    //vertical check
    for (int i = row-1; i >=0; i--)
    {
        if (grid[i][col]=='Q')
        {
            return false;
        }
        
    }
    //left-diagonal check
    for(int i=row-1,j=col-1;i>=0 and j>=0;i--,j--){
        if (grid[i][j]=='Q')
        {
            return false;
        }
        
    }
    //Right-diagonal check
    for(int i=row-1,j=col+1;i>=0 and j<grid.size();i--,j++){
        if (grid[i][j]=='Q')
        {
            return false;
        }
        
    }
    return true;
}

void nQueen(int currRow,int n,vector<vector<char>> &grid){
    //base-case
    if (currRow==n)  // when row=col and in square that is at end
    {
        for (int i = 0; i < n; i++)
        {
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"*******"<<endl;
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (canWePlace(currRow,col,grid))
        {
            grid[currRow][col]='Q';
            nQueen(currRow+1,n,grid);
            grid[currRow][col]='.';
        }
        
    }
    
}

int main(){
    cout<<"Enter the size of board : ";
    int n;
    cin>>n;
    vector<vector<char >> grid(n,vector<char> (n,'.'));
    nQueen(0,n,grid);
    return 0;
}

// Output:-
// Enter the size of board : 4
// . Q . . 
// . . . Q
// Q . . .
// . . Q .
// *******
// . . Q . 
// Q . . .
// . . . Q
// . Q . .
// *******

*/


