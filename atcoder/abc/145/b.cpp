#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  if (n % 2 != 0) {
    cout << "No" << endl;
    return 0;
  } else {
    rep(i, n / 2) {
      if (s[i] != s[i + n / 2]) {
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
  }
  return 0;
}
