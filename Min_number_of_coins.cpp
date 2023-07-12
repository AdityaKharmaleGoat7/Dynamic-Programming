#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int solve(int* nums, int target, int n) {
    if (target == 0) {
        return 0;
    }
    if (target < 0) {
        return INT_MAX;
    }
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        int ans = solve(nums, target - nums[i], n);
        if (ans != INT_MAX) {
            mini = min(mini, 1 + ans);
        }
    }
    return mini;
}
int solveMem(int* nums, int target, int n, vector<int> &dp) {
    if (target == 0) {
        return 0;
    }
    if (target < 0) {
        return INT_MAX;
    }

    if(dp[target] != -1){
        return dp[target];
    }


    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        int ans = solveMem(nums, target - nums[i], n, dp);
        if (ans != INT_MAX) {
            mini = min(mini, 1 + ans);
        }
    }
    dp[target] = mini;
    return dp[target];
}
int main() {
    int n;
    cout << "Enter the number of coins: ";
    cin >> n;
    int nums[n];

    cout << "Enter the values of the coins: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    // int result = solve(nums, target, n);
    // if (result == INT_MAX) {
    //     cout << -1<< endl;
    // } else {
    //     cout<< result << endl;
    // }

    //dp
    vector<int> dp(target + 1, -1);
    int result = solveMem(nums, target, n,dp);
    if (result == INT_MAX) {
        cout << -1<< endl;
    } else {
        cout<< result << endl;
    }

    return 0;
}
