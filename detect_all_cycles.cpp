// C++ program to print all the cycles 
// in an undirected graph 
//CONCEPT-use colors
#include <bits/stdc++.h> 
using namespace std; 
const int N = 100000; 

// variables to be used 
// in both functions 
vector<int> graph[N]; 
vector<int> cycles[N]; 

// Function to mark the vertex with 
// different colors for different cycles 
void dfs_cycle(int node,int parent,int color[],int mark[],int par[],int cyclenumber){
	if(color[node]==2)return;
	if(color[node]==1){
		int curr=parent;
		cyclenumber++;
		mark[parent]=cyclenumber;
		//backtrack
		while(curr!=node){
			curr=par[curr];
			mark[curr]=cyclenumber;
		}
		return;
	}
	par[node]=parent;
	color[node]=1;
	for(int ii=0;ii<graph[node].size();ii++){
		//if not visited previously
		if(graph[node][ii]==par[node])continue;
		dfs_cycle(graph[node][ii],node,color,mark,par,cyclenumber);
	}
	//all descendants seen so change the color
	color[node]==2;
}

// add the edges to the graph 
void addEdge(int u, int v) 
{ 
	graph[u].push_back(v); 
	graph[v].push_back(u); 
} 

// Function to print the cycles 
void printCycles(int edges, int mark[], int& cyclenumber) 
{ 
	for (int i = 1; i <= edges; i++) { 
		if (mark[i] != 0) 
			cycles[mark[i]].push_back(i); 
	} 

	// print all the vertex with same cycle 
	for (int i = 1; i <= cyclenumber; i++) { 
		// Print the i-th cycle 
		cout << "Cycle Number " << i << ": "; 
		for (int x : cycles[i]) 
			cout << x << " "; 
		cout << endl; 
	} 
} 

// Driver Code 
int main() 
{ 
	addEdge(1, 2); 
	addEdge(2, 3); 
	addEdge(3, 4); 
	addEdge(4, 6); 
	addEdge(4, 7); 
	addEdge(5, 6); 
	addEdge(3, 5); 
	addEdge(7, 8); 
	addEdge(6, 10); 
	addEdge(5, 9); 
	addEdge(10, 11); 
	addEdge(11, 12); 
	addEdge(11, 13); 
	addEdge(12, 13); 

	int color[N]; 
	int par[N];  
	int mark[N]; 
	int cyclenumber = 0; 
	int edges = 13; 
	dfs_cycle(1, 0, color, mark, par, cyclenumber); 
	printCycles(edges, mark, cyclenumber); 
} 
