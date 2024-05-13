
/*

-1.Unique Paths II

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e.,grid[0][0]). The robot tries
to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in the grid. A path that the robot takes cannotinclude any square that is an
obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

-Top Down

vector<vector<int>> dp;
int paths(int i,int j,vector<vector<int>> &grid){
    if(i>=grid.size() || j>= grid[0].size() || grid[i][j]==1) return 0;
    if(i==grid.size()-1 && j==grid[0].size()-1) return 1;

    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    ans = paths(i,j+1,grid)+paths(i+1,j,grid);
    return dp[i][j]=ans;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    dp.clear();
    dp.resize(105,vector<int> (105,-1));
    return paths(0,0,obstacleGrid);
}


-Bottom up

int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    dp.clear();
    dp.resize(105,vector<long long> (105,0));
    int n=grid.size();
    int m=grid[0].size();
    dp[n-1][m-1]=1;
    if(grid[n-1][m-1]==1) return 0;

    for(int i=n-2;i>=0;i--){
        if(grid[i][m-1]==1){
            dp[i][m-1]=0;
        }else{
            dp[i][m-1]=dp[i+1][m-1];
        }
    }

    for(int j=m-2;j>=0;j--){
        if(grid[n-1][j]==1){
            dp[n-1][j]=0;
        }else{
            dp[n-1][j]=dp[n-1][j+1];
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            if(grid[i][j]!=1){
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }else{
                dp[i][j]=0;
            }
        }
    }
    return dp[0][0];
}

-2.Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which
minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

-Top down

int m,n;
vector<vector<int>> dp;
int path(int i,int j,vector<vector<int>>& grid){
    if(i>=n || j>= m) return INT_MAX;
    if(i==n-1 && j==m-1) return grid[n-1][m-1];
    if(dp[i][j]!=-1) return dp[i][j];
    int down=path(i+1,j,grid);
    int right=path(i,j+1,grid);
    return dp[i][j]=grid[i][j]+min(down,right);
}

int minPathSum(vector<vector<int>>& grid) {
    n=grid.size();
    m=grid[0].size();
    dp.clear();
    dp.resize(200,vector<int> (200,-1));
    return path(0,0,grid);
}

-Bottom Up

vector<vector<int>> dp;
int minPathSum(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    dp.clear();
    dp.resize(205,vector<int> (205,0));
    dp[n-1][m-1]=grid[n-1][m-1];
    for(int i=n-2;i>=0;i--){
        dp[i][m-1]=grid[i][m-1]+dp[i+1][m-1];
    }
    for(int j=m-2;j>=0;j--){
        dp[n-1][j]=grid[n-1][j]+dp[n-1][j+1];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
        }
    }
    return dp[0][0];
}

-3.Partition into Equal Subsets

Given an integer array nums, return true if you can partition the array into two subsets such that the
sum of the elements in both subsets is equal or false otherwise.

-Top down

vector<vector<int>> dp;

bool part(vector<int>&nums,int i,int k){
    if(i==nums.size()) return false;
    if(k==0) return true;
    if(dp[i][k]!=-1) return dp[i][k];
    if(k>=nums[i]){
        return dp[i][k]=part(nums,i+1,k-nums[i]) || part(nums,i+1,k); //include
    }else{
        return dp[i][k]=part(nums,i+1,k); //exclude
    }

}

bool canPartition(vector<int>& nums) {
    dp.clear();
    dp.resize(205,vector<int> (20005,-1));
    int k=0;
    for(int i=0;i<nums.size();i++) k+=nums[i];
    if(k%2!=0) return false;
    else return part(nums,0,k/2);
}

-Bottom Up

vector<vector<int>> dp;

bool canPartition(vector<int>& nums) {
    dp.clear();
    dp.resize(205,vector<int> (20005,false));
    int k=0;
    for(int i=0;i<nums.size();i++) k+=nums[i];
    if(k%2!=0) return false;
    k=k/2;
    int n=nums.size();
    for(int i=0;i<n;i++) dp[i][0]=true; //base-case
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=k;j++){
            if(nums[i]<=j){
                dp[i][j]=dp[i+1][j-nums[i]] || dp[i+1][j];
            }else{
                dp[i][j]=dp[i+1][j];
            }
        }
    }
    return dp[0][k];
}

-4.Catalan Number - Unique BST

Catalan numbers are defined as a mathematical sequence that consists of positive integers, which can
be used to find the number of possibilities of various combinations.
The nth term in the sequence denoted Cn, is found in the following formula: (2n)! / (n + 1)!* n!

The first few Catalan numbers for n = 0, 1, 2, 3, ... are : 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, ...
Given a number n. Print the nth catalan number.

 OR

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of
 unique values from 1 to n.

-Top Down

vector<int> dp;
int numBST(int i){
    if(i==0 || i==1) return 1;
    if(i==2) return 2;
    if(dp[i]!=-1) return dp[i];
    int sum=0;
    for(int k=1;k<=i;k++){
        sum+=numBST(k-1)*numBST(i-k);
    }
    return dp[i]=sum;
}

int numTrees(int n) {
    dp.clear();
    dp.resize(20,-1);
    return numBST(n);
}

-Bottom Up

vector<int> dp;

int numTrees(int n) {
    dp.clear();
    dp.resize(20,0);
    dp[0]=dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        for(int k=1;k<=i;k++){
            dp[i]+=dp[k-1]*dp[i-k];
        }
    }
    return dp[n];
}


*/




