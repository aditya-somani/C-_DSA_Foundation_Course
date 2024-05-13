
/*
Given an integer , find out sum of its digits using recursion
ex:- 1234 = 1+2+3+4 = 10

->Recuresively go and find the sum of n-1 digits and add the last digit to it
-f(n)= f(n/10)+n%10
-f(1234) = f(123) + 4
            |
          f(12) + 3
            |
          f(1) + 2 -> Base case  

#include<iostream>
using namespace std;
int f(int n){
    if(n>=0 && n<= 9) return  n;
    return f(n/10)+(n%10);
}
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<"Sum of digits of number is "<<f(n);
    return 0;
}
Output:-
Enter the number : 111220055
Sum of digits of number is 17

-Given two numbers p and q , find value of p^q using recursion
-p^q = p*p*p*p.....q times => p^q = p* (p*p*p*p...[q-1] times)
-p^q = p * (p^q-1)
              |
           (p^q-2)
              |
           till q=0 -> base case as when q==0 => p^q=0  
-f(p,q) = p * f(p,q-1) -> recursiuve relation   


#include<iostream>
using namespace std;
int f(int p , int q){
    if(q==0) return 1;
    return p*f(p,q-1);
}
int main(){
    int p,q;
    cout<<"Enter the base number : ";
    cin>>p;
    cout<<"Enter the raise to power number : ";
    cin>>q;
    cout<<p<<" raise to power "<<q<<" is "<<f(p,q);
    return 0;
}

-More efficient way:-
-just read the code its just amazing
*/
#include<iostream>
using namespace std;
int f(int p , int q){
    if(q==0) return 1;
    if(q%2==0){
        //if q is even 
        int result = f(p,q/2);
        return result*result;
    }
    else{
        //if q is odd
        int result = f(p,(q-1)/2);
        return p*result*result;
    }
}
int main(){
    int p,q;
    cout<<"Enter the base number : ";
    cin>>p;
    cout<<"Enter the raise to power number : ";
    cin>>q;
    cout<<p<<" raise to power "<<q<<" is "<<f(p,q);
    return 0;
}




