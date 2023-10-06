#include <bits/stdc++.h>
using namespace std;
// int rec(int i, int ac, int bc, int n, int m, vector<vector<int>> &v) {
//     // if anyone gets out of grid
//     if (ac < 0 or bc < 0 or ac > m or bc > m) {
//         return 0;  // we can't collect any chocolates
//     }
//     if (i == n) {
//         // if alice and bob are in same col
//         if (ac == bc)
//             return v[i][ac];
//         else
//             return v[i][ac] + v[i][bc];
//     }
//     // again if both are in same col
//     if (ac == bc) {
//         int ans = 0;
//         for (int alice = -1; alice <= 1; alice++) {
//             for (int bob = -1; bob <= 1; bob++) {
//                 int cur = v[i][ac] + rec(i + 1, ac + alice, bc + bob, n, m, v);
//                 ans = max(ans, cur);
//             }
//         }
//         return ans;
//     }
//     // now general case when both are in different cells
//     // options for alice
//     int alice = 0;
//     int down = 0, left = 0, right = 0;
//     down = v[i][ac] + rec(i + 1, ac, bc, n, m, v);
//     if (ac - 1 >= 0) left = v[i][ac] + rec(i + 1, ac - 1, bc, n, m, v);
//     if (ac + 1 <= m) right = v[i][ac] + rec(i + 1, ac + 1, bc, n, m, v);
//     alice =  max({down, left, right});

//     // options for bob
//     int bob = 0;
//     down = 0, left = 0, right = 0;
//     down = v[i][bc] + rec(i + 1, ac, bc, n, m, v);
//     if (bc - 1 >= 0) left = v[i][bc] + rec(i + 1, ac, bc - 1, n, m, v);
//     if (bc + 1 <= m) right = v[i][bc] + rec(i + 1, ac, bc + 1, n, m, v);
//     bob = max({down, left, right});

//     return alice + bob;
// }

int rec(int i, int ac, int bc, int n, int m, vector<vector<int>> &v, vector<vector<vector<int>>> &dp) {
    // always right corner cases first in recursive solution
    if (ac < 0 or ac >= m or bc < 0 or bc >= m) return 0;
    // now write base case
    if (i == n - 1) {
        if (ac == bc) {
            // they are in same col
            return v[i][ac];
        }
        return v[i][ac] + v[i][bc];  // diff col
    }
    // memoized case
    if (dp[i][ac][bc] != -1) return dp[i][ac][bc];
    int ans = 0;
    // trying all possible paths
    for (int alice = -1; alice <= 1; alice++) {
        for (int bob = -1; bob <= 1; bob++) {
            int cur;
            if (ac == bc) {
                cur = v[i][ac] + rec(i + 1, ac + alice, bc + bob, n, m, v, dp);
            } else
                cur = v[i][ac] + v[i][bc] + rec(i + 1, ac + alice, bc + bob, n, m, v);
            ans = max(ans, cur);
        }
    }
    return dp[i][ac][bc] = ans;
}

// int iterative(int n, int m, vector<vector<int>> &v) {
//     int dp[n][m][m];
//     // base case
//     // 0 -> n-1 in recursion => n-1 -> 0 in iterative
//     // filling all the dp[n-1][i][j] choices
//     for (int alice = 0; alice < m; alice++) {
//         for (int bob = 0; bob < m; bob++) {
//             if (alice == bob)
//                 dp[n - 1][alice][bob] = v[n - 1][alice];
//             else
//                 dp[n - 1][alice][bob] = v[n - 1][alice] + v[n - 1][bob];
//         }
//     }
//     for (int i = n - 2; i >= 0; i--) {
//         for (int alice = 0; alice < m; alice++) {
//             for (int bob = 0; bob < m; bob++) {
//                 // for(int )
//             }
//         }
//     }
// }

int maximumChocolates(int n, int m, vector<vector<int>> &v) {
    // int rec(int i,int ac,int bc,int n, int m ,vector<vector<int>>&v)
    // 3d dp
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return rec(0, 0, m - 1, n - 1, m - 1, v, dp);
}
signed main() {
}
