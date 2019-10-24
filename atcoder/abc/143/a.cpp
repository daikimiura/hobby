#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;
long long MOD = 1e9 + 7;

int main() {
  int a, b;
  cin >> a >> b;
  int res;
  res = a - 2 * b;
  if (res > 0) {
    cout << res << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
