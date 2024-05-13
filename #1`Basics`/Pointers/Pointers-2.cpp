/*
In this we learned about call-by-reference using pointers , Pointers aritmetic , and how arrays act as pointers
Go through it once to revise all topics!

This example was by me , after it is done using Pointers
#include<iostream>
using namespace std;
void swap(int &x,int &y){  //here if we don't use '&' operator then 
    int temp=x;                 // Output will be - 10 90 only;
    x=y;
    y=temp;
}

int main(){
    int x=10;
    int y=90;
    swap(x,y);
    cout<<x<<" "<<y;
    return 0;
}
Output :- 90 10   // if we use '&' operator with 'x' and 'y'
Output:- 10 90  // without '&' operator

//Using pointers:-


#include<iostream>
using namespace std;
void swap(int *x,int *y){  //here if we don't use '&' operator then 
    int temp=*x;                 // Output will be - 10 90 only;
    *x=*y;
    *y=temp;
}

int main(){
    int x=10;
    int y=90;
    int *p1= &x;
    int *p2 = &y;
    swap(p1,p2);
    cout<<x<<" "<<y;   //Output:- 90 10
    return 0;
}

-*Call by Reference :- example 

-Write a programm to find first and last index of a character in a string using pointers 
#include<iostream>
using namespace std;
void findfandl(string s,char ch, int *first , int *last){
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]==ch)
        {
            *first = i;
            break;
        }
        
    }
    for (int i = s.size()-1; i > 0; i--)
    {
        if (s[i]==ch)
        {
            *last= i;
            break;
        }
        
    }
    
}
int main(){
    string s;
    cout<<"Enter string : ";
    cin>>s;
    char ch;
    cout<<"Enter the character whose first and last value of occurence you want to find :";
    cin>>ch;
    int first=-1,last=-1;
    int *p1= &first;
    int *p2= &last;
    findfandl(s,ch,p1,p2);
    cout<<"Starting character is at place : "<<*p1<<" and ending at : "<<*p2;
    return 0;

}
Output:-
Enter string : asdfghdaafrraytcyy
Enter the character whose first and last value of occurence you want to find :a
Starting character is at place : 0 and ending at : 12

-**Pointers Arithmetic**
Its like we can write 'ptr+1' so it will assign the address value to just one block afterwards of ptr and remember
that the address of 'ptr+1' depends upon the the "Datatype" of 'x'.

To find use operator :- sizeof(variable);
Size goes like this :- 1->2->3...->8->9->a->b->c
i.e. instead of using double digits we use alphabets to represent them like :- "4+9 = c"
-Size of operator is complier dependent , so it varies from computer to computer*


#include<iostream>
using namespace std;
int main(){
    int x=20;
    int *ptr = &x;
    cout<<ptr<<" "<<(ptr+1)<<" "<<(ptr+2)<<" "<<(ptr-1)<<"\n";
    //Output:-0xd8e9bffb34 0xd8e9bffb38 0xd8e9bffb3c 0xd8e9bffb30
    //Now look carefully as 4 -> 8 there is a difference  of 4 , WHY? -Because 'int' datatype occupies a size of 4 units
    //Then what about the third value?? - ptr+2 = ptr + 2*(size of Datatype) = 4 + 2*4 = 4+8 = 12  
    // 12 is represented as 'c' therefore last value has been updated from to "c" .
    //As for ptr-1 = 4 - 1*(size of Datatype ) = 4-1*4 = 0;
    return 0;
}

-Examples of array(Increment or decrement):- We move "Right -> Left"

SUMMARY:-

*ptr++ - Simply move the pointer to next value 
(*ptr)++ - Simply increases the dereferenced value
*++ptr - First move pointer by datatype size then derefernce it 
++*ptr - First dereference , then increment the dereferenced value 

-At end there is a in-depth explanation with examples of this 

#include<iostream>
using namespace std;
int main(){
    int x[2]={1,2};
    int *ptr = &x[0];
    cout<<ptr<<" "<<*ptr<<endl;
    cout<<ptr+1<<" "<<*(ptr+1)<<"\n";
    //Output:-
    //0x931b5ff9d0 1
    //0x931b5ff9d4 2
    cout<<*ptr++<<"\n";   //Phele value use horahi he and then increment 
    cout<<x[0]<<" "<<x[1]<<"\n";
    //Output:-
    //1
    //1 2
    return 0;
}

#include<iostream>
using namespace std;
int main(){
    int x[2]={1,2};
    int *ptr = &x[0];
    cout<<(*ptr)++<<"\n";    //Yaha dereferance phele uha and then add
    cout<<x[0]<<" "<<x[1]<<"\n";
    //Output:-
    //1
    //2 2
    return 0;
}


#include<iostream>
using namespace std;
int main(){
    int x[2]={1,2};
    int *ptr = &x[0];
    cout<<*++ptr<<"\n"; 
    //Output:- 2 
    cout<<x[0]<<" "<<x[1]<<"\n"; //No change in array
    
    return 0;
}

#include<iostream>
using namespace std;
int main(){
    int x[2]={1,2};
    int *ptr = &x[0];
    cout<<++*ptr<<"\n";
    //Output :- 2 ->1+1
    return 0;
}

IN-DEPTH EXPLANATION:-

1. `*ptr++`: This operation is known as "post-increment" or "postfix increment" of the pointer. It moves the pointer to the next memory 
location and returns the value at the current memory location (the one before the increment). It is equivalent to `*(ptr++)`.

Example:

```cpp
int arr[] = {1, 2, 3, 4, 5};
int* ptr = arr; // Pointer to the first element of the array

int value = *ptr++; // value = 1 (value at arr[0]), ptr now points to arr[1]
```

2. `(*ptr)++`: This operation dereferences the pointer and increments the value it points to. It is equivalent to `(*ptr) = (*ptr) + 1`.

Example:

```cpp
int x = 5;
int* ptr = &x; // Pointer pointing to the variable x

(*ptr)++; // Increment the value at the memory location pointed by ptr (x becomes 6)
```

3. `*++ptr`: This operation is known as "pre-increment" or "prefix increment" of the pointer. It first moves the pointer to the next 
memory location and then returns the value at the new memory location. It is equivalent to `*(++ptr)`.

Example:

```cpp
int arr[] = {1, 2, 3, 4, 5};
int* ptr = arr; // Pointer to the first element of the array

int value = *++ptr; // value = 2 (value at arr[1]), ptr now points to arr[2]
```

4. `++*ptr`: This operation dereferences the pointer and then increments the value it points to. It is equivalent to `++(*ptr)`.

Example:

```cpp
int x = 5;
int* ptr = &x; // Pointer pointing to the variable x

++*ptr; // Increment the value at the memory location pointed by ptr (x becomes 6)
```

It's essential to understand the differences between these operations as they have distinct behaviors and may yield different results 
based on their order of evaluation. Proper usage and understanding of these operations are crucial to writing correct and efficient 
C++ code.

-*Array as Pointers:-

IMP :- That is name of array at base index is actually a address!!

#include<iostream>
using namespace std;
int main(){
    int x[3]={1,2,3};
    int *ptr = &x[0];
    cout<<ptr<<" "<<x<<"\n";  //IMP :- That is name of array at base index is actually a address!!
    //Output:- 0xf79dbffb4c 0xf79dbffb4c
    return 0;
}
#include<iostream>
using namespace std;
int main(){
    int n=3;
    int x[n]={1,2,3};
    int *ptr = &x[0];
    cout<<ptr<<" "<<x<<" "<<*ptr<<" "<<*x<<"\n";  //That is name of array at base index is actually a address!!
    //Output:- 0xa5bb5ff62c 0xa5bb5ff62c 1 1
    cout<<*(x+0)<<" "<<*(x+1)<<"\n";  //We are getting value of first and second index 
    //output:- 1 2
    for (int i = 0; i < n; i++)  //This will print whole array using Pointers!
    {
        cout<<*(x+i)<<" ";
    }
    //Output:- 1 2 3
    return 0;
}
#include<iostream>
using namespace std;
void process(int *arr , int n){
    //Inside this function we have access to same array as that in main function
    for (int i = 0; i < n; i++) //This is internal logic for below cout syntax in main() function
    {
        cout<<*(arr + i)<<" ";
    }
    cout<<endl;
    *(arr+1)=33;

}
int main(){
    int arr[3]={5,1,2};
    process(arr,3);
    for (int i = 0; i < 3; i++)
    {
        cout<<arr[i]<<" ";
    }
    //Output:-
    //5 1 2 
    //5 33 2

    return 0;
}

#include<iostream>
using namespace std;
int main(){
    int arr[5]={1,2,3,4,5};
    int *ptr = (arr+2);
    cout<<*ptr<<"\n";
    *ptr++;
    cout<<*ptr<<"\n";
    *ptr--;
    cout<<*ptr<<"\n";
    return 0;
}
Output:-
3
4
3

-Program to point at entire array

#include<iostream>
using namespace std;
int main(){
    int arr[5]={1,2,3,4,5};
    int (*ptr)[5]=&arr;
    cout<<ptr<<" "<<arr<<" "<<*ptr<<" "<<*arr<<"\n";
    //Output :- 0x2d16fffd40 0x2d16fffd40 0x2d16fffd40 1
    return 0;
}

-Same way we can do for 2D array;
*/

