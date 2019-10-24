#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int N;
  cin >> N;

  int A[N + 1];
  int B[51];
  int C[51];

  rep(i, N) { cin >> A[i]; }

  rep(i, N) { cin >> B[i]; }

  rep(i, N - 1) { cin >> C[i]; }

  int tmp = 0;
  int result = 0;

  rep(i, N) {
    result += B[A[i] - 1];

    if (tmp != 0 && tmp == A[i] - 1) {
      result += C[tmp - 1];
    }
    tmp = A[i];
  }

  cout << result << endl;
  return 0;
}
