#include <bits/stdc++.h>
using namespace std;
int rec(int i, int j, int n, vector<vector<int>>& v, vector<vector<int>>& dp) {
    if (i == n) {
        return v[i][j];
    }
    if (dp[i][j] != -1e7) return dp[i][j];
    int down = v[i][j] + rec(i + 1, j, n, v, dp);
    int diagonal = v[i][j] + rec(i + 1, j + 1, n, v, dp);
    return dp[i][j] = min(down, diagonal);
}

int top( vector<vector<int>>& v) {
    int n = v.size();
    int m = n;
    int dp[n][m];
    for(int j = 0;j<n;j++){
        dp[n-1][j]=v[n-1][j];
    }
    for(int i = n-2;i>=0;i--){
        for(int j = 0;j<=i;j++){
            dp[i][j]=v[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    return dp[0][0];
}

int iter(vector<vector<int>>& v) {
    int n = v.size();
    int m = n;
    int dp[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == 0 and j == 0)
                dp[i][j] = v[i][j];
            else {
                int up = INT_MAX, diagonal = INT_MAX;
                if(i>0)up = v[i][j]+dp[i-1][j];
                if(j>0)diagonal = v[i][j] + dp[i-1][j-1];
                dp[i][j] = min(up,diagonal);
            }
        }
    }
    int ans = INT_MAX;
    for(int i = 0;i<n;i++){
        ans = min(ans,dp[n-1][i]);
    }
    return ans;
}

int minimumPathSum(vector<vector<int>>& v, int n) {
    vector<vector<int>> dp(n, vector<int>(n, -1e7));
    return iter(v);
}
signed main() {
}
