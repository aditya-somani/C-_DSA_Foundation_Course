/*In this we solved problems related to prefix sum -> sum from 'o' th to 'i' th term

**REVISION is left** 


->Prefix Sum Problems- sum of prefix (phelewale) ak sum - I did the the 
question but i did made a new array which should not be created as per question !
#include<iostream>
#include<vector>
using namespace std;
void psum(vector <int> &v, int size){
    vector <int> vec(size);
    for (int i = 0; i < size; i++)
    {
        vec[i]=v[i];
    }
    
    for (int i = 0; i < size; i++)
    {
        
        int j=i;
        while (j>0)
        {

            v[i]=v[i]+vec[j-1];
            j--;
        }   
    }
    for (int i = 0; i < size; i++)
    {
        cout<<v[i]<<" ";
    }    
}
int main(){
    int a;
    cout<<"Enter the size of array : ";
    cin>>a;
    cout<<"Enter the vector : ";
    vector <int> v(a);
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    cout<<"Vector is : ";
    psum(v,a);
    return 0;

}
Output:-
Enter the size of array : 5
Enter the vector : -11 -9 0 5 100
Vector is : -11 -20 -20 -15 85 

->Prefix Sum Problems- sum of prefix (phelewale) ak sum -Did by myself!!
#include<iostream>
#include<vector>
using namespace std;
void psum(vector <int> &v, int size){
    for (int i = 1; i < size; i++)
    {
        int j=i-1;
        while(j>=0)
        {
            v[i]+=v[j];
            break; 
        } 
    }
    for (int i = 0; i < size; i++)
    {
        cout<<v[i]<<" ";
    }    
}
int main(){
    int a;
    cout<<"Enter the size of array : ";
    cin>>a;
    cout<<"Enter the vector : ";
    vector <int> v(a);
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    cout<<"Vector is : ";
    psum(v,a);
    return 0;

}
Output:-
Enter the size of array : 6
Enter the vector : -7 -55 100 200 1 0
Vector is : -7 -62 38 238 239 239 

#include<iostream>
#include<vector>
using namespace std;
bool psum(vector <int> &v, int size){
    int tsum=0;
    for (int i = 0; i < size; i++)
    {
        tsum+=v[i];
    }
    int psum=0;
    
    for (int i = 0; i < size; i++)
    {
        psum+=v[i];
        int ssum=tsum-psum;
        if (psum==ssum)
        {
            return true;
        }
        
    }
    return false;
}
int main(){
    int a;
    cout<<"Enter the size of array : ";
    cin>>a;
    cout<<"Enter the vector : ";
    vector <int> v(a);
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    cout<<"Prefix sum is "<<boolalpha<<psum(v,a)<<" suffix sum ";
    
    return 0;

}
Output:-
Enter the size of array : 5
Enter the vector : 1 2 3 4 5
Prefix sum is false suffix sum 

Enter the size of array : 4
Enter the vector : 6 2 8 0
Prefix sum is true suffix sum 

->Write a program to give sum from the location to the location specified by the user
-Code after this is more good and optimal so if you want you can skip it!
#include<iostream>
#include<vector>
using namespace std;
void rsum(vector <int> &v , int size , int l , int r){
    //l-> starting point , r-> ending point
    int s=0;
    for (int i = 0; i < r ; i++)
    {
        s+=v[i];
    }
    int t=0;
    for (int i = 0; i < l-1; i++)
    {
        t+=v[i];
    }
    int ans=s-t;
    cout<<ans;
    return;    
}
int main(){
    int a;
    cout<<"Enter the size of vector : ";
    cin>>a;
    vector <int> v(a);
    cout<<"Enter vector : ";
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    cout<<"Enter starting point : ";
    int ll,rr;
    cin>>ll;
    cout<<"Enter ending point : ";
    cin>>rr;
    cout<<"Sum of range is : ";
    rsum(v,a,ll,rr);
    return 0;   
}
Output:-
Enter the size of vector : 7
Enter vector : -100 -90 0 88 10 6 5
Enter starting point : 3
Enter ending point : 6
Sum of range is : 104 
->Thi scode seems mor eoptimal than my original code 
#include<iostream>
#include<vector>
using namespace std;

void rsum(vector<int>& v, int size) {
    // l -> starting point, r -> ending point
    int q;
    cout<<"Enter number of queries : ";
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int l,r;
        cout << "Enter starting point: ";
        
        cin >> l;
        cout << "Enter ending point: ";
        cin >> r;
        
        int s = 0;
        for (int i = l - 1; i < r; i++) {
            s += v[i];
        }

        cout << "Sum of range is: " << s << endl;
    }
    
    
}

int main() {
    int a;
    cout << "Enter the size of vector: ";
    cin >> a;
    vector<int> v(a);
    cout << "Enter vector: ";
    for (int i = 0; i < a; i++) {
        cin >> v[i];
    }
    
    rsum(v, a);
    return 0;
}
Output:-
Enter the size of vector: 5
Enter vector: 1 2 3 4 5
Enter number of queries : 2
Enter starting point: 1
Enter ending point: 4
Sum of range is: 10
Enter starting point: 4
Enter ending point: 5
Sum of range is: 9 */







