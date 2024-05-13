/* -> To print rectangular pattern
#include<iostream>
using namespace std;
int main(){
    char a;
    cout<<"Enter the character you want in rectangular pattern : "<<endl;
    cin>>a;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 6; i++)
        {
        cout<<a;
        }
    cout<<endl;
    }
    
    return 0;

} 

-> This time input no. of rows and columns and create pattern based on it 
#include<iostream>
using namespace std;
int main(){
    int n,m;
    char a;
    cout<<"Enter the pattern : "<<endl;
    cin>>a;
    cout<<"Number of rows : "<<endl;
    cin>>n;
    cout<<"Number of columns : "<<endl;
    cin>>m;
    cout<<"The pattern is : "<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<a;
        }
        cout<<endl;
    }
    return 0;
} 

-> To print a hollow rectangle (It took quite a lot of time #Learn_from_Mistake)
#include<iostream>
using namespace std;
int main(){
    int n,m;
    char a;
    cout<<"Enter the pattern : "<<endl;
    cin>>a;
    cout<<"Number of rows : "<<endl;
    cin>>n;
    cout<<"Number of columns : "<<endl;
    cin>>m;
    cout<<"The pattern is : "<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i==1 || j==1 || i==n || j==m )
            {
                cout<<a;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}

-> Right sided Traingular shaped pattern printing
#include <iostream>
using namespace std;
int main(){
    int n;
    char a;
    cout<<"Enter the pattern : "<<endl;
    cin>>a;
    cout<<"Number of rows : "<<endl;
    cin>>n;
    cout<<"The pattern is : "<<endl;
    for (int i = 1; i <= n; i++)
    {
        
        for (int m = 1; m <= i; m++)
        {
            cout<<a;
        }
        cout<<endl;   
    }
    return 0;
}

-> Right sided Reverse Traingular Pattern
#include <iostream>
using namespace std;
int main(){
    int n,m;
    char a;
    cout<<"Enter the pattern : "<<endl;
    cin>>a;
    cout<<"Number of rows : "<<endl;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i ; j--)
        {
            cout<<a;
        }
        cout<<endl;
    }
    return 0;

}

-> Traingular Shaped Pattern Printing #OP QUESTION 
#include<iostream>
using namespace std;
int main(){
    int n;
    char a;
    cout<<"Enter the pattern : "<<endl;
    cin>>a;
    cout<<"Number of rows : "<<endl;
    cin>>n;
    cout<<"The pattern is : "<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n-i); j++)
        {
            cout<<" ";
        }
        for (int k = 1; k <= (2*i-1) ; k++)
        {
            cout<<a;
        }
        cout<<endl;
    }
    return 0;
}
-> Numerical Rectangular Pattern #First_Time_me_SAHI!!
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Number of rows : "<<endl;
    cin>>n;
    cout<<"The pattern is : "<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            m=j+i-1;
            if (m>n)
            {
                cout<<m%n;
            }
            else{
                cout<<m;
            }
        }
        cout<<endl;
    }
    return 0;
}
->Numerical rectangular pattern
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Number of rows : "<<endl;
    cin>>n;
    cout<<"The pattern is : "<<endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <=n ; j++)
        {
            cout<<j;
        }
        cout<<endl;
    }
    return 0;
}
-> Hollow rectangular Pattern
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Number of rows : "<<endl;
    cin>>n;
    cout<<"The pattern is : "<<endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <=n ; j++)
        {
            if (i==1 || j==1 || i==n || j==n){
                cout<<j;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
 -> 1-2-1-2 Pattern Question
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Number of rows : "<<endl;
    cin>>n;
    cout<<"Number of columns : "<<endl;
    cin>>m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if ((i%2==0 && j%2==1) || (i%2==1 && j%2==0))
            {
                cout<<"2";
            }
            else{
                cout<<"1";
            }
            
        }
        cout<<endl;
    }
    return 0;
}
-> Another way of doing this question is
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Number of rows : "<<endl;
    cin>>n;
    cout<<"Number of columns : "<<endl;
    cin>>m;
    for(int i=1 ; i<=n ; i++){
        for(int j=1; j<=m ; j++){
            if ((i+j)%2==0){
                cout<<"1";
            }
            else{
                cout<<"2";
            }
        }
        cout<<endl;
    }
    return 0;
}
-> Numerical Traingular Pattern
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Number of rows : "<<endl;
    cin>>n;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=i ; j++){
            cout<<j;
        }
        cout<<endl;
    }
    return 0;
}
-> to Print ->
                       1
                      121
                     12321
                    1234321       
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Number of rows : "<<endl;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n-i); j++)
        {
            cout<<" ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout<<j;
        }
        for (int j = (i-1); j >= 1; j--)
        {
            cout<<j;
        }
        
        cout<<endl;
    }
    return 0;
}
-> Nahi aya!!
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Number of rows : "<<endl;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n-i); j++)
        {
            cout<<" ";
        }
    
 
        }

        cout<<endl;
    }
    return 0;
}*/













