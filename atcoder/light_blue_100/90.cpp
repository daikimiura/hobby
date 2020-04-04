#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long mod = 1e9 + 7;
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
  int n, m;
  cin >> n >> m;

  vector<vector<double>> nv;
  vector<vector<double>> mv;

  double min2 = 10000;
  rep(i, n)
  {
    double x, y, r;
    cin >> x >> y >> r;
    nv.push_back({x, y, r});
    chmin(min2, r);
  }

  rep(i, m)
  {
    double x, y;
    cin >> x >> y;
    mv.push_back({x, y});
  }

  rep(i, m - 1)
  {
    repi(j, i + 1, m)
    {
      chmin(min2, sqrt((mv[i][0] - mv[j][0]) * (mv[i][0] - mv[j][0]) + (mv[i][1] - mv[j][1]) * (mv[i][1] - mv[j][1])) / 2);
    }
  }

  rep(i, n)
  {
    rep(j, m)
    {
      chmin(min2, sqrt((nv[i][0] - mv[j][0]) * (nv[i][0] - mv[j][0]) + (nv[i][1] - mv[j][1]) * (nv[i][1] - mv[j][1])) - nv[i][2]);
    }
  }

  cout << setprecision(10) << min2 << endl;
  return 0;
}
