#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
const long long INF = 1LL << 60;
using namespace std;

template <class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int n, k;
  cin >> n >> k;
  ll h[n];
  ll dp[n];

  rep(i, n) { cin >> h[i]; }
  rep(i, n) { dp[i] = INF; }

  dp[0] = 0;

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < k + 1; j++) {
      if (i >= j) {
        chmin(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
      }
    }
  }
  cout << dp[n - 1] << endl;
  return 0;
}
