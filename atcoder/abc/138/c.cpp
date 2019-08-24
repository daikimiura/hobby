#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
  int N;
  cin >> N;
  double A[N];
  rep(i, N) { cin >> A[i]; }

  sort(A, A + N);

  double ans;
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      continue;
    };
    if (i == 1) {
      ans = 0.5 * (A[0] + A[1]);
      continue;
    }
    ans = 0.5 * (ans + A[i]);
  }

  cout << ans << endl;
  return 0;
}
