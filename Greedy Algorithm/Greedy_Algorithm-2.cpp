/*

 -And with this we have completed some really OP! questions based on greedy approach their solutions were easy but
 the most tricky part is to get the intuition to apply greedy algorithm.

 -Make sure to get a good revision of all of them and have a good day ahead!!



-1.Minimum Cost to cut a board into squares.

A board of length M and width N is given. The task is to break this board into M * N squares such that the cost of
 breaking is minimized. The cutting cost for each edge will be given for the board in two arrays X[] and Y[], representing
 the cost of cutting horizontal and vertical edges respectively. For example, X[i] represents the cost of cutting a
 horizontal edge of size i. In short, you need to choose such a sequence of cutting such that the cost is minimized.
 Return the minimized cost.


#include "iostream"
#include "vector"
#include "algorithm"
#define ll long long int
using namespace std;

bool cmp(ll x,ll y){
    return x>y;
}

int minCost(int m,int n,vector<ll>& vertical,vector<ll>& horizontal){
    sort(vertical.begin(),vertical.end(),cmp);
    sort(horizontal.begin(),horizontal.end(), cmp);
    int hz=1,vz=1; //values which will multiplied i.e. number of pieces
    int h=0,v=0; //pointer for traversal
    ll ans=0;
    while(h<horizontal.size() && v<vertical.size()){
        if(vertical[v]>horizontal[h]){
            ans += vertical[v]*vz;
            hz++; //horizontal is increased when vertical is cut
            v++;
        }else{
            ans+=horizontal[h]*hz;
            vz++;
            h++;
        }
    }
    while(h<horizontal.size()){
        ans+=horizontal[h]*hz;
        vz++;
        h++;
    }
    while(v<vertical.size()){
        ans+=vertical[v]*vz;
        hz++;
        v++;
    }
    return ans;
}

int main(){
    int m,n;
    cout<<"Enter the coordinates of grid : ";
    cin>>m>>n;
    vector<ll> x(m);
    vector<ll> y(n);
    cout<<endl<<"Enter the values of cost of cutting vertical : ";
    for(int i=0;i<m-1;i++){
        cin>>x[i];
    }
    cout<<endl<<"Enter the values of cost of cutting horizontal : ";
    for(int i=0;i<n-1;i++){
        cin>>y[i];
    }
    cout<<endl<<"Minimum cost to convert grid to squares : "<<minCost(m,n,x,y);
    return 0;
}

Output:-
Enter the coordinates of grid :6 4
Enter the values of cost of cutting vertical :2 1 3 1 4
Enter the values of cost of cutting horizontal :4 1 2
Minimum cost to convert grid to squares : 42

 -2.Non-overlapping Intervals

 Given an array of intervals intervals where intervals[i] = [starti, endi],
 return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.


class Solution {
public:

    static bool cmp(vector<int>& v1,vector<int>& v2){
        return v1[1]<v2[1]; //sorting based on end
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int lastPicked=0;
        int count=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[lastPicked][1]>intervals[i][0]){
                count++; //overlapping
            }else{
                lastPicked=i;
            }
        }
        return count;
    }
};

 -3.Smallest Number

 The task is to find the smallest number with given sum of digits as S and number of digits as Ds


#include "iostream"
#include "vector"
using namespace std;

void minNum(int d,int s){
    int a=s;
    vector<char> v(d,'0');
    int i;
    for(i=d-1;i>=0;i--){
        if(s<=9) break;
        v[i]='9';
        s-=9;

    }

    if(i==0){
        v[i]=char(s+'0');
    }else{
        v[0]='1';
        v[i]=char((s-1)+'0');
    }
    cout<<"Smallest Number with number of digit "<<d<<" and sum of digit as "<<a<<" is : ";
    for (int j = 0; j < v.size(); ++j) {
        cout<<v[j];
    }

}

int main(){
    cout<<"Enter the value of number of digit and sum of digit : ";
    int d,s;
    cin>>d>>s;
    minNum(d,s);
    return 0;
}

Output:-
Enter the value of number of digit and sum of digit :6 15
Smallest Number with number of digit 6 and sum of digit as 15 is :100059

 -4.Maximum Profit in Job Scheduling

We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].
You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two
 jobs in the subset with overlapping time range.
If you choose a job that ends at time X you will be able to start another job that starts at time X.


int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    vector<vector<int>> jobs;
    for(int i=0;i<profit.size();i++){
        jobs.push_back({startTime[i],endTime[i],profit[i]});
    }
    sort(jobs.begin(),jobs.end()); //sorting based on start time
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    int maxProfit=0;
    for(int i=0;i<jobs.size();i++){
        int start=jobs[i][0];
        int end=jobs[i][1];
        int prof=jobs[i][2];
        while(!pq.empty() && start>=pq.top()[0]){
            maxProfit=max(maxProfit,pq.top()[1]);
            pq.pop();
        }
        pq.push({end,prof+maxProfit});
    }
    while(!pq.empty()){
        maxProfit=max(maxProfit,pq.top()[1]);
        pq.pop();
    }
    return maxProfit;
}


*/







