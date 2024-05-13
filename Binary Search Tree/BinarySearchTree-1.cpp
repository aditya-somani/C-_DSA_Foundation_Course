/*

-And with that my friend , I have completed my introduction and understanding basic concepts of Binary Search Tree 
what an amazing concept and logic it is!! , Just give it a try as it not only teaches you about basics but also helped
me a lot with me gaining grip on recursions and also teaches just how IMP recursions are!

-It was quite the journey as now i am starting to get ill and my sleep as well as schedule are messed ipand college exams are at the door
but these are the days which really shows the dedication I have for my future and the focus that I desire .

So, thank YOU , give BST as many revision you can as they are one of the most if not the most IMP topics for DSA 
and one tip which I got :- Don't study DSA cause they are asked during interviews , study them cause they make you a better 
SOFTWARE ENGINEER 

-HAVE A GOOD DAY AHEAD!!!


-Binary Search Tree - In this all the elements in my left subtree are less than the root node and the 
elements in the right subtree are more than the root node and this is valid for all levels .

i.e. true for rootnodes of all subtrees

-Advantages :-

-Insertion , Deletion and searching will be in O(log N) with base 2 , time in average case
-Sorted order -> easier to find min and max element. leftmost-> minn and rightmost -> max

-Disadvantages :-

-In worst case - O(N) -> is skewed in one direction -> Unbalanced Tree
-So, we need to make this tree into balanced tree

-Application :-

-Data structures like sets , maps ,priority queues are implemented using binary search tree

-Traversal :- Same as Binary Tree , preorder , inorder , postorder , levelorder

-Insertion :- 

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

class BST{
public:
    node* root;

    BST(){
        root=NULL;
    }

    void insert(node* &root,int k){
        node* newNode = new node(k);
        //base-case
        if (root==NULL)
        {
            root=newNode;
            return;
        }
        node* curr=root;
        while (true)
        {
            if (curr->value > k)  //left subtree
            {
                if (curr->left==NULL)
                {
                    curr->left=newNode;
                    return;
                }
                curr=curr->left;
                
            }
            else{
                if (curr->right==NULL)
                {
                    curr->right=newNode;
                    return;
                }
                curr=curr->right;
                
            }
        }
        
    }

    void preOrderTraversal(node* root){
        if (root==NULL)
        {
            return;
        }
        preOrderTraversal(root->left);
        cout<<root->value<<" ";
        preOrderTraversal(root->right);
    }

    node* insertUsingRecursion(node* root,int k){
        node* newNode=new node(k);
        //base-case
        if (root==NULL)
        {
            return newNode;
        }
        if (root->value<k)
        {
            root->right=insertUsingRecursion(root->right,k);
        }
        else{
            root->left=insertUsingRecursion(root->left,k);
        }
        return root;
    }
};

int main(){
    BST bst;
    bst.root=bst.insertUsingRecursion(bst.root,3);
    bst.insertUsingRecursion(bst.root,1);
    bst.insertUsingRecursion(bst.root,4);
    bst.insertUsingRecursion(bst.root,6);
    bst.insertUsingRecursion(bst.root,2);
    bst.preOrderTraversal(bst.root);  
    return 0;
}

// Output:-
// 1 3 4 ->using iteration
// 1 2 3 4 6  -> using recursion

-Searching :-

#include<iostream>
#include<vector>
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

class BST{
public:
    node* root;

    BST(){
        root=NULL;
    }

    node* insertion(node* root,int k){
        node* newNode=new node(k);
        if (root==NULL)
        {
            return newNode;
        }
        if (root->val<k)
        {
            root->right=insertion(root->right,k);
        }
        else{
            root->left=insertion(root->left,k);
        }
        return root;
    }

    bool searchR(node* root,int k){
        if (root==NULL)
        {
            return false;
        }
        if (root->val==k)
        {
            return true;
        }
        if (root->val<k)
        {
            return searchR(root->right,k);
        }
        else{
            return searchR(root->left,k);
        }
    }

    bool searchI(node* root,int k){
        node* newNode=new node(k);
        if (root==NULL)
        {
            return false;
        }
        if (root->val==k)
        {
            return true;
        }
        node* curr=root;
        while (true)
        {
            if (curr->val<k)
            {
                if (curr->val==k)
                {
                    return true;
                }
                curr=curr->right;
            }
            else{
                if (curr->val==k)
                {
                    return true;
                }
                curr=curr->left;
            }
        }
        
        
    }
};

int main(){
    BST bst;int n;
    cout<<"Enter the number of node : ";
    cin>>n;
    vector<int> v;
    cout<<"Enter the nodes : ";
    for (int i = 0; i < n; i++)
    {
        if (i==0)
        {
            int m;
            cin>>m;
            v.push_back(m);
            bst.root=bst.insertion(bst.root,v[i]);
        }
        else{
            int k;
            cin>>k;
            v.push_back(k);
            bst.insertion(bst.root,v[i]);
        }
        
    }
    cout<<"Enter the number you want to search : ";
    int m;cin>>m;
    if (bst.searchR(bst.root,m)==true  &&  bst.searchI(bst.root,m)==true)  // just for unsertanding both ways 
    {
        cout<<"Yes , it present in binary tree ";
    }
    else{
        cout<<"NO , number is not present ";
    }
    return 0;
}

// Output:-
// Enter the number of node : 6
// Enter the nodes : 3 1 2 4 5 6
// Enter the number you want to search : 0
// NO , number is not present

-Deletion in BST :-

1.With '0' childs 

#include<iostream>
#include<stack>
#include<vector>
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

class BST{
public:
    node* root;

    BST(){
        root=NULL;
    }

    node* largestInLeftSub(node* root){
        node* curr=root;
        while (curr && curr->right)
        {
            curr=curr->right;
        }
        return curr;
    }

    node* insertion(node* root,int data){
        node* newNode=new node(data);
        if (root==NULL)
        {
            return newNode;
        }
        if (root->val<data)
        {
            root->right=insertion(root->right,data);
        }
        else{
            root->left=insertion(root->left,data);
        }
        return root;
    }

    node* deleteNode(node* root, int k){
        if (root==NULL)
        {
            return root;
        }
        if (root->val<k)
        {
            root->right = deleteNode(root->right,k);
        }
        else if (root->val>k)
        {
            root->left=deleteNode(root->left,k);
        }

// -When multiple if statements are there then it will evalute and check all the condition regardless if one is true or not i.e. it will 
// check for all and multiple code blocks may be executed , whereas in multiple if , else if , else if , if even one condition is true 
// then it will execute it and then will not chec the other conditions!

        else{  //root->val==k

            //with '0' child nodes
            if (root->left==NULL && root->right==NULL)
            {
                free(root);
                return NULL;
            }
            //with '1' child node
            else if (root->left==NULL)
            {
                node* temp=root->right;
                free(root);
                return temp;
            }
            else if (root->right==NULL)
            {
                node* temp=root->left;
                free(root);
                return temp;
            }
            //with '2' child node
            else{
                node* justSmallerEle=largestInLeftSub(root->left);
                root->val=justSmallerEle->val;
                root->left=deleteNode(root->left,justSmallerEle->val);

            }
        }
    }

    void preorder(node* root){
        if (root==NULL)
        {
            return;
        }
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);

    }
};

int main(){
    BST bst;
    vector<int> v;
    cout<<"Enter the nodes (-1 to stop) : ";
    while (true)
    {
        int i;int j=0;
        cin>>i;
        if (i==-1)
        {
            break;
        }
        if (j==0)
        {
            bst.root=bst.insertion(bst.root,i);
            j++;
        }
        else{
            bst.insertion(bst.root,i);
        }
        
    }
    cout<<"Enter the element(leaf node) you wish to delete : ";
    int m;cin>>m;
    bst.deleteNode(bst.root,m);
    cout<<"Changed tree is : ";
    bst.preorder(bst.root);
    return 0;
}

// Output:-
// Enter the nodes (-1 to stop) : 3 1 4 2 5 6 -1
// Enter the element(leaf node) you wish to delete : 3
// Changed tree is : 2 1 4 5 6 

-Here's a example that include all insertion , searching and deletion with how to display :- 

#include<iostream>
#include<vector>
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

class BST{
public:
    node* root;

    BST(){
        root=NULL;
    }

    node* insertion(node* root,int k){
        node* newNode=new node(k);
        if (root==NULL)
        {
            return newNode;
        }
        node* curr=root;
        if (curr->val<k)
        {
            curr->right=insertion(curr->right,k);
        }
        if (curr->val>k)
        {
            curr->left=insertion(curr->left,k);
        }
        return root;
        
    }

    bool searchBT(node* root,int k){
        if (root==NULL)
        {
            return false;
        }
        node* curr=root;
        if (curr->val==k)
        {
            return true;
        }
        if (curr->val<k)
        {
            return searchBT(curr->right,k);
        }
        if (curr->val>k)
        {
            return searchBT(curr->left,k);
        }
        return false;
    }

    node* smallest(node* root){
        node* curr=root;
        while (curr && curr->right)
        {
            curr=curr->right;
        }
        return curr;
    }

    node* deleteNode(node* root,int k){
        if (root==NULL)
        {
            return NULL;
        }
        if (root->val<k)
        {
            root->right=deleteNode(root->right,k);
        }
        else if (root->val>k)
        {
            root->left=deleteNode(root->left,k);
        }
        else{
            //0 child node 
            if (root->left==NULL && root->right==NULL)
            {
                free(root);
                return NULL;
            }
            //1 child node
            if (root->left==NULL)
            {
                node* temp=root->right;
                free(root);
                return temp;
            }
            if (root->right==NULL)
            {
                node* temp=root->left;
                free(root);
                return temp;
            }
            // 2 child nodes
            else{
                node* smallestValue=smallest(root); //I think it should be root->left
                root->val=smallestValue->val;
                root->left=deleteNode(root->left,smallestValue->val);
            }
            
        }
        
    }

    void preorder(node* root){
        if (root==NULL)
        {
            return;
        }
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
};

int main(){
    vector<int> v;
    BST bst;
    cout<<"Enter the nodes (-1 to exit ) : ";
    while (true)
    {
        int i,j=0;
        cin>>i;
        if (i==-1)
        {
            break;
        }
        if (j==0)
        {
            bst.root=bst.insertion(bst.root,i);j++;
        }
        else{
            bst.insertion(bst.root,i);
        }
    }
    cout<<"Enter the value you want search : ";
    int m;cin>>m;
    cout<<"Output : ";
    if (bst.searchBT(bst.root,m))
    {
        cout<<"Yes "<<endl;
    }
    else cout<<"No "<<endl;

    cout<<"Enter the node you want to delete : ";
    int x;cin>>x;
    bst.deleteNode(bst.root,x);
    cout<<"Output : ";
    bst.preorder(bst.root);
    return 0;
}

Output:-
Enter the nodes (-1 to exit ) : 3 1 4 2 5 6 -1
Enter the value you want search : 0
Output : No 
Enter the node you want to delete : 1
Output : 3 2 4 5 6 

-QUESTIONS :-

-1. Sorted Array to Balanced BST - Given a sorted array. Create a Balanced Binary Search Tree out of it.
A Balanced BST is height-balanced i.e. the difference between the height of the left subtree and right subtree is
not more than 1.
You need to print the preorder traversal of the BST created.


#include<iostream>
#include<vector>
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

class BST{
public: 
    node* root;
    BST(){
        root=NULL;
    }
};

node* vectorToBST(vector<int> &v,int start,int end){
    //base-case
    if (start>end)
    {
        return NULL;
    }
    int mid=(start+end)/2;
    node* root=new node(v[mid]);
    root->left=vectorToBST(v,start,mid-1);
    root->right=vectorToBST(v,mid+1,end);
    return root;
}

void preOrderTraversal(node* root){
    if (root==NULL)
    {
        return;
    }
    cout<<root->val<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main(){
    vector<int> v;
    cout<<"Enter the elements of vector ( -1 to exit ) : ";
    while (true)
    {
        int i;
        cin>>i;
        if (i==-1)
        {
            break;
        }
        v.push_back(i);
    }
    BST bst;
    bst.root=vectorToBST(v,0,v.size()-1);
    cout<<"Converted vector to Tree is : ";
    preOrderTraversal(bst.root);
    return 0;
}

// -Time and Space complexity : O(N)

// -Output:-
// Enter the elements of vector ( -1 to exit ) : 1 2 3 4 5 6 7 -1
// Converted vector to Tree is : 4 2 1 3 6 5 7

-2. Lowest Common Ancestor of BST :-
Given a Binary Search Tree (BST) and two values. You need to find the LCA i.e. Lowest common ancestor of the
two nodes provided both the nodes exist in the BST.


#include<iostream>
#include<vector>
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

class BST{
public: 
    node* root;
    BST(){
        root=NULL;
    }

    node* insert(node* root,int k){
        node* newNode=new node(k);
        if (root==NULL)
        {
            return newNode;
        }
        if (root->val<k)
        {
            root->right=insert(root->right,k);
        }
        if (root->val>k)
        {
            root->left=insert(root->left,k);
        }
        return root;
        
    }
};

node* lca(node* root,node* node1,node* node2){
    //base-case 
    if (root==NULL)
    {
        return NULL;
    }
    if (root->val>node1->val && root->val>node2->val)
    {
        //LCA will lie in left subtree
        return lca(root->left,node1,node2);
    }
    if (root->val<node1->val && root->val<node2->val)
    {
        //LCA will lie in right subtree
        return lca(root->right,node1,node2);
    }
    //if root value lies between node1 and node2
    //or root value if a node value
    return root; 
}

int main(){
    BST bst;
    cout<<"Enter the elements of vector ( -1 to exit ) : ";
    while (true)
    {
        int i;
        cin>>i;
        if (i==-1)
        {
            break;
        }
        bst.root=bst.insert(bst.root,i);
    }
    cout<<"Enter the value node's whose lowest common ancestor you want to find : ";
    int n1;int n2;
    cin>>n1>>n2;
    node* node1=new node(n1);
    node* node2=new node(n2);

    cout<<"Lowest common Ancestor is : "<<lca(bst.root,node1,node2)->val;
    
    return 0;
}

// Output:-
// Enter the elements of vector ( -1 to exit ) : 3 1 4 6 2 -1
// Enter the value node's whose lowest common ancestor you want to find : 1 2
// Lowest common Ancestor is : 1

-3.Remove all leaf nodes from BST

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

class BST{
public: 
    node* root;
    BST(){
        root=NULL;
    }

    node* insert(node* root,int k){
        node* newNode=new node(k);
        if (root==NULL)
        {
            return newNode;
        }
        if (root->val<k)
        {
            root->right=insert(root->right,k);
        }
        if (root->val>k)
        {
            root->left=insert(root->left,k);
        }
        return root;
        
    }

    void preorder(node* root){
        if (root==NULL)
        {
            return;
        }
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
};

node* removeLeaf(node* root){
    if (root==NULL)
    {
        return NULL;
    }
    
    if (root->left==NULL && root->right==NULL)
    {
        return NULL;
    }
    root->left=removeLeaf(root->left);
    root->right=removeLeaf(root->right);
    return root;
}

int main(){
    BST bst;
    cout<<"Enter the elements of vector ( -1 to exit ) : ";
    while (true)
    {
        int i;
        cin>>i;
        if (i==-1)
        {
            break;
        }
        bst.root=bst.insert(bst.root,i);
    }
    cout<<"Tree after removing leaf node is : ";
    bst.root=removeLeaf(bst.root);
    bst.preorder(bst.root);
    return 0;
}

// Output:-
// Enter the elements of vector ( -1 to exit ) : 4 2 6 1 3 5 7 -1
// Tree after removing leaf node is : 4 2 6

-4.Inorder Predecessor and successor for a given Key in BST.


#include<iostream>
#include<vector>
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

class BST{
public: 
    node* root;
    BST(){
        root=NULL;
    }

    node* insert(node* root,int k){
        node* newNode=new node(k);
        if (root==NULL)
        {
            return newNode;
        }
        if (root->val<k)
        {
            root->right=insert(root->right,k);
        }
        if (root->val>k)
        {
            root->left=insert(root->left,k);
        }
        return root;
        
    }

    void preorder(node* root){
        if (root==NULL)
        {
            return;
        }
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
};

void InPreSucc(node* root,node* &pre,node* &succ,int Key){
    if (root==NULL)
    {
        return;
    }
    if (root->val==Key)
    {
        //rightmost of left Subtree
        if (root->left!=NULL)
        {
            node* temp=root->left;
            while (temp->right!=NULL)
            {
                temp=temp->right;
            }
            pre=temp;
        }
        //leftmost of right subtree
        if (root->right!=NULL)
        {
            node* temp=root->right;
            while (temp->left!=NULL)
            {
                temp=temp->left;
            }
            succ=temp;
        }
        return;    
    }
    if (root->val>Key)  //Key will exists in left subtree
    {
        succ=root;
        InPreSucc(root->left,pre,succ,Key);
    }
    else if (root->val<Key)  // Key will exists in right subtree 
    {
        pre=root;
        InPreSucc(root->right,pre,succ,Key);
    }


    return;
}

int main(){
    BST bst;
    cout<<"Enter the elements of Tree ( -1 to exit ) : ";
    while (true)
    {
        int i;
        cin>>i;
        if (i==-1)
        {
            break;
        }
        bst.root=bst.insert(bst.root,i);
    }
    cout<<"Enter the key : ";
    int k;
    cin>>k;
    node* pre=NULL;
    node* succ=NULL;
    InPreSucc(bst.root,pre,succ,k);
    if(pre!=NULL){
        cout<<"Predecessor is : "<<pre->val<<endl;
    }
    else{
        cout<<"Predecessor is : NULL "<<endl;
    }
    if (succ!=NULL)
    {
        cout<<"Successor is : "<<succ->val;
    }
    else{
        cout<<"Successor is : NULL"<<endl;
    }
    return 0;
}

// Output:-
// Enter the elements of Tree ( -1 to exit ) : 3 1 4 6 2 -1
// Enter the key : 4
// Predecessor is : 3
// Successor is : 6

-Time and Space commplexity :- O(H) , H->height of BST
*/




