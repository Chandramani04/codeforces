#include <bits/stdc++.h>
using namespace std;

int rec(int i, int target, vector<int>& v, map<pair<int, int>, int>& dp) {
    if (i == 0) {
        int temp = 0;
        if (target + v[i] == 0) temp++;
        if (target - v[i] == 0) temp++;
        return temp;
    }
    if (dp.find({i, target}) != dp.end()) return dp[{i, target}];
    int add = rec(i - 1, target + v[i], v, dp);
    int sub = rec(i - 1, target - v[i], v, dp);
    return dp[{i, target}] = add + sub;
}

int iterative(int n,int target,vector<int>&v){
    int tsum = accumulate(v.begin(),v.end(),0);
    vector<vector<int>>dp(n,vector<int>(tsum+1,0));
    for(int j = 0;j<=tsum;j++){
        int temp = 0;
        if(j+v[0]==0)temp++;
        if(j-v[0]==0)temp++;
        dp[0][j]=temp;
    }
    for(int i = 1;i<n;i++){
        for(int j = 0;j<=tsum;j++){
            int add = dp[i-1][j+v[i]];
            int sub = 0 ;
            if(v[i]<=j)sub = dp[i-1][j-v[i]];
            dp[i][j] = add+sub;
        }
    }
    return dp[n-1][target];
}

int targetSum(int n, int target, vector<int>& v) {
    return iterative(n,target,v);
}
signed main() {

}
