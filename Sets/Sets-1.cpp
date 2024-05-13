/*

-In this lecture we learned about sets and its types , really amazing lecture it was as i was really amazed by how usefull
they are to store unique values in ordered manner , we also did a bit of questions on sets which were quite easy but still 
used a little bit of mind!

-So, now we are taking a little bit break and doing the revision of everything that we did/learned till now!

-So , have a good day and happy REVISION!!!!



'-Number.*' -> represents the main topics 
'-' -> represents the sybtopics or notes of the main topic 
'-Number.' -> represent the questions 

-1.*Sets:- It is an STL containers used to store unique values
      - It stores values in order manner/state i.e. either increasing or decreasing
      - No indexing , here elements are identified by their own values
      - Once value is inserted in a set , it cannot be modified

-We use sets whenever we have to store some 'unique' values

-Advantages of sets :-
    - unique values
    - ordered 
    - dynamic size -> no overflowing errors
    - faster , here all insertion , deletion and search(Binary Search) are of O(logN)

-Disadvantages :-
    - can't access elements using indexes 
    - uses more memory than array
    - not suitable for large datasets as insertion and deletion takes O(logN)

-Declaration :- set<datatype> set_name;

#include<set>
set<int> set={1,2,3,4,5}; -> by default it will store values in increasing order

set<datatype , greater<datatype>> set_name; -> for decreasing order

-Insertion in sets:- set_name.insert(value);  -Time complexity -> O(logN)
    -This function returns a iterator(iterate through STL container) to the inserted value


#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> set1;
    set1.insert(3);set1.insert(2);set1.insert(1);
    cout<<set1.size()<<endl;  //3
    set1.insert(3);
    cout<<set1.size();  //3
    return 0;
}

-For transversing through the sets :-

-set_name.begin() - returns iterator to the first element of the set 
-set_name.end() - iterator pointing to the position after the last element of set


#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> set1;
    set1.insert(3);set1.insert(2);set1.insert(1);
    set1.insert(3);
    set<int>::iterator itr;

    // for (itr = set1.begin(); itr!=set1.end(); itr++)
    // {
    //     cout<<*itr<<" ";  //1 2 3
    // }cout<<endl;

    for (auto value:set1)
    {
        cout<<value<<" ";  // 1 2 3
    }cout<<endl;
    
    
    return 0;
}

-Deleting elements from a set 

-set_name(value)
-set_name(psoition)
-set_name(start pos , end pos) - deletes elements formm start pos including it , till end pos , excluding end pos


#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> set1;
    set1.insert(3);set1.insert(2);set1.insert(1);
    set1.insert(4);

    // set1.erase(1);  // 2 3 4

    // auto itr = set1.begin();
    // advance(itr,2);
    // set1.erase(itr);  // 1 2 4

    // auto itr1 = set1.begin();
    // itr1++;
    // auto itr2 = set1.begin();
    // advance(itr2,3);
    // set1.erase(itr1,itr2);  // 1 4

    for(auto values:set1){
        cout<<values<<" ";  
    }cout<<endl;
}

-Member functions of a set container 

-max_size() - max no. of elements set can hold
-empty() - return true if our set is empty else false
-clear() - reoves all elements from set
-find() - return position of elements if present , else returns end iterator
-count() - return the number of occurenece of an element -> 1 for all else 0 if not present
-lower_bound() - returns element if present , else return the just greater value
-upper_bound() - always returns the next greater value
-rbegin() -  returns iterator to first element of set in 'reverse order' 
-rend() - returns iterator to position after last element in 'reverse order'

-Now let's do QUESTIONS!! 

-1.Cherry's birthday is coming this month! She wants to plan a Birthday party and is preparing an invite list with her friend Aashi, 
she asks Aashi to tell her names to add to the list.
Aashi is a random guy and keeps coming up with names of people randomly to add to the invite list, 
even if the name is already on the list! Cherry hates redundancy and
hence, enlists the names only once. Find the final invite-list, that contain names without any repetition.

-Take input the number of names you want to input and in output the names should be arranged lexographically!


#include<iostream>
#include<set>
using namespace std;
int main(){
    set<string> invitelist;
    int n;
    cout<<"Enter the number of invities : ";
    cin>>n;
    cout<<"Enter their names : ";
    while (n--)
    {
        string name;
        cin>>name;
        invitelist.insert(name);
    }
    cout<<"Final invite list is : ";
    for(auto name:invitelist){
        cout<<name<<" ";
    }
    return 0;
}

Output:-
Enter the number of invities : 7
Enter their names : aditya atul markam riya piyush aditya namo
Final invite list is : aditya atul markam namo piyush riya

-2.Given two vectors v1 and v2 . Find out the common elements between the two and return the sum of them!


#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the size of first vector : ";
    cin>>n;
    vector<int> v1(n);
    cout<<"Enter the elements of first vector : ";
    for (int i = 0; i < n; i++)
    {
        cin>>v1[i];
    }
    cout<<"Enter the size of second vector : ";
    cin>>m;
    vector<int> v2(n);
    cout<<"Enter the elements of second vector : ";
    for (int i = 0; i < m; i++)
    {
        cin>>v2[i];
    }

    int ans_sum=0;

    set<int> s1;
    for(auto ele:v1){
        s1.insert(ele);
    }
    for (auto ele:v2)
    {
        if (s1.find(ele)!=s1.end())
        {
            ans_sum+=ele;
        }
        
    }
    
    cout<<"Answer of sum of similar elements is : "<<ans_sum;
    return 0;
}

Output:-
Enter the size of first vector : 5
Enter the elements of first vector : 1 2 3 4 5
Enter the size of second vector : 3
Enter the elements of second vector : 5 2 0
Answer of sum of similar elements is : 7

-3.Check if the given strings contains all alphabets of english language


#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

bool checkAllAlphabets(string s){
    if (s.length()<26)
    {
        return false;
    }
    
    transform(s.begin(),s.end(),s.begin(),::tolower); //transform is used to change entire string and ::tolower is used to convert all elements to lower case

    set<char> alphabets;
    for(auto ch:s){
        alphabets.insert(ch);
    }
    return (alphabets.size()==26);
}

int main(){
    string input;
    cout<<"Enter the string : ";
    cin>>input;
    if (checkAllAlphabets(input))
    {
        cout<<"Yes , given number contains all letters of alphabets ";
    }
    else{
        cout<<"No , it does not contain all letters of alphabets ";
    }


    return 0;
}

Output:-
Enter the string : ABCdefghijklmnooooopqrsTUVVVVwxYz
Yes , given number contains all letters of alphabets 

Enter the string : ABCdefghijklnooooopqrsTUVVVVwxYz  
No , it does not contain all letters of alphabets

-2.*unordered_set - values are stored in unordered(random) fashion
               - unique values , values can't be modified inside set and 
               - values will be identifiedd by itself

-Here the time comlpexity of insertion , deletion and search are of O(1) on average; -> by using hashing
first make a hashing function(which reduces begger number to smaller ) then insert the value at that hashing index


#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> s1;
    s1.insert(3);s1.insert(3);s1.insert(2);s1.insert(1);s1.insert(4);s1.insert(100);s1.insert(50);
    for(auto val:s1){
        cout<<val<<" ";  // 50 100 4 1 2 3 
    }
    cout<<endl;

    return 0;
} 

-Member functions of unordered_set :-

-insert - element is inserted only if it is not present in the set
    -single element insertion -> TC(Time Complexity) is = O(1) in avergae cases
    and when size>=capacity -> TC = O(N) as we have to do rehashing and allot a bigger node
    -multiple elements -> TC = O(N) on average where 'n' is the nummber of elements being inserted
    and when size>= capacity i.e. worst case then TC = O(n*(N+1)) where N is the number of elements in the set

NOTE:- I AM NOT WRITING MORE NOTES FOR MEMEBER FUNTIONS IN UNDORED SETS AS THOSE PROVIDED BY CW ARE MORE THEN SUFFICIENT
SO, HERE IS  THE LINK GO CHECK OUT  THE TABLE FROM PAGE NUMBER 11

Link:- https://drive.google.com/file/d/13LRszP3vzVHJBgL88MkXdBbEJ0odxrDs/view?usp=sharing

-deletion , find and count -> all have same TC in avg case -> O(1) and in worst case O(N)
-load_factor() - size of unordered set/bucket_count -> TC = O(N) on avg and in worst case O(N^2)
-rehash(x) - sets the  no. of buckets to 'x' or more -> TC = O(N) on avg and in worst case O(N^2)

-3.*Mutiset - it can store duplicate values
         - values will be ordered
         - value will be identified by itself and it can't be modified


#include<iostream>
#include<set>
using namespace std;
int main(){
    multiset<int> ms;
    ms.insert(3);ms.insert(3);ms.insert(1);ms.insert(2);
    for(auto ele:ms){
        cout<<ele<<" ";  // 1 2 3 3
    }
    return 0;
}

-Member function of multiset:-

-insert() -> O(logN)
-erase(value) -> deletes all instances of that element -> o(logN)
              -> if you want to delete just one then pass the iterator and if in bulk then pass the range of iterator
-find() -> lowerbound of element search if found else end iterator -> O(logN)
-count() -> no. of occurences -> O(k+logN) where k is number of occureneces
-lower_bound() -> iterator pointing to first occurence of valie if present else will return the next greater value -> O(logN)
-upper_bound() -> position of next greater value -> O(logN)

-4.*unordered_multiset - allows duplicate values 
                       - values are not ordered 
                       - value will be identified by itself
                       - values cannot be modified



#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_multiset<int> um;
    um.insert(3);um.insert(1);um.insert(4);um.insert(3);um.insert(0);um.insert(5);um.insert(3);

    for (auto ele:um)
    {
        cout<<ele<<" "; //5 0 4 1 3 3 3 
    }
    return 0;
}

-insert() - single element insertion -> TC(Time Complexity) is = O(1) in avergae cases
            and when size>=capacity -> TC = O(N) as we have to do rehashing and allot a bigger node
          - multiple elements -> TC = O(N) on average where 'n' is the nummber of elements being inserted
            and when size>= capacity i.e. worst case then TC = O(n*(N+1)) where N is the number of elements in the set

-deletion(erase) , find -> both have same TC in avg case -> O(1) and in worst case O(N)
-count() - O(n) in avg case where n->no. of occurence
         - O(N) in worst case where N is the size of set
-All functions related to hasing will have TC -> TC = O(N) on avg and in worst case O(N^2)


-1. Given n integers (can be duplicates), print the second smallest integers if does not exist -1


#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of numbers : ";
    cin>>n;
    cout<<"Enter the numbers : ";
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    set<int> s;
    // for (int i = 0; i < n; i++)
    // {
    //     s.insert(v[i]);
    // }

    for(auto val:v){
        s.insert(val);
    }
    auto itr = s.begin();
    advance(itr,1);
    cout<<"Second smallest element in the vector is : "<<*itr<<endl;
    return 0;
    
}

Output:-
Enter the size of numbers : 7
Enter the numbers : 5 3 2 5 4 3 8
Second smallest element in the vector is : 3


-2.Given the number of questions as n, and marks for the correct answer as p and q marks for the incorrect answer. 
One can either attempt to solve the question in an examination and get either p marks if the answer is right, 
or q marks if the answer is wrong, or leave the question unattended and get 0 marks. 
The task is to find the count of all the different possible marks that one can score in the examination.



#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    int n,p,q;
    cout<<"number of questions : ";
    cin>>n;
    cout<<"marks for the correct answer : ";
    cin>>p;
    cout<<"marks for the incorrect answer : ";
    cin>>q;
    unordered_set<int> s;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int correct=i;
            int incorrect=j;
            int unattended=n-(i+j);

            if (unattended>=0)
            {
                int score=correct*p+incorrect*q;
                s.insert(score);
            }
            else{
                break;
            }
            
        }
        
    }
    cout<<"possible outcomes are : ";
    for(auto ele:s){
        cout<<ele<<" ";
    }cout<<endl;
    cout<<"Number of possible outcomes are : "<<s.size();
    return 0;
}

Output:-
number of questions : 2
marks for the correct answer : 1
marks for the incorrect answer : -1
possible outcomes are : 1 -2 2 -1 0 
Number of possible outcomes are : 5

-time complexity -> O(N^2); and space -> O(N);


*/