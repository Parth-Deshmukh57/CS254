#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int partition(int a[], int pos, int left, int right)
{

    int i = left - 1, j = left;int p = a[right];
    for (; j <= right - 1; j++)
    {
        if (a[j] < p)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[++i], a[right]);

    if (i == pos){return p;}
    if (i > pos){ return partition(a, pos, left, i - 1);}
    else{return partition(a, pos, i + 1, right);}
}

float calculateMedian(int a[], int scale)
{
    int num1 = (scale - 1) / 2, i2 = scale / 2;
    int num2 = partition(a, num1, 0, scale - 1);
    int num3=0;
    if(scale%2){num3=num2;}
    else{num3=partition(a, i2, 0, scale - 1);}
    return ((float)num2 + (float)num3) / 2;
}

void solve()
{
        int n;
        cin >> n; //input n
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        float medianValue = calculateMedian(a, n);
        cout << medianValue << endl;
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input_4.in", "r", stdin);
    freopen("output_4.out", "w", stdout);
#endif
    //testcases
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        solve();
    }

    return 0;
}
