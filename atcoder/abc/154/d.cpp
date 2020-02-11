#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int a[n];
  rep(i, n) { cin >> a[i]; }

  vector<int> wa;
  int tmp = 0;
  rep(i, n) {
    wa.push_back(tmp + a[i]);
    tmp = tmp + a[i];
  }

  int left;
  int max_sum = 0;
  rep(i, n - k + 1) {
    int sum = wa[i + k - 1] - wa[i - 1];
    if (sum >= max_sum) {
      max_sum = sum;
      left = i;
    }
  }

  double ans = 0.0;

  for (int i = left; i < left + k; i++) {
    if (a[i] % 2 == 0) {
      ans += double(a[i] / 2) + 0.5;
    } else {
      ans += double(a[i] / 2) + 1;
    }
  }

  cout << setprecision(10) << ans << endl;
  return 0;
}
