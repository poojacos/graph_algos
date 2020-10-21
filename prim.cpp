
// https://www.hackerrank.com/challenges/primsmstsub/problem#include 
<bits/stdc++.h>
using namespace std;
#define MAX 4000
#define rep(i,a,b) for(int i=a;i<b;i++)
int n,m;
typedef pair<int,int> pii;
vector <pii> adj[MAX];
bool vis[MAX];

int main(){
	int a,b,w,cost=0;
	cin>>n>>m;
	rep(i,0,m){
		cin>>a>>b>>w;
		adj[a].push_back(make_pair(w,b));
		adj[b].push_back(make_pair(w,a));
	}

	priority_queue <pii,vector<pii>,greater<pii> > q;
	int y;
	pii p;
	q.push(make_pair(0,1));
	while(!q.empty()){
		p=q.top();
		q.pop();
		y=p.second;
		if(vis[y]==true)continue;

		vis[y]=true;
		cost+=p.first;
		rep(i,0,adj[y].size()){
			int x=adj[y][i].second;
			if(vis[x]==false){
				q.push(adj[y][i]);
			}
		}
	}
	cout<<cost<<endl;
	return 0;
}