/*

-And with that we have finally completed our BackTracking , in on word it was just 'AMAZING' , all the
questions I did were really mind blowing and really played with basics as well as my thinking ability
, which off course I need to immprove a lot , but you know the single thought that you were able to 
persist till here , really makes me damn proud of myself .

-So, at teh end I will just say this have a faith in yourself and its okay if you don't get evrything
at first,second or even third time , just keep walking at your own pace and keep learning and revising!

-HAVE A GOOD DAY AHEAD!!


-1.Sudoku Solver - Consider a 9*9 2D array grid that is partially filled with numbers from 1 to 9. The Sudoku Solver problem is to fill
remaining blocks with numbers from 1 to 9 so that every row, column and subgrid (3*3) contains exactly one
instance of digits (1 to 9).

-Time complexity :- O(9^(N*N))

#include<iostream>
#include<vector>
using namespace std;

bool canWePlace(int i,int row,int col,vector<vector<char>> &board){
    //checking for rows
    for (int j = 0; j < 9; j++)
    {
        if (board[row][j]=='0'+i)
        {
            return false;
        }
        
    }
    //checking for columns
    for(int j=0;j<9;j++){
        if (board[j][col]=='0'+i)
        {
            return false;
        }
        
    }
    //checking sub-grid
    int r=(row/3)*3;
    int c=(col/3)*3;
    for (int k = r; k < r+3; k++)
    {
        for(int j=c;j < c+3;j++){
            if (board[k][j]=='0'+i)
            {
                return false;
            }
            
        }
    }
    return true;
}



bool sudoku(vector<vector<char>> &board,int row ,int col){
    //base-case
    if (col==9)
    {
        return sudoku(board,row+1,0);
    }
    if (row==9)
    {
    cout<<"Solved Sudoku is : "<<endl;
    for (int i = 0; i < 9; i++)
    {
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
        return true;
    }
    

    if (board[row][col]=='.')
    {
        for (int i = 1; i <= 9; i++)
        {
            if (canWePlace( i, row, col, board))
            {
                board[row][col]='0'+i;
                bool res=sudoku(board,row,col+1);
                if (res)
                {
                    return true;
                }
                board[row][col]='.';
            }
            
        }
        return false;
        
    }
    else{
        return sudoku(board,row,col+1);
    }
}

int main(){
    vector<vector<char>> v = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    sudoku(v,0,0);
    
    return 0;
}

// Output:-
// Solved Sudoku is : 
// 5 3 4 6 7 8 9 1 2
// 6 7 2 1 9 5 3 4 8
// 1 9 8 3 4 2 5 6 7
// 8 5 9 7 6 1 4 2 3
// 4 2 6 8 5 3 7 9 1
// 7 1 3 9 2 4 8 5 6
// 9 6 1 5 3 7 2 8 4
// 2 8 7 4 1 9 6 3 5
// 3 4 5 2 8 6 1 7 9

-2. K-Knights - Given integers M, N and K, the task is to place K knights on an M*N chessboard such that they don’t attack each
other. The knights are expected to be placed on different squares on the board. A knight can move two squares
vertically and one square horizontally or two squares horizontally and one square vertically. The knights attack
each other if one of them can reach the other in single move. There are multiple ways of placing K knights on an
M*N board or sometimes, no way of placing them. We are expected to list out all the possible solutions.


#include<iostream>
#include<vector>
using namespace std;

bool canWePlace(vector<vector<char>> &grid,int i,int j,int m,int n){
    if(i-1>=0 and j-2>=0 and grid[i-1][j-2]=='K') return false; //V-H-H - left
    if(i-2>=0 and j-1>=0 and grid[i-2][j-1]=='K') return false; //V-V-H - bottom-left
    if(i-1>=0 and j+2<n and grid[i-1][j+2]=='K') return false; //V-H-H - right
    if(i-2>=0 and j+1<n and grid[i-2][j+1]=='K') return false; //V-V-H - bottom-right
    return true;
}

void K_Knight(int m,int n, vector<vector<char>> &grid,int k,int i,int j){
    //base-case
    if (k==0)
    {
        
        for (int i = 0; i < m; i++)
        {
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        for (int ip = 0; ip < 2*n; ip++)
        {
            cout<<"*";
        }
        cout<<endl;
        return;
        
    }
    if (j==n)
    {
        return K_Knight(m,n,grid,k,i+1,0);
    }
    if (i==m)
    {
        return;
    }
    for (int row = i; row < m; row++)
    {
        for (int col = (row == i ? j:0); col < n; col++)
        {
            if (canWePlace(grid,row,col,m,n))
            {
                grid[row][col]='K';
                K_Knight(m,n,grid,k-1,row,col+1);
                grid[row][col]='.';
            }
            
        }
        
    }

}

int main(){
    int m,n;
    cout<<"Size of chess board mxn : ";
    cin>>m>>n;
    cout<<"Enter the number of Knights : ";
    int K;
    cin>>K;
    vector<vector<char>> v(m,vector<char> (n,'.'));
    cout<<"Possible placement are : "<<endl;
    K_Knight(m,n,v,K,0,0);
    return 0;
    
}

// Output:-
// Size of chess board mxn : 3 3
// Enter the number of Knights : 5
// Possible placement are : 
// K . K
// . K .
// K . K
// ******
// . K .
// K K K
// . K .
// ******

-3.Knights's Tour - Consider an N*N chessboard. The Knight’s Tour problem is to print order when the Knight visits that block of the
chessboard. Initially, the knight will be placed at the first block of the chessboard. The rule is that the Knight
visits each block exactly once.


#include<iostream>
#include<vector>
using namespace std;

bool f(vector<vector<int>> &grid,int i,int j,int n,int count){
    if(i<0 || j<0 || i>=n || j>=n || grid[i][j]>=0) return false;
    if(count==n*n-1){
        grid[i][j]=count; //to manage my last jump
        for (int i = 0; i < n; i++)
        {
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<"\t";
            }
            cout<<endl;
        }
        return true;
    }
    grid[i][j]=count;
    if(f(grid,i-2,j-1,n,count+1)) return true;
    if(f(grid,i-2,j+1,n,count+1)) return true;
    if(f(grid,i-1,j+2,n,count+1)) return true;
    if(f(grid,i+1,j+2,n,count+1)) return true;
    if(f(grid,i+2,j+1,n,count+1)) return true;
    if(f(grid,i+2,j-1,n,count+1)) return true;
    if(f(grid,i+1,j-2,n,count+1)) return true;
    if(f(grid,i-1,j-2,n,count+1)) return true;
    grid[i][j]=-1;
    return false;
}

int main(){
    int n;
    cout<<"Enter the size of grid : ";
    cin>>n;

    vector<vector<int>> grid(n,vector<int> (n,-1));
    f(grid,0,0,n,0);
    return 0;
}

// Output:-
// Enter the size of grid : 6
// 0       21      6       27      2       13
// 19      26      1       14      7       28
// 22      15      20      5       12      3
// 33      18      25      10      29      8
// 16      23      34      31      4       11
// 35      32      17      24      9       30

-4.Combination Sum II – Find all unique combinations 
-Given a collection of candidate numbers (candidates) and a target number (target), find all unique
combinations in candidates where the candidate numbers sum to target. Each number in candidates may
only be used once in the combination.

-Time complexity :- O(N * 2^N)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void f(vector<int> &c,int index,int target,vector<int> &v,vector<vector<int>> &result){
    //base-case
    if (target==0)
    {
        result.push_back(v);
        return;
    }
    if (index==c.size())
    {
        return;
    }
    if (c[index]<=target)
    {
        // we can pick
        v.push_back(c[index]);
        f(c,index+1,target-c[index],v,result);
        v.pop_back();
    }
    //but we will face problem if same elements get repeated , so lets solve it
    int j=index+1;
    while (j<c.size() and c[j]==c[j-1])
    {
        j++;
    }
    //we can not pick
    f(c,index+1,target,v,result);

}

void combinationSum2(vector<int> &c,int target,vector<vector<int>> &result){
    vector<int> v;
    sort(c.begin(),c.end());
    f(c,0,target,v,result);
    cout<<"Answer sub-vectors are : "<<endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout<<"{ ";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<"} ";
        
    }
    
}

int main(){
    int n;
    cout<<"Enter the size of vector : ";
    cin>>n;
    vector<int> c(n);
    cout<<"Enter the vector : ";
    for (int i = 0; i < n; i++)
    {
        cin>>c[i];

    }
    cout<<"Enter the target element : ";
    int m;
    cin>>m;
    vector<vector<int>> result;
    combinationSum2(c,m,result);
    return 0;
}

// Output:-
// Enter the size of vector : 7
// Enter the vector : 10 1 2 7 6 1 5
// Enter the target element : 8
// Answer sub-vectors are : 
// { 1 1 6 } { 1 2 5 } { 1 7 } { 1 2 5 } { 1 7 } { 2 6 }

-5.Combinational Sum - Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency of at least one of the chosen numbers is different.


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void f(vector<vector<int>> &result,vector<int> &c,int target,int index,vector<int> &v){
    //base-case
    if (target==0)
    {
        result.push_back(v);
        return;
    }
    if (index==c.size())
    {
        return;
    }
    if (c[index]<=target)
    {
        v.push_back(c[index]);
        f(result,c,target-c[index],index,v);
        v.pop_back();
    }
    int j=index+1;
    f(result,c,target,j,v);
    
}

void combinationSum(vector<vector<int>> &result,vector<int> &c,int target,int index){
    vector<int> v;
    sort(c.begin(),c.end());
    f(result,c,target,0,v);
    cout<<"Answer sub-vectors are : ";
    for (int i = 0; i < result.size(); i++)
    {
        cout<<"{ ";
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"} ";
    }
    
}

int main(){
    int n;
    cout<<"Enter the size of vector : ";
    cin>>n;
    vector<int> c(n);
    cout<<"Enter the vector : ";
    for (int i = 0; i < n; i++)
    {
        cin>>c[i];

    }
    cout<<"Enter the target element : ";
    int m;
    cin>>m;
    vector<vector<int>> result;
    combinationSum(result,c,m,0);
    return 0;
}

// Enter the size of vector : 4
// Enter the vector : 2 3 6 7
// Enter the target element : 7
// Answer sub-vectors are : { 2 2 3 } { 7 } 

*/









