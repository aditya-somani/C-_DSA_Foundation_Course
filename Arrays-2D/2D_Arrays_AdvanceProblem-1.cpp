/*
So, int is we solved two questions and both of them were really exciting and in terestinf and 
if you get time do solve them once again!!

Given a boolean 2D array , where each row is sorted , find row with max. no of 1s 
#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"Enter the size of rows : ";
    cin>>r;
    cout<<"Enter the size of column : ";
    cin>>c;
    int arr[r][c];
    cout<<"Enter the boolean array : ";
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cin>>boolalpha>>arr[i][j];
        }
        
    }
    int a=1;
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (a==arr[i][j])
            {
                cout<<"Row "<<i<<" Has the highest number of 1 (Starting from 0)";
                return 1;
            }
            
        }
        cout<<endl;
    }
    return 0;
}
Output:-
Enter the size of rows : 3
Enter the size of column : 4
Enter the boolean array : 0 1 1 1 0 0 0 1 0 0 1 1
Row 0 Has the highest number of 1 (Starting from 0)   

Now mam's way :- 

#include <iostream>
#include <vector>
using namespace std;

int maxones(vector<vector<int>>& v) {
    int maxones = 0; // Initialize the maximum number of ones to 0
    int maxonerow = -1; // Initialize the row index of the maximum ones to -1
    int columns = v[0].size(); // Get the number of columns in the vector
    for (int i = 0; i < v.size(); i++) { // Iterate through each row of the vector
        int numberofones = 0; // Initialize the count of ones for the current row
        for (int j = 0; j < v[i].size(); j++) { // Iterate through each element in the row
            if (v[i][j] == 1) { // Check if the element is equal to 1
                numberofones++; // Increment the count of ones
            }
        }
        if (numberofones > maxones) { // Check if the count of ones for the current row is greater than the maximum ones
            maxones = numberofones; // Update the maximum ones
            maxonerow = i; // Update the row index for the current maximum ones
        }
    }
    return maxonerow; // Return the row index with the maximum ones
}

int main() {
    int r, c;
    cout << "Enter the size of rows: ";
    cin >> r;
    cout << "Enter the size of column: ";
    cin >> c;
    vector<vector<int>> vec(r, vector<int>(c)); // Create a 2D vector with the specified number of rows and columns
    cout << "Enter the boolean array: ";
    for (int i = 0; i < r; i++) { // Iterate through each row
        for (int j = 0; j < c; j++) { // Iterate through each column
            cin >> boolalpha >> vec[i][j]; // Read the boolean value and store it in the vector
        }
    }
    int ro = maxones(vec); // Get the row index with the maximum ones
    if (ro != -1) { // Check if a row with ones is found
        cout << "Max number of ones is in row " << ro; // Print the row index with the maximum ones
    } else {
        cout << "No ones found in any row."; // Print a message indicating that no ones are found in any row
    }
    return 0;
}
Output :-
Enter the size of rows: 3
Enter the size of column: 4
Enter the boolean array:  1 0 1 0 0 1 1 1 1 1 1 0  
Max number of ones is in row 1

-Given a matrix , turn it by 90 degree in clockwise direction without making another array 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to rotate the array by 90 degrees
void rotatedarray(vector <vector <int>> &v){
    int n=v.size();
    
    // Transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(v[i][j],v[j][i]);
        }
    }
    
    // Reverse each row of the matrix
    for (int i = 0; i < n; i++)
    {
        reverse(v[i].begin(),v[i].end());
    }
    
    return;
}

int main(){
    int r,c;
    cout<<"Enter the size of rows : ";
    cin>>r;
    cout<<"Enter the size of column : ";
    cin>>c;
    cout<<"Enter the array : ";
    
    // Create a 2D vector to store the array
    vector <vector <int>> vec(r, vector<int> (c));
    
    // Input the array elements
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>vec[i][j];
        }
    }
    
    cout<<"Array after rotating by 90 degrees is : ";
    
    // Rotate the array by 90 degrees
    rotatedarray(vec);
    
    // Print the rotated array
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<vec[i][j]<<" ";
        }
    }
    
    return 0;
}

Output :-
Enter the size of rows : 3
Enter the size of column : 3
Enter the array : 1 2 3 4 5 6 7 8 9
Array after rotating by 90 degree is : 7 4 1 8 5 2 9 6 3   */













