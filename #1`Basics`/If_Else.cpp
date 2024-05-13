/*#include <iostream>
using namespace std;
int main() {
    int a,b=5;
    //cout<<(++a)<<endl;   //5
    //cout<<(--b)<<endl;   //4
    cout<<"Enter value of a : "<<endl;
    cin>>a;
    if (a%2==0) {
        cout<<"Even"<<endl;
    }
    else {
        cout<<"Odd"<<endl;
    }
    return 0;

}

#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the age"<<endl;
    cin>>a;
    if (a<5){
        cout<<"Child"<<endl;
    }
    else if (a>18)
    {
    cout<<"Adult"<<endl;
    }
    else{
       cout<<"tennager"<<endl;
    }
    return 0;
}

#include <iostream>
using namespace std;
int main() {
    int a,b;
    cout<<"Enter the marks: "<<endl;
    cin>>a;
    if (a>33){
        if (a>80){
            cout<<"passed Gracefully"<<endl;
        }
        else{
            cout<<"Pass";
        }
        
    }
    else{
        cout<<"Fail"<<endl;

    }
    return 0;
}

#include <iostream>
using namespace std;
int main(){
    int marks;
    cout<<"enter the marks: "<<endl;
    cin>>marks;
    marks>33 ? cout<<"pass"<<endl : cout<<"fail"<<endl;
    return 0; 
}

#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"enter the numaber"<<endl;
    cin>>a;
    a%2==0 && a%3==0 ? cout<<"Even and divisible by 3"<<endl : cout<<"No"<<endl;
    return 0; 
}

#include <iostream>
using namespace std;
int main(){
    int a;
    cout<<"enter the number "<<endl;
    cin>>a;
    if ((a%3==0) || a%5==0){
        cout<<"Divisible by 3 and 5"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    (a%3==0) || (a%5==0) ? cout<<"Divisible by 3 or 5"<<endl : cout<<"No"<<endl; -> can be written like this also 
    return 0;
}
#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Enter the number"<<endl;
    cin>>a;
    switch (a)
    {
    case 1:
        cout<<"Monday"<<endl;
        break;
    case 2:
        cout<<"Tuesday"<<endl;
        break;
    case 3:
        cout<<"wednesday"<<endl;
        break;
    case 4:
        cout<<"Thrusday"<<endl;
        break;
    case 5:
        cout<<"Friday"<<endl;
        break;
    case 6:
        cout<<"Saturday"<<endl;
        break;
    case 7:
        cout<<"Sunday"<<endl;
        break;
    default:
        cout<<"Not a Day"<<endl;
        break;
    }
    return 0;
}
#include <iostream>
using namespace std;
int main(){
    char character,b;
    cout<<"Enter the character: "<<endl;
    cin>>character;
    switch (character)
    {
    case 'a':
        cout<<"Vowel"<<endl;
        break;
    case 'e':
        cout<<"Vowel"<<endl;
        break;
    case 'i':
        cout<<"Vowel"<<endl;
        break;
    case 'o':
        cout<<"Vowel"<<endl;
        break;
    case 'u':
        cout<<"Vowel"<<endl;
        break;
    
    default:
        cout<<"Consonant"<<endl;
        break;
    }
    return 0;
}*/




