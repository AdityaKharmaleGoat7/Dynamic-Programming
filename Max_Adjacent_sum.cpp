#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rep(i, a, b) for(int i = a;i < b;i++)

using namespace std;

//to return the maximum adjacent sum in the given array, [9, 9, 8, 2] --> 17

int solve(int index, int* arr, int n){
    if(index >= n){
        return 0;
    }
int include = arr[index] + solve(index+2, arr, n);
int exclude = 0 + solve(index+1, arr, n);
return max(include, exclude);
}

int solveMem(int index, int* arr, int n, vector<int> &dp){
    if(index >= n){
        return 0;
    }

    if(dp[index] != -1){
        return dp[index];
    }
int include = arr[index] + solveMem(index+2, arr, n, dp);
int exclude = 0 + solveMem(index+1, arr, n, dp);

return dp[index] = max(include, exclude);
}

int main(){
int n; cin>>n;
int arr[n];

for(int i = 0;i < n;i++){
    cin>>arr[i];
}

// cout<<solve(0, arr, n)<<endl;

vector<int> dp(n+1,-1);
cout<<solveMem(0, arr, n, dp)<<endl;

    return 0;
}