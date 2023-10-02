#include <bits/stdc++.h>
using namespace std;
signed main()
{
   int t;cin>>t;
   while(t--){
       int n, k;
       cin >> n >> k;
        vector<int>fruit(n),height(n);
        for(auto &x:fruit)cin>>x;
        for(auto &x:fruit)cin>>x;
       // using two ptrs approach
       int i = 0, j = 1;
       int ans = 0, fruitsum = height[0];
       while (i < j and j < n) {
           if (height[j - 1] % height[j] == 0) {
               fruitsum += fruit[j];
               j++;
           } else {
               ans = max(ans, j - i);
               fruitsum = fruit[j];
               j++;
           }
       }
       cout << ans << endl;
   }
}
