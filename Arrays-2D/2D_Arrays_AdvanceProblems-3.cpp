/*
In this we learned about solvind really unique as well as complex question based on prefix sum + 2D-Array manipulation

- Given a matrix 'a' of dimension n x m and 2 coordinates (l1,r1) and (l2,r2),
 return the sum of the rectangle from (l1,r1) to (l2,r2)
 
//Method 1 - Brute force 
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int r,c;
    cout<<"Enter the size of rows : ";
    cin>>r;
    cout<<"Enter the size of column : ";
    cin>>c;
    cout<<"Enter the matrix : ";
    vector<vector <int>> a(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>a[i][j];
        }
        
    }
    cout<<"The entered matrix is : "<<endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int l1,r1,l2,r2,sum=0;
    cout<<"Enter the coordinates of starting point of rectangle : ";
    cin>>l1>>r1;
    cout<<"Enter the coordinates of ending point of rectangle : ";
    cin>>l2>>r2;
    cout<<"Rectangle formed by coodinates "<<l1<<" , "<<r1<<" to "<<l2<<" , "<<r2<<" is : "<<endl;
    for (int i = l1; i <= l2; i++)
    {
        for(int j=r1 ; j<= r2 ; j++)
        {
            sum+=a[i][j];
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Sum of integers from "<<l1<<" , "<<r1<<" to "<<l2<<" , "<<r2<<" is : "<<sum;
    return 0;
}
Output:-
Enter the size of rows : 4
Enter the size of column : 4
Enter the matrix : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
The entered matrix is : 
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16 
Enter the coordinates of starting point of rectangle : 0 0
Enter the coordinates of ending point of rectangle : 1 2
Rectangle formed by coodinates 0 , 0 to 1 , 2 is : 
1 2 3
5 6 7
Sum of integers from 0 , 0 to 1 , 2 is : 24       

//Method 2 - Pre-calculating the horizontal sum for each row in the matrix

#include<iostream>
#include<vector>
using namespace std;
int rectSum(vector<vector <int>> &a , int l1,int r1,int l2,int r2){
    //Prefix sum array row-wise :
    for (int i = 0; i < a.size(); i++)
    {
        for(int j=1 ; j<a[0].size() ; j++){
            a[i][j]+=a[i][j-1];
        }
    }
    int sum=0;
    for (int i = l1; i <= l2; i++)
    {
        if(r1!=0){
            sum+=a[i][r2]-a[i][r1-1];  //if r1=0 then it will give error
        }
        else{
            sum+=a[i][r2];
        }
    }
    return sum;
}
int main(){
    int r,c;
    cout<<"Enter the size of rows : ";
    cin>>r;
    cout<<"Enter the size of column : ";
    cin>>c;
    cout<<"Enter the matrix : ";
    vector<vector <int>> a(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>a[i][j];
        }
        
    }
    cout<<"The entered matrix is : "<<endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int l1,r1,l2,r2;
    cout<<"Enter the coordinates of starting point of rectangle : ";
    cin>>l1>>r1;
    cout<<"Enter the coordinates of ending point of rectangle : ";
    cin>>l2>>r2;
    cout<<"Sum of integers from "<<l1<<" , "<<r1<<" to "<<l2<<" , "<<r2<<" is : "<<rectSum(a,l1,r1,l2,r2);
    return 0;
}

Output:-
Enter the size of rows : 4
Enter the size of column : 4
Enter the matrix : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
The entered matrix is : 
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Enter the coordinates of starting point of rectangle : 0 0
Enter the coordinates of ending point of rectangle : 1 2
Sum of integers from 0 , 0 to 1 , 2 is : 24

Explanation :-

The main logic of this code revolves around two important steps: building a prefix sum array and then calculating the sum 
within the specified rectangular region.

1. Building Prefix Sum Array (Row-wise):
The code starts by reading the input matrix and then proceeds to construct the prefix sum array row-wise. 
The prefix sum array is a 2D array with the same dimensions as the input matrix, where each element represents the sum of all 
elements to its left in the same row, including itself.

To achieve this, the code uses a nested loop:

```
for (int i = 0; i < a.size(); i++) {
    for (int j = 1; j < a[0].size(); j++) {
        a[i][j] += a[i][j - 1];
    }
}
```

- The outer loop `for (int i = 0; i < a.size(); i++)` iterates over each row of the input matrix `a`.
- The inner loop `for (int j = 1; j < a[0].size(); j++)` starts from the second column (index 1) and goes up to the 
last column (`a[0].size()` gives the number of columns in the matrix).
- For each element `a[i][j]`, the code adds the value of the element to its left, `a[i][j - 1]`. This cumulative sum is stored back
 in the matrix, effectively building the prefix sum array.

After this step, the matrix `a` contains the prefix sum for each row, allowing us to calculate the sum of elements within any 
rectangular region in that row efficiently.

2. Calculating the Sum within the Rectangular Region:
The next step is to calculate the sum of integers within the specified rectangular region (l1, r1) to (l2, r2) in the input matrix. 
The prefix sum array built in the previous step will help optimize this calculation.

```
int sum = 0;
for (int i = l1; i <= l2; i++) {
    if (r1 != 0) {
        sum += a[i][r2] - a[i][r1 - 1];
    } else {
        sum += a[i][r2];
    }
}
return sum;
```

- The code initializes a variable `sum` to store the final sum of integers within the specified rectangular region.
- The loop `for (int i = l1; i <= l2; i++)` iterates over the rows in the specified range, from `l1` to `l2`.
- Within this loop, the code checks if `r1` is not equal to 0. If `r1` is not 0, it means the starting column index `r1` is not the
 leftmost column (column 0) of the row. In this case, it calculates the sum by taking the difference between the prefix sum at the 
 ending column index `r2` and the prefix sum at the column index just before the starting column, i.e., `r1 - 1`. This difference 
 represents the sum of integers in the specified rectangular region within the current row.
- If `r1` is 0 (the starting column index is the leftmost column), then it means the prefix sum at `r1 - 1` would be out of 
 bounds (before the start of the row). In this case, the code directly adds the prefix sum at the ending column `r2` to the sum.
- The loop continues until all rows within the specified range have been processed, effectively computing the sum of integers in the 
entire rectangular region.
- The final sum is returned by the function.

In the `main()` function, the user is prompted to enter the size of the matrix, the elements of the matrix, and the coordinates of the
 starting and ending points of the rectangular region. The `rectSum()` function is called with these parameters to calculate the sum, 
 and the result is displayed on the screen.

//Method 3- Prefix sum over columns and rows both

#include<iostream>
#include<vector>
using namespace std;
void print(vector<vector <int>> &a){
    for (int i = 0; i < a.size(); i++)
    {
        for(int j=0 ; j< a[0].size() ; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
int rectSum(vector<vector <int>> &a , int l1,int r1,int l2,int r2){
    //Prefix sum array row-wise :
    for (int i = 0; i < a.size(); i++)
    {
        for(int j=1 ; j<a[0].size() ; j++){
            a[i][j]+=a[i][j-1];
        }
    }
    cout<<"Prefix sum array row-wise : "<<endl;
    print(a);
    
    // Prefix sum array column wise :
    for (int i = 1; i < a.size(); i++)
    {
        for(int j=0 ; j< a[0].size() ; j++){
            a[i][j]+=a[i-1][j];
        }
    }
    cout<<"Prefix sum array column-wise : "<<endl;
    print(a);
    int sum=0;
    cout<<"Sum of integers from "<<l1<<" , "<<r1<<" to "<<l2<<" , "<<r2<<" is : ";
    int left_sum=0 , top_sum=0 , leftmost_sum=0;
    if(l1!=0) top_sum= a[l1-1][r2];
    if(r1!=0) left_sum= a[l2][r1-1];
    if(l1!=0 && r1!=0) leftmost_sum= a[l1-1][r1-1];

    sum= a[l2][r2]- left_sum - top_sum + leftmost_sum;
    return sum;
}
int main(){
    int r,c;
    cout<<"Enter the size of rows : ";
    cin>>r;
    cout<<"Enter the size of column : ";
    cin>>c;
    cout<<"Enter the matrix : ";
    vector<vector <int>> a(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>a[i][j];
        }
        
    }
    cout<<"The entered matrix is : "<<endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int l1,r1,l2,r2;
    cout<<"Enter the coordinates of starting point of rectangle : ";
    cin>>l1>>r1;
    cout<<"Enter the coordinates of ending point of rectangle : ";
    cin>>l2>>r2;
    cout<<rectSum(a,l1,r1,l2,r2);
    return 0;
}
Output:-

Enter the size of rows : 4
Enter the size of column : 4
Enter the matrix : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
The entered matrix is : 
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Enter the coordinates of starting point of rectangle : 0 2
Enter the coordinates of ending point of rectangle : 3 3
Prefix sum array row-wise : 
1 3 6 10
5 11 18 26
9 19 30 42
13 27 42 58
Prefix sum array column-wise :
1 3 6 10
6 14 24 36
15 33 54 78
28 60 96 136
Sum of integers from 0 , 2 to 3 , 3 is : 76

Explanation :-

The main logic of the code is to calculate the sum of integers within a specified rectangular region of a given matrix using 
the concept of prefix sums to optimize the process.

Lets go through the code step by step:

1. Function `print`:
```cpp
void print(vector<vector<int>> &a)
```
This function is responsible for printing the elements of a 2D matrix. It takes a 2D vector `a` by reference as input and iterates 
through the elements to print them row-wise.

2. Function `rectSum`:
```cpp
int rectSum(vector<vector<int>> &a, int l1, int r1, int l2, int r2)
```
This is the main function for calculating the sum of integers within the specified rectangular region. The parameters are:
- `a`: A reference to a 2D vector (`vector<vector<int>>`) representing the input matrix.
- `l1`: The row coordinate of the starting point of the rectangle.
- `r1`: The column coordinate of the starting point of the rectangle.
- `l2`: The row coordinate of the ending point of the rectangle.
- `r2`: The column coordinate of the ending point of the rectangle.

3. Prefix Sum Calculation:
The function starts by calculating the prefix sum array for both rows and columns to optimize the sum calculation within the rectangular
 region.

a. Row-wise Prefix Sum:
```cpp
for (int i = 0; i < a.size(); i++) {
    for (int j = 1; j < a[0].size(); j++) {
        a[i][j] += a[i][j - 1];
    }
}
```
The code iterates through each row of the input matrix and updates each element with the sum of its previous element. This creates a
 row-wise prefix sum array, where `a[i][j]` stores the sum of elements in row `i` from index 0 to `j`.

b. Column-wise Prefix Sum:
```cpp
for (int i = 1; i < a.size(); i++) {
    for (int j = 0; j < a[0].size(); j++) {
        a[i][j] += a[i - 1][j];
    }
}
```
The code iterates through each column of the input matrix and updates each element with the sum of its element above it. This creates a
 column-wise prefix sum array, where `a[i][j]` stores the sum of elements in column `j` from index 0 to `i`.

4. Calculating the Sum within the Rectangular Region:
After computing the prefix sum arrays, the function proceeds to calculate the sum of integers within the specified rectangular region.

The code calculates four different sums:
- `left_sum`: The sum of elements in the rectangle's leftmost column above the starting row.
- `top_sum`: The sum of elements in the rectangle's topmost row to the left of the starting column.
- `leftmost_sum`: The sum of elements in the rectangle's top-left subrectangle.
- `sum`: The sum of elements within the specified rectangular region.

The `sum` is computed by subtracting the `left_sum` and `top_sum` from the total sum of elements in the rectangle (`a[l2][r2]`) and
 then adding back the `leftmost_sum`, as it is subtracted twice in the previous step.

5. Main Function:
The `main()` function takes user input for the size of the matrix, the elements of the matrix, and the coordinates of the starting 
and ending points of the rectangular region. It then calls the `rectSum` function to calculate the sum and prints the result.

With these calculations and optimizations using the prefix sum arrays, the code efficiently computes the sum of integers within the
 specified rectangular region of the given matrix.

 */
