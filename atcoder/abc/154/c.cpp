#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) { cin >> a[i]; }

  sort(a, a + n);
  rep(i, n - 1) {
    if (a[i] == a[i + 1]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
