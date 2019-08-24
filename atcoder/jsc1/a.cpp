#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
  int M, D;
  cin >> M >> D;
  int ans = 0;
  rep(p, M) {
    int month;
    month = p + 1;
    rep(i, D) {
      int j = i + 1;
      int ten;
      int one;
      ten = j / 10;
      one = j % 10;
      if (ten * one == month && ten >= 2 && one >= 2)
        ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
