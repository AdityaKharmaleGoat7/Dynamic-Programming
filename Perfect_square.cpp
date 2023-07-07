#include <bits/stdc++.h>
using namespace std;
//100 = 10^2 --> 1, 5 = 2^2 + 1^2 --> 2, 7 = 2^2 + 1^2 + 1^2 + 1^2 --> 4
int solve(int n){
    if(n <= 0){
        return 0;
    }

int ans = n;
 

for(int i = 1;i*i <= n;i++){
 ans = min(ans, 1+solve(n-i*i));
}
return ans;
}


int solveMem(int n, vector<int> &dp){
    if(n <= 0){
        return 0;
    }

int ans = n;
if(dp[n] != -1){
    return dp[n];
}

for(int i = 1;i*i <= n;i++){
 ans = min(ans, 1+solveMem(n-i*i, dp));
}
dp[n] = ans;
return dp[n];
}

int main(){
int n; cin>>n;

vector<int> dp(n+1, -1);
// cout<<solve(n)<<endl;
cout<<solveMem(n, dp)<<endl;

    return 0;
}
