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
  int k;
  cin >> k;
  vector<int> a;
  rep(i, k)
  {
    int x;
    cin >> x;
    a.push_back(x);
  }

  if (*a.rbegin() != 2)
  {
    cout << -1 << endl;
    return 0;
  }

  reverse(a.begin(), a.end());

  vector<ll> next;
  next.push_back(a[0]);
  ll mini, maxi;

  rep(i, k)
  {
    mini = *next.begin();
    maxi = *next.rbegin();
    next.clear();

    next.push_back(ceil(double(mini) / double(a[i])) * a[i]);
    next.push_back(floor(double(maxi) / double(a[i])) * a[i] + a[i] - 1);

    if (*next.begin() == 0 || *next.begin() > *next.rbegin())
    {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << *next.begin() << " " << *next.rbegin() << endl;
  return 0;
}
