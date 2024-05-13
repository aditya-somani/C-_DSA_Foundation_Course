/*
 *
 * And with these set of questions , I have finally completed Dynamic programming , This concept was really filled with mind blowing
questions and intiutions which I have to revise very thoroughly  .

 So,get a good grasp of DP , its gonna be really really important for you journey and it took more than required time

 AS i CHICKNED OUT in middle due to the difficulty of questions but  still I got my courage together and still tried and
 now I am gratefull that I did it.

 -Thanks have a good Day Ahead!




-1.Regex Matching

Given an input string s and a pattern p, implement regular expression matching with support for the following special characters:

'.' matches any single character.
'*' matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).


-Top Down

vector<vector<int>> dp;
bool match(string& s,string& p,int i,int j){
    if(j==p.size()) return i==s.size();
    if(dp[i][j]!=-1) return dp[i][j];
    if(j+1<p.size() && p[j+1]=='*'){
        return dp[i][j]=(match(s,p,i,j+2) or (i<s.size() and (s[i]==p[j] or p[j]=='.') ? match(s,p,i+1,j):false));
    }else if(i<s.size() and (s[i]==p[j] or p[j]=='.')){
        return dp[i][j]=match(s,p,i+1,j+1);
    }else{
        return false;
    }
}

bool isMatch(string s, string p) {
    dp.clear();
    dp.resize(25,vector<int> (25,-1));
    return match(s,p,0,0);
}

-Top Down - I didn't got it neither understood it.

bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            } else {
                dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            }
        }
    }
    return dp[m][n];
}


-2.House Robber III

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in
 this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into
 on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

unordered_map<TreeNode*,int> unRobbed;
unordered_map<TreeNode*,int> robbed;
int robber(TreeNode* root,bool isRobbed){
    //isRobbed -> tells us the status of parent node , if it has been robbed or not
    if(root==NULL) return 0;
    if(isRobbed){
        if(robbed.find(root)!=robbed.end()){
            return robbed[root];
        }
        int ans= robber(root->left,false) + robber(root->right,false);
        return robbed[root]=ans;
    }else{
        if(unRobbed.find(root)!=unRobbed.end()){
            return unRobbed[root];
        }
        int c1= root->val+robber(root->left,true)+robber(root->right,true);
        int c2= robber(root->left,false)+robber(root->right,false);
        return unRobbed[root]=max(c1,c2);
    }
}

int rob(TreeNode* root) {
    robbed.clear();
    unRobbed.clear();
    return robber(root,false);
}


 */










