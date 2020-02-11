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
  int n;
  cin >> n;
  int a[n], b[n], c[n];
  rep(i, n) { cin >> a[i] >> b[i] >> c[i]; }

  int dp[n][3];
  dp[0][0] = a[0];
  dp[0][1] = b[0];
  dp[0][2] = c[0];

  for (int i = 1; i < n; i++) {
    dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b[i];
    dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c[i];
  }

  cout << max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << endl;

  return 0;
}
