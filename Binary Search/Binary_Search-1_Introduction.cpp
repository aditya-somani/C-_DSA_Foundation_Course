/*

-In this we have theory for binary search which is not that out of the world just breaking sorted array into two halves and then
comparing the target value with the mid value and then choosing halves and then repeating the process till we get the target element or not

-So, you choice if you want to read it , I will say skip theory just jump on to Question -bye have a great day!! 


#include<iostream>
#include<vector>
using namespace std;

// Function to perform binary search in a sorted vector and find the index of the target element
int binarySearch(vector<int> &v, int target) {
    int li = 0;                 // Initialize the left index of the search range
    int hi = v.size() - 1;      // Initialize the right index of the search range

    while (li <= hi) {          // Continue the loop while the search range is valid
        int mid = (li + hi) / 2; // Calculate the middle index of the current search range

        if (v[mid] == target) {  // If the middle element is the target, return its index
            return mid;
        } else if (v[mid] > target) { // If the middle element is greater, search the left subarray
            hi = mid - 1;           // Update the right index to mid-1
        } else {               // If the middle element is smaller, search the right subarray
            li = mid + 1;           // Update the left index to mid+1
        }
    }

    return -1; // Return -1 to indicate that the target element was not found
}

int main() {
    int n;
    cout << "Enter the size of vector: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements of vector: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int target;
    cout << "Enter the target element: ";
    cin >> target;

    // Call the binarySearch function to find the index of the target element
    int result = binarySearch(v, target);

    // Display the result
    if (result != -1) {
        cout << "Index of target element is: " << result;
    } else {
        cout << "Target element not found in the vector.";
    }

    return 0;
}

Output:-
Enter the size of vector : 5
Enter the elements of vector : 1 2 3 4 5
Enter the target element : 4
Index of target element is : 3

**Explanation:**

- The `binarySearch` function:
  - This function performs binary search on a sorted vector to find the index of a target element.
  - Parameters:
    - `v`: A reference to a sorted vector in which the search will be conducted.
    - `target`: The target element to search for.

  - `int li=0;` and `int hi= v.size()-1;`:
    - Initialize `li` (left index) to 0 and `hi` (right index) to the last index of the vector. 
    These indices define the search range.

  - `while (li<=hi)`:
    - This loop continues as long as `li` is less than or equal to `hi`, ensuring the search range is 
    valid.

  - `int mid = (li+hi)/2;`:
    - Calculate the middle index `mid` of the current search range.

  - `if (v[mid]==target)`:
    - If the element at the middle index (`mid`) is equal to the target element (`target`), return `mid` 
    as the index where the target element is found.

  - `else if (v[mid]>target)`:
    - If the element at `mid` is greater than the target, it means the target element is on the left side 
    of `mid`. So, update `hi` to `mid-1` to search in the left subarray.

  - `else`:
    - If the element at `mid` is less than the target, it means the target element is on the right side 
    of `mid`. So, update `li` to `mid+1` to search in the right subarray.

  - If the loop exits without finding the target element, return `-1` to indicate that the element was 
  not found.

- The `main` function:
  - This is the entry point of the program.
  - Takes user input for the size of the vector (`n`) and its elements.
  - Takes user input for the target element to search for.
  - Calls the `binarySearch` function with the vector and target element as arguments.
  - Prints the index of the target element if found or `-1` if not found.

This code performs a binary search on a sorted vector to find the index of a target element and displays the result.

-Dry Run:-

**Sample Input:**

```
Enter the size of vector: 8
Enter the elements of vector: 1 3 5 7 9 11 13 15
Enter the target element: 9
```

**Dry Run:**

1. User is prompted to enter the size of the vector (`n`), which is 8. They input the elements of the vector: `[1, 3, 5, 7, 9, 11, 13, 15]`.

2. User is prompted to enter the target element (`target`), which is 9.

3. `main` function:
   - `v` is `[1, 3, 5, 7, 9, 11, 13, 15]` with a size of 8.
   - `target` is 9.

4. `binarySearch` function (Initial Call):
   - Parameters: `v`, `target`.
   - Initializes `li` to 0 and `hi` to 7 (size of `v` minus 1).

5. First iteration of the `while` loop:
   - `li` is 0, `hi` is 7, so the loop is executed.
   - Calculates `mid` as (0 + 7) / 2 = 3.

6. `if (v[mid] == target)`:
   - Checks if `v[3]` (7) is equal to the `target` (9), which is false.

7. `else if (v[mid] > target)`:
   - Checks if `v[3]` (7) is greater than the `target` (9), which is false.
   - Updates `hi` to `mid - 1` which is 2.

8. Second iteration of the `while` loop:
   - `li` is still 0, `hi` is now 2, so the loop continues.
   - Calculates `mid` as (0 + 2) / 2 = 1.

9. `if (v[mid] == target)`:
   - Checks if `v[1]` (3) is equal to the `target` (9), which is false.

10. `else if (v[mid] > target)`:
    - Checks if `v[1]` (3) is greater than the `target` (9), which is true.
    - Updates `hi` to `mid - 1` which is 0.

11. Third iteration of the `while` loop:
    - `li` is still 0, `hi` is now 0, so the loop continues.
    - Calculates `mid` as (0 + 0) / 2 = 0.

12. `if (v[mid] == target)`:
    - Checks if `v[0]` (1) is equal to the `target` (9), which is false.

13. `else if (v[mid] > target)`:
    - Checks if `v[0]` (1) is greater than the `target` (9), which is false.
    - Updates `li` to `mid + 1` which is 1.

14. Fourth iteration of the `while` loop:
    - `li` is now 1, `hi` is still 0, which is not a valid range, so the loop exits.

15. The function returns -1 to indicate that the target element (9) was not found in the vector.

16. In the `main` function, the result of `binarySearch(v, target)` is -1, so it prints "Target element not found in the vector."

**Output:**
```
Target element not found in the vector.
```

The code successfully performed a binary search and correctly identified that the target element 9 is not present in the vector.

-Space Complexity :- O(n)
-Time Complexity :- O(logn)

n -> n/2 -> n/4 -> ... -> 1 => n/2^k = 1 => 2^k = n => k = log_2(n);

-Now doing binary search recursively


#include<iostream>
#include<vector>
using namespace std;

// Function to perform binary search in a sorted vector and find the index of the target element
int binarySearch(vector<int> &v, int target, int li, int hi) {
    int mid = (li + hi) / 2;

    // Base case: If li is greater than or equal to hi, the search range is invalid.
    // In this case, return mid as it represents the closest index to the target.
    if (li >= hi) {
        return mid;
    } else if (v[mid] < target) {
        // If the middle element is less than the target, search the right subarray.
        return binarySearch(v, target, mid + 1, hi);
    } else {
        // If the middle element is greater or equal to the target, search the left subarray.
        return binarySearch(v, target, li, mid - 1);
    }

    // Return -1 to indicate that the target element was not found (this line is not reachable).
    return -1;
}

int main() {
    int n;
    cout << "Enter the size of vector: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements of vector: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int target;
    cout << "Enter the target element: ";
    cin >> target;

    int li = 0, hi = v.size() - 1;

    // Call the binarySearch function to find the index of the target element
    int result = binarySearch(v, target, li, hi);

    // Display the result
    if (result != -1) {
        cout << "Index of target element is: " << result;
    } else {
        cout << "Target element not found in the vector.";
    }

    return 0;
}

Output:-
Enter the size of vector: 5
Enter the elements of vector: 1 2 3 4 5
Enter the target element: 3
Index of target element is: 2

-Here both time and space complexity will be -> O(logn)

-The value of mid can exceed int count("OVERFLOW") if value of li and hi are very big (INT_MAX) so to solve it
we use 'mid = li + (hi-li)/2' */






