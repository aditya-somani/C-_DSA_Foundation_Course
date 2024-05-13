/*
-We learned about recursion -> JUst AMAZING!!

In Recursion , we try to solve a bigger problem by finding out solution to smaller sub problems
We represent there problems in the form of function and these function calls itself to solve smaller sub problems.


Syntax:-

methodName (N parameters){    //-> Bigger Problem
    if(halting condition){    //-> Base case
        return result;   //Always remember to write base case at starting and do add return statement with it!
    }
    return methodName (N parameters);  //-> assumption and self work
}

Example - 1.find factorial
-f(n) = n * f(n-1) => 5! = 5 * 4! = 5*4*3*2*1  ->Recursion
                               |
                               4*3!
                                 |
                                 3*2!
                                   |
                                   2*1! -> Base case
Code:-

#include<iostream>
using namespace std;
int f(int n){
    //base case
    if(n==1) return 1;
    return n*f(n-1);
}
int main(){
    cout<<"Enter the number whose factorial you want : ";
    int n;
    cin>>n;
    cout<<"Factorial of "<<n<<" is : "<<f(n);
    return 0;
}
Output:-
Enter the number whose factorial you want : 7
Fctorial of 7 is : 5040

2. Program to write fibonacci number(value of "n"th term is Sum of previous two terms)
- 0,1,1,2,3,5,8,13,21...
- fib(n)= fib(n-1) + fib(n-2)

#include<iostream>
using namespace std;
int fib(int n){
    if(n==0 || n==1) return n;
    else return fib(n-1)+fib(n-2);
}
int main(){
    cout<<"Enter the 'n' term : ";
    int n;
    cin>>n;
    cout<<"Fibonacci number at nth place is : "<<fib(n);
    return 0;
}
Output:-
Enter the 'n' term : 10
Fibonacci number at nth place is : 55
*/



