/*
All the questions solved here were really interesting and played with my basics and imaginative skills , if you were to revise them 
absolutely solve them using pictures in your brain because that will make them seem like a piece of cake!!

They are easy so don't take that much headache just keep learning and have a good Day!!!


-1.Copy Stack - Copy contents of one stack to another in same order

--*Whenever we transfer data from one stack to others it get "reverse"

-This is an example in which i implemented a stack using both Arrays and Linked List as well!! 

#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node(int data){
        this->val=data;
        this->next=NULL;
    }
};

class stackUsingArr{
    int capacity;
    int* arr;
    int top;
    public:
    stackUsingArr(int c){
        this->capacity=c;
        arr = new int[c];
        this->top=-1;
    }

    void push(int data){
        if (this->top==capacity-1)
        {
            cout<<"Overflow "<<endl;
            return;
        }
        this->top++;
        this->arr[this->top]=data;
    }

    void pop(){
        if (this->top==-1)
        {
            cout<<"Underflow "<<endl;
            return;
        }
        this->top--;
    }

    int getTop(){
        if (this->top==-1)
        {
            cout<<"Underflow ";
            return INT_MIN;
        }
        return this->arr[this->top];
    }

    bool isEmpty(){
        return this->top==-1;
    }

    bool isFull(){
        return this->top==capacity-1;
    }

    int size(){
        return this->top+1;
    }
};

class stackUsingLL{
    node* head;
    int capacity;
    int currsize;
    public:
    stackUsingLL(int c){
        this->capacity=c;
        this->currsize=0;
        this->head=NULL;
    }

    void push(int c){
        if (this->currsize==this->capacity)
        {
            cout<<"Overflow "<<endl;
            return;
        }
        node* newnode=new node(c);
        newnode->next=head;
        this->head=newnode;
        currsize++;
    }

    int pop(){
        if (this->head==NULL)
        {
            cout<<"Underflow ";
            return INT_MIN;
        }
        node* new_head=head->next;
        this->head->next=NULL;
        node* tobeRemoved = this->head;
        int result = tobeRemoved->val;
        this->head=new_head;
        delete tobeRemoved;
        currsize--;
        return result;
    }

    int getTop(){
        if (this->head==NULL)
        {
            cout<<"Underflow ";
            return INT_MIN;
        }
        return this->head->val;
    }

    bool isEmpty(){
        return this->head==NULL;
    }

    bool isFull(){
        return this->currsize==this->capacity;
    }
};

int main(){
    stackUsingLL st(5); //a stack of size 5;
    st.push(1);
    st.push(2);
    cout<<st.getTop()<<"\n";  //2
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<st.getTop()<<"\n";  //5
    st.push(8);  //overflow

    st.pop();
    st.pop();
    cout<<st.getTop()<<endl;  //3
    return 0;
}

//confirmed that both are working fine!

-Here is the answer to that copy stack

#include<iostream>
#include<stack>
using namespace std;
stack<int> copyStack(stack<int> &input){
    stack<int> temp;
    while (not input.empty())
    {  //do the process till the input stack doesn't become empty
        
        int curr=input.top();
        input.pop();
        temp.push(curr);
    }
    stack<int> result;
    while (not temp.empty())
    {
        int res=temp.top();
        temp.pop();
        result.push(res);
    }
    return result;
}
int main(){
    stack<int> st;
    int n;
    cout<<"Enter the size of stack : ";
    cin>>n;
    cout<<"Enter the stack : ";
    while (n--)
    {
        int val;
        cin>>val;
        st.push(val);
    }
    cout<<st.top()<<endl;
    stack<int> res=copyStack(st);
    cout<<res.top()<<endl;
    cout<<"Stack after copying is : ";
    while (not res.empty())
    {
       int curr = res.top();
       res.pop();
       cout<<endl;
       cout<<curr<<endl;
    }
    return 0;
}

-1.1 Now let's solve this copy stack question using Recursion

#include<iostream>
#include<stack>
using namespace std;

void f(stack<int> &st , stack<int> &result){
    if (st.empty())
    {
        return;
    }
    int curr=st.top();
    st.pop();
    f(st,result);
    result.push(curr);
}

int main(){
    stack<int> st;
    int n;
    cout<<"Enter the size of stack : ";
    cin>>n;
    cout<<"Enter the stack : ";
    while (n--)
    {
        int val;
        cin>>val;
        st.push(val);
    }
    cout<<st.top()<<endl;
    stack<int> res;
    f(st,res);
    cout<<res.top()<<endl;
    cout<<"Stack after copying is : "<<endl;;
    while (not res.empty())
    {
       int curr = res.top();
       res.pop();
       cout<<curr<<endl;
    }
    return 0;
}

Output:-
Enter the size of stack : 5
Enter the stack : 1 2 3 4 5
5
5
Stack after copying is :
5
4
3
2
1

-2.Insering at bottom of the stack!


#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st,int x){
    stack<int> temp;
    while (not st.empty())
    {
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(x);  //this is the point where 'x' got inserted at the bottom

    while (not temp.empty())
    {
        int curr=temp.top();
        temp.pop();
        st.push(curr);
    }
    
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    insertAtBottom(st,100);
    while (not st.empty())
    {
        int curr=st.top();
        st.pop();
        cout<<curr<<endl;  // 4 3 2 1 100 -> top to bottom
    }
    return 0;
}

-Time & Space complexity :- O(n)

-2.1 Now let's iuse recursion to solve this question

#include<iostream>
#include<stack>
using namespace std;

void f(stack<int> &st , int x){
    if (st.empty())
    {
        st.push(x);
        return;
    }
    int curr=st.top();
    st.pop();
    f(st,x);
    st.push(curr);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    f(st,100);
    while (not st.empty())
    {
        int curr=st.top();
        st.pop();
        cout<<curr<<endl;  // 4 3 2 1 100 -> top to bottom
    }
    return 0;
}

-Time & Space complexity :- O(n)

-3.Let's try to insert at any index


#include<iostream>
#include<stack>
using namespace std;

void insertAtIndex(stack<int> &st, int index , int x){
    int idx = st.size()-index;
    stack<int> result;
    while (idx--)
    {
        int curr=st.top();
        st.pop();
        result.push(curr);
    }
    st.push(x);
    while (not result.empty())
    {
        int curr=result.top();
        result.pop();
        st.push(curr);
    }
    
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    insertAtIndex(st,2,100);
    while (not st.empty())
    {
        int curr=st.top();
        st.pop();
        cout<<curr<<endl;  // 4 3 100 2 1 -> top to bottom
    }
    return 0;
}

-4.Remove from bottom!

//Code is working both ways through using iterative and recursive way!

#include<iostream>
#include<stack>
using namespace std;

// void removeAtBottomRecursive(stack<int> &st){
//     if (st.size()==1)
//     {
//         st.pop();
//         return;
//     }
//     int curr=st.top();
//     st.pop();
//     removeAtBottom(st);
//     st.push(curr);
// }

void removeAtBottom(stack<int> &st){
    stack<int> temp;
    while (st.size()!=1)
    {
        int curr=st.top();
        st.pop();
        temp.push(curr);
    }
    st.pop();
    while (not temp.empty())
    {
        int curr=temp.top();
        temp.pop();
        st.push(curr);
    }
    
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    removeAtBottom(st);
    while (not st.empty())
    {
        int curr=st.top();
        st.pop();
        cout<<curr<<endl;  // 4 3 2 -> top to bottom
    }
    return 0;
}

-5.Remove at any index 

#include<iostream>
#include<stack>
using namespace std;

void deleteAtIndex(stack<int> &st,int index){
    stack<int> temp;
    int idx=st.size();
    while (st.size()!=index+1)
    {
        int curr=st.top();
        st.pop();
        temp.push(curr);
    }
    st.pop();
    while (not temp.empty())
    {
        int curr=temp.top();
        temp.pop();
        st.push(curr);
    }
    
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    deleteAtIndex(st,2);
    while (not st.empty())
    {
        int curr=st.top();
        st.pop();
        cout<<curr<<endl;  // 4 2 1 -> top to bottom
    }
    return 0;
}

-6.Reverse the stack! -> Did both recursively and iteratively 
*/
#include<iostream>
#include<stack>
using namespace std;

// void reverse(stack<int> &st){
//     stack<int> t1,t2;
//     while (not st.empty())
//     {
//         int curr=st.top();
//         st.pop();
//         t2.push(curr);
//     }
//     while (not t2.empty())
//     {
//         int curr=t2.top();
//         t2.pop();
//         t1.push(curr);
//     }
//     while (not t1.empty())
//     {
//         int curr=t1.top();
//         t1.pop();
//         st.push(curr);
//     }
    
// }

void insertAtBottom(stack<int> &st,int value){
    stack<int> temp;
    while (not st.empty())
    {
        int curr=st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(value);
    while (not temp.empty())
    {
        int curr=temp.top();
        temp.pop();
        st.push(curr);
    }
    
}

void reverseUsingRecursion(stack<int> &st){
    if (st.empty())
    {
        return;
    }
    int curr=st.top();
    st.pop();
    reverseUsingRecursion(st);
    insertAtBottom(st,curr);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverseUsingRecursion(st);
    while (not st.empty())
    {
        int curr=st.top();
        st.pop();
        cout<<curr<<endl;  // 1 2 3 4 -> top to bottom
    }
    return 0;
}
