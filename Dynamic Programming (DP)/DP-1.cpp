/*

-Dynamic Programming -> if you already know something then do not recompute it
                     -> reuse more , repeat less
                     -> It is just optimization on brute force , all paths will be explored but repetitive one's will not be
                     computed but stored

 -dp works on global optimum whereas greedy works on local optimum

 -Top down DP - Memoization -> generally recursive

vector<int> dp(n+1,-1);
int f(int n){
    if(n==0 || n==1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=f(n-1)+f(n-2);
}

 -Bottom up DP - Tabulation -> generally iteratively

vector<int> dp(n+1,-1);
int fbu(int n){
    if(n==0 || n==1) return n;
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

 //Optimised bottom up

int fbuo(int n){
    if(n==0 || n==1) return n;
    int a=0;
    int b=1;
    for(int i=2;i<=n;i++){
        int c=a+b;
        a=b;
        b=c;
    }
    return c;
}

-Questions :-

 -1.House Robber

 You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
 the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and
 it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can
 rob tonight without alerting the police.

 -Bottom Up approach

vector<int> dp;  //for dynamic programming
int f(int i,vector<int>& arr){
    if(i>=arr.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    return dp[i]=max(arr[i]+f(i+2,arr),f(i+1,arr));
}

int rob(vector<int>& nums) {
    dp.resize(nums.size()+10,-1);
    return f(0,nums);
}

 -Top down approach

vector<int> dp;
int f(vector<int>& arr){
    int n=arr.size();
    if(n==1) return arr[n-1]; //base case
    dp[n-1]=arr[n-1];
    dp[n-2]=max(arr[n-2],arr[n-1]);
    for(int i=n-3;i>=0;i--){
        dp[i]=max(arr[i]+dp[i+2],dp[i+1]);
    }
    return dp[0];
}

int rob(vector<int>& nums) {
    dp.resize(nums.size()+10,-1);
    return f(nums);
}

 -Top down with O(1) space complexity
 
*/





