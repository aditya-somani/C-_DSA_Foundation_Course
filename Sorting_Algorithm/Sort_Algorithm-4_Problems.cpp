/*
-1. Given an integer arr, move all 0s to the end of it while maintaining the relative order of the 
non-zero elements

#include<iostream>
#include<vector>
using namespace std;

// Function to move all zeros to the end of a vector
void swapZeroesToEnd(vector<int> &v, int n) {
    // Iterate through the vector in reverse order
    for (int i = n - 1; i >= 0; i--) {
        int j = 0;
        bool flag = false;
        
        // Iterate through the vector until reaching the current position
        while (j != i) {
            // If a zero is found followed by a non-zero element, swap them
            if (v[j] == 0 && v[j + 1] != 0) {
                swap(v[j], v[j + 1]);
                flag = true;
            }
            j++;
        }
        
        // If no swaps were made in this pass, break the loop
        if (!flag) {
            break;
        }
    }
    
    // Output the sorted vector
    cout << "Sorted vector is : ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> v(n);
    
    // Input elements of the array
    cout << "Enter the array: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    // Call the swapZeroesToEnd function to sort the array
    swapZeroesToEnd(v, n);
    return 0;
}

Output:-
Enter the size of array : 5
Enter the array : 3 0 5 0 1
Sorted vector is : 3 5 1 0 0 

Explanation:

1. swapZeroesToEnd Function (Lines 7-27):
   - The `swapZeroesToEnd` function takes a vector `v` and its size `n` as parameters.
   - It uses a modified bubble sort-like approach to move all zeros to the end of the vector.
   - It iterates through the vector in reverse order and compares adjacent elements.
   - If it encounters a zero followed by a non-zero element, it swaps them.
   - If no swaps are made in a pass, it breaks the loop as the vector is sorted.

2. Main Function (Lines 29-51):
   - The `main` function interacts with the user and performs the sorting.
   - It takes user input for the size of the array and the array elements.
   - It calls the `swapZeroesToEnd` function to sort the array by moving zeros to the end.
   - Finally, it prints the sorted vector to the console.



-Space complexity -> O(n)
-Time complexity -> O(n^2)

If you want to keep time complexity to O(n) then use this code:-

#include<iostream>
#include<vector>
using namespace std;

// Function to move all zeros to the end of a vector
void swapZeroesToEnd(vector<int> &v, int n) {
    // Initialize an index to keep track of non-zero elements
    int nonZeroIdx = 0;

    // Iterate through the vector to move non-zero elements to the front
    for (int i = 0; i < n; i++) {
        // Check if the current element is non-zero
        if (v[i] != 0) {
            // Move the non-zero element to the current nonZeroIdx position
            v[nonZeroIdx] = v[i];
            // Increment the nonZeroIdx to point to the next position
            nonZeroIdx++;
        }
    }

    // Fill the remaining elements with zeros
    while (nonZeroIdx < n) {
        v[nonZeroIdx] = 0;
        nonZeroIdx++;
    }
    
    // Output the sorted vector
    cout << "Sorted vector is : ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    vector<int> v(n);

    // Input elements of the array
    cout << "Enter the array : ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Call the swapZeroesToEnd function to sort the array
    swapZeroesToEnd(v, n);

    return 0;
}

Output:-
Enter the size of array : 5
Enter the array : 3 0 5 0 1
Sorted vector is : 3 5 1 0 0 

Explanation:

1. swapZeroesToEnd Function (Lines 7-23):
   - The `swapZeroesToEnd` function takes a vector `v` and its size `n` as parameters.
   - It initializes an index `nonZeroIdx` to keep track of non-zero elements.
   - It iterates through the vector to move non-zero elements to the front of the vector.
   - When a non-zero element is encountered at index `i`, it is moved to the `nonZeroIdx` position.
   - The `nonZeroIdx` is incremented to point to the next available position.
   - After processing all non-zero elements, it fills the remaining positions with zeros.

2. Main Function (Lines 25-47):
   - The `main` function interacts with the user and performs the sorting.
   - It takes user input for the size of the array and the array elements.
   - It calls the `swapZeroesToEnd` function to sort the array by moving zeros to the end.
   - Finally, it prints the sorted vector to the console.

This program takes an array of integers as input and rearranges it to move all zeros to the end 
while preserving the order of non-zero elements. It accomplishes this by iterating through the array, 
moving non-zero elements to the front, and filling the remaining positions with zeros. The result is 
a sorted array with zeros at the end.

-Here Time complexity - O(n)

-2. Given an array of names of fruits, sort it in the lexicographical order using selection sort.

#include<iostream>
#include<cstring>
using namespace std;

// Function to perform Selection Sort on an array of strings
void selectionSort(char fruit[][10], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Initialize the index of the minimum element
        int min_idx = i;

        // Find the index of the minimum lexicographically
        for (int j = i + 1; j < n; j++) {
            // Compare strings using strcmp function
            if (strcmp(fruit[min_idx], fruit[j]) > 0) {
                min_idx = j;
            }
        }

        // Swap the minimum element with the current element (if different)
        if (i != min_idx) {
            swap(fruit[i], fruit[min_idx]);
        }
    }

    // Output the lexicographically sorted array of strings
    cout << "Lexicographically ordered fruits: ";
    for (int i = 0; i < n; i++) {
        cout << fruit[i] << " ";
    }
}

int main() {
    int num;
    
    // Prompt user for the number of fruits
    cout << "Enter the number of fruits : ";
    cin >> num;
    
    // Create a 2D array to store the names of fruits
    char fruit[num][10];

    // Input names of fruits from the user
    cout << "Enter the names of fruits : ";
    for (int i = 0; i < num; i++) {
        cin >> fruit[i];
    }

    // Calculate the size of the 2D array
    int n = sizeof(fruit) / sizeof(fruit[0]);

    // Call the selectionSort function to lexicographically sort the array of strings
    selectionSort(fruit, n);

    return 0;
}

Output:-
Enter the number of fruits : 5
Enter the name fruits : banana pineapple apple guava cherry
Lexicographically order is : apple banana cherry guava pineapple 

Explanation:

1. selectionSort Function (Lines 7-24):
   - The `selectionSort` function takes a 2D array of characters `fruit` and its size `n` as parameters.
   - It performs the Selection Sort algorithm to lexicographically sort the array of strings.
   - It starts by assuming the first element as the minimum and finds the minimum lexicographically 
   among the remaining elements.
   - If a smaller string is found, it updates the `min_idx` to the index of the new minimum.
   - After the inner loop, if the minimum element's index is different from the current element's 
   index (`i`), it swaps them.

2. Main Function (Lines 26-49):
   - The `main` function interacts with the user and performs the sorting.
   - It takes user input for the number of fruits and their names, storing them in a 2D character 
   array `fruit`.
   - It calculates the size of the `fruit` array using `sizeof`.
   - It calls the `selectionSort` function to lexicographically sort the array of fruits.
   - Finally, it prints the lexicographically sorted array of fruits to the console.

This program allows the user to input a list of fruits and then uses the Selection Sort algorithm 
to lexicographically order the names of these fruits. The program takes care of comparing and 
rearranging the strings based on their lexicographical order, and the sorted list of fruits is presented 
to the user.

-Time complexity :- O(n^2)

*/



