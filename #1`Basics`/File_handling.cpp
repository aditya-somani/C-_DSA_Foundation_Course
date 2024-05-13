/*

### File Handling :

- File handling is used to store data permanently in secondary memory i.e. permanently
- Streams → flow of data in sequence
- We have to use header file i.e. fstream
- For writing in File , First we have to  create a object with datatype ofstream
- os.open() → is used to create a file , we have to pass the address where we want the file to be created

```cpp
#include "iostream"
#include "fstream"
using namespace std;
int main(){
    ofstream os;  //os is object created for ofstream which is used to write in file
    os.open("C:\\Users\\H.P\\Desktop\\aditya.txt");
    os<<"Helping Poor people is my Passion ";  //Used to write
    os.close();
    return 0;
}
```

- For reading the file , we have to create a object with datatype ifstream

```cpp
#include "iostream"
#include "fstream"
using namespace std;
int main(){
    ifstream is;string str;
    is.open("C:\\Users\\H.P\\Desktop\\aditya.txt");
    is>>str;
    is.close();
    cout<<str;  //It's output will be -> Helping
    //This is because we have space between them , so we have to use loop to get everything
    return 0;
}
```

- So, to solve this problem we will sue getline() function in loop

```cpp
#include "iostream"
#include "fstream"
using namespace std;
int main(){
    ifstream is;string str;
    is.open("C:\\Users\\H.P\\Desktop\\aditya.txt");
    while(getline(is,str)){
        cout<<str; //Output-> Heling poor people is my passion
    }
    is.close();
    return 0;
}
```

- To create a copy of my file we need to get data by reading a file using ifstream and then using get() function in the object which is reading my file and paste that in a variable a of datatype **char** and then use in loop put() with object of ofstream

```cpp
#include "iostream"
#include "fstream"
using namespace std;
int main(){
    ifstream is;char str;
    ofstream of;
    is.open("C:\\Users\\H.P\\Desktop\\aditya.txt");
    of.open("C:\\Users\\H.P\\Desktop\\aditya1.txt");  //aditya1 is copy of aditya
    while(is.get(str)){
        of.put(str);
    }
    is.close();
    of.close();
    return 0;
}
```

- Program to create a copy of a file i.e. transferring all data into the other

```cpp
#include "iostream"
#include "fstream"
using namespace std;
int main(){
    int value= remove("C:\\Users\\H.P\\Desktop\\aditya.txt");
    if (value==0){
        cout<<"File is deleted ";
    }else{
        cout<<"File not dleted ";
    }
    return 0;
}
```


### Storage Class

- It tell us about the scope and lifetime of the variable
- syntax → storage_class datatype variable_name;
- There are five types of storage class :
1. Auto / local variable → these are local variable
1. The **`auto`** storage class is used for automatic storage duration. The variable **`localVarAuto`** is created and destroyed automatically within its scope.
2. NOTE → The **`auto`** keyword in this context does not refer to type inference, which is used in C++11 onwards. The **`auto`** keyword here means automatic storage duration.
2. Static - The **`static`** storage class is used for static storage duration. The variable **`localVarStatic`** retains its value between function calls.
3. Extern → these are global variable → we don’t initialize an extern variable
- In this we can change the value of global variable but if we don’t use extern then the value of global variable can’t be change.
- The **`extern`** keyword is used to declare a global variable (**`globalVar`**) with external linkage, which means it can be accessed across multiple source files.

```cpp
int a=10; //let  a be a global variable
//then to to use it in extern why? kay pata bhot sari files ho c++m ki jaha same
//variable use karna ho to we use extern
extern int a;
```

4. Register → these are same like local variable just they are faster than local variable → ye store hi register memory me hota he that is why it is faster.
1. The **`register`** storage class is used for register storage duration. It suggests the compiler to store the variable in a register for faster access.

```cpp
register int a=10;
```

5. Mutable → whose values you can change → used on class variable
- Scope are of two types → local and global .

 */