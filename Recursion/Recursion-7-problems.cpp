/*

-All the questions were really interesting and the last one really looked hard but was quite easy when
it comes to solving , so just do revision once!

-Print if x exists in the array or not.

-Bye ME!


#include<iostream>
using namespace std;
bool f(int *arr,int n,int x, int z){
    //base-case
    if (arr[n]==x)
    {
        return true;
    }
    if (n<z)
    {
        return f(arr,n+1,x,z);
    }
    return false;
}
int main(){
    int n,x;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Ente the array : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the number whose presence you eant to check : ";
    cin>>x;
    cout<<"Presence of number is (1-True,0-False) : "<<f(arr,0,x,n);
    return 0;
}

Output:-
Enter the size of array : 5
Ente the array : 1 2 3 4 5
Enter the number whose presence you eant to check : 1
Presence of number is (1-True,0-False) : 1

-By sir!

#include<iostream>
using namespace std;
bool f(int *arr , int n , int i , int x){
    //base-case
    if (i==n)
    {
        // array is exhausted 
        return false;
    }
    return (arr[i]==x) || f(arr,n,i+1,x);
}
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int x;
    cout<<"Enter the number you want to check : ";
    cin>>x;
    if(f(arr,n,0,x)==true){
        cout<<"Yes , the number is present ";
    }
    else{
        cout<<"No , the number is not present ";
    }
    return 0;
}

Output:-
Enter the size of array : 5
Enter the array : 1 2 3 4 5
Enter the number you want to check : 3
Yes , the number is present 

-Print the sum of all subsets in an array. -OP! question

#include<iostream>
#include<vector>
using namespace std;
void f(int *arr, int size , int index ,int sum , vector <int> &result){
    //base-case
    if(index==size){
        result.push_back(sum);
        return;
    }
    f(arr,size,index+1,sum+arr[index],result); //pick the 'i'th element 
    f(arr,size,index+1,sum,result);  // does not pick the 'i'th element
}
int main(){
    int n,i=0;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector <int> result;
    f(arr,n,i,0,result);
    cout<<"The sum of subset is(in random order) : ";
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}

Output:-
Enter the size of array : 3
Enter the array : 3 2 5
The sum of subset is(in random order) : 10 5 8 3 7 2 5 0 

-The problem is to count all the possible paths on an m x n grid from top left
to bottom right (grid[m-l] [n-1]).

Having constraints that from each cell you can either move only to right or
down.
#include<iostream>
using namespace std;
int f(int i,int j,int m,int n){
    //base-case
    if(i==(m-1) && j==(n-1)) return 1;
    if(i>=m || j>=n) return 0;
    return f(i,j+1,m,n)+f(i+1,j,m,n);
}
int main(){
    int m,n,s,e;
    cout<<"Enter the starting point : ";
    cin>>s>>e;
    cout<<"Enter the grid dimension : ";
    cin>>m>>n;
    cout<<"Sum of All possible paths are : "<<f(s,e,m,n);
    return 0;
    
}

Output:-
Enter the starting point : 0 0 
Enter the grid dimension : 3 3
Sum of All possible paths are : 6

*/

