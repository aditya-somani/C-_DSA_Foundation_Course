/*
So, in this lecture we learned about basics of pointers and its basic syntax and application
It's is quite easy just understand it with exampole of storing value in a bucket and then assigning a address to that bucket
this analogy will have you a lot in understanding the basics of Pointers!
Intro to pointers:-
C++ me har value , location ke pass address hota he .(RAM me store hota he)
The mechansim to access and manipulate address -> Pointers

If we want to access the address of a memory bucket we can use "Address-OF " operator
That is :- "&"
int x=10;
cout<<&x;       // usage -> &<var-name>

Here's the code :-
#include<iostream>
using namespace std;
int main(){
    int x=9,y=0;
    cout<<&x<<" "<<&y;
    return 0;
}
Output :- 0x6e7f7ff84c 0x6e7f7ff848           //Hexa-decimal value

This address canges everytime we run the code cause it is in RAM(Random Access Memory)

-Pointers :- Special type of variables which can store address 
Syntax:-  Data-Type *Pointers_name;
ex:- int *ptr = &x;

#include<iostream>
using namespace std;
int main(){
    int x=9;
    float y=10.234;
    char z= 'A';
    //Now make pointers for each datatype to assign address
    int *ptri = &x;
    float* ptrf = &y;
    char * ptrc = &z;
    cout<<ptri<<" "<<ptrf<<" "<<static_cast<void*>(ptrc);
    return 0;
}
Output:- 0xe5339ff9e4 0xe5339ff9e0 0xe5339ff9df

-Dereference operator :- *  //It gives the value stored at that address

#include<iostream>
using namespace std;
int main(){
    int x=9,y=0;
    int * ptr = &x;
    cout<<ptr<<"\n";  //Output :- 0x4255bff75c
    cout<<*ptr;     //Output:- 9
    return 0;
}

----------------------------------------------------
*/
#include<iostream>
using namespace std;
int main(){
    int x=9;
    int * ptr = &x;
    x=10;  //Changes the value of x from 9 to 10 
    //Value change ho rahi he but address to same , so ptr will not change onlu *ptr;
    cout<<ptr<<"\n";  //Output :- 0xcf6adff764
    cout<<*ptr<<"\n";     //Output:- 10
    *ptr = 50;   // We changed the value that was stored in ptr i.e. value of 'x'
    cout<<x<<"\n";     //Output :- 50
    cout<<&ptr;   //prints address of ptr not of the address of value stored in ptr
    //output:- 0xd2d5bffca0
    return 0;
}

----------------------------------------------------











