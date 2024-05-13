/*  
In this we learned about 2D vector and solved pascal traingle problem which is really important and trickly(at first ) to solve!

2D-vectors:- vector of vector datatype //it is not imp to define size of vectors
syntax:-    vector <vector <int>> vec;
        vector <vector <int>> v(n, vector <int> (m))    
v = {{1,2,3},{5,6,7,8},{0,1}} i.e. they necessary don't need to same 

->Given the integer 'n' return first n rows of pascal's traingle


#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> pascalTraingle(int n){
    vector<vector<int>> pascal(n);
    for (int i = 0; i < n; i++)
    {
        pascal[i].resize(i+1);

        for (int j = 0; j < i+1; j++)
        {
            if (j==0 || j==i)
            {
                pascal[i][j]=1;
            }
            else{
                pascal[i][j]= pascal[i-1][j]+pascal[i-1][j-1];
            }
            
        }
        
    }
    return pascal;
    
}
int main(){
    int ne;
    
    cout<<"Enter the number of rows : ";
    cin>>ne;
    vector <vector <int>> ans;
    ans = pascalTraingle(ne);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
Output:-
Enter the number of rows : 7
1 
1 1
1 2 1
1 3 3 1
1 4 6 4 1 
1 5 10 10 5 1
1 6 15 20 15 6 1 */

#include<iostream>
using namespace std;
int main(){
    cout<<"Helllo Workl!";
    return 0;
}
