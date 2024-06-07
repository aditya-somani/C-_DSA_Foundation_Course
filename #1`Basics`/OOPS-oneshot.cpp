/*
-OOPS - Object oriented programming
-Notes and definition are in notebook!

-Start from 480 line , if you want to see updated code , rest all is same.

-Basics to create class , objects and others...

#include<iostream>
#include<string>
#include<vector>
using namespace std;
class fruit{
public:
    string name;
    string colour;
};
int main(){
    fruit apple; //object
    apple.name="Apple";
    apple.colour="Red";
    cout<<apple.name<<" - "<<apple.colour<<endl;  //object me '.' use hota he
    //ye downwards pointer variable he 
    fruit *mango = new fruit; //object pointer ke case me '->' use hoga
    mango->name="mango";
    mango->colour="yellow";
    cout<<mango->name<<" - "<<mango->colour;

    return 0;

}

-About Objects , Constructor and Destructor

#include<iostream>
using namespace std;
class rectangle{
public:
    int l;
    int b;

    rectangle(){ //default constructor -> no argument passed
        l=0;
        b=0;
    }
    rectangle(int x,int y){  //parameterised constructor -> args passed 
        l=x;
        b=y;
    }
    rectangle(rectangle& r){  //copy constructor -> initialise an 'obj' by another existing obj
        l= r.l;
        b = r.b;
    }

    ~rectangle(){  //Dectructor 
        cout<<"Destructor is called "<<endl; //Destructor is called
                                            //Destructor is called
                                            //Destructor is called
    }
};
int main(){
    rectangle r;
    cout<<"Length : "<<r.l<<" Breadth : "<<r.b<<endl;  //Length : 0 Breadth : 0
    rectangle r1(3,4);
    cout<<"Length : "<<r1.l<<" Breadth : "<<r1.b<<endl;  //Length : 3 Breadth : 4
    rectangle r2=r1;
    cout<<"Length : "<<r2.l<<" Breadth : "<<r2.b<<endl;  //Length : 3 Breadth : 4

    rectangle* r3 = new rectangle();
    cout<<r3->l<<" "<<r3->b<<endl;  //0 0
    delete r3;  //Destructor is called
    return 0;
}

-About encapsulation, abstraction

#include<iostream>
using namespace tsd;
class abc{
    int x;
    public:
    void set(int n){
        x=n;
    }
    int get(){
        return x;
    }
};
int main(){
    abc object1;
    object1.set(3);
    cout<<object1.get()<<endl;
    return 0;
}

-About inheritance and access specifier

#include<iostream>
using namespace std;
class parent(){
    public:
    int x;
    private:
    int y;
    protected:
    int z;

};

class child1: public parent{  //inheritance
    //x will remain public
    //y will remain protected
    //z will not be accessible
};

class child2: private parent{
    //x will be private
    //y will be private
    //z will be inaccessible
};

class child3: protected parent {
    //x will be protected
    //y will be protected
    //z will be inaccessible
}


int main(){
    parent p;

}

-About types of inheritance -> 1.Single inheritance

#include<iostream>
using namespace std;
class parent {
    public:
    parent(){
        cout<<"parent class "<<endl;
    }
};
class child : public parent{
    public:
    child(){
        cout<<"child class "<<endl;
    }
};
int main(){
    child c;
    return 0;
}

Output:-
parent class 
child class

2. Multi-level inheritance

#include<iostream>
using namespace std;
class parent {
    public:
    parent(){
        cout<<"parent class "<<endl;
    }
};
class child : public parent{
    public:
    child(){
        cout<<"child class "<<endl;
    }
};
class grandchild : public child{
    public:
    grandchild(){
        cout<<"Grandchild class "<<endl;
    }
};
int main(){
    grandchild gc;
    return 0;
}

Output:-
parent class 
child class
Grandchild class

-3. Multiple Inheritance

#include<iostream>
using namespace std;
class parent1 {
    public:
    parent1(){
        cout<<"parent1 class "<<endl;
    }
};
class parent2{
    public:
    parent2(){
        cout<<"parent2 class "<<endl;
    }
};
class child : public parent1, public parent2{
    public:
    child(){
        cout<<"child class "<<endl;
    }
};
class grandchild : public child{
    public:
    grandchild(){
        cout<<"Grandchild class "<<endl;
    }
};
int main(){
    child c;
    return 0;
}

Output:-
parent1 class 
parent2 class
child class

-4.Hierarchial Inheritance 

#include<iostream>
using namespace std;
class parent1 {
    public:
    parent1(){
        cout<<"parent1 class "<<endl;
    }
};
class child2{
    public:
    child2(){
        cout<<"child2 class "<<endl;  //child2 class 
    }
};
class child1 : public parent1{
    public:
    child1(){
        cout<<"child1 class "<<endl;  //parent 1 class
                                      //child 1 class
    }
};
int main(){
    child1 c;
    return 0;
}

-5. Hybrid Inheritance -> combination of more than one inheritance

-Diamond question -> base class has multiple parent classes having a common ancestor class

#include<iostream>
using namespace std;
class parent{
    public:
    parent(){
        cout<<"parent class "<<endl;
    }
};
class child1:public parent{
    public:
    child1(){
        cout<<"child1 class "<<endl;
    }
};
class child2:public parent{
    public:
    child2(){
        cout<<"child2 class "<<endl;
    }
};
class grandchild:public child1, public child2{
    public:
    grandchild(){
        cout<<"grandchild class "<<endl;
    }
};
int main(){
    grandchild gc;
    return 0;
}
Output:-
parent class 
child1 class 
parent class
child2 class
grandchild class

-Creating a programm using OOPS to add two/more numbers

#include<iostream>
using namespace std;
class sum{
    public:
    void add(int x,int y){
        int sum = x+y;
        cout<<sum<<endl;
    }

    void add(int x ,int y , int z){
        int sum = x+y+z;
        cout<<sum<<endl;
    }

    void add(float x,float y){
        int sum = x+y;
        cout<<sum<<endl;
    }
};

int main(){
    sum s;
    s.add(2,3);  //5
    s.add(2,3,4);  //9
    s.add(float (2.3),float (2.7));  //5
    return 0;
}

-Operator Overloading

#include<iostream>
using namespace std;

// Class to represent complex numbers
class Complex {
public:
    int real; // Real part of the complex number
    int img;  // Imaginary part of the complex number

    // Constructor to initialize the complex number
    Complex(int x, int y) {
        real = x;
        img = y;
    }

    // Operator overloading for addition
    Complex operator+(Complex &c) {
        Complex ans(0, 0);
        ans.real = real + c.real; // Add real parts
        ans.img = img + c.img;    // Add imaginary parts
        return ans;               // Return the result as a new Complex object
    }
};

int main() {
    // Create two complex numbers: c1 and c2
    Complex c1(1, 2); // Real part = 1, Imaginary part = 2
    Complex c2(1, 3); // Real part = 1, Imaginary part = 3

    // Use operator overloading to add c1 and c2 and store the result in c3
    Complex c3 = c1 + c2; // Addition is performed naturally, thanks to operator overloading

    // Print the real and imaginary parts of the result
    cout << "Real Part of c3: " << c3.real << endl;
    cout << "Imaginary Part of c3: " << c3.img << endl;

    return 0;
}

-Run-time Polymorphism

#include<iostream>
using namespace std;

// Base class
class Parent {
public:
    // Virtual function for polymorphism
    virtual void print() {
        cout << "Parent class" << endl;
    }

    // Non-virtual function
    void show() {
        cout << "Parent class" << endl;
    }
};

// Derived class
class Child : public Parent {
public:
    // Overridden virtual function
    void print() {
        cout << "Child class" << endl;
    }

    // Non-virtual function with the same name as the base class
    void show() {
        cout << "Child class" << endl;
    }
};

int main() {
    Parent* p;      // Pointer to the base class
    Child c;        // Object of the derived class

    p = &c;         // Point the base class pointer to the derived class object

    // Call virtual function, which exhibits polymorphism
    p->print();

    // Call non-virtual function, resolved at compile-time based on the pointer type
    p->show();

    return 0;
}
Explanation:

- This C++ code defines a base class `Parent` and a derived class `Child`.
- The `Parent` class has a virtual function `print()` and a non-virtual function `show()`.
- The `Child` class overrides the `print()` function, providing its own implementation.
- In the `main()` function, we create an object `c` of the `Child` class and a pointer `p` to the `Parent` class.
- We assign the address of the `Child` object `c` to the `Parent` pointer `p`. This is possible due to polymorphism.
- We call the `print()` and `show()` functions through the `p` pointer.
- The `print()` function is virtual, so it exhibits polymorphism and calls the implementation in the `Child` class.
- The `show()` function is non-virtual, so it is resolved at compile-time based on the pointer type (`Parent`), and it calls the `Parent` class implementation.

The output of this code will be:

```
Child class
Parent class
```
*/
```cpp
#include<iostream>
using namespace std;

// Class declaration
class A {
    int x; // Private member

public:
    // Constructor
    A(int y) {
        x = y;
    }

    // Declaring a friend function
    friend void print(A &obj);
};

// Friend function definition
void print(A &obj) {
    cout << obj.x << endl;
}

int main() {
    // Create an object of class A
    A obj(5);

    // Call the friend function to print the private member 'x'
    print(obj);

    return 0;
}

Output:-
5

In this code:

- The `A` class has a private member `x`, and its constructor initializes `x` with a value provided as an argument.

- The `print` function is declared as a friend of the `A` class. This allows the `print` function to access the private member `x` 
of objects of class `A`.

- In the `main` function, an object `obj` of class `A` is created with an initial value of 5.

- The `print` function is called with `obj` as an argument, allowing it to access and print the private member `x` of the `obj`.

- The output will be `5`, demonstrating that the friend function can access and print the private member of the class.

 -------------------------------------------------------------------------------------------------------------------

 Class v/s Objects

 * Classes and Objects in C++
 *
 * Class:
 * - Definition: A blueprint or template for creating objects. It defines the properties (attributes) and behaviors (methods)
 * that the objects created from the class will have.
 * - Structure: Contains member variables (data) and member functions (methods).
 * - Purpose: Encapsulates data for the object and methods to manipulate that data.
 * - Example:
 *     class Car {
 *     public:
 *         string color;
 *         string brand;
 *         int year;
 *
 *         void start() {
 *             cout << "Car started" << endl;
 *         }
 *
 *         void stop() {
 *             cout << "Car stopped" << endl;
 *         }
 *     };
 *
 * Object:
 * - Definition: An instance of a class. It represents a concrete entity with actual values for the properties defined by the class.
 * - Usage: Used to perform operations and store data defined by the class.
 * - Multiple Instances: Multiple objects can be created from the same class, each with different attribute values.
 * - Example:
 *     int main() {
 *         Car car1; // car1 is an object of the Car class
 *         car1.color = "Red";
 *         car1.brand = "Toyota";
 *         car1.year = 2020;
 *
 *         Car car2; // car2 is another object of the Car class
 *         car2.color = "Blue";
 *         car2.brand = "Ford";
 *         car2.year = 2018;
 *
 *         car1.start(); // Using car1's method
 *         car2.start(); // Using car2's method
 *
 *         return 0;
 *     }
 *
 * Differences Between Classes and Objects:
 * 1. Class is a blueprint or template, while an object is an instance of a class.
 * 2. Class defines attributes and methods; Object embodies actual values and functionalities.
 * 3. Class does not consume memory by itself; Objects consume memory when instantiated.
 * 4. One class can be used to create many objects; Each object is a unique instance.


-Size of a empty class is 1;
-Also,

#include <iostream>
using namespace std;

class a{
    int no;
    char c;
};

int main(){
    a obj;
//    Now normally its size should be 4+1 = 5 bytes but,
    cout<< sizeof(obj)<<" "; // 8
    //8!=5 , This is due to the concept of padding , and due to this only size of an empty class's object is 1;
    return 0;
}

-So , if I have

struct pad{
    char a;
    char b;
    int c;
}

it will be like this ,

is 0 a multiple of sizeof(a)? -> 0 multiple of 1 -> Yes -> allocate it -> 1 Byte
is 1 a multiple of sizeof(b)? -> 1 multiple of 1 -> Yes -> allocate it -> 1 Byte
is 2 a multiple of sizeof(c)? -> 2 multiple of 4 -> No -> Pad it -> 1 Byte
is 3 a multiple of sizeof(c)? -> 3 multiple of 4 -> No -> Pad it -> 1 Byte
is 4 a multiple of sizeof(c)? -> 4 multiple of 4 -> Yes allocate it -> 4 Byte

Therefore , total = 8 bytes


-But in case of

struct pad{
    char a;
    int b;
    char c;
}

It should be -> 1+3(pad)+4+1 = 9 bytes

but its size is allocated = 12 bytes WHY?

-Because the data type that is occupying the largest space should be able to divide the total size , so instead of taking
 9 which is not divisible by 4 , we take next multiple of 4 i.e. 12 .

-This concludes that to have s optimized space management we need to have better alignment -> we use greedy Alignment
 i.e. write the datatype with max. space first and then in decreasing order -> optimize utilization of memory

ex:-

struct a{
    char e;
    int b;
    char c;
    double d;
}

-Memory Alignment -> e p p p b b b b c p p p p p p p d d d d d d d d = 24 bytes

-----------------------------------------------------------GPT-----------------------------------------------------------------------

-Padding in C++: A Simple Explanation

 **Padding** is the extra space added between data members of a structure in memory to align them according to the processor's
 * requirements. This alignment helps the processor access the data more efficiently.

### Why Padding is Needed

- **Alignment**: Processors access data faster if it is aligned at certain memory boundaries (e.g., 4 bytes, 8 bytes).
- **Performance**: Proper alignment reduces the number of memory access cycles, improving performance.

### Efficient Memory Access

1. **Aligned Data**: When data is aligned, the CPU can access it in a single memory access cycle. For example, accessing an
 integer that starts at an address divisible by 4 (assuming a 4-byte integer) is faster.
2. **Misaligned Data**: If data is misaligned, the CPU may need to perform multiple memory access cycles to fetch the data,
 which is slower.
3. **Processor Design**: CPUs are optimized to read data at certain boundaries. Accessing data that spans multiple chunks
 requires extra processing, leading to slower access times.

### Example of Padding

        Consider this structure:

```cpp
struct Example {
    char a;  // 1 byte
    int b;   // 4 bytes
    char c;  // 1 byte
};
```

Without padding, it would look like this in memory:

```
| a | b | b | b | b | c |
```

But with padding, it actually looks like this:

```
| a | pad | pad | pad | b | b | b | b | c | pad | pad | pad |
```

- `a` (1 byte) is followed by 3 bytes of padding to align `b`.
- `c` (1 byte) is followed by 3 bytes of padding to maintain alignment.

### Reducing Padding

You can minimize padding by rearranging the members:

```cpp
struct OptimizedExample {
    int b;   // 4 bytes
    char a;  // 1 byte
    char c;  // 1 byte
};
```

This results in less padding and more efficient memory usage:

```
| b | b | b | b | a | c | pad | pad |
```

### Summary

- **Padding**: Extra space added to align data in memory.
- **Alignment**: Ensures data is accessed efficiently by the CPU.
- **Performance**: Aligned data is accessed faster, improving overall performance.
- **Rearranging Members**: Helps reduce padding and optimize memory usage.

By understanding padding, you can write more efficient and optimized code, ensuring data is aligned for faster access by the processor.

-------------------------------------------------------------GPT-END------------------------------------------------------------------

-Static V/S Dynamic memory allocation

-Memory/data can be stored be either stack or heap but in stack you can't demand for too much space due to this it is used
 for static allocation only whereas heap provides us with a much large space to occupy making it suitable for dynamic allocation

student *s=new student; //Dynamically created object
(*s).name="Aditya";
or
s->name="Aditya";

-Constructor

 -It is a special functions that is automatically invoked at the time of object creation
 -It's name is same as the class name
 -It does not have a return type

 -It can be default , default user defined , parametrized
    -In case our parametrized variable and data members of class have same name , in that case we take the one that
    is closest i.e. parametrized variables instead of data members

Examples on Types of Constructors :-

class a{
public:
    int name,cap;
    a(){
        cout<<"Constructor is called!"; //default constructor
    }

    a(int name,int cap){
        name=name; //what it is doing is that it is writing value of name in name(variable) only which is making no change
                    // leaving our data members with no value
        cap=cap;
    }

    //So to resolve this problem , we use a pointer "this" which points to object so we access our data members using "this->"
    //'this' will store the address of object which has called it.

    //Parameterized Constructor
    a(int name,int cap){
        this->name=name;
        this->cap=cap;
        //Now value of name and cap will be assigned to the data members of the objects
    }

    a(int name){
        this->name=name;
        //Here value of cap will be initialized as garbage value
    }

    //Inline constructor
    inline a(int n,int c) : name(n),cap(c){
        cout<<"Inline Constructor";
    }

    //NOTE:- Here parameterized and inline have same parameters and definition -> this will give error , so we have to make their
    number of parameters different or we can use only one at a time.

    // rest(copy constructor) are a little below , as it was getting congested
};

-Function/Constructor Overloading:

This concept of creating multiple function/Constructors with same function name but different parameters is called
Function/Constructor Overloading

-Inline Constructors:

 -A constructor defined within the class body is considered an inline constructor.
 -Defining the constructor inside the class declaration automatically makes it an inline function.
 -All functions as well as constructors which are defined inside a class are by default inline though you can also explicitly define them
 -The inline keyword can also be explicitly used in the constructor definition outside the class to make it an inline function.

Advantages of Inline Constructors:
 -Inline constructors help improve the efficiency of the code by reducing the function call overhead.
 -They allow the compiler to substitute the constructor code directly at the call site, rather than making a function call.
 -This can lead to faster execution times, especially for small, simple constructors.

-Uses of constructors:-
 -Can be used to initialise data members of an object
 -To check the availability of resources in advance saving us time and effort
 -Used to open files , with whose help we can know at the very start if the resources are available or not.

-Copy Constructor


#include <iostream>
using namespace std;

class a{
public:
    int first,second;
    a(int f,int s){
        first=f;
        second=s;
    }

    //Explicitly defined copy constructor
    a(a &o){  //-> se below reason for using "&"
        first=o.first;
        second=o.second;
    }
};

int main(){
    a obj(1,2);

    //This is a system designed copy constructor
    //a cobj(obj); //1 2

    a cobj(obj);  //1 2 -> explicitly defined copy constructor

    //Can do it like this
    a ccobj(3,6);
    ccobj=cobj;  //1 2
    cout<<ccobj.first<<" "<<ccobj.second<<endl;
    return 0;
}

But Now comes a twist , if we were not able to copy the values from "obj" to "cobj" ,how can "o" copy values from "obj" when passed by value
as at that particular instance it calls copy constructor again (as it is explicilty defined (so it will not call system created
copy constructor)), which will lead to infinite recursion , so to solve this problem
we never pass object by "call by value" in copy constructor as it creates a copy of itself by again calling the constructor leading
to infinite recursion , so to solve it we pass values by "call by reference" using "&".

-Destructor

 -It is an instance member function that is invoked automatically whenever a object is going to be destroyed
 -It is the last function that is going to be called before object is destroyed

 -A destructor is a special member function of a class that is executed when an object of that class goes out of scope
 or is explicitly deleted. It is used to release resources that the object may have acquired during its lifetime,
 such as dynamically allocated memory or open file handles.

 -The primary role of a destructor is to clean up and free resources to avoid memory leaks or other resource management issues.

 -Data members of an object get deleted automatically when the object's scope ends, such as when the program exits the block
 in which the object was created (e.g., when the main() function finishes if the object is local to main()).

 -The destructor does not delete the data members themselves. Instead, it performs cleanup tasks that may be necessary for
 those data members, like freeing dynamic memory they might point to or closing files they might have opened.

 -Destructor get's executed in reverse of that of constructor creation i.e. if there objects a,b,c are created in this order
 then the destructor order will be c,b,a;

 *Reason -> Why destructors are called in reverse Order?

 -This is because the objects are created in a Stack which follows the LIFO order, so when one object gets out of the stack,
 its destructor gets called. Also, the intuition behind this LIFO order is that, one object can be dependent of other object
 in case of copy constructor.

 -Eg: for Customer A4(A3), suppose A3 contains one dynamically allocated data, it means that A4 is dependent on A3.
 Now, if A3 is destroyed first, then that heap memory is also going to be destroyed and A4 will not have any data to point to.


#include <iostream>
using namespace std;

class a{
public:
    int first,second;

    //constructor
    a(int f,int s){
        first=f;
        second=s;
        cout<<"Constructor : "<<first<<endl;
    }

    //destructor
    ~a(){
        cout<<"Destructor : "<<first<<endl;
    }
};

int main(){
    a a1(1,2),a2(2,3),a3(3,4);
    return 0;
}

//Output:-
//Constructor : 1
//Constructor : 2
//Constructor : 3
//Destructor : 3
//Destructor : 2
//Destructor : 1

-If case we point a pointer to an object then its memory/resources does not get released automatically , we have to explicitly
use delete keyword to free its resource

a* a1=new a; //It will not call destructor automatically -> memory won't be free
delete a1; //Now memory will be free

-Static Data Member

 -They are attributes of classes or class members
 -Only one member is created for entire class and is shared by all objects -> i.e. value static (global type rehti he)
 -They Belong to class and not data members
 -It should be in public and if not we have to use static member function to access the private static data member

 -By writing the function/data member becomes part of our class
 -Cannot use or call non-static members/functions in static function


#include <iostream>
using namespace std;

class a{
    static int count;
public:
    int first,second;
    //static int count;

    //constructor
    a(int f,int s){
        first=f;
        second=s;
        cout<<"Constructor : "<<first<<endl;
        count++;
    }

    //Static getter function to access private static variable
    static int accStatic(){
        //This function cannot access non-static variables in the class
        //first; -> gives error
        cout<<"Count : "<<count;
    }

    void display(){
        cout<<"Count : "<<count<<endl;
    }

};

int a::count=0;  //initialising static int variable out of class

int main(){
    a a1(1,2),a2(2,3),a3(3,4);
    a1.display();  //3
    a2.display();  //3
    a3.display();  //3
//  a::count=5; //when it was in public
    a::accStatic(); //3
    return 0;
}

-"const":

 -Unlike static they are not shared among all instances i.e. object , each object have their own copy of const

Const Member Functions:
 -Functions that do not modify the state of the object.
 -Can be called on const objects.
 -Indicated by placing const at the end of the function declaration.

Const Data Members:
 -Data members that are immutable after initialization.
 -Must be initialised using an initializer list in the constructor.

Const Objects:
 -Objects that are declared as const cannot have their member variables modified directly or through non-const member functions.

Const Parameters in Member Functions:
 -Ensures that the objects passed to member functions are not modified.
 -Useful for functions that need to read data without changing it.

Const Return Types:
 -Functions that return const references or pointers to ensure the returned object cannot be modified by the caller.
 -Useful for protecting internal data from modification.

 Code:-

#include <iostream>

class MyClass {
public:
    // Constructor to initialize const and non-const members
    MyClass(int v) : constValue(v) {
        ++sharedCount;
    }

    // Const member function
    int getConstValue() const {
        return constValue;
    }

    // Non-const member function
    void setValue(int v) {
        value = v;
    }

    // Const member function returning a const reference
    const int& getValue() const {
        return value;
    }

    // Static member function
    static int getSharedCount() {
        return sharedCount;
    }

    // Static member function to modify the static member variable
    static void resetSharedCount() {
        sharedCount = 0;
    }

private:
    const int constValue; // Const data member
    int value; // Regular data member
    static int sharedCount; // Static data member
};

// Initialise static member variable
int MyClass::sharedCount = 0;

void demonstrateConstKeyword() {
    // Create objects
    MyClass obj1(10);
    MyClass obj2(20);

    // Display const member values
    std::cout << "obj1 const value: " << obj1.getConstValue() << std::endl; // Outputs 10
    std::cout << "obj2 const value: " << obj2.getConstValue() << std::endl; // Outputs 20

    // Modify non-const member through non-const member function
    obj1.setValue(100);
    obj2.setValue(200);

    // Display non-const member values
    std::cout << "obj1 value: " << obj1.getValue() << std::endl; // Outputs 100
    std::cout << "obj2 value: " << obj2.getValue() << std::endl; // Outputs 200

    // Display static member variable
    std::cout << "Shared count: " << MyClass::getSharedCount() << std::endl; // Outputs 2

    // Reset static member variable
    MyClass::resetSharedCount();
    std::cout << "Shared count after reset: " << MyClass::getSharedCount() << std::endl; // Outputs 0

    // Working with const objects
    const MyClass obj3(30);

    // obj3.setValue(300); // Error: cannot call non-const member function on a const object
    std::cout << "obj3 const value: " << obj3.getConstValue() << std::endl; // Outputs 30
    // std::cout << "obj3 value: " << obj3.getValue() << std::endl; // Outputs 0 (default-initialized, undefined if not set explicitly)
}

int main() {
    demonstrateConstKeyword();
    return 0;
}

-Encapsulation

 -Wrapping up data or information in a single unit while controlling access to them
 -User should not have access to some data members or functions which could lead to incorrect data filling/operation , so to
 resolve it we hide the data members in private , this is called Encapsulation.

-Abstraction

 -Displaying only the essential information and hiding the details .

-Inheritance

 -The capability of class to derive properties and characteristics from another class

-Access Modifier

 In which access we want to inherit the properties/characteristics of our base/parent class

 -Class/data in public mode can be used outside the class , within the class and also by derived class
 -In protected mode , it cannot be used outside the class , we can use it within the class and also by derived class
 -Private , cannot be used outside the class ,can be used inside the class and also cannot be used by derived class

Code to understand

#include <iostream>

class Base {
public:
    int publicVar; // Accessible from anywhere

    Base() : publicVar(1), protectedVar(2), privateVar(3) {}

    void showVars() {
        std::cout << "Base publicVar: " << publicVar << std::endl;
        std::cout << "Base protectedVar: " << protectedVar << std::endl;
        std::cout << "Base privateVar: " << privateVar << std::endl;
    }

protected:
    int protectedVar; // Accessible within the class and derived classes

private:
    int privateVar; // Accessible only within the class
};

// Public inheritance: Public and protected members of Base remain public and protected in Derived
class PublicDerived : public Base {
public:
    void showInheritedVars() {
        std::cout << "PublicDerived publicVar: " << publicVar << std::endl; // Accessible
        std::cout << "PublicDerived protectedVar: " << protectedVar << std::endl; // Accessible
        // std::cout << "PublicDerived privateVar: " << privateVar << std::endl; // Not accessible
    }
};

// Protected inheritance: Public and protected members of Base become protected in Derived
class ProtectedDerived : protected Base {
public:
    void showInheritedVars() {
        std::cout << "ProtectedDerived publicVar: " << publicVar << std::endl; // Accessible as protected
        std::cout << "ProtectedDerived protectedVar: " << protectedVar << std::endl; // Accessible as protected
        // std::cout << "ProtectedDerived privateVar: " << privateVar << std::endl; // Not accessible
    }
};

// Private inheritance: Public and protected members of Base become private in Derived
class PrivateDerived : private Base {
public:
    void showInheritedVars() {
        std::cout << "PrivateDerived publicVar: " << publicVar << std::endl; // Accessible as private
        std::cout << "PrivateDerived protectedVar: " << protectedVar << std::endl; // Accessible as private
        // std::cout << "PrivateDerived privateVar: " << privateVar << std::endl; // Not accessible
    }
};

// Derived class from PublicDerived (public inheritance)
class GrandChild : public PublicDerived {
public:
    void showInheritedVars() {
        std::cout << "GrandChild publicVar: " << publicVar << std::endl; // Accessible
        std::cout << "GrandChild protectedVar: " << protectedVar << std::endl; // Accessible
        // std::cout << "GrandChild privateVar: " << privateVar << std::endl; // Not accessible
    }
};

void demonstrateInheritanceAndAccessModifiers() {
    Base baseObj;
    baseObj.showVars();

    PublicDerived publicDerivedObj;
    publicDerivedObj.showInheritedVars();

    ProtectedDerived protectedDerivedObj;
    protectedDerivedObj.showInheritedVars();
    // std::cout << protectedDerivedObj.publicVar << std::endl; // Not accessible

    PrivateDerived privateDerivedObj;
    privateDerivedObj.showInheritedVars();
    // std::cout << privateDerivedObj.publicVar << std::endl; // Not accessible

    GrandChild grandChildObj;
    grandChildObj.showInheritedVars();
}

int main() {
    demonstrateInheritanceAndAccessModifiers();
    return 0;
}

-Types of Inheritance

-1.Single level Inheritance - one parent class and one derived class


#include<iostream>
using namespace std;

class Human{
protected:
    string name;
    int age;
public:
    Human(){
        cout<<"Human Constructor Called "<<endl;
    }
    ~Human(){
        cout<<"Human Destructor is called "<<endl;
    }
    void display(){
        cout<<name<<" "<<age<<endl;
    }
};

class student:public Human{
public:
    int rollno,fees;

    student(string name,int age,int r,int fees){
        this->name=name;
        this->age=age;
        rollno=r;
        this->fees=fees;
        cout<<"Student Constructor Called "<<endl;
    }

    ~student(){
        cout<<"Student destructor is called "<<endl;
    }

    void display(){
        cout<<name<<" "<<age<<" "<<rollno<<" "<<fees<<endl;
    }
};

int main(){
    student s("Aditya",23,21,150000);
//    Order of Constructor Creation
//    Human Constructor Called
//    Student Constructor Called
//    This shows that first the constructor of parent class is called then the constructor of derived class is called.

//    Whereas in regards to destructor
//    Student destructor is called
//    Human Destructor is called
//    First the destructor of child class is called as they are present in stack and child is dependent on parent class , so it will
//    be destroyed before parent class hence this order.

//    Can also call the constructor of parent explicitly using the syntax at derived constructor :-
//    student(int rollno,int fees):Human(string name,int age){}  //Now of-course a parameterized constructor of Human should be present

//    For functions with same name(i.e. same name and parameter function present in both child and parent class ) -Then It first start
//            searching from the class whose object is used to call the function i.e. in this cases derived class.

    s.display(); //    Aditya 23 21 150000

//    Do NOTE one thing that I read Before that what destructor does is release dynamically allocated memory and the objects are
//    deleted when main finishes i.e. their scope ends . This code Output explains/verify this point.

//    Output:-
//    Human Constructor Called
//    Student Constructor Called
//    Aditya 23 21 150000
//    Student destructor is called
//    Human Destructor is called

    return 0;
}

-2.Multilevel Inheritance - Inheritance on multiple levels i.e. a->b->c -> a parent of b and b parent of c

#include<iostream>
using namespace std;

class Human{
protected:
    string name;
    int age;
public:
    Human(){
        cout<<"Human Constructor Called "<<endl;
    }
    ~Human(){
        cout<<"Human Destructor is called "<<endl;
    }
    void display(){
        cout<<name<<" "<<age<<endl;
    }
};

class student:public Human{
public:
    int rollno,fees;
    student(){

    }
    student(string name,int age,int r,int fees){
        this->name=name;
        this->age=age;
        rollno=r;
        this->fees=fees;
        cout<<"Student Constructor Called "<<endl;
    }

    ~student(){
        cout<<"Student destructor is called "<<endl;
    }

    void display(){
        cout<<name<<" "<<age<<" "<<rollno<<" "<<fees<<endl;
    }
};

class aditya:public student{
public:
    int unique;
    aditya(string name,int age,int r,int fees,int unique){
        this->name=name;
        this->age=age;
        rollno=r;
        this->fees=fees;
        this->unique=unique;
        cout<<"Constructor for Aditya"<<endl;
    }
    ~aditya(){
        cout<<"Destructor for aditya"<<endl;
    }
    void display(){
        cout<<name<<" "<<age<<" "<<rollno<<" "<<fees<<endl;
    }
};

int main(){
    aditya a("Adi",23,2,424,1);
    a.display();
    return 0;

    //Same concept as Single level Inheritance

//    Output:-
//    Human Constructor Called
//    Constructor for Aditya
//    Adi 23 2 424
//    Destructor for aditya
//    Student destructor is called
//    Human Destructor is called

    //Here default constructor of student is called rather than parametrized i.e. we don't have it in output
}

-3.Multiple Inheritance - When derived class has multiple base class


#include<iostream>
using namespace std;

class Human{
protected:
    string name;
    int age;
public:
    Human(){
        cout<<"Human Constructor Called "<<endl;
    }
    ~Human(){
        cout<<"Human Destructor is called "<<endl;
    }
    void display(){
        cout<<name<<" "<<age<<endl;
    }
};

class student{
public:
    int rollno,fees;
    student(){
        cout<<"Student Constructor Called "<<endl;
    }

    ~student(){
        cout<<"Student destructor is called "<<endl;
    }

    void display(){
        cout<<rollno<<" "<<fees<<endl;
    }
};

class Coder:public student,public Human{
public:
    int unique;
    Coder(string name,int age,int r,int fees,int unique){
        this->name=name;
        this->age=age;
        rollno=r;
        this->fees=fees;
        this->unique=unique;
        cout<<"Constructor for Coder"<<endl;
    }
    ~Coder(){
        cout<<"Destructor for Coder"<<endl;
    }
    void display(){
        cout<<name<<" "<<age<<" "<<rollno<<" "<<fees<<" "<<unique<<endl;
    }
};

int main(){
    Coder a("Adi",23,2,424,1);

//    Order of Constructor Creation and Destruction:
//    Student Constructor Called
//    Human Constructor Called
//    Constructor for Coder
//    Destructor for Coder
//    Human Destructor is called
//    Student destructor is called

    return 0;
}

-4.Hierarchical Inheritance -> Single base class and multiple derived/child class

#include<iostream>
using namespace std;

class Human{
protected:
    string name;
    int age;
public:
    Human(){
        cout<<"Human Constructor Called "<<endl;
    }
    ~Human(){
        cout<<"Human Destructor is called "<<endl;
    }
    void display(){
        cout<<name<<" "<<age<<endl;
    }
};

class student:public Human{
public:
    int rollno,fees;
    student(){

    }
    student(string name,int age,int r,int fees){
        this->name=name;
        this->age=age;
        rollno=r;
        this->fees=fees;
        cout<<"Student Constructor Called "<<endl;
    }

    ~student(){
        cout<<"Student destructor is called "<<endl;
    }

    void display(){
        cout<<name<<" "<<age<<" "<<rollno<<" "<<fees<<endl;
    }
};

class aditya:public Human{
public:
    int unique;
    aditya(string name,int age,int unique){
        this->name=name;
        this->age=age;
        this->unique=unique;
        cout<<"Constructor for Aditya"<<endl;
    }
    ~aditya(){
        cout<<"Destructor for aditya"<<endl;
    }
    void display(){
        cout<<name<<" "<<age<<" "<<endl;
    }
};

int main(){
    aditya a("Adi",23,1);
    a.display();
    return 0;

    //Same concept as other Inheritance
}

-5.Hybrid Inheritance - Inheritance with both multiple and hierarchical inheritance combined. Represent all possible combinations of inheritance

ex :- Male class inherits boy and student class and Female class inherits girl and student class -> Hybrid Inheritance

-6.Multipath Inheritance - IN an inheritance we are getting the same thing but through multiple path

To resolve the ambiguity in Multipath Inheritance we use virtual keyword.


#include<iostream>
using namespace std;

class Human{
protected:
    string name;
    int age;
public:
    Human(){
        cout<<"Human Constructor Called "<<endl;
    }
    ~Human(){
        cout<<"Human Destructor is called "<<endl;
    }
    void display(){
        cout<<name<<" "<<age<<1<<endl;
    }
};

class student:public virtual Human{
public:
    int rollno,fees;
    student(){
        cout<<"Constructor for Student"<<endl;
    }

    ~student(){
        cout<<"Student destructor is called "<<endl;
    }

};

class Coder:public virtual Human{
public:
    Coder(){
        cout<<"Constructor for coder"<<endl;
    }
    ~Coder(){
        cout<<"Coder destructor is called"<<endl;
    }

};

class aditya:public Coder, public student{
public:
    aditya(){
        cout<<"Constructor for aditya"<<endl;
    }
    ~aditya(){
        cout<<"Destructor for aditya"<<endl;
    }
};

int main(){
    aditya a;
//    a.display(); ->error
//    This is the problem/error we get :

//    Non-static member 'display' found in multiple base-class subobjects of type 'Human':
//    class aditya -> Coder -> Human
//    class aditya -> student -> Human
//    member found by ambiguous name lookup

//    It is because both my Coder and Student have a copy of Human(data member and functions) , so the compiler doesn't know which it
//    should choose when a function or data member is called.

//    To resolve it we have to use virtual keyword while inheriting Human
    a.display(); // -> now it is working fine;
    return 0;

//    Output/Flow of constructor creation and deletion:
//    Human Constructor Called
//    Constructor for coder
//    Constructor for Student
//    Constructor for aditya
//    01
//    Destructor for aditya
//    Student destructor is called
//    Coder destructor is called
//    Human Destructor is called

    //Same concept as other Inheritance
}

-Polymorphism

 Polymorphism is a feature in C++ that allows one function or method to behave differently based on the object that calls it.
 -It enables the same function name to be used for different types, allowing objects to be treated as instances of their parent class,
 -but still call the correct function for their specific type.

There are two types of Polymorphism -> 1.Compile time and 2.Runntime time Polymorphism

-1.Compile-time Polymorphism (Static Binding):
 -This type of polymorphism is resolved during the compilation of the program.
 -It is achieved using function overloading and operator overloading.

-2.Run-time Polymorphism (Dynamic Binding):
 -This type of polymorphism is resolved during the execution of the program.
 -It is achieved using inheritance and virtual functions.

-Function Overloading - Same function name and return type but different parameters

#include<iostream>
using namespace std;

class shape{
public:
    int area(int r){
        return 3.14*r*r;
    }
    int area(int l,int b){
        return l*b;
    }
};

int main(){
    shape s1,s2;
    cout<<s1.area(4)<<endl;  //50
    cout<<s2.area(5,6);  //30
    return 0;
}

-Operator Overloading

#include<iostream>
using namespace std;

class Complex{
    int real ,img;
public:

    Complex(){
        //Default Constructor
    };

    //NOTE:- It is optional to put semicolon ";" after the constructor

    Complex(int real,int img){
        this->real=real;
        this->img=img;
    };
    void display(){
        cout<<real<<" + i"<<img<<endl;
    }

    //This is operator Overloading
    Complex operator +(Complex &c){
        Complex c3;
        c3.real=real+c.real;  //Here 'real' is member of object with which function is called and 'c.real' if for object on which '+'
                                // is called
        c3.img=img+c.img;   //Within the class you can access the private member of an object given that it is of same class.
        //Like here I can access c.real even though they are in private , this is due to above reason
        return c3;
    }
};

int main(){
    Complex c1(1,2);
    Complex c2(3,4);
    Complex c3=c1+c2; //Here object c1 is called a function which is "+" while passing parameter c2 -> c1.add(c2);
    c3.display();  //4 + i6
    return 0;
}


-Virtual Function - Used to perform runntime polymorphism tells the compiler to not decide which function should execute based
                    on dataype of object used (either parent or child class).
                    After writing it compiler decides the execution part during runntime where it sees what kind of object is getting
                    created , so then w.r.t that object it will call the function. This is called Runntime Polymorphism.


#include <iostream>
#include <vector>
using namespace std;

class animal{
public:
    virtual void speak(){
        cout<<"HUHU"<<endl;
    }

//    virtual void speak()=0; //This will be called pure virtual function -> Also called as abstract class.

//    And remember you can never create object of a abstract class.(Pure virtual function).

//    Use case -> as we know animal in general does not make any sound , so i shouldn't be allowed to make its object

//    It will not give any problem being used as a pointer datatype or during inheritance constructor creation.

};

class dog:public animal{
public:
    void speak(){
        cout<<"bark"<<endl;
    }
};

class cat:public animal{
public:
    void speak(){
        cout<<"Meow"<<endl;
    }
};

int main(){
    animal *p; //pointer to the animal class
    p=new dog();

    //Without using Virtual
//    p->speak(); //Output -> HUHU

//    While using virtual keyword
    p->speak();  //Output -> bark

//    -So when virtual is not written it decides at compile time w.r.t the datatype/class of object using in this case initially
//     it was "animal" (as dog object was not created yet , as it was to be created dynamically i.e. at runntime ),
//        so it ran the function of animal but by writing the keyword virtual it tells the compiler to decide
//     things at runn time , due to which now the pointer "p" has object of "dog" inside it and will execute function of it.

//    -Hence we will say that speak of dog has overwritten the speak of animal


//    If you try to access another function of dog which is not in animal using the pointer with animal as its datatype then you will
//    get error

//    Therefore, Runntime polymorphism is only possible if the derived class function have same name as base class function

//    Why create pointer of base class and make things complex when you can just create pointer pointing to derived class??

//    -It is because using the pointer of parent class we can point to derived class , so when we have to store multiple objects
//            of different classes rather than type casting each one , we can make the datatype of vector as parent/base class
//            pointer and use it to store dynamically allocated objects of its derived classes .
//            This problem is much more bigger when think w.r.t real world scenario as we can have hundreds of different classes to
//            be stored.

    vector<animal*> v;
    v.push_back(new dog());
    v.push_back(new cat());
    v.push_back(new animal());  //Will not work if pure virtual function is used i.e. Abstract classes
    v.push_back(new cat());
    v.push_back(new dog());
    v.push_back(new cat());

    for(int i=0;i<v.size();i++){
        v[i]->speak();
    }

//    Output:-
//    bark
//    Meow
//    HUHU
//    Meow
//    bark
//    Meow

    return 0;
}

-Templates -  allows you to write generic and reusable code. They enable functions and classes to operate with generic types,
 which means you can create a function or class to work with any data type without rewriting code for each type.

 -They are also called parametrized classes
 -With their help we don't have to write code again and again for different datatype , we can write them in general from for all .
 -A Template represent multiple classes written in generalized/generic form.

#include <iostream>
using namespace std;

template <class T>  // for multiple customer datatype we can write like -> template<class T1,class T2,....> and so rest all is same.
//Can also write template with default argument -> template<class T1=int,class T2=char,...>
//same can be used for function called generic function
class vector{
public:
    T* arr;
    int size;

    vector(int m){
        size=m;
        arr=new T[size];
    }

    T dotPro(vector &v){
        T sum=0;
        for(int i=0;i<size;i++){
            sum += this->arr[i] * v.arr[i]; // -> (jis object se call kiya gaya he) * (jo vector as a parameter pass kiya gaya he)
        }
        return sum;
    }

    void display(); //Defining the function .
};

//generic function
template<class T1,class T2>
int add(T1 a,T2 b){
    return a+b;
}

//This is how we write a function outside a class
template <class T>
void vector<T>::display() {
    cout<<size<<endl;
}

//In function(template) overloading i.e. when a function and template have same name and no. of parameters -> exact match takes the
//highest priority
int over(int a){
    cout<<"int ka over "<<endl;
    return a;
}

template<class T>
T over(T a){
    cout<<"Template ka over "<<endl;
    return a;
}

int main(){
    vector<float> v(3);  //Here I can use any data type
    //At the timme of object creation only i have to specify the data types being used like <int,char,...>
//    vector<> v; //To use default arguments
    v.arr[0]=1.23;
    v.arr[1]=1.56;
    v.arr[2]=3.43;
    vector<float> v1(3);
    v1.arr[0]=1.23;
    v1.arr[1]=1.56;
    v1.arr[2]=3.43;
    cout<<v1.dotPro(v)<<endl;  //15.7114
    over(4);  //int ka over
    over("a");  //Template ka over
    return 0;
}

-STL - Standard Template Library


 -provides us with library of generic classes and functions
 -We get well tested components and it saves our time.

-Container - It is a object that stores data -> uses template classes

 Types :- -1.Sequential - stores in data in linear fashion -> like vector , list
        -2.Associative - Allows direct access -> like map(unordered + multi) , sets(unordered + multi) -> allows faster access but slower random access
        -3.Derived container -> used for real world modelling -> like stacks , queues , priority queue

-Algorithms - Procedure to process data -> Used for data manipulation -> like sorting , searching -> use template functions

-Iterators - It is an object that points to an element in a container -> handled just like containers -> connects algo's and container's.

------------------------------------------- left out concepts --------------------------------------------------

-Passing array of objects as parameters

#include<iostream>
using namespace std;

class a{
public:
    void take(a* arr){
        for(int i=0;i<20;i++){

        }
    }
    void display(a*);
};

void a::display(a * arr) {
    cout<<"Ulahaa ha";
}

int main(){
    a b[20];
    b[0].take(b);
}

-Friend Function - using this we can allow a function outside the class to have access of private data of a class.

 -It is out of scope of class
 -It cannot be called from object of class
 -it needs a object to access data of class


#include<iostream>
using namespace std;

//Forward declaration -> karna padta he
class a;

class b{
public:
    void sum(a);  //ye tab karunga when i am using a class which i have not declared yet.
};

class a{
    int z=55;
public:
    void take(a* arr){
        for(int i=0;i<20;i++){

        }
    }
    void display(a*);

    friend void show(a);  //friend function
    friend void b::sum(a);  //declaring a function of a class as friend
    friend class b; //declaring the entire class as friend

};

void show(a var){
    cout<<var.z;
}

void b::sum(a c){
    show(c);
    c.z;
}

void a::display(a * arr) {
    cout<<"Ulahaa ha";
}



int main(){
    a l;
    show(l);  //55
    b w;
    w.sum(l);
    return 0;
}

-Exceptions:-

In C++, exceptions are used to handle errors and other exceptional situations in a controlled way.
 They allow you to separate error handling code from the main logic of the program.
 Let's go through the syntax for throwing and catching exceptions, including how to pass arguments with exceptions.

### Basic Syntax for Exceptions

1. **Throwing an Exception**: Use the `throw` keyword followed by an exception object.
2. **Catching an Exception**: Use a `try` block to wrap the code that might throw an exception and a `catch` block to handle the exception.

### Example of Basic Exception Handling

```cpp
#include <iostream>
#include <stdexcept> // For standard exceptions like std::runtime_error

void mayThrow(bool shouldThrow) {
    if (shouldThrow) {
        throw std::runtime_error("An error occurred");
    }
}

int main() {
    try {
        mayThrow(true);
    } catch (const std::runtime_error& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
```

### Explanation

1. **Throwing an Exception**:
- In `mayThrow`, an exception of type `std::runtime_error` is thrown if the argument `shouldThrow` is `true`.

2. **Catching an Exception**:
- The `try` block in `main` contains the code that might throw an exception.
- The `catch` block handles the exception by catching it as a `std::runtime_error` reference and printing the error message.

### Custom Exceptions with Arguments

You can define your own exception classes to pass specific information when an exception is thrown. Here's how to do it:

1. **Define a Custom Exception Class**.
2. **Throw the Custom Exception**.
3. **Catch the Custom Exception and Access the Arguments**.

### Example of Custom Exception

```cpp
#include <iostream>
#include <string>

// Custom exception class
class MyException : public std::exception {
private:
    std::string message;
    int errorCode;
public:
    MyException(const std::string& msg, int code) : message(msg), errorCode(code) {}

    // Override what() method
    const char* what() const noexcept override {
        return message.c_str();
    }

    // Method to get the error code
    int getErrorCode() const {
        return errorCode;
    }
};

void mayThrow(bool shouldThrow) {
    if (shouldThrow) {
        throw MyException("Custom error occurred", 404);
    }
}

int main() {
    try {
        mayThrow(true);
    } catch (const MyException& e) {
        std::cerr << "Caught custom exception: " << e.what() << std::endl;
        std::cerr << "Error code: " << e.getErrorCode() << std::endl;
    }

    return 0;
}
```

### Explanation

1. **Custom Exception Class**:
- `MyException` inherits from `std::exception`.
- It has private members to store the error message and error code.
- The constructor initializes these members.
- The `what` method is overridden to return the error message.
- A `getErrorCode` method is added to retrieve the error code.

2. **Throwing the Custom Exception**:
- In `mayThrow`, an exception of type `MyException` is thrown if the argument `shouldThrow` is `true`.

3. **Catching the Custom Exception**:
- The `catch` block in `main` handles the `MyException` by catching it as a reference to `MyException`.
- It prints the error message and error code using the `what` and `getErrorCode` methods, respectively.

### Key Points

- **Exception Classes**: Can inherit from `std::exception` and override the `what` method.
- **Throwing Exceptions**: Use the `throw` keyword followed by an instance of the exception class.
- **Catching Exceptions**: Use `try` and `catch` blocks, catching exceptions by reference to avoid slicing and to access the original exception object.

By defining custom exceptions and using arguments, you can provide detailed error information and handle exceptions in a more flexible and informative way.
