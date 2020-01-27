#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  ll N;
  cin >> N;

  vector<ll> ya;

  for (ll i = 1; i * i < N + 1; i++) {
    if (N % i == 0) {
      ya.push_back(i);
    }
  }

  ll res = 1e12 + 1;

  for (const ll &e : ya) {
    res = min(res, e + (N / e) - 2);
  }
  cout << res << endl;
  return 0;
}
