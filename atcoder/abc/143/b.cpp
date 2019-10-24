#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int n;
  cin >> n;

  int d[n + 1];
  rep(i, n) { cin >> d[i]; }

  int sum = 0;

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      sum += d[i] * d[j];
    }
  }

  cout << sum << endl;
  return 0;
}
