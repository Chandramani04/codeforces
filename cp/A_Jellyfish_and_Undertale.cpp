#include <bits/stdc++.h>
using namespace std;

int rec(int i, int last, vector<vector<int>> &v, vector<vector<int>> &dp) {
    //  base case
    if (i == 0) {
        int ans = 0;
        for (int j = 0; j < v[0].size(); j++) {
            if (j != last) {
                ans = max(ans, v[i][j]);
            }
        }
        return ans;
    }
    // memoization check
    if (dp[i][last] != -1) return dp[i][last];

    // available options
    int ans = 0;
    for (int j = 0; j < v[0].size(); j++) {
        if (j != last) {
            int cur = v[i][j] + rec(i - 1, j, v, dp);
            ans = max(ans, cur);
        }
    }
    return dp[i][last] = ans;
}


int ninjaTraining(int n, vector<vector<int>> &v) {
    int m = v[0].size();
    int dp[n][m];
    for (int j = 0; j < m; j++) {
        int maxi = 0;
        for (int i = 0; i < m; i++) {
            if (i != j) {
                maxi = max(maxi, v[0][i]);
            }
        }
        dp[0][j] = maxi;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int last = 0;
            for (int k = 0; k < m; k++) {
                if (k != j) {
                    int point  = v[i][k] + dp[i-1][k];
                    last = max(last,point);
                }
            }
            dp[i][j] =  last;
        }
    }
    int ans = 0;
    for (int j = 0; j < m; j++) {
        ans = max(ans, dp[n - 1][j]);
    }
    return ans;
}
int ninjaTraining(int n, vector<vector<int>> &points) {
    // DP table to memoize the solution.
    vector<vector<int>> dp(n + 1, vector<int>(4, -1));

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            dp[i][1] = points[i][0];
            dp[i][2] = points[i][1];
            dp[i][3] = points[i][2];
            continue;
        }

        dp[i][1] = max(dp[i - 1][2], dp[i - 1][3]) + points[i][0];
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][3]) + points[i][1];
        dp[i][3] = max(dp[i - 1][1], dp[i - 1][2]) + points[i][2];
    }

    int ans = 0;
    ans = max(ans, dp[n - 1][1]);
    ans = max(ans, dp[n - 1][2]);
    ans = max(ans, dp[n - 1][3]);
    return ans;
}

signed main() {
}
