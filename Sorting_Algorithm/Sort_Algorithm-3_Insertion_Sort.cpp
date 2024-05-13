/*
Yep , it was easy just remember the main idea of all algorithms and enjoy learning!
Have A Good Day!

-Insertion Sort Algorithm

-Repeatedly take elements from unsorted subarray & insert in sorted subarray 

#include<iostream>
#include<vector>
using namespace std;

// Function to perform Insertion Sort on a vector of integers
void insertionSort(vector<int> &v, int n) {
    for (int i = 1; i < n; i++) {
        // Store the current element to be inserted into the sorted part of the array
        int current = v[i];
        int j = i - 1; 

        // Compare and shift elements in the sorted part to make space for the current element
        while (j >= 0 && v[j] > current) {
            v[j + 1] = v[j];
            j--;
        }

        // Insert the current element into its correct position in the sorted part
        v[j + 1] = current;
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

    // Call the insertionSort function to sort the array
    insertionSort(v, n);

    return 0;
}

Output:-
Enter the size of array : 5
Enter the array : 50 -10 90 20 0
Sorted vector is : -10 0 20 50 90

**Explanation:**

1. **insertionSort Function (Lines 7-19):**
   - The `insertionSort` function performs the Insertion Sort algorithm on a vector of integers.
   - It starts with the second element (index 1) and considers it as the current element to be inserted 
   into the sorted part of the array.
   - It compares the current element with elements in the sorted part, shifting them to the right until 
   it finds the correct position.
   - Once the correct position is found, it inserts the current element.
   
2. **Main Function (Lines 21-43):**
   - The `main` function interacts with the user and performs the sorting.
   - It takes user input for the size of the array and the array elements.
   - It calls the `insertionSort` function to sort the array.
   - Finally, it prints the sorted vector to the console.


- Worst case occurs when the order is in Descending order, resulting in a time complexity of O(n^2).
- Time complexity in both best and worst cases is given by O(n(n-1)/2), which simplifies to O(n^2).
- The space complexity is O(n) as additional space is required to store the array.
- In the best case, the time complexity is O(n) when the array is already sorted.
- Insertion Sort is a Stable Sorting Algorithm, which means it preserves the relative order of equal 
elements.
*/








