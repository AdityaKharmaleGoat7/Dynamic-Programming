#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rep(i, a, b) for(int i = a;i < b;i++)

using namespace std;

int solve(vector<vector<int>> mat, int i, int j, int &maxi){
    if(i >= mat.size() || j >= mat[0].size())
    return 0;

    int right = solve(mat, i, j+1, maxi);
    int down = solve(mat, i+1, j, maxi);
    int diagnol = solve(mat, i+1, j+1, maxi);

    if(mat[i][j] == 1){
        int ans = 1 + min(right, min(down, diagnol));
        maxi = max(maxi, ans);
    return ans;
    }

    else{
        return 0;
    }
}

int solveMem(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp){
    if(i >= mat.size() || j >= mat[0].size())
    return 0;

    if(dp[i][j] !=-1){
        return dp[i][j];
    }

    int right = solveMem(mat, i, j+1, maxi, dp);
    int down = solveMem(mat, i+1, j, maxi, dp);
    int diagnol = solveMem(mat, i+1, j+1, maxi, dp);

    if(mat[i][j] == 1){
        int ans = 1 + min(right, min(down, diagnol));
        maxi = max(maxi, ans);
        dp[i][j] = ans;
    return dp[i][j];
    }

    else{
        return 0;
    }
}


int main(){

int maxi = 0;
vector<vector<int>> mat = {{0,0,1,1},
                           {1,1,1,1},
                           {1,1,1,1},
                           {1,1,1,1},
                           {1,1,1,1}};

int a = mat.size();
int b = mat[0].size();

vector<vector<int>> dp(a+1, vector<int> (b+1, -1));

//  solve(mat, 0, 0, maxi);


solveMem(mat, 0, 0, maxi, dp);
cout<<maxi;

    return 0;
}