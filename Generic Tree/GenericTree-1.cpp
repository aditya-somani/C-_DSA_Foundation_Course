/*
-It's not so IMP topic as compared to BST but as it is part of DSA , you should still get a general idea about it

 -Genric Trees - Every nodes has data and references to its children Nodes.
               - Also called N-ary trees
               - Unlike Binary Trees which has only two children nodes , it can have max. "n" nodes.

 -Creating a GT

#include "iostream"
#include "vector"
using namespace std;
class Node{
public:
    char data;
    vector<Node*> children;
    Node(char val){
        data=val;
    }
};
int main(){
    Node* root=new Node('A');
    root->children.push_back(new Node('B'));
    root->children.push_back(new Node('C'));
    cout<<root->data<<endl;
    for(Node* ele:root-> children){
        cout<<ele->data<<" ";
    }
    return 0;
}

Output:-
A
B C

 -Traversal in Generic Trees are of same types as BST :-
 -1.DFS - Depth First Search - Preorder , Inorder ,Postorder
 -2.BFS - Breadth First Search - Levelorder

 1.DFS :-
 -Preorder -> Print root , recursively call for child nodes (left->right);
 -Inorder -> Recursively visit all child node except last , print root node then recursively visit last node
 -Postorder -> Recursively visit all child nodes and print root

#include "iostream"
#include "vector"
using namespace std;
class Node{
public:
    char data;
    vector<Node*> children;
    Node(char val){
        data=val;
    }
};

void preorder(Node* root){
    //base-case
    if (root== nullptr){
        return;
    }
    cout<<root->data<<" ";
    for(Node* ele:root->children){
        preorder(ele);
    }
    return;
}

void inorder(Node* root){
    if (root== nullptr){
        return;
    }
    int childNodes=root->children.size();
    for (int i = 0; i < childNodes-1; ++i) {
        inorder(root->children[i]);
    }
    cout<<root->data<<" ";
    if (childNodes>0){
        inorder(root->children[childNodes-1]);
    }
    return;
}

void post(Node* root){
    if (root== nullptr){
        return;
    }
    for(Node* ele:root->children){
        post(ele);
    }
    cout<<root->data<<" ";
    return;
}

int main(){
    Node* root=new Node('A');
    root->children.push_back(new Node('B'));
    root->children.push_back(new Node('C'));
    root->children[0]->children.push_back(new Node('D'));
    root->children[0]->children.push_back(new Node('1'));
    root->children[0]->children.push_back(new Node('2'));
    root->children[0]->children.push_back(new Node('3'));
    root->children[1]->children.push_back(new Node('E'));
    cout<<"Preorder Traversal of Generic Tree is : "<<endl;
    preorder(root);
    cout<<endl<<" Inorder Traversal of Generic Tree is : "<<endl;
    inorder(root);
    cout<<endl<<"Postorder traversal of Generic Trees is : "<<endl;
    post(root);
    return 0;
}

Output:-
Preorder Traversal of Generic Tree is :
A B D 1 2 3 C E
Inorder Traversal of Generic Tree is :
D 1 2 B 3 A C E
Postorder traversal of Generic Trees is :
D 1 2 3 B E C A

 -2.BFS :-
 -Levelorder ->

#include "iostream"
#include "vector"
#include "queue"
using namespace std;

class Node{
public:
    char data;
    vector<Node*> children;
    Node(char val){
        data=val;
    }
};

void levelorder(Node* root){
    if (root== nullptr){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int nodesAtCurrLevel=q.size();
        while(nodesAtCurrLevel--){
            Node* currNode=q.front();
            q.pop();  //dequeue
            cout<<currNode->data<<" ";
            for(Node* child:currNode->children){
                q.push(child);
            }
        }
        cout<<endl;
    }
}

int main(){
    Node* root=new Node('A');
    root->children.push_back(new Node('B'));
    root->children.push_back(new Node('C'));
    root->children[0]->children.push_back(new Node('D'));
    root->children[0]->children.push_back(new Node('1'));
    root->children[0]->children.push_back(new Node('2'));
    root->children[0]->children.push_back(new Node('3'));
    root->children[1]->children.push_back(new Node('E'));
    cout<<"Levelorder wise traversal of Generic Tree is : "<<endl;
    levelorder(root);
    return 0;

}

Output:-
Levelorder wise traversal of Generic Tree is :
A
B C
D 1 2 3 E

*/


