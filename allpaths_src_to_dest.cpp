
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > allpaths;
void dfs(int v, int t, vector<int> &path, vector<vector<int> >& graph, vector<bool>& visited){
    visited[v]=true;
    path.push_back(v);
    
    if(v==t){
        allpaths.push_back(path);
    }
    else{
        for(int i=0;i<graph[v].size();i++){
            int neighbour = graph[v][i];
            if(!visited[neighbour]){
                dfs(neighbour, t, path, graph, visited);
            }
        }
    }
    
    visited[v] = false;
    path.pop_back();
}

void allPathsSourceTarget(vector<vector<int> >& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> path;
    dfs(0,n-1, path, graph, visited);
}

int main(){
    // graph is adjacency list
    // vertices are numbered 0 to n-1
    // graph = [[1,2],[3],[3],[]]
    vector<vector<int> >graph;
    vector<int> v0;
    v0.push_back(1);
    v0.push_back(2);
    vector<int> v1;
    v1.push_back(3);
    vector<int> v2;
    v2.push_back(3);
    vector<int> v3;
    graph.push_back(v0);
    graph.push_back(v1);
    graph.push_back(v2);
    graph.push_back(v3);
    
    allPathsSourceTarget(graph);
    for(int i=0;i<allpaths.size();i++){
        cout<<"path "<<i<<": ";
        for(int j=0;j<allpaths[i].size();j++){
            cout<<allpaths[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}