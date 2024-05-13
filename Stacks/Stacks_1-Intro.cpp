/*

-Stacks of plates/books -> that we take the plate/book on top of the stacks of plates
Here you can't access  any element other than top!

-The element that was added the last will be removed the first

push -> insert at top
pop -> remove from top
isempty -> to  check if stack is empty
size -> size of stack
isfull -> if stack is full 
top -> will give the top element of the stack


-Overflow -> When we to add a element to the stack but the stack is already full
-Underflow -> when we want to delete/access the element from the stack but it is already empty  

-Stack using Arrays and Stack using Linked List <- implementation of Stacks

-To check for underflow condition -> check if top_idx == -1; or not
-to check for overflow condition -> check if top_ide==arr.size()-1; or not
-size -> top_idx + 1;



#include<iostream>
using namespace std;

class stack{
    int capacity;
    int* arr;
    int top;
    public:
    stack(int c){
        this->capacity=c;
        arr = new int[c];
        this->top=-1;
    }

    void push(int data){
        if (this->top == this->capacity-1) 
        {
            cout<<"Overflow \n";
            return;
        }
        this->top++;
        this->arr[this->top]=data;
    }

    void pop(){
        if (this->top==-1)
        {
            cout<<"Underflow \n";
            return;
        }
        this->top--;
    }

    int getTop(){
        if (this->top == -1)
        {
            cout<<"Underflow \n";
            return INT_MIN;
        }
        return this->arr[this->top];
    }

    bool isEmpty(){
        return this->top==-1;
    }

    int size(){
        return this->top+1;
    }

    bool isFull(){
        return this->top==this->capacity-1;
    }
};

int main(){
    stack st(5); //a stack of size 5;
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

-All of this functions are running in constant time complexity!!

-Linked List implementation of stacks 

-push -> insert at head 
-pop -> delete at head


#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int d){
        this->data=d;
        this->next=NULL;
    }
};

class stack{
    node* head;
    int capacity;
    int currsize;
    public:
    stack(int c){
        this->capacity=c;
        this->currsize=0;
        head=NULL;
    }
    bool isEmpty(){
        return this->head==NULL;
    }

    bool isFull(){
        return this->currsize==this->capacity;
    }

    void push(int data){
        if (this->currsize==this->capacity)
        {
            cout<<"Overflow "<<endl;
            return;
        }
        
        node* newnode= new node(data);
        newnode->next=this->head;
        this->head=newnode;
        currsize++;
    }

    int pop(){
        if (this->head==NULL)
        {
            cout<<"Underflow "<<endl;
            return INT_MIN;
        }
        node* new_head=this->head->next;
        this->head->next=NULL;
        node* tobeRemoved=this->head;  //to return the deleted value we are doing this sheningans
        int result = tobeRemoved->data;
        delete tobeRemoved;
        this->head=new_head;
        currsize--;
        return result;
        
    }

    int getTop(){
        if (this->head==NULL)
        {
            cout<<"Underflow "<<endl;
            return INT_MIN;
        }
        return this->head->data;
    }

    int size(){
        return this->currsize;
    }
};

int main(){
    stack st(5); //a stack of size 5;
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

-We can also use a already built in stack using #include<stack>
-This is a direct and sure shot method to implement stacks but I would recommend to do it through Linked List so you can give a recheck at 
your logical and reasoning part as linked list are really interesting in that regards
*/
#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.top()<<endl;  //3
    st.push(4);
    st.push(5);
    cout<<st.top()<<endl;  //5
    st.pop();
    st.pop();
    cout<<st.top()<<endl;  //3
    cout<<st.empty()<<
    return 0;
}



