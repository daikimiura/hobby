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

// dp[i][j] :=
// i番目までの商品を、重さがj以下になるように選んだ時の価値の最大値
ll dp[110][100100] = {0};

int main() {
  int n, w_limit;
  cin >> n >> w_limit;

  int w[n + 1];
  int v[n + 1];
  repi(i, 1, n + 1) { cin >> w[i] >> v[i]; }

  repi(i, 1, n + 1) {
    repi(j, 0, w_limit + 1) {
      // i番目の商品を選ぶ場合
      if (j >= w[i]) {
        chmax(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
      }

      // i番目の商品を選ばない場合
      chmax(dp[i][j], dp[i - 1][j]);
    }
  }

  cout << dp[n][w_limit] << endl;
  return 0;
}
