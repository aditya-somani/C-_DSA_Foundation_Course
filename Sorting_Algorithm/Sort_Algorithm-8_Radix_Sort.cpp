/*
-Radix Sort Algorithm - Advance Algorithm 

-It is more efficient than Count Sort but also like it does not work for negative element
-Count and Radix Sort also does not work for float integers

-Just give a quick revision get a grasp of its logic , logic is more important than Algo as it is more
used than actual Algorithm!


#include <iostream>
#include <vector>
using namespace std;

// Function to perform Count Sort for a specific digit position (pos)
void countSort(vector<int> &v, int pos) {
    int n = v.size();

    // Step 1: Calculate the frequency array
    vector<int> freq(10, 0);   //as max. size can only vary between '0-9' as we are talking about only unit digits
    for (int i = 0; i < n; i++) {
        freq[(v[i] / pos) % 10]++;
    }

    // Step 2: Create a cumulative array
    for (int i = 1; i < 10; i++) {
        freq[i] += freq[i - 1];
    }

    // Step 3: Create the answer array
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[--freq[(v[i] / pos) % 10]] = v[i];
    }

    // Step 4: Copy the sorted array back to the original vector
    for (int i = 0; i < n; i++) {
        v[i] = ans[i];
    }
}

// Function to perform Radix Sort on a vector of integers
void radixSort(vector<int> &v, int n) {
    int max_ele = INT_MIN;

    // Find the maximum element in the array to determine the number of digits
    for (auto x : v) {
        max_ele = max(x, max_ele);
    }

    // Perform counting sort for each digit position, from least to most significant
    for (int pos = 1; max_ele / pos > 0; pos *= 10) {
        countSort(v, pos);
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

    // Call the radixSort function to sort the vector
    radixSort(v, n);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }

    return 0;
}

Output:-
Enter the size of the array: 6
Enter the array elements: 170 45 75 90 802 2
Sorted array is: 2 45 75 90 170 802 

**Explanation:**

1. **countSort Function (Lines 10-31):**
   - The `countSort` function sorts the vector `v` based on the digit position `pos`.
   - Step 1 calculates the frequency array for the current digit position.
   - Step 2 creates a cumulative frequency array.
   - Step 3 constructs the sorted array.
   - Step 4 copies the sorted elements back to the original vector.

2. **radixSort Function (Lines 33-47):**
   - The `radixSort` function orchestrates the Radix Sort algorithm.
   - It determines the maximum element in the input vector to decide the number of iterations.
   - For each digit position (from least to most significant), it calls `countSort`.

3. **Main Function (Lines 49-80):**
   - The `main` function takes user input for the size of the array and the array elements.
   - It calls `radixSort` to sort the vector.
   - Finally, it prints the sorted array to the console.

-Time Complexity -> O(d*(n+k)) ~ O(d*n) where d-> no. of digits of max. element and k-> size of freq vector
and as k is fixed at 10 it can be ignored. Therefore, Time Complexity -> O(d*n)

-Space Complexity -> O(n+k) ~ O(n)     , k being ignored for same reason


*/




