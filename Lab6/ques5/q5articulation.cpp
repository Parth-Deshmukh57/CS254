#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int timer = 0;


using namespace std;



void dfs(int node, int parent, vector<int>& vis, int discovery_time[], int low[], vector<int>& mark, vector<int>adj[]) {
    vis[node] = 1; 
    discovery_time[node] = low[node] = timer++; 
    int child = 0; 
    for (auto it : adj[node]) {
        if (it == parent) continue; 
        if (!vis[it]) { 
            dfs(it, node, vis, discovery_time, low, mark, adj);
            low[node] = min(low[node], low[it]); 
            if (low[it] >= discovery_time[node] && parent != -1) mark[node] = 1; 
            child++; 
        }
        else { 
            low[node] = min(low[node], discovery_time[it]);
        }
    }
   
    if (child > 1 && parent == -1) mark[node] = 1;
}


void articulation_points(int n, vector<int>adj[]) {
    vector<int> vis(n, 0); 
    int low[n], discovery_time[n]; 
    vector<int> mark(n, 0); 
    
    for (int i = 0; i < n; i++) {
        if (!vis[i])
            dfs(i, -1, vis, discovery_time, low, mark, adj);
    }
    vector<int> ans; 
    bool no_articulation_point = 1; 
    for (int i = 0; i < n; i++) {
        if (mark[i]) {
            cout << i << ' '; 
            no_articulation_point = 0; 
        }
    }
    if (no_articulation_point) cout << "no articulation point"; 
    cout << endl;
}

int main() {
    freopen("input_5_articulation_points.txt", "r", stdin); 
    freopen("output_5_articulation_points.txt", "w", stdout); 
    int t; cin >> t; 
    while (t--) {
        int V, E;
        cin >> V >> E; 
        vector<int> adj[V];
        
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v); 
            adj[v].push_back(u); 
        }

        articulation_points(V, adj); 

    }
    return 0;
}
