/*

-And with that we have completed some really interesting problems on DFS and BFS and I also got to know about concept such
 as Connected Component and Multisource BFS , which really makes your question a breeze , so now go revise them and then
 solve questions on graphs to get a good grip on them!!

 -Have a good Day ahead!

-1.Connected components -> Very Very IMP concept

Connected components in graphs are subsets of vertices within a graph in which every vertex is connected to every other
 vertex in the same subset. In other words, a connected component is a subgraph in which there is a path between any two vertices.

A graph may have one or more connected components, and each connected component represents a group of vertices that are
 mutually reachable, while there are no edges connecting vertices in different connected components.

Vertexes of two connected component do not have  a path

-No. of times DFS/BFS is called = No. of connected components


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> g;
int v; // no. of vertices

void dfs(int node,unordered_set<int> &visited) {
    visited.insert(node);
    for(auto &neigh:g[node]){
        if (not visited.count(neigh)){
            dfs(neigh,visited);
        }
    }
}

int cc(){
    int result=0;
    unordered_set<int> visited;
    for (int i = 0; i < v; ++i) {
        //go to every vertex and if from a vertex we can initialise a dfs then we get one more cc
        if (visited.count(i)==0){
            result++;
            dfs(i,visited);
        }
    }
    return result;
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

    cout<<"Number of Connected Component in the graph are :"<<cc();

    return 0;
}

Output:-
Enter no. of vertices:6
Enter no. of edges :8
0 1
1 4
4 3
3 0
3 1
2 5
2 6
5 6
Number of Connected Component in the graph are :2

-2.Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume
 all four edges of the grid are all surrounded by water.

-Using BFS

int numIslands(vector<vector<char>>& grid) {
    int rows=grid.size();
    int cols=grid[0].size();
    int cc=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            //water body
            if(grid[i][j]=='0'){
                continue;
            }
            //now land part
            cc++;
            queue<pair<int,int>> q;
            q.push({i,j});
            grid[i][j]='0';
            while(not q.empty()){
                pair<int,int> curr=q.front();
                q.pop();
                int currRows=curr.first;
                int currCols=curr.second;
                //left
                if(currCols>0 and grid[currRows][currCols-1]=='1'){
                    q.push({currRows,currCols-1});
                    grid[currRows][currCols-1]='0'; //marked visited for next cycle
                }
                //right
                if(currCols+1<cols and grid[currRows][currCols+1]=='1'){
                    q.push({currRows,currCols+1});
                    grid[currRows][currCols+1]='0'; //marked visited for next cycle
                }
                //up
                if(currRows>0 and grid[currRows-1][currCols]=='1'){
                    q.push({currRows-1,currCols});
                    grid[currRows-1][currCols]='0';
                }

                //down
                if(currRows+1<rows and grid[currRows+1][currCols]=='1'){
                    q.push({currRows+1,currCols});
                    grid[currRows+1][currCols]='0';
                }

            }
        }
    }
    return cc;
}

-Using DFS

int rows,cols;
void dfs(vector<vector<char>> &grid,int i,int j){
    grid[i][j]='0';
    if(j>0 and grid[i][j-1]=='1'){
        dfs(grid,i,j-1);
    }
    //right
    if(j+1<cols and grid[i][j+1]=='1'){
        dfs(grid,i,j+1);
    }
    //up
    if(i>0 and grid[i-1][j]=='1'){
        dfs(grid,i-1,j);
    }

    //down
    if(i+1<rows and grid[i+1][j]=='1'){
        dfs(grid,i+1,j);
    }
}

int numIslands(vector<vector<char>>& grid) {
    rows=grid.size();
    cols=grid[0].size();
    int cc=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            //water body
            if(grid[i][j]=='0'){
                continue;
            }
            //now land part
            cc++;
            dfs(grid,i,j);
        }
    }
    return cc;
}

-3.Pacific Atlantic Water Flow - Uses concept of MultiSource BFS -> just add all sources to BFS in starting at once and rest all same

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches
 the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where
 heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east,
 and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from
 any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from
 cell (ri, ci) to both the Pacific and Atlantic oceans.

-> We have solved this question entirely based on assuming things opposite that water can flow from ocean to island and
 not the way the question asked , for water to flow from island to ocean; And we also used the concept of Multi source
 BFS

vector<vector<int>> h;
int rows,cols;
vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    h=heights;
    rows=h.size();
    cols=h[0].size();
    queue<pair<int,int>> atlantic;
    queue<pair<int,int>> pacific;

    for(int i=0;i<rows;i++){
        atlantic.push({i,cols-1});
        pacific.push({i,0});
    }

    for(int i=1;i<cols;i++){
        pacific.push({0,i});
    }

    for(int i=0;i<cols-1;i++){
        atlantic.push({rows-1,i});
    }

    vector<vector<bool>> atli=bfs(atlantic);
    vector<vector<bool>> paci=bfs(pacific);

    vector<vector<int>> ans;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(atli[i][j] and paci[i][j]){
                ans.push_back({i,j});
            }
        }
    }

    return ans;

}

vector<vector<bool>> bfs(queue<pair<int,int>>& q){
    vector<vector<bool>> visited(rows,vector<bool>(cols,false));
    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        int i=curr.first;
        int j=curr.second;
        visited[i][j]=true; //i.e. visited marked!

        for(int d=0;d<4;d++){
            //for its neighbours -> dir
            int currRow=i+dir[d][0];
            int currCol=j+dir[d][1];
            if(currRow < 0 or currCol < 0 or currRow >= rows or currCol >= cols) continue; //out of bounds
            if(visited[currRow][currCol]) continue; // already visited
            if(h[currRow][currCol]<h[i][j]) continue; // neighbour height is less then water will not flow -> we are thinking opposite
            q.push({currRow,currCol});
        }
    }
    return visited;
}


-4.Rotting Oranges

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

int orangesRotting(vector<vector<int>>& grid) {

    vector<vector<int>> dir={{1,0},{-1,0},{0,-1},{0,1}};
    int time=0;
    int m,n;
    queue<pair<int,int>> q;
    int fresh=0;  //no. of fresh oranges
    n=grid.size();
    m=grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                //rotten oranges
                q.push({i,j});
            }
            if(grid[i][j]==1){
                fresh++;
            }
        }
    }
    q.push({-1,-1}); //represent end of one level
    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        if(curr.first==-1 and curr.second==-1){
            time++;
            if(!q.empty()){
                q.push({-1,-1});
            }else{
                break;
            }
        }else{
            int i=curr.first;
            int j=curr.second;
            for(int d=0;d<4;d++){
                int r=i+dir[d][0];
                int c=j+dir[d][1];

                if(r<0 || c<0 || r>=n || c>=m) continue;
                if(grid[r][c]==0 || grid[r][c]==2) continue;
                grid[r][c]=2;
                fresh--;
                q.push({r,c});

            }
        }
    }
    return (fresh==0) ? time-1:-1;
}

-5. 01 Matrix

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.


vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>> ans(n,vector<int>(m,-1));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                ans[i][j]=0;
                q.push({i,j});
            }
        }
    }
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    while(!q.empty()){
        auto cell=q.front();
        q.pop();
        int i=cell.first;
        int j=cell.second;
        for(int d=0;d<4;d++){
            int r=i+dir[d][0];
            int c=j+dir[d][1];
            if(r<0 || c<0 || r>=n || c>=m) continue;
            if(ans[r][c]>=0) continue;
            ans[r][c]=ans[i][j]+1;
            q.push({r,c});

        }
    }
    return ans;
}

*/













