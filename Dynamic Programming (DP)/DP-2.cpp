/*


-1. Decode ways

 A message containing letters from A-Z can be encoded into numbers using the following mapping:
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the
reverse of the mapping above (there may be multiple ways)J For example, "11106" can be mapped into:
"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".
Given a string s containing only digits, return the number of ways to decode it.

-Top down Approach

vector<int> dp;
int string_to_int(string s){
    if(s.size()==1) return s[0]-'0';
    return (s[0]-'0')*10 + s[1]-'0';
}

int f(string s,int idx){
    //base-case
    if(s[idx]=='0') return 0;
    if(idx>=s.size()) return 0;
    if(idx==s.size()-1){  //Base Condition
        if(s[idx]=='0') return 0;
        else return 1;
    }
    if(idx == s.size()-2){  //for two digits like "12" // This is a Base Condition
        bool canForm2Digits=string_to_int(s.substr(idx,2))<=26;
        return canForm2Digits+f(s,idx+1);
    }
    if(dp[idx]!=-1) return dp[idx];
    bool canForm2Digits=string_to_int(s.substr(idx,2))<=26;
    return dp[idx]=f(s,idx+1)+((canForm2Digits) ? f(s,idx+2):0);
}

int numDecodings(string s) {
    dp.clear();
    dp.resize(105,-1);
    return f(s,0);
}

-Bottom Up Approach

int string_to_int(string s){
    if(s.size()==1) return s[0]-'0';
    return (s[0]-'0')*10 + s[1]-'0';
}

int fbu(string s){
    dp.clear();
    dp.resize(105,0);
    int n=s.size();

    dp[n-1] = (s[n-1]=='0') ? 0:1;
    bool canForm=string_to_int(s.substr(n-2,2))<=26;
    if(s[n-2]=='0') dp[n-2]=0;
    else dp[n-2] = dp[n-1] + (canForm);
    for(int i=n-3;i>=0;i--){
        if(s[i]=='0'){
            dp[i]=0;
            continue;
        }
        bool canForm2=string_to_int(s.substr(i,2))<=26;
        dp[i]=dp[i+1] + ((canForm2) ? dp[i+2]:0);
    }
    return dp[0];
}

int numDecodings(string s) {
    int n=s.size();
    if(n==1){
        if(s[n-1]!='0') return 1;
        else return 0;
    }
    return fbu(s);
}

-2. Coin Change

Given an integer array of coins[ ] of size N representing different types of currency and an integer sum,
The task is to find the number of ways to make a sum by using different combinations from coins[]. Assume
that you have an infinite supply of each type of coin.

-Top down

int change(int amount, vector<int>& coins) {
     int n=coins.size();
     vector<int> dp(10e+5,0);
     dp[0]=1;
     for(int j=0;j<n;j++){
         for(int i=1;i<=amount;i++){
             if(i-coins[j]<0) continue;
             dp[i]=dp[i]+dp[i-coins[j]];
         }
     }
     return dp[amount];
}

-Bottom Up

int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0); // Create DP array with all zeros
    dp[0] = 1; // Base case: one way to make sum 0

    // Fill the DP table
    for(int coin : coins) {
        for(int s = coin; s <= amount; s++) {
            dp[s] += dp[s - coin];
        }
    }
    return dp[amount];
}

-3.Frog-N

There are N stones, numbered 1,2,...,N. The height of ith stone is hi.
There is a frog who is initially on Stone 1. He will repeat an action some number of times to reach Stone N. The
action is that if the frog is currently on Stone i, it jumps to one of the following: Stone i+1,i+2,...,i+K. Here, a cost
of |hi - hj| is incurred, where j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone N.

-Top down Approach - f()
-Bottom up Approach - fbu()

#include "iostream"
#include "vector"
using namespace std;

vector<int> dp;
int f(vector<int> &height,int i,int k){
    if(i==height.size()-1) return 0;
    if(dp[i]!=-1) return dp[i];
    int ans=INT_MAX;
    for(int j=1;j<=k;j++){
        if(i+j>=height.size()) break;
        ans = min(ans,abs(height[i]-height[i+j])+f(height,i+j,k));
    }
    return dp[i]=ans;
}

int fbu(vector<int> height,int k){
    //off course clear and resize dp; -> dp.resize(100005,INT_MAX) -> not -1;
    int n=height.size();
    dp[n-1] = 0;
    for(int i=n-2;i>=0;i--){
        for (int j = 1; j <= k; ++j) {
            if(i+j>=n) break;
            dp[i]=min(dp[i],abs(height[i] - height[i+j])+dp[i+j])
        }
    }
    return dp[0];
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> height(n);
    for(int i=0;i<n;i++) cin>>height[i];
    dp.clear();
    dp.resize(100005,-1);
    cout<<f(height,0,k);
    return 0;
}

Output:-
5 3
10 30 40 50 20
30


*/



