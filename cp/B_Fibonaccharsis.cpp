#include <bits/stdc++.h>
using namespace std;
#define int long long 
void solve(){
    int n;cin>>n;
    vector<int>a(n),b(n);
    for(auto &x:a)cin>>x;
    for(auto &x:b)cin>>x;
    int ma = *min_element(a.begin(),a.end());
    int mb = *min_element(b.begin(),b.end());
    int sumofa = accumulate(a.begin(),a.end(),0);
    int sumofb = accumulate(b.begin(),b.end(),0);
    int ans1 = (n*ma)+sumofb;
    int ans2 = (n*mb)+sumofa;
    cout<<min(ans1,ans2)<<endl;

}
signed main()
{
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
