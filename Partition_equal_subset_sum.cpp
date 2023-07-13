#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rep(i, a, b) for(int i = a;i < b;i++)

using namespace std;

bool solve(int target, int arr[], int n, int index){
    if(index >= n){
        return false;
    }
    if(target < 0){
        return false;
    }
    if(target == 0){
        return true;
    }
    int include = solve(target - arr[index], arr,  n, index + 1);
    int exclude = solve(target, arr, n, index + 1);
    return include or exclude;
}

bool solveMem(int target, int arr[], int n, int index, vector<vector<int>> &dp){
    if(index >= n){
        return false;
    }
    if(target < 0){
        return false;
    }
    if(target == 0){
        return true;
    }

    if(dp[target][index] != -1){
        return dp[target][index];
    }

    int include = solveMem(target - arr[index], arr,  n, index + 1, dp);
    int exclude = solveMem(target, arr, n, index + 1, dp);

    dp[target][index] = include or exclude;
    return dp[target][index];
}

int main(){
int n; cin>>n;
int arr[n];
int sum = 0;
for(int i = 0;i < n;i++){
cin>>arr[i];
sum+=arr[i];
}
if(sum%2 == 1)
    cout<<false<<endl;
else{
    cout<<solve(sum/2, arr, n, 0)<<endl;

    //Memoization
    vector<vector<int>> dp(sum/2 + 1, vector<int> (n, -1));
    cout<<solveMem(sum/2, arr, n, 0, dp);
}
    return 0;
}