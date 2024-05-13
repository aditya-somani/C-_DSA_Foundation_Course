/*
-Based on the concept of Heaps - If you don't know about Heaps first complete till Heaps and Trees and then start it afterwards

 i.e. if deleting element from minHeap -> we get min. element
 and if deleting element from maxHeap -> we get max. element

 -Time complexity -> O(nlogn) , logn -> heapify and n-> deleting the node

Steps:-
 1.Convert the array into heap data structure using heapify
 2.One by one delete the root node of the heap and replace it with the last node in the heap and then heapify the root
 of the root of the heap . Repeat this process till the size of the heap is greater than 1.


#include "iostream"
using namespace std;
int const n=1e3;

void heapify(int arr[],int n,int curr){

    while(2*curr<= n){
        int leftChild=2*curr;
        int rightChild=2*curr+1;
        int maxChild=leftChild;
        if (rightChild<=n && arr[rightChild]>arr[maxChild]){
            maxChild=rightChild;
        }
        if (arr[maxChild]<=arr[curr]){
            return;
        }
        swap(arr[maxChild],arr[curr]);
        curr= maxChild;
    }
}

void remove(int arr[],int &size){
    swap(arr[1],arr[size]);
    size--;
    heapify(arr,size,1);

}

void heapSort(int arr[],int n){
    //1.heapify the array
    for (int i = n/2; i > 0 ; --i) {
        heapify(arr,n,i);
    }
    //2.Keep deleting elements from maxHeap until size becomes zero
    while(n>0){
        remove(arr,n);
    }
    return;
}

int main(){
    int arr[n]={-1,60 ,10 ,80 ,50 ,5 ,20,70};
    int size = 7;
    heapSort(arr,size);
    cout<<"Sorted array using HeapSort is : ";
    for (int i = 1; i <= size; ++i) {
        cout<<arr[i]<<" ";
    }
    return 0;
}

Output:-
Sorted array using HeapSort is : 5 10 20 50 60 70 80

*/






