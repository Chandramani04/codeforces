#include <bits/stdc++.h>
using namespace std;
#define ll long long int

inline void debugMode() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main() {
    // debugMode();
    int testcases;
    cin >> testcases;
    while (testcases--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);// storing all the n values 
        map<int, vector<int>> rows; // storing the occurence index of each unqiue value in given array 
        map<int, vector<int>> cols;
        priority_queue<int, vector<int>, greater<int>> gq; // stores minimum at top 

        for (int i = 0; i < n; i++) {
            cin >> v[i];// taking input
            rows[v[i]].push_back(i + 1);// particular unique element ke har ek frequency index ko store kr rhe
            cols[v[i]].push_back(i + 1);
            gq.push(v[i]);
            rows[gq.top()].push_back(i + 1);
            cols[gq.top()].push_back(i + 1);
        }

        for (int i = 1; i <= k; i++) {
            if (rows.count(i) == 0) {
                cout << 0 << " ";
                continue;
            }
            sort(rows[i].begin(), rows[i].end());
            sort(cols[i].begin(), cols[i].end());
            int rowd, cold;
            if (rows[i].back() != rows[i].front())
                rowd = abs(rows[i].back() - rows[i].front());
            else
                rowd = rows[i].back();
            if (cols[i].back() != cols[i].front())
                cold = abs(cols[i].back() - cols[i].front());
            else
                cold = cols[i].back();
            cout << 2 * (max(rowd, cold) + 1) << " ";
        }
        cout << "\n";
    }
    return 0;
}