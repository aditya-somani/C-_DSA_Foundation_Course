/*Array syntax
Datatype arrayname [Size];
or datatype arrayname[] = {1,2,3,4,5} // when we intilize a array , we don't need to specify its size

Memory allocation = Byte * size 
int,float -> 4 byte , char -> 1 byte , tuple -> 8 byte

Arrays ne 0 based indexing hoti he , just like python i.e. starting zero se
-> To access elements of a array -> arrayname[index]; 

sizeof() function tells us about how much size array occupies
similarily , length of array = bytes/sizeof(array)   
#include<iostream>
using namespace std;
int main(){
    int array[]={1,2,3,4,5};
    //cout<<sizeof(array)<<endl;      //output is 20
    //cout<<sizeof(array)/sizeof(array[0])<<endl;    // output is 5
    
    //Loops in array , if value is not assigned it will create garbage value
    int b= sizeof(array)/sizeof(array[0]);
    for(int i=0 ; i<b ; i++){       
        cout<<array[i]<<endl;
    }
    
    return 0;
}
-> For each loop -> isme it will transverse through every element of array
#include<iostream>
using namespace std;
int main(){
    int array[]={1,2,3,4,5};
    int size= sizeof(array)/sizeof(array[0]);
    for(int ele:array){
        cout<<ele<<endl;
    }
    return 0;
}
->while loop -> same as while loop (aata he muje)
#include<iostream>
using namespace std;
int main(){
    int array[]={1,2,3,4,5};
    int size= sizeof(array)/sizeof(array[0]);
    int index=0;
    while(index<size){
        cout<<array[index]<<endl;
        index++;
    }
    return 0;
}
-> Write a program to take input of vowels and ceate a array using it
#include<iostream>
using namespace std;
int main(){
    char vowel[5];
    cin>>vowel;
    for(int index=0 ; index < 5 ; index++){
        cout<<vowel[index]<<endl;
    }
    return 0;
}
To use for each loop in arrays you need to use '&' int it 

#include<iostream>
using namespace std;
int main(){
    char vowels[5];
    for(char &elements:vowels){
        cin>>elements;
    }
    for(int ind=0 ; ind<5 ; ind++){
        cout<<vowels[ind]<<endl;
    }
    return 0;
}
->Write a programm to cout sum of digits in a array
#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"Enter the no. of numbers you want to add : ";
    cin>>a;
    int* array;
    array = new int[a];
    cout<<"Enter the numbers you want to add : "<<endl;
    for (int i = 0; i < a; i++)
    {
     cin>>array[i];
    }
    int sum=0;
    for (int i = 0; i < a; i++)
    {
        sum+=array[i];
    }
    cout<<"Sum : "<<sum;
    delete array;
    return 0;
    
}
-> Write a prgram to print max element of the array
#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the size of array ";
    cin>>a;
    int* array;
    array = new int[a];
    for (int i = 0; i < a; i++)
    {
        cin>>array[i];
    }
    b= array[0];
    for (int i = 1; i < a; i++)
    {
        
        if (array[i]>b)
        {
            b = array[i];
        }  
    }
    cout<<b;
    delete array;
    return 0;   
}
-> Write a programm to search if the number exist in the array and give its location
#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the size of array : ";
    cin>>a;
    int* array;
    array = new int[a];
    for (int i = 0; i < a; i++)
    {
        cin>>array[i];
    }
    cout<<"Enter the number you want to search : ";
    cin>>b;
    bool c = false;
    for (int i = 0; i < a; i++)
    {
        if (array[i]==b)
        {
            cout<<"Yes "<<b<<" lies at index "<<i<<endl;
            c=true;
            break;
        }
       
    }
    //if(c == false){
    //    cout<<"-1";
    //}
    delete array;
    return 0;
}
Alternate way to this question is : 
#include<iostream>
using namespace std;
int main(){
    int a,key;
    int* array;
    cout<<"Enter the size of array : ";
    cin>>a;
    array = new int[a];
    cout<<"Enter the array : ";
    for (int i = 0; i < a; i++)
    {
        cin>>array[i];
    }
    cout<<"Enter the key you want to search : ";
    cin>>key;
    int b=-1;
    for (int i = 0; i < a; i++)
    {
        if (array[i]==key){
            b=i;
            break;     // to make the loop run faster
        }
    }
    cout<<"Position of "<<key<<" is index "<<b;
    delete array;
    return 0;
}*/






