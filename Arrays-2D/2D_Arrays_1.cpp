/*
So in this we learned about 2D arrays -=> mostly matrices  

Array -> group of homogenous items
-contiguous memory allocation (Rest syntax i know or do a recap)
->In this we are gonna learn about multidimensional array -> they are arrays of arrays
    datatype array_name[row][column] -> for 2-D array
    ex- int array[4][3] -> 4 rows and 3 columns
Same zero based indexing as in array or vector 
To intialize -> int array[2][3]={1,2,3,4,5};       ex:-     array[0][0]   array[0][1]   array[0][2]
            or  int array[2][3]={{1,2,3},{4,5,6}}           array[1][0]   array[1][1]   array[1][2]
               
      
For 3-D arrays -> 3*2*4 (Not so imp but yeah do read it)
        ->    3 2D arrays of 2*4 -> to visualize it
Basic structure :-

array[0][0][0]   array[0][0][1]   array[0][0][2]   array[0][0][3]
array[0][1][0]   array[0][1][1]   array[0][1][2]   array[0][1][3]
array[0][2][0]   array[0][2][1]   array[0][2][2]   array[0][2][3]

array[1][0][0]   array[1][0][1]   array[1][0][2]   array[1][0][3]
array[1][1][0]   array[1][1][1]   array[1][1][2]   array[1][1][3]
array[1][2][0]   array[1][2][1]   array[1][2][2]   array[1][2][3]

Now to take input in 2D array:-
for (int i = 0; i < row; i++)
{
    for (int j = 0; j < column; j++)
    {
        cin>>array[i][j];  // and for output same but just use cout
    }
    
}
->What/Why are multidem. used for -> 1. Representing grids
 2. faster access 
 3. Predefined size

->Write a code to display multiplication of two matrices
->The main logic of this code I copied from GPT , so in revision use your brain before looking for solution 
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the dimensions of first matrices : ";
    cin>>a>>b;
    int c,d;
    cout<<"Enter the dimensions of second matrices : ";
    cin>>c>>d;
    bool m=false;
    if (b==c)
    {
        m=true;
    }
    int mone[a][b];
    int msec[c][d];
    if (m==true)
    {
        cout<<"Enter the elements of first matrice : ";
        
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                cin>>mone[i][j];
            }
            
        }
        cout<<"Enter the elements of second matrice : ";
        
        for (int i = 0; i < c; i++)
        {
            for (int j = 0; j < d; j++)
            {
                cin>>msec[i][j];
            }
        }
    }
    if (m==false)
    {
        cout<<"Multiplication of matrices not possible ";
    }
    int mans[a][d];
    
    if (m==true)
    {
        cout<<"Multiplication of matrices of order "<<a<<" X "<<d<<" is : "<<endl;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < d; j++)
            {
                mans[i][j]=0;
                for (int k = 0; k < c; k++)
                {
                    mans[i][j]+=mone[i][k]*msec[k][j];
                }
                cout<<mans[i][j]<<" ";
                
            }   
            cout<<endl;
        }  
    }  
    return 0;
}
Output:-
Enter the dimensions of first matrices : 3 3
Enter the dimensions of second matrices : 3 2
Enter the elements of first matrice : 1 2 3 0 2 1 1 2 5
Enter the elements of second matrice : 1 0 0 1 2 1
Multiplication of matrices of order 3 X 2 is : 
7 5
2 3
11 7 
->To display transpose of the matrix displayed by the user
#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the dimensions of matrix : ";
    cin>>a>>b;
    int arr[a][b];
    cout<<"Enter the matrix elements : ";
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    cout<<"Transpose of matrix is: "<<endl;
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
        {
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
    
}
Output:-
Enter the dimensions of matrix : 3 2
Enter the matrix elements : 1 1 2 2 3 3
Transpose of matrix is: 
1 2 3
1 2 3 */









