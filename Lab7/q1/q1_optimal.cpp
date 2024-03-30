#include<bits/stdc++.h>
using namespace std;


int Ans(int weight[], int val[], int n, int W) {
    int dp[n + 1][W + 1];
    for (int i = 0;i <= n;i++){
        dp[i][0] = 0;
    }
    for (int i = 0;i <= W;i++){
        dp[0][i] = 0;
    }

    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= W;j++) {
            if (weight[i - 1] <= j) {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            }
            else {dp[i][j] = dp[i - 1][j];}
        }
    }
    return dp[n][W];
}

void solve(){
        int n;cin >> n;
        int weight[n], val[n];
        for (int i = 0;i < n;i++){cin >> weight[i];}
        for (int i = 0;i < n;i++){cin >> val[i];}
        int W;
        cin >> W;
        cout << Ans(weight, val, n, W) << endl;
}
int main() {
    freopen("input1_optimal.txt", "r", stdin);
    freopen("output_optimal.txt", "w", stdout);
    int t;cin >> t;
    while (t--) {
        solve();

    }
    return 0;
}