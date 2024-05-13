/*
-PLEASE DO REVISION OF IT ONCE!!

-Quick Sort Algorithm - Divide and Conquer Algorithm

-Also an OP Algo. so will definetly need REVISION!!

-> Divide the problems into subproblems -> solve those subproblems -> then merge those subproblems

In this we take a pivot element and put it at correct position and then around it we divide our array into two parts and then recursively
solve the parts and then after solving them merge them. 


#include<iostream>
using namespace std;

// Partition function that helps in rearranging elements
int partition(int arr[], int first, int last) {
    int pivot = arr[last];  // Choose the last element as the pivot
    int j = first - 1;  // Initialize the index of the smaller element

    // Loop through the array elements within the specified range
    for (int i = first; i <= last - 1; i++) {
        if (arr[i] < pivot) {
            j++;
            swap(arr[i], arr[j]);  // Swap current element with the smaller element
        }
    }

    swap(arr[j + 1], arr[last]);  // Swap the pivot element to its correct position
    return j + 1;  // Return the index of the pivot element
}

// Quicksort function
void quickSort(int arr[], int first, int last) {
    // Base case: If there are one or zero elements in the array, no need to sort
    if (first >= last) {
        return;  // Already sorted or empty
    }

    int pi = partition(arr, first, last);  // Partition the array
    quickSort(arr, first, pi - 1);  // Recursively sort elements before the pivot
    quickSort(arr, pi + 1, last);   // Recursively sort elements after the pivot
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0, r = n - 1;
    quickSort(arr, l, r);  // Call quickSort function to sort the array

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

**Explanation:**

- The `partition` function:
  - Selects the last element as the pivot.
  - Initializes an index `j` to track the position of the smaller element.
  - Iterates through the elements in the specified range (`first` to `last - 1`).
  - If an element is smaller than the pivot, it's swapped with the element at index `j`.
  - After the loop, the pivot is swapped to its correct position (after elements smaller than the pivot).
  - The function returns the index of the pivot element.

- The `quickSort` function:
  - Serves as the recursive sorting engine.
  - Checks for the base case: If the range has one or zero elements, it's already sorted.
  - Calls the `partition` function to obtain the pivot index.
  - Recursively sorts the elements before and after the pivot index.

- In the `main` function:
  - Takes user input for the array size and elements.
  - Calls `quickSort` to sort the array.
  - Outputs the sorted array.

Output:-
Enter the size of the array: 6
Enter the array elements: 3 7 1 9 10 8
Sorted array is: 1 3 7 8 9 10 

-Time Complexity for best case -> O(nlogn) ->Solved using Master's Theorem 
-Time Complexity for worst case -> O(n^2)
-Space Complexity -> O(n)

-To save space we can use a approach called Randomised Pivot .
    int pivot = first + rand()%(last-first+1);

-Quick Sort is a Unstable Algorithm

-Application of Quick Sort :-
    -where memory is concern
    -inbuilt sorting algorithms
    -works better in smaller databases whereas merge sort works better for larger datatbase
*/


