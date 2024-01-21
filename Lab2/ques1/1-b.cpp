#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> unionTwoSortedArray(int a[], int b[], int m, int n)
{
    int i = 0;
    int j = 0;

    vector<int> final_union_array;

    while (i < m && j < n)
    {

        if (a[i] < b[j])
        {
            final_union_array.push_back(a[i]);
            do
            {
                i++;
            } while (i < m && a[i] == a[i - 1]);
        }

        else if (a[i] > b[j])
        {
            final_union_array.push_back(b[j]);

            do
            {
                j++;
            } while (j < n && b[j] == b[j - 1]);
        }

        else
        {
            final_union_array.push_back(a[i]);
            do
            {
                i++;
            } while (i < m && a[i] == a[i - 1]);

            do
            {
                j++;
            } while (j < n && b[j] == b[j - 1]);
        }
    }
    while (i < m)
    {

        final_union_array.push_back(a[i]);
        do
        {
            i++;
        } while (i < m && a[i] == a[i - 1]);
    }
    while (j < n)
    {

        final_union_array.push_back(b[j]);
        do
        {
            j++;
        } while (j < n && b[j] == b[j - 1]);
    }

    return final_union_array;
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

    vector<int> final_union_array=unionTwoSortedArray(a,b,m,n);

    for(int i=0;i<final_union_array.size();i++){

        cout<<final_union_array[i]<<' ';
    }

    cout<<endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input_1-b.in", "r", stdin);
    freopen("output_1-b.out", "w", stdout);
#endif

    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}