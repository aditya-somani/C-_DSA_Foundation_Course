/*

-Solved some really good questions related to recursions and the last one was just amazing
do make sure to try it once more when you get time!!

For two numbers x and y, find the GCD/HCF using recursion or iteration

-Through iteration

#include <iostream>
#include <vector>
using namespace std;

int findHCF(int n, int m) {
    int smaller = (n < m) ? n : m;
    int hcf = 1;

    for (int i = 1; i <= smaller; i++) {
        if (n % i == 0 && m % i == 0) {
            hcf = i;
        }
    }

    return hcf;
}

int main() {
    int n, m;
    cout << "Enter the first number: ";
    cin >> n;
    cout << "Enter the second number: ";
    cin >> m;

    int hcf = findHCF(n, m);

    cout << "HCF is: " << hcf << endl;
    return 0;
}

Output:-
Enter the first number: 44
Enter the second number: 100
HCF is: 4

-Using Recursion

#include<iostream>
using namespace std;
int findHcf(int a,int b){
    if(b>a) return findHcf(b,a);
    //base-case
    if (b==0)
    {
        return a;
    }
    return findHcf(b,a%b);

}
int main(){
    int a,b;
    cout<<"Enter the first number : ";
    cin>>a;
    cout<<"Enter the second number : ";
    cin>>b;
    cout<<"HCF is : "<<findHcf(a,b);
    
    return 0;
}

Output:-
Enter the first number : 20  
Enter the second number : 24
HCF is : 4

-For a number n, check and print whether it is an Armstrong number or not 
#include<iostream>
#include<cmath>
using namespace std;
int arms(int n, int d){
    //base-case
    if (n==0)
    {
        return 0;
    }
    return arms(n/10,d)+(int) pow(n%10,d);
}
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    int d=0,a=n;
    while (a>0)
    {
        d++;
        a/=10;
    }
    int b = arms(n,d);
    if (n==b)
    {
        cout<<"Yes "<<n<<" it is Armstrong number ";
    }
    else{
        cout<<"No it is not Armstrong number ";
    }
    return 0;
}

Output:-
Enter the number : 548834
Yes 548834 it is Armstrong number 

There are N stones, numbered For each i (IsiSN), the height of Stone i is hi.There
is a frog who is initially on Stone 1. He will repeat the following action some number of
times to reach Stone N:
If the frog is currently on Stone i, jump to Stone i+l or Stone i+2. Here, a cost of |(hi - hj)|
is incurred, where j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone N.


#include<iostream>
using namespace std;
int f(int *h, int n, int i){  //ye 'int *h' is same is 'int &h[]' 
    //base case
    if(i==n-1) return 0;
    if(i==n-2) return f(h,n,i+1)+abs(h[i]-h[i+1]);
    return min(f(h,n,i+1)+abs(h[i]-h[i+1]),f(h,n,i+2)+abs(h[i]-h[i+2]));
}
int main(){
    int n;
    cout<<"Enter the height of array : ";
    cin>>n;
    cout<<"Enter the array : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Minimum lose is : "<<f(arr,n,0);
    return 0;

}

Output:-
Enter the height of array : 5
Enter the array : 10 30 40 30 50
Minimum lose is : 40

*/







