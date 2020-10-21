//working
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef pair<int,int> pii;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n,m;
    cin>>n>>m;

    int dist[n+1];  //do not use INF
    memset(dist,-1,sizeof(dist));
    vector< pair<int,int> > adj[n+1];

    rep(i,0,m){
        int a,b,d;
        cin>>a>>b>>d;
        adj[a].push_back(make_pair(d,b)); //list stored as (dist,adj node)
        adj[b].push_back(make_pair(d,a)); 
    }

    int src;
    cin>>src;

    priority_queue< pii, vector <pii> , greater<pii> > q;
    
    q.push(make_pair(0,src));
    dist[src]=0;
    while(!q.empty()){

       pair<int,int> p=q.top();
        q.pop();

        int n=p.second; //node
        int d=p.first; //dist

        int sz=adj[n].size();
        rep(i,0,sz){

            pair<int ,int> temp=adj[n][i];
            int a=temp.first;
            int b=temp.second;
            if(dist[b]==-1 || dist[b]>d+a){
                dist[b]=d+a;
                q.push(make_pair(dist[b],b));
            }
        }

    }

    for(int i=1;i<=n;i++){
        if(i==src)continue;
        else cout<<dist[i]<<" ";
    }
    }
    return 0;
}