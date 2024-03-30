#include<bits/stdc++.h>
using namespace std;


struct comparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return (a.first / a.second) > (b.first / b.second);
    }
};


int greedyAns(int weight[], int val[], int n, int W) {
    multimap<pair<int, int>, int, comparator>m;
    for (int i = 0;i < n;i++){
        m.insert(pair<pair<int, int>, int>({ val[i],weight[i] }, weight[i]));}
    int ans = 0;
    for (auto it : m) {
        if (it.second <= W) {
            W =W- it.second;
            ans =ans+ it.first.first;
        }
    }
    return ans;
}

void solve(){
       int n;cin >> n;
        int weight[n], val[n];
        for (int i = 0;i < n;i++){cin >> weight[i];}
        for (int i = 0;i < n;i++){cin >> val[i];}
        int W;
        cin >> W;
        cout << greedyAns(weight, val, n, W) << endl;
}

int main() {
    freopen("input1_greedy.txt", "r", stdin);
    freopen("output_greedy.txt", "w", stdout);
    int t;cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}