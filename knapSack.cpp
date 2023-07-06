#include <bits/stdc++.h>
using namespace std;

//Without using DP
int solve(vector<int> &weight, vector<int> &value, int index, int capacity){
    if(index == 0){
        if(weight[0] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }

    int include = 0;
    if(weight[index] <= capacity){
        include = value[index] + solve(weight, value, index-1, capacity- weight[index]);
    }

    int exclude = 0 + solve(weight, value, index-1, capacity);

    int ans = max(include, exclude);
    return ans;
}

//1) Memoization
int solveMem(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp){
    if(index == 0){
        if(weight[0] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }
    
    //step 3
    if(dp[index][capacity] != -1){
        return dp[index][capacity];
    }

    int include = 0;
    if(weight[index] <= capacity){
        include = value[index] + solveMem(weight, value, index-1, capacity- weight[index], dp);
    }
    int exclude = 0 + solveMem(weight, value, index-1, capacity, dp);

    //2nd step of storing the answer in DP
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

//2) Tabulation Method
int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity){
    
    //step 1
    vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
    
    //step 2: analyse the base case 
    for(int w = weight[0]; w<=capacity; w++){
        if(weight[0] <= capacity)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    for(int index = 1;index < n;index++){
        for(int w = 0;w <= capacity;w++){
            int include = 0;
         if(weight[index] <= w){
             include = value[index] + dp[index-1][w-weight[index]];
        }
        int exclude = 0 + dp[index-1][w];

        dp[index][w] = max(include, exclude);
        }
    }
return dp[n-1][capacity];
}

int main(){
int n; cin>>n;

vector<int> weight(n); 
vector<int> value(n); 

for(int i = 0;i < n;i++){
    cin>>weight[i];
}

for(int i = 0;i < n;i++){
    cin>>value[i];
}
int knapSack; cin>>knapSack;

cout<<"Without using DP "<<solve(weight, value, n, knapSack)<<endl;


//creation of DP step 1
vector<vector<int>> dp(n, vector<int>(knapSack+1, -1));
cout<<"With DP Memoization "<<solveMem(weight, value, n, knapSack, dp)<<endl;

cout<<"With DP Tabulation "<<solveTab(weight, value, n, knapSack )<<endl;

    return 0;
}
