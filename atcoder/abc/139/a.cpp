#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;
long long MOD = 1e9 + 7;

int main() {
  string S, T;
  cin >> S >> T;
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    if (S[i] == T[i]) {
      ans += 1;
    }
  }

  cout << ans << endl;

  return 0;
}
