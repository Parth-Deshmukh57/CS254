#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int DFS(vector<int>adj[], int i, vector<int> &dp,vector<int>&visited) {
    if(visited[i])
        return dp[i];
    visited[i] = 1;
    int mx = 0;
    for (auto x : adj[i])
        mx = max(mx, DFS(adj, x, dp, visited));
    
    return dp[i] = 1 + mx;

}


int longestWay(vector<int>adj[], int N, int M) {
    vector<int>visited(N, 0);
    vector<int>dp(N, -1);
    for (int i = 0;i < N;i++) {
        if (!visited[i]) {
            DFS(adj, i, dp, visited);
        }
    }
    int ans = 0;
    for (auto x : dp)ans = max(ans, x);
    return ans;
}

void solve(){
      int N, M;
        cin >> N >> M;

        vector<int>adj[N];
        for (int i = 0;i < M;i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        cout << longestWay(adj, N, M)<<endl;
}

int main() {
    freopen("input_2.txt","r",stdin);
    freopen("output_2.txt","w",stdout);
    int t;cin >> t;
    while (t--) {
      solve();
    }
    return 0;
}