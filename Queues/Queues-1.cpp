/*

-In this lecture we learned about the implementation of queue's using linke dlist , array  and also 
directly using it through stl . All in all it was quite easy if you understand stack sufficiently then 
queues are gonna be a piece of cake for you!

-Just remember them as array but a little more to it -> first come , first  serve motto it follows!!

-Give it a quick revision and that's all it want , HAVE A GOOD DAY AHEAH!!!!

-Queues -> first in, first out (FIFO) || first come , first serve (FIFS)

-Linear data structure 

-Types of operations on Queues:-

-Enqueue -> helps us to add a new element in queue
-Dequeue -> helps us to remove a new element(first) in the queue
-isfull -> to check if queue is full or not
-isempty -> to check if queue is empty or not
-front -> gives us the element which came first
-size -> tell us the size of queue

-Types of Queues:-

-Simple -> back se add hoga and front pe settle ho jaygea
-Priority Queue -> Criteria custom hota he yaha queue ka , ex:- size,price,quantity  just not first come first serve
-Circular Queue -> rear element is connected to front queue
-Double ended queue / Deque -> allows insertion and deletion from both sides


-Here we are implementing Queues using Linked List!

#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;
    int size;
public:
    Queue(){
        this->head=NULL;
        this->tail=NULL;
        this->size=0;
    }

    void enqueue(int data){
        Node* newNode=new Node(data);
        if (this->head==NULL)
        {
            //ll is empty
            this->head=this->tail=newNode;
        }
        else{
            this->tail->next=newNode;
            this->tail=newNode;
        }
        this->size++;
    }

    void dequeue(){
        if (this->head==NULL)
        {
            return;
        }
        else{
            Node* oldHead=this->head;
            Node* newHead=this->head->next;
            this->head=newHead;
            if (this->head==NULL)
            {
                this->tail=NULL;
            }
            oldHead->next=NULL;
            delete oldHead;
            this->size--;
        }
    }

    int getSize(){
        return this->size;
    }

    bool isEmpty(){
        return this->head==NULL;
    }

    int front(){
        if (this->head==NULL)
        {
            return -1;
        }
        
        return this->head->data;
    } 
};

int main(){
    Queue qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.dequeue();
    while (not qu.isEmpty())
    {
        cout<<qu.front()<<" ";  //20 30
        qu.dequeue();
    }
    return 0;
}

-Here we are implementing queues using arrays!


#include<iostream>
#include<vector>
using namespace std;

class Queue{
    int front;
    int back;
    vector<int> v;
public:
    Queue(){
        this->front=-1;
        this->back=-1;
    }

    void enqueue(int data){
        this->v.push_back(data);
        this->back++;
        if (this->back==0)
        {
            this->front=0;
        }
        
    }

    void dequeue(){
        if (this->front == this->back)
        {
            this->front=-1;
            this->back=-1;
            this->v.clear();
        }
        else{
            this->front++;
        }
        
    }

    int getFront(){
        if (this->front==-1)
        {
            return -1;
        }
        return this->v[this->front];
    }

    bool isEmpty(){
        return this->front==-1;
    }
};

int main(){
    Queue qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.dequeue();
    while (not qu.isEmpty())
    {
        cout<<qu.getFront()<<" ";  //20 30
        qu.dequeue();
    }
    return 0;
}

-But in solving questions you will be directly using the #include<queue>


#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.pop();
    while (not qu.empty())
    {
        cout<<qu.front()<<" ";  //20 30
        qu.pop();
    }
    
    return 0;
}

-Linked List based queue is more space efficient as compared to array based queue

-Reverse the elements of a queue!

-Intiution came from the stack reversing problem!!

#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(){
    stack<int> st;
    queue<int> q;
    cout<<"Input the size of queue : ";
    int n;
    cin>>n;
    cout<<"Enter the number : ";
    while (n--)
    {
        int va;
        cin>>va;
        q.push(va);
    }

    while (not q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (not st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    cout<<"Reverse number is : ";
    while (not q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}

Output:-
Input the size of queue : 9
Enter the number : 1 2 3 4 5 6 7 8 9
Reverse number is : 9 8 7 6 5 4 3 2 1 
*/