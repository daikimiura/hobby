#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int N;
  ll K;
  cin >> N >> K;
  int A[2005];
  ll low_sum = 0;
  rep(i, N) { cin >> A[i]; }

  ll tmp = 0;
  for (int p = 0; p < N; p++) {
    for (int q = 0; q < N; q++) {
      if (A[p] > A[q] && p < q) {
        tmp++;
      }
      if (A[p] > A[q]) {
        low_sum++;
      }
    }
  }

  long long ans = 0;
  long long cal = K * (K - 1) / 2 % MOD;
  ans += tmp * K % MOD;
  ans %= MOD;
  ans += low_sum * cal % MOD;
  ans %= MOD;
  cout << ans << endl;
  return 0;
}
