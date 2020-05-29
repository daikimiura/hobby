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

bool pair_compair_blue(pair<int, int> a, pair<int, int> b)
{
  if (a.first != b.first)
  {
    return a.first < b.first;
  }
  else
  {
    return a.second > b.second;
  }
}

bool pair_compair_red(pair<int, int> a, pair<int, int> b)
{
  if (a.second != b.second)
  {
    return a.second > b.second;
  }
  else
  {
    return a.first < b.first;
  }
}

int main()
{
  int n;
  cin >> n;

  vector<pair<int, int>> r, b;
  bool used[110] = {};

  rep(i, n)
  {
    int x, y;
    cin >> x >> y;
    r.push_back({x, y});
  }

  rep(i, n)
  {
    int x, y;
    cin >> x >> y;
    b.push_back({x, y});
  }

  sort(r.begin(), r.end(), pair_compair_red);
  sort(b.begin(), b.end(), pair_compair_blue);

  int ans = 0;
  for (auto blue : b)
  {
    rep(i, n)
    {
      if (used[i])
        continue;

      auto red = r[i];
      if (blue.first >= red.first + 1 && blue.second >= red.second + 1)
      {
        ans++;
        used[i] = true;
        // cout << "blue: " << blue.first << " " << blue.second << endl;
        // cout << "red: " << red.first << " " << red.second << endl;
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
