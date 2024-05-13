/*

-Template classes -> they allow us to pass data type as a parameter 

At the time running i.e. at user side we can decide the datatype we want to input in the class
and we don't have to write same code for different datatypes

#include<iostream>
using namespace std;
template<typename T>
class node{
    public:
    T val;
    node* next;

    node(T data){
        val=data;
        next=NULL;
    }
};
int main(){
    node<int>* node1=new node<int>(3);
    cout<<node1->val<<endl;

    node<char>* node2=new node<char>('a');
    cout<<node2->val<<endl;
    return 0;
}

-STL -> Standard template library

Set of template classes for implementing commonly used data structures and fuctions
ex-> vector , lists , set , map , queue , stack

- Three Major components :- 1.Containers  2.Iterators 3.Algorithms 

-1.Containers -> used to hold data of same datatype 
eg:- Vector - class that defines a dynamic array
    lists - class for doubly Linked List
    Map -  used to store unique key-value pairs
    set - used to store unique value

-2.Iterators -> used to iterate/transverse the container
             -> Pointer Like entities
vector<int> v={1,2,3,,4,5}
vector<int>::iterator itr;
itr.begin() //Output:- 1

-3.Algorithms -> Functions that are used to manipulate data in the containers
ex:- sort(),min(),max(); 


-List -> template class in STL for implementing doubly Linked List

--We were taught doubly linked list so that we can understand what is actually happening at the back-end;

-Declaration of Linked List:-

#include<list>
list<data_type> list_name;
list<int> rollno;
list<int> list1{1,2,3,4,5};
list<int> list2={5,6,7,8,9};

-Advantages of a list in c++ -> implementation becomes easy

-Iteration functions :-

list.begin() -> iterator of the first element
list.end() -> iterator for the position after the last element


#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> l1={1,2,3,4,5};
    auto itr=l1.begin();
    cout<<*itr<<endl;  //1
    auto bitr=l1.end();
    cout<<*bitr<<endl;  //5
    return 0;
}

-list.rbegin() - iterator for the first element in reverse iteration
-list.rend() - iterator for the position after last element in reverse iteration
-advance(itr,n) - advances the itr by n places

#include<iostream>
#include<list>
#include<iterator>
using namespace std;
int main(){
    list<int> l1={1,2,3,4,5};
    auto itr=l1.rbegin();
    cout<<*itr<<endl;  //5
    auto bitr=l1.rend();
    cout<<*bitr<<endl;  //5
    auto itr1 = l1.begin();
    advance(itr1,3);
    cout<<*itr1<<endl; //4
    return 0;
}

-Tanversal in a List

#include<iostream>
#include<list>
#include<iterator>
using namespace std;
int main(){
    list<int> l1={1,2,3,4,5};
    for(auto num: l1){
        cout<<num<<" "; //1 2 3 4 5 
    }
    
    //now using iterators
    for(auto itr= l1.begin();itr!=l1.end();itr++){
        cout<<*itr<<" ";  //1 2 3 4 5
    }cout<<endl;

    //reversal transversal
    for (auto i = l1.rbegin(); i!=l1.rend(); i++)
    {
        cout<<*i<<" ";  //5 4 3 2 1
    }cout<<endl;
    

    return 0;
}

-Inserting elements in a list

-list.insert(itr,value) -> insert value before the position of the itr
-list.insert(itr,count,value) -> insert value count number of times before itr
-list.insert(itr,str_itr,end_itr) -> insert values from str_itr....end_str before itr


#include<iostream>
#include<list>
#include<iterator>
using namespace std;
int main(){
    list<int> l1={1,2,3,4,5};
    auto itr=l1.begin();
    for (auto i = l1.begin(); i!=l1.end(); i++)
    {
        cout<<*i<<" ";  //1 2 3 4 5
    }cout<<endl;

    advance(itr,2);
    l1.insert(itr,5);
    for (auto i = l1.begin(); i!=l1.end(); i++)
    {
        cout<<*i<<" ";  //1 2 5 3 4 5
    }cout<<endl;
    
    l1.insert(itr,3,4);
    for (auto i = l1.begin(); i!=l1.end(); i++)
    {
        cout<<*i<<" ";  //1 2 5 4 4 4 3 4 5
    }cout<<endl;

    auto l=l1.begin();
    auto r=l1.begin();
    advance(r,3);
    l1.insert(itr,l,r);
    for (auto i = l1.begin(); i!=l1.end(); i++)
    {
        cout<<*i<<" ";  //1 2 5 4 4 4 1 2 5 3 4 5
    }cout<<endl;
    return 0;
}

-Deleting elements from a list 

list.erase(itr) - delete  the element pointing to the itr
list.erase(str_itr,end_itr) - delete elements from [start itr to end itr)


#include<iostream>
#include<list>
#include<iterator>
using namespace std;
int main(){
    list<int> l{1,2,3,4,5};
    auto itr=l.begin();
    l.erase(itr);
    for (auto i = l.begin(); i !=l.end(); i++)
    {
        cout<<*i<<" ";  //2 3 4 5
    }cout<<endl;

    auto nitr=l.begin(); // because after using erase our itr becomes invalid or either update  it 
    // like itr= l.erase(itr);
    l.insert(nitr,4,5);
    advance(nitr,2);
    auto s_itr=l.begin();
    l.erase(s_itr,nitr);
    for (auto i = l.begin(); i !=l.end(); i++)
    {
        cout<<*i<<" ";  //4 5
    }cout<<endl;
    return 0;

}

-Other functions in list container :-

push_front(val) - insert val in the front of the list
pop_front() - removes val from front of list
push_back(val) - insert val in the back of the list
pop_back() - removes val from the back of the list

REST FUNCTIONS ARE AVAILABLE ON THE SITE 'C++.COM' , SO GO AND CHECK IT OUT!!


*/