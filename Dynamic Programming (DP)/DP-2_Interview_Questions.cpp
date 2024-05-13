/*
-1. Triangle

Given a triangle array, return the minimum path sum from top to bottom.For each step, you may move to
an adjacent number of the row below. More formally, if you are on index i on the current row, you may move
to either index i or index i + 1 on the next row.

-Top Down approach

//would be good if i made triangle and dp global ;

int mini(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>& dp){
    if(i==triangle.size()-1 ) return triangle[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int down = mini(triangle,i+1,j,dp);
    int dori=mini(triangle,i+1,j+1,dp);
    dp[i][j]=triangle[i][j]+min(down,dori);
    return dp[i][j];
}

int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dp(triangle.size(), vector<int>());
    for (int i = 0; i < triangle.size(); ++i) {
        dp[i].resize(triangle[i].size(), -1);
    }
    return mini(triangle,0,0,dp);
}

-Bottom Up

int minimumTotal(vector<vector<int>>& triangle) {
    int n=triangle.size();
    // int m=triangle[n-1].size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++) dp[n-1][i]=triangle[n-1][i];
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    return dp[0][0];
}

-2.Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no
common subsequence, return 0.
A subsequence of a string is a new string generated from the original string with some characters (can be
none) deleted without changing the relative order of the remaining characters.

-Top Down

vector<vector<int>> dp;
int f(string &a,string &b,int i,int j){
    if(i==a.size() || j==b.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]!=b[j]){
        return dp[i][j]=max(f(a,b,i,j+1),f(a,b,i+1,j));
    }else{
        return dp[i][j]=1+f(a,b,i+1,j+1);
    }
}

int longestCommonSubsequence(string text1, string text2) {
    dp.clear();
    dp.resize(1005,vector<int>(1005,-1));
    return f(text1,text2,0,0);
}

-Bottom Up

int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(1005,vector<int>(1005,0));
    int n=text1.size();
    int m=text2.size();
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(text1[i]!=text2[j]){
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }else{
                dp[i][j]=1+dp[i+1][j+1];
            }
        }
    }
    return dp[0][0];
}

-3.Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.

-Top Down

vector<int> arr;
vector<int> dp;

int f(int i){
    if(i==0) return 1;
    int mx=INT_MIN;
    if(dp[i]!=-1) return dp[i];
    for(int j=0;j<i;j++){
        if(arr[j]<arr[i]){
            mx=max(mx,f(j));
        }
    }
    if(mx==INT_MIN) return 1;
    return dp[i]=1+mx;
}

int lengthOfLIS(vector<int>& nums) {
    arr=nums;
    dp.resize(2505,-1);
    dp[0]=1;
    int ans=INT_MIN;
    for(int i=0;i<nums.size();i++){
        ans=max(ans,f(i));
    }
    return ans;
}

-Bottom Up

vector<int> arr;
vector<int> dp;
int lengthOfLIS(vector<int>& nums) {
    arr=nums;
    dp.resize(2505,-1);
    dp[0]=1;
    int ans=INT_MIN;
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        if(dp[i]==-1) dp[i]=1;
        ans=max(ans,dp[i]);
    }
    return ans;
}

-4.Matrix chain multiplication

Given the dimension of a sequence of matrices in an array arr[], where the dimension of the ith matrix is
(arr[i-1] * arr[i]), the task is to find the most efficient way to multiply these matrices together such that the
total number of element multiplications is minimum.

-Top down


#include "iostream"
#include "vector"
using namespace std;

vector<vector<int>> dp;

int mcm(int i,int j,vector<int> &v){
    //base-case
    if(i==j || i+1==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
        ans=min(ans,mcm(i,k,v)+mcm(k,j,v)+v[i]*v[j]*v[k]);
    }
    return dp[i][j]=ans;
}

int main(){
    int n;
    cout<<"Enter the size of vector :";
    cin>>n;
    dp.clear();
    dp.resize(n+5,vector<int> (n+5,-1));
    cout<<"Enter the value of vector :";
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<"Answer : "<<mcm(0,n-1,v)<< endl;
    return 0;
}

//Output:-
//Enter the size of vector :5
//Enter the value of vector :40 20 30 10 30
//Answer : 26000

-Bottom up


#include "iostream"
#include "vector"
using namespace std;

vector<vector<int>> dp;

int main(){
    int n;
    cout<<"Enter the size of vector :";
    cin>>n;
    dp.clear();
    dp.resize(n+5,vector<int> (n+5,0));
    cout<<"Enter the value of vector :";
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    // Matrix Chain Multiplication DP setup
    for(int len = 2; len < n; ++len) { // Starts from 2 because we need at least two matrices for multiplication
        for(int i = 0; i + len < n; ++i) {
            int j = i + len; // Corrected the index for the last element in the current sub-array
            dp[i][j] = INT_MAX;
            for(int k = i + 1; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + v[i] * v[k] * v[j]);
            }
        }
    }

    cout << "Minimum cost of multiplication is: " << dp[0][n-1] << endl;
    return 0;
}

//Output:-
//Enter the size of vector :5
//Enter the value of vector :40 20 30 10 30
//Minimum cost of multiplication is: 26000

*/