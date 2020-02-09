#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

struct Edge {
  int to, id;
};

vector<vector<Edge>> g;
vector<int> ans;

void dfs(int v, int p = -1, int c = -1) {
  int k = 1;
  rep(i, g[v].size()) {
    int u = g[v][i].to;
    int id = g[v][i].id;
    if (u == p)
      continue;
    if (k == c)
      k++;
    ans[id] = k;
    k++;

    dfs(u, v, ans[id]);
  }
}

int main() {
  int n;
  cin >> n;
  ans = vector<int>(n - 1);
  g.resize(n);

  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(Edge{b, i});
    g[b].push_back(Edge{a, i});
  }

  dfs(0);
  int mx = 0;
  rep(i, n) { mx = max(mx, int(g[i].size())); }

  cout << mx << endl;
  rep(i, n - 1) { cout << ans[i] << endl; }
  return 0;
}
