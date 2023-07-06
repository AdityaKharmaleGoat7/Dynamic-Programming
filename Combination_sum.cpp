#include <bits/stdc++.h>
using namespace std;

//This problem is about giving the output of no. of combinations to for a sum, ex. tar = 3, given = {1,2} 
// Output = 1 1 1, 1 2, 2 1 --> 3


int solveMem(vector<int> &v, int n, int tar, vector<int> &dp){
    if(tar == 0){
        return 1;
    }
    if(tar < 0){
        return 0;
    }

    int ans = 0;

    if(dp[ans] != -1){
        return dp[ans];
    }
    for(int i = 0;i < n;i++){
        ans += solveMem(v, n, tar-v[i],dp);
    }
    dp[tar] = ans;
    
    return dp[tar];
}

int solveTab(vector<int> &v, int n, int tar){

    vector<int> dp(tar+1, 0);
    dp[0] = 1;

    for(int i = 1;i <= tar;i++){

        //traverse on v vector
        for(int j = 0;j < v.size();j++){
            if(i - v[j] >= 0)
            dp[i] += dp[i- v[j]];
        }
    }
   return dp[tar];
}


int main(){
int n, target;  cin>>n>>target;  

vector<int> v(n);
for(int i = 0;i < n;i++){
    cin>>v[i];
}
vector<int> dp(target+1, -1);
cout<<solveMem(v, n, target, dp)<<endl;

cout<<solveTab(v, n, target);


    return 0;
}
