#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int N;
  ll H[100005];
  cin >> N;
  rep(i, N) { cin >> H[i]; }

  ll count = 0;
  ll tmp = 0;
  for (int i = 0; i < N - 1; i++) {
    if (H[i] >= H[i + 1]) {
      tmp += 1;
    } else {
      count = max(count, tmp);
      tmp = 0;
    }
  }
  count = max(count, tmp);
  cout << max(count, tmp) << endl;

  return 0;
}
