#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;
long long MOD = 1e9 + 7;

int main() {
  string s, t, u;
  int a, b;
  cin >> s >> t >> a >> b >> u;
  if (u == s) {
    cout << a - 1 << " " << b << endl;
  } else {
    cout << a << " " << b - 1 << endl;
  }

  return 0;
}
