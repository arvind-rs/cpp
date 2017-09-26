
/*
 * Graph implementation using adjacency list in c++.
 * Also implemented Breadth First Search and Depth First Search.
 * @author: ArvindRS
 * @date: 09/26/2017
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {

private:
	int V;
	vector<int> *adj;
public:
	// Public constructor
	Graph(int vt) {
		V = vt + 1; // Adding 1 as we'll not store a graph node in the 0th index of the array.
		adj = new vector<int>[V];
	}

	// Method to test if graph is empty
	bool is_empty() {
		for(int i = 0; i < V; i++) {
			if(adj[i].size() > 0)
				return false;
		}
		return true;
	}

	// Method to add edges to the graph
	void add_edge(int v, int w) {
		adj[v].push_back(w);
		adj[w].push_back(v);
	}

	// Method to get vertex count
	int get_size() {
		return V;
	}

	// Method to get the adjacent vertices of a vertex
	vector<int> get_adjacent_vertices(int v) {
		return adj[v];
	}

	// Display the graph
	void display() {
		for(int i = 0; i < get_size(); i++) {
			cout << i << "->";
			auto v = get_adjacent_vertices(i);
			for(auto it = v.begin(); it != v.end(); it++)
				cout << *it << " ";
			cout << endl;
		}
	}

	// Method to perform breadth first traversal on the graph
	void bfs(int start) {
		// Declare a queue
		queue<int> q;
		// Declare a boolean array to mark vertices as visited
		bool visited[V];
		for(int i = 0; i < V; i++)
			visited[i] = false;
		// Add the start node to the queue and mark it as visited
		q.push(start);
		visited[start] = true;
		while(q.size() > 0) {
			// Pop an element from the queue
			int node = q.front();
			q.pop();
			// Print the node
			cout << node << endl;
			// Add it's neighbours to the queue
			auto v = get_adjacent_vertices(node);
			for(auto it = v.begin(); it != v.end(); it++) {
				// If the neighbour has not been added to the queue before then mark it and add it
				if(visited[*it] == false) {
					visited[*it] = true;
					q.push(*it);
				}	
			}
		}
	}

	// Wrapper method for the recursive depth first traversal algorithm
	void dfs(int start) {
		bool visited[V];
		for(int i = 0; i < V; i++)
			visited[i] = false;
		dfs(start, visited);
	}

private:
	// Private overloaded DFS method
	void dfs(int node, bool visited[]) {
		// Process the node and mark it as visited
		cout << node << endl;
		visited[node] = true;
		// Recursively visit all of it's neighbours.
		// DFS actually uses a stack. But as we are using recursion here the stack is the implicit function call stack.
		auto v = get_adjacent_vertices(node);
		for(auto it = v.begin(); it != v.end(); it++) {
			if(!visited[*it]) {
				dfs(*it, visited);
			}
		}
	}
};

// Main function
int main() {

	Graph g(4);

	cout << g.is_empty() << endl;
	g.add_edge(1,2);
	g.add_edge(2,3);
	g.add_edge(1,4);
	cout << g.is_empty() << endl;

	g.display();

	g.bfs(1);
	g.dfs(1);
}