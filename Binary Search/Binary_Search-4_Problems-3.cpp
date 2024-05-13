/*
-1.You have 'n'(n<= 10^5) boxes of chocolate. Each box contains a[i] (a[i] <= 10000) chocolates. 
You need to distribute these boxes among 'm' students such that the maximum number of chocolates
allocated to a student is minimum. 
a One box will be allocated to exactly one student.
b. All the boxes should be allocated.
c. Each student has to be allocated at least one box.
d Allotment should be in contiguous order, for instance, a student cannot be allocated box 1 and
box 3, skipping box 2. Calculate and return that minimum possible number.
Assume that it is always possible to distribute the chocolates.
The first line of input will contain the value of n, the number of boxes. The second line of input will 
contain the n numbers denoting the number of chocolates in each box. The third line will contain the m, 
number of students



#include <iostream>
#include <vector>
using namespace std;

// Function to check if it's possible to distribute chocolates such that
// no student gets more than 'mid' chocolates
bool canDistChoco(vector<int> &v, int mid, int s) {
    int studentReq = 1; // Initialize the number of students required
    int currSum = 0;    // Initialize the current sum of chocolates
    int n = v.size();   // Get the total number of boxes

    for (int i = 0; i < n; i++) {
        if (v[i] > mid) {
            return false; // If a box has more chocolates than 'mid', it's not possible
        } else if (currSum + v[i] > mid) {
            studentReq++; // Start a new student as current sum exceeds 'mid'
            currSum = v[i]; // Reset the current sum to the chocolates in the current box
            if (studentReq > s) return false; // If more students are required than 's', not possible
        } else {
            currSum += v[i]; // Add chocolates to the current sum
        }
    }
    return true; // If all boxes can be allocated, return true
}

// Function to find the minimum possible number of chocolates allocated to a student
int distChoco(vector<int> &v, int s) {
    int n = v.size();
    int lo = v[0]; // Initialize the minimum chocolates as the first box
    int hi = 0;    // Initialize the maximum chocolates as the sum of all boxes

    for (int i = 0; i < n; i++) {
        hi += v[i]; // Calculate the total number of chocolates
    }
    int ans = -1; // Initialize the answer to -1

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; // Calculate the middle value
        if (canDistChoco(v, mid, s)) {
            ans = mid; // If distribution is possible, update the answer and search the left half
            hi = mid - 1;
        } else {
            lo = mid + 1; // If not possible, search the right half
        }
    }
    return ans; // Return the minimum possible chocolates allocated
}

int main() {
    int n;
    cout << "Enter the number of boxes : ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the vector : ";
    for (int i = 0; i < n; i++) {
        cin >> v[i]; // Input the number of chocolates in each box
    }
    cout << "Enter the number of students : ";
    int s;
    cin >> s;
    cout << "Max. number of chocolates allocated to a student minimum is : " << distChoco(v, s);
    return 0;
}

Output:-
Enter the number of boxes : 4
Enter the vector : 12 34 67 90
Enter the number of student : 2
Max. number of choclates allocated to a student minimum is : 113

**Explanation:**

- The `canDistChoco` function:
  - This function checks whether it's possible to distribute chocolates such that no student gets more 
  than a specified maximum value (`mid`).
  - It takes three parameters: a vector `v` containing the number of chocolates in each box, an integer 
  `mid` representing the maximum chocolates allowed for a student, and an integer `s` representing the 
  number of students.
  - Inside the function:
    - Initialize `studentReq` to 1, which keeps track of the number of students required.
    - Initialize `currSum` to 0, which represents the current sum of chocolates.
    - Get the total number of boxes (`n`) from the vector.
    - Iterate through the boxes:
      - Check if the chocolates in the current box (`v[i]`) exceed the specified maximum (`mid`). If yes, 
      return `false` as it's not possible.
      - If adding the chocolates in the current box to `currSum` exceeds `mid`, it means a new student 
      is required. Increment `studentReq` and reset `currSum` to the chocolates in the current box.
      - If the chocolates can be added to the current sum without exceeding `mid`, update `currSum`.
      - If the number of students required exceeds the specified `s`, return `false` as it's not possible.
    - If all boxes can be allocated without violating the conditions, return `true`.

- The `distChoco` function:
  - This function finds the minimum possible number of chocolates allocated to a student while satisfying 
  the specified conditions.
  - It takes two parameters: a vector `v` containing the number of chocolates in each box and an 
  integer `s` representing the number of students.
  - Inside the function:
    - Initialize `n` to the size of the vector, which is the total number of boxes.
    - Initialize `lo` to the number of chocolates in the first box, assuming it as the minimum.
    - Initialize `hi` to 0, representing the maximum possible chocolates by summing up all boxes.
    - Initialize `ans` to -1, which will store the final answer.
    - Implement a binary search loop:
      - Calculate `mid` as the middle value between `lo` and `hi`.
      - Call the `canDistChoco` function with `v`, `mid`, and `s` to check if distribution is possible 
      within the specified maximum (`mid`).
      - If distribution is possible, update `ans` with `mid` and search the left half by setting `hi` 
      to `mid - 1`.
      - If distribution is not possible, search the right half by setting `lo` to `mid + 1`.
    - Return the value of `ans`, which represents the minimum possible chocolates allocated to a student.

-2.A new racing track for kids is being built in New York with 'n' starting spots. The spots are located 
along a straight line at positions x1, x2... xn(xi <=10^9). For each 'i', xi+1> xi. At a time only 'm' 
children are allowed to enter the race. Since the race track is for kids, they may run into each other 
while running. To prevent this, we want to choose the starting spots such that the minimum distance 
between any two of them is as large as possible. What is the largest minimum distance?

The first line of input will contain the value of n, the number of starting spots. The second line of 
input will contain the n numbers denoting the location of each spot. The third line will contain the 
value of m, number of children.   

#include<iostream>
#include<vector>
using namespace std;

// Function to check if it's possible to place students with a minimum distance 'mid'
bool canPlaceStud(vector<int> &v, int s, int mid) {
    int studentsReq = 1; // Initialize the number of students required to 1.
    int lastPlace = v[0]; // Initialize the last placed student's position with the first spot.

    for (int i = 1; i < v.size(); i++) {
        if (v[i] - lastPlace >= mid) { // Check if the current spot allows placement with minimum distance 'mid'.
            studentsReq++; // Increment the number of students required.
            lastPlace = v[i]; // Update the last placed student's position.

            if (studentsReq == s) { // If all students are placed, return true.
                return true;
            }
        }
    }
    return false; // If all students cannot be placed with the given 'mid', return false.
}

// Function to find the maximum of the minimum distances to place 's' students
int race(vector<int> &v, int s) {
    int n = v.size();
    int lo = 1; // Lower bound of the search space.
    int hi = v[n - 1] - v[0]; // Upper bound of the search space, maximum possible distance.
    int ans = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (canPlaceStud(v, s, mid)) {
            ans = mid; // Update the answer with the current 'mid'.
            lo = mid + 1; // Search in the right half of the range because it's possible to find a greater minimum distance.
        } else {
            hi = mid - 1; // Search in the left half of the range because it's not possible to achieve the desired minimum distance.
        }
    }
    return ans; // Return the maximum of the minimum distances.
}

int main() {
    int n;
    cout << "Enter the number of spots in the race: ";
    cin >> n;
    vector<int> v(n);

    cout << "Enter the starting spots: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << "Enter the number of students: ";
    int s;
    cin >> s;

    cout << "Maximum of minimum distance to put children is: " << race(v, s);

    return 0;
}

Output:-
Enter the number of spots in race : 5
Enter the starting spots : 1 2 4 8 9
Enter the number of students : 3
To find maximum of minimum distance to put children is : 3

**Explanations**

**`bool canPlaceStud(vector<int> &v, int s, int mid)`**

   - This function checks if it's possible to place students with a minimum distance of 'mid' between 
   them on a race track.
   - It takes three parameters:
     - `v`: A reference to a vector containing the positions of spots on the race track.
     - `s`: The number of students that need to be placed.
     - `mid`: The minimum distance that should be maintained between the students.
   - Inside the function:
     - It initializes `studentsReq` to 1, indicating the first student is placed at the first spot.
     - `lastPlace` is set to the position of the first spot, as it's the starting point.
     - It then iterates through the spots, starting from the second spot.
     - For each spot, it checks if the difference between the current spot's position and the 
     `lastPlace` is greater than or equal to 'mid'.
     - If this condition is met, it means a student can be placed at this spot, so it increments 
     `studentsReq`, updates `lastPlace`, and checks if `studentsReq` equals 's'.
     - If all students are placed with the given 'mid', it returns `true`. Otherwise, it continues 
     checking the remaining spots.
     - If it reaches the end of the loop and cannot place all students with the given 'mid', it returns `false`.

** `int race(vector<int> &v, int s)`**

   - This function finds the maximum of the minimum distances required to place 's' students on a race track.
   - It takes two parameters:
     - `v`: A reference to a vector containing the positions of spots on the race track.
     - `s`: The number of students that need to be placed.
   - Inside the function:
     - It initializes `lo` to 1, which is the minimum possible distance between students.
     - It sets `hi` to the maximum possible distance between the first and last spots on the race track.
     - It initializes `ans` to -1, which will store the maximum of the minimum distances.
     - It enters a binary search loop where it calculates `mid` as the average of `lo` and `hi`.
     - It calls the `canPlaceStud` function to check if it's possible to place students with a minimum 
     distance of 'mid'.
     - If it's possible, it updates `ans` with the current 'mid' and moves the search to the right half 
     of the range by setting `lo` to `mid + 1`.
     - If it's not possible, it moves the search to the left half of the range by setting `hi` to `mid - 1`.
     - The loop continues until `lo` is less than or equal to `hi`, ensuring the search space is correctly
    narrowed down.
     - Finally, it returns `ans`, which holds the maximum of the minimum distances to place 's' students.

** `int main()`**

   - The `main` function is the entry point of the program.
   - It first takes input for the number of spots in the race track (`n`), the positions of the spots, 
   and the number of students (`s`) from the user.
   - Then, it calls the `race` function with the provided input to find the maximum of the minimum 
   distances required to place the students.
   - Finally, it displays the result to the user.

The code efficiently uses binary search to find the maximum of the minimum distances required to place 
students, ensuring a balanced distribution while adhering to the specified minimum distance constraint.

*/