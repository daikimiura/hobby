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

int n, m, k;
vector<int> a, b;
ll sum = 0;

bool ok(int x)
{
  int a_index = n - 1;
  int b_index = m - 1;
  rep(i, n + m - x)
  {
    if (a_index > 0 && a[a_index] > b[b_index])
    {
      a_index--;
      sum -= a[a_index];
      if (sum <= k)
      {
        return true;
      }
    }
    else if (b_index > 0)
    {
      b_index--;
      sum -= b[b_index];
      if (sum <= k)
      {
        return true;
      }
    }

    if (a_index < 0 || b_index < 0)
      return false;
  }
  return false;
};

int main()
{

  cin >> n >> m >> k;

  rep(i, n)
  {
    cin >> a[i];
    sum += a[i];
  }

  rep(i, m)
  {
    cin >> b[i];
    sum += b[i];
  }

  int l = 0;
  int r = n + m;
  ll tmp = sum;

  while (r - l > 1)
  {
    int mid = (l + r) / 2;
    cout << "mid"
         << " " << mid << endl;
    sum = tmp;
    if (ok(mid))
    {
      cout << "ok" << endl;
      l = mid;
    }
    else
    {
      cout << "ng" << endl;
      r = mid;
    }
  }

  cout << l << endl;
  return 0;
}
