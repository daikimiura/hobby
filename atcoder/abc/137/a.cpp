#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  int res;
  cin >> a >> b;
  res = max(a + b, a - b);
  cout << max(res, a * b) << endl;
  return 0;
}
