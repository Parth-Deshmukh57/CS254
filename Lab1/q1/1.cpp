#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define ll long long 

using namespace std;

// Function to find the maximum sum of two elements in an array
ll maxSumOfTwoElements(vector<ll> & v) {
    if (v.size() < 2) {
        //  where the array has less than two elements
        return -1; 
    }

    //  two largest elements
    ll max1 = max(v[0], v[1]);
    ll max2 = min(v[0], v[1]);

    // Iterate  the array to find the two largest elements
    for (ll i = 2; i < v.size(); ++i) {
        if (v[i] > max1) {
            // If current element is greater than the largest
            max2 = max1;
            max1 = v[i];
        }
         else if (v[i] > max2) {
            // If current element is greater than the second largest
            max2 = v[i];
        }
    }

    // sum of the two largest elements
    return max1 + max2;
}

int main() {


#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif


    // vector<ll> v = {3, 1, 4, 6, 8, 2, 5};
    ll t;
    cin>>t;

    while(t--){

    ll n;
    cin>>n;

    vector<ll> v ;
    ll x;

    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    ll output = maxSumOfTwoElements(v);
   
    cout << "Input: ";
    for (ll i : v) {
        cout << i<< " ";
    }
    cout<<endl;
    cout << "Output: " << output << endl;
    }

    return 0;
}
