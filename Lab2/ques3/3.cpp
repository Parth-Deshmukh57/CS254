#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void merger(int A[], int n, int m)
{

    int interval = (n + 1) / 2;

    while (interval > 0)
    {
 
        int l = 0;
        int r = l + interval;
        while (r < n)
        {
            if (A[l] > A[r]){swap(A[l], A[r]);}
            l++;
            r++;
        }
        if (interval == 1){break;}
        interval = (interval + 1) / 2;
    }
}

void solve(){
        int n, m; 
        cin >> n >> m;
        int A[n];
        for (int i = 0; i < n; i++){
            cin >> A[i]; // input
        }

        merger(A, n, m); // applying  merger function

        for (int i = 0; i < n; i++){
            cout << A[i] << ' '; //  result
        }
        cout << endl; //break line after each test case
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input_3.in", "r", stdin);
    freopen("output_3.out", "w", stdout);
#endif
    // no. of test cases
    int t;
    cin >> t;
    while (t--)
    {
       solve();
    }
    return 0;
}
