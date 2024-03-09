#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool dfs(vector<int> adj[], vector<bool> &vis, vector<bool> &rec, int V, int u)
{
    vis[u] = true;
    rec[u] = true;

    for (auto it : adj[u])
    {
        if (vis[it] == false && dfs(adj, vis, rec, V, it))
        {
            return true;
        }
        else if(rec[it]==true){
            return true;
        }
    }
    rec[u]=false;
    return false;
}

bool loopDetection(vector<int> adj[], int V)
{
    vector<bool> vis(V);
    vector<bool> rec(V);
    for (int i = 0; i < V; i++)
    {
        vis[i] = false;
        rec[i] = false;
    }

    for (int i = 0; i < V; i++)
    {
        if (vis[i] == false)
        {
            if (dfs(adj, vis, rec, V, i) == true)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    freopen("input_4.txt", "r", stdin);
    freopen("output_4.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        while (E--)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        cout << ((loopDetection(adj, N)) ? "yes,loop detected" : "no loop") << endl;
    }
    return 0;
}