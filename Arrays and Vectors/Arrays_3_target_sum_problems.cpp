/*This file includes question related to Target Sum , Array manipulation , Rotation , Queries (Frequency Array related)
->There are multiple ways of doing a question .
->few question have been shown with different methods make sure to read all of them!

Write a prgramm to print no. of pairs possible which can be expressed as sum of 'x' 
-> In this prgramm , I am allowing (1,4) and (4,1) as two different pairs

#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"Enter the size of array : ";
    cin>>a;
    cout<<"Enter Array : ";
    int v[a];
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    int b;
    cout<<"Enter the number whose sum pairs you want to find : ";
    cin>>b;
    int num=0;
    cout<<"Pairs are : "<<endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = a-1; j>=0 ; j--)
        {
            if ((v[i]+v[j])==b)
            {
                num++;
                cout<<v[i]<<" , "<<v[j]<<endl;
            } 
        }  
    }
    cout<<"Number of pairs is : "<<num;
    return 0;  
}
Output:-
Enter the size of array : 5
Enter Array : -100 100 55 -55 0
Enter the number whose sum pairs you want to find : 55
Pairs are : 
55 , 0
0 , 55
Number of pairs is : 2
Write a prgramm to print no. of pairs possible which can be expressed as sum of 'x' 
-> In this prgramm , I am allowing (1,4) and (4,1) as two same pairs
#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"Enter the size of array : ";
    cin>>a;
    cout<<"Enter Array : ";
    int v[a];
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    int b;
    cout<<"Enter the number whose sum pairs you want to find : ";
    cin>>b;
    int num=0;
    cout<<"Pairs are : "<<endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = i+1; j < a; j++)
        {
            if ((v[i]+v[j])==b)
            {
                num++;
                cout<<v[i]<<" , "<<v[j]<<endl;
            }   
        }    
    }
    cout<<"Number of pairs are : "<<num;
    return 0;
}
Output:-
Enter the size of array : 5
Enter Array : 1 2 3 4 5
Enter the number whose sum pairs you want to find : 5
Pairs are : 
1 , 4
2 , 3
Number of pairs are : 2
->Write code to print triplets as sum of number 'x' 
#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"Enter the size of array : ";
    cin>>a;
    cout<<"Enter Array : ";
    int v[a];
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    int b;
    cout<<"Enter the number whose sum Triplets you want to find : ";
    cin>>b;
    int num=0;
    cout<<"Triplets are : "<<endl;
    for (int i = 0; i < a-2; i++)
    {
        for (int j = i+1; j < a-1; j++)
        {
            for (int k = j+1; k < a; k++)
            {
                if ((v[i]+v[j]+v[k])==b)
                {
                    num++;
                    cout<<v[i]<<" , "<<v[j]<<" , "<<v[k]<<endl;
                } 
            }
              
        }    
    }
    cout<<"Number of Triplets are : "<<num;
    return 0;
}
Output:-
Enter the size of array : 7
Enter Array : 1 2 3 4 0 6 3
Enter the number whose sum pairs you want to find : 7
Pairs are : 
1 , 2 , 4
1 , 3 , 3
1 , 0 , 6
3 , 4 , 0
4 , 0 , 3
Number of pairs are : 5
->To find a unique number in array where all number are repeated twice but it is repeated once
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a;
    cout<<"Enter the size of vector : ";
    cin>>a;
    vector <int> v(a);
    cout<<"Enter the vector : ";
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    int c=-1;
    for (int i = 0; i < a; i++)
    {
        for (int j = i+1; j < a; j++)
        {
            if (v[i]==v[j])
            {
                v[i]=v[j]=-1;   
            } 
        }   
    }
    cout<<"Unique number which only comes one is : ";
    for (int i = 0; i < a; i++)
    {
        if (v[i]>0)
        {
            cout<<v[i]<<" ";
        }  
    }
    return 0;  
}
Output:-
Enter the size of vector : 7
Enter the vector : 1 2 3 4 5 1 2
Unique number which only comes one is : 3 4 5 

->Write a code to print ascending and decending order  (OOPP!! QUESTION!! HATS OFF!!)
#include<iostream>
using namespace std;
void cussort(int arr[] , int size , bool asc){
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j< size-i-1; j++)  // Here was something new as i took size of 0 to size-i-1;
        {
            if (asc)
            {
                if (arr[j]>arr[j+1])
                {
                    int temp;
                    temp= arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]= temp;
                }
            }
            else if(!asc){
                if (arr[j]<arr[j+1])
                {
                    int temp;
                    temp = arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
                
            }
            
        }
        
    }
    
}
int main(){
    int a;
    cout<<"Enter the size of array : ";
    cin>>a;
    int array[a];
    cout<<"Enter Array : ";
    for (int i = 0; i < a; i++)
    {
        cin>>array[i];
    }
    bool ascen;
    cout<<"Sort form -> ascending = true , Decending = false : ";
    cin>>boolalpha>>ascen;
    cussort(array,a,ascen);
    cout<<"Sorted array : ";
    for (int i = 0; i < a; i++)
    {
        cout<<array[i]<<" ";
    }
    
    return 0;
}
Output:-
Enter the size of array : 7
Enter Array : 100 5 4 99 10000 -88 0
Sort form -> ascending = true , Decending = false : true
Sorted array : -88 0 4 5 99 100 10000 

Enter the size of array : 7
Enter Array : 100 5 4 99 10000 -88 0
Sort form -> ascending = true , Decending = false : false
Sorted array : 10000 100 99 5 4 0 -88 

-> Write a prgram to print second largest number in the array (My way!!)
//The problem in this code is that , I can't put in duplicate numbers of the largest , so solving it!!
#include<iostream>
using namespace std;
void asc(int arr[] , int size ){
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            
        }
        
    }
    
}
int main(){
    int a;
    cout<<"Enter the size of array : ";
    cin>>a;
    int array[a];
    cout<<"Enter array : ";
    for (int i = 0; i < a; i++)
    {
        cin>>array[i];
    }
    asc(array,a);
    cout<<"Second largest number in array is : "<<array[a-2];
    return 0;
    
}
Output:-
Enter the size of array : 5
Enter array : -100 -383 -4 -5 -090
Second largest number in array is : -5

-> Write a prgram to print second largest number in the array (Mam's way!! )
#include <iostream>
using namespace std;

void asc(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int a;
    cout << "Enter the size of the array: ";
    cin >> a;
    int array[a];
    cout << "Enter the array elements: ";
    for (int i = 0; i < a; i++) {
        cin >> array[i];
    }
    asc(array, a);

    int largest= array[a-1];
    int secondlargest = array[a-1];
    for (int i = a-2; i >=0; i--)
    {
        if (array[i]!=largest)
        {
            secondlargest= array[i];
            break;
        }
        
    }
    

    cout << "Second largest number in the array is: " << secondlargest << endl;
    return 0;
}
Output:-
Enter the size of the array: 7
Enter the array elements: 11 22 11 22 -99 99 99
Second largest number in the array is: 22
->Another way of doing this question! Most easiest one!!
#include<iostream>
using namespace std;
int secondlargest(int array[] , int size){
    int max= INT_MIN;
    int secondmax= INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (array[i]>max)
        {
            max=array[i];
        }
        
    }
    for (int i = 0; i < size; i++)
    {
        if (array[i]>secondmax && array[i]!=max)
        {
            secondmax=array[i];
        }
        
    }
    return secondmax;  
}
int main(){
    int a;
    cout<<"Enter the size of array : ";
    cin>>a;
    cout<<"Enter Array : ";
    int arr[a];
    for (int i = 0; i < a; i++)
    {
        cin>>arr[i];
    }
    cout<<"Second Largest element is : "<<secondlargest(arr,a);
    return 0;
    
}
Output:-
Enter the size of array : 7
Enter Array : 11 22 7 22 9 -100 0
Second Largest element is : 11
->Write a prgramm to rotate the given array by 'K' steps
#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"Enter the size of array : ";
    cin>>a;
    int array[a];
    for (int i = 0; i < a; i++)
    {
        cin>>array[i];
    }
    cout<<"Enter the number of steps you want to rotate(left) : ";
    int k;
    cin>>k;
    cout<<"Array : ";
    for (int i = 0; i < a; i++)
    {
        int b=i+k;
        if (b>=a)
        {
            b=(i+k)%a;
        }
        cout<<array[b]<<" ";
        
    }
    return 0;
    
}

#include<iostream>
using namespace std;
int rotate(int array[] , int size , int steps , bool left){
    int b;
    for (int i = 0; i < size; i++)
    {
        if (left)
        {
            b=i+steps;
            if (b>=size)
            {
                b=(i+steps)%size;
            }
            array[i]=array[b];
            
            
        }
        else{
            b=(i+steps)%size;
            if ((i+steps)>=size)
            {
                b=i+steps-size;
            }
            array[size]=array[b];
            
            
        }
        
    }
    return array[0];
    
}
int main(){
    int a;
    cout<<"Enter the size : ";
    cin>>a;
    cout<<"Enter the vector : ";
    int arr[a];
    for (int i = 0; i < a; i++)
    {
        cin>>arr[i];
    }
    int b;
    cout<<"Enter steps you want to rotate : ";
    cin>>b;
    bool lefte;
    cout<<"Enter direction left = true , right = false : ";
    cin>>boolalpha>>lefte;
    int c[a];
    cout<<(arr , a , b , lefte);
    
    
    
    
    return 0;
}

**NOTE:- I DIDN'T UNDERSTOOD THIS CODE!! , WILL NEED REVISION!!**


#include <iostream>
using namespace std;

void rotate(int array[], int size, int steps, bool left) {
    if (left) {
        steps = steps % size; // Ensure steps are within the array size
        for (int i = 0; i < steps; i++) {
            int temp = array[0]; // Store the first element
            for (int j = 0; j < size - 1; j++) {
                array[j] = array[j + 1]; // Shift elements to the left
            }
            array[size - 1] = temp; // Move the first element to the last
        }
    } else {
        steps = steps % size; // Ensure steps are within the array size
        for (int i = 0; i < steps; i++) {
            int temp = array[size - 1]; // Store the last element
            for (int j = size - 1; j > 0; j--) {
                array[j] = array[j - 1]; // Shift elements to the right
            }
            array[0] = temp; // Move the last element to the first
        }
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter the elements of the array: ";
    int array[size];
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    int steps;
    cout << "Enter the number of steps to rotate: ";
    cin >> steps;

    bool isLeft;
    cout << "Enter the rotation direction (left = true, right = false): ";
    cin >> boolalpha >> isLeft;

    rotate(array, size, steps, isLeft);

    cout << "Rotated array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    return 0;
}
Output:-
Enter the size of the array: 5
Enter the elements of the array: 1 2 3 4 5
Enter the number of steps to rotate: 3
Enter the rotation direction (left = true, right = false): false
Rotated array: 3 4 5 1 2 

->Now comes the easy way to it!!
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int a;
    cout<<"Enter the size of vector : ";
    cin>>a;
    vector <int> v(a);
    cout<<"Enter the vector : ";
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    int b;
    cout<<"Enter the number of steps : ";
    cin>>b;
    b=b%a;
    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin()+b);
    reverse(v.begin()+b,v.end());
    cout<<"Vector is : ";
    for (int i = 0; i < a; i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
    
    
}
->This is not written by me, i needd to understand it once again!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotatesd(vector<int>& vect, int size, int steps, bool left) {
    steps=steps%size;

    if (left) {
        reverse(vect.begin(), vect.end());
        reverse(vect.begin(), vect.begin() + steps);
        reverse(vect.begin() + steps, vect.end());
    } else {
        reverse(vect.begin(), vect.end());
        reverse(vect.end() - steps, vect.end());
        reverse(vect.begin(), vect.end() - steps);
    }
}

int main() {
    int a;
    cout << "Enter the size of vector: ";
    cin >> a;

    vector<int> v(a);
    cout << "Enter the vector: ";
    for (int i = 0; i < a; i++) {
        cin >> v[i];
    }

    int b;
    cout << "Enter the number of steps: ";
    cin >> b;

    bool le;
    cout << "Enter direction of rotation (Left = true, Right = false): ";
    cin >> boolalpha >> le;

    rotatesd(v, a, b, le);

    cout << "Vector is: ";
    for (int i = 0; i < a; i++) {
        cout << v[i] << " ";
    }

    return 0;
}
output:-
Enter the size of vector: 5
Enter the vector: 1 2 3 4 5
Enter the number of steps: 2
Enter direction of rotation (Left = true, Right = false): true
Vector is: 4 5 1 2 3 

Enter the size of vector: 5
Enter the vector: 1 2 3 4 5 
Enter the number of steps: 2 
Enter direction of rotation (Left = true, Right = false): false
Vector is: 3 4 5 1 2 
->Write a prgramm to check if that element is present in array or not 
->This question was really a unique one! Make sure to solve it one more time and pay attention when doing revision
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a;
    cout<<"Enter the size of vector : ";
    cin>>a;
    vector <int> v(a);
    cout<<"Enter the vector: ";
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    int q;
    cout<<"Enter Queries : ";
    cin>>q;
    const int n= 1e5+10 ;
    vector<int> freq(n,0);
    for (int i = 0; i < a; i++)
    {
        freq[v[i]]++;
    }
    while (q>0)
    {
        cout<<"Query element : ";
        int qe;
        cin>>qe;
        cout<<"Number of times element "<<qe<<" has been repeated is : "<<freq[qe]<<endl;
        q--;
    }
    return 0;   
}
Output:-
Enter the size of vector : 7
Enter the vector: 1 1 2 33 3 5 1
Enter Queries : 4
Query element : 1
Number of times element 1 has been repeated is : 3
Query element : 4
Number of times element 4 has been repeated is : 0
Query element : 33
Number of times element 33 has been repeated is : 1
Query element : 0
Number of times element 0 has been repeated is : 0

HAVE A NICE DAY!*/
















