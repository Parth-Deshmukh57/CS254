#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int mindis(vector<vector<int>> &dp, vector<vector<int>> &dis, int n, int visited, int pos)
{
    if (visited == ((1 << n) - 1))
        return dis[pos][0];
    if (dp[visited][pos] != -1)
        return dp[visited][pos];
    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if ((visited & (1 << i)) == 0)
        {
            int curr = dis[pos][i] + mindis(dp, dis, n, visited | (1 << i), i);
            ans = min(ans, curr);
        }
    }
    return dp[visited][pos] = ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> dp;
        vector<int> m;
        for (int j = 0; j < n; j++)
        {
            m.push_back(-1);
        }
        int x = 1 << n;
        for (int i = 0; i < x; i++)
        {
            dp.push_back(m);
        }

        vector<vector<int>> dis;
        for (int i = 0; i < n; i++)
        {
            vector<int> v(n);
            for (int j = 0; j < n; j++)
            {
                cin >> v[j];
            }
            dis.push_back(v);
        }

        cout << mindis(dp, dis, n, 1, 0) << endl;
    }
    return 0;
}