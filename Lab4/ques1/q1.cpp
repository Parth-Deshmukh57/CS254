#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define int long long


int mergerAns(int a[],int l,int m,int r){
    int num1=m-l+1;int num2=r-m;
    int leftArray[num1];int rightArray[num2];
    for(int i=0;i<num1;i++){leftArray[i]=a[l+i];}
    for(int i=0;i<num2;i++){rightArray[i]=a[m+1+i];}
    int i=0;int j=0;int k=l;int ans=0;

    while(i<num1 && j<num2){
        if(leftArray[i]<=rightArray[j]){a[k]=leftArray[i];i++;}
        else{a[k]=rightArray[j];j++;
            ans=ans+(num1-i);}
            k++;
    }
    while(i<num1){a[k]=leftArray[i];i++;k++;}
    while(j<num2){a[k]=rightArray[j];j++;k++;}
    return ans;

}

int numOfInversions(int a[],int l,int r){
    int ans=0;
    if(l<r){
        int m=l+(r-l)/2;
        ans=ans+numOfInversions(a,l,m);
        ans=ans+numOfInversions(a,m+1,r);
        ans=ans+mergerAns(a,l,m,r);
    }
    return ans;
}


signed main(){
#ifndef ONLINE_JUDGE
    freopen("input1.in", "r", stdin);
    freopen("output1.out", "w", stdout);
#endif
    int t;cin>>t;// test cases
    while(t--){
        int n;cin>>n;//array size
        int arr[n];
        for(int i=0;i<n;i++){cin>>arr[i];}//input 
        cout<<numOfInversions(arr,0,n-1)<<endl;//answer
}
    
    return 0;
}