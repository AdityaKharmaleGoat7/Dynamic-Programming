#include <bits/stdc++.h>
using namespace std;

// To give the output of maximum segments you can make by breaking a rod of length n, using length{x, y, z} only
int solve(int n, int x, int y, int z, vector<int> &dp){
if(n == 0)
return 0;

if(n < 0){
    return INT_MIN;
}
if(dp[n] != -1){
    return dp[n];
}
int a = solve(n-x, x, y, z, dp) + 1;
int b = solve(n-y, x, y, z, dp) + 1;
int c = solve(n-z, x, y, z, dp) + 1;


int ans = max(a, max(b,c));
dp[n] = ans;
return dp[n];
}

int main(){
int n, x, y, z; cin>>n>>x>>y>>z;
vector<int> dp(n+1, -1);
if(solve(n, x, y, z, dp) < 0){
    cout<<0<<endl;
}
else{
    cout<<solve(n, x, y, z, dp)<<endl;
}

    return 0;
}
