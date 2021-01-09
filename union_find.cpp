// Solving Leetcode 684: Redundant Connection using Union Find
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void init_unionset(int *unionset, int n){
        for(int i=1;i<n+1;i++){
            unionset[i] = i;
        }
    }
    
    int inSet(int x, int* unionset){
        while(x!=unionset[x]){
            unionset[x] = unionset[unionset[x]];
            x = unionset[x];
        }
        return x;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int m = edges.size();
        cout<<"edges: "<<m<<endl;
        int n = 0;
        int ans[2];
        for(int i=0;i<m;i++){
            n = n<max(edges[i][0], edges[i][1])?max(edges[i][0], edges[i][1]):n;
        }
        int unionset[n+1];
        memset(unionset, 0, sizeof(unionset));
        init_unionset(unionset, n);
        
        for(int i=0;i<m;i++){
            int x = edges[i][0];
            int y = edges[i][1];
            int w = 1;
            int p1 = inSet(x, unionset);
            int p2 = inSet(y, unionset);
            if(p1==p2){
                ans[0]=x;
                ans[1]=y;
            }
            else{
                unionset[p1]=unionset[p2];
            }
            
        }
        vector<int> v;
        v.push_back(ans[0]);
        v.push_back(ans[1]);
        return v;
    }
};