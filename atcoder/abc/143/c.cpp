#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int N;
  cin >> N;

  string S;
  cin >> S;

  char tmp;
  int count = 1;

  rep(i, S.size()) {
    if (i == 0) {
      tmp = S[i];
      continue;
    }
    if (tmp != S[i]) {
      count++;
    }
    tmp = S[i];
  }

  cout << count << endl;
  return 0;
}
