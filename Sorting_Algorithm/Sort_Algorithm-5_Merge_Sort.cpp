/*

-Merge Sort Algorithm - Recursive Sort Algorithm --> Divide and Conquer Algorithm
-Quite the the code it is -> DEFINETELY NEED REVESION!!


#include<iostream> 
using namespace std;

// Function to merge two sorted arrays into one sorted array
void merge(int arr[], int l, int mid, int r) {
    int a = mid - l + 1;  // Calculate the size of the first subarray
    int b = r - mid;      // Calculate the size of the second subarray
    int arr1[a];          // Create a temporary array to hold the first subarray
    int arr2[b];          // Create a temporary array to hold the second subarray

    // Fill the temporary arrays with elements from the main array
    for (int i = 0; i < a; i++) {
        arr1[i] = arr[l + i];
    }
    for (int i = 0; i < b; i++) {
        arr2[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;

    // Merge the two subarrays back into the main array in sorted order
    while (i < a && j < b) {
        if (arr1[i] < arr2[j]) {
            arr[k++] = arr1[i++];
        } else {
            arr[k++] = arr2[j++];
        }
    }

    // Copy any remaining elements from the first subarray
    while (i < a) {
        arr[k++] = arr1[i++];
    }

    // Copy any remaining elements from the second subarray
    while (j < b) {
        arr[k++] = arr2[j++];
    }
}

// Function to perform Merge Sort
void mergeSort(int arr[], int l, int r) {
    // Base case: If there's only one element or no elements, it's already sorted
    if (l >= r) {
        return;  // No need to sort
    }

    int mid = (l + r) / 2;  // Calculate the middle index

    // Recursively sort the left and right halves of the subarray
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    // Merge the sorted halves
    merge(arr, l, mid, r);
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

    // Call the mergeSort function to sort the array
    mergeSort(arr, l, r);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}


**Explanation:**

- The provided code implements the Merge Sort algorithm to sort an array of integers. Let's break it down step by step:

- The `merge` function takes care of merging two sorted subarrays back into the main array.
  - It calculates the sizes of the two subarrays (`arr1` and `arr2`) based on the given indices `l`, `mid`, and `r`.
  - The elements from the main array are copied into the temporary subarrays `arr1` and `arr2`.
  - Then, a merge process compares elements from both subarrays and places them back into the main array in sorted order.
  - Any remaining elements in `arr1` or `arr2` are copied back to the main array.

- The `mergeSort` function is the core of the Merge Sort algorithm.
  - It first checks for the base case: If the subarray contains one element or is empty, it's already sorted, so no action is needed.
  - The middle index (`mid`) is calculated to split the array into two halves.
  - Recursively, the function sorts the left half and the right half of the array using `mergeSort`.
  - Finally, the `merge` function is called to merge the sorted halves back together.

- The `main` function gets user input for the array size and elements, then sorts the array using `mergeSort` and outputs the sorted array.



Output:-
Ente the size of array : 8
Enter the array : 9 2 4 5 1 3 7 6
Sorted array is : 1 2 3 4 5 6 7 9 

-Time Complexity -> O(nlogn)
-Space Complexity -> O(n)

-Merge Sort is a Stable Sort Algorithm

-Application of Merge Sort:-
    -Large Datasets
    -Linked Lists
-Drawbacks :-
    -Slower for smaller tasks
    -O(n) extra space
    -goes through whole process even if array is sorted

-Master's theorem :- The Master Theorem is a technique for analyzing the time complexity of divide-and-conquer algorithms. It provides 
a way to determine the time complexity of algorithms that can be divided into subproblems of equal size, and it's often used when 

analyzing recursive algorithms like those used in divide-and-conquer strategies.

Master Theorem Explanation for Recurrence Relation:

Let's apply the Master Theorem to the recurrence relation:
                    T(n) = aT(n/b) + Θ(n^k log^p n)

Step 1: Identify the parameters:
- 'a' is the number of subproblems.
- 'b' is the factor by which the problem size is reduced.
- 'f(n) = Θ(n^k log^p n)' represents the time complexity outside the recursive calls.

Step 2: Calculate the values of 'a', 'b', 'k', and 'p':
- 'a' is the coefficient in front of the recursive term, which is 'a = a'.
- 'b' is the factor by which the problem size is reduced, which is 'b = b'.
- 'k' is the exponent of the polynomial term, which is 'k = k'.
- 'p' is the exponent of the logarithmic term, which is 'p = p'.

Step 3: Calculate 'log_b(a)':    //log_b(a) -> log 'a' with base 'b' 
- 'log_b(a)' represents the exponent in the recurrence relation. In this case, 'log_b(a)' is equal to 'log_b(a)'.

Step 4: Compare 'log_b(a)' with 'k':
- If 'log_b(a) > k', then the time complexity is 'T(n) = Θ(n * log_b(a))'.
- If 'log_b(a) = k', there are three sub-cases:
  - If 'p > -1', then the time complexity is 'T(n) = Θ(n^k log_(p+1) n)'.
  - If 'p = -1', then the time complexity is 'T(n) = Θ(n^k log(log(n)))'.
  - If 'p < -1', then the time complexity is 'T(n) = Θ(n^k)'.
- If 'log_b(a) < k', there are three sub-cases:
  - If 'p >= 0', then the time complexity is 'T(n) = Θ(n^k log_p(n))'.
  - If 'p < 0' , then the time complexity is 'T(n) = Θ(n^k)'.


In your specific recurrence, you have 'Θ(n^k log^p n)' outside the recursive calls. To apply the Master Theorem, compare 'log_b(a)' 
with 'k':

- If 'log_b(a) < k', which means the polynomial term '(n^k)' dominates the logarithmic term, then the time complexity is 'T(n) = Θ(n^k)'.

- If 'log_b(a) = k', which means both the polynomial and logarithmic terms have similar growth rates, then the time complexity is 
'T(n) = Θ(n^k log^(p+1) n)'.

- If 'log_b(a) > k', which means the logarithmic term dominates the polynomial term, then the time complexity is 'T(n) = Θ(f(n))', 
where 'f(n)' is the given 'Θ(n^k log^p n)'.

So, based on the comparison between 'log_b(a)' and 'k', you can determine the time complexity of the recurrence relation as one of the 
three cases mentioned above.
*/







