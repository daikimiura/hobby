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
  int h, w, k;
  cin >> h >> w >> k;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  --x1;
  --x2;
  --y1;
  --y2;

  char g[h + 5][w + 5];
  double dist[w + 5][h + 5];

  rep(i, h) rep(j, w)
  {
    cin >> g[i][j];
    dist[i][j] = -1.0;
  }

  queue<pair<pair<int, int>, int>> q;
  q.push({{x1, y1}, -1});
  dist[x1][y1] = 0.0;

  // 0, 1, 2, 3
  const int dx[4] = {1, 0, -1, 0};
  const int dy[4] = {0, 1, 0, -1};

  while (!q.empty())
  {
    pair<int, int> tmp_pos = q.front().first;
    int prev = q.front().second;
    q.pop();
    int tmp_x = tmp_pos.first;
    int tmp_y = tmp_pos.second;

    for (int i = 0; i < 4; i++)
    {
      int next_x = tmp_x + dx[i];
      int next_y = tmp_y + dy[i];

      if (next_x < 0 || next_x >= h || next_y < 0 || next_y >= w)
        continue;
      if (g[next_x][next_y] == '@')
        continue;

      if (dist[next_x][next_y] == -1)
      {
        q.push({{next_x, next_y}, i});

        if (prev == i)
        {
          dist[next_x][next_y] = dist[tmp_x][tmp_y] + 1.0 / k;
        }
        else
        {
          dist[next_x][next_y] = ceil(dist[tmp_x][tmp_y]) + 1.0 / k;
        }
      }
      else
      {
        if (prev == i)
        {
          if (dist[next_x][next_y] > dist[tmp_x][tmp_y])
          {
            dist[next_x][next_y] = dist[tmp_x][tmp_y] + 1.0 / k;
            q.push({{next_x, next_y}, i});
          }
        }
        else
        {
          if (dist[next_x][next_y] > dist[tmp_x][tmp_y] + 1.0 / k)
          {
            dist[next_x][next_y] = ceil(dist[tmp_x][tmp_y]) + 1.0 / k;
            q.push({{next_x, next_y}, i});
          }
        }
      }
    }
  }

  // cout << "==" << endl;
  // rep(i, h)
  // {
  //   rep(j, w)
  //   {
  //     cout << g[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // rep(i, h)
  // {
  //   rep(j, w)
  //   {
  //     cout << dist[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  if (dist[x2][y2] == -1)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << ceil(dist[x2][y2]) << endl;
  }

  return 0;
}
