/*

-Graph Implementation

There are many ways to represent a graph, and the choice mainly depends on the situation in which it is being used.
 However, the most commonly used representations are:

1. Adjacency Matrix
2. Adjacency List
3. Edge List

In these methods of representation, each node is represented by a number. If there are N nodes,
 we represent each node with a unique value between ‘0’ and ‘N-1’. The order in which we assign each node a value
 entirely depends on your preference.

In 90% of cases, we will use the adjacency list representation.

1.Edge List

-In edge list we make three classes -> 1. Node -> consists of value
 2. Edge -> consist of source , destination nodes , weight of edge , and if it is directional or not (bool) .
 3.Graph -> consists of vector of Nodes as well as edges!

This is the cleanest approach but also the most time-consuming as well as not so competition friendly .

2.Adjacency List - neighbour's info is stored in array of linked list .

An adjacency list is a data structure used to represent a graph where each node in the graph stores a list of
 its neighboring vertices. It is an array of linked lists, where the index of the array represents a vertex and
 each element in its linked list represents the other vertices that form an edge with that vertex.

 eg:- here is an undirected graph

1 -- 2
| \  |
|  3
| /  |
0 -- 4

We can represent this graph in the form of a linked list on a computer as shown below:

0 -> 1 -> 4
1 -> 0 -> 2
2 -> 1 -> 3
3 -> 2
4 -> 0

-Used generally for sparse Graph

-3.Adjacency map - array of hashmap/unordered map -> same as previous just we use hashmap to store instead of linked list

->Efficient for questions where it is asked if "a is neighbour of b"

An adjacency map is a data structure used to represent a graph where each vertex in the graph is associated with a map
 that stores the adjacent vertices and the corresponding edge weights. It is similar to an adjacency list, but instead
 of storing a list of adjacent vertices, it stores a map that maps each adjacent vertex to the edge weight.

For example, consider the following undirected graph with edge weights:

1 -- 2 (3)
| \  |
|  3
| /  |
0 -- 4 (1)

We can represent this graph in the form of a map on a computer as shown below:
0: {4: 1}
1: {0: 3, 2: 3, 3: 1}
2: {1: 3}
3: {1: 1}
4: {0: 1}

Here, 0, 1, 2, 3, and 4 are the vertices and each of them is associated with a map that stores the adjacent vertices
 and the corresponding edge weights. For instance, vertex 1 has three adjacent vertices 0, 2, and 3 with edge
 weights 3, 3, and 1 respectively. Therefore, 1 is associated with a map that maps 0, 2, and 3 to 3, 3, and 1 respectively.

-4.Adjacency Matrix - we represent graph as matrix of vxv dimension where v is the number of vertices

In this vertex ,

arr[i][j] = 1 -> represent that there is an edge from ith to jth vertex
arr[i][j] = 0 -> represent no edge

If weight is coming then instead of 1 , just store the weight and instead of 0 just store -1 or INT_MAX
-It is not space efficient
-Suitable for Dense graph

-5.Incidence Matrix - in this we represent graph with a vxe matrix where v is the no. of vertices and e is the no. of edges

arr[i][j]=1 -> represent if ith vertex belongs to jth edge
arr[i][j]=0 -> it does not

In case of directed graph -> we give preference to the node which is being pointed
For self loop just put value arr[i][j]=2;

-Use for space optimization on sparse graph but doesn't make that much of a difference

-At the end the most usefull and used are -> 1. Adj list and 2.Adj matrix

-Code for Adjacency list

-Mistake I was doing , I didn't resize the vector of list


#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<list<pair<int, int>>> graph; // Corrected graph structure
int v; // Number of vertices

// Adds an edge to the graph
void add_edge(int src, int des, int wt = -1, bool biDirectional = true) {
    graph[src].push_back(make_pair(des, wt));
    if (biDirectional) {
        graph[des].push_back(make_pair(src, wt));
    }
}

// Displays the graph
void display() {
    cout<<"Adjacency List is :"<<endl;
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";
        for (auto& p : graph[i]) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Enter no. of vertices:";
    cin >> v;
    graph.resize(v,list<pair<int,int>> ()); // Resize the graph to hold 'v' vertices

    cout << "Enter the no. of edges:";
    int e; cin >> e;
    cout << "Enter source, destination, weight (-1 if unweighted):"<<endl;
    while (e--) {
        int s, d, w;

        cin >> s >> d >> w;
        add_edge(s, d, w);
    }
    display();
    return 0;
}

Output:-
Enter no. of vertices:7
Enter the no. of edges:7
Enter source, destination, weight (-1 if unweighted):
0 2 2
0 1 1
1 5 3
2 5 2
2 3 6
3 6 2
6 4 4
Adjacency List is :
0 -> (2, 2) (1, 1)
1 -> (0, 1) (5, 3)
2 -> (0, 2) (5, 2) (3, 6)
3 -> (2, 6) (6, 2)
4 -> (6, 4)
5 -> (1, 3) (2, 2)
6 -> (3, 2) (4, 4)

-Code for Adjacency map

Simply instead of list use unordered map


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<unordered_map<int,int>> graph; // Corrected graph structure
int v; // Number of vertices

// Adds an edge to the graph
void add_edge(int src, int des, int wt = -1, bool biDirectional = true) {
    graph[src][des]=wt;
    if (biDirectional) {
        graph[des][src]=wt;
    }
}

// Displays the graph
void display() {
    cout<<"Adjacency Map is :"<<endl;
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";
        for (auto& p : graph[i]) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Enter no. of vertices:";
    cin >> v;
    graph.resize(v,unordered_map<int,int> ()); // Resize the graph to hold 'v' vertices

    cout << "Enter the no. of edges:";
    int e; cin >> e;
    cout << "Enter source, destination, weight (-1 if unweighted):"<<endl;
    while (e--) {
        int s, d, w;

        cin >> s >> d >> w;
        add_edge(s, d, w);
    }
    display();
    return 0;
}

Output:-
Enter no. of vertices:7
Enter the no. of edges:7
Enter source, destination, weight (-1 if unweighted):
0 2 2
0 1 1
1 5 3
2 5 2
2 3 6
3 6 2
6 4 4
Adjacency Map is :
0 -> (1, 1) (2, 2)
1 -> (5, 3) (0, 1)
2 -> (3, 6) (5, 2) (0, 2)
3 -> (6, 2) (2, 6)
4 -> (6, 4)
5 -> (2, 2) (1, 3)
6 -> (4, 4) (3, 2)

*/












