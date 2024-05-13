/*
-Problems based on Sorting Algorithm

Hers's a one line quick revision for Sorting Algorithm 

Bubble - swap two adjacet elements
Selection - find min. element and place it at beginning
Insert - take element from unsorted subarray and insert in sorted subarray
Merge - Divide the array until only one element is there using recursion and then merge them
Quick - choose a pivot element then sort left and right side same way using recursion
Count - making frequency table then cummulative then answer array and then copyinng it to main array
Radix - Same as count but we use unit digit of number as freqency counter so makes code more efficient
Bucket - Create bucket , place element in bucket using index formula , solve boundary condition and done

-Questions are quite easy just do them once and try to understand logic and code behind it!!

-1. Write a program to find 'K' th smallest element in an array using QuickSort

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to partition the vector and return the pivot position
int partition(vector<int> &arr, int l, int r) {
    int pivot = arr[r]; // Choose the pivot as the last element
    int j = l - 1; // Initialize the index of the smaller element

    // Iterate through the elements from l to r-1
    for (int i = l; i < r ; i++) {
        if (arr[i] < pivot) {
            j++;
            swap(arr[i], arr[j]); // Swap elements smaller than the pivot
        }
    }

    swap(arr[j + 1], arr[r]); // Swap the pivot to its correct position
    return j + 1; // Return the index of the pivot element
}

// Function to find the kth smallest element in the vector
int kthSmallest(vector<int> &arr, int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int pos = partition(arr, l, r); // Get the pivot position

        // Base case: If the pivot position is the kth smallest element, return it
        if (pos - l == k - 1) {
            return arr[pos];
        }
        // If the pivot position is greater than k-1, search in the left subarray
        else if (pos - l > k - 1) {
            return kthSmallest(arr, l, pos - 1, k);
        }
        // If the pivot position is smaller than k-1, search in the right subarray
        else {
            return kthSmallest(arr, pos + 1, r, k - (pos - l + 1));
        }
    }
    else {
        cout << "Value of K is wrong ";
        return -1; // Handle the case where K is out of range
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the array: ";
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k, l = 0, r = n - 1;
    cout << "Enter the 'k' th smallest number you want: ";
    cin >> k;

    int result = kthSmallest(arr, l, r, k); // Call the kthSmallest function

    if (result != -1) {
        cout << "'" << k << "'" << " th smallest number is : " << result << endl;
    }

    return 0;
}

Output:-
Enter the the size of array : 7
Enter the array : 1 99 55 45 -10 0 77
Enter the 'k' th smallest number you want : 3
'3' th smallest number is : 1

Explanation:
 - The `partition` function:
   - Chooses the pivot as the last element.
   - Initializes an index `j` to track the position of the smaller element.
   - Iterates through the elements in the specified range (`l` to `r`).
   - If an element is smaller than the pivot, it's swapped with the element at index `j`.
   - After the loop, the pivot is swapped to its correct position (after elements smaller than the pivot).
   - The function returns the index of the pivot element.

 - The `kthSmallest` function:
   - Serves as the recursive function to find the kth smallest element.
   - Checks for the base case: If the range has one or zero elements, it's already sorted.
   - Calls the `partition` function to obtain the pivot index.
   - Recursively searches for the kth smallest element in the left or right subarray depending on the 
   pivot position.

 - In the `main` function:
   - Takes user input for the array size and elements.
   - Calls `kthSmallest` to find the kth smallest element.
   - Outputs the kth smallest element if it's within a valid range.
   - Handles cases where the value of K is out of range.

-Time complexity in worst case -> O(n^2)
                 in any case   -> O(n)

-Dry Run :-

**Sample Input:**

```
Enter the size of the array: 6
Enter the array: 12 3 1 7 8 2
Enter the 'k' th smallest number you want: 3
```

**Dry Run:**

1. User is prompted to enter the size of the array (`n`), which is 6. They input the array elements: `[12, 3, 1, 7, 8, 2]`.

2. User is asked to enter the value of `k`, which is 3 (they want to find the 3rd smallest element).

3. `main` function:
   - `n` is 6, so `l` is set to 0 (the left pointer) and `r` is set to 5 (the right pointer).

4. `kthSmallest` function (Initial Call):
   - Parameters: `arr` (array), `l` (0), `r` (5), `k` (3).
   - It checks if `k` (3) is within valid range (1 to 6). It is, so it proceeds.
   - Calls `partition` to find the pivot and partition the array.

5. `partition` function:
   - Parameters: `arr` (array), `l` (0), `r` (5).
   - Chooses the pivot as the last element (2).
   - Initializes `j` to -1.

   - Iteration 1: i=0, arr[0]=12 (not < 2), no swap.
   - Iteration 2: i=1, arr[1]=3 (< 2), swap with arr[0]. Array: `[3, 12, 1, 7, 8, 2]`. Increment j to 0.
   - Iteration 3: i=2, arr[2]=1 (< 2), swap with arr[0]. Array: `[1, 12, 3, 7, 8, 2]`. Increment j to 1.
   - Iteration 4: i=3, arr[3]=7 (not < 2), no swap.
   - Iteration 5: i=4, arr[4]=8 (not < 2), no swap.

   - Swap the pivot (2) with arr[1]. Array: `[1, 2, 3, 7, 8, 12]`. Pivot index 1 is returned.

6. `kthSmallest` function (Recursive Call 1):
   - Parameters: `arr` (array), `l` (0), `r` (0), `k` (3).
   - It checks if `k` is within valid range. It's not (`k` is 3, but there's only one element), 
   so it prints "Value of K is wrong."

7. The result is not -1, so it prints the 3rd smallest number: "3rd smallest number is: 3".

**Output:**
```
3rd smallest number is: 3
```

The code correctly finds and outputs the 3rd smallest number from the given array using the Quickselect 
algorithm.

-2. Given two sorted arrays , Write a program to merge them in a sorted manner 

#include<iostream>
#include<vector>
using namespace std;

// Function to merge two sorted arrays arr1 and arr2
// into a single sorted array and print the result
void merge(vector<int> &arr1, vector<int> &arr2, int n, int m) {
    int j = 0, l = 0, k = 0;
    vector<int> arr(m + n);  // Create a merged array of size m+n

    // Compare elements within bounds of both arrays
    while (j < n && l < m) {
        // Compare the current elements from both arrays
        if (arr1[j] < arr2[l]) {
            // If the element in arr1 is smaller, add it to the merged array
            arr[k++] = arr1[j++];
        } else {
            // If the element in arr2 is smaller, add it to the merged array
            arr[k++] = arr2[l++];
        }
    }

    // If there are remaining elements in arr1, copy them to the merged array
    while (j < n) {
        arr[k++] = arr1[j++];
    }

    // If there are remaining elements in arr2, copy them to the merged array
    while (l < m) {
        arr[k++] = arr2[l++];
    }

    // Print the combined sorted vector
    cout << "Combined sorted vector is : ";
    for (int i = 0; i < m + n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter the size of array 1: ";
    cin >> n;
    cout << "Enter the elements of array 1: ";
    vector<int> arr1(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    int m;
    cout << "Enter the size of array 2: ";
    cin >> m;
    cout << "Enter the elements of array 2: ";
    vector<int> arr2(m);
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    // Call the merge function to combine and print the sorted vector
    merge(arr1, arr2, n, m);
    return 0;
}

Output:-
Enter the size of the array 1 : 3
Enter the array: 1 2 9
Enter the size of the array 2 : 4
Enter the array: 2 4 5 8
Combined sorted vector is : 1 2 2 4 5 8 9 

**Explanation:**

- The `merge` function:
  - Combines two sorted arrays, `arr1` and `arr2`, into a single sorted array `arr`.
  - Initializes three indices: `j` for `arr1`, `l` for `arr2`, and `k` for `arr`.
  - Creates a merged array `arr` of size `m + n`.
  - Compares elements from `arr1` and `arr2` and adds the smaller element to `arr`.
  - Increments the respective indices (`j`, `l`, and `k`) after adding an element.
  - Handles any remaining elements in `arr1` and `arr2`.
  - Prints the combined sorted vector `arr`.

- The `main` function:
  - Acts as the program's entry point.
  - Takes user input for the size and elements of two arrays, `arr1` and `arr2`.
  - Calls the `merge` function to merge and print the sorted vector.

This code essentially performs the task of merging two sorted arrays into a single sorted array and 
then displays the combined sorted result.

-Dry Run :-

**Sample Input:**

```
Enter the size of array 1: 4
Enter the elements of array 1: 1 3 5 7
Enter the size of array 2: 3
Enter the elements of array 2: 2 4 6
```

**Dry Run:**

1. User is prompted to enter the size of the first array (`arr1`), which is 4. They input the array 
elements: `[1, 3, 5, 7]`.

2. User is prompted to enter the size of the second array (`arr2`), which is 3. They input the array 
elements: `[2, 4, 6]`.

3. `main` function:
   - `arr1` is `[1, 3, 5, 7]` with a size of 4.
   - `arr2` is `[2, 4, 6]` with a size of 3.

4. `merge` function (Initial Call):
   - Parameters: `arr1`, `arr2`, `n` (4), and `m` (3).
   - Initializes `j`, `l`, and `k` to 0.
   - Creates a merged array `arr` of size 7 (`m + n`).

5. `while (j < n && l < m) {`
   - Iteration 1:
     - Compares `arr1[0]` (1) and `arr2[0]` (2). `arr1[0]` is smaller.
     - Adds `arr1[0]` to `arr[0]` and increments `j` and `k`.

   - Iteration 2:
     - Compares `arr1[1]` (3) and `arr2[0]` (2). `arr2[0]` is smaller.
     - Adds `arr2[0]` to `arr[1]` and increments `l` and `k`.

   - Iteration 3:
     - Compares `arr1[1]` (3) and `arr2[1]` (4). `arr1[1]` is smaller.
     - Adds `arr1[1]` to `arr[2]` and increments `j` and `k`.

   - Iteration 4:
     - Compares `arr1[2]` (5) and `arr2[1]` (4). `arr2[1]` is smaller.
     - Adds `arr2[1]` to `arr[3]` and increments `l` and `k`.

   - Iteration 5:
     - Compares `arr1[2]` (5) and `arr2[2]` (6). `arr1[2]` is smaller.
     - Adds `arr1[2]` to `arr[4]` and increments `j` and `k`.

   - Iteration 6:
     - Compares `arr1[3]` (7) and `arr2[2]` (6). `arr2[2]` is smaller.
     - Adds `arr2[2]` to `arr[5]` and increments `l` and `k`.

   - `while` loop ends because both `j` and `l` are out of bounds.

6. Printing the merged array:
   - `Combined sorted vector is : 1 2 3 4 5 6 7`

**Output:**
```
Combined sorted vector is : 1 2 3 4 5 6 7
```

The code successfully merges the two sorted arrays into a single sorted array and prints the result.

*/




