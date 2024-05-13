/*Vectors are dynamic array -> i.e. we can resize an array -> add or delete elements in array
->similarity with array is that it have contiguous memory allocation
->difference that in vector we can resize but array we can't
Sysntax:
#include<vector>
    vector <datatype> vector-name;
    vector<datatype> vector-name(size);

    ex- vector <int> v;

->To check size -> use vector-name.size() = will give length of that vector
-> To resize -> vector-name.resize(new size);
        ex- v.size() = 4
            v.resize(8);
            v.size() = 8

-> capacity -> capacity >= size -> v.capacity()
 it is chnageable i.e. it changes dynamically 
 -> capacity increases in 2 raise to power; -> this thing is complier dependend and vary from pc to pc
-> Capacity will only increase when the threshold of size is reached
+------+---------+
| Size | Capacity|
+------+---------+
|  0   |    0    |
+------+---------+
|  1   |    2    |
+------+---------+
|  3   |    4    |
+------+---------+
|  5   |    8    |  // that is jab size =4 hoga then also 
+------+---------+      capacity ki value 4 hi rahegi as 'c>=s'


Operators -> Here 'v' is my vector-name and remember here numbering starts from 0 like that of array;
1. v.pushback(elements) -> adds a element at end of vector
2. v.insert(position , element) -> position should be relative to that of first element
3. v.begin() -> first element
4. v.end() -> last element
5. v.pop_back() -> to delete the last element
6. v.erase(position) -> will delete the element at that position and position should be from start
7. v.clear() -> deletes all elements

Now code!-
-This is the code to take input and make vector of those input

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a;
    cout<<"Enter the size of vector : ";
    cin>>a;
    vector<int> v(a);    // make sure to not use [] in this and remeber the syntax
    //v = new int[a];  -> this line does not come in vector , though it comes in array
    cout<<"Enter "<<a<<" integer values : \n";
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    cout<<"Vector elements are: \n";
    for (int i = 0; i < a; i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
Now we are gonna perform opertions on vectors using opertors
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a;
    cout<<"Enter the size of vector :";
    cin>>a;
    cout<<"Enter the vector : ";
    vector<int> v(a);
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    cout<<" Size : "<<v.size()<<endl;
    cout<<" Capacity : "<<v.capacity()<<endl;

    v.push_back(5);
    cout<<" Size : "<<v.size()<<endl;
    cout<<" Capacity : "<<v.capacity()<<endl;

    v.resize(7);
    cout<<" Size : "<<v.size()<<endl;
    cout<<" Capacity : "<<v.capacity()<<endl;

    return 0;  
}
output is ->
Enter the size of vector :3
Enter the vector : 1 2 3
 Size : 3
 Capacity : 3
 Size : 4
 Capacity : 6
 Size : 7
 Capacity : 8
Now to test other operators 
#include<iostream>
#include<vector>
using namespace std;
vector<int> vec(vector <int>& v){
    
    vector <int> result;
    for (int i = 0; i < v.size(); i++)
    {
        result.push_back(v[i]);
    }
    return result;
}
int main(){
    int a;
    cout<<"Enter the size of vector : ";
    cin>>a;
    vector<int> v(a);
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    cout<<"Vector is : ";
    cout<<vec;
    cout<<"Operators : "<<endl;
    v.push_back(5);
    cout<<vec;
    return 0;
    
}
-> This is is code to join two different vectors
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a;
    cout<<"Enter the size of vector \n";
    cin>>a;
    vector <int> v(a);
    cout<<"Enter the vector : "<<endl;
    for(int i=0 ; i<v.size() ; i++){
        cin>>v[i];   
    }
    int g;
    cout<<"Enter the size of vector you want to add \n";
    cin>>g;
    vector <int> c(g);
    cout<<" Enter the vector you want to add : ";
    for(int i=0 ; i<c.size() ; i++){
        cin>>c[i];
        v.push_back(c[i]);
    }
    for (int i = 0; i < (a+g); i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
Now if you don't wanrt to define the size of the vector
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    cout<<"Enter vector ";
    for (int i = 0; i < 5; i++)
    {
        int element;
        cin>>element;
        
        v.push_back(element);
    }
    cout<<endl<<"Vector is : ";
    for (int i = 0; i < 5; i++)
    {
        cout<<v[i]<<" ";      //Vector is : 1 2 3 4 5
    }
    v.insert(v.begin()+2,6);   // insert repplace nahi add karta he , and it also work w.r.t indexing from 0
    cout<<endl<<"Vector is : ";
    for (int i = 0; i < 5; i++)
    {
        cout<<v[i]<<" ";        //Vector is : 1 2 6 3 4
    }
    v.erase(v.end()-2);      // erase uda deta he 
    cout<<endl<<"Vector is : ";
    for (int i = 0; i < 5; i++)
    {
        cout<<v[i]<<" ";       //Vector is : 1 2 6 3 5
    }
    return 0; 
}
->Write a program to print last occurenece of a number!
-> To do question directly you can start loop from v.size() i.e. a to 0

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a;
    cout<<"Enter the size of vector : ";
    cin>>a;
    vector <int > v(a);
    cout<<"Enter the vector : ";
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    cout<<"Enter the number whose position you want to find : ";
    int b;
    cin>>b;
    int occcur=-1;
    for (int i = 0; i < a; i++)
    {
        if (v[i]==b)
        {
            occcur=i;
        }
    }
    cout<<" Position of "<<b<<" is at index: "<<occcur;
    return 0;
}
Output:-
Enter the size of vector : 5
Enter the vector : 1 2 3 1 2
Enter the number whose position you want to find : 2
 Position of 2 is at index: 4

-> Now create a prgramm to count the number of occurenece of that number in the vector
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a;
    cout<<"Enter the size of vector : ";
    cin>>a;
    cout<<"Enter the vector : ";
    vector <int> v(a);
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    int b;
    cout<<"Enter the number whose output you want : ";
    cin>>b;
    int count=0;
    for (int i = 0; i < a; i++)
    {
        if (v[i]==b)
        {
            count++;
        }
        
    }
    cout<<"Number of time "<<b<<" has been repeated is "<<count;
    return 0;
    
}
output:-
Enter the size of vector : 5
Enter the vector : 1 2 3 1 1
Enter the number whose output you want : 1
Number of time 1 has been repeated is 3
-> To count number of elemenets strictly greater than 'x' 
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a;
    cout<<"Enter the size of vector : ";
    cin>>a;
    cout<<"Enter the vector : ";
    vector <int> v(a);
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    int b,c=0;
    cout<<"Enter the number who's greater than count you want to find : ";
    cin>>b;
    for (int i = 0; i < a; i++)
    {
        if (v[i]>b)
        {
            c++;
        }  
    }
    cout<<"Number greater than "<<b<<" is(count) "<<c;
    return 0;  
}
output:-
Enter the size of vector : 4
Enter the vector : -12 13 33 0
Enter the number who's greater than count you want to find : -13
Number greater than -13 is(count) 4
-> Check if the given vector is sorted(ascending) or not!
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a;
    cout<<"Enter the size of array : ";
    cin>>a;
    cout<<"Vector is : ";
    vector <int> v(a);
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    bool c=false;
    for (int i = 0; i < a-1; i++)
    {
        if (v[i]<=v[i+1])
        {
            c=true;
            continue;
        }
        else{
            c=false;
            break;
        }  
    }
    if (c==true)
    {
        cout<<"Yes the vector is sorted ";
    }
    else{
        cout<<" No the pattern is not sorted ";
    }
    return 0;
}
There is also an easy way to solve this question  by taking c=true intially, 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a;
    cout << "Enter the size of array: ";
    cin >> a;
    cout << "Vector is: ";
    vector<int> v(a);
    for (int i = 0; i < a; i++) {
        cin >> v[i];
    }
    bool c; // By default bool ki value is false
    for (int i = 0; i < a - 1; i++) {
        if (v[i] > v[i + 1]) {
            c = false;
            break;
        }
        c = true;
    }
    if (c) {
        cout << "Yes, the vector is sorted.";
    } else {
        cout << "No, the vector is not sorted.";
    }
    return 0;
}
-> To print differenece of sum of elements at even indices to sum of elements at odd indices
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a;
    cout << "Enter the size of array: ";
    cin >> a;
    cout << "Vector is: ";
    vector<int> v(a);
    for (int i = 0; i < a; i++) {
        cin >> v[i];
    }
    int b,c;
    int sumeven=0, sumodd=0;
    for (int i = 0; i < a; i++)
    {
        if (i%2==0) //Remember here numbering starts from 0 , so don't just start suming from taking zero indice as one
        {
            sumeven += v[i];
        }
        else if (i%2!=0)
        {
            sumodd += v[i];
        }
    }
    cout<<"Differnece of sum is : "<<sumeven-sumodd;
    return 0;  
}
Output :- 
Enter the size of array: 5
Vector is: -11 -12 55 13 22
Differnece of sum is : 65*/






























