/*
Really easy and interesting  

-Selection Sort Algorithm 

-Repeatedly find min. element in unsorted array & place it at the beginning 
-In 'i'th iteration we are selecting element for 'i'th position


#include<iostream>
#include<vector>
using namespace std;

// Function to perform Selection Sort on a vector of integers
void selectionSort(vector<int> &v, int n) {
    // Iterate through the entire array
    for (int i = 0; i < n - 1; i++) {
        // Assume the current element as the minimum
        int min_idx = i;
        
        // Iterate through the unsorted part of the array to find the minimum element
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        
        // Swap the minimum element with the current element (if different)
        if (min_idx != i) {
            swap(v[i], v[min_idx]);
        }
    }

    // Output the sorted vector
    cout << "Sorted vector is: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> v(n);

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Call the selectionSort function to sort the vector
    selectionSort(v, n);

    return 0;
}

Output:-
Enter the size of array : 5
Enter the array : 50 -10 90 20 0
Sorted vector is : -10 0 20 50 90

**Explanation:**

1. **selectionSort Function (Lines 7-21):**
   - The `selectionSort` function performs the Selection Sort algorithm on a vector of integers.
   - It iterates through the entire array, considering each element as the potential minimum.
   - Within the inner loop, it searches for the minimum element in the unsorted part of the array.
   - If a smaller element is found, it updates the `min_idx` to the index of the new minimum.
   - After the inner loop, if the minimum element's index is different from the current element's index 
   (`i`), it swaps them.
   
2. **Main Function (Lines 23-45):**
   - The `main` function interacts with the user and performs the sorting.
   - It takes user input for the size of the array and the array elements.
   - It calls the `selectionSort` function to sort the array.
   - Finally, it prints the sorted vector to the console.

Selection Sort is a simple comparison-based sorting algorithm that repeatedly selects the minimum 
element from the unsorted part of the array and places it at the beginning. It has a time complexity 
of O(n^2) in all cases, making it less efficient for large datasets compared to more advanced sorting 
algorithms.
 

// ⏰ **Time Complexity:**
// Selection Sort has a time complexity of O(n(n-1)/2), which simplifies to O(n^2).
// This is because, in the worst-case scenario, it performs approximately n^2/2 comparisons and swaps.
// Despite its simplicity, Selection Sort exhibits a quadratic time complexity, making it less efficient 
for large datasets.

// 🌌 **Space Complexity:**
// The space complexity of Selection Sort is O(n) since it requires additional memory to store the input 
array.
// However, this space complexity remains constant regardless of the size or order of the input data.

// 🔍 **Notable Insight:**
// One notable characteristic of Selection Sort is that its time complexity remains the same, O(n^2), 
in both the best and worst cases.
// This is because the algorithm always performs the same number of comparisons and swaps, regardless of 
the initial order of the elements.


-Selection sort is Unstable Sort Algorithm

-Applications of Selection Sort :-
    -Max. swaps is O(n)
    
Code for ->Repeatedly finding max. element and placing at end

#include<iostream>
#include<vector>
using namespace std;

// Function to perform Selection Sort in descending order on a vector of integers
void selectionSort(vector<int> &v, int n) {
    // Iterate through the entire array in reverse order
    for (int i = n - 1; i > 0; i--) {
        // Assume the current element as the maximum
        int max_idx = i;
        
        // Iterate through the unsorted part of the array to find the maximum element
        for (int j = i - 1; j >= 0; j--) {
            if (v[j] > v[max_idx]) {
                max_idx = j;
            }
        }
        
        // Swap the maximum element with the current element (if different)
        if (max_idx != i) {
            swap(v[i], v[max_idx]);
        }
    }

    // Output the sorted vector in ascending order
    cout << "Sorted vector is: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> v(n);

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Call the selectionSort function to sort the vector in descending order
    selectionSort(v, n);

    return 0;
}

Output:-
Enter the size of array : 5
Enter the array : 50 -10 90 20 0
Sorted vector is : -10 0 20 50 90 

**Explanation:**

1. **selectionSort Function (Lines 7-21):**
   - The `selectionSort` function performs Selection Sort in descending order on a vector of integers.
   - It iterates through the entire array in reverse order, considering each element as the potential 
   maximum.
   - Within the inner loop, it searches for the maximum element in the unsorted part of the array.
   - If a larger element is found, it updates the `max_idx` to the index of the new maximum.
   - After the inner loop, if the maximum element's index is different from the current element's 
   index (`i`), it swaps them.
   
2. **Main Function (Lines 23-45):**
   - The `main` function interacts with the user and performs the sorting.
   - It takes user input for the size of the array and the array elements.
   - It calls the `selectionSort` function to sort the vector in descending order.
   - Finally, it prints the sorted vector in ascending order to the console.

This variation of Selection Sort sorts the elements in descending order by repeatedly selecting 
the maximum element from the unsorted part of the array and placing it at the end. It has the same 
time complexity as the original Selection Sort, which is O(n^2) in all cases.




*/


