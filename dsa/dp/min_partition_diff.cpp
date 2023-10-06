#include <bits/stdc++.h>
using namespace std;

int findWays(vector<int> &v, int target) {
    int n = v.size();
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    // target = 0 -> all true 
    for(int i = 0;i<n;i++){
        dp[i][0]=1;
    }
    // if we pick v[0]
    if(v[0]<=target)dp[0][v[0]]=1;
    for(int i = 1;i<n;i++){
        for(int j = 1;j<=target;j++){
            // if we pick v[i] 
            int include = 0 ;
            if(v[i]<=j)include = dp[i-1][j-v[i]];
            int exclude = dp[i-1][j];
            dp[i][j] = include + exclude;
        }
    }
    return dp[n-1][target];
}
signed main()
{
   
}
