#include <bits/stdc++.h>
using namespace std;
int rec(int i, int target, vector<int>& v, map<pair<int, int>, int>& dp) {
    if (target == 0) return 1;
    if (i == 0) {
        if (target % v[i] == 0)
            return 1;
        else
            return 0;
    }
    if (dp.count({i, target})) return dp[{i, target}];
    int exclude = rec(i - 1, target, v, dp);
    int include = 0;
    if (v[i] <= target) include = rec(i, target - v[i], v, dp);
    return dp[{i, target}] = include + exclude;
}

int iterative(int target,vector<int>&v){
    if(target==0)return 1;
    int n = v.size();
    int dp[n][target+1] = {0};
    for(int j = 0;j<=target;j++){
        if(j%v[0]==0)dp[0][j]=1;
    }
    for(int i =1;i<n;i++){
        for(int j =0;j<=target;j++){
            int exclude = dp[i-1][j];
            int include = 0;
            if(v[i]<=j)include = dp[i][j-v[i]];
            dp[i][j] = include + exclude;
        }
    }
    return dp[n-1][target];
}

int change(int target, vector<int>& v) {
    return iterative(target,v);
    // if (target == 0) return 1;
    // // don't pick anything
    // int n = v.size();
    // map<pair<int, int>, int> dp;
    // return rec(n - 1, target, v, dp);
}
signed main()
{
   
}
