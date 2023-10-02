// Problem: A. MEXanized Array
// Contest: Codeforces - CodeTON Round 6 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1870/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)
#include <bits/stdc++.h>
using namespace std;

/*-------------------------------------------------------------------*/
#define fastio()                    \
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
  vi v(n);          \
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
int a  = 0b101 ;//print 5   to print the deciaml number from binary 0b(binary
form) bitset<8>b(6);cout<<b<<endl; // deciaml to binary a+b = (a^b)+2(a&b)
*/
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
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
  for (auto x : v) cout << x << " ";
  cout << endl;
}
vector<int> sieve(int n) {
  int *arr = new int[n + 1]();
  vector<int> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
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

/*---------------------------Code
 * Begins---------------------------------------*/
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  for (auto x : v) cout << x << " ";
  cout << endl;
}
signed main() {
  fastio();

  int testcase = 1;
  cin >> testcase;
  while (testcase--) solve();
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
BIT TRICKS->
UC -> LC -> char('C' | ' '); // or with space
LC -> UC -> char('c' & '_'); // and with underscore
*/