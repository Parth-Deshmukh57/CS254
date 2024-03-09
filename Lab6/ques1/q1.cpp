#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void topologicalSort(vector<int> adj[],int V,vector<int> &indegree){
    queue<int> q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";

        for(auto it :adj[u]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }

}



int main() {
    freopen("input_1.txt", "r", stdin);
    freopen("output_1.txt", "w", stdout);
    int t;cin >> t;
    while (t--) {
        int V;cin >> V;
        int E;cin >> E;
        vector<int>adj[V];
        for (int i = 0;i < E;i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        
        topologicalSort(adj, V,indegree);
        cout<<endl;
    }
    return 0;
}