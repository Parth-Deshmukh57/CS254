#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> intersectionTwoSortedArray(int a[],int b[],int m,int n){
    int i=0;
    int j=0;

    vector<int> final_intersection_array;
    while(i<m && j<n){
        if(i>0 && a[i]==a[i-1]){i++;continue;}
        if(a[i]<b[j])i++;
        
        else if(a[i]>b[j])j++;
        
        else{
            final_intersection_array.push_back(a[i]);
            i++;
            j++;
        }
    }
    return final_intersection_array;
}

void solve(){
 int m;
    cin>>m;
    int a[m];
      int n;
    cin>>n;

    for(int i=0;i<m;i++){
        cin>>a[i];
    }
  
    int b[n];

    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<int> final_intersection_array= intersectionTwoSortedArray(a,b,m,n);

    for (int i = 0; i < final_intersection_array.size(); i++) {
        cout << final_intersection_array[i] << " ";
    }
    cout<<endl;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input_1-c.in", "r", stdin);
    freopen("output_1-c.out", "w", stdout);
#endif
    int t;
    cin>>t;

    while(t--){
        solve();
    }

return 0;
}