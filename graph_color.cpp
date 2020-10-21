//given a graph and m colors
//workssss
#include<bits/stdc++.h>
using namespace std;
bool allowed(vector<vector<int> > &g,int v_num, vector<int> &v){
	for(int i=0;i<v_num;i++){
		//cout<<"adjacent?= "<<g[v_num][i]<<" v_num= "<<v_num<<" color= "<<v[v_num]<<" adjacent= "<<i<<" color= "<<v[i]<<endl;
		if(g[v_num][i]==1 && v[v_num]==v[i])return false;
	}
	return true;
}

bool Coloring(vector<vector<int> > &g, int m, vector<int> &v, int v_num){
	//v_num is the vertex we are coloring
	if(v_num==v.size())return true;
	for(int i=1;i<=m;i++){
		v[v_num]=i;
		if(allowed(g,v_num,v)==true){
			if(Coloring(g,m,v,v_num+1))
				return true; //if this statement is not added then it will continue to test on other remaining colors as well
		}
		else v[v_num]=0;
	}
	return false;
}

void graph_col(vector<vector<int> > &g, int m, vector<int> &v){
	if(Coloring(g,m,v,0)==false){
		printf("coloring graph with %d colors is not possible\n",m);
		return;
	}
	printf("graph coloring possible\n");
	for(int i=0;i<v.size();i++){
		printf("vertice %d - color - %d\n",i,v[i]);
	}
}

int main(){
	//get number of vertices
	int n;
	scanf("%d",&n);
	vector<vector<int> > g(n,vector<int>(n,0));
	int edges;
	//get edges stored in matrix format
	scanf("%d",&edges);
	for(int i=0;i<edges;i++){
		int e1,e2;
		scanf("%d%d",&e1,&e2);
		g[e1][e2]=1;
		g[e2][e1]=1;
	}
	//get required color number
	int m;
	scanf("%d",&m);
	//initialize vector storing colors for vertices
	vector<int> v(n,0);
	graph_col(g,m,v);
}
