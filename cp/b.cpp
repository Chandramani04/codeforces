#include <bits/stdc++.h>
using namespace std;
int numberOfSubarrays(vector<int> &v, int k) {
    int ans = 0, cnt = 0, i = 0, j = 0;

    while (j < v.size()) {
        if(v[j]&1){
            
        }
    }
    return ans;
}

signed main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    cout<<numberOfSubarrays(v,k)-numberOfSubarrays(v,k-1)<<endl;
}
