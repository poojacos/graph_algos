//https://www.hackerrank.com/challenges/kruskalmstrsub/problem

#include <bits/stdc++.h>

using namespace std;
#define MAX 30000
#define rep(i,a,b) for(int i=a;i<b;i++)
pair<int, pair<int,int> > p[MAX];
int unionset[MAX];
int n,m;

void initSet(int n){
	rep(i,1,n+1){
		unionset[i]=i;
	}
}

int inSet(int x){
	while(unionset[x]!=x){
		unionset[x]=unionset[unionset[x]];
		x=unionset[x];
	}
	return x;
}

int main(){
	int w,x,y;
	cin>>n>>m;
	initSet(n);

	rep(i,0,m){
		cin>>x>>y>>w;
		p[i]=make_pair(w,make_pair(x,y));
	}

	sort(p,p+m);
	int cost=0;
	rep(i,0,m){
		int x=p[i].second.first;
		int y=p[i].second.second;
		int w=p[i].first;

		if(inSet(x)!=inSet(y)){
			cost+=w;
			int p=inSet(x);
			int q=inSet(y);
			unionset[p]=unionset[q];
		}
	}
	cout<<cost<<endl;
}
