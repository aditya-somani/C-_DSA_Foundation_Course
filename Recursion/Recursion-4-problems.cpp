/*
-In this we are gonna solve questions based on strings

MAKE SURE TO DO THE SECOND QUESTION AGAIN AND AGAIN!!!

-Remove all the occurence of 'a' from he string 'abcax' using recursion
-f(array,idx,n) = s[idx]=='a' ? " ":s[idx] + f(array,idx+1,n) ->recursive statement
-Assume that this function works for idx+1


#include<iostream>
using namespace std;
string f(string &s,int idx , int n , char x){
    //base case
    if (idx==n) return "";
    //self work
    string cur="";
    cur+=s[idx];

    return (s[idx]==x ? "": cur) + f(s,idx+1,n,x);
}
int main(){
    string s;
    char x;
    cout<<"Enter the string : ";
    cin>>s;
    int n= s.size();
    cout<<"Enter the variable you want remove : ";
    cin>>x;
    cout<<"After removing all occurence of '"<<x<<"' new string is : "<<f(s,0,n,x);
    return 0;
}
Output:-
Enter the string : adityasomani
Enter the variable you want remove : a
After removing all occurence of 'a' new string is : ditysomni

-Write a program to check whether a given number is plaindrome or not i.e. 12621
-Bhoto OP question -> MAKE SURE TO DO IT ONCE AGAIN!!


#include <iostream>
using namespace std;

bool f(int num, int &temp)
{
    // Base case
    if (num >= 0 && num <= 9)
    {
        int lastdigit = (temp) % 10;
        (temp) /= 10;
        return (num == lastdigit);
    }
    bool result = f(num / 10, temp) && ((num % 10) == ((temp) % 10));
    (temp) /= 10;
    return result;
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int another = n;
    int *temp = &another;
    cout << "Given number is (True-1/False-0) palindrome: " << f(n, *temp) << endl;
    return 0;
}
Output:-
Enter the number: 12621
Given number is (True-1/False-0) palindrome: 1


*/