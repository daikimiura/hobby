#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

const int MAX = 1000000;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

long long COM(int n, int k) {
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  COMinit();
  string n;
  int k;
  cin >> n >> k;
  int keta = n.length();

  int ketaa[keta];

  rep(i, keta) { ketaa[i] = n[i] - '0'; }

  ll ans = 0;
  if (k == 1) {
    cout << (keta - 1) * 9 + ketaa[0] << endl;
  } else if (k == 2) {
    int wa;
    wa = COM(keta - 1, 2) * 9 * 9;
    rep(i, ketaa[0] - 1) { wa += 9 * (keta - 1); };
    wa += ketaa[1] + 9 * (keta - 2);
    cout << wa << endl;
  } else if (k == 3) {
    int wa;
    if (keta > 3) {
      wa = COM(keta - 1, 3) * 9 * 9 * 9;
    } else {
      wa = 0;
    }
    wa += 9 * 9 * COM(keta - 1, 2) * (ketaa[0] - 1);
    for (int i = 1; i < keta - 1; i++) {
      for (int j = i + 1; j < keta; j++) {
        wa += ketaa[i] * ketaa[j];
      }
    }
    cout << wa << endl;
  }
  return 0;
}
