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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  rep(i, n - 2) {
    if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
