#include <bits/stdc++.h>
using namespace std;
int rec(int i, int target, vector<int> &v, vector<vector<int>> &dp) {
    if (i == 0) {
        if (target % v[i] == 0) return target / v[i];
        return 1e9;
    }
    if (dp[i][target] != -1) return dp[i][target];
    int exclude = rec(i - 1, target, v, dp);
    int include = 1e9;
    if (v[i] <= target) include = 1 + rec(i, target - v[i], v, dp);
    return dp[i][target] = min(include, exclude);
}
int iterative(vector<int> &v, int target) {
    sort(v.begin(), v.end(),greater<int>());
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for(int j = 0;j<=target;j++){
        if(j%v[0]==0)dp[0][j]=j/v[0];
        else dp[0][j] = 1e9;
    }

    for(int i =1;i<n;i++){
        for(int j =0;j<=target;j++){
            int exclude = dp[i-1][j];
            int include = 1e9;
            if(v[i]<=j){
                include = 1 + dp[i][target-v[0]];
            }
            dp[i][j] = min(include,exclude);
        }
    }
    int ans = dp[n-1][target];
    if (ans >= 1e9) return -1;
    return ans;
}
int minimumElements(vector<int> &v, int x) {
    return iterative(v,x);
    // sort(v.begin(), v.end());
    // int n = v.size();
    // vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    // int ans = rec(n - 1, x, v, dp);
    // if (ans >= 1e9) return -1;
    // return ans;

}
signed main() {
}
