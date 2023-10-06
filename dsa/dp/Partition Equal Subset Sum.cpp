#include <bits/stdc++.h>
using namespace std;

bool rec(int i, int target, vector<int> &v, vector<vector<int>> &dp) {
    if (target == 0) return true;
    if (i == 0) {
        return target == 0;
    }

    if (dp[i][target] != -1) return dp[i][target];
    bool exclude = rec(i - 1, target, v, dp);
    bool include = false;
    if (v[i] <= target) include = rec(i - 1, target - v[i], v, dp);
    return dp[i][target] = exclude or include;
}

bool iterative(vector<int> &v, int n) {
    int target = accumulate(v.begin(), v.end(), 0ll);
    if (target & 1) {
        return false;
    }
    target /= 2;
    // bool dp[n][target + 1];
    int k = target;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for(int i = 0;i<n;i++)dp[i][0]=true;
    if(v[0]<=target)dp[0][v[0]]=true;
    for(int i = 1;i<n;i++){
        for(int j = 1;j<=target;j++){
            bool exclue = dp[i-1][j];
            bool include = false;
            if(v[i]<=j)include = dp[i-1][j-v[i]];
            dp[i][j] = exclue or include;
        }
    }
    return dp[n-1][target];
}

bool canPartition(vector<int> &v, int n) {
    long long tsum = accumulate(v.begin(), v.end(), 0ll);
    if (tsum & 1) {
        return false;
    }
    tsum /= 2;
    vector<vector<int>> dp(n, vector<int>(tsum + 1, -1));
    // return rec(n - 1, tsum, v, dp);
    return iterative(v,n);
}
signed main() {
}
