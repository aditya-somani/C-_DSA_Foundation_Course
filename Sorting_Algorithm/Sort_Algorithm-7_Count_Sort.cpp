/*

-Count Sort Algorithm - Advance Algorithm - Only works for +ve numbers 


#include <iostream>
#include <vector>
using namespace std;

// Function to perform Count Sort on a vector
void countSort(vector<int> &v, int n) {
    // Step 1: Find the maximum element in the vector
    int max_ele = INT_MIN; // Initialize the maximum element as the smallest possible value

    // Iterate through the vector to find the actual maximum element
    for (int i = 0; i < n; i++) {
        max_ele = max(v[i], max_ele); // Update max_ele if v[i] is larger
    }

    // Step 2: Create a frequency array and populate it
    vector<int> freq(max_ele + 1, 0); // Frequency array initialized with zeros

    // Count the occurrences of each element in the input vector
    for (int i = 0; i < n; i++) {
        freq[v[i]]++; // Increment frequency count for the current value v[i]
    }

    // Step 3: Create a cumulative frequency array
    for (int i = 1; i <= max_ele; i++) {
        freq[i] += freq[i - 1]; // Update cumulative frequency by adding the previous count
    }

    // Step 4: Create the sorted array using the frequency array
    vector<int> ans(n, 0); // Answer array to hold sorted elements

    // Traverse the input vector in reverse to construct the sorted array
    for (int i = n - 1; i >= 0; i--) {
        // Decrement the frequency count and use it as the index in the sorted array
        ans[--freq[v[i]]] = v[i];
    }

    // Step 5: Copy the sorted elements back to the original vector
    for (int i = 0; i < n; i++) {
        v[i] = ans[i]; // Copy sorted elements from ans[] back to the original vector
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

    // Call the countSort function to sort the vector
    countSort(v, n);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }

    return 0;
}

Output:-
Enter the size of the array: 5
Enter the array elements: 5 2 3 2 1 
Sorted array is: 1 2 2 3 5 

1. **Finding the Maximum Element (Step 1):**
   - `int max_ele = INT_MIN;`: We start by assuming the maximum element is the smallest possible integer
    value.
   - We will iterate through the vector later to find the actual maximum.

2. **Populating the Frequency Array (Step 2):**
   - `vector<int> freq(max_ele + 1, 0);`: We create a frequency array initialized with zeros, where 
   the size is one more than the maximum element.
   - This array will be used to count the occurrences of each element in the input vector.

3. **Counting Occurrences (Step 2 Continued):**
   - `freq[v[i]]++;`: We iterate through the input vector and increment the frequency count for each 
   element `v[i]` in the frequency array.
   - This tells us how many times each element appears in the original vector.

4. **Creating Cumulative Frequencies (Step 3):**
   - `freq[i] += freq[i - 1];`: We create a cumulative frequency array by adding the previous count to 
   the current count.
   - This helps us determine the position of each element in the sorted array.

5. **Creating the Sorted Array (Step 4):**
   - `vector<int> ans(n, 0);`: We create an answer array initialized with zeros to hold the sorted 
   elements.
   - We traverse the input vector in reverse to construct the sorted array.

6. **Constructing the Sorted Array (Step 4 Continued):**
   - `ans[--freq[v[i]]] = v[i];`: We decrement the frequency count for the current element `v[i]` and 
   use it as the index in the sorted array.
   - This ensures that elements with higher frequencies come earlier in the sorted array.

7. **Copying Sorted Elements (Step 5):**
   - `v[i] = ans[i];`: Finally, we copy the sorted elements from the `ans` array back to the original 
   vector `v`.

8. **Main Function:**
   - We take the size of the array and its elements as input, call the `countSort` function to sort the 
   vector, and then print the sorted array.

-This algorithm sorts the input vector in ascending order using the Counting Sort technique. It counts 
the occurrences of each element, creates cumulative frequencies, and then constructs the sorted array 
efficiently.

Overall, Count Sort is an efficient algorithm for sorting non-negative integers when the range of input 
values is not significantly larger than the number of elements. The provided code demonstrates this 
sorting process step by step.


-Time Complexity -> O(n + max_ele) -> if n>>>max_ele -> O(n)
-Space Complexity -> O(n + k) -> if n>>>k -> O(n)  , here k -> size of vector freq[max_ele]

-We will not prefer Count Sort when there is too much disparity between elements and when elements can be -ve.
So , to solve these problems we will use Radix Sort

*/





