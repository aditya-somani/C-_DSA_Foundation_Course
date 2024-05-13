/*

-And with that I have completed both Kruskal and prims algorithm which are used to make a minimum spanning tree , both algo's
 are really really IMP , so make sure to give them a good revision , if you have to DRY-RUN them .

-Notes and some key points are written in note book so see it.

-HAve a good Day Ahead!

-Minimum Spanning Tree

Given an undirected weighted connected graph, find the Really Special SubTree in it. The Really Special SubTree is
 defined as a subgraph consisting of all the nodes in the graph and:

-There is only one exclusive path from a node to every other node.
-The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
-No cycles are formed

-->Solution/Pseudo-Code:-

To create the Really Special SubTree, always pick the edge with smallest weight. Determine if including it will create a cycle.
 If so, ignore the edge. If there are edges of equal weight available:

-Choose the edge that minimizes the sum  where  and  are vertices and  is the edge weight.
-If there is still a collision, choose any of them.

Print the overall weight of the tree formed using the rules.

-KRUSKAL'S ALGORITHM -> NOTES ARE IN NOTEBOOK!

-Time complexity - O(v + ElogE)

#include <bits/stdc++.h>
using ll=long long;
using namespace std;

vector<int> parent;
vector<int> ranki;
int v,e;

int find(int x){
    return parent[x]=parent[x]==x ? x:find(parent[x]);
}

void Union(int src,int dest){
    src= find(src);
    dest= find(dest);
    if(src==dest) return; // cycle found
    if (ranki[src]>=ranki[dest]){
        ranki[src]++;
        parent[dest]=src;
    }else{
        ranki[dest]++;
        parent[src]=dest;
    }
}

struct Edge{
    int source;
    int destination;
    int weight;
};

bool cmp(Edge a,Edge b){
    return a.weight<b.weight;  //ascending order
}

ll kruskal(vector<Edge> &input){
    sort(input.begin(),input.end(),cmp);  // TC :- ElogE
    parent.resize(v+1);
    ranki.resize(v+1,1);
    for(int i=0;i<=v;i++){
        parent[i]=i;
    }
    int edgeCount=0;// as in tree number of edges should be always less than v-1;
    int i=0;
    ll ans=0;
    while(edgeCount<v-1 && i<input.size()){ // tc :- v-1 ~~ vlog*v ~~ v
        Edge curr=input[i];
        int src=curr.source;
        int dest=curr.destination;
        src= find(src);
        dest= find(dest);
        if(src!=dest){
            //their parent are different -> no cycle will be formed by including them
            Union(src,dest);
            ans+=curr.weight;
            edgeCount++;
        }
        //regardless if cycle i formed or not , we still need to move to next element
        i++;
    }
    return ans;
}

int main(){
    cout<<"Enter the vertices and edges :";
    cin>>v>>e;
    vector<Edge> v(e);
    cout<<"Enter the source and destination and weight of graph :"<<endl;
    for (int i = 0; i < e; ++i) {
        cin>>v[i].source>>v[i].destination>>v[i].weight;
    }
    cout<<"Minimum Spanning Tree is of weight :"<<kruskal(v);
    return 0;
}

Output:-
Enter the vertices and edges :4 6
Enter the source and destination and weight of graph :
1 2 5
1 3 3
4 1 6
2 4 7
3 2 4
3 4 5
Minimum Spanning Tree is of weight :12


-PRIM'S ALGORITHM -> NOTES ARE IN NOTEBOOK!

-The actual implementation of Prim's is by using a type of heap called fibonacci heap but as making it is beyond our current
 capabilities we are using priority_queue which is also internally a heap (Binary Heap).

-Q.Given a graph which consists of several edges connecting its nodes, find a subgraph of the given graph with the following properties:

    -The subgraph contains all the nodes present in the original graph.
    -The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
    -It is also required that there is exactly one, exclusive path between any two nodes of the subgraph.

One specific node  is fixed as the starting point of finding the subgraph using Prim's Algorithm.
Find the total weight or the sum of all edges in the subgraph.

NOTE :- This question is basedd on 1-BASED INDEXING , so make sure to have this is mind that vertexes are from 1<=v<=n.

-Time Complexity:  O(v log V).

#include <bits/stdc++.h>
using namespace std;

using ll=long long int;
using p=pair<int,int>;

vector<list<p>> graph;
int v,e;

ll prims(int src){
    priority_queue<p , vector<p> , greater<p>> pq;  //minPQ
    unordered_set<int> vis;
    vector<int> parent(v+1);
    unordered_map<int,int> dis;

    for(int i=1;i<=v;i++){
        dis[i]=INT_MAX;
    }

    pq.push({0,src});
    dis[src]=0;

    int totalCount =0;  // < v-1
    ll result =0;
    while(totalCount<v && !pq.empty()){ //as here we have one based indexing so condiiton will be < v not < v-1
        p curr=pq.top();
        pq.pop();
        int pqWeight = curr.first;
        int pqNode = curr.second;
        if (vis.count(pqNode)) continue; //no need to go further as the node is already visited
        vis.insert(pqNode);
        totalCount++;
        result+=pqWeight;
        for(auto &neigh:graph[pqNode]){
            int node=neigh.first;
            int weight=neigh.second;
            if (!vis.count(node) && dis[node] > weight){
                pq.push({weight,node});
                parent[node]=pqNode;
                dis[node]=weight;
            }
        }
    }
    return result;
}

int main(){
    cout<<"Enter the no. of vertices and edges :";
    cin>>v>>e;
    cout<<"Enter the src ,dest and weight :"<<endl;
    graph.resize(v+1,list<p> ());
    while(e--){
        int s,d,w;
        cin>>s>>d>>w;
        graph[s].push_back({d,w});
        graph[d].push_back({s,w});
    }
    cout<<"Enter the source node :";
    int src;
    cin>>src;
    cout<<"Minimum Spanning Tree is of weight : "<<prims(src);
    return 0;
}

Output:-
Enter the no. of vertices and edges :5 6
Enter the src ,dest and weight :
1 2 3
1 3 4
4 2 6
5 2 2
2 3 5
3 5 7
Enter the source node :1
Minimum Spanning Tree is of weight : 15



*/








