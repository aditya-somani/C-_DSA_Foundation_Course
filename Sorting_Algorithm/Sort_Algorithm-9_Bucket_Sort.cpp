/* 
-Bucket Sort - Advance Algorithm - Scatter and Gather approach

-We create bucket of size and then we insert elements into buckets using 'index = arr[i]*n' 
then sort all individuals elements and combine all


Time in avg case - O(n+k) and in worse case O(n^2)

-This code run perfectly if input numbers are below 1 but for numbers greater than 1 it does not!

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to perform Bucket Sort on a vector of floats
void bucketSort(vector<float> &v, int n) {
    // Create a vector of vectors to represent buckets
    vector<vector<float>> bucket(n, vector<float>());

    // Step 1: Distributing elements into buckets based on their normalized values
    for (int i = 0; i < n; i++) {
        // Calculate the index of the bucket using the normalized value of each element
        int index = static_cast<int>(v[i] * n);
        
        // Place the element in the corresponding bucket
        bucket[index].push_back(v[i]);
    }

    // Step 2: Sorting each non-empty bucket
    for (int i = 0; i < n; i++) {
        if (!bucket[i].empty()) {
            // Sort the elements in each non-empty bucket
            sort(bucket[i].begin(), bucket[i].end());
        }  
    }

    // Step 3: Merging sorted buckets back into the original vector
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket[i].size(); j++) {
            // Copy sorted elements from buckets back to the original vector
            v[k++] = bucket[i][j];
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<float> v(n);

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Call the bucketSort function to sort the array
    bucketSort(v, n);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        // Print the sorted elements of the array
        cout << v[i] << " ";
    }

    return 0;
}

Output:-
Enter the size of array : 5
Enter the the array : 0.66 0.72 0.09 0.12 0.661
Sorted array is : 0.09 0.12 0.66 0.661 0.72 

**Explanation:**

1. **bucketSort Function (Lines 7-39):**
   - The `bucketSort` function performs Bucket Sort on the vector `v`.
   - Step 1: It distributes elements into buckets based on their normalized values (scaling to the range [0, 1]).
   - Step 2: It sorts each non-empty bucket.
   - Step 3: It merges the sorted buckets back into the original vector.

2. **Main Function (Lines 41-74):**
   - The `main` function interacts with the user and performs the sorting.
   - It takes user input for the size of the array and the array elements.
   - It calls the `bucketSort` function to sort the array.
   - Finally, it prints the sorted array to the console.

-This code below work for numbers above 1 also!

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform Bucket Sort on a vector of floats
void bucketSort(vector<float> &v, int n) {
    // Create a vector of vectors to represent buckets
    vector<vector<float>> bucket(n, vector<float>());

    // Step 1: Finding the range of input values
    float maxele = v[0];
    float minele = v[0];
    for (int i = 1; i < n; i++) {
        maxele = max(maxele, v[i]);
        minele = min(minele, v[i]);
    }
    float range = (maxele - minele) / n;  //This means that each bucket should cover a range of 'range' values

    // Step 2: Distributing elements into buckets
    for (int i = 0; i < n; i++) {
        // Calculate the index of the bucket for the current element
        int index = (v[i] - minele) / range;

        // Handling boundary elements by checking for a fractional part (diff)
        float diff = (v[i] - minele) / range - index;
        if (diff == 0 && v[i] != minele) {
            // Place the element in the previous bucket for boundary cases
            bucket[index - 1].push_back(v[i]);
        } else {
            // Place the element in the corresponding bucket
            bucket[index].push_back(v[i]);
        }
    }

    // Step 3: Sorting each bucket
    for (int i = 0; i < n; i++) {
        if (!bucket[i].empty()) {
            // Sort the elements in each non-empty bucket
            sort(bucket[i].begin(), bucket[i].end());
        }
    }

    // Step 4: Merging sorted buckets back into the original vector
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket[i].size(); j++) {
            // Copy sorted elements from buckets back to the original vector
            v[k++] = bucket[i][j];
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<float> v(n);

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Call the bucketSort function to sort the array
    bucketSort(v, n);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        // Print the sorted elements of the array
        cout << v[i] << " ";
    }

    return 0;
}

Output:-
Enter the size of array : 6
Enter the the array : 1.2 0.5 6.6 0.95 8.963 1.205
Sorted array is : 0.5 0.95 1.2 1.205 6.6 8.963 

**Explanation:**

1. **bucketSort Function (Lines 7-45):**
   - The `bucketSort` function performs Bucket Sort on the vector `v`.
   - Step 1: It calculates the range of input values to determine the bucket size.
   - Step 2: It distributes elements into buckets based on their values, accounting for boundary cases.
   - Step 3: It sorts each non-empty bucket.
   - Step 4: It merges the sorted buckets back into the original vector.

2. **Main Function (Lines 47-80):**
   - The `main` function interacts with the user and performs the sorting.
   - It takes user input for the size of the array and the array elements.
   - It calls the `bucketSort` function to sort the array.
   - Finally, it prints the sorted array to the console.

-Time Complexity(in any case) -> O(n+k) and in worst case -> O(n^2)
-Space Complexity -> O(n+k)
-It is a Stable Sorting Algorithm


*/









