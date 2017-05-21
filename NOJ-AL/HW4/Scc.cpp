Description

给定一个有向图，输出SCC的数量。

Input

一个图。

第一行的1个数代表点的个数。

之后每一行的第一个数是点的编号，之后也是一些点的编号，代表前者到后者有边，每行以-1结束。

Sample Input是书上的Figure 7.20

Output

SCC的数量。

Sample Input

7
0 1 2 5 -1
1 2 3 -1
3 0 2 -1
4 2 6 -1
5 0 2 -1
6 3 4 -1
Sample Output

3
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
geekforgeek代码再改了下输入方式
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <list>
#include <stack>
using namespace std;
#define D(x) cout<<#x<<"="<<x<<endl;
class Graph
{
	int V;    // No. of vertices
	list<int> *adj;    // An array of adjacency lists

	// Fills Stack with vertices (in increasing order of finishing
	// times). The top element of stack has the maximum finishing time
	void fillOrder(int v, bool visited[], stack<int> &Stack);
	void DFSUtil(int v, bool visited[]);//A recursive function to print DFS starting from v
public:
	Graph(int V);
	void addEdge(int v, int w);
	void printSCCs();//finds and prints scc
	Graph getTranspose();// Function that returns reverse (or transpose) of this graph
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

// A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and print it
	visited[v] = true;
	//cout << v << " ";

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 0; v < V; v++)
	{
		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			g.adj[*i].push_back(v);
		}
	}
	return g;
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
	// Mark the current node as visited and print it
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			fillOrder(*i, visited, Stack);

	// All vertices reachable from v are processed by now, push v
	Stack.push(v);
}

// The main function that finds and prints all strongly connected
// components
void Graph::printSCCs()
{
	int n = 0;
	stack<int> Stack;

	// Mark all the vertices as not visited (For first DFS)
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Fill vertices in stack according to their finishing times
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			fillOrder(i, visited, Stack);

	// Create a reversed graph
	Graph gr = getTranspose();

	// Mark all the vertices as not visited (For second DFS)
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Now process all vertices in order defined by Stack
	while (Stack.empty() == false)
	{
		// Pop a vertex from stack
		int v = Stack.top();
		Stack.pop();

		// Print Strongly connected component of the popped vertex
		if (visited[v] == false)
		{
			n++;
			gr.DFSUtil(v, visited);
			//cout << endl;
		}
	}
	cout << n;
}

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
				cin >> b;
			}
		}
	*/
	cin >> a;
	while (cin >> b) {
		while (b != -1) {
			g.addEdge(a, b);
			//D(a)D(b)
			cin >> b;
		}
		cin >> a;
	}

	/*
	string str;
	while (cin>>str) {
		cout << str << endl;
		getline(cin, str);
	}
	*/
	g.printSCCs();

	return 0;
}
