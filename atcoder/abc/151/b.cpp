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
  int n, k, m;
  cin >> n >> k >> m;
  int a[n - 1];
  rep(i, n - 1) { cin >> a[i]; }

  int goal = n * m;
  int sum = 0;

  rep(i, n - 1) { sum += a[i]; }

  if (goal - sum <= k) {
    cout << max(0, goal - sum) << endl;
  } else {
    cout << "-1" << endl;
  }
  return 0;
}
