#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int knapsack(int W, int w[], int v[], int n)
{

    int dp[W + 1][n + 1];

    // Initializing the first row and column to 0
    for (int i = 0; i <= W; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
    }

    //  DP table
    for (int i = 1; i <= W; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            //  maximum value between the previous row and the previous column
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            // If the weight of the current item is less than or equal to the current capacity
            if (w[j - 1] <= i)
            {
                // Update the current cell with the maximum value between the previous item
                // and the value of including the current item
                dp[i][j] = max(dp[i][j], dp[i - w[j - 1]][j - 1] + v[j - 1]);
            }
        }
    }

    // return answer
    return dp[W][n];
}

void solve()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    int t;
    cin>>t;

    while(t--){
    int n;
    cin >> n;

    int W;
    cin >> W;
    int w[n], v[n];

    // weights of the items
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    //  values of the items
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    //  printing the result
    cout << knapsack(W, w, v, n) << endl;
    }
}

int main()
{
    // Calling the solve function
    solve();

    return 0;
}

// 5
// 10
// 2 5 7 3 1
// 10 20 15 7 5