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
  int n;
  ll k;
  cin >> n >> k;

  int g[300300] = {};
  rep(i, n)
  {
    int x;
    cin >> x;
    --x;
    g[i] = x;
  }

  int tmp = 0;
  int last = 0;
  int index = 0;
  vector<int> vec;
  map<int, int> mp;

  for (;;)
  {
    auto it = mp.find(tmp);
    if (it == mp.end())
    {
      mp[tmp] = index;
      last = tmp;
      vec.push_back(tmp);
      tmp = g[tmp];
      index++;
    }
    else
    {
      int index = mp[tmp];
      ll size = mp[last] - index + 1;

      if (k <= index)
      {
        cout << vec[k] + 1 << endl;
        return 0;
      }
      else
      {
        ll amari = (k - index) % size;
        cout << vec[index + amari] + 1 << endl;
        return 0;
      }
    }
  }

  return 0;
}
