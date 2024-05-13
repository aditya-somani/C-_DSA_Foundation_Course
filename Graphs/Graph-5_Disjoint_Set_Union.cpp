/*

-IN this we studied about DSU and all concepts and reasoning's related to it , do make sure to read the hand written notes
 of it , as they really clear up the concept that how we were able to come to conclusion of using find() and union() function
 most optimal approach , and take it a little slow , I know as the end is near I am more and more excited but my friend

 THIS IS JUST the BEGINNING!!!

-Disjoint Set Union

Need?

-Clustering/Grouping - you need to group or segregate some elements into groups or decide if a element belongs to which group.
 in such case DSU is used .
-Also used in Graph algo's as these groups works as connected component

-Terminologies related to DSU:-

1.Leader/Parent of the group - To uniquely identify a group we will pick any element from the group and make it the representative
 /leader/parent of th group

-To use DSU

 we will ask a question -> what function DSU need to support??

1. Union(a,b) -> adds the group where elements 'b' belongs to the group where element 'a' belongs or vice-versa

2. find(x)/get(x) -> this will be used to find which group 'x' belongs to -> we will return the parent of the grp that "x" belongs to;

-NOW , GO READ THE HANDWRITTEN NOTES IN THE NOTEBOOK -> THIS IS COMPULSORY FOR YOU TO UNDERSTAND THE REASON BEHIND
 DSU FAST PERFORMANCE AND INTUITION!! -> GO READ IT!!!!!!!

-Implementation of DSU:-

-Time Complexity :- O(long*n) -> log star n

#include <iostream>
#include <vector>
using namespace std;

//This function return which group/cluster "x" belongs to
int find(vector<int> &parent,int x){
    return parent[x]=(parent[x]==x) ? x: find(parent,parent[x]);
}

void union_u(vector<int> &parent ,vector<int>& rank, int a ,int b){
    a=find(parent,a);
    b=find(parent,b);
    if(rank[a]>=rank[b]){
        parent[b]=a;
        rank[a]++;
    }else{
        parent[a]=b;
        rank[b]++;
    }
}

int main(){
    int n,m;
    // n-> no. of elements and m-> no. of queries
    cout<<"no. of elements and no. of queries :";
    cin>>n>>m;
    vector<int> parent(n+1); // as we want one based indexing
    vector<int> rank(n+1,0);

    for(int i=0;i<=n;i++){
        parent[i]=i;
    }

    while(m--){
        cout<<"What do want :-\n 1.Union of two element \n 2.Find the parent/leader/group of element"<<endl;
        int s;
        cin>>s;
        switch(s){
            case 1:
                cout<<"Enter the value's of element :";
                int a,b;
                cin>>a>>b;
                union_u(parent,rank,a,b);
                break;

            case 2:
                cout<<"Enter the element value :";
                int x;
                cin>>x;
                cout<<find(parent,x)<<endl;
                break;

            default:
                cout<<"Invalid choice"<<endl;
                break;
        }
    }
    return 0;
}

Output:-
no. of elements and no. of queries :8 10
What do want :-
1.Union of two element
2.Find the parent/leader/group of element
1
Enter the value's of element :1 2
What do want :-
1.Union of two element
2.Find the parent/leader/group of element
2
Enter the element value :1
1
What do want :-
1.Union of two element
2.Find the parent/leader/group of element
1
Enter the value's of element :1 3
What do want :-
1.Union of two element
2.Find the parent/leader/group of element
1
Enter the value's of element :1 4
What do want :-
1.Union of two element
2.Find the parent/leader/group of element
1
Enter the value's of element :1 5
What do want :-
1.Union of two element
2.Find the parent/leader/group of element
2
Enter the element value :1
1
What do want :-
1.Union of two element
2.Find the parent/leader/group of element
2
Enter the element value :3
1
What do want :-
1.Union of two element
2.Find the parent/leader/group of element
1
Enter the value's of element :8
7
What do want :-
1.Union of two element
2.Find the parent/leader/group of element
2
Enter the element value :6
6
What do want :-
1.Union of two element
2.Find the parent/leader/group of element
2
Enter the element value :8
8

*/








