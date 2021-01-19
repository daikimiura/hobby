#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long mod = 1e9 + 7;
const int iINF = 0x3f3f3f3f;
const long long INF = 1LL << 60;
using namespace std;
using pint = pair<int, int>;

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
  int h, w;
  cin >> h >> w;
  char s[21][21];
  int d[21][21];
  rep(i, h) rep(j, w) cin >> s[i][j];

  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  int ans = 0;
  rep(i, h) rep(j, w)
  {
    if (s[i][j] == '#')
      continue;

    rep(k, h) rep(l, w) d[k][l] = iINF;
    queue<pint> q;
    d[i][j] = 0;
    pint start = {i, j};
    q.push(start);

    while (!q.empty())
    {
      pint cur = q.front();
      q.pop();

      rep(k, 4)
      {
        int next_y = cur.first + dy[k];
        int next_x = cur.second + dx[k];

        if (0 <= next_x && next_x < w && 0 <= next_y && next_y < h && s[next_y][next_x] == '.' && d[next_y][next_x] == iINF)
        {
          q.push({next_y, next_x});
          d[next_y][next_x] = d[cur.first][cur.second] + 1;
        }
      }
    }
    rep(k, h) rep(l, w)
    {
      if (d[k][l] != iINF && s[k][l] == '.')
        chmax(ans, d[k][l]);
    }
  }

  cout << ans << endl;

  return 0;
}
