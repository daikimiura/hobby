#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  int unh = 0;

  char tmp = 'A';
  rep(i, s.size()) {
    if (tmp == 'R' && s[i] == 'L') {
      unh += 2;
      tmp = s[i];
      continue;
    }

    if (i == 0 && s[i] == 'L') {
      unh++;
      tmp = s[i];
      continue;
    }

    if (i == s.size() - 1 && s[i] == 'R') {
      unh++;
      tmp = s[i];
      continue;
    }

    tmp = s[i];
  }

  if (2 * k < unh) {
    unh -= 2 * k;
  } else {
    unh = 1;
  }

  cout << n - unh << endl;
  return 0;
}
