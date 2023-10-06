#include <bits/stdc++.h>
using namespace std;



int iter(vector<vector<int>>&v){
    int n = v.size();
    int m = v[0].size();
    int dp[n+1][m+1];
    for(int i = 0;i<=n;i++)dp[i][0]=0;
    for(int j = 0;j<=m;j++)dp[0][j]=0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            int rd = INT_MIN;
            if(j<m)rd = dp[i-1][j+1];
            dp[i][j] = v[i-1][j-1] + max({dp[i-1][j-1],dp[i-1][j],rd});
        }
    }
    int ans = INT_MIN;
    for(int j = 1;j<=m;j++)ans = max(ans,dp[n][j]);
    return ans;
}

int rec(int i,int j,vector<vector<int>>&v,vector<vector<int>>&dp){
    if(i==0)return v[i][j];
    if(dp[i][j]!=(-1e9))return dp[i][j];
    int m = v[0].size();
    m--;
    int u = INT_MIN,ld = INT_MIN, rd = INT_MIN ;
    u = rec(i-1,j,v,dp);
    if(j-1>=0)ld = rec(i-1,j-1,v,dp);
    if(j+1<=m)rd = rec(i-1,j+1,v,dp);
    return dp[i][j]=v[i][j]+ max({u,ld,rd});
}
int getMaxPathSum(vector<vector<int>> &v) {
    int n = v.size();
    int m = v[0].size();
    int ans = INT_MIN ;
    int dp[n][m];
    for(int i = 0;i<m;i++)dp[0][i]=v[0][i];
    for(int i = 1;i<n;i++){
        for(int j = 0;j<m;j++){
            int u = v[i][j]+dp[i-1][j];
            int ld = INT_MIN,right = INT_MIN;
            if(j-1>=0)ld = v[i][j]+dp[i-1][j-1];
            if(j+1<m)right = v[i][j] + dp[i-1][j+1];
            dp[i][j] = max({u,ld,right});
        }
    }
    for(int j = 0;j<m;j++)ans = max(ans,dp[n-1][j]);
    return iter(v);
}
signed main() {
}
