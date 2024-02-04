#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define int long long


int lPartition(int a[],int l,int r){
    int pivot=a[r];int i=l-1;
    for(int j=l;j<=r-1;j++){
        if(a[j]<pivot){
            i++;swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return (i+1);
}

int kthLargest(int arr[],int n,int k){
    int l=0; int r=n-1;
    while(l<=r){
        int pivot=lPartition(arr,l,r);
        if(pivot==k-1){return arr[pivot];}
        else if(pivot>k-1){r=pivot-1;}
        else{l=pivot+1;}
    }
    return -1;
}

signed main(){
#ifndef ONLINE_JUDGE
    freopen("input3.in", "r", stdin);
    freopen("output3.out", "w", stdout);
#endif
int t;cin>>t;
while(t--){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int k;
    cin>>k;
    cout<<kthLargest(arr,n,n-k+1)<<endl;
}
return 0;
}