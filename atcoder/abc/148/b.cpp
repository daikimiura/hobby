#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  string ans = "";

  rep(i, n) {
    ans += s[i];
    ans += t[i];
  }

  cout << ans << endl;
  return 0;
}
