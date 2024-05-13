/*
So in this question we learned about 2 pointer based questions , make sure to revise and dry run by yourself
increase you logic prowness and keep learning!

->Sort an array only consisting of zeros and ones!
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int a;
    cout<<"Enter the size of array : ";
    cin>>a;
    cout<<"Enter the vector : ";
    vector <int> v(a);
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    
    int c=0,b=0;
    for (int i = 0; i < a; i++)
    {
        if (v[i]==0)
        {
            c++; 
        } 
    }
    cout<<"Sorted vector is : ";
    for (int i = 0; i < c; i++)
    {
        cout<<"0 ";
    }
    for (int i = 0; i < a-c; i++)
    {
        cout<<"1 ";
    }
    return 0;   
}
Output:-
Enter the size of array : 7
Enter the vector : 1 0 1 1 1 0 0
Sorted vector is : 0 0 0 1 1 1 1 
->Another way!
#include<iostream>
#include<vector>
using namespace std;
void sep(vector <int>& v ,int size){
    int znum=0;
    for (int i = 0; i < size; i++)
    {
        if (v[i]==0)
        {
            znum++;
        }   
    }
    for (int i = 0; i < size; i++)
    {
        if (i<znum)
        {
            v[i]=0;
        }
        else{
            v[i]=1;
        }  
    }   
}
int main(){
    int a;
    cout<<"Enter the size of array : ";
    cin>>a;
    cout<<"Enter the vector : ";
    vector <int> v(a);
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    cout<<"Sorted vector is : ";
    sep(v,a);
    for (int i = 0; i < a; i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
Output:-
Enter the size of array : 5
Enter the vector : 1 0 1 1 0  
Sorted vector is : 0 0 1 1 1 

->Another way! This time we are transversing array only one time!
#include<iostream>
#include<vector>
using namespace std;
void sep(vector <int>& v){
    int leftp=0;
    int rightp= v.size()-1;
    while (leftp<rightp)
    {
        if (v[leftp]==1 && v[rightp]==0)
        {
            v[leftp++]=0;
            v[rightp--]=1;
        }
        if (v[leftp]==0)
        {
            leftp++;
        }
        if (v[rightp]==1)
        {
            rightp--;
        }    
    }
    return;
    
}

int main(){
    int a;
    cout<<"Enter the size of array : ";
    cin>>a;
    cout<<"Enter the vector : ";
    vector <int> ve(a);
    for (int i = 0; i < a; i++)
    {
        cin>>ve[i];
    }
    cout<<"Sorted vector is : ";
    sep(ve);
    for (int i = 0; i < a; i++)
    {
        cout<<ve[i]<<" ";
    }
    return 0;
}
Output:-
Enter the size of array : 5
Enter the vector : 1 0 0 0 1
Sorted vector is : 0 0 0 1 1 
#include<iostream>
#include<vector>
using namespace std;
void sep(vector <int>& v , int size){
    for (int i = 0; i < size; i++)
    {
        if (v[i]%2==0)
        {
            v.insert(v.begin(),v[i]);
            v.erase(v.begin()+i+1);
            i--;
        }
        else
        {
            v.insert(v.end(),v[i]);
            v.erase(v.begin()+i);
            i--;
        }  
    } 
    return;
}

int main(){
    int a;
    cout<<"Enter the size of array : ";
    cin>>a;
    cout<<"Enter the vector : ";
    vector <int> ve(a);
    for (int i = 0; i < a; i++)
    {
        cin>>ve[i];
    }
    cout<<"Sorted vector is : ";
    sep(ve,a);
    for (int i = 0; i < a; i++)
    {
        cout<<ve[i]<<" ";
    }
    return 0;
}
-> To move all even integers to left and all odd to right (My way!)
#include <iostream>
#include <vector>
using namespace std;

void sep(vector<int>& v, int size) {
    for (int i = 0; i < size; i++) {
        if (v[i] % 2 == 0) {
            v.insert(v.begin(), v[i]);
            v.erase(v.begin() + i + 1);
        }
        if (v[i] % 2 != 0) {
            v.insert(v.begin() + i, v[i]);
            v.erase(v.begin() + i + 1);
        }
    }
}

int main() {
    int a;
    cout << "Enter the size of the array: ";
    cin >> a;
    cout << "Enter the vector: ";
    vector<int> ve(a);
    for (int i = 0; i < a; i++) {
        cin >> ve[i];
    }
    cout << "Sorted vector is: ";
    sep(ve, a);
    for (int i = 0; i < a; i++) {
        cout << ve[i] << " ";
    }
    return 0;
}
Output:-
Enter the size of the array: 5
Enter the vector: 1 2 3 4 5
Sorted vector is: 4 2 1 3 5 

-> To move all even integers to left and all odd to right (Mam's way!)
#include <iostream>
#include <vector>
using namespace std;
void sep(vector <int>& v , int size){
    int leftp = 0;
    int rightp= size-1;
    int b=0;
    while (leftp<rightp)
    {
        if (v[leftp]%2!=0 and v[rightp]%2==0)
        {
           swap(v[leftp],v[rightp]);
           leftp++;
           rightp--;
            
        }
        else{
            if (v[rightp]%2!=0 )
            {
                rightp--;
            }
            if (v[leftp]%2==0)
            {
                leftp++;
                
            } 
        } 
    }
    return;
}
int main() {
    int a;
    cout << "Enter the size of the array: ";
    cin >> a;
    cout << "Enter the vector: ";
    vector<int> ve(a);
    for (int i = 0; i < a; i++) {
        cin >> ve[i];
    }
    cout << "Sorted vector is: ";
    sep(ve, a);
    for (int i = 0; i < a; i++) {
        cout << ve[i] << " ";
    }
    return 0;
}
Output:-
Enter the size of the array: 5
Enter the vector: 1 2 3 4 5
Sorted vector is: 4 2 3 1 5 

-> Write a prgramm to give square of a sorted function in decending order! 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int a;
    cout << "Enter the size of the array: ";
    cin >> a;
    cout << "Enter the vector: ";
    vector<int> v(a);
    for (int i = 0; i < a; i++) {
        cin >> v[i];
    }
    cout << "Sorted vector is: ";
    int i=0,j=a-1;
    vector <int> sqr(a);
    for (int i = 0; i < a; i++)
    {
        sqr[i]=v[i]*v[i];
    }
    sort(sqr.begin(),sqr.end());
    for (int i = 0; i < a; i++)
    {
        cout<<sqr[i]<<" ";
    }
    return 0;
}
Output:-
Enter the size of the array: 7
Enter the vector: -22 -10 -3 0 1 5 9
Sorted vector is: 484 100 81 25 9 1 0 
->Now let's try mam's logic
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void sqr(vector <int> &v , int size){
    vector <int> sqrv;
    int l=0;
    int r=size-1;
    while(l<=r)
    {
        if (abs(v[l])<abs(v[r]))
        {
            sqrv.push_back(v[r]*v[r]);
            r--;
        }
        else{
            sqrv.push_back(v[l]*v[l]);
            l++;
        }  
    }
    reverse(sqrv.begin(),sqrv.end());
    for (int i = 0; i < size; i++)
    {
        cout<<sqrv[i]<<" ";
    }   
}
int main(){
    int a;
    cout << "Enter the size of the array: ";
    cin >> a;
    cout << "Enter the vector: ";
    vector<int> v(a);
    for (int i = 0; i < a; i++) {
        cin >> v[i];
    }
    cout<<"Sorted vector : ";
    sqr(v,a);
    return 0; 
}
Output:-
Enter the size of the array: 5
Enter the vector: -22 -10 1 2 9
Sorted vector : 1 4 81 100 484 */















