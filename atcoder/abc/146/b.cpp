#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  rep(i, s.size()) {
    int x;
    x = s[i] - 'A';
    s[i] = 'A' + (x + n) % 26;
  }

  cout << s << endl;
  return 0;
}
