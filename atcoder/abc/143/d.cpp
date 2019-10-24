#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int N;
  cin >> N;

  int L[N];

  rep(i, N) { cin >> L[i]; }
  sort(L, L + N);

  int count = 0;

  for (int i = 0; i < N - 2; i++) {
    for (int j = i + 1; j < N - 1; j++) {
      int a = L[i];
      int b = L[j];
      for (int k = j + 1; k < N; k++) {
        if (a + b > L[k]) {
          count++;
        } else {
          break;
        }
      }
    }
  }

  cout << count << endl;

  return 0;
}
