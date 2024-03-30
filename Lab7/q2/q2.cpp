#include<bits/stdc++.h>
using namespace std;




struct comparator {
    bool operator ()(const pair<int, pair<int, char>>& p1, const pair<int, pair<int, char>>& p2) {
        return p1.first > p2.first;
    }
};

int Ans(map<int, vector<pair<int, char>>>& m) {


    priority_queue<pair<int, pair<int, char>>, vector<pair<int, pair<int, char>>>, comparator >pq;

    int ans = 0;
    for (auto it : m) {
        int curr = it.first;
 
      
        int len = (int)(it.second).size();

        for (int i = 0;i < len;i++) {
            if ((int)pq.size() < curr) {
                pq.push({ it.second[i].first,{it.first,it.second[i].second} });
                ans =ans+ it.second[i].first;
            }
            else if (pq.top().first < it.second[i].first) {
                ans =ans- pq.top().first;
                pq.pop();

                pq.push({ it.second[i].first,{it.first,it.second[i].second} });
                ans =ans+ it.second[i].first;
            }
        }
    }
    multimap<int, char>dl;
    while (!pq.empty()) {
        dl.insert(pq.top().second);
        pq.pop();
    }
    for (auto q : dl) {
        cout << q.second << ' ';
    }
    cout << endl;

    return ans;

}

void solve(){
        int n;
        cin >> n;
        map<int, vector<pair<int, char>>>m;
        for (int i = 0;i < n;i++) {
            char c;
            int d, p;
            cin >> c >> d >> p;
            m[d].push_back({ p,c });
        }
        cout << Ans(m) << endl << endl;
}

int main() {
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    int t;cin >> t;
    while (t--) {
       solve();
    }
    return 0;
}