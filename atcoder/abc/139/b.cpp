#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  if (B == 1) {
    cout << 0 << endl;
    return 0;
  }

  if (A > B) {
    cout << 1 << endl;
    return 0;
  }
  if ((B - A) % (A - 1) == 0) {
    cout << 1 + (B - A) / (A - 1) << endl;
  } else {
    cout << 1 + (B - A) / (A - 1) + 1 << endl;
  }
  return 0;
}
