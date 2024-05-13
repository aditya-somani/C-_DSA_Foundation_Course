/* Type conversion Demo -> it converts number into character using ascii and vice versa
#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    a=98;
    char n = (char)a;     // here it converts integers into variable
    cout<<n;
    int x = (int)b;       // here it gives ascii of variable b
    return 0;
}

- To print diamond shaped pattern
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
}*/







