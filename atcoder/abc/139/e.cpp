#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int N;
  vector<vector<int>> bo;
  rep(i, N) {
    int order = 0;
    for (int j = 0; j++; j < N - 1) {
      if (i == j) {
        continue;
      } else {
        int aite;
        cin >> aite >> endl;
        bo[i][aite] = order;
        order++;
      }
    }
  }

  for (int i = 0; i < N * (N - 1) / 2; i++) {
  }

  return 0;
}
