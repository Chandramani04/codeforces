#include <bits/stdc++.h>
using namespace std;

// two possibilites 
// 0 -> n  or n -> 0
bool rec(int i  , int target, vector<int>&v,vector<vector<int>>&dp){
    // if(target<0)return false ;
    if(i==0)return v[i]==target;
    if(target==0)return true;
    if(dp[i][target]!=-1)return dp[i][target];
    bool include = false;
    if(target-v[i]>=0)  include = rec(i-1,target-v[i],v,dp);
    bool exlude = rec(i-1,target,v,dp);
    return dp[i][target]=include or exlude ; 

}

int iterative(int n,int target,vector<int>&v){

    bool dp[n][target+1];
    for(int i = 0;i<n;i++)dp[i][0]=true;
    if(v[0]<target) dp[0][v[0]]=true;
    for(int i = 1;i<n;i++){
        for(int j = 1 ;j<=target;j++){
            bool include = false,exclude = false;
            if(j-v[i]>=0)include = dp[i-1][j-v[i]];
            exclude = dp[i-1][j];
            dp[i][j] = include or exclude;
        }

    }
    return dp[n-1][target];


}
bool subsetSumToK(int n, int k, vector<int> &v) {
    // Write your code here.
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    // return rec(n-1,k,v,dp);
    return iterative(n,k,v);
}

signed main()
{
   
}
