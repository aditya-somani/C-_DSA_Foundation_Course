/*
-And with that my Friend we have completed some really good and VERY IMP questions on Binary Search Trees which is
 one of the most IMP topics in DSA so, make sure that you do a good revision and enjoy again solving this questions as much as
 you want!!


 -1.Check if the given Tree is Binary Search Tree or not!

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

bool isBSTHelper(node* root,int minvalue,int maxvalue){
    if (root==NULL)
    {
        return true;
    }
    if (root->val<minvalue || root->val>maxvalue)
    {
        return false;
    }
    return isBSTHelper(root->left,minvalue,root->val) && isBSTHelper(root->right,root->val,maxvalue);
}

bool isBSTHelperUsingPrev(node* root,node* &prev){
    
}

bool isBST(node* root){
    return isBSTHelper(root,INT_MIN,INT_MAX);
}

int main(){
    node* root = new node(1);
    root->left=new node(2);
    root->right=new node(3);
    if (isBST(root))
    {
        cout<<"Yes , given tree is BST ";
    }
    else{
        cout<<"NO , given tree is not BST ";
    }
    return 0;
    
}

// Output:-
// NO , given tree is not BST


-Another way to do the same question is by doing a inorder traversal and check if it is sorted or not.

 //Method -2

bool isBSThelper(Node* root , Node* &prev){

    //base-case
    if(root==NULL){
        return true;
    }

    //As we are traversing inorder wise , first we will go to left
    if(!isBSThelper(root->left,prev)){
        return false;
    }
    //now check if value is smaller than previous or not and then update prev
    if(prev!=NULL && root->data <= prev->data){
        return false;
    }
    prev=root; // updated previous
    return isBSThelper(root->right,prev);
}

//Function to check whether a Binary Tree is BST or not.
bool isBST(Node* root)
{
    Node* prev=NULL;
    return isBSThelper(root,prev);
}

2.BSTs are identical - ive two vectors that represet a sequece of keys. Imagie we make a Biary Search Tree (BST) from each
 array. We need to tell whether two BSTs will be identical or not without actually constructing the tree.


#include "iostream"
#include "vector"
using namespace std;

bool checkIdenticalBSThelper(vector<int> &v1,vector<int> &v2,int a1,int a2,int minvalue,int maxvalue){
    //find the first element in v1 within the range
    int i;
    for (i=a1;i< v1.size(); i++) {
        if(v1[i]>minvalue && v1[i]<maxvalue) break;
    }
    //find the first element in v2 within the range
    int j;
    for (j = a2; j < v2.size(); j++) {
        if (v2[j]>minvalue && v2[j]<maxvalue) break;
    }
    //if no elements is found within the range (leaf nodes )
    if (i==v1.size() && j==v2.size()) return true;

    //if only one vector does not have element within range
    if ((i==v1.size() && j!=v2.size()) && (i!=v1.size() && j==v2.size())){
        return false;
    }

    //if both elements are not equal
    if (v1[i]!=v2[j]) return false;

    //recursively check for left and right subtree
    return checkIdenticalBSThelper(v1,v2,a1+1,a2+1,minvalue,v1[i]) &&
            checkIdenticalBSThelper(v1,v2,a1+1,a2+1,v1[i],maxvalue);

}

bool checkIdenticalBST(vector<int> &v1,vector<int> &v2){
    return checkIdenticalBSThelper(v1,v2,0,0,INT_MIN,INT_MAX);
}

int main(){
    cout<<"Enter the size of BST's : ";
    int n;cin>>n;
    cout<<"Enter the elements of first BST : ";
    vector<int> v1(n),v2(n);
    for (int i = 0; i < n; ++i) {
        cin>>v1[i];
    }
    cout<<"Enter the elements of second BST's : ";
    for (int i = 0; i < n; ++i) {
        cin>>v2[i];
    }
    if (checkIdenticalBST(v1,v2)){
        cout<<"Yes , the arrays form identical BST's ";
    }
    else{
        cout<<"No , they don't form identical BST's ";
    }
    return 0;
}

Output:-
Enter the size of BST's :5
Enter the elements of first BST :4 2 5 1 3
Enter the elements of second BST's :4 5 2 3 1
Yes , the arrays form identical BST's

-3. Given the preorder traversal of a BST , construct a BST

 -Mam Solved it by only checking for upperbound only , but as i tried it myself so I kept track of both
 lowerbound as well as upperbound .

 -A major mistake I did due to which I had to invest hours debugging was not making prestart pass by reference.

#include "iostream"
#include "vector"
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=right=NULL;
    }
};

void display(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" -> ";
    display(root->left);
    display(root->right);
}

TreeNode* bstFromPreorderHelper(vector<int> &preorder,int &prestart,int lbound,int ubound){
    //base-case
    if (prestart>=preorder.size()) return NULL;
    if (preorder[prestart]<lbound) return NULL;
    if (preorder[prestart]>ubound) return NULL;
    TreeNode* root=new TreeNode(preorder[prestart]);
    prestart++;
    root->left=bstFromPreorderHelper(preorder,prestart,lbound,root->val);
    root->right=bstFromPreorderHelper(preorder,prestart,root->val,ubound);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    //TreeNode* root=new TreeNode(preorder[0]);
    int prestart=0;
    return bstFromPreorderHelper(preorder,prestart,INT_MIN,INT_MAX);
}
int main(){
    vector<int> v={8,5,1,7,10,12};
    display(bstFromPreorder(v));
    return 0;
}

Output:-
8 -> 5 -> 1 -> 7 -> 10 -> 12 ->

-4.Largest BST in Binary Tree - Given a Binary Tree, write a function that returns the size of the largest subtree which is also a Binary
Search Tree (BST). If the complete Binary Tree is BST, then return the size of the whole tree.

This question is Similar to above one and has been Solved , so it is now your job to do the above one by yourself

-4*.Maximum Sum BST in Binary Tree - Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also
 a Binary Search Tree (BST).

Assume a BST is defined as follows:

-The left subtree of a node contains only nodes with keys less than the node's key.
-The right subtree of a node contains only nodes with keys greater than the node's key.
-Both the left and right subtrees must also be binary search trees.

 Solution:-

class NodeInfo{
public:
    int minValue;
    int maxValue;
    int maxSum;
    NodeInfo(int min,int max,int sum){
        minValue=min;
        maxValue=max;
        maxSum=sum;
    }
};

class Solution {
public:
    int ans=0;
    NodeInfo maxSumBSTHelper(TreeNode* root){
        //base-case
        if(root==NULL){
            return NodeInfo(INT_MAX,INT_MIN,0);
        }
        NodeInfo leftSubTree = maxSumBSTHelper(root->left);
        NodeInfo rightSubTree = maxSumBSTHelper(root->right);
        //check condition for it be BST
        if(root->val > leftSubTree.maxValue && root->val < rightSubTree.minValue){
            //then it is my BST
            ans=max(ans,leftSubTree.maxSum+rightSubTree.maxSum+root->val);
            return NodeInfo(min(leftSubTree.minValue,root->val),max(rightSubTree.maxValue,root->val),leftSubTree.maxSum
            +rightSubTree.maxSum+root->val);
        }
        //If it is not a BST
        return NodeInfo(INT_MIN,INT_MAX,max(leftSubTree.maxSum,rightSubTree.maxSum));
    }

    int maxSumBST(TreeNode* root) {
        maxSumBSTHelper(root); //If we were only finding maxSize then till here would hhave been enough but we are finding maxSum with
        -ve values also
        return ans;
    }
};

-5.Unique Binary Search Trees - Given an integer n, return all the structurally unique BST's (binary search trees), which
 has exactly n nodes of unique values from 1 to n. Return the answer in any order.


 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 *
class Solution {
public:

    vector<TreeNode*> generateTreesHelper(int start,int end){
        vector<TreeNode*> ans;
        //base-case
        if(start>end){
            ans.push_back(NULL);
            return ans;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*> leftSubTrees=generateTreesHelper(start,i-1);
            vector<TreeNode*> rightSubTrees=generateTreesHelper(i+1,end);

            for(TreeNode* leftSubTree:leftSubTrees){
                for(TreeNode* rightSubTree:rightSubTrees){
                    TreeNode* root=new TreeNode(i);
                    root->left=leftSubTree;
                    root->right=rightSubTree;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return  generateTreesHelper(1,n);
    }
};

-6.Replace with greater element on right - Given an array of integers, replace every element with the least greater element on
 its right side in the array. If there are no greater elements on the right side, replace it with -1.


#include "iostream"
#include "vector"
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=right=NULL;
    }
};

TreeNode* insert(TreeNode* root,int element,int& succ){

    //base-case
    if (root==NULL){
        return new TreeNode(element);
    }
    if (element<root->val){
        succ=root->val;
        root->left= insert(root->left,element,succ);
    }
    else if(element>root->val){
        root->right= insert(root->right,element,succ);
    }
    return root;
}

void lge(vector<int> &v){
    TreeNode* root=NULL;
    for (int i = v.size()-1; i >= 0 ; i--) {
        int succ=-1;
        root=insert(root,v[i],succ);
        v[i]=succ;
    }

    return;
}

int main(){
    cout<<"Enter the size of array : ";
    int n;cin>>n;
    cout<<"Enter the array whose least greater array you want : ";
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    cout<<"Least Greater Element array is : ";
    lge(v);
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<" ";
    }
    return 0;
}

Output:-
Enter the size of array :7
Enter the array whose least greater array you want :8 3 10 1 6 9 14
Least Greater Element array is : 9 6 14 6 9 14 -1


*/





