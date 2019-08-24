#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

vector<int> to[200005];
vector<int> ans;

void dfs(int v, int p = -1) {
  for (int u : to[v]) {
    if (u == p)
      continue;
    ans[u] += ans[v];
    dfs(u, v);
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;

  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  ans.resize(N);

  rep(i, Q) {
    int p, x;
    cin >> p >> x;
    --p;
    ans[p] += x;
  }

  dfs(0);
  rep(i, N) { cout << ans[i] << endl; }
  return 0;
}
