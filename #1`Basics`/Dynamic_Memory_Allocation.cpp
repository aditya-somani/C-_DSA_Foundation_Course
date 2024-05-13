/*

### Dynamic Memory Allocation

**1. Static vs. Dynamic Memory:**
   - **Static Memory:** Allocated at compile time. Size and properties are known before the program runs.
   - **Dynamic Memory:** Allocated at runtime. Size and properties can be determined during program execution.

**2. Heap Memory:**
   - Dynamic memory is often managed using the heap, a region of the computer's memory used for dynamic allocation.

**3. Keywords and Functions:**
   - **C:**
     - `malloc(size)`: Allocates a block of specified size in bytes.
     - `calloc(num, size)`: Allocates an array of num elements, each of size bytes.
     - `realloc(ptr, newSize)`: Resizes the previously allocated memory block pointed to by ptr.
     - `free(ptr)`: Deallocates the memory block pointed to by ptr.

   - **C++:**
     - `new type`: Allocates memory for a variable of the specified type.
     - `new type[size]`: Allocates memory for an array of variables of the specified type.
     - `delete ptr`: Deallocates the memory pointed to by ptr.
     - `delete[] ptr`: Deallocates the memory allocated for an array.

**4. Memory Leaks:**
   - Failure to deallocate memory after use leads to memory leaks.
   - Always free or delete dynamically allocated memory when it's no longer needed.

**5. Initializing Memory:**
   - Memory allocated by `malloc` or `new` is not initialized. Use `calloc` or manually set values.

**6. Error Handling:**
   - Check if the allocation was successful before using the memory.
   - Memory allocation functions return `NULL` on failure.

**7. Example (C):**
   ```c
   int *arr;
   arr = (int *)malloc(5 * sizeof(int)); // Allocating memory for an array of 5 integers

   if (arr != NULL) {
       // Use the allocated memory
       arr[0] = 1;
       arr[1] = 2;
       // ...

       free(arr); // Deallocate memory when done
   } else {
       // Handle allocation failure
   }
   ```

**8. Example (C++):**
   ```cpp
   int *arr = new int[5]; // Allocating memory for an array of 5 integers

   if (arr != nullptr) {
       // Use the allocated memory
       arr[0] = 1;
       arr[1] = 2;
       // ...

       delete[] arr; // Deallocate memory when done
   } else {
       // Handle allocation failure
   }
   ```

**9. Best Practices:**
   - Avoid unnecessary dynamic allocation. Use it when the size is not known at compile time or when flexibility is required.
   - Always free or delete allocated memory to prevent memory leaks.

Dynamic memory allocation provides flexibility in managing memory during program execution but requires careful handling to 
avoid memory-related issues. Always manage memory responsibly to ensure efficient and reliable programs.


*/

// #include<iostream>
// #include<stdlib.h>
// using namespace std;
// int main(){
//    int n;
//    cout<<"Enter the size : ";
//    cin>>n;
//    int *ptr=(int*)malloc(n*sizeof(int));
//    cout<<"Enter the number : ";
//    for (int i = 0; i < n; i++)
//    {
//       cin>>*(ptr+i); //did not work for ptr+i;

//    }
//    cout<<"Elements are : ";
//    for (int i = 0; i < n; i++)
//    {
//       cout<<*(ptr+i)<<" - "<<ptr+i<<" | ";
//    }
//    return 0;
// }

//Output:-
// Enter the size : 3
// Enter the number : 1 2 3
// Elements are : 1 - 0x11413d0 | 2 - 0x11413d4 | 3 - 0x11413d8 | 

// #include<iostream>
// #include<stdlib.h>
// using namespace std;
// int main(){
//    int* p= new int[3];
//    // int a=4;
//    // p[0]=&a;
//    cout<<*(p+0)<<endl;
//    cin>>*(p+0);
//    cout<<p<<endl;
//    cout<<&p[0]<<endl;
//    cout<<p[0]<<endl;
//    cout<<*p+0<<endl;
//    return 0;
   
// }

//Storing complex number in structure 

// #include<iostream>
// using namespace std;
// struct complex
// {
//    float real;
//    float image;
// };

// int main(){
//    struct complex s1,s2; //s1 and s2 are variable not object
//    cout<<"Input real part of s1 and s2 : ";
//    cin>>s1.real>>s2.real;
//    cout<<"Input the img part : ";
//    cin>>s1.image>>s2.image;
//    cout<<"Complex no. s1 is : "<<s1.real<<" + "<<s1.image<<"i"<<endl;
//    cout<<"Complex no. s2 is : "<<s2.real<<" + "<<s2.image<<"i"<<endl;
//    struct complex s3;
//    s3.real=s1.real+s2.real;
//    s3.image=s1.image+s2.image;
//    cout<<"Complex no. s3 is : "<<s3.real<<" + "<<s3.image<<"i"<<endl;   
//    return 0;
// }


// #include<iostream>
// #include<stdlib.h>
// using namespace std;
// int main(){
//    // int *p=(int *)calloc(3,sizeof(int));
//    // cout<<p[0]<<endl;
//    // cout<<p[1]<<endl;
//    // cout<<p[2]<<endl;
//    // cout<<p[3]<<endl;
//    // p[0]=150;
//    // cout<<p[0]<<endl;
//    // cout<<p[10]<<endl;
//    // cout<<p[4]<<endl;
//    int a[3];
//    for (int i = 0; i < 5; i++)
//    {
//       cin>>a[i];
//    }
//       for (int i = 0; i < 5; i++)
//    {
//       cout<<a[i]<<" ";
//    }
   
   
//    return 0;
// }
//Output:-
// 0
// 0
// 0
// 0
// 150
// 1634028636
// 1420830392

//try function in function

#include<iostream>
#include<string.h>
using namespace std;

void Check(char *a,char *b,int (*cmp) (const char* ,const char *));


int main(){
   char s1[80],s2[80];
   int(*p)(const char*,const char*);
   p=strcmp;
   cout<<"Enter the value of strings : ";
   cin>>s1>>s2;
   Check(s1,s2,p);
   return 0;
}
void Check(char *a,char *b,int(*cmp)(const char*,const char*) ){
   cout<<"Testing for inequality "<<endl;
   if (!(*cmp)(a,b))
   {
      cout<<"Equal";
   }
   else{
      cout<<"Not equal ";
   }
}


