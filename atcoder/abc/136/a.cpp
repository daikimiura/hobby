#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;
long long MOD = 1e9 + 7;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << max(c - (a - b), 0) << endl;
  return 0;
}
