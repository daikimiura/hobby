#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  double a, b, x;
  cin >> a >> b >> x;

  double ans;
  if ((x / a) >= (a * b) / 2) {
    ans = 90 - (atan(1 / ((2 * b / a) - (2 * x / (a * a * a)))) * 180 / M_PI);
  } else {
    ans = atan((a * b * b) / (2 * x)) * 180 / M_PI;
  }

  cout << setprecision(12) << ans << endl;
  return 0;
}
