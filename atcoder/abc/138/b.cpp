#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<double> A;

  rep(i, N) {
    int a;
    cin >> a;
    A.push_back(a);
  }

  double mo;
  for (int i = 0; i < N; i++) {
    mo += double(1 / A[i]);
  }

  cout << double(1 / mo) << endl;

  return 0;
}
