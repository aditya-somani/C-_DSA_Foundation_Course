/*

-In this lecture we studied about deque , converting queues to stack and stack to queues and at last we studied about
circular queues 
-All in all this lecture was really interesting as it played with the fundamentals of both stacks and queues.

-Revise it thoroughly and make sure to give yourself a little space to do mistake and learn from them , 
Don't be too harsh on yourself at  you will be accomplishing absolutely nothing by keep pushing yourself,
somethimes rest and patience are necessary , my friend!

-So, have A GOOD DAY AHEAD!!!!


-Deque -> It's a doubly ended queue 
       -> we can add/remove elements from both sides 
       -> They are really powerful concept , do not underestimate deques!

-1.You are given an array of integers nums, there is a sliding window of size k which is 
moving from the very left of the array to the very right. You can only see the k numbers in the window. 
Each time the sliding window moves right by one position. 
Return the max sliding window which basically contains the max element in each window.

-It was an amazing terrific question which really opened my mind!!!

#include<iostream>
#include<deque>
#include<vector>
using namespace std;

void max_window(vector<int> &arr,int k){
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            while (not dq.empty() and arr[dq.back()]<arr[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(arr[dq.front()]);
        for (int i = k; i < arr.size(); i++)  //I did a error here by starting the loop from '0' instead of 'k'
        {
            int curr=arr[i];
            if (dq.front()==(i-k))  //This is solely for the purpose to move my sliding window
            {
                dq.pop_front();
            }
            while (not dq.empty() and arr[dq.back()]<arr[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            res.push_back(arr[dq.front()]);
        }
        cout<<"The max sliding window's vector is : ";
        for (int i = 0; i < res.size(); i++)
        {
            cout<<res[i]<<" ";
        }
        
}

int main(){
    cout<<"Enter the size of vector : ";
    int n;
    cin>>n;
    cout<<"Enter the vector : ";
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the windows value : ";
    int k;
    cin>>k;
    max_window(arr,k);
    return 0;
}

Output:-
Enter the size of vector : 8
Enter the vector : 1 3 -1 -3 5 3 6 7
Enter the windows value : 3
The max sliding window's vector is : 3 3 5 5 6 7 

-2.We are given a stack data structure with push and pop operations, the task is to 
implement a queue using instances of stack data structure and operations on them.

-There are two ways to solve this question one is by letting push function to be efficient and other 
by letting pop function to be efficient

-Let's first make it push efficient

-Here the time complexity of push function is O(1) but the time complexity of pop and front is O(n)

#include<iostream>
#include<stack>
using namespace std;

class Queue{
    stack<int> st;
    public:

    void push(int x){  //this equal to queue.enqueue
        this->st.push(x);
    }

    void pop(){  //this equal to queue.dequeue
        if (this->st.empty())
        {
            return;
        }
        
        stack<int> temp;
        while (this->st.size()>1)
        {
            temp.push(st.top());
            st.pop();
        }
        
        // now stack size is 1 , and we are at the bottom element 
        this->st.pop();
        while (not temp.empty())
        {
            this->st.push(temp.top());
            temp.pop();
        }
        
    }

    bool empty(){
        return this->st.empty();
    }

    int front(){
        // return this->st.top(); -> this is wrong as from front should be at bottom of the stack but here i will get the answer of the topmost of the stack
        if (this->st.empty())
        {
            return -1;
        }
        
        stack<int> temp;
        while (this->st.size()>1)
        {
            temp.push(st.top());
            st.pop();
        }
        
        // now stack size is 1 , and we are at the bottom element 
        int result = this->st.top();
        while (not temp.empty())
        {
            this->st.push(temp.top());
            temp.pop();
        }
        return result;
    }
};

int main(){
    Queue qu;
    qu.push(1);qu.push(2);qu.push(3);qu.push(4);
    qu.pop();
    while (not qu.empty())
    {
        cout<<qu.front()<<" ";  // 2 3 4
        qu.pop();
    }
    return 0;
}

-Now let's talk about pop efficient code 

-Here time complexity of my push is O(n) but the time complexity of my pop and front function is O(1);

#include<iostream>
#include<stack>
using namespace std;

class Queue{
    stack<int> st;
    public:

    void push(int x){
        stack<int> temp;
        while (not this->st.empty())
        {
            temp.push(st.top());
            this->st.pop();
        }
        this->st.push(x);
        while (not temp.empty())
        {
            this->st.push(temp.top());
            temp.pop();
        }
        
    }

    void pop(){
        if (this->st.empty())
        {
            return;
        }
        this->st.pop();
    }

    bool empty(){
        return this->st.empty();
    }

    int front(){
        if (this->st.empty())
        {
            return -1;
        }
        return this->st.top();
    }
};

int main(){
    Queue qu;
    qu.push(1);qu.push(2);qu.push(3);qu.push(4);
    qu.pop();
    while (not qu.empty())
    {
        cout<<qu.front()<<" ";  // 2 3 4
        qu.pop();
    }
    return 0;
}

-Now we are gonna make stack using queue!

-It has the same possibilites as queues using stacks that is :-
once it will be push efficient and other time it will be pop efficient! 

-Let's first try push efficient code  

#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> qu;
    public:

    void push(int x){
        this->qu.push(x);
    }

    void pop(){
        if (this->qu.empty())
        {
            return;
        }
        
        queue<int> temp;
        while (this->qu.size()!=1)
        {
            temp.push(this->qu.front());
            this->qu.pop();
        }
        
        //now only one element is there in my queue
        
        this->qu.pop();
        while (!temp.empty())
        {
            this->qu.push(temp.front());
            temp.pop();
        }
        
    }

    bool isEmpty(){
        return this->qu.empty();
    }

    int getTop(){
        if (this->qu.empty())
        {
            return -1;
        }
        queue<int> temp;
        while (this->qu.size()!=1)
        {
            temp.push(this->qu.front());
            this->qu.pop();
        }
        
        //now only one element is there in my queue
        int result = this->qu.front();
        temp.push(this->qu.front());
        this->qu.pop();
        while (!temp.empty())
        {
            this->qu.push(temp.front());
            temp.pop();
        }
        return result;
    }
};

int main(){
    Stack st;
    st.push(1);st.push(2);st.push(3);st.push(4);
    st.pop();
    while (!st.isEmpty())
    {
        cout<<st.getTop()<<" ";  // 3 2 1
        st.pop();
    }
    return 0;
}

-Now let's solve this question by making our pop function efficient!


#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> qu;
    int front;
    public:

    void push(int x){
        this->qu.push(x);
        if (!this->qu.empty())
        {
            int size=this->qu.size();
            for (int i = 0; i < size-1; i++)
            {
                int ont=this->qu.front();
                this->qu.pop();
                this->qu.push(ont);
            }
            
        }
        
    } 

    void pop(){
        if (this->qu.empty())
        {
            return;
        }
        qu.pop();
    }

    int getTop(){
        return this->qu.front();
    }

    bool isEmpty(){
        return this->qu.size()==0;
    }
};

int main(){
    Stack st;
    st.push(1);st.push(2);st.push(3);st.push(4);
    st.pop();
    while (!st.isEmpty())
    {
        cout<<st.getTop()<<" ";  // 3 2 1
        st.pop();
    }
    return 0;
}

-Making Circular Queues using arrays!
 
-Here we will be using the amazinng properties of '%' function

-there may be some problem in this code but i am unable to spot it even after using all resources 
at my disposal 

*/
#include<iostream>
#include<vector>
using namespace std;

class Queue{
    vector<int> v;
    int front;
    int back;
    int cs; // current size
    int ts; //total size
public:
    Queue(int n){
        this->v.resize(n);
        this->ts=n;
        this->front=-1;
        this->back=-1;
        this->cs=0;
    }
    
    void enqueue(int x){
        
        if (isFull())
        {
            return;
        }
        this->back=(this->back+1)%this->ts;
        this->v[this->back]=x;
        this->cs++;
    }

    bool isFull(){
        return this->cs==this->ts;
    }

    void dequeue(){
        if (isEmpty())
        {
            return;
        }
        this->front=(this->front+1)%this->ts;
        this->cs--;
    }

    bool isEmpty(){
        return this->cs==0;
    }

    int getFront(){
        if (this->front==-1)
        {
            return -1;
        }
        
        return this->v[this->front];
    }

};


int main(){
    Queue qu(3);
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.dequeue();
    qu.enqueue(40);
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    qu.enqueue(400);qu.enqueue(500);
    while (!qu.isEmpty())
    {
        cout<<qu.getFront()<<" ";
        qu.dequeue();
    }
    return 0;
}








