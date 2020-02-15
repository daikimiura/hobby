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

int main() {
  int n, k;
  cin >> n >> k;
  int r, s, p;
  cin >> r >> s >> p;
  string t;
  cin >> t;

  string t_sub[k];
  rep(i, n) {
    int mod = i % k;
    t_sub[mod] += t[i];
  }

  ll ans = 0;

  rep(i, k) {
    string t_tmp = t_sub[i];

    // dp[i][j]: i回目にjを出した時にi回目までに得られる最高得点
    int dp[100010][3];
    dp[0][0] = 0; // 0: グー, 1: チョキ, 2: パー
    dp[0][1] = 0; // 0: グー, 1: チョキ, 2: パー
    dp[0][2] = 0; // 0: グー, 1: チョキ, 2: パー
    repi(j, 1, t_tmp.size() + 1) {
      if (t_tmp[j - 1] == 'r') {
        dp[j][0] = max(dp[j - 1][1], dp[j - 1][2]);
        dp[j][1] = max(dp[j - 1][2], dp[j - 1][0]);
        dp[j][2] = max(dp[j - 1][0], dp[j - 1][1]) + p;
      } else if (t_tmp[j - 1] == 's') {
        dp[j][0] = max(dp[j - 1][1], dp[j - 1][2]) + r;
        dp[j][1] = max(dp[j - 1][2], dp[j - 1][0]);
        dp[j][2] = max(dp[j - 1][0], dp[j - 1][1]);
      } else if (t_tmp[j - 1] == 'p') {
        dp[j][0] = max(dp[j - 1][1], dp[j - 1][2]);
        dp[j][1] = max(dp[j - 1][2], dp[j - 1][0]) + s;
        dp[j][2] = max(dp[j - 1][0], dp[j - 1][1]);
      }
    }
    ans +=
        max(dp[t_tmp.size()][0], max(dp[t_tmp.size()][1], dp[t_tmp.size()][2]));
  }

  cout << ans << endl;
  return 0;
}
