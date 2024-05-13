/*To print number of digits in a number
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the Number : "<<endl;
    cin>>n;
    m=0;
    while (n>0)            -> while se
    {
        m++;
        n=n/10;
    }
    for ( ; n>0; m++)      -> for se
    {
        n=n/10;
    }
    
    cout<<"The nummber of digits : "<<m;
    return 0;
}
-> To print sum of digits of number given
#include<iostream>
using namespace std;
int main(){
    int n,m,k;
    cout<<"Enter the number : "<<endl;
    cin>>n;
    m,k=0;
    while (n>0)
    {
        k=n%10;
        n=n/10;
        m=m+k;
    }
    cout<<"Sum = "<<m;
    return 0;
}
-> To print reverse of a number 
#include<iostream>
using namespace std;
int main(){
    int n,m,k;
    cout<<"Enter the number : ";
    cin>>n;
    m,k=0;
    cout<<"Reverse of the number : ";
    while (n>0)
    {
        k=n%10;
        cout<<k;
        n=n/10;
    }
    return 0;
}
--> by Mam's method
#include<iostream>
using namespace std;
int main(){
    int n,m,k;
    cout<<"Enter the number : ";
    cin>>n;
    m,k=0;
    while (n>0)
    {
        k=n%10;
        m=m*10+k;
        n=n/10;
        
    }
    cout<<"Reverse : "<<m;
    return 0;
}
->Sum of series where odd is added and even is subtracted 
#include <iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the value : ";
    cin>>n;
    m=0;
    for (int i = 1; i <= n; i++)
    {
        if (i%2==0)
        {
            m=m-i;
        }
        else{
            m=m+i;
        }
    }
    cout<<"Sum of Series : "<<m;
}
-> To print factorial of a number
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the  number : ";
    cin>>n;
    m=1;
    for (int i = n; i >= 1; i--)
    {
        m=m*i;
    }
    cout<<"Factorial : "<<m;
    return 0;
}
-> For systematic answer
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the  number : ";
    cin>>n;
    m=1;
    for (int i = 1; i <= n; i++)
    {
        m=m*i;
        cout<<m<<endl;
    }
    
    return 0;
}
-> a raise to power b
#include<iostream>
using namespace std;
int main(){
    int n,m,k;
    cout<<"Enter the base number : ";
    cin>>n;
    k=n;
    cout<<"Enter raise to power number : ";
    cin>>m;
    while (m>1)
    {
        k=k*n;
        m-=1;
    }
    cout<<k;
    return 0;
}*/













