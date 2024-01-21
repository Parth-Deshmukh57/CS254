#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define ll long long 

using namespace std;


void minTwoElements(vector<ll> & v) {
    if (v.size() < 2) {
        //  where the array has less than two elements
        cout<<-1<<endl;  //return -1 when not possible
        return ; 
    }

    //  two min elements
    ll min1 = min(v[0], v[1]);
    ll min2 = max(v[0], v[1]);

    // Iterate  the array to find the two mint elements
    for (ll i = 2; i < v.size(); ++i) {
        if (v[i] < min1) {
         
            min2 = min1;
            min1 = v[i];
        }
         else if (v[i] < min2) {
            min2 = v[i];
        }
    }

    cout<<min1<<" "<<min2<<endl;
  
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input_5.in", "r", stdin);
    freopen("output_5.out", "w", stdout);
#endif

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
    minTwoElements(v);
    }
    return 0;
}
