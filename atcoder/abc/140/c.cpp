#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int N;
  cin >> N;

  int B[N];
  rep(i, N - 1) { cin >> B[i]; }

  ll result = 0;

  rep(i, N - 1) {
    if (i == 0) {
      result += B[0] + min(B[0], B[1]);
    } else if (i == N - 2) {
      result += B[i];
    } else {
      result += min(B[i], B[i + 1]);
    }
  }

  cout << result << endl;
  return 0;
}
