#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define ll long long 

using namespace std;

void medianQuickSort(int a[], int left, int right) {
    if (right <= left){ return;}
    if (right - left == 1) {
        if (a[left] > a[right]){ swap(a[left], a[right]);}
        return;
    }

    int mid = left + (right - left) / 2;
    int min_num = min(a[left],
     min(a[right], a[mid]));
    int max_num = max(a[left], 
    max(a[right], a[mid]));
    int sum = a[left] + a[right] + a[mid];
    a[left] = min_num;a[right] = max_num;a[mid] = sum - min_num - max_num;
    int p = a[mid];
    int i = left;
    int j = i+1;
    swap(a[mid], a[right-1]);

    for(;j<=right-2;j++){
        if(a[j]<p)
            swap(a[++i],a[j]);
    }
    swap(a[++i],a[right-1]);

    medianQuickSort(a, left, i-1);
    medianQuickSort(a, i + 1, right);
}

void solve(){
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        medianQuickSort(a, 0, n - 1);

        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }

        cout << endl;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input_6.in", "r", stdin);
    freopen("output_6.out", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}


