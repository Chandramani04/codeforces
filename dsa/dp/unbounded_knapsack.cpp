#include <bits/stdc++.h>
using namespace std;

int rec(int i, int w, vector<int> &profit, vector<int> &weight, map<pair<int, int>, int> &dp) {
    if (i == 0) {
        int get = w / weight[i];
        return get * profit[i];
    }
    if (dp.count({i, w})) {
        return dp[{i, w}];
    }
    int exclude = rec(i - 1, w, profit, weight, dp);
    int include = -1e8;
    if (weight[i] <= w and w > 0) {
        include = profit[i] + rec(i, w - weight[i], profit, weight, dp);
    }
    return dp[{i, w}] = max(include, exclude);
}
int iterative(int n, int w, vector<int> &profit, vector<int> &weight) {
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for(int i = 0;i<=w;i++){
        int get = i/weight[0];
        dp[0][i]= get*profit[0];
    }
    for(int i = 1;i<n;i++){
        for(int j = 0;j<=w;j++){
            int exclude = dp[i-1][j];
            int include = 0;
            if(weight[i]<=j and j>0)include = profit[i] + dp[i][j-weight[i]];
            dp[i][j] = max(include,exclude);
        }
    }
    
    return dp[n-1][w];
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    // map<pair<int, int>, int> dp;
    // return rec(n - 1, w, profit, weight, dp);
    return iterative(n,w,profit,weight);
}
signed main() {
    //
}
