/*
-Here I learned that sometimes questions may sound/appear but its logic it easy and simple. so don't get 
overwhelmed by its language , have cool mind and try to solve and believe me it will get SOLVED!!

-As for question they are medium grade and here we solved one question (second last) using binary search 
which was not sorted. -> Busting myth that binary search can only be used on sorted array



-1.Given a mountain array 'a' of length greater than 3, return the index 'i' such that 
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length-1]. 
This index is known as the peak index.


#include<iostream>
#include<vector>
using namespace std;

// Function to find the peak element in a mountain array.
// A mountain array is defined as an array that increases up to a certain index and then decreases.
// Returns the index of the peak element.
int peakInMountainArray(vector<int> &v, int n) {
    int lo = 0, hi = n - 1, ans = -1;

    // Binary search to find the peak element in the mountain array.
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        // If the element at the middle index is greater than the element to its left,
        // update the 'ans' and move the 'lo' to the right half of the array.
        if (v[mid] > v[mid - 1]) {
            ans = max(mid, ans);
            lo = mid + 1;
        } else {
            // If the element at the middle index is not greater, move 'hi' to the left half.
            hi = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the vector: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Call the 'peakInMountainArray' function to find the peak index.
    int peakIndex = peakInMountainArray(v, n);

    cout << "Maximum number in the vector is at index: " << peakIndex;

    return 0;
}

Output:-
Enter the size of vector : 9
Enter the vector : 1 2 3 4 5 6 3 2 0
Maximum number in whole vector is at index : 5

**Explanation**

### `int peakInMountainArray(vector<int> &v, int n)`
- This function aims to find the peak element in a mountain array.
- It takes two parameters:
  - `v`: A reference to a vector containing the mountain array.
  - `n`: The size of the vector.
- The function uses a binary search approach to efficiently locate the peak element.
- It initializes `lo` and `hi` to define the search range.
- Within a while loop:
  - It calculates the middle index `mid` within the search range.
  - If the element at `mid` is greater than the element to its left, it updates `ans` with `mid` as a 
  potential peak index and narrows the search to the right half.
  - If the element at `mid` is not greater than its left neighbor, the search narrows to the left half.
- The loop continues until `lo` is less than or equal to `hi`, ensuring a thorough search.
- The function returns the index of the peak element (or -1 if not found) stored in `ans`.

### `int main()`
- This is the main function responsible for user interaction, input, and output.
- Within this function:
  - It declares an integer variable `n` for vector size and a vector `v` to store the input array.
  - It interacts with the user by requesting input for the vector size and vector elements.
  - It calls the `peakInMountainArray` function to find the peak index.
  - It displays a message indicating the index of the maximum number in the vector.
- Finally, it returns `0` to indicate successful program execution.

This explanation provides a clear overview of the purpose and functionality of each function in your code.


-2.A peak element is an element that is strictly greater than its neighbors. Given a 0-indexed integer 
array nums, find a peak element, and return its index. If the array contains multiple peaks, return 
the index to any of the peaks. You may imagine that nums[-1] = nums[n] = -∞. In other words, an element 
is always considered to be strictly greater than a neighbor that is outside the array.


#include<iostream>
#include<vector>
using namespace std;

// Function to find the index of multiple peaks in a mountain array.
int multiplePeakInMountainArray(vector<int> &v) {
    int n = v.size();   // Get the size of the input vector.
    int li = 0, hi = n - 1; // Initialize left and right pointers for binary search.
    
    while (li <= hi) { // Binary search loop for finding peaks.
        int mid = li + (hi - li) / 2; // Calculate the middle index.
        
        if (mid == 0) { // Special case: Check the leftmost element.
            if (v[mid] > v[mid + 1]) {
                return 0; // Return 0 if it's a peak.
            } else {
                return 1; // Return 1 if it's not a peak.
            }
        } else if (mid == n - 1) { // Special case: Check the rightmost element.
            if (v[mid] > v[mid - 1]) {
                return n - 1; // Return n-1 if it's a peak.
            } else {
                return n - 2; // Return n-2 if it's not a peak.
            }
        } else {
            if (v[mid] > v[mid + 1] && v[mid] > v[mid - 1]) {
                return mid; // Return mid if it's a peak.
            } else if (v[mid] > v[mid - 1]) {
                li = mid + 1; // Adjust the left pointer if mid is not a peak.
            } else {
                hi = mid - 1; // Adjust the right pointer if mid is not a peak.
            }
        }
    }
    
    return -1; // Return -1 if no peak is found.
}

int main() {
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the vector: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Call the 'multiplePeakInMountainArray' function to find the peak index.
    int peakIndex = multiplePeakInMountainArray(v);

    cout << "Index of a peak in the vector: " << peakIndex;

    return 0;
}


Output:-
Enter the size of the vector: 7
Enter the vector: 1 2 1 2 6 10 3
Maximum number in the vector is at index: 5

**Explanation**

### `int multiplePeakInMountainArray(vector<int> &v)`
- This function is designed to find the index of multiple peaks in a mountain array.
- It takes a single parameter:
  - `v`: A reference to a vector containing the mountain array.
- The function uses a binary search-like approach to locate multiple peaks within the array.
- It first determines the size of the array `n`.
- It initializes `li` (left index) to 0 and `hi` (right index) to `n-1` to define the initial search range.
- Inside a while loop:
  - It calculates the middle index `mid` within the current search range.
  - It handles special cases:
    - If `mid` is 0, it checks whether the element at `mid` is greater than the element to its right. 
    If true, it's considered a peak, and 0 is returned. Otherwise, it's not a peak, and 1 is returned.
    - If `mid` is `n-1`, it checks whether the element at `mid` is greater than the element to its left. 
    If true, it's considered a peak, and `n-1` is returned. Otherwise, it's not a peak, and `n-2` is 
    returned.
  - For other values of `mid`, it checks whether the element at `mid` is greater than its neighbors on 
  both sides. If true, it's considered a peak, and `mid` is returned.
  - If the element at `mid` is not greater than both neighbors, it determines whether to search in the 
  left or right half by updating `li` or `hi` accordingly.
- The loop continues until `li` is less than or equal to `hi`, ensuring all potential peaks are identified.
- The function returns the index of the first peak found or -1 if no peaks are found.

### `int main()`
- This is the main function responsible for user interaction, input, and output.
- Within this function:
  - It declares an integer variable `n` for vector size and a vector `v` to store the input array.
  - It interacts with the user by requesting input for the vector size and vector elements.
  - It calls the `multiplePeakInMountainArray` function to find the peak index.
  - It displays a message indicating the index of the maximum number in the vector.
- Finally, it returns `0` to indicate successful program execution.

-3.Search the target' value in a 2d integer matrix of dimensions n x m and retum 1 if found,
else retum O. This matrix has the following properties:
-. Integers in each row are sorted from left to right.
-. The first integer of each row is greater than the last integer of the previous row.

->linear search , binary on rows , coverting 2D array into 1D and then using binary search but most effective:-

#include<iostream>
#include<vector>
using namespace std;

// Function to search for an element in a 2D vector using binary search
int search(vector<vector<int>>& v, int m, int n, int x) {
    int start = 0, last = m * n - 1;
    while (start <= last) {
        // Calculate the middle index
        int mid = start + (last - start) / 2;

        // Calculate the row and column coordinates in the 2D vector
        int row = mid / m;  // Row coordinate
        int col = mid % m;  // Column coordinate

        // Compare the element at the calculated row and column with the target element 'x'
        if (x == v[row][col]) {
            return mid;  // Element found, return its index
        } else if (x > v[row][col]) {
            start = mid + 1;  // If the middle element is smaller, search in the right half
        } else {
            last = mid - 1;   // If the middle element is larger, search in the left half
        }
    }
    return -1;  // Element not found
}

int main() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    // Create a 2D vector of integers
    vector<vector<int>> v(m, vector<int>(n));

    cout << "Enter the 2D vector: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    int x;
    cout << "Enter the target element: ";
    cin >> x;

    // Call the search function to find the element in the 2D vector
    int result = search(v, n, m, x);

    // Check if the element was found and display the result
    if (result != -1) {
        cout << "Yes, number is present in vector -> 1(found)";
    } else {
        cout << "No, number is not present in vector -> -1 (Not Found)";
    }

    return 0;
}


Ouput:-
Enter the number of rows : 3
Enter the number of column : 4
Enter the 2D vector : 1 3 5 7 11 13 15 17 19 21 23 25
Enter the target element : 0
No , number is not present in vector -> -1 (Not Found)

Enter the number of rows : 3
Enter the number of column : 4
Enter the 2D vector : 1 3 5 7 11 13 15 17 19 21 23 25
Enter the target element : 19
Yes , number is present in vector -> 1 (found)

**Explanation**

### `int search(vector<vector<int>>& v, int m, int n, int x)`
- This function is designed to search for a target element `x` within a 2D vector `v` using a binary search algorithm.
- Parameters:
  - `v`: A reference to the 2D vector in which the search is performed. Passed by reference to avoid unnecessary copying.
  - `m`: The number of columns in the 2D vector.
  - `n`: The number of rows in the 2D vector.
  - `x`: The target element to locate within the 2D vector.
- The function initializes `start` to 0 and `last` to `m * n - 1` to define the initial search range.
- It employs a while loop to perform binary search:
  - In each iteration, it calculates the middle index `mid`.
  - It computes the row and column coordinates within the 2D vector:
    - `row`: Represents the row coordinate of the element at `mid`.
    - `col`: Represents the column coordinate of the element at `mid`.
  - The function compares the element at the calculated row and column with the target element `x`:
    - If they match, the function returns `mid` to indicate that the element is found.
    - If `x` is greater than the element, it narrows the search to the right half by updating `start`.
    - If `x` is less than the element, it narrows the search to the left half by updating `last`.
- This process continues until the element is found or the search range is exhausted.
- If the element is not found within the 2D vector, the function returns -1.

### `int main()`
- The `main` function is the central component of the program, responsible for user interaction, input, and output.
- Within this function:
  - It declares integer variables `n` for the number of rows and `m` for the number of columns in the 2D vector.
  - It creates a 2D vector `v` with dimensions `m`x`n` to store user-inputted elements.
  - User interaction takes place as follows:
    - The program requests input for the number of rows (`n`) and columns (`m`).
    - The user is prompted to provide the elements for the 2D vector `v`.
    - The target element `x` is input from the user.
  - The function then calls the `search` function to find the index of the target element within the 2D vector.
  - Based on whether the element is found (the result is not -1), it displays a message to the user:
    - If found, it displays "Yes, number is present in vector -> 1(found)".
    - If not found, it displays "No, number is not present in vector -> -1 (Not Found)".
- Finally, the function returns 0 to indicate the successful execution of the program.


*/







