#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rep(i, a, b) for(int i = a;i < b;i++)

using namespace std;

int solve(int index, int* arr, int n){
    if(index >= n){
        return 0;
    }
    int include = arr[index] + solve(index +2, arr, n);
    int exclude = 0 + solve(index +1, arr, n);
    return max(include, exclude);
}

int solveMem(int index, int* arr, int n, vector<int> &dp){
    if(index >= n){
        return 0;
    }

    if(dp[index] != -1){
        return dp[index];
    }
    int include = arr[index] + solveMem(index +2, arr, n, dp);
    int exclude = 0 + solveMem(index +1, arr, n, dp);
    return dp[index] = max(include, exclude);
}

int main(){
int houses; cin>>houses;
int arr[houses];

for(int i = 0;i < houses;i++){
    cin>>arr[i];
}

vector<int> dp1(houses+1, -1);
int case1 = solveMem(0, arr, houses-1, dp1);

vector<int> dp2(houses+1, -1);
int case2 = solveMem(1, arr, houses, dp2);

cout<<max(case1, case2);

    return 0;
}
