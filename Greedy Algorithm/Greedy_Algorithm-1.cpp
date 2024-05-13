/*
 *
 * So ,in this we got a pretty idea of what greedy algorithms are , how to apply them and through questions we understood
 * wide variety of them , these problems were basics , so review them and try to build intuition around them
 * as much as possible and if you can solve some problems by yourself , but don't forget one IMP thing
 *
 * IT's ONE step at a time!!
 *
 * So, go ahead and revise it and have a good day!!

-Greedy Algorithm

 For Greedy Algorithm to be applied we need two things :-
 1.Greedy Choice - local optimal
 2.

 There wasn't that much theory just its application , advantages and disadvantages

 -Questions :-

 -1.Fractional Knapsack

Given the eights and profits of a items, in the form of {profit, eight} put these items in a knapsack of
capacity W to get the maximum total profit in the knapsack. In Fractional Knapsack, we can break items for
maximizing the total value of the knapsack.


#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

struct items{
    int value;
    int weight;
};

bool cmp(items& i1,items& i2){
    double v_w_i1= static_cast<double> (i1.value)/i1.weight;
    double v_w_i2= static_cast<double> (i2.value)/i2.weight;
    return v_w_i1>v_w_i2;
}

double fractional(int W,vector<items>&itemPairs){
    double ans=0;
    sort(itemPairs.begin(),itemPairs.end(), cmp); //This was something new for me
    for(const auto& item:itemPairs){
        // we can take full weight for our knapsack
        if(item.weight <= W){
            ans += item.value;
            W -= item.weight;
        }else{
            //we have to take fractional part for our knapsack
            double fraction = static_cast<double> (W)/item.weight;
            ans += fraction * item.value;
            W=0;
        }
    }
    return ans;
}

int main(){
    int n,w;
    cout<<"Enter the size of vector and Knapsack : ";
    cin>>n>>w;
    vector<items> ietm;
    for(int i=0;i<n;i++){
        int v,W;
        cin>>v>>W;
        items it;
        it.value=v;
        it.weight=W;
        ietm.push_back(it);
    }
    cout<<"Total value of Fractional Knapsack : "<<fractional(w,ietm);
    return 0;
}

Output:-
Enter the size of vector and Knapsack :3 50
60 10
120 30
100 20
Total value of Fractional Knapsack : 240

 -2.Maximum meetings in one room

 -Many combination can be formed for this question , so amke sure to give a good revision to it.

 There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of
meeting i and F[i] is the finish time of meeting i. The task is to find the maximum number of meetings that can
be accommodated in the meeting room. Print all meeting numbers.


#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

struct meeting{
    int start;
    int end;
    int idx;
};

bool cmp(meeting m1,meeting m2){
    return m1.end<m2.end;
}

void printMaxMeeting(vector<meeting>& m){
    sort(m.begin(),m.end(),cmp);
    cout<<m[0].idx+1<<" ";
    meeting last=m[0];
    for(int i=0;i<m.size();i++){
        if(m[i].start > last.end){
            cout<<m[i].idx+1<<" ";
            last=m[i];
        }
    }
}

int main(){
    int n;
    cout<<"Enter the size of meetings : ";
    cin>>n;
    cout<<"Enter the meetings "<<endl;
    vector<meeting> mi(n);
    for (int i = 0; i < n; ++i) {
        cin>>mi[i].start;
        cin>>mi[i].end;
        mi[i].idx=i;
    }
    cout<<"Combo for max. meeting is : ";
    printMaxMeeting(mi);
    return 0;
}

Output:-
Enter the size of meetings :6
Enter the meetings
1 2
3 4
0 6
5 7
8 9
5 9
Combo for max. meeting is : 1 2 4 5

 -3.Check if it is possible to survive on Island

 You are a person on an islandZ There is only one shop in this island, this shop is open on all days of the week
except for SundayZ Consider following constraints=
S – Number of days you are required to survive.
N – Maximum unit of food you can buy each day.
M - Unit of food required each day to survive.

Currently, it’s Monday, and you need to survive for the next S daysZ
Find the minimum number of days on which you need to buy food from the shop so that you can survive the
next S days, or determine that it isn’t possible to surviveZ


#include "iostream"
#include "cmath"
using namespace std;
int main(){
    cout<<"Enter Number of days you are required to survive : ";
    int s;
    cin>>s;
    cout<<endl<<"Enter Maximum unit of food you can buy each day : ";
    int n;
    cin>>n;
    cout<<endl<<"Enter Unit of food required each day to survive : ";
    int m;
    cin>>m;
    //s -> represent , total no. days then s/7 will represent no. of sundays in all those days
    // then s-s/7 will be the net number of days we can actually buy the food and s*m will be total amount
    // of food consumed as we are gonna eat regardless if it is sunday or not!
    if((s-(s/7))*n<(s*m)){
        cout<<endl<<"Survival not possible! "<<endl;
    }else{
        cout<<endl<<"Number of days : "<<ceil((double)(s*m)/n);
    }
    return 0;
}

 -4. Largest Kalindromic number by Permuting digits

 Given N(very large), the task is to print the largest palindromic number obtained by permuting the digits of N. If
it is not possible to make a palindromic number, then print an appropriate message.

#include "iostream"
#include "unordered_map"
#include "vector"
using namespace std;

bool isPossible(unordered_map<int,int>& mp){
    //Now let's check if we have more than one odd in our unordered map
    int count=0;
    //as my map will only contain 0-9 digits
    for(int i=0;i<=9;i++){
        if(mp.count(i)){
            if (mp[i]%2!=0){
                count++;
            }
            if(count>1){
                return false;
            }
        }
    }
    return true;
}

string max_palindrome(string s){
    int n=s.size();
    unordered_map<int,int> has;
    for(int i=0;i<n;i++){
        has[s[i]-'0']++;
    }
    if (!isPossible(has)){
        return "Not Possible";
    }
    vector<char> v(n);
    int front=0;
    for(int i=9;i>=0;i--){
        if(has[i]%2!=0){
            v[n/2]=char(i+48);
            has[i]--;
        }
        while(has[i]>0){
            v[front]=char(i+48);
            v[n-front-1]=char(i+48);
            has[i]-=2;
            front++;
        }
    }
    string ans="";
    for(int i=0;i<v.size();i++) ans+=v[i];
    return ans;

}

int main(){
    cout<<"Enter the number : ";
    string s;
    cin>>s;
    cout<<endl<<"Max Palindrome (NP->Not Possible) : "<<max_palindrome(s);
    return 0;
}

Output:-
Enter the number :1234554321
Max Palindrome (NP->Not Possible) : 5432112345

*/
