#include <bits/stdc++.h>
using namespace std;

//top-down approach --> memoization
int fib(int n, vector<int> &dp){
    if(n == 0 || n == 1){
        return n;
    }
    
    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = fib(n-1, dp) + fib(n-2, dp);
    return dp[n];
}

//Bottom-up approach --> tabulation
int fib1(int n, vector<int> &dp){
dp[0] = 0;
dp[1] = 1;

for(int i = 2;i <=n;i++){
    dp[i] = dp[i-1] + dp[i-2];
}
return dp[n];
}

//Space optimization 
int fib2(int n){
    int a = 0;
    int b = 1;
    int c;

    if(n == 1 || n ==0){
        return n;
    }

    for(int i =2;i <= n;i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
int n; cin>>n;
vector<int> dp(n+1);

for(int i = 0;i < n+1;i++){
    dp[i] = -1;
}

cout<<"Top-down approach --> "<<fib(n, dp)<<endl;
cout<<"Bottom-up approach --> "<<fib1(n, dp)<<endl;
cout<<"Space optimization --> "<<fib2(n)<<endl;

    return 0;
}