/*
-For traversing any graph we use :-

1.DFS - Depth First Search/Traversal
2.BFS - Breadth First Search/Traversal

-let's first understand DFS using a question

-1.There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive).
 The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a
 bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge,
 and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination,
 or false otherwise.

-This is a question that can be solved using basic DFS algo.


unordered_set<int> visited;
vector<list<int>> adjl;

bool dfs(int source ,int destination){
    if(source==destination) return true;
    visited.insert(source);
    for(auto &neighbour:adjl[source]){
        if(not visited.count(neighbour)){
            bool ans=dfs(neighbour,destination);
            if(ans) return true;
        }
    }
    return false;
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    visited.clear();
    adjl.clear();
    adjl.resize(n,list<int>());

    for(auto &edge:edges){
        adjl[edge[0]].push_back(edge[1]);
        adjl[edge[1]].push_back(edge[0]);
    }
    return dfs(source,destination);
}

-2.There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive).
 The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a
 bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge,
 and no vertex has an edge to itself.

You want to determine total number valid path that exists from vertex source to vertex destination.



#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<vector<int>> ans;
unordered_set<int> visited;
vector<vector<int>> g;
vector<int> path;

void dfs(int src, int dest) {
    if(src==dest){
        path.push_back(src);
        ans.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(src); // mark visited
    path.push_back(src); // put curr node in path
    for(auto& neighbour:g[src]) {
        if (not visited.count(neighbour)) {
            dfs(neighbour, dest);
        }
    }
    //revert the changes made in state , so we can find multiple paths
    visited.erase(src);
    path.pop_back();
    return;
}

int main() {
    int n,m;
    cout << "Enter no. of vertices:";
    cin >> n;
    cout<<"Enter no. of edges :";
    cin>>m;
    g.resize(m,vector<int>(2));
    while(m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int source, dest;
    cout<<"Enter source and destination :";
    cin >> source >> dest;

    // Validate input
    if (source < 0 || source >= n || dest < 0 || dest >= n) {
        cout << "Invalid source or destination\n";
        return 0;
    }

    dfs(source,dest);

    cout<<"All possible paths from source to destination is :"<<endl;
    for(auto &ele:ans){
        for(auto &el:ele){
            cout<<el<<" ";
        }
        cout<<endl;
    }

    return 0;
}

Output:-
Enter no. of vertices:7
Enter no. of edges :8
0 4
0 1
1 3
3 4
1 5
5 6
5 2
2 6
Enter source and destination :0 6
All possible paths from source to destination is:
0 4 3 1 5 6
0 4 3 1 5 2 6
0 1 5 6
0 1 5 2 6

-BFS - Level order wise -> used to find the shortest path in unweighted graph -> process immediate neighbour

-So, let's solve a question to find the shortest distance between two nodes


#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

unordered_set<int> visited;
vector<vector<int>> g;
int v; // no. of vertices

void bfs(int src,vector<int> &dist) {
    queue<int> q;
    visited.clear();
    dist.resize(v,INT_MAX);
    q.push(src);
    visited.insert(src);
    dist[src]=0;
    while (!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto &neigh:g[curr]){
            if (not visited.count(neigh)){
                q.push(neigh);
                visited.insert(neigh);
                dist[neigh]=dist[curr]+1; // distance of neighbour = distance of parent + 1 -> for distance form source

            }
        }

    }
}

int main() {
    int m;
    cout << "Enter no. of vertices:";
    cin >> v;
    cout<<"Enter no. of edges :";
    cin>>m;
    g.resize(m,vector<int>(2));
    while(m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int source, dest;
    cout<<"Enter source :";
    cin >> source;

    // Validate input
    if (source < 0 || source >= v ) {
        cout << "Invalid source or destination\n";
        return 0;
    }

    vector<int> d;
    bfs(source,d);

    cout<<"All Shortest Distance of nodes from source / origin :";
    for(auto &ele:d){
        cout<<ele<<" ";
    }

    return 0;
}

Output:-
Enter no. of vertices:7
Enter no. of edges :8
0 4
0 1
1 3
3 4
1 5
5 6
5 2
2 6
Enter source :0
All Shortest Distance of nodes from source / origin :0 1 3 2 1 2 3

*/










