#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int n;
  cin >> n;
  int h[n];
  rep(i, n) { cin >> h[i]; }
  int tmp;

  tmp = h[0];
  for (int i = 1; i < n; i++) {
    if (h[i] < tmp) {
      cout << "No" << endl;
      return 0;
    } else {
      if (h[i] > tmp) {
        tmp = h[i] - 1;
      } else {
        tmp = h[i];
      }
    }
  }

  cout << "Yes" << endl;

  return 0;
}
