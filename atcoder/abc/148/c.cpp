#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  ll a, b;
  cin >> a >> b;
  ll i = 1;
  while (true) {
    if (a * i % b == 0) {
      cout << a * i << endl;
      break;
    }
    i++;
  }
  return 0;
}
