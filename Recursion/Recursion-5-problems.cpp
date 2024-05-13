/*
-Problems on Recursion
-In this we solved some basic problems on recursion , not much of a big deal 

-Given a number 'n' , find sequence of number from 1 to n without using loop


#include<iostream>
using namespace std;
void seqSmallToBig(int n , int current ){
    if (n<0)
    {
        return;
    }
    //base case
    if(current == n ) {
        cout<<current;
        return;
    }
    cout<< current <<" , ";
    seqSmallToBig(n,current+1);
}
void seqBigToSmall(int n){
    //base case 
    if(n==1){
        cout<<n;
        return;
    }
    cout<< n << " , "; 
    seqBigToSmall(n-1);
}

//By Sir! ------------------------------------------------

void f(int n){
    //base case
    if(n<1) return;
    //Go and print 'n-1' natural numbers
    f(n-1);
    cout<<n<<" ";
}

//--------------------------------------------------------
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<"Sequence is from "<<n<<" to "<<" 1 is : ";
    seqBigToSmall(n);
    cout << endl;
    cout<<"Sequence is from"<<" 1 "<<" to "<<n<<" is : ";
    seqSmallToBig(n,1);
    cout << endl;
    return 0;
}
Output:-
Enter the number : 7
Sequence is from 7 to  1 is : 7 , 6 , 5 , 4 , 3 , 2 , 1
Sequence is from 1  to 7 is : 1 , 2 , 3 , 4 , 5 , 6 , 7

-Given a number 'num' and a value 'k' . Print k multiples of num

#include<iostream>
using namespace std;
void multi(int num , int k , int curr){
    if(curr>k){
        return;
    }
    cout<< num*curr <<" " ;
    multi(num,k,curr+1);
}
int main(){
    int num ,k;
    cout<<"Enter the number : ";
    cin>>num;
    cout<<"Enter amount of multiples you require : ";
    cin>>k;
    cout<<"Multiples are : ";
    multi(num,k,1);
    return 0;
}

Output:-
Enter the number : 17
Enter amount of multiples you require : 5
Multiples are : 17 34 51 68 85 

- Given a number n, find the sum of natural numbers till 'n' but with alternate sign
-f(n)=f(n-1)+((n%2==0)?(-n):n)
*/
#include<iostream>
using namespace std;
int altSum(int n){
    //base-case
    if(n==0) return 0;
    return altSum(n-1)+((n%2==0) ? (-n):n);
}
int main(){
    int n;
    cout<<"Enter the no. of natural number : ";
    cin>>n;
    cout<<"Sum with alternate sign is : "<<altSum(n);
    return 0;
}







