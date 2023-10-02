#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int polystrength, polyendurance;
    cin >> polystrength >> polyendurance;
    vector<pair<int, int>> v(n - 1);
    for (auto &x : v) {
        cin >> x.first >> x.second;
    }
    sort(v.begin(),v.end());
    vector<int> possible;
    for(int i = 0;i<n-1;i++) {
        if (v[i].first >= polystrength)
            possible.push_back(v[i].second);
    }
    if ((possible.size()) == 0) {
        cout << polystrength << endl;
        return;
    }
   
    sort(possible.begin(),possible.end());
    int maxi = possible.back();
    if (maxi >= polyendurance) {
        cout << -1 << endl;
        return;
    }
    cout << polystrength << endl;
}
signed main()
{
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
