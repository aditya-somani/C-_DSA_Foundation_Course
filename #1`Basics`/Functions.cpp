/*Functions are set of code which can be both built in and user defined

Systax for functions!

returntype functionname(para 1 , para 2,...){
    ...||code||...
    return variable ;
}

-> Write a prgram to define a funtion to add two no. 

#include<iostream>
using namespace std;

int add(int num1 , int num2){
    int sum = num1+num2;
    return sum;
}
int main(){
    int a,b;
    cout<<"Enter the first num : "<<endl;
    cin>>a;
    cout<<"Enter the second num : "<<endl;
    cin>>b;
    cout<<"Sum is"<<add(a,b)<<endl;
    return 0;
}

-> For multiple functions
#include<iostream>
using namespace std;

int add(int n1 , int n2){
    int sum = n1+n2;
    return sum;
}
int add(int n1 , int n2 , int n3){
    int sum = n1+n2+n3;
    return sum;
}
float add(float n1 , float n2){
    float sum = n1+n2;
    return sum;
}
int main(){
    float a,b;
    cout<<"Enter the first num : "<<endl;
    cin>>a;
    cout<<"Enter the second num : "<<endl;
    cin>>b;
    cout<<"Sum is "<<add(a,b)<<endl;
    return 0;
}
-> If you want to define function after int main() 
Then you will use prototype function like -> int add(int , int)
then int main() and then after it define the function add()

-Now about built in function
If you want to use pow(a,b) or sqrt(a) then first you need to include <cmath> 

#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the base num : "<<endl;
    cin>>a;
    cout<<"Enter the raise to power num : "<<endl;
    cin>>b;
    cout<<a<<" raise to power "<<b<<" is "<<pow(a,b)<<endl;
    cout<<"Square root of "<<a<<" is "<<sqrt(a);
    return 0;
}
Now there is case if you want to print int value or in decimals , for
decimals double is use like int double a = pow(c,d); 
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a,b;
    //cout<<"Enter the base num : "<<endl;
    //cin>>a;
    //cout<<"Enter the raise to power num : "<<endl;
    //cin>>b;
    //cout<<a<<" raise to power "<<b<<" is "<<pow(a,b)<<endl;
    //cout<<"Square root of "<<a<<" is "<<sqrt(a);
    
    double ans= sqrt(24);
    int ab = sqrt(24);
    cout<<ans<<endl;
    cout<<ab;
    return 0;
}

-> Agar void likh diya to return wala statement nahi likna 
void sim(int x , int y){
    cout<<(x+y)
}
int main(){
    int p=10;
    sum(p,32);  -> output will be 42

}

-> Scope of variable!
1. Local variable -> joki confined hota {} me.
2. Global variable -> ye {} ke bhar aata he 

#include <iostream>
using namespace std;
int p=5;  // Global variable
int main(){
    int p=4;  //Local variable -> Local > Global 
    cout<<p<<endl; // Output -> 4
    //Now if I want to access global variable in {} then I will use Scope resolution " :: "
    cout<<::p;  // Output -> 5
    return 0;
}

-> Formal parameters -> para which get defined at the time a definition
-> Actual parameters -> Are para which get define during call of function 
int print(int a ,  int b){          // formal para
    cout<<a,b;
}  
int main(){
    int p=4,q=5;
    print(a,b); // ACtual parameters
}

-> Pass by Value me copy create ho jati he and you can't change the value
-> Pass by Reference me both have same memory allocation/place so , value is changable

#include<iostream>
using namespace std;
void changevalue(int z){     // Pass by Value
    z=100;
}
int main(){
    int a=5;
    changevalue(a);
    cout<<a;      //Output is 5 -> I.E. Value of a did not change
    return 0;
}
#include<iostream>
using namespace std;
void chnagevalue(int &z){       // & -> operator represents amberson i.e. pass by referenece 
    z=100;                           // , also used to find memory allocation
    cout<<&z<<endl;
}
int main(){
    int a=5;
    chnagevalue(a);
    cout<<a<<endl;           // output is 100 -> I.E. Value of 'a' changed
    cout<<&a<<endl;          // Both have same value -> 0xe502bff99c

    return 0;
}
-> About setting default parameter
#include<iostream>
using namespace std;
int add(int a=2 , int b=2 , int c=2){
    return (a+b+c);
}
int main(){

    cout<<add(5)<<endl;   // 9
    cout<<add(5,5)<<endl;  //12
    cout<<add(5,5,5)<<endl;  //15

    return 0;
}*/












