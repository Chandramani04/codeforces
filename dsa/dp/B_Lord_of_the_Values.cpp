#include <bits/stdc++.h>
using namespace std;

/*-------------------------------------------------------------------*/
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define int long long int
#define pb emplace_back
#define ff first
#define ss second
#define setbits __builtin_popcountll
#define clz __builtin_clzll
#define ctz __builtin_ctzll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define reverse(x) (reverse(all(x)))
#define pll pair<int, int>
#define rep(i, a, n) for (int i = a; i < (n); ++i)
#define repo(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define sum(a) (accumulate((a).begin(), (a).end(), 0ll))
#define sorted(a) (sort((a).begin(), (a).end()))
#define countx(v, x) (count(all(v), x))
#define minel(a) (*min_element((a).begin(), (a).end()))
#define maxel(a) (*max_element((a).begin(), (a).end()))
#define maxidx(a) (max_element((a).begin(), (a).end()) - (a).begin())
#define minidx(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define lb(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define ub(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define vi vector<int>
#define input(v, n) \
    vi v(n);        \
    for (auto &x : v) cin >> x;
// 48-57 -> 0-9
// 65-90 -> A-Z
// 97-122 -> a-z
/*
    size_t found = str.find(str1);
    if (found != string::npos)
    auto index = str.find(targetstr , starting index , ending index)
    to find in while string
    auto index = str.find(target)
 v.insert->
vector_name.insert(vector_name.begin() + 3, 100);
int a  = 0b101 ;//print 5   to print the deciaml number from binary 0b(binary form)
bitset<8>b(6);cout<<b<<endl; // deciaml to binary
a+b = (a^b)+2(a&b)
*/
bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b) {
    return (a.second < b.second);
}
int maxdigitprodcut(int n) {
    if (n < 10) return max((int)1, n);
    return max((n % 10) * maxdigitprodcut(n / 10), 9 * maxdigitprodcut(n / 10 - 1));
}
// sort(v.begin(), v.end(), sortbysec);
int modadd(int a, int b, int m) {
    a %= m;
    b %= m;
    return (a + b) % m;
}
int modmul(int a, int b, int m) {
    a %= m;
    b %= m;
    return (a * b) % m;
}
int modsub(int a, int b, int m) {
    a %= m;
    b %= m;
    return (a - b + m) % m;
}
int power(int a, int b) {  // binary exponentiaion
    int ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        a *= a;
        b = b >> 1;  // b/=2
    }
    return ans;
}
void print(vi &v) {
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}
vector<int> sieve(int n) {
    int *arr = new int[n + 1]();
    vector<int> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0) {
            vect.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}
vi frequency(vi v) {
    unordered_map<int, int> mp;
    for (int i = 0; i < sz(v); i++) {
        mp[v[i]]++;
    }
    vi ans;
    for (auto x : mp) {
        ans.push_back(x.second);
    }
    return ans;
}

/*---------------------------Code Begins---------------------------------------*/
void solve() {
    int n;
    cin >> n;
    input(v, n);
    vector<pair<int, int>> store(n);
    store[0]=make_pair(v[0],0);
    for(int i = 1;i<n;i++){
        pair<int,int>last = store[i-1];
        pair<int,int>curr = make_pair(v[i],i);
        if(curr.first>last.first){
            store[i]=curr;
        }
        else store[i]=last;
    }
    // for (auto x : store) {
    //     cout << x.first << " " << x.second << endl;
    // }
    vector<pair<int,pair<int,int>>> ans;
    for(int i = 1;i<n;i++){
        if(v[i]>v[i-1]){
            // make v[i] smaller 
            pair<int,int>prev_max = store[i-1];
            int del = prev_max.first;
            int index = prev_max.second;
            while(v[i]>v[i-1]){
                // cout<<2<<" "<<index+1<<" "<<i+1<<endl;
                pair<int,int>ip = make_pair(index+1,i+1);
                pair<int,pair<int,int>>cmd = make_pair(2,ip);
                ans.push_back(cmd);
                v[i]-=del;
            }
        }
    }
    // now array in decrasing order 
    vi temp = v;
    for(int i = 1;i<n;i++){
        int cur = v[i];
        while(cur>=0){
            // cout<<2<<" "<<i-1<<" "<<i<<endl;
            pair<int, int> ip = make_pair(i, i+1);
            pair<int, pair<int, int>> cmd = make_pair(2, ip);
            ans.push_back(cmd);
            cur-=v[i-1];
            temp[i]=cur;
        }
    }
    // 1 -1 -1 1
    // 4 -1 -2 -2
    // int maxi = 0 ; 
    int mini = INT_MIN;
    int mini_idx ;
    for(int i = 1;i<n;i++){
        if(abs(temp[i])>mini){
            mini = abs(temp[i]);
            mini_idx = i;
        }
    }
    int cur = v[0];
    while(cur>=0){
        // cout<<1<<" "<<1<<" "<<mini_idx+1<<endl;
        pair<int, int> ip = make_pair( 1, mini_idx + 1);
        pair<int, pair<int, int>> cmd = make_pair(1, ip);
        ans.push_back(cmd);
        cur-=mini;
        temp[0]=cur;
    }
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
    }
    // print(temp);

    // two condition / if(v.back()>)
    


    // store[n - 1] = make_pair(v.back(), n - 1);

    // for (int i = n - 2; i >= 0; i--) {
    //     pair<int, int> last = store[i + 1];
    //     pair<int, int> curr = make_pair(v[i], i);
    //     if (curr.first > last.first) {
    //         store[i] = curr;
    //     } else
    //         store[i] = last;
    // }

    // //  we have to make array in non -decrasing order
    // for (int i = 1; i < n - 1; i++) {
    //     if(v[i]<v[i-1]){
    //         pair<int,int>next_max = store[i+1];
    //         int add = next_max.first;
    //         int index = next_max.second;
    //         while(v[i]<v[i-1]){
    //             // type i j  i<j
    //             // t1 -> a[i] = a[i]+a[j]
    //             // t2-> a[j] = a[j]-a[i]
    //             cout<<1<<" "<<i+1<<" "<<index+1<<endl;
    //             v[i]+=add;
    //         }
    //     }
    // }
    // for(int i = 0;i<n-1;i++){
    //     while(v[i]>=0){
    //         cout<<
    //     }
    // }
}
signed main() {
    fastio();

    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
/*BS TEMPLET
int l,r;
l = 0;(assuming we have a 0 at l);
r = 1e9 ( assuming we have a 1 at r);
0-> false , 1 -> true;
while(r>l+1){
    int mid =  l + (r-l)/2;
    // if we have a 1 at mid ie
    if(check(mid)==true){
        r =mid ;
    }
    else l = mid;
}
print(l or r depeneding on what we need);
agr hme maximum chahiye to low ko expandkrenge -> if(check)low = mid krenge
agr minimum chahiye to high to shrink krenge -> high = mid
BIT TRICKS->
UC -> LC -> char('C' | ' '); // or with space
LC -> UC -> char('c' & '_'); // and with underscore
*/
