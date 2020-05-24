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

bool pairCompare(const pair<int, int> &firstElof, const pair<int, int> &secondElof)
{
  return firstElof.second < secondElof.second;
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> c;
  rep(i, m)
  {
    int x, y;
    cin >> x >> y;
    c.push_back({x, y});
  }

  sort(c.begin(), c.end(), pairCompare);
  int count = 0;
  int last_removed = -1;

  for (auto i : c)
  {
    if (last_removed == -1)
    {
      last_removed = i.second - 1;
      count++;
      continue;
    }

    if (i.first <= last_removed)
      continue;

    last_removed = i.second - 1;
    count++;
    continue;
  }

  cout << count << endl;

  return 0;
}
