#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(m), y(m);
  vector<vector<int>> y_sort(n + 1);

  rep(i, m) {
    cin >> p[i] >> y[i];
    y_sort[p[i]].push_back(y[i]);
  }

  rep(i, n) { sort(y_sort[i + 1].begin(), y_sort[i + 1].end()); }

  for (int i = 0; i < m; i++) {
    printf("%012lld\n", ll(p[i]) * 1000000 +
                            int(lower_bound(all(y_sort[p[i]]), y[i]) -
                                y_sort[p[i]].begin()) +
                            1);
  }

  return 0;
}
