#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const long long MOD = 1e9 + 7;
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
  int n;
  cin >> n;
  ll h[n];
  rep(i, n) { cin >> h[i]; }

  ll dp[n];
  // dp テーブルの初期化
  rep(i, n) { dp[i] = INF; }
  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);

  for (int i = 1; i < n; i++) {
    chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
    chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
  }

  cout << dp[n - 1] << endl;

  return 0;
}
