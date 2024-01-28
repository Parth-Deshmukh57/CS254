#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// Function to find the maximum subarray sum using Kadane's Algorithm
int MaxSubarraySum(vector<int> &nums, int n) {
    int res = nums[0]; int currMax = nums[0];
    for (int i = 1; i < n; i++) {
        // Update the current maximum subarray sum
        currMax = max(currMax + nums[i], nums[i]);
        
        // Update the result if the current maximum is greater
        res = max(res, currMax);
    }
    return res;
}

// Function to solve each test case
void solve() {
    int n;cin >> n;
    // Input array
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    // Output the result of the maximum subarray sum
    cout << MaxSubarraySum(nums, n) << endl;
}

// function if we want to do by divide and conquer
// tc=O(logn)
// int maxCrossingSum(const vector<int>& arr, int low, int mid, int high) {
//     int leftSum = INT_MIN;
//     int sum = 0;
//     for (int i = mid; i >= low; --i) {
//         sum += arr[i];
//         leftSum = max(leftSum, sum);
//     }
//     int rightSum = INT_MIN;
//     sum = 0;
//     for (int i = mid + 1; i <= high; ++i) {
//         sum += arr[i];
//         rightSum = max(rightSum, sum);
//     }
//     return leftSum + rightSum;
// }

// int maxSubArraySumDivideandConq(const vector<int>& arr, int low, int high) {
//     if (low == high) {
//         return arr[low];
//     }
//     int mid = (low + high) / 2;
//     return max({
//         maxSubArraySumDivideandConq(arr, low, mid),
//         maxSubArraySumDivideandConq(arr, mid + 1, high),
//         maxCrossingSum(arr, low, mid, high)
//     });
// }

int main() {
#ifndef ONLINE_JUDGE
    freopen("input2.in", "r", stdin);
    freopen("output2.out", "w", stdout);
 #endif
    int t;cin >> t;
    // Process each test case
    while (t--) {
        solve();
    }
    return 0;
}
