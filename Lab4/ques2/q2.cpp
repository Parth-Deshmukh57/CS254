#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define int long long


double getMedian(int a1[],int a2[],int n1,int n2){
    int begin1=0;
    int end1=n1;

    while(begin1<=end1){
        int i1=(begin1+end1)/2;
        int i2=(n1+n2+1)/2 - i1;

        int min1=(i1==n1)?INT_MAX:a1[i1];
        int max1=(i1==0)?INT_MIN:a1[i1-1];
        int min2=(i2==n2)?INT_MAX:a2[i2];
        int max2=(i2==0)?INT_MIN:a2[i2-1];

        if(max1<=min2 && max2<=min1){
            if((n1+n2)%2==0){
                return ((double)(max(max1, max2) + min(min1, min2)) / 2);

            }
            else{
                return ((double)max(max1,max2));
            }
        }
        else if(max1>min2){
            end1=i1-1;
        }
        else{
            begin1=i1+1;
        }
    }


}

signed main(){
#ifndef ONLINE_JUDGE
    freopen("input2.in", "r", stdin);
    freopen("output2.out", "w", stdout);
#endif

int t;cin>>t;
while(t--){
    int n1;
    cin>>n1;
    int a1[n1];
    for(int i=0;i<n1;i++)cin>>a1[i];
    int n2;cin>>n2;
    int a2[n2];
    for(int i=0;i<n2;i++)cin>>a2[i];
    


    cout<<fixed<<setprecision(9)<<((n1<n2)?getMedian(a1,a2,n1,n2):getMedian(a2,a1,n2,n1))<<endl;

}
    return 0;
}