/*
-OOPS - Object oriented programming
-Notes and definition are in notebook!

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
