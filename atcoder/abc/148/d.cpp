#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a;
  rep(i, n) {
    int x;
    cin >> x;
    a.push_back(x);
  }

  int tmp = 1;
  int ans = 0;
  bool ok = false;

  rep(i, n) {
    if (a[i] != tmp) {
      ans++;
      continue;
    } else {
      ok = true;
      tmp++;
    }
  }

  if (ok) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  };
  return 0;
}
