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
  map<int, int> mp;
  int n;
  cin >> n;
  rep(i, n)
  {
    int x;
    cin >> x;
    mp[x]++;
  }

  vector<ll> v;
  for (auto mpi : mp)
  {
    if (mpi.second >= 2)
    {
      v.push_back(mpi.first);
      if (mpi.second >= 4)
      {
        v.push_back(mpi.first);
      }
    }
  }

  if (v.size() <= 1)
    cout << 0 << endl;
  else
    cout << v[v.size() - 1] * v[v.size() - 2] << endl;
  return 0;
}
