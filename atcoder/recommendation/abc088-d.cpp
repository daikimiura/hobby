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

int main()
{
  int H, W;
  char g[100][100];
  int black_num = 0;
  cin >> H >> W;

  rep(i, H) rep(j, W)
  {
    cin >> g[i][j];
    if (g[i][j] == '#')
      black_num++;
  }

  pair<int, int> start;
  start = {0, 0};

  queue<pair<int, int>> q;
  q.push(start);

  int dh[4] = {1, 0, -1, 0};
  int dw[4] = {0, -1, 0, 1};

  int d[100][100];

  rep(i, H) rep(j, W)
      d[i][j] = -1;

  d[0][0] = 1;
  while (!q.empty())
  {
    pair<int, int> tmp = q.front();
    q.pop();

    int tmp_h = tmp.first;
    int tmp_w = tmp.second;

    rep(i, 4)
    {
      int next_h = tmp_h + dh[i];
      int next_w = tmp_w + dw[i];

      if (next_h < 0 || next_h > H - 1 || next_w < 0 || next_w > W - 1)
        continue;
      if (g[next_h][next_w] == '#')
        continue;

      if (d[next_h][next_w] == -1)
      {
        d[next_h][next_w] = d[tmp_h][tmp_w] + 1;
        q.push({next_h, next_w});
      }
    }
  }

  if (d[H - 1][W - 1] == -1)
    cout << -1 << endl;
  else
    cout << H * W - d[H - 1][W - 1] - black_num << endl;

  return 0;
}
