/*
In this we are gonna do questions on Generic Trees

 -And  with that we hAVE COMPLETED our generic trees , they  are easy just one revision would suffice but the last
 question was really something make sure to do it properly , it is not that important in regards to DSA but you should
 still learn and understand it!

 -With that bye and HAve a GOOD DAY!!!

-1.NEXT GREATER ELEMENT IN N-ARY TREE - Given a generic tree and an integer x. Find and return the node with the next larger element
 in the tree i.e. find a node just greater than x. Return NULL if no node is present with value greater than x.

 -Just greater than "x" = samllest number greater than "x"


#include "iostream"
#include "vector"
using namespace std;

class Node{
public:
    int val;
    vector<Node*> children;
    Node(int data){
        val=data;
    }
};

void justGreater(Node* root, int x,Node* &ansNode){
    if(root==NULL){
        return;
    }
    Node* curr=root;
    if(curr->val>x && (ansNode==NULL || curr->val<ansNode->val)){
        //update my ansNode
        ansNode=curr;
    }
    for(Node* child:root->children){
        justGreater(child,x,ansNode);
    }
}

int main(){
    Node* root=new Node(20);
    root->children.push_back(new Node(8));
    root->children.push_back(new Node(22));
    root->children[0]->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(12));
    root->children[0]->children[1]->children.push_back(new Node(10));
    root->children[0]->children[1]->children.push_back(new Node(14));
    Node* ansNode=NULL;
    justGreater(root,10,ansNode);
    if (ansNode==NULL) {
        cout<<"NULL";
    }
    else {
        cout<<ansNode->val;  //12
    }
    return 0;
}

//Output:-
//2

 -2.MIRROR OF N-ARY TREE - Given a Tree where every node contains a variable number of children, convert the tree to its mirror.


#include <algorithm>
#include "iostream"
#include "vector"
using namespace std;

class Node{
public:
    int val;
    vector<Node*> children;
    Node(int data){
        val=data;
    }
};

void preorder(Node* root){
    if (root==NULL) return;
    cout<<root->val<<" ";
    for(Node* child:root->children) {
        preorder(child);
    }
    return;
}

void mirrorImage(Node* root){
    if (root==NULL){
        return;
    }
    reverse(root->children.begin(),root->children.end());
    for(Node* child:root->children){
        mirrorImage(child);
    }
    return;
}

int main(){
    Node* root=new Node(20);
    root->children.push_back(new Node(8));
    root->children.push_back(new Node(22));
    root->children[0]->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(12));
    root->children[0]->children[1]->children.push_back(new Node(10));
    root->children[0]->children[1]->children.push_back(new Node(14));
    cout<<"Tree : ";
    preorder(root);
    mirrorImage(root);
    cout<<endl<<"Mirror Image : ";
    preorder(root);
    return 0;
}

Output:-
Tree : 20 8 4 12 10 14 22
Mirror Image : 20 22 8 12 14 10 4

 -3.Serialize and Deserialize an N-ary tree - Serialization is the process of converting an object into a format that can be stored
 or transmitted.
Deserialization is the process of converting the serialized string back into an object.
Serialization is to store tree in a file so that it can be later restored. The structure of tree must be maintained.
Deserialization is reading tree back from file.

 format -> root:root.children.size():children


#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
#include "queue"
using namespace std;

class Node{
public:
    int val;
    vector<Node*> children;
    Node(int data){
        val=data;
    }
};

void serialized(Node* root,string &s){
    if (root==NULL){
        return;
    }
    s += to_string(root->val)+":"+ to_string(root->children.size())+":";
    for(Node* child:root->children){
        s+= to_string(child->val)+",";
    }
    if(root->children.size()) s.pop_back();  //to remove "," and not mistakingly remove ":" incase of none children
    s += "\n";
    for(Node* child:root->children){
        serialized(child,s);
    }
    return;
}

Node* deserializedTreeHelper(int nodeValue,unordered_map<int,string> mp){
    Node* node=new Node(nodeValue);
    string nodestr=mp[nodeValue];
    if (nodestr[0]=='0'){
        return node;  //leaf Node he
    }
    int breakPos=nodestr.find(':');
    int childNum = stoi(nodestr.substr(0,breakPos));
    string childstr=nodestr.substr(breakPos+1);
    int start=0;
    for (int i = 0; i < childNum; ++i) {
        int end=childstr.find(',',start);
        //but at the last we do not have a "," , so we have to handle this case
        if (end== string::npos) end=childstr.size();
        int childnodeValue= stoi(childstr.substr(start,end));
        node->children.push_back(deserializedTreeHelper(childnodeValue,mp));
        start=end+1;
    }
    return node;
}

Node* deserializedTree(string str){
    if(str==""){
        return NULL;
    }
    unordered_map<int,string > mp;
    int start=0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i]=='\n'){
            string nodestr=str.substr(start,i-start);  //"10:2:30,40"
            int breakPos1=nodestr.find(':');
            int nodeValue = stoi(nodestr.substr(0,breakPos1));  //10
            mp[nodeValue]=nodestr.substr(breakPos1+1); //"2:30,40"
            start=i+1;
        }
    }
    int rootNodeValue= stoi(str.substr(0,str.find(':')));
    return deserializedTreeHelper(rootNodeValue,mp);
}

void levelOrder(Node* root){
    if (root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int levelSize=q.size();
        while (levelSize--){
            Node* currNode=q.front();
            q.pop();
            cout<<currNode->val<<" ";
            for(Node* child:currNode->children) {
                q.push(child);
            }
        }
        cout<<endl;
    }
}


int main(){
    Node* root=new Node(20);
    root->children.push_back(new Node(8));
    root->children.push_back(new Node(22));
    root->children[0]->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(12));
    root->children[0]->children[1]->children.push_back(new Node(10));
    root->children[0]->children[1]->children.push_back(new Node(14));
    cout<<"Generic Tree : "<<endl;
    levelOrder(root);
    string s="";
    cout<<endl<<"Serialized form : "<<endl;
    serialized(root,s);
    cout<<s<<endl;
    cout<<"Deserialized form : "<<endl;
    Node* temp=deserializedTree(s);
    levelOrder(temp);
    return 0;
}

Output:-
Generic Tree :
20
8 22
4 12
10 14

Serialized form :
20:2:8,22
8:2:4,12
4:0:
12:2:10,14
10:0:
14:0:
22:0:

Deserialized form :
20
8 22
4 12
10 14


*/


