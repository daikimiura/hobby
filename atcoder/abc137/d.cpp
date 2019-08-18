#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> jobs(m);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    if (a > m)
      continue;
    jobs[m - a].push_back(b);
  }

  priority_queue<int> q;
  ll ans = 0;

  for (int i = m - 1; i >= 0; --i) {
    for (auto &b : jobs[i]) {
      q.push(b);
    }
    if (!q.empty()) {
      ans += q.top();
      q.pop();
    }
  }
  cout << ans << endl;
  return 0;
}
