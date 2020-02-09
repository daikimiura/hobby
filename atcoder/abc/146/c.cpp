#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  ll a, b, x;
  cin >> a >> b >> x;

  ll left, right;
  left = 0;
  right = 1e9 + 1;

  while (right - left > 1) {
    ll mid = (left + right) / 2;
    if (a * mid + b * (int(log10(mid)) + 1) > x) {
      right = mid;
    } else {
      left = mid;
    }
  }

  cout << left << endl;
  return 0;
}
