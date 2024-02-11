#include<bits/stdc++.h>
using namespace std;


int BFSModified(vector<vector<int>>& arr, vector<vector<int>>& visited, int i, int j) {
    if (arr[i][j] == 0)return 0;
    if (visited[i][j])return 0;
    visited[i][j] = 1;

   
    return 1 + BFSModified(arr, visited, i + 1, j) + BFSModified(arr, visited, i - 1, j)+ BFSModified(arr, visited, i, j + 1) + BFSModified(arr, visited, i, j - 1) + BFSModified(arr, visited, i + 1, j + 1) + BFSModified(arr, visited, i - 1, j - 1) + BFSModified(arr, visited, i + 1, j - 1) + BFSModified(arr, visited, i - 1, j + 1);
}

int reqRegion(vector<vector<int>>& arr, int n, int m) {
    int ans = 0;

    vector<vector<int>> visited(n + 2, vector<int>(m + 2));
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (arr[i][j] == 1) {
                if (!visited[i][j]) {
                    int temp = BFSModified(arr, visited, i, j);
                    ans = max(ans, temp);

                }
            }
        }
    }
    return ans;
}

void solve(){
        int n, m;
        cin >> n >> m;

        vector<vector<int>>arr(n + 2, vector<int>(m + 2));
    
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++)
                cin >> arr[i][j];
        }
    
        cout << reqRegion(arr, n, m) << endl;
    
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input_1.txt", "r", stdin);
    freopen("output_1.txt", "w", stdout);
#endif
    int t;cin >> t;
    while (t--) {
       solve();

    }

    return 0;
}