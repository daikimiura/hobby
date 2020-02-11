#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
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

// dp[i][j] := i番目までの商品から価値がv以上になるように選んだ時の重さの最小値
ll dp[110][100001];

int main() {
  int n, w_limit;
  cin >> n >> w_limit;

  repi(i, 0, n + 1) repi(j, 0, 100001) dp[i][j] = INF;
  dp[0][0] = 0;

  int w[n + 1], v[n + 1];
  repi(i, 1, n + 1) { cin >> w[i] >> v[i]; }

  repi(i, 1, n + 1) {
    repi(j, 0, 100001) {
      // i番目の商品を選ぶ
      if (j - v[i] >= 0) {
        chmin(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
      }
      // i番目の商品を選ばない
      chmin(dp[i][j], dp[i - 1][j]);
    }
  }

  ll ans = 100000;
  while (dp[n][ans] > w_limit)
    ans--;
  cout << ans << endl;
  return 0;
}
