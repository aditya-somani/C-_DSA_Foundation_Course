/*So, in this we will get a general idea about loops -> for, while , do while , and about
functions like break and continue , its easy just use a little brain! , Have a Good Day!! */
/*Write a programm to print sum of n integers given by users -> using while loop
#include<iostream>
using namespace std;
int main(){
    int a,b=0;
    cout<<"Enter the number :"<<endl;
    cin>>a;
    while (a>0)
    {
        b=a+b;
        a=a-1;
    }
    cout<<"sum : "<<b<<endl;
    return 0;

}
Solving this question using Mam's method
#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Enter the number"<<endl;
    cin>>a;
    b=0;
    c=1; // Loop value
    while (c<=a)
    {
        b=b+c;
        c++;
    }
    cout<<"Sum : "<<b<<endl;
    return 0;

} same question but with for loop
#include<iostream>
using namespace std;
int main(){
    int a,b,i;
    cout<<"Enter the number"<<endl;
    cin>>a;
    b=1;
    int sum;
    for (int i = 1; i<=a; i++)
    {
        sum= sum+i;
    }
    cout<<"sum : "<<sum<<endl;
    return 0;
}
#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    a=5;
    while (true)
    {
        if (a%7==0)
        {
            cout<<a<<endl;
            break;
        }
        a=a+5;
        
    }
    // for(int a=5;;a+=5){
    //    if (a%7==0){
    //        cout<<a<<endl;
    //}
    //}
} 
Do while loop
#include<iostream>
using namespace std;
int main(){
    int a,b=0;
    cout<<"Enter the number : "<<endl;
    cin>>a;
    do
    {
        b++;
        cout<<"The numbers : "<<b<<endl;
    } while (a>b);
    return 0;
}
-> Code to print numbers from a particular starting point to a ending point while excluding
a certain type of number using continue operator.
#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e;
    cout<<"Enter starting point"<<endl;
    cin>>b;
    cout<<"Enter Last point"<<endl;
    cin>>a;
    cout<<"Enter the number whose multiple are to be excluded : "<<endl;
    cin>>c;
    while (a>b)
    {
        b++;
        if (b%c==0)
        {
            continue;
        }
        cout<<"The numbers are : "<<endl;
        cout<<b<<endl;
        
    }
    return 0;
}*/














