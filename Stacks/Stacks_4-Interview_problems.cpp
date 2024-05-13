/*

-The Questions were hella innteresting and mind bending , they really did set up the inituition require 
to solve problems related to stacks and I want youto definetly solve them all once again from scratch and give
yourself time as well as patience and some space while you keep working and rocking!!

-HAVE A GOOD DAY AHEAD!!!!



-1.Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
    -MinStack() initializes the stack object.
    -void push(int val) pushes the element val onto the stack. 
    -void pop() removes the element on the top of the stock.
    -int top() gets the top element of the stack.
    -int getMin() retrieves the minimum element in the stack
You must implement a solution with O(1) time complexity for each function. 
Assumption: Methods pop, top and getMin operations will always be called on non-empty stacks.

Explanation :-
-> only  for +ve elements:-

x<min -> condn to update 'min' -> x-min<0 => x - min = y
    old_min= x-y; -ve value will represent that at that positio we have updated 'min'

-I have written just the main code/logic behind the code as it was done on leetcode!!

#define ll long long int
class MinStack {
public:
    stack<ll> st;
    ll mn;  //minimum
    MinStack() {
        this->mn=INT_MAX;
    }
    
    void push(int val) {
        if(this->st.empty()){
            this->mn=val;
            this->st.push(val);
        }else{
            this->st.push(val-this->mn);
            if(this->mn>val){
                this->mn=val;
            }
        }
    }
    
    void pop() {
        if(not st.empty()){
            if(this->st.top()>=0){
                this->st.pop();
            }else{
                this->mn=this->mn-this->st.top();
                this->st.pop();
            }
        }
    }
    
    int top() {
        if(this->st.size()==1){
            return this->st.top();
        }else if(this->st.top()<0){
            return this->mn;
        }else{
            return this->mn + this->st.top();
        }
    }
    
    int getMin() {
        return this->mn;
    }
};


-2.Find the minimum number of brackets that we need to remove to make the given bracket sequence balanced.


#include<iostream>
#include<string>
#include<stack>
using namespace std;

int minBracketsRemove(string &str){
    stack<char> st;
    int count=0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i]=='(')
        {
            st.push(str[i]);
        }
        else if (str[i]==')' &&  st.empty())
        {
            count++;
        }
        
        else{
            if (!st.empty())
            {
                st.pop();
            }
            
        }
        
    }
    while (!st.empty())
        {
            count++;
            st.pop();
        }
    return count;
}

int main(){
    string s;
    cout<<"Enter the bracket pattern : ";
    cin>>s;
    cout<<"Min. brackets to remove : "<<minBracketsRemove(s);
    return 0;
}

Output:-
Enter the bracket pattern : (())()(((())
Min. brackets to remove : 2

-Infix expression :- operand (operator) operand type
-Postfix expression :- Reverse Polish Notation :- first operands and then operators
-Prefix Notation :- Polish Notation :- first operators and then operands 

-Implement a code to solve postfix expression 


#include<iostream>
#include<math.h>
#include<stack>
#include<string>
using namespace std;

int calc(int v1,int v2,char op){
    if (op=='^')
    {
        return pow(v1,v2);
    }
    else if (op=='*')
    {
        return v1*v2;
    }
    else if (op=='+')
    {
        return v1+v2;
    }
    else if (op=='-')
    {
        return v1-v2;
    }
    else{
        return v1/v2;
    }
}

int eval(string &str){
    stack<int> st;
    int result=-1;
    for (int i = 0; i < str.size(); i++)
    {
        char ch=str[i];
        if (isdigit(str[i]))  //ye in-built he!!!
        {
            st.push(ch-'0');
        }
        else{
            int v1=st.top();
            st.pop();
            int v2=st.top();
            st.pop();
            st.push(calc(v1,v2,ch));  //I couldn't do this step!
        }
    }
    return st.top();
}

int main(){
    cout<<"Enter the postfix expression : ";
    string s;
    cin>>s;
    cout<<"Solved postfix expression is : "<<eval(s);
    return 0;
}

Output:-
Enter the postfix expression : 231*+9-
Solved postfix expression is : 4

-Now let's evaluate prefix expression!


#include<iostream>
#include<math.h>
#include<stack>
#include<string>
using namespace std;

int calc(int v1,int v2,char op){
    if (op=='^')
    {
        return pow(v1,v2);
    }
    else if (op=='*')
    {
        return v1*v2;
    }
    else if (op=='+')
    {
        return v1+v2;
    }
    else if (op=='-')
    {
        return v1-v2;
    }
    else{
        return v1/v2;
    }
}

int eval(string &str){
    stack<int> st;
    int result=-1;
    for (int i = str.size()-1; i >=0; i--)
    {
        char ch=str[i];
        if (isdigit(str[i]))  //ye in-built he!!!
        {
            st.push(ch-'0');
        }

//I was unable to do this if part of the code , rest i was able to imagine as well as implement!!

        else{
            int v1=st.top();
            st.pop();
            int v2=st.top();
            st.pop();
            st.push(calc(v1,v2,ch));  //I couldn't do this step!
        }
    }
    return st.top();
}

int main(){
    cout<<"Enter the postfix expression : ";
    string s;
    cin>>s;
    cout<<"Solved postfix expression is : "<<eval(s);
    return 0;
}

Output:-
Enter the postfix expression : 231*+9-
Solved postfix expression is : 4double

-let's implement infix expression -> here 'BODMAS' plays a very big and vital role!!!

--Amazing question really loved solving and playing with it , if you ever revise it make sure 
to give it a try!!


#include<iostream>
#include<string>
#include<stack>
#include<math.h>
using namespace std;

double calc(double v1,double v2,char c){
    if (c=='^')
    {
        return pow(v1,v2);
    }
    else if (c=='+')
    {
        return v1+v2;
    }
    else if (c=='-')
    {
        return v1-v2;
    }
    else if (c=='*')
    {
        return v1*v2;
    }
    else{
        return v1/v2;
    }
    
}

int precedence(char c){
    if (c=='^')
    {
        return 3;
    }
    else if (c=='*' || c=='/')
    {
        return 2;
    }
    else if (c=='+' || c=='-')
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

int eval(string &s){
    stack<int> nums;
    stack<char> oper;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            nums.push(s[i]-'0');
        }
        else if (s[i]=='(')
        {
            oper.push('(');
        }
        else if (s[i]==')')
        {
            while (!oper.empty() && oper.top()!='(')
            {
                char ch=oper.top();
                oper.pop();
                double v1=nums.top();
                nums.pop();
                double v2=nums.top();
                nums.pop();
                nums.push(calc(v2,v1,ch));
            }
            if (not oper.empty())
            {
                oper.pop();  //for '(' brackets  that has been stored in oper stack!
            }
            
        }
        else{
            while (not oper.empty() && precedence(oper.top())>=precedence(s[i]))
            {
                char ch=oper.top();
                oper.pop();
                double v1=nums.top();
                nums.pop();
                double v2=nums.top();
                nums.pop();
                nums.push(calc(v1,v2,ch));
            }
            oper.push(s[i]);
        }
        
        
    }
    while (not oper.empty())
    {
        char ch=oper.top();
        oper.pop();
        int v1=nums.top();
        nums.pop();
        int v2=nums.top();
        nums.pop();
        nums.push(calc(v1,v2,ch));
    }
    return nums.top();
}



int main(){
    cout<<"Enter the INFIX Pattern : ";
    string s;
    cin>>s;
    cout<<"Solved pattern is : "<<eval(s);
    return 0;
}

Output:-
Enter the INFIX Pattern : 1+(2*(3-1))+2
Solved pattern is : 7

-Converssion of a prefix expression to a postfix expression
*/

#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

string eval(string &pre){
    stack<string> st;
    reverse(pre.begin(),pre.end());
    for (int i = 0; i < pre.size(); i++)
    {
        if (isdigit(pre[i]))
        {
            st.push(to_string(pre[i]-'0'));  //adding the converted number to string in my stack!
        }
        else{
            string v1=st.top();
            st.pop();
            string v2=st.top();
            st.pop();
            string newexp= v1+v2+pre[i];
            st.push(newexp);
        }
    }
    return st.top();
}

int main(){
    cout<<"Write a prefix expression : ";
    string s;
    cin>>s;
    cout<<"It's Postfix expression is : "<<eval(s);
    return 0;
}

Output:-
Write a prefix expression : *+31-15
It's Postfix expression is : 31+15-*

