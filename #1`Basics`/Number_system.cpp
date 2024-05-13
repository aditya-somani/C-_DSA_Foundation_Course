/*
Number system :-
1. Decimal NS - Base 10 , (0 to 9) * (10 raise to power)
-like 7234 =  7*10^3 + 2*10^2 + 3*10^1 + 4*10^0

2. Binary NS - base power 2 , (0 and 1) * (2 raise to power no. of digits after it)
-like 10010 = 1*(2^4) + 0*(2^3) + 0*(2^2) + 1*(2^1) + 0*(2^0)

3. (Extra) Hexa decimal - base power 16 , 10 - A , 11 - B , 12 - C , 13- D , 14- E , 15 -F , 16- D
like - 4A5C = 4* (16^3) + 10 * ( 16^ 2) + 5*(16^1) + 12*(16^0)

Now write a program to take Binary and convert it into Decimal 

#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,m,a,i,b,c;
    cout<<"Enter the Boolean number : ";
    cin>>n;
    c=n;
    a=0,i=0,m=0;
    while (n>0){
        m=n%10;
        n=n/10;
        double b = pow(2,i);
        a=a+(m*b);
        i++;
    }
    cout<<"Value in decimal of "<<c<<" is : "<<a;
    return 0;
    
}
-> In case I don't want to use pow() function
#include <iostream>
using namespace std;
int main(){
    int n,m=0;
    cout<<"Enter the number in Binary : ";
    cin>>n;
    int lastdigit = 0;
    int power=1;
    while(n>0){
        int lastdigit = n%10;
        m=m+(lastdigit*power);
        power = power*2;
        n=n/10;
    }
    cout<<m;
    return 0;

}

To convert from decimal to binary -> we divide that number by two and then write the remainder
in reverse order
 ex- 5 -> 5/2 = 2 with rem = 1
          2/2 = 1 with rem = 0
          1/2 = 0 with rem = 1
          there fore -> 5 = 101
          
Writing a prgram to convert deccimal into binary
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter number : ";
    cin>>n;
    int a=0,b=0;
    int power =1;
    while(n>0){
        a=n%2;
        b=b+a*power;
        power = power*10;
        n=n/2;
    }
    cout<<b;
    return 0;
}*/
















