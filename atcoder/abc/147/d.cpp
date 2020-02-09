#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int n;
  cin >> n;
  ll a[n];

  rep(i, n) { cin >> a[i]; }

  ll ans = 0;
  rep(i, 60) {
    ll x = 0;
    rep(j, n) if (a[j] >> i & 1) x++;
    ll now = x * (n - x) % MOD;
    rep(k, i) { now = now * 2 % MOD; }
    ans += now;
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}
