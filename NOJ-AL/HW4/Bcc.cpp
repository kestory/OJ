Description

 给定一个无向图，输出BCC的数量。

Input

 一个图。

第一行的1个数代表点的个数。

之后每一行的第一个数是点的编号，之后也是一些点的编号，代表前者到后者有边，每行以-1结束。

Sample Input是书上的Figure 7.22

Output

BCC的数量。

Sample Input

10
0 3 5 7 -1
1 2 4 6 8 -1
2 4 -1
3 5 9 -1
4 5 -1
5 7 9 -1
6 8 -1
Sample Output

4
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
geekforgeek代码再改了下输入方式
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <list>
#include <stack>
#define NIL -1
using namespace std;
int the_count = 0;//count is ambitious
class Edge
{
public:
	int u;
	int v;
	Edge(int u, int v);
};
Edge::Edge(int u, int v)
{
	this->u = u;
	this->v = v;
}

// A class that represents an directed graph
class Graph
{
	int V;    // No. of vertices
	int E;    // No. of edges
	list<int> *adj;    // A dynamic array of adjacency lists

	// A Recursive DFS based function used by BCC()
	void BCCUtil(int u, int disc[], int low[],
	             list<Edge> *st, int parent[]);
public:
	Graph(int V);   // Constructor
	void addEdge(int v, int w);   // function to add an edge to graph
	void BCC();    // prints strongly connected components
};

Graph::Graph(int V)
{
	this->V = V;
	this->E = 0;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	E++;
}

// A recursive function that finds and prints strongly connected
// components using DFS traversal
// u --> The vertex to be visited next
// disc[] --> Stores discovery times of visited vertices
// low[] -- >> earliest visited vertex (the vertex with minimum
//             discovery time) that can be reached from subtree
//             rooted with current vertex
// *st -- >> To store visited edges
void Graph::BCCUtil(int u, int disc[], int low[], list<Edge> *st,
                    int parent[])
{
	// A static variable is used for simplicity, we can avoid use
	// of static variable by passing a pointer.
	static int time = 0;

	// Initialize discovery time and low value
	disc[u] = low[u] = ++time;
	int children = 0;

	// Go through all vertices adjacent to this
	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i;  // v is current adjacent of 'u'

		// If v is not visited yet, then recur for it
		if (disc[v] == -1)
		{
			children++;
			parent[v] = u;
			//store the edge in stack
			st->push_back(Edge(u, v));
			BCCUtil(v, disc, low, st, parent);

			// Check if the subtree rooted with 'v' has a
			// connection to one of the ancestors of 'u'
			// Case 1 -- per Strongly Connected Components Article
			low[u]  = min(low[u], low[v]);

			//If u is an articulation point,
			//pop all edges from stack till u -- v
			if ( (disc[u] == 1 && children > 1) ||
			        (disc[u] > 1 && low[v] >= disc[u]) )
			{
				while (st->back().u != u || st->back().v != v)
				{
					//cout << st->back().u << "--" << st->back().v << " ";
					st->pop_back();
				}
				//cout << st->back().u << "--" << st->back().v;
				st->pop_back();
				//cout << endl;
				the_count++;
			}
		}

		// Update low value of 'u' only of 'v' is still in stack
		// (i.e. it's a back edge, not cross edge).
		// Case 2 -- per Strongly Connected Components Article
		else if (v != parent[u] && disc[v] < low[u])
		{
			low[u]  = min(low[u], disc[v]);
			st->push_back(Edge(u, v));
		}
	}
}

// The function to do DFS traversal. It uses BCCUtil()
void Graph::BCC()
{
	int *disc = new int[V];
	int *low = new int[V];
	int *parent = new int[V];
	list<Edge> *st = new list<Edge>[E];

	// Initialize disc and low, and parent arrays
	for (int i = 0; i < V; i++)
	{
		disc[i] = NIL;
		low[i] = NIL;
		parent[i] = NIL;
	}

	for (int i = 0; i < V; i++)
	{
		if (disc[i] == NIL)
			BCCUtil(i, disc, low, st, parent);

		int j = 0;
		//If stack is not empty, pop all edges from stack
		while (st->size() > 0)
		{
			j = 1;
			//cout << st->back().u << "--" << st->back().v << " ";
			st->pop_back();
		}
		if (j == 1)
		{
			//cout << endl;
			the_count++;
		}
	}
}

// Driver program to test above function
int main()
{
	int n;
	cin >> n;
	Graph g(n);
	int a, b;
	/*
		for (int i = 0; i < n; ++i)
		{
			cin >> a >> b;
			while (b != -1) {
				g.addEdge(a, b);
				g.addEdge(b, a);
				cin >> b;
			}
		}
	*/
	cin >> a;
	while (cin >> b) {
		while (b != -1) {
			g.addEdge(a, b);
			g.addEdge(b, a);
			//D(a)D(b)
			cin >> b;
		}
		cin >> a;
	}

	g.BCC();
	cout << the_count;
	return 0;
}
