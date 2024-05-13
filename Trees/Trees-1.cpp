/*

-And with that we have completed trees intro and basics questions on trees , if you are learning trees first time then one suggestion
will be that don't get overwhelmed and make yourself feel inferior or down if you can't grasp the concept in one iteration , cause trees 
requires time and effort if you are like a me (average mind but hardworking) then just give yourself time and you will be good .

-Second make sure to write the code as well dry run the code on notebook it will provide a deeper understanding of concept and yes they
at first they are not that intiutive so , don't worry as I said time will solve everything like how it everytime does.

-HAVE A GOOD DAY AHEAD!!!


So, before starting actual Trees , first we are gonna learn a little about data structures 

-Data structures means the structure in which we can represent our data 

There are two types of data :- Linear and Non-Linear 

-All our previous data structures like :- arrays , linked list , queues , vectors , hashmap , stacks are 
Linear data structures

and Non-Linear structures are which data is stored in hierachy i.e. data is stored in some hierachial order

ex:- Trees , Graphs

-Trees - It is a Non-Linear data structure which stores hierachial data
       - Elements are stored at different levels  
       - These elements are called Nodes - which are connected/linked together to represent hierachy
       - Top most node is called Root Node. -> Tree is represented by Root node only
       - Every node will contain data and links to other successor nodes/descendant nodes
    
-Terminology :-

1.Root Node - Top most node - Not a child node - has NO parent node
2.Child Node - successor/descendant of any node 
3.Parent Node - predecessor of any node 
4.Siblings Node - Nodes with common parent node 
5.Leaf Node - which have no child nodes i.e. last nodes of tree
6.Number of edges - Link between two nodes - Unidirectional -> from parent node to child node 
7.Level - Number from edges from root nodes
8.Height - Maximum number of edges between a leaf node and root node
9.Size -  Number of nodes in my tree -> if there are 'n' nodes -> (n-1) edges
10.SubTree - Tree which is a child of a node  

-Types of Trees :-

1.Generic Tree - A node can have any number of child nodes
2.Binary Tree - A node can have maximum two child nodes - can have 0,1,2
3.**Binary Search Tree** - A Binary tree in which all left subtree will have value less than root node and all right subtree will have 
                       value greater than root node (Very IMP!!)
4.AVL Trees - Self balancing trees - Difference between heights of left subtree and right subtree can be 1,0,-1 - Start it from leaf node

-Binary Trees - Every node can have max. two child nodes and each node will contain data and Link to left and right child node if present 
              - if left or right node not present then it will point towards "NULL"
              - Leaf nodes will have both nodes pointing towards NULL

-Implementation of Node class -> [left-Data-right] -if any chlid does not exist then it will point towards NULL 


#include<iostream>
using namespace std;

class node{
public:
    int value;
    node* left;
    node* right;

    node(int val){
        value=val;
        left=right=NULL;
    }
};

int main(){
    node* root=new node(2);
    root->left=new node(3);
    root->right=new node(4);

    cout<<"Root node : "<<root->value<<endl;
    cout<<"left node : "<<root->left->value<<endl;
    cout<<"Right node : "<<root->right->value<<endl;

    return 0;
}

// Output:-
// Root node : 2
// left node : 3
// Right node : 4

-Traversals in Trees 

I. DFS (Depth-First-Search) -  travels along the height , first upar se niche

-Types in DFS -

-1.Preorder - We visit the root node , then left subtree and then right subtree REURSIVELY

#include<iostream>
using namespace std;

class node{
public:
    int value;
    node* left;
    node* right;

    node(int val){
        value=val;
        left=right=NULL;
    }

};

void preorderTraversal(node* rootNode){
    //base-case
    if (rootNode==NULL)
    {
        return;
    }

    cout<<rootNode->value<<" ";
    //recursive call
    preorderTraversal(rootNode->left);
    preorderTraversal(rootNode->right);
}

int main(){
    node* root = new node(2);
    root->left=new node(4);
    root->right=new node(10);
    root->left->left=new node(6);
    root->left->right=new node(5);
    root->right->right=new node(11);

    preorderTraversal(root);
    return 0;
}

// Output:- 2 4 6 5 10 11

2.Inorder - visit the left subtree , root node , right subtree using recursion


#include<iostream>
using namespace std;

class node{
public:
    int value;
    node* left;
    node* right;

    node(int val){
        value=val;
        left=right=NULL;
    }

};

void inorderTraversal(node* rootNode){
    if (rootNode==NULL)
    {
        return;
    }

    //recursive call
    inorderTraversal(rootNode->left);
    cout<<rootNode->value<<" ";
    inorderTraversal(rootNode->right);
}

int main(){
    node* root = new node(2);
    root->left=new node(4);
    root->right=new node(10);
    root->left->left=new node(6);
    root->left->right=new node(5);
    root->right->right=new node(11);

    inorderTraversal(root);
    return 0;
}

// Output:- 6 4 5 2 10 11

-3.Postorder - visit left subtree , right subtree and then root node usig recursion

#include<iostream>
using namespace std;

class node{
public:
    int value;
    node* left;
    node* right;

    node(int val){
        value=val;
        left=right=NULL;
    }

};

void postorderTaversal(node* rootNode){
    //base-case
    if (rootNode==NULL)
    {
        return;
    }
    

    //recursive call
    postorderTaversal(rootNode->left);
    postorderTaversal(rootNode->right);
    cout<<rootNode->value<<" ";
}

int main(){
    node* root = new node(2);
    root->left=new node(4);
    root->right=new node(10);
    root->left->left=new node(6);
    root->left->right=new node(5);
    root->right->right=new node(11);

    postorderTaversal(root);
    return 0;
}

// Output:- 6 5 4 11 10 2 

II.Breadth First Search (BFS) - First we search entire level i.e. sibling nodes 

1.Levelorder - first root node then , its child nodes and then child nodes of left and child nodes of right and so on!

#include<iostream>
#include<queue>
using namespace std;

class node{
public:
    int value;
    node* left;
    node* right;

    node(int val){
        value=val;
        left=right=NULL;
    }
    
};

void levelorderTraversal(node* rootNode){
    if (rootNode==NULL)
    {
        return;
    }
    queue<node*> q;
    q.push(rootNode);

    while (!q.empty())
    {
        int nodesAtCurrentLevel=q.size();
        while (nodesAtCurrentLevel--)
        {
            node* currNode=q.front();
            q.pop();
            if (currNode->left) //cuurNode->left!=NULL
            {
                q.push(currNode->left);
            }
            if (currNode->right)
            {
                q.push(currNode->right);
            }
            cout<<currNode->value<<" ";
            
        }
        cout<<endl;
    }
    
}

int main(){
    node* root = new node(2);
    root->left=new node(4);
    root->right=new node(10);
    root->left->left=new node(6);
    root->left->right=new node(5);
    root->right->right=new node(11);

    levelorderTraversal(root);
    return 0;
}

// Output:-
// 2 
// 4 10 
// 6 5 11

-QUESTIONS!!

1.​ Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to
the farthest leaf node.


#include<iostream>
#include<queue>
using namespace std;

class node{
public: 
    int value;
    node* left;
    node* right;
    node(int data ){
        value=data;
        left=right=NULL;
    }
};
// BY ME!!
// void maxDepth(node* rootNode){
//     if (rootNode==NULL)
//     {
//         return;
//     }
//     queue<node*> q;
//     q.push(rootNode);
//     int ans=0;
//     while (!q.empty())
//     {
//         int currSize=q.size();
//         while (currSize--)
//         {
//             node* currNode=q.front();
//             q.pop();
//             if (currNode->left)
//             {
//                 q.push(currNode->left);
//             }
//             if (currNode->right)
//             {
//                 q.push(currNode->right);
//             }
            
//         }
//         ans++;
//     }
//     cout<<"Max. depth is : "<<ans;
// }

//BY MAM!

int maxDepth(node* root){
    
    //base-case
    if (root==NULL)
    {
        return 0;
    }
    

    //recursive case
    int leftDepth=maxDepth(root->left);
    int rightDepth=maxDepth(root->right);
    return (max(leftDepth,rightDepth)+1);
}

int main(){
    node* root = new node(2);
    root->left=new node(3);
    root->right=new node(4);
    root->left->left=new node(5);
    root->left->right=new node(6);
    cout<<"Max. Depth is : "<<maxDepth(root);
    return 0;
}

// Output:-
// Max. Depth is : 3

2.Calculate number of leaf nodes of a tree

#include<iostream>
#include<queue>
using namespace std;

class node{
public: 
    int value;
    node* left;
    node* right;
    node(int data ){
        value=data;
        left=right=NULL;
    }
};

int leafNode(node* root){
    //base-case
    if (root==NULL)
    {
        return 0;
    }
    if (root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    
    
    //recursive case
    int leftSubtreeLeafNodes=leafNode(root->left);
    int rightSubtreeLeafNodes=leafNode(root->right);

    return leftSubtreeLeafNodes+rightSubtreeLeafNodes;
}

int main(){
    node* root = new node(2);
    root->left=new node(3);
    root->right=new node(4);
    // root->left->left=new node(5);
    // root->left->right=new node(6);
    
    cout<<"Number of leaf node are : "<<leafNode(root);
    return 0;
}

// Output:- Number of leaf node are : 2

3. Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the
nodes you can see from top to bottom.


#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class node{
public: 
    int value;
    node* left;
    node* right;
    node(int data ){
        value=data;
        left=right=NULL;
    }
};

vector<int> rightView(node* root){
    vector<int> ans;
    
    //base-case
    if (root==NULL)
    {
        return ans;
    }
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        int currNodesAtLevel=q.size();
        while (currNodesAtLevel)
        {
            node* currnode=q.front();
            q.pop();
            if (currNodesAtLevel==1)
            {
                ans.push_back(currnode->value);
            }
            if (currnode->left)
            {
                q.push(currnode->left);
            }
            if (currnode->right)
            {
                q.push(currnode->right);
            }
            currNodesAtLevel--;
        }
        
    }
    return ans;
}

int main(){
    node* root = new node(2);
    root->left=new node(4);
    root->right=new node(10);
    root->left->left=new node(6);
    root->left->right=new node(5);
    root->right->right=new node(11);
    root->left->right->left=new node(12);
    
    cout<<"Right most node are : ";
    vector<int> v=rightView(root);
    for(auto i:v){
        cout<<i<<" ";
    }
    
    return 0;
}

// Output:- 
// Right most node are : 2 10 11 12 

-4.Given a binary tree. Print the top view of the binary tree. Top view of a binary tree is the set of nodes
visible when the tree is viewed from the top.


#include<iostream>
#include<vector>
#include<map>
#include<queue>
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

vector<int> topView(node* root){
    vector<int> ans;
    if (root==NULL)
    {
        return ans;
    }
    queue<pair<node*,int>> q;  //int -> represent column number of node
    q.push(make_pair(root,0));
    map<int,int> m;

    while (!q.empty())
    {
        int nodesAtCurrLevel=q.size();
        while (nodesAtCurrLevel--)
        {
            pair<node*,int> p=q.front();
            node* currNode=p.first;
            int currCol=p.second;
            q.pop();

            if (m.find(currCol)==m.end())
            {
                m[currCol]=currNode->value;
            }
            if (currNode->left)
            {
                q.push(make_pair(currNode->left,currCol-1));
            }
            if (currNode->right)
            {
                q.push(make_pair(currNode->right,currCol+1));
            }
            
            
        }
        
    }
    for(auto i:m){
        ans.push_back(i.second);
    }
    return ans;
}

int main(){
    node* root = new node(2);
    root->left=new node(4);
    root->right=new node(10);
    root->left->left=new node(6);
    root->left->right=new node(5);
    root->right->right=new node(11);
    root->left->right->left=new node(12);
    
    cout<<"Node's when viewed from top are : ";
    vector<int> v=topView(root);
    for(auto i:v){
        cout<<i<<" ";
    }
    
    return 0;
}

// Output:-
// Node's when viewed from top are : 6 4 2 10 11 

-5.[H.W.] Given a binary tree. Print the bottom view of the binary tree. Bottom view of a binary tree is the set of nodes
visible when the tree is viewed from the bottom.

-DONE BY MYSELF! WITHOUT ANY HELP AND DRIED RUN AND EXPLAINED EVERYTHING TO MYSELF!!

#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

vector<int> bottomView(node* root){
    vector<int> ans;
    //base-case
    if (root==NULL)
    {
        return ans;
    }
    queue<pair<node*,int>> q;
    q.push(make_pair(root,0));
    map<int,int> m;
    while (!q.empty())
    {
        int nodesAtcurrLevel=q.size();
        while (nodesAtcurrLevel--)
        {
            pair<node*,int> p=q.front();
            node* currNode=p.first;
            int currCol=p.second;
            q.pop();
            m[currCol]=currNode->value;
            if (currNode->left)
            {
                q.push(make_pair(currNode->left,currCol-1));
            }
            if (currNode->right)
            {
                q.push(make_pair(currNode->right,currCol+1));
            }
            
        }
        
    }
    for(auto i:m){
        ans.push_back(i.second);
    }
    
}

int main(){
    node* root = new node(2);
    root->left=new node(4);
    root->right=new node(10);
    root->left->left=new node(6);
    root->left->right=new node(5);
    root->right->right=new node(11);
    root->left->right->left=new node(12);
    
    cout<<"Node's when viewed from bottom are : ";
    vector<int> v=bottomView(root);
    for(auto i:v){
        cout<<i<<" ";
    }
    
    return 0;
}

// Output:-
// Node's when viewed from bottom are : 6 12 5 10 11 

-6.Given a binary tree, print the level order in reverse manner i.e. print the last row first and then the rows
above.

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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

vector<int> reverseBT(node* root){
    vector<int> ans;
    //base-case
    if (root==NULL)
    {
        return ans;
    }
    queue<node*> q;
    q.push(root);
    stack<int> st;
    while (!q.empty())
    {
        int nodesAtCurrLevel=q.size();
        while (nodesAtCurrLevel--)
        {
            node* currNode=q.front();
            q.pop();
            st.push(currNode->value);
            if (currNode->right)
            {
                q.push(currNode->right);
            }
            if (currNode->left)
            {
                q.push(currNode->left);
            }
            
            
        }
        
    }
    int n=st.size();
    for (int i = 0; i < n; i++)
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;

}
int main(){
    node* root = new node(2);
    root->left=new node(4);
    root->right=new node(10);
    root->left->left=new node(6);
    root->left->right=new node(5);
    root->right->right=new node(11);
    root->left->right->left=new node(12);
    
    cout<<"Node's in reverse level order are : ";
    vector<int> v=reverseBT(root);
    for(auto i:v){
        cout<<i<<" ";
    }
    
    return 0;
}

// Output:-
// Node's in reverse level order are : 12 6 5 11 4 10 2 

*/

