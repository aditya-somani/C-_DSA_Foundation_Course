/*

-And with this my c++ foundation course has come to an end , it was an incredible journey that lasted about 6-8 months ,
 The only thing left for me is to revise and practice question as much as I can.

 -Good bye , have a good day ahead!!!

-Dijkstra Algorithm - algorithm used to find the minimum length path from a source to destination

-Theory , notes and dry run are in notebook

-Time Complexity :- O(vlogv + elogv)

#include <bits/stdc++.h>;
using namespace std;

using p = pair<int,int>;


vector<list<p>> graph;  // node,weight
int v,e;

unordered_map<int,int> dijkstra(int src){ O(vlogv + elogv)

    unordered_set<int> visited;  // marks the visited node
    priority_queue<p , vector<p> , greater<p>> pq;  // weight,node
    unordered_map<int,int> nodis; // node,distance
    unordered_map<int,int> nodvia; // node,via

    for(int i=0;i<v;i++){  //O(v)
        nodis[i]=INT_MAX;
    }

    pq.push({0,src});
    nodis[src]=0;
    nodvia[src]=INT_MAX;
    int edgeCount=0;  //Here this edge Count variable is useless , so you can remove it
    while(edgeCount<v-1 && !pq.empty()){  //O((v+e) logv)
        p curr=pq.top();
        pq.pop();
        int pq_weight=curr.first;
        int pq_node=curr.second;
        if (visited.count(pq_node)) continue;
        visited.insert(pq_node);

        for(auto &neigh:graph[pq_node]){
            int nei_node=neigh.first;
            int nei_weight=neigh.second;  //edge weight
            if(!visited.count(nei_node) && nodis[nei_node] > nodis[pq_node]+nei_weight){
                nodis[nei_node]=nodis[pq_node]+nei_weight;
                nodvia[nei_node]=pq_node;
                pq.push({nei_weight,nei_node}); NOTE:- Here insert "nodis[nei_weight]" instead of "nei_weight" , anyway it is right!!!
            }

        }
    }
    return nodvia;
}

int main(){
    cout<<"Enter the no. of vertices and edges :";
    cin>>v>>e;
    cout<<"Enter the src ,dest and weight :"<<endl;
    graph.resize(v,list<p> ());
    while(e--){
        int s,d,w;
        cin>>s>>d>>w;
        graph[s].push_back({d,w});
        graph[d].push_back({s,w});
    }

    cout<<"Enter the source and destination node :";
    int src,dest;
    cin>>src>>dest;
    unordered_map<int,int> ans= dijkstra(src);
    cout<<"Shortest path from "<<src<<" to "<<dest<<" is :";

    stack<int> path;
    path.push(dest);

    while(ans[path.top()]!=INT_MAX){
        path.push(ans[path.top()]);
    }

    while(!path.empty()){
        cout<<path.top()<<" ";
        path.pop();
    }

    return 0;
}

Output:-
Enter the no. of vertices and edges :7 8
Enter the src ,dest and weight :
0 2 2
0 1 7
2 3 1
3 1 2
2 4 2
4 6 3
4 5 5
5 6 1
Enter the source and destination node :1 5
Shortest path from 1 to 5 is :1 3 2 4 6 5

-Kruskals is preferred -> no. of edges < no. of vertices -> sparse graph -> interview friendly
-Prim's is preferred -> no. of edges > no. of vertices -> dense graph

-Question's :-

-1.Minimum Cost to Make at Least One Valid Path in a Grid

Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently
 in this cell. The sign of grid[i][j] can be:

1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])

Notice that there could be some signs on the cells of the grid that point outside the grid.

You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the
 upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid.

 The valid path does not have to be the shortest.  //This is line was just to confuse us

You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.

Return the minimum cost to make the grid have at least one valid path.

int minCost(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();

    int dy[] = {1,-1,0,0};
    int dx[] = {0,0,1,-1};

    int dis[n][m];
    deque<pair<int,int>> dq;  //x,y -> coordinates

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dis[i][j]=INT_MAX;
        }
    }

    dis[0][0]=0;
    dq.push_back({0,0});

    while(!dq.empty()){
        auto curr=dq.front();
        dq.pop_front();
        int x=curr.first;
        int y=curr.second;
        int dir=grid[x][y];

        for(int i=0;i<4;i++){

            int nx = x + dx[i];
            int ny = y + dy[i];

            int edgew = 1;
            if(i+1==dir){
                //as i is 0 based indexing , so we are checking if grid[x][y]==i+1 -> 0 = edgew
                edgew=0;
            }

            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(dis[nx][ny] > dis[x][y]+edgew){
                    dis[nx][ny] = dis[x][y]+edgew;
                    if(edgew==0){
                        dq.push_front({nx,ny});
                    }else{
                        //edgew==1
                        dq.push_back({nx,ny});
                    }
                }
            }
        }
    }
    return dis[n-1][m-1];
}

-2.Is Graph Bipartite?

-There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a
 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u],
 there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.

A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the
 graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

bool isBipartite(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int> color(n,-1);
    queue<int> q;

    for(int i=0;i<n;i++){  //this loop is to handle disconnected graphs , i.e.
    // when my 0 is a disconneted component in itself
        if(color[i]==-1){
            q.push(i);
            color[i]=0;

            while(!q.empty()){
                int curr=q.front();
                q.pop();
                for(auto &neigh:graph[curr]){
                    if(color[neigh]==-1){
                        color[neigh] = !color[curr];
                        q.push(neigh);
                    }else if(color[neigh]==color[curr]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
*/




