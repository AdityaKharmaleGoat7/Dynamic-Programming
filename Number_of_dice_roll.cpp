#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rep(i, a, b) for(int i = a;i < b;i++)

using namespace std;

int solve(int dice, int faces, int target){
    if(target<0){
        return 0;
    }
    if(dice == 0 && target!= 0){
        return 0;
    }
    if(target == 0 && dice != 0){
        return 0;
    }   
    if(dice == 0 && target == 0){
        return 1;
    }

    int ans =0;
    for(int i = 1;i <= faces;i++){
        ans += solve(dice-1, faces, target-i);
    }
return ans;
}

int solveMem(int dice, int faces, int target, vector<vector<int>> &dp){
    if(target<0){
        return 0;
    }
    if(dice == 0 && target!= 0){
        return 0;
    }
    if(target == 0 && dice != 0){
        return 0;
    }   
    if(dice == 0 && target == 0){
        return 1;
    }

    if(dp[dice][target] != -1){
        return dp[dice][target];
    }

    int ans =0;
    for(int i = 1;i <= faces;i++){
        ans += solveMem(dice-1, faces, target-i, dp);
    }
    dp[dice][target] = ans;
return dp[dice][target];
}
int main(){
//To give the output of distinct way to make a target sum
int N, M, X;  //N = no. of dice, M = no. of faces of each dice, X = target
cin>>N>>M>>X;

cout<<solve(N, M, X)<<endl; 

vector<vector<int>> dp(N+1, vector<int>(X+1, -1));
cout<<solveMem(N, M, X, dp); 

    return 0;
}