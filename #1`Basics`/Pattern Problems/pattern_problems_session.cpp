/*- To print diamond shaped pattern
    B
   CCC
  DDDDD
 EEEEEEE
FFFFFFFFF
 EEEEEEE
  DDDDD
   CCC
    B

#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of rows : ";
    cin>>n;
    for (int i = 1; i <= 5; i++)   // This is loop for upper traingle
    {
        for (int j = 1; j <= (n-i); j++)  // loop for spaces of upper traingle
        {
            cout<<" ";
        }
        for (int k = 0; k < (2*i-1) ; k++)   //loop for taingular pattern
        {
            cout<<(char)('A'+i);    // syntax for alphabets
        }
        cout<<endl;    // to cchange lines
        
        
    }
    for (int a = n-1; a >= 1; a--)  // loop for lower traingle 
    {
        for (int b = 1; b <= n-a ; b++)   // loop for spaces of lower traingular
        {
            cout<<" ";
        }
        for (int c = 1; c <= (2*a-1); c++)  // loop for variables in lower traingular
        {
            cout<<(char)('A'+a);    // character conversions
        }
        cout<<endl;
        
    }
    return 0;
}

- To print diamond shaped pattern ->

    A
   ABC
  ABCDE
 ABCDEFG
ABCDEFGHI
 ABCDEFG
  ABCDE
   ABC
    A


#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of rows : ";
    cin>>n;
    for (int i = 1; i <= n; i++)   // This is loop for upper traingle
    {
        for (int j = 1; j <= (n-i); j++)  // loop for spaces of upper traingle
        {
            cout<<" ";
        }
        for (int k = 0; k < (2*i-1) ; k++)   //loop for taingular pattern
        {
            cout<<(char)('A'+k);    // syntax for alphabets
        }
        cout<<endl;    // to cchange lines
        
        
    }
    for (int a = n-1; a >= 1; a--)  // loop for lower traingle 
    {
        for (int b = 1; b <= n-a ; b++)   // loop for spaces of lower traingular
        {
            cout<<" ";
        }
        for (int c = 0; c < (2*a-1); c++)  // loop for variables in lower traingular
        {
            cout<<(char)('A'+c);    // character conversions
        }
        cout<<endl;
        
    }
    return 0;
}

- To print Plus pattern ->

   +   
   +
   +
+++++++
   +
   +
   +


#include<iostream>
using namespace std;
int main(){
    int a,c;
    char b;
    cout<<"Enter a odd number : ";
    cin>>a;
    cout<<"Enter the pattern : ";
    cin>>b;
    c=(a/2)+1;
    for (int i = 1 ; i <= a ; i++){
        for (int j =1 ; j<= a ; j++){
            if (i==c || j==c){
                cout<<b;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
-> A rectangular pattern

#include<iostream>
using namespace std;
int main(){
    int n,m;
    char a;
    cout<<"Enter no. of rows : ";
    cin>>n;
    cout<<"Enter the no. of columns : ";
    cin>>m;
    cout<<"enter pattern : ";
    cin>>a;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout<<a;
        }
        cout<<endl;
    }
    return 0;
}*/

















