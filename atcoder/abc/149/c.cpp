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
  ll x;
  cin >> x;

  while (true) {
    bool is_prime = true;
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        is_prime = false;
      }
    }
    if (is_prime) {
      cout << x << endl;
      return 0;
    }
    x++;
  }

  return 0;
}
