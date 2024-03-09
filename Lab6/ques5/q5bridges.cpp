#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int timer = 1;
void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges)
{
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (vis[it] == 0)
        {
            dfs(it, node, vis, adj, tin, low, bridges);
            low[node] = min(low[it], low[node]);
        
            if (low[it] > tin[node])
            {
                bridges.push_back({it, node});
            }
        }
        else
        {
            low[node] = min(low[node], low[it]);
        }
    }
}

vector<vector<int>> bridges(int n, vector<int>adj[])
{
 
   
    vector<int> vis(n, 0);
    int tin[n];
    int low[n];
    vector<vector<int>> bridges;
    dfs(0, -1, vis, adj, tin, low, bridges);
    return bridges;
}

void print_bridges(vector<vector<int>> &bridges){
    for(int i=0;i<bridges.size();i++){
        for(auto it:bridges[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

void solve(){
        int V, E;
        cin >> V >> E;     
        vector<int> adj[V]; 
       
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v); 
            adj[v].push_back(u); 
        }

       vector<vector<int>> bridge=bridges(V,adj); 
       print_bridges(bridge);
}

int main()
{
    freopen("input_5_bridges.txt", "r", stdin);   
    freopen("output_5_bridges.txt", "w", stdout); 
    int t;
    cin >> t; 
    while (t--)
    {
        solve();
        
    }
    return 0;
}