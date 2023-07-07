#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int n, vector<int> &dp){
    if(n == 0){
        return nums[0];
    }
    if(n < 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int include = nums[n] + solve(nums, n-2, dp);
    int exclude = 0 + solve(nums, n-1, dp);

    int ans = max(include, exclude); 
    dp[n] = ans;
    return  dp[n];
}

int main(){
int n; cin>>n;
vector<int> nums(n);

for(int i = 0;i < n;i++){
    cin>>nums[i];
}
vector<int> dp(n+1, -1);
cout<<solve(nums, n-1, dp)<<endl;

    return 0;
}
