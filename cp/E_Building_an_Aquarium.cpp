#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;cin>>t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for (auto &x : v)
            cin >> x;
        int s = 1, e = 2e9 + 1;
        while (e - s > 1) {
            int mid = s + (e - s) / 2;
            int rest = x;
            for (int i = 0; i < n; i++) {
                if (v[i] < mid)
                    rest -= mid - v[i];
                if (rest < 0)
                    break;
            }
            if (rest < 0)
                e = mid;
            else
                s = mid;
        }
        cout << s << endl;
    }
}
