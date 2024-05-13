/*

-The Questions done here are amazing and logic bending -> the MOST IMP thing I learned is that not every questionn
is a new question you have to MAP that question to the previous question that you have done

Try to map the concept/logic and you would be really amazed how easily those complex question gets solved!!

-MAKE SURE TO GIVE THEM A GOOD AND THOROUGH REVISION!! HAVE A GOOD DAY AHEAD!!!!



-1.Check whether bracket sequence is balanced or not

#include<iostream>
#include<stack>
using namespace std;

bool isVAlid(string str){
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];  //current character
        if (ch=='[' || ch=='{' || ch=='(')
        {
            st.push(ch);
        }
        else{
            //closing bracket
            if (ch==')' && !st.empty() && st.top()=='(')
            {
                st.pop();
            }
            else if (ch==']' && !st.empty() && st.top()=='[')
            {
                st.pop();
            }
            else if (ch=='}' && !st.empty() && st.top()=='{')
            {
                st.pop();
            }
            else{
                return false;
            }
            
            
        }
        
    }
    return st.empty();
}

int main(){
    cout<<"Enter the string : ";
    string s;
    cin>>s;
    if (isVAlid(s))
    {
        cout<<"Given string has valid bracket combo ";
    }else{
        cout<<"Given string has invalid bracket combo ";
    }
    return 0;
}

Output:-
Enter the string : ({[([()])]})
Given string has valid bracket combo 

-2. Next greater element

--*This concept is really IMP , so make sure you properly revise it!

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void nge(vector<int> &v){
    int n=v.size();
    vector<int> output(n,-1);

    stack<int> st; //indexes 
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() and v[i] > v[st.top()])
        {
            output[st.top()]=v[i];
            st.pop();
        }
        st.push(i);
    }
    while (not st.empty())  //just written for knowledge
    {
        output[st.top()]=-1;
        st.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout<<output[i]<<" ";
    }
    
}

int main(){
    int n;
    cout<<"Enter the size of vector : ";
    cin>>n;
    cout<<"Enter the vector : ";
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    cout<<"Next greater element's vector is : ";
    nge(v);
    return 0;
}

Output:-
Enter the size of vector : 7
Enter the vector : 4 6 3 1 5 7 0
Next greater element's vector is : 6 7 5 5 7 -1 -1

-If you want to find previous greater element than simply just :-
1.reverse the array
2.find next greater element of that array
3.reverse the output array 

-Code to convert Decimal to Binary -> challenge by Atul!!
#DONE!!

#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int rem=0;
    int count=0;
    int a=n;
    int sum=0;
    while (a>0)
    {
        a=a/2;
        count++;
    }
    int cnt = 0;
    while (n>0 && cnt<=count)
    {
        rem=n%2;
        n=n/2;
        rem=rem*pow(10,cnt);
        cnt++;
        sum=sum+rem;
    }
    cout<<sum;
    return 0;
}

-3.Given a series of N daily price quotes for a stock, we need to calculate the span of the stock's price for all N days. 
The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) 
for which the stock price was less than or equal to the price of that day.


#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> pge(vector<int> &arr){
    int n=arr.size();
    reverse(arr.begin(),arr.end());
    vector<int> output(n,-1);
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && arr[i]>arr[st.top()])
        {
            output[st.top()]=n-i-1; //because after reverse the indexes will change
            st.pop();
        }
        st.push(i);
    }
    reverse(output.begin(),output.end());
    reverse(arr.begin(),arr.end());
    return output;
}

int main(){
    int n;
    cout<<"Enter the size of vector : ";
    cin>>n;
    cout<<"Enter the vector : ";
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    vector<int> res=pge(v);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<i-res[i]<<" ";
    }
    
    return 0;
}

Output:-
Enter the size of vector : 7
Enter the vector : 100 80 60 70 60 75 85
1 1 1 2 1 4 6 

-4.Given an array of integer heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram,

-*You can solve this question by apply the concept of next smaller element index and prev smaller element index ->
just do next-prev-1 => will give you the width of the reactangle , rest all logic is same as the code written below!

*****  By the way the  code written below is more OP! tha you can imagine so do check it out and more than anything 
DO REVISE IT!!!!!  *****
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int histogram(vector<int> &arr){
    int n=arr.size();
    stack<int> st;
    int ans=INT_MIN;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && arr[i]<arr[st.top()])
        {
            int el=arr[st.top()];  //current bar to be removed and its answer will be calculated
            int nsi=i;
            st.pop();
            int psi=0;
            if (st.empty())
            {
                psi=-1;
            }else{
                psi=st.top();
            }
            
            ans=max(ans,(el)*(nsi-psi-1));
            
        }
        st.push(i);
    }
    while (not st.empty())
    {
        int el=arr[st.top()];
        int nsi=n;
        st.pop();
        int psi=0;
        if (st.empty())
        {
            psi=-1;
        }else{
            psi=st.top();
        }
        ans=max(ans,el*(nsi-psi-1));
        
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of histogram : ";
    cin>>n;
    cout<<"Enter the histogram vertical length : ";
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int res=histogram(v);
    cout<<"The area of max. possible rectangle formed in the histogram is : "<<res;
    return 0;
}

Output:-
Enter the size of histogram : 13
Enter the histogram vertical length : 2 1 5 6 2 3 0 2 1 5 6 2 3
The area of max. possible rectangle formed in the histogram is : 10

