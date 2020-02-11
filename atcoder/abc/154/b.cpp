#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  string s;
  cin >> s;
  string ans = "";
  rep(i, s.size()) { ans += "x"; }
  cout << ans << endl;
  return 0;
}
