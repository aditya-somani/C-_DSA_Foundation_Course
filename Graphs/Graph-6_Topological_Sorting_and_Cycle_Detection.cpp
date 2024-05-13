/*
 *
 *
 * -After it(cycle detection using BFS) the site crashed so , I don't have access to 30 min. further lectures ,
 * after it I am gonna start with next video
 and when the bug get's resolved I will complete this! -> So, I have completed the rest of the lecture and the only thing
 in it were 3 questions based on topological sorting -> they were HW , sir told about the intuition but I still have
 problem implementating them , So when I come for revision , I will do them


Dependency Resolution - When one things depends on other for its functioning/working.

 ->Directed Graph are used for DR but we need to make sure they are not cyclic.

-Otherwise we will go into a loop without any solution

-> Such kind of graph are called Directed Acyclic graph -> DAG

-WE use topological sorting in DAG

-Implementation of topo. soring

-1.Kahn's Algo - Using BFS (multisorce) -> put all nodes into queue in the starting whose indegree in 1

 indegree -> no. of incoming edges

-Startfrom nodes with indegree 0 -> they are independent


#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v; //vertices

void topoBFS(){
    vector<int> indegree(v,0);
    for(int i=0;i<v;i++){
        for(auto &neigh:graph[i]){
            indegree[neigh]++; // i -> neigh , so indegree of neighbour will increase
        }
    }

    queue<int> q;
    unordered_set<int> visited; //This is not required , it is extra

    //Now insert all the nodes with indegree 0
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    cout<<"Topological Sorted :";
    //now run normal multisource BFS
    while(not q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(auto &neigh:graph[curr]){
            if(not visited.count(neigh)){  // this condition is not required it is extra
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
    }
}

int main(){
    cout<<"Enter the no. of vertices and edges :";
    int e;
    cin>>v>>e;
    cout<<"Enter the source -> destination :"<<endl;
    graph.resize(v,list<int>());
    while(e--){

        int s,d;
        cin>>s>>d;
        graph[s].push_back(d); //no need to make a add_edge function;
    }
    topoBFS();
    return 0;
}

Output:-
Enter the no. of vertices and edges :8 11
Enter the source -> destination :
0 2
1 2
1 3
2 4
2 6
2 5
2 3
3 5
5 6
4 6
6 7
Topological Sorted :0 1 2 4 3 5 6 7

-*To check for Cycle presence -> simply check the number of nodes our topological sort is giving us if it is less than
 number of vertex of graph then a cycle is present in the graph and it is not a DAG.

-Topological Sorting using DFS

#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v; //vertices
unordered_set<int> visited; //for visited
stack<int> s; // for correct order of displaying

void topoDFSHelper(int i){
    visited.insert(i);
    for(auto &neigh:graph[i]){
        if (not visited.count(neigh)){
            topoDFSHelper(neigh);
        }
    }
    s.push(i);
}

void topoDFS(){
    for(int i=0;i<v;i++){
        if(not visited.count(i)){
            topoDFSHelper(i);
        }
    }
    cout<<"Topological Sorted order :";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(){
    cout<<"Enter the no. of vertices and edges :";
    int e;
    cin>>v>>e;
    cout<<"Enter the source -> destination :"<<endl;
    graph.resize(v,list<int>());
    while(e--){

        int s,d;
        cin>>s>>d;
        graph[s].push_back(d); //no need to make a add_edge function;
    }
    topoDFS();
    return 0;
}

Output:-
Enter the no. of vertices and edges :8 11
Enter the source -> destination :
0 2
1 2
1 3
2 4
2 6
2 5
2 3
3 5
5 6
4 6
6 7
Topological Sorted order :1 0 2 3 5 4 6 7

-Questions:-

-1.Course Schedule I & II -> Simple question of cycle detection

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array
 prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them.
 If it is impossible to finish all courses, return an empty array.

vector<list<int>> graph;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ans;

    graph.resize(numCourses,list<int>());
    for(auto &pre:prerequisites){  //This as giving me error as I was looping till numCourses which
        graph[pre[1]].push_back(pre[0]);
    }
    vector<int> indegree(numCourses,0);
    queue<int> q;

    for(int i=0;i<numCourses;i++){
        for(auto &neigh:graph[i]){
            indegree[neigh]++;
        }
    }

    for(int i=0;i<numCourses;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(not q.empty()){
        int cell=q.front();
        q.pop();
        ans.push_back(cell);
        for(auto &neigh:graph[cell]){
            indegree[neigh]--;
            if(indegree[neigh]==0){
                q.push(neigh);
            }
        }
    }

    if(numCourses==ans.size()){
        return ans;
    }else{
        ans.clear();
        return ans;
    }
}

-2.Grid question from Sanket sir's google interview

Given a grid of nxm size . Every cell of the grid are marked as 'L' , 'R' , 'U' and 'D' . Character on a cell denotes if you
 are standing at that cell , what direction you can move to .

Check if we start from (0,0) , can we reach (n-1,m-1).

--> First approach we thought of simple using bfs/dfs to detect cycle and give answer , but the interviewer gave a constrain
 Space Complexity : O(1).

--> SO , he thought of an entirely different approach i.e.
  we know that number of transitions/steps can never be greater than n*m , so we just use a step variable and increase it
  for every step taken , for every node we see if step<=n*m and if not that means we are looping in a cycle , so this will be
  our answer

--> Third, the way which the interviewer was hoping was using Slow and Fast pointer approach for every node and if at a place
 they both coincide then the cycle exist and we get the answer

-Now topological sorting was for -> DAG -> where directed graphs are present but what for undirected??

-To detect cycle in Directed Graph -> we have three method -> 1.BFS 2.DFS 3.DSU

-1.DSU - If we come to know two elements have same parent while doing union , then that is the sign that it we have a cycle

-Time Complexity -> log * n -> log star n


#include <bits/stdc++.h>
using namespace std;

int v; //no. of vertexes
vector<int> parent;
vector<int> ranki;
bool cycle= false;

int find(int x){
    return parent[x] = parent[x]==x ? x:find(parent[x]);
}

void union_cycle(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b){  //Both have same parent so linking them will create a cycle
        cycle=true;
        return;
    }
    if(ranki[a]>=ranki[b]){
        parent[b]=a;
        ranki[a]++;
    }else{
        parent[a]=b;
        ranki[b]++;
    }
}

int main(){
    cout<<"Enter the number of vertexes :";
    cin>>v;
    cout<<"Enter the number of edges :";
    int e;cin>>e;
    parent.resize(v+1);
    ranki.resize(v+1,0);
    for(int i=0;i<=v;i++){
        parent[i]=i;
    }
    cout<<"Enter the src and dest :"<<endl;
    while(e--){
        int s,d;
        cin>>s>>d;
        union_cycle(s,d);
        if(cycle) {
            cout << "Cycle exists " << endl;
            break;
        }
    }
    if(!cycle) cout<<"Cycle does not exist "<<endl;
    return 0;
}

Output:-
Enter the number of vertexes :10
Enter the number of edges :10
Enter the src and dest :
0 1
0 2
0 3
3 4
5 6
4 5
3 6
Cycle exists

-Cycle detection using DSU - check if the visited node is your parent or not -> if not then there exist cycle
 -This edge is called back edge i.e. a edge that connect a node to one of its ancestors during recursion(DFS).


#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v; //vertices
unordered_set<int> visited; //for visited
bool cycle= false;

bool dfs(int src,int parent){
    visited.insert(src);
    for(auto &neigh:graph[src]){
        if (visited.count(neigh) && neigh!=parent){
            //cycle detected
            return true;
        }
        if(not visited.count(neigh)){
            if (dfs(neigh,src)) return true;
        }
    }
    return false;
}

bool hasCycle(){
    bool result=false;
    for(int i=0;i<v;i++){
        if(not visited.count(i)){
            result=dfs(i,-1);
            if (result) return true;
        }
    }
    return false;
}

int main(){
    cout<<"Enter the no. of vertices and edges :";
    int e;
    cin>>v>>e;
    cout<<"Enter the source -> destination :"<<endl;
    graph.resize(v,list<int>());
    while(e--){

        int s,d;
        cin>>s>>d;
        graph[s].push_back(d);
        graph[d].push_back(s);

    }
    cycle=hasCycle();
    if (cycle){
        cout<<"cycle detected "<<endl;
    }
    else{
        cout<<"No cycle "<<endl;
    }
    return 0;
}

Output:-
Enter the no. of vertices and edges :4 4
Enter the source -> destination :
0 1
1 2
2 3
3 0
cycle detected

-Cycle Detection using BFS - same as DFS - If a node is visited and it is not your parent -> cycle exists!

Here unlike dfs you can't  pass parent recursively so maintain a parent array


#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;
queue<pair<int,int>> q;
unordered_set<int> visited;

bool hasCycle(){
    for(int src=0;src<v;src++){
        if(visited.count(src)) continue;
        q.push({src,-1});
        visited.insert(src);
        while(!q.empty()){
            auto curr=q.front();
            int node=curr.first;
            int parent=curr.second;
            q.pop();
            for(auto &neigh:graph[node]){
                if(visited.count(neigh) && neigh!=parent){
                    cout<<"Cycle detected "<<endl;
                    return true;
                }
                if(not visited.count(neigh)){
                    q.push({neigh,node});
                    visited.insert(neigh);
                }
            }
        }

    }
    cout<<"NO cycle detected ";
    return false;
}

int main(){
    cout<<"Enter the no. of vertices and edges :";
    int e;
    cin>>v>>e;
    cout<<"Enter the source -> destination :"<<endl;
    graph.resize(v,list<int>());
    while(e--){

        int s,d;
        cin>>s>>d;
        graph[s].push_back(d);
        graph[d].push_back(s);

    }
    hasCycle();
    return 0;
}

Output:-
Enter the no. of vertices and edges :4 4
Enter the source -> destination :
0 1
1 2
2 3
3 0
Cycle detected

-Questions

-1.Most Stones Removed with Same Row or Column

On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the
 largest possible number of stones that can be removed.

-2.Count Unreachable Pairs of Nodes in an Undirected Graph

-You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1.
 You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge
 connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.

-3.Detect Cycles in 2D Grid

-Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.

A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell,
 you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right),
 if it has the same value of the current cell.

Also, you cannot move to the cell that you visited in your last move. For example,
 the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

Return true if any cycle of the same value exists in grid, otherwise, return false.
*/













