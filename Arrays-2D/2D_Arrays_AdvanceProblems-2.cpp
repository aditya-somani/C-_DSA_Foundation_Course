/*
In this we learned how to code spiral matrix and Man that was sure interesting as well as mind bobling1

-Given a matrix "v" , print its spiral matrix
1 2 3        1 2 3 
4 5 6   ->   6 9 8
7 8 9        7 4 5


#include<iostream>
#include<vector>
using namespace std;
void spiralorder(vector<vector<int>> &v){
    int left =0;
    // (condition) ? (value_if_true) : (value_if_false)
    int right = v.empty() ? (-1) : (v[0].size()-1); //because it gives column and to check if matrix is empty
    int top=0;
    int bottom = v.size()-1;

    int direction =0;
    //Loop will run till Bottom >= Top or Right >= Left
    while(left<=right && top<=bottom){
        // left -> right 
        if (direction==0)
        {
           for (int col = left; col <= right; col++) //we are transversing through column
           {
                cout<<v[top][col]<<" ";
           }
           top++;
        }
        //top -> botttom
        else if (direction==1)
        {
            for(int row = top ; row <= bottom ; row++)
            {
                cout<<v[row][right]<<" ";
            }
            right--;
        }
        // right -> left
        else if (direction ==2)
        {
            for (int col = right; col >= left; col--)
            {
                cout<<v[bottom][col]<<" ";
            }
            bottom--;
        }
        //bottom -> top
        else
        {
            for (int row = bottom; row >= top; row--)
            {
                cout<<v[row][left]<<" ";
            }
            left++;
        }
        //Increase direction value but it should be 0,1,2,3
        direction = (direction+1)%4; //So, now value will not got more than 3
        
    }
    
    return;
}

int main(){
    int r,c;
    cout<<"Enter the size of rows : ";
    cin>>r;
    cout<<"Enter the size of column : ";
    cin>>c;
    cout<<"Enter the matrix : ";
    vector<vector<int>> v(r,vector <int> (c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>v[i][j];
        }
       
    }
    cout<<"Matrix you have entered is : "<<endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Spiral matrix is : ";
    spiralorder(v);
    return 0;
}
Output:-
Enter the size of rows : 3
Enter the size of column : 3
Enter the matrix : 1 2 3 4 5 6 7 8 9
Matrix you have entered is : 
1 2 3
4 5 6
7 8 9
Spiral matrix is : 1 2 3 6 9 8 7 4 5

Here's a little explanation in case you forget the logic :-

Here's a step-by-step explanation of the main logic implemented in the `spiralorder` function:

1. Initialize four variables: `left`, `right`, `top`, and `bottom` to define the boundaries of the current spiral loop.
   - `left` represents the leftmost column index of the untraversed part of the matrix.
   - `right` represents the rightmost column index of the untraversed part of the matrix.
   - `top` represents the topmost row index of the untraversed part of the matrix.
   - `bottom` represents the bottommost row index of the untraversed part of the matrix.

2. Initialize the `direction` variable to keep track of the current direction of traversal. It takes values 0, 1, 2, and 3 to represent 
the four directions: left to right, top to bottom, right to left, and bottom to top, respectively.

3. Run a loop as long as the boundaries do not cross each other, i.e., as long as `left` is less than or equal to `right` and `top` is 
less than or equal to `bottom`.

4. Inside the loop, use if-else conditions to decide the direction of traversal.

5. Four cases are considered for different directions:
   - `direction == 0`: Traverse from `left` to `right` along the top row (`v[top][col]`).
   - `direction == 1`: Traverse from `top` to `bottom` along the rightmost column (`v[row][right]`).
   - `direction == 2`: Traverse from `right` to `left` along the bottom row (`v[bottom][col]`).
   - `direction == 3`: Traverse from `bottom` to `top` along the leftmost column (`v[row][left]`).

6. After traversing a row or column, update the corresponding boundary (left, right, top, or bottom) to indicate that the row or column 
has been processed. For example, after traversing the top row (`direction == 0`), increment `top` to move to the next row.

7. Increment the `direction` variable by 1 and take its modulo 4 (`direction = (direction + 1) % 4`). This ensures that `direction` stays
 within the range 0 to 3, and the next traversal direction is set correctly.

8. The loop continues to traverse the matrix in a spiral manner until all elements are printed.

In summary, the main logic of the code uses boundary variables and direction tracking to traverse the 2D matrix in a spiral order, and it 
prints the elements in that order.
 The code takes care of different cases for square and rectangular matrices, and it ensures that the traversal covers all elements 
 without going out of bounds. 
 
-Given a +ve inetger 'n' , generate a n x n matrix filled with elements in spiral order from 1 to n^2 

#include<iostream>
#include<vector>
using namespace std;
void createSpiralMatrix(int n){
    vector<vector <int>> v(n,vector<int> (n));
    int left =0;
    int right = n-1;
    int top = 0;
    int bottom = n-1;
    int direction =0;
    int value =1;
    while (left<=right && top<=bottom)
    {
        if (direction==0)
        {
            for (int col = left; col <= right; col++)
            {
                v[top][col]=value++;
            }
            top++;
        }
        else if (direction ==1)
        {
            for (int row = top; row <= bottom; row++)
            {
                v[row][right]=value++;
            }
            right--;
        }
        else if (direction ==2)
        {
            for (int col = right; col >= left; col--)
            {
                v[bottom][col]=value++;
            }
            bottom--;
        }
        else
        {
            for (int row = bottom; row >= top; row--)
            {
                v[row][left]=value++;

            }
            left++;
        }
        direction = (direction+1)%4;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}

int main(){
    int r;
    cout<<"Enter the value of n : ";
    cin>>r;
    
    createSpiralMatrix(r);
    
    
    return 0;
}
Output :-
Enter the value of n : 3
1 2 3 
8 9 4
7 6 5          
 
 Explanation :-
 
The provided code generates a square spiral matrix of size `n` and then prints the matrix. The spiral matrix is a matrix in which the 
elements are filled in a spiral order, starting from the top-left corner and moving inwards towards the center in a clockwise direction.

Let's break down the logic of the code step by step:

1. The `createSpiralMatrix` function takes an integer `n` as input, which represents the size of the square matrix to be created.

2. Inside the function, a 2D vector `v` of size `n x n` is initialized with all elements set to 0. This matrix will be used to store 
the spiral order values.

3. Four variables `left`, `right`, `top`, and `bottom` are initialized to define the boundaries of the current spiral loop. These 
variables represent the indices of the leftmost, rightmost, topmost, and bottommost elements of the untraversed part of the matrix,
 respectively.

4. The `direction` variable is initialized to 0. It will be used to keep track of the current direction of traversal. The value
 of `direction` will be 0, 1, 2, or 3, representing the four directions: right, down, left, and up, respectively.

5. The `value` variable is initialized to 1. This variable will be used to fill the matrix with consecutive integers in the spiral order.

6. A while loop runs as long as the boundaries do not cross each other, i.e., as long as `left` is less than or equal to `right` 
and `top` is less than or equal to `bottom`. This loop is responsible for traversing the matrix in a spiral order and filling it with 
appropriate values.

7. Inside the loop, if-else conditions are used to decide the direction of traversal.

8. There are four cases for different directions:
   - `direction == 0`: Traverse from `left` to `right` along the top row and fill the matrix elements with consecutive 
      values (`v[top][col] = value++`).
   - `direction == 1`: Traverse from `top` to `bottom` along the rightmost column and fill the matrix elements with consecutive 
      values (`v[row][right] = value++`).
   - `direction == 2`: Traverse from `right` to `left` along the bottom row and fill the matrix elements with consecutive
      values (`v[bottom][col] = value++`).
   - `direction == 3`: Traverse from `bottom` to `top` along the leftmost column and fill the matrix elements with consecutive 
      values (`v[row][left] = value++`).

9. After traversing a row or column, the corresponding boundary (left, right, top, or bottom) is adjusted to indicate that the row or 
column has been processed.

10. The `direction` variable is incremented by 1 and taken modulo 4 (`direction = (direction + 1) % 4`). This ensures that `direction` 
stays within the range 0 to 3, and the next traversal direction is set correctly.

11. Once the while loop is complete, the matrix `v` is filled with elements in the spiral order.

12. Finally, the function prints the generated spiral matrix by iterating through the matrix using nested for loops.

In summary, the main logic of the code generates a square spiral matrix of size `n` and then prints the matrix. The matrix elements are 
filled in a spiral order, starting from the top-left corner and moving clockwise towards the center of the matrix. The code ensures that
 the matrix is printed correctly in a spiral even if `n` is 0 or negative.*/














