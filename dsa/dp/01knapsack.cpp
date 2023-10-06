#include <bits/stdc++.h>
using namespace std;

int rec(int level, int maxweight, vector<int>& weight, vector<int> value, vector<vector<int>>& dp) {
    // base case
    if (level == 0) {
        // if we can take , then by greedy it will always increase our overall profit
        if (maxweight >= weight[level]) return value[level];
        // if we can't take return a large min value which will affect all the prev calls of recursion
        return 0;
    }
    if (dp[level][maxweight] != -1) return dp[level][maxweight];
    int pick = 0, notpick = 0;
    notpick = rec(level - 1, maxweight, weight, value, dp);
    if (maxweight >= weight[level]) pick = value[level] + rec(level - 1, maxweight - weight[level], weight, value, dp);
    return dp[level][maxweight] = max(pick, notpick);
}
int iterative(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for(int w = 0;w<=maxWeight;w++){
        if(w>=weight[0])dp[0][w]=value[0];
    }
    for(int i =1;i<n;i++){
        for(int j = 0;j<=maxWeight;j++){
            int notpick = dp[i-1][j];
            int pick = 0;
            if(j>=weight[i])pick = value[i]+dp[i-1][j-weight[i]];
            dp[i][j] = max(notpick,pick);
        }
    }
    return dp[n-1][maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    return iterative(weight,value,n,maxWeight);
}
signed main() {
}
