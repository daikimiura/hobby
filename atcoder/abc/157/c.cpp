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
  int n, m;
  cin >> n >> m;
  int s[5];
  rep(i, 6) { s[i] = -1; }

  rep(i, m) {
    int si, ci;
    cin >> si >> ci;

    if (s[si - 1] != -1 && s[si - 1] != ci) {
      cout << "-1" << endl;
      return 0;
    }

    if (si == 1 && ci == 0 && n != 1) {
      cout << "-1" << endl;
      return 0;
    }

    s[si - 1] = ci;
  }

  int ans[5];
  rep(i, n) {
    if (s[i] != -1) {
      ans[i] = s[i];
    } else {
      if (n != 1 && i == 0) {
        ans[i] = 1;
      } else {
        ans[i] = 0;
      }
    }
  }

  int res = 0;

  rep(i, n) { res += ans[i] * pow(10, n - i - 1); }

  cout << res << endl;
  return 0;
}
