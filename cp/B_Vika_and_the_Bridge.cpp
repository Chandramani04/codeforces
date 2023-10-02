#include <bits/stdc++.h>
using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define int long long
#define endl "\n"

const int N = 2e5 + 5;

int n, k;
int a[N];

int32_t main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        map<int, vector<int>> pos;
        for (int i = 1; i <= k; i++)
            pos[i].push_back(0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }
        for (int i = 1; i <= k; i++)
            pos[i].push_back(n + 1);
        int ans = n;
        for (int i = 1; i <= k; i++) {
            vector<int> diffs;
            for (int j = 0; j + 1 < pos[i].size(); j++)
                diffs.push_back(pos[i][j + 1] - pos[i][j]);
            sort(diffs.begin(), diffs.end());
            for(auto cmd:diffs){
                cout<<cmd<<" ";
            }
            cout<<endl;
            if (diffs.size()) {
                int cur;
                if (diffs.size() == 1)
                    cur = diffs.back();
                else
                    cur = max((diffs.back() + 1) / 2, diffs[(int)diffs.size() - 2]);
                ans = min(ans, cur);
            }
        }
        cout << ans - 1 << endl;
    }
    return 0;
}