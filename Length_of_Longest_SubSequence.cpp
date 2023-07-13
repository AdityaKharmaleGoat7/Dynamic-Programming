#include <bits/stdc++.h>
#define ll long long
#define vi vector<ll>
#define pb push_back
#define rep(i, a, b) for(ll i = a;i < b;i++)

using namespace std;

int solve(int n, int arr[], int curr, int prev){
    if(curr == n){
        return 0;
    }
    //include 
    int include = 0;
    if(prev == -1 || arr[curr] > arr[prev]){
        include = 1 + solve(n, arr, curr+1, curr); 
    }

    int exclude = 0 + solve(n, arr, curr+1, prev);

    return max(include, exclude);
}

int solveMem(int n, int arr[], int curr, int prev, vector<vector<int>> &dp){
    if(curr == n){
        return 0;
    }

    if(dp[curr][prev+1] != -1){
        return dp[curr][prev+1];
    }

    //include 
    int include = 0;
    if(prev == -1 || arr[curr] > arr[prev]){
        include = 1 + solveMem(n, arr, curr+1, curr, dp); 
    }

    int exclude = 0 + solveMem(n, arr, curr+1, prev, dp);
    
    dp[curr][prev+1] = max(include, exclude);
    return dp[curr][prev+1];
}

int main(){

//to print the length of longest subsequence 
int n; cin>>n;
int arr[n];

for(int i =0;i < n;i++){
    cin>>arr[i];
}

//solve(size, array, curr, prev)
cout<<solve(n, arr, 0, -1)<<endl; 

vector<vector<int>> dp(n, vector<int>(n+1, -1));
cout<<solveMem(n, arr, 0, -1, dp); 
    return 0;
}