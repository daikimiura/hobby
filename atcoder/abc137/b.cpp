#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int k, x;
  cin >> k >> x;

  for (int i = x - k + 1; i <= k + x - 1; i++) {
    cout << i << endl;
  }
  return 0;
}
