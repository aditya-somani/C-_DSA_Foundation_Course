/*

-The questions were really good , they have the same concept but don't skip them as every question
have quite different approach , so go and have a good revision!!


-To apply what we need to see is a distinguisable property through which we can divide the array or vector
and it is not compulsory for it to be ascending or decending only it can be anything!

-1. Find the first occurenece of a given element 'x' , given that the given array is sorted.
If no occurence is found return -1. 

#include<iostream>
#include<vector>
using namespace std;

// Function to perform binary search in a sorted vector and find the index of the first occurrence of the target element
int binarySearch(vector<int> &v, int target) {
    int lo = 0;             // Initialize the lower bound of the search range
    int hi = v.size() - 1;  // Initialize the upper bound of the search range

    while (lo <= hi) {
        // Calculate the middle index to split the search range
        int mid = lo + (hi - lo) / 2;

        if (v[mid] == target) {
            // If the middle element is equal to the target, search for the first occurrence by moving backwards
            while (v[mid - 1] == target && mid > 0) {
                mid--;
            }
            return mid; // Return the index of the first occurrence
        } else if (v[mid] > target) {
            // If the middle element is greater than the target, narrow the search to the left subarray
            hi = mid - 1;
        } else {
            // If the middle element is less than the target, narrow the search to the right subarray
            lo = mid + 1;
        }
    }

    return -1; // Return -1 to indicate that the target element was not found
}

int main() {
    int n;
    cout << "Enter the size of vector: ";
    cin >> n;
    vector<int> v(n);

    cout << "Enter the elements of vector (in sorted order): ";
    cin >> v[0]; // Read the first element separately

    // Input validation: Ensure that the entered elements are in sorted order
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        if (v[i] < v[i - 1]) {
            cout << "Error: Please enter elements in sorted order." << endl;
            return 1; // Exit with an error code
        }
    }

    int target;
    cout << "Enter the target element: ";
    cin >> target;

    // Call the binarySearch function to find the index of the first occurrence of the target element
    int result = binarySearch(v, target);

    // Display the result
    if (result != -1) {
        cout << "Index of the first occurrence of target element is: " << result;
    } else {
        cout << "Target element not found in the vector.";
    }

    return 0;
}

Output:-
Enter the size of vector: 7
Enter the elements of vector: 1 2 2 3 4 4 5
Enter the target element: 4
First occurence of target element is: 4

**Explanation:**

- The `binarySearch` function:
  - This function takes a sorted vector (`v`) and a target integer (`target`) as input.
  - It initializes two variables `lo` and `hi` to represent the lower and upper bounds of the search range.
  - The function enters a `while` loop that continues as long as `lo` is less than or equal to `hi`, ensuring the search range is valid.
  - Inside the loop, it calculates the middle index `mid` to split the search range.
  - If the middle element `v[mid]` is equal to the target, it enters a nested loop to search for the first occurrence of the target by 
  moving backward until a different element is encountered or the beginning of the vector is reached. It then returns the index of the 
  first occurrence.
  - If `v[mid]` is greater than the target, it narrows the search to the left subarray by updating `hi` to `mid - 1`.
  - If `v[mid]` is less than the target, it narrows the search to the right subarray by updating `lo` to `mid + 1`.
  - If the target element is not found within the search range, the function returns -1 to indicate that the target element was not found.

- In the `main` function:
  - It starts by taking user input for the size of the vector (`n`) and creates a vector `v` of that size.
  - Then, it prompts the user to enter the elements of the vector one by one in sorted order, ensuring that the entered elements are 
  indeed sorted. If an element is entered out of order, it displays an error message and exits the program with an error code.
  - Next, it takes input for the target element.
  - Finally, it calls the `binarySearch` function to find the index of the first occurrence of the target element and displays the result.
   If the target element is not found, it indicates that as well.

This program effectively performs binary search in a sorted vector and returns the index of the first occurrence of the target element.

-2. Find the square root of the given non negative value of x. Round it off the nearest floor integer value

-This question concept is really important and can be asked in interviews!!


#include<iostream>
#include<vector>
using namespace std;

// Function to calculate the integer square root of a number
int sqrt(int x) {
    // Initialize variables for the search range and the answer
    int lo = 1;
    int hi = x;
    int ans = -1;

    // Perform a binary search to find the square root
    while (lo <= hi) {
        // Calculate the middle value
        int mid = lo + (hi - lo) / 2;

        // Check if the square of mid is less than or equal to x
        if (mid * mid <= x) {
            // If true, update the answer and search the right half
            ans = mid;
            lo = mid + 1;
        } else {
            // If false, search the left half
            hi = mid - 1;
        }
    }

    // Return the truncated square root
    return ans;
}

int main() {
    cout << "Enter the number whose square root you want to find: ";
    int x;
    cin >> x;

    // Call the sqrt function to calculate the square root and display the result
    cout << "Square root of " << x << " is (truncated): " << sqrt(x);

    return 0;
}

Output:-
Enter the number whose square root you want to find : 50
Square root of 50 is (truncated) : 7

**Explanation:**

- The `sqrt` function:
  - Initializes `lo` as 1 (the lowest possible square root) and `hi` as `x` (the input number).
  - Initializes `ans` as -1, which will store the truncated square root.
  - Enters a while loop that continues until `lo` is less than or equal to `hi`.
  - Calculates the `mid` value as the average of `lo` and `hi`.
  - Checks if the square of `mid` is less than or equal to `x`. If true, updates `ans` to `mid` and 
  narrows the search to the right half by updating `lo`. Otherwise, it narrows the search to the left 
  half by updating `hi`.
  - Returns `ans` as the truncated square root.

- In the `main` function:
  - Asks the user to input the number whose square root they want to find.
  - Calls the `sqrt` function with the input number and displays the truncated square root.

This code uses a binary search algorithm to efficiently find the square root of a given integer. 
It iteratively narrows down the search range until it finds the closest integer square root.

-3. Given an array of int a sorted in non-decreasing order. Find the first and last position of 
the given 'target' element in a sorted array

-We can also solve it by solving both firstOccurence and lastOccurence separetely
-This is my way!


#include<iostream>
#include<vector>
using namespace std;

// Function to find the first and last occurrence of an element in a sorted vector
void firstAndLastOccurence(vector<int> &v, int x) {
    int first = -1;  // Initialize first occurrence to -1
    int last = -1;   // Initialize last occurrence to -1
    int lo = 0;
    int hi = v.size() - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        // Check if the middle element is equal to x
        if (v[mid] == x) {
            first = mid;  // Update first occurrence
            last = mid;   // Update last occurrence

            // Search left for the first occurrence
            while (first > 0 && v[first - 1] == x) {
                first--;
            }

            // Search right for the last occurrence
            while (last < v.size() - 1 && v[last + 1] == x) {
                last++;
            }

            // Break out of the loop as both occurrences have been found
            break;
        } else if (v[mid] < x) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    // Check if occurrences were found
    if (first != -1 && last != -1) {
        cout << "The first and last occurrence of " << x << " is: [ " << first << " , " << last << " ]";
    } else {
        cout << "Element " << x << " not found in the vector.";
    }
}

int main() {
    int n, x;
    cout << "Enter the size of the vector: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the vector (sorted in ascending order): ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << "Enter the number whose first and last occurrence you want to find: ";
    cin >> x;
    firstAndLastOccurence(v, x);
    return 0;
}

Output:-
Enter the size of the vector: 6
Enter the vector (sorted in ascending order): 1 2 2 2 3 4
Enter the number whose first and last occurrence you want to find: 2
The first and last occurrence of 2 is: [ 1 , 3 ]

**Explanation:**

- The `firstAndLastOccurrence` function:
  - Initializes `first` and `last` to -1, which are used to store the indices of the first and last 
  occurrences.
  - Performs a binary search for the element `x` in the sorted vector `v`.
  - If `x` is found, it updates both `first` and `last` to the index of the found element.
  - Then, it searches left and right of the found element to find the first and last occurrences, 
  respectively, and updates `first` and `last` accordingly.
  - After the loop, it checks if both occurrences were found and prints the result.

- In the `main` function:
  - It prompts the user for the size of the vector and the elements, assuming the vector is sorted in 
  ascending order.
  - Then, it calls the `firstAndLastOccurrence` function with the user-provided input to find and print 
  the first and last occurrences of `x`.

This code is more efficient and will work correctly for sorted vectors. It uses a single binary search 
to find both the first and last occurrences of the element `x`, reducing the time complexity to O(log n)
 for a sorted vector.

-This is how sir did it!


#include<iostream>
#include<vector>
using namespace std;

// Function to find the lower bound of an element in a sorted vector
int lowerBound(vector<int> &v, int target) {
    int lo = 0;             // Initialize the lower bound of the search range
    int hi = v.size() - 1;  // Initialize the upper bound of the search range
    int ans = -1;           // Initialize the answer to -1

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; // Calculate the middle index

        if (v[mid] >= target) {
            ans = mid;  // Update the answer to the current index
            hi = mid - 1; // Narrow the search to the left subarray
        } else {
            lo = mid + 1; // Narrow the search to the right subarray
        }
    }

    return ans;
}

// Function to find the upper bound of an element in a sorted vector
int upperBound(vector<int> &v, int target) {
    int lo = 0;
    int hi = v.size() - 1;
    int ans = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (v[mid] > target) {
            ans = mid;  // Update the answer to the current index
            hi = mid - 1; // Narrow the search to the left subarray
        } else {
            lo = mid + 1; // Narrow the search to the right subarray
        }
    }

    return ans;
} 

int main() {
    int n, x;
    cout << "Enter the size of the vector: ";
    cin >> n;
    cout << "Enter the vector (in sorted order): ";
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << "Enter the target element: ";
    cin >> x;

    // Call the lowerBound and upperBound functions to find the lower and upper bounds
    int lower = lowerBound(v, x);
    int upper = upperBound(v, x);

    // Display the result
    cout << "First and last occurrence of " << x << " is: [ " << lower << " , " << upper - 1 << " ]";
    return 0;
}

Output:-
Enter the size of vector : 6
Enter the vector : 1 2 2 2 3 4
Enter the target element : 2
First and last occurence of 2 is [ 1 , 3 ]

**Explanation:**

- `lowerBound` and `upperBound` functions:
  - These functions use binary search to find the lower and upper bounds of the target element `x` in a 
  sorted vector `v`.
  - They maintain a search range defined by `lo` and `hi`, initializing `ans` to -1.
  - The search range is narrowed down based on whether the middle element is greater or equal to 
  (for lower bound) or greater than (for upper bound) the target element.
  - The functions return the indices of the lower and upper bounds, respectively.

- In the `main` function:
  - It prompts the user for the size of the vector and the elements, assuming the vector is sorted in 
  ascending order.
  - It calls the `lowerBound` and `upperBound` functions to find the lower and upper bounds of the 
  target element `x`.
  - Finally, it displays the results, providing the first and last occurrences of `x` in the vector.

-4. Given the rotated sorted array of integers, which contains distinct elements, return the minimum element if array 

#include <iostream>
#include <vector>
using namespace std;

// Function to find the minimum element in a rotated sorted vector
int findMinimum(vector<int> &v, int n) {
    // Base case: If the vector has only one element, it's the minimum
    if (n == 1) {
        return v[0];
    }

    int lo = 0;         // Initialize the lower bound
    int hi = n - 1;     // Initialize the upper bound

    // If the first element is smaller than the last element, the vector is sorted
    if (v[lo] < v[hi]) {
        return v[lo];
    }

    // Binary search for the minimum element in a rotated sorted vector
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;  // Calculate the middle index

        // Check if the current element is greater than the next element (a sign of rotation)
        if (v[mid] > v[mid + 1]) {
            return v[mid + 1];  // The minimum element is found at mid+1
        }

        // Check if the current element is smaller than the previous element (another sign of rotation)
        if (v[mid] < v[mid - 1]) {
            return v[mid];  // The minimum element is found at mid
        }

        // If the middle element is greater than the initial element, search on the right side
        if (v[mid] > v[lo]) {
            lo = mid + 1;
        } else {
            // Otherwise, search on the left side
            hi = mid - 1;
        }
    }

    return -1;  // If no minimum is found (shouldn't reach here for a valid rotated sorted vector)
}

int main() {
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;
    cout << "Enter the vector (in sorted/rotated sorted order): ";
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int result = findMinimum(v, n);
    // Display the result
    cout << "Minimum number is present at index: " << result;
    return 0;
}

Output:-
Enter the size of the vector: 5
Enter the vector (in sorted/rotated sorted order): 4 5 1 2 3
Minimum number is present at index : 2

**Explanation** 

### `int findMinimum(vector<int> &v, int n)`
- Finds the minimum element in a rotated sorted vector using binary search.
- Checks if the vector has only one element and returns it as the minimum.
- Initializes bounds (lo and hi) for the binary search.
- If the vector is sorted, returns the first element as the minimum.
- Binary search loop:
   - Calculates the middle index.
   - Determines if the minimum is at mid+1 or mid.
   - Adjusts bounds based on comparisons.
- Returns the index of the minimum element.

### `int main()`
- Main function for user input and output.
- Declares variables for vector size (n) and the vector itself (v).
- Takes user input for vector size and elements.
- Calls findMinimum to find the minimum element's index.
- Displays the index of the minimum element.
- Ends the program with a return statement.

-5.Given the rotated sorted array of integers, which contains distinct elements, and a target value, 
return the index of target if it is in the array otherwise return -1.    


#include<iostream>
#include<vector>
using namespace std;

// Function to find a target element in a rotated or sorted vector
int findTarget(vector<int> &v, int n, int x) {
    int lo = 0, hi = n - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        // Check if the middle element is equal to the target
        if (v[mid] == x) {
            return mid; // Element found, return its index
        }

        // Check whether the left half (lo to mid) is sorted
        if (v[mid] >= v[lo]) {    //To check all elements in left half are sorted lo to mid use gpt for more explanation
            // If the target is within the left half's range, search it
            if (x >= v[lo] && x <= v[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        } else { // The right half (mid to hi) is sorted
            // If the target is within the right half's range, search it
            if (x >= v[mid] && x <= v[hi]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }

    return -1; // Element not found
}

int main() {
    int n, x;
    cout << "Enter the size of the vector: ";
    cin >> n;
    cout << "Enter the vector (in sorted/rotated sorted order): ";
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << "Enter the target element: ";
    cin >> x;

    // Call the findTarget function to search for the target element
    int result = findTarget(v, n, x);

    // Display the result
    if (result != -1) {
        cout << "Target number is present at index: " << result;
    } else {
        cout << "Target number is not present in the vector.";
    }

    return 0;
}

Output:-
Enter the size of the vector: 5
Enter the vector (in sorted/rotated sorted order): 4 5 1 2 3
Enter the target element : 2
Target number is present at index: 3

**Explanation**

### `int findTarget(vector<int> &v, int n, int x)`
- This function finds the index of a target element `x` in a sorted or rotated sorted vector `v` using binary search.
- It initializes `lo` and `hi` to define the search range.
- In a loop, it calculates the middle index `mid` and checks if `v[mid]` equals `x`. If found, it returns `mid`.
- It identifies whether the left or right half of the range is sorted and adjusts `lo` and `hi` accordingly.
- The loop continues until `lo` is less than or equal to `hi`. If the target is not found, it returns -1.

### `int main()`
- This is the main function for user input and output.
- It declares variables for vector size (`n`), the vector itself (`v`), and the target element (`x`).
- It takes user input for vector size, vector elements, and the target element.
- It calls the `findTarget` function to search for the target element.
- It displays the index of the target element if found, or a message if not.
- Finally, it returns 0 to indicate successful program execution.

-6.Search an element in a rotated sorted array with duplicate elements, return 1 if it is found, 
otherwise return -1.

#include<iostream>
#include<vector>
using namespace std;

// Function to search for an element 'x' in a rotated sorted array with duplicates.
// Returns 1 if 'x' is found, otherwise -1.
int searchElement(vector<int> &v, int n, int x) {
    int lo = 0, hi = n - 1;

    // Handle duplicate elements at the beginning and end of the array.
    if (v[lo] == v[hi]) {
        // If the first and last elements are the same, it indicates a sequence of duplicates.
        while (lo <= hi) {
            if (v[lo] == v[hi]) {
                // Increment 'lo' to skip duplicate elements from the start.
                lo++;
                // Decrement 'hi' to skip duplicate elements from the end.
                hi--;
            } else {
                // If 'v[lo]' and 'v[hi]' are not equal, break out of the loop.
                break;
            }
        }
    }

    // Binary search in the rotated sorted array.
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        // Check if the middle element is equal to the target 'x'.
        if (v[mid] == x) {
            return 1; // Element found, return 1
        }

        // Determine which half of the array is sorted and adjust 'lo' and 'hi' accordingly.
        if (v[mid] > x) {
            hi = mid - 1; // Search in the left half
        } else {
            lo = mid + 1; // Search in the right half
        }
    }

    return -1; // Element not found
}

int main() {
    int n, x;
    cout << "Enter the size of the vector: ";
    cin >> n;
    cout << "Enter the vector (in sorted/rotated sorted order): ";
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << "Enter the target element: ";
    cin >> x;

    // Call the searchElement function to search for the target element.
    int result = searchElement(v, n, x);

    // Display the result.
    if (result != -1) {
        cout << "Target number is present at index: " << result;
    } else {
        cout << "Target number is not present in the vector.";
    }

    return 0;
}

Output:-
Enter the size of the vector: 7
Enter the vector (in sorted/rotated sorted order): 5 5 1 2 3 4 5
Enter the target element: 2
Target number is present at index: 3

**Explanation**

### `int searchElement(vector<int> &v, int n, int x)`
- This function is designed to search for a target element `x` in a rotated sorted array with possible duplicate elements.
- It takes three parameters:
  - `v`: A reference to a vector containing the rotated sorted array.
  - `n`: The size of the vector.
  - `x`: The target element to be searched for.
- The function first handles duplicate elements at the beginning and end of the array to optimize the search.
- It then performs a binary search in the rotated sorted array:
  - It calculates the middle index `mid` in the search range and checks if `v[mid]` equals `x`. If found, it returns `1`.
  - Based on whether the left or right half of the array is sorted, it adjusts the search range by updating `lo` and `hi`.
- The search continues until `lo` is less than or equal to `hi`, ensuring a thorough search.
- If the target element `x` is not found, the function returns `-1`.

### `int main()`
- This is the main function responsible for user interaction, input, and output.
- Within this function:
  - It declares integer variables `n` (for vector size), `x` (for the target element), and a vector `v` to store the input array.
  - It interacts with the user by requesting input for the vector size, vector elements, and the target element.
  - It calls the `searchElement` function to perform the search for the target element.
  - Based on the result:
    - If the target element is found (`result == 1`), it displays a message indicating that the target is present and at which index.
    - If the target element is not found (`result == -1`), it displays a message indicating that the target is not present in the vector.
  - Finally, it returns `0` to indicate successful program execution.


*/


