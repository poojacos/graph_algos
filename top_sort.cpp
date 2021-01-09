/*
Given a Directed and Acyclic Graph having N vertices and M edges, print topological sorting of the vertices.

Input:
First line consists of two space separated integers denoting N and M.
Each of the following M lines consists of two space separated integers X and Y denoting there is an from X directed towards Y.

Output:
Print N space separated integers denoting the topological sort, if there are multiple ordering print the lexicographically smallest one.
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 12

void top_sort(stack<int> &q, vector<vector<int> > &v, int i,bool visited[]){
    visited[i]=true;
    for(int j=0;j<v[i].size();j++){
        if(!visited[v[i][j]]){
            top_sort(q,v,v[i][j],visited);
        }
    }
    q.push(i);
}

void top_util(stack<int> &q, vector<vector<int> > &v, int n){
    bool visited[MAX];
    for(int i=0;i<=n;i++){
        visited[i]=false;
        sort(v[i].begin(),v[i].end(),greater<int>());
    }
    for(int i=n;i>0;i--){
        if(!visited[i]){
            top_sort(q,v,i,visited);
        }
    }
}

int main(){
    int n,m,x,y;
    vector<vector<int> > v(MAX);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        //v[y].push_back(x);
    }
    
    stack<int> q;
    top_util(q,v,n);
    while(!q.empty()){
        printf("%d ",q.top());
        q.pop();
    }
    printf("\n");
    return 0;
}