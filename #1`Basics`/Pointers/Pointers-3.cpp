
/*
Go at leat there's good explanation there!

Types of Pointers:-

1*. Null Pointers - IF we want to declare a pointer which will get address afterwards , so we use NULL pointer there 
                  - It is considered a good practice to use NULL pointer.  
                  - Here we can get segmentation fault , when we try to dereference the pointer.
                  - NULL = 0 = '\0'
2. Wild Pointers - Is a type of poiunter where the user has declared the pointer but has not intialised it.
                 - Due to which it ends up locating at some random address 
                 - Due to this we may get undefined behaviour , crashes and segmentation faults in some cases 
3. Dangling Pointers - Is a type of pointer that points to a memory location which is not valid (was valid before but not now)    
4. Void Pointers - These are special pointers that can point to any datatype value
                 - Void pointers can not be dereferenced but can use type casting 
                 - i.e. ->  float f=10.2;
                            void *ptr = &f;  
                            int *integerPointer = (int *)ptr;
                            Now we can dereference *ptr;

Here's some example (mine) related to types of pointers:-
(At LAST there's a IN-DEPH explanation . So, do chcek it out!)

#include<iostream>
using namespace std;
int main(){
    int *ptr;  //For wild pointer
    cout<<ptr<<" "<<*ptr<<"\n";   // Output :- 0x8
    return 0;
}

#include<iostream>
using namespace std;
int main(){
    int *pr = NULL;  //For NULL pointer
    cout<<pr<<" "<<*pr;  //Output :- 0
    return 0;
}


#include<iostream>
using namespace std;
int main(){
    int *ptr = NULL;  //For Danglings pointer
    {
        int x=10;
        ptr=&x;
    }
    cout<<ptr<<" "<<*ptr;  //Output :- 0x8fb4fff734 10
    return 0;
}

#include<iostream>
using namespace std;
int main(){
    float f=10.2;
    void *ptr=&f;    // For void Pointers
    float *integerPointer = (float *)ptr; 
    cout<<*integerPointer<<"\n";  //Output:- 10.2
    return 0;
}

Explanation:-

1. **Null Pointer:**
   - A null pointer is a pointer that does not point to any valid memory address.
   - In C++, you can initialize a pointer to null using the value `nullptr` (recommended) or `NULL` (macro).
   - A null pointer is often used to indicate that a pointer does not currently point to a valid object or memory location.
   - Attempting to dereference (access the value pointed to by) a null pointer will lead to undefined behavior.
   - Example:
     ```cpp
     int* ptr = nullptr;  // Declaration of a null pointer
     ```

2. **Wild Pointer:**
   - A wild pointer is a pointer that is not initialized or points to an arbitrary/random memory location.
   - Wild pointers can arise when you declare a pointer but don't assign it any valid address before using it.
   - Using a wild pointer can lead to undefined behavior or crash your program since it may access invalid memory locations.
   - Example:
     ```cpp
     int* ptr;  // Declaration of a wild pointer (uninitialized)
     ```

3. **Dangling Pointer:**
   - A dangling pointer is a pointer that points to an invalid memory location.
   - This happens when the memory previously pointed to by a pointer is deallocated, or the variable it pointed to goes out of scope.
   - After a pointer becomes dangling, attempting to dereference it will lead to undefined behavior.
   - To avoid dangling pointers, ensure that pointers are always pointing to valid memory locations.
   - Example:
     ```cpp
     int* danglingPtr;

     {
         int x = 5;
         danglingPtr = &x;  // danglingPtr now points to a local variable x
     } // x goes out of scope, danglingPtr becomes a dangling pointer
     ```

4. **Void Pointer:**
   - A void pointer is a special type of pointer in C++ that does not have any associated data type.
   - It can hold the address of any data type but cannot be directly dereferenced because its type is unknown.
   - You must explicitly cast a void pointer to the appropriate pointer type before dereferencing it.
   - It's often used when dealing with memory or APIs that require generic pointers to handle different data types.
   - Example:
     ```cpp
     void* ptr;  // Declaration of a void pointer

     int num = 42;
     ptr = &num;  // void pointer holding the address of an integer

     int* intPtr = static_cast<int*>(ptr); // Casting void pointer to int pointer
     cout << *intPtr << endl;  // Output: 42
     ```

Remember to use pointers with care, initialize them before use, and avoid accessing memory that might have been deallocated or 
gone out of scope. Understanding and managing pointers properly will help you write safer and more efficient C++ code.

*/







