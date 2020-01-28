#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int n;
  int x[10];
  int y[10];
  cin >> n;
  rep(i, n) { cin >> x[i] >> y[i]; }

  double ans = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      double dx = x[i] - x[j];
      double dy = y[i] - y[j];
      ans += pow(dx * dx + dy * dy, 0.5) * 2 / n;
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
