#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

int rec(int i, int target, vector<int> &v, vector<vector<int>> &dp) {
    if(i==0){
        if(target==0 and v[i]==0)return 2;
        else if(target==0)return 1;
        else return target==v[i];
    }
    if(dp[i][target]!=-1)return dp[i][target];
    int exclude = rec(i-1,target,v,dp);
    int include = 0;
    if(v[i]<=target)include = rec(i-1,target-v[i],v,dp);
    int ans = (include%mod + exclude%mod)%mod;
    return dp[i][target]=ans;
}

int iterative(int n,int d,vector<int>&v){
    int ts = accumulate(v.begin(), v.end(), 0ll);
    int target = ts - d;
    if (target < 0) return 0;
    if (target & 1) return 0;
    target /= 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for(int j = 0;j<=target;j++){
        if(v[0]==0 and j==0)dp[0][j]=2;
        else if(j==0 or j==v[0])dp[0][j]=1;
        else dp[0][j]=0;
        
    }
    for(int i =1;i<n;i++){
        for(int j = 0;j<=target;j++){
            int exclude = dp[i-1][j];
            int include = 0;
            if(v[i]<=j)include = dp[i-1][j-v[i]];
            int ans = (include % mod + exclude % mod) % mod;
            dp[i][j] = ans;
        }
    }
    return dp[n-1][target];
}

int countPartitions(int n, int d, vector<int> &v) {
    return iterative(n,d,v);
    // int ts = accumulate(v.begin(),v.end(),0ll);
    // int target = ts-d;
    // if(target<0)return 0;
    // if(target&1)return 0;
    // target/=2;
    // vector<vector<int>>dp(n,vector<int>(target+1,-1));
    // return rec(n-1,target,v,dp);
}
signed main()
{
   
}
