/*

-And with these we have completed some good questions on Tree , these questions are most frequently asked questions
and are really important for understanding trees in DSA , so make sure to give them a thorough revision
and write the code down on both notebook as well as on VS code and dry run but the most important thing

-I found out was asking relevant question that is if we are uisng maps then why maps? if sets , then
why sets? asking such basics questions will help you a lot , they are hard to get at once so make sure
to have patience and give yourself time to understand them.

-1.Given the root of a binary tree and an integer targetSum, return the number of paths where 
the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards 
(i.e., traveling only from parent nodes to child nodes).

#include<iostream>
#include<unordered_map>
using namespace std;

class node{
public:
    int val;
    node* left;
    node* right;

    node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};

int targetSumHelper(node* root,int tarSum,int currSum,unordered_map<long int , int>& pathCount){
    //base-case
    if (root==NULL)
    {
        return 0;
    }
    currSum+=root->val;
    int ansSum=pathCount[currSum-tarSum]; //See below code 
    pathCount[currSum]++;
    ansSum+=targetSumHelper(root->left,tarSum,currSum,pathCount) + targetSumHelper(root->right,tarSum,currSum,pathCount);
    pathCount[currSum]--;
    return ansSum;
}

int targetSum(node* root,int tarSum){
    unordered_map<long int,int> pathCount;
    pathCount[0]=1;
    return targetSumHelper(root,tarSum,0,pathCount);
}

int main(){
    node* root=new node(10);
    root->left=new node(5);
    root->right=new node(-3);
    root->left->left=new node(3);
    root->left->right=new node(2);
    root->left->left->left=new node(3);
    root->left->left->right=new node(-2);
    root->left->right->right=new node(1);
    root->right->right=new node(11);
    cout<<"Number of pair for target sum in Binary Trees are : "<<targetSum(root,8);
    return 0;
}

// Output:-
// Number of pair for target sum in Binary Trees are : 3

The line `int ansSum = pathCount[currSum - tarSum];` is crucial for calculating the number of 
paths in a binary tree whose elements sum to a given target sum. Let's break down its significance in-depth:

1. **`currSum - tarSum`:** This part calculates the difference between the current sum (`currSum`) and the target sum (`tarSum`). 
The idea is to check how many times we've encountered a particular cumulative sum that, when subtracted from the current cumulative sum, 
results in the target sum. This is essentially identifying the number of paths leading to the current node that form the target sum.

2. **`pathCount[currSum - tarSum]`:** Here, we use the calculated difference as a key to access the `pathCount` unordered map. 
The `pathCount` map stores the count of cumulative sums encountered during the traversal of the tree.

   - If `pathCount[currSum - tarSum]` exists, it means that there are paths from some previous node to the current node whose sum equals 
   the target sum. So, we add the count stored at that key to our `ansSum`.
   
   - If `pathCount[currSum - tarSum]` doesn't exist, it means we haven't encountered a cumulative sum that, when subtracted from the 
   current cumulative sum, equals the target sum. In this case, the count for this key remains 0.

3. **`ansSum`:** This variable keeps track of the total count of paths encountered so far in the recursion that satisfy the target sum 
condition. It is incremented by the count of paths identified in the current node based on the cumulative sum and the target sum.

This approach is essentially using a running count of cumulative sums encountered during the traversal, and for each node, it checks 
how many paths lead to that node that satisfy the target sum condition. This count is then added to the overall count (`ansSum`). 
The recursion continues to explore the entire tree, accumulating the counts for different paths that meet the target sum condition.

-2.Binry Tree Maximum path Sum - A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence 
has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to
pass through the root.The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.


#include<iostream>
using namespace std;

class node{
public:
    int val;
    node* left;
    node* right;

    node(int data){
        val=data;
        left=right=NULL;
    }
};

int maxPathSumHelper(node* root,int& maxSum){
    //base-case
    if (root==NULL)
    {
        return 0;
    }
    int leftSum=max(0,maxPathSumHelper(root->left,maxSum));
    int rightSum=max(0,maxPathSumHelper(root->right,maxSum));
    maxSum=max(maxSum,root->val+leftSum+rightSum);
    return root->val+max(leftSum,rightSum);
}

int maxPathSum(node* root){
    int maxSum=INT8_MIN;
    maxPathSumHelper(root,maxSum);
    return maxSum;
}

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    cout<<"Max. Sum in the path is : "<<maxPathSum(root);
    return 0;
}

-Time and space complexity : O(N); 

// Output:-
// Max. Sum in the path is : 6

-3.Construct binary tree from preorder and inorder traversal - Given two integer arrays preorder and inorder where preorder is 
the preorder traversal of a Binary tree and inorder is the inorder traversal of the same tree, construct and return the Binary tree.

Preorder- root->left->right
Inorder - left->root->right
Postorder - left->right->root

-This code will only work for non-duplicate elements , the moment you will have duplicate elements map will give you problem
 as it doesn't allow to store duplicate elements.
 -SEE GFG for its solution.

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class node{
public:
    int value;
    node* left;
    node* right;
    node(int data){
        value=data;
        left=right=NULL;
    }
};

node* buildTreeHelper(vector<int>& preorder,int prestart,int preend , vector<int>& inorder,int instart, int inend,unordered_map<int,int> imap){
    //base-case
    if (prestart>preend || instart>inend)
    {
        return NULL;
    }
    node* rootNode=new node(preorder[prestart]);
    int rootIndex=imap[preorder[prestart]];
    int leftSubtreeSize=rootIndex-instart;
      
    rootNode->left= buildTreeHelper(preorder,prestart+1,prestart+leftSubtreeSize,inorder,instart,rootIndex-1,imap);
    rootNode->right= buildTreeHelper(preorder,prestart+leftSubtreeSize+1,preend,inorder,rootIndex+1,inend,imap);
    

    return rootNode;
}

node* buildTree(vector<int> &preorder,vector<int> &inorder){
    unordered_map<int,int> imap;
    for (int i = 0; i < inorder.size(); i++)
    {
        imap[inorder[i]]=i;
    }
    
    return buildTreeHelper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,imap);

}

void preorderTraversal(node* root){
    if (root==NULL)
    {
        return;
    }
    cout<<root->value<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main(){
    vector<int> pre={1,2,4,5,3,6,7};
    vector<int> in={4,5,2,6,7,3,1};
    node* root;
    root=buildTree(pre,in);
    cout<<"Answer Tree is : ";
    preorderTraversal(root);
}

// Output:-
// Answer Tree is : 1 2 4 5 3 6 7 

-4.Construct Binary Tree from Preorder and Postorder Traversal - Given two integer arrays, preorder 
and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder 
is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.

-This is done by ChatGpt as I was facing too many errors in writing the code

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = right = NULL;
    }
};

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        unordered_map<int, int> postmap;

        // Create a mapping of postorder values to their indices
        for (int i = 0; i < post.size(); i++) {
            postmap[post[i]] = i;
        }

        // Start the construction from the root node
        return buildTree(pre, 0, pre.size() - 1, postmap, 0, post.size() - 1);
    }

    TreeNode* buildTree(vector<int>& pre, int prestart, int preend, unordered_map<int, int>& postmap, int poststart, int postend) {
        // Base-case
        if (prestart > preend || poststart > postend) {
            return NULL;
        }

        // Create the root node using the current preorder value
        TreeNode* root = new TreeNode(pre[prestart]);

        if (prestart == preend) {
            return root;
        }

        // Find the index of the next element in postorder in the range [poststart, postend]
        int nextElementIndex = postmap[pre[prestart + 1]];

        // Calculate the size of the left subtree
        int leftSubtreeSize = nextElementIndex - poststart + 1;

        // Recursively build the left and right subtrees
        root->left = buildTree(pre, prestart + 1, prestart + leftSubtreeSize, postmap, poststart, nextElementIndex);
        root->right = buildTree(pre, prestart + leftSubtreeSize + 1, preend, postmap, nextElementIndex + 1, postend - 1);

        return root;
    }
};

void displayBT(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int nodesAtCurrLevel = q.size();

        while (nodesAtCurrLevel--) {
            TreeNode* currNode = q.front();
            q.pop();

            cout << currNode->val << " ";

            if (currNode->left != NULL) {
                q.push(currNode->left);
            }

            if (currNode->right != NULL) {
                q.push(currNode->right);
            }
        }

        cout << endl;
    }
}

int main() {
    vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    vector<int> post = {4, 5, 2, 6, 7, 3, 1};

    Solution sol;
    TreeNode* root = sol.constructFromPrePost(pre, post);

    cout << "Constructed Binary Tree:" << endl;
    displayBT(root);

    return 0;
}

// Output:-
// Constructed Binary Tree:
// 1
// 2 3
// 4 5 6 7

-Making Tree from Inorder and Postorder - Did it myself!! , Here I am only sharing main code that I have wriiten
in LeetCode

class Solution {
public:

    TreeNode* buildTreeHelper(vector<int>& inorder,int instart,int inend,vector<int>& postorder,int poststart,int postend,unordered_map<int,int>& inmap){
        //base-case
        if(instart>inend || poststart>postend){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[postend]);
        if(poststart==postend){
            return root;
        }
        int leftSubEle=inmap[postorder[postend]];
        int leftSubSize=leftSubEle-instart-1;
        root->left=buildTreeHelper(inorder,instart,leftSubEle,postorder,poststart,poststart+leftSubSize,inmap);
        root->right=buildTreeHelper(inorder,leftSubEle+1,inend,postorder,poststart+leftSubSize+1,postend-1,inmap);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        return buildTreeHelper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inmap);
    }
};

-5.Flatten Binary Tree to Linked List - Given the root of a binary tree, flatten the tree into a 
"linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next 
node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.


#include<iostream>
using namespace std;
class node{
public:
    int value;
    node* left;
    node* right;

    node(int data){
        value=data;
        left=right=NULL;
    }
};

class solution{
public:
    node* last=NULL;
    void flatten(node* root){
        if (root==NULL)
        {
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->right=last;
        root->left=NULL;
        last=root;
    }

    void display(node* root){
        while (root!=NULL)
        {
            cout<<root->value<<" -> ";
            root=root->right;
        }
        cout<<"NULL";
        return;
    }
};

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(5);
    root->right->right=new node(6);
    root->left->left=new node(3);
    root->left->right=new node(4);
    solution sol;
    sol.flatten(root);
    sol.display(root);
    return 0;

}

// Output:-
// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL

-6.Amount of Time for Binary Tree to Be Infected - You are given the root of a binary tree with unique 
values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.


#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

class node{
public:
    int val;
    node* left;
    node* right;
    node(int data){
        val=data;
        left=right=NULL;
    }
};

int calTime(node* start,unordered_map<node*,node*>& parent){
    int ans=0;
    unordered_set<node*> infected;
    infected.insert(start);
    queue<node*> q;
    q.push(start);
    while (!q.empty())
    {
        int nodesAtcurrLevel=q.size();
        bool infect=false;
        while (nodesAtcurrLevel--)
        {
            node* currNode=q.front();
            q.pop();
            //checking for left - right child and parent
            if (currNode->left && !infected.count(currNode->left))
            {
                infected.insert(currNode->left);
                q.push(currNode->left);
                infect=true;
            }
            if (currNode->right && !infected.count(currNode->right))
            {
                infected.insert(currNode->right);
                q.push(currNode->right);
                infect=true;
            }
            if (parent[currNode] && !infected.count(parent[currNode]))
            {
                infected.insert(parent[currNode]);
                q.push(parent[currNode]);
                infect=true;
            }
                     
        }
        if(infect) ans++;

    }
    return ans;
    

}

node* makeParent(node* root,unordered_map<node*,node*>& parent,int start){
    node* startN=NULL;
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        node* currNode=q.front();
        q.pop();
        if (currNode->val==start)
        {
            startN=currNode;
        }
        if (currNode->left)
        {
            parent[currNode->left]=currNode;
            q.push(currNode->left);
        }
        if (currNode->right)
        {
            parent[currNode->right]=currNode;
            q.push(currNode->right);
        }
        
        
    }
    return startN;
}

int timeToInfect(node* root,int start){
    unordered_map<node*,node*> parent; // To store child-parent node pair 
    node* startNode=makeParent(root,parent,start);
    return calTime(startNode,parent);
}

int main(){
    node* root=new node(1);
    root->left=new node(5);
    root->left->right=new node(4);
    root->left->right->left=new node(9);
    root->left->right->right=new node(2);
    root->right=new node(3);
    root->right->right=new node(6);
    root->right->left=new node(10);
    cout<<"Time to infect the Binary Tree is : "<<timeToInfect(root,3)<<" min";
    return 0;
}

// Output:-
// Time to infect the Binary Tree is : 4 min


*/
#include "iostream"
using namespace std;
int main(){
    cout<<bool(int());  //Output - 0 i.e. False
    return 0;
}