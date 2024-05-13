/*
-Yep , quite easy jsut give one reading and it would be good as over!

Sorting -> Order of elements -> Increasing or Decreasing Order

-Repeatedly swap two adjacent elements if they are in wrong order


#include<iostream>
#include<vector>
using namespace std;

// Function to perform Bubble Sort on a vector of integers
void bubbleSort(vector<int> &v , int n) {
    // Iterate through the entire array
    for (int i = 0; i < n-1; i++) {
        // Iterate through the unsorted part of the array
        for (int j = 0; j < n-1-i; j++) {
            // Compare adjacent elements and swap if they are out of order
            if (v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
            }
        }
    }

    // Output the sorted array
    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;
    vector<int> v(n);

    cout << "Enter the vector elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Call the bubbleSort function to sort the vector
    bubbleSort(v, n);

    return 0;
}

Output:-
Enter the size of vector : 5
Enter the vector : 10 -20 50 -100 0
Sorted array is : -100 -20 0 10 50 

**Explanation:**

1. **bubbleSort Function (Lines 7-20):**
   - The `bubbleSort` function performs the Bubble Sort algorithm on a vector of integers.
   - It consists of two nested loops: the outer loop iterates through the entire array, and the inner 
   loop iterates through the unsorted part of the array.
   - Within the inner loop, adjacent elements are compared, and if they are out of order 
   (the current element is greater than the next element), they are swapped.
   - This process is repeated until the entire array is sorted.

2. **Main Function (Lines 22-42):**
   - The `main` function interacts with the user and performs the sorting.
   - It takes user input for the size of the vector and the vector elements.
   - It calls the `bubbleSort` function to sort the vector.
   - Finally, it prints the sorted vector to the console.

Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent 
elements, and swaps them if they are in the wrong order. It continues these steps until no more swaps 
are needed, indicating that the list is sorted. While it's not the most efficient sorting algorithm for 
large datasets, it serves as a good introductory example of a sorting algorithm.


// **Worst Case Scenario:** 
// The worst-case scenario for Bubble Sort occurs when the input array is in Descending Order.

// - In this worst-case scenario, Bubble Sort performs a maximum of (n-1) + (n-2) + ... + 1 swaps.
//   - **Explanation:** This sum represents the total number of swaps required to arrange the elements 
in ascending order.
//   - The sum is calculated by adding up the numbers from (n-1) down to 1.
//   - **Explanation:** This summation follows the formula for the sum of the first 'n-1' natural numbers:
n(n-1)/2.

// ⏰ Therefore, the Worst Case Time Complexity of Bubble Sort is expressed as O(n(n-1)/2), which 
simplifies to O(n^2).
//   - **Explanation:** This quadratic time complexity illustrates Bubble Sort's inefficiency, 
particularly for large datasets.

// 🌌 The Space Complexity of Bubble Sort is O(n) because it requires additional memory to store the 
input array.
//   - **Explanation:** This space complexity remains constant and does not vary based on the initial 
order or size of the input data.

// **Notable Insight:**
// - Bubble Sort exhibits the same time complexity, O(n^2), in both best and worst cases.
//   - **Explanation:** This characteristic makes it a consistent but less efficient sorting algorithm 
for a wide range of input scenarios.



-To optimise Bubble Sort in case of nearly sorted array

#include<iostream>
#include<vector>
using namespace std;

// Function to perform Bubble Sort on a vector of integers
void bubbleSort(vector<int> &v , int n) {
    bool flag = false;  // A flag to optimize the algorithm
    for (int i = 0; i < n-1; i++) {
        flag = false;  // Reset the flag for each pass
        for (int j = 0; j < n-1-i; j++) {
            // Compare adjacent elements and swap if they are out of order
            if (v[j] > v[j+1]) {
                flag = true;  // Set the flag to true if a swap is performed
                swap(v[j], v[j+1]);  // Swap the elements
            }
        }
        // If no swaps were performed during this pass, the array is already sorted
        if (!flag) {
            break;
        }
    }

    // Output the sorted array
    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }  
}

int main() {
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;
    vector<int> v(n);

    cout << "Enter the vector elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Call the bubbleSort function to sort the vector
    bubbleSort(v, n);

    return 0;
}


**Explanation:**

1. **bubbleSort Function (Lines 7-26):**
   - The `bubbleSort` function performs Bubble Sort on a vector of integers.
   - It introduces a boolean flag (`flag`) to optimize the algorithm. The flag is initially set to `false`.
   - It consists of two nested loops: the outer loop iterates through the entire array, and the inner loop 
   iterates through the unsorted part of the array.
   - Within the inner loop, adjacent elements are compared, and if they are out of order 
   (the current element is greater than the next element), they are swapped. The `flag` is set to `true` 
   if a swap is performed.
   - After each inner loop (pass), the function checks if any swaps were performed during that pass. 
   If no swaps were performed (i.e., `flag` remains `false`), it means the array is already sorted, and 
   the sorting process terminates early.

2. **Main Function (Lines 28-50):**
   - The `main` function interacts with the user and performs the sorting.
   - It takes user input for the size of the vector and the vector elements.
   - It calls the `bubbleSort` function to sort the vector, which may terminate early if the array is 
   already sorted.
   - Finally, it prints the sorted vector to the console.

This optimized version of Bubble Sort improves efficiency by avoiding unnecessary passes through 
the array when it's already sorted. It is still a simple sorting algorithm with a time complexity of 
O(n^2) in the worst case but performs better when the array is partially sorted or nearly sorted.

-Stable sort -> order of same element does not change after sorting
-Unstable sort -> order of same element changes after sorting 

->Bubble Sort -> is a Stable Sort

*/

