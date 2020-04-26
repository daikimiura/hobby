#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long mod = 1e9 + 7;
const int iINF = 0x3f3f3f3f;
const long long INF = 1LL << 60;
using namespace std;

template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}

struct Edge
{
  int to, sil, cost;
};

int V;
vector<vector<Edge>> g(100100);
int costs[100100][100100] = {};

// pair<コスト, pair<頂点, 消費した銀貨の枚数>>
using P = pair<int, pair<int, int>>;

void dijkstra(int s)
{
  // コストが小さいものがtop()にくる
  priority_queue<P, vector<P>, greater<P>> q;
  memset(costs, 0x3f, sizeof(costs));
  costs[s][0] = 0;
  q.push(P(0, pair<int, int>(1, 0)));

  while (!q.empty())
  {
    P p = q.top();
    q.pop();

    int v = p.second.first;
    int c = p.second.second;
    if (costs[v][c] < p.first)
      continue;

    rep(i, g[v].size())
    {
      Edge e = g[v][i];
      if(e.sil >= c) {
　　　　　// 銀貨を交換するしかない
        if (costs[e.to] > costs[v] + e.cost)
        {
          costs[e.to] = costs[v] + e.cost;
          q.push(P(costs[e.to], e.to));
        }
      }else{
        // 銀貨を交換する
        // 銀貨を交換しない

      }
      
    }
  }
}

int main()
{
  int V, E, S;
  cin >> V >> E >> S;

  rep(i, E)
  {
    int s, t, a, d;
    cin >> s >> t >> a >> d;
    Edge e = {t, a, d};
    g[s].push_back(e);
    Edge e2 = {s, a, d};
    g[t].push_back(e2);
  }

  dijkstra(1);

  // for (int i = 0; i < V; ++i)
  // {
  //   if (costs[i] != iINF)
  //     cout << costs[i] << endl;
  //   else
  //     cout << "INF" << endl;
  // }
  return 0;
}
