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
  ll a, b, k;
  cin >> a >> b >> k;
  ll ans_a = a, ans_b = b;

  if (a <= k) {
    ans_a = 0;
    if (b <= k - a) {
      ans_b = 0;
    } else {
      ans_b = b - k + a;
    }
  } else {
    ans_a = a - k;
  }

  cout << ans_a << " " << ans_b << endl;
  return 0;
}
