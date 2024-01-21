#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int> mergeTwoSortedArray(int a[],int b[],int m,int n){
   int i=0,j=0;
   vector<int> final_merged_array;

   while(i<m && j<n){
    if(a[i]<=b[j]){
        final_merged_array.push_back(a[i]);
        i++;
    }
    else{
        final_merged_array.push_back(b[j]);
        j++;
    }
   }
   while(i<m){
        final_merged_array.push_back(a[i]);
        i++;
   }
   while(j<n){
        final_merged_array.push_back(b[j]);
        j++;
   }
   return final_merged_array;
}

void solve(){
    int m;
    cin>>m;
    int n;
    cin>>n;
    int a[m];

    for(int i=0;i<m;i++){
        cin>>a[i];
    }
 
    int b[n];

    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<int> final_merged_array=mergeTwoSortedArray(a,b,m,n);

    for(int i=0;i<final_merged_array.size();i++){

        cout<<final_merged_array[i]<<' ';
    }

    cout<<endl;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input_1-a.in", "r", stdin);
    freopen("output_1-a.out", "w", stdout);
#endif
    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}