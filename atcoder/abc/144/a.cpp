#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;
long long MOD = 1e9 + 7;

int main() {
  int a, b;
  cin >> a >> b;
  if (a > 9 || b > 9) {
    cout << -1 << endl;
    return 0;
  }

  cout << a * b << endl;
  return 0;
}
