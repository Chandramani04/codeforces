#include<bits/stdc++.h>
using namespace std;
int main(){

    string s;cin>>s;
    string v;cin>>v;
    int n = s.size();
    int m = v.size();
    int dp[n+1][m+1];
    for(int i =0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j = 0;j<=m;j++){
        dp[0][j]=0;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s[i-1]==v[j-1])dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<endl;
	
}
