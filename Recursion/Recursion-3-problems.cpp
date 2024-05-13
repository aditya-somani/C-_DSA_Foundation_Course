/*
In this we are gonna solve question on strings and arrays using recursion

-Given an array , print all elements of arrays in new line recursively 
-We will assume that we can print all the remaining numbers but at once we will print the current element
-f(arr,idx,n) = print(arr[idx]) -> assuming it runs for f(arr,idx+1,n)

#include<iostream>
using namespace std;
void f(int *arr , int idx , int n){
    //base case
    if(idx==n) return;
    //self work
    cout<<arr[idx]<<"\n";
    //assumption
    f(arr,idx+1,n);

}
int main(){
    int n,idx;
    cout<<"Enter the size of array : ";
    cin>>n;
    idx=0;
    cout<<"Enter the array : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Array is : "<<endl;
    f(arr,idx,n);
    return 0;
}
Output:-
Enter the size of array : 5
Enter the array : 1 2 3 4 5
Array is :
1
2
3
4
5

-Print the max. value of the given array 

#include<iostream>
using namespace std;
int f(int *arr , int idx , int n){
    //base case
    if(idx==n-1) return arr[idx];
    //self work
    return max(arr[idx],f(arr,idx+1,n));    
}
int main(){
    int n,idx;
    cout<<"Enter the size of array : ";
    cin>>n;
    idx=0;
    cout<<"Enter the array : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Max. value of Array is : "<<f(arr,idx,n);
    return 0;
}
Output:-
Enter the size of array : 5
Enter the array : -100 11 0 55 -90
Max. value of Array is : 55

-Find the sum of array using recursion
-base case -> idx==n-1 then return that last element i.e. return arr[idx]
-return arr[idx] + f(arr,idx+1,n) ->self-work

#include<iostream>
using namespace std;
int f(int *arr , int idx , int n){
    //base case
    if(idx == n-1) return arr[idx];
    //self work
    return arr[idx] + f(arr,idx+1,n);
}
int main(){
    int n,idx;
    cout<<"Enter the size of array : ";
    cin>>n;
    idx=0;
    cout<<"Enter the array : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Sum of value Array is : "<<f(arr,idx,n);
    
    return 0;
}

Output:-
Enter the size of array : 5
Enter the array : 0 0 -11 10 11
Sum of value Array is : 10

*/