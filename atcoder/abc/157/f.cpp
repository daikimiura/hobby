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
  int a[65][3];
  rep(i, n) {
    int x, y, c;
    cin >> x >> y >> c;
    a[i][0] = x;
    a[i][1] = y;
    a[i][2] = c;
  }

  double jyu_x, jyu_y, jyu_w = 0.0;

  rep(i, n) {
    jyu_x = (jyu_w * a[i][0] + a[i][2] * jyu_x) / (jyu_w + a[i][2]);
    jyu_y = (jyu_w * a[i][1] + a[i][2] * jyu_y) / (jyu_w + a[i][2]);
    jyu_w += a[i][2];
  }

  cout << jyu_x << " " << jyu_y << endl;

  return 0;
}
