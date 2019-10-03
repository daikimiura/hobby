#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int n;
  int ans = 0;
  cin >> n;

  rep(i, n) {
    int tmp = i + 1;
    if (to_string(tmp).size() % 2 == 1) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
