//HACKERRANK
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define pb push_back
typedef pair<int,int[]> pii;
vector<vector<int> > g;
int main()
{
    int q;
    cin>>q;
    while(q--){
    int n, e;
    cin >> n >> e;

    bool v[n+1]={false};
    
    int ddis[n+1]={-1};
    g.assign(n+1, vector<int>()); //very IMP-Any elements held in the container before the call are destroyed and replaced by newly constructed elements 
    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    int u;
    cin>>u;

    queue<int> q;
 
    q.push(0);
    v[u] = true;
    ddis[u]=0;
    while (!q.empty()) {
 
        int f = q.front();
        q.pop();
 
        for (int j=0;j<g[f].size(); j++) {
            int i=g[f][j];
            //cout<<"test1";
            if (!v[i]) {
                q.push(i);
                v[i] = true;
                ddis[i]=ddis[f]+6;
                //cout<<ddis[i]<<" "<<ddis[f]<<" "<<f<<" ";
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(i!=u){
            if(v[i]==true)cout<<ddis[i]<<" ";
            else cout<<-1<<" ";
        }
    }
        cout<<endl;

    }
    return 0;
}