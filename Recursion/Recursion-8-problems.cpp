/*
-Both of these questions are quite good but the Key Pad one is one hella UNIQUE , Do solve it again!
-And with these Recursion are over , start more only once you have a fine frip over recursion and solve all assignment question of 
recursion


-For a given string, find all the subsequences

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void f(const string &s, int i ,string result ,vector <string> &li){
    //base-case 
    if(i==s.length()){
        li.push_back(result);
        return;
    }
    f(s,i+1,result+s[i],li);
    f(s,i+1,result,li);
}
int main(){
    string s,result;
    cout<<"Enter the string : ";
    cin>>s;
    vector<string> li;
    f(s,0,"",li);
    cout<<"All the possible substrings are : ";
    for (int i = 0; i < li.size(); i++)
    {
        cout<<li[i]<<" ";
    }
    return 0;
}

Output:-
Enter the string : abc
All the possible substrings are : abc ab ac a bc b c  

-Given a string containing digits 09, return all possible combinations that the numbers can represent

#include<iostream>
#include<vector>
using namespace std;
void f(string &str, int i , string result, vector <string> &li,vector<string> &v){
    //base-case
    if (i==str.size())
    {
        li.push_back(result);
        return;
    }
    int digit= str[i]-'0'; //OP method
    if (digit<=1)
    {
        f(str,i+1,result,li,v);
        return;
    }
    for(int j=0; j < v[digit].size(); j++){
        f(str,i+1,result+v[digit][j],li,v);
    }
    return;
    
}
int main(){
    vector<string> v(10); 
    v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string str;
    cout<<"Enter the string : ";
    cin>>str;
    vector<string> li;
    f(str,0,"",li,v);
    cout<<"Mobile Pad sequence : ";
    for (int i = 0; i < li.size(); i++)
    {
        cout<<li[i]<<" ";
    }
    return 0;
}

*/












