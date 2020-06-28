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
  ll n, m, k;
  cin >> n >> m >> k;

  int a[200005], b[200005];
  rep(i, n)
  {
    cin >> a[i];
  }

  rep(i, m)
  {
    cin >> b[i];
  }

  ll tmp_time = 0;
  int a_index = 0;
  int b_index = 0;
  int ans = 0;

  while (true)
  {
    if (a_index <= n - 1 && b_index <= m - 1 && a[a_index] == b[b_index])
    {
      // cout << "===" << endl;
      // cout << a[a_index] << endl;
      int iter = min(n - 1 - a_index, m - 1 - b_index);

      if (iter == 0)
      {
        if (tmp_time + b[b_index] > k)
          break;
        tmp_time += b[b_index];
        b_index++;
        ans++;
        continue;
      }

      rep(i, iter)
      {
        if (a[a_index + i + 1] > b[b_index + i + 1])
        {
          if (tmp_time + b[b_index] > k)
            break;
          tmp_time += b[b_index];
          b_index++;
          ans++;
          continue;
        }
        else if (a[a_index + i + 1] < b[b_index + i + 1])
        {
          if (tmp_time + a[a_index] > k)
            break;
          tmp_time += a[a_index];
          a_index++;
          ans++;
          continue;
        }
        else if (i == iter - 1)
        {
          if (tmp_time + a[a_index] > k)
            break;
          tmp_time += a[a_index];
          a_index++;
          ans++;
          // continue;
          // cout << "here" << endl;
        }
      }
      // continue;
    }
    else if (a_index <= n - 1 && (b_index > m - 1 || a[a_index] < b[b_index]))
    {
      if (tmp_time + a[a_index] > k)
        break;
      tmp_time += a[a_index];
      a_index++;
      ans++;
      continue;
    }
    else if (b_index <= m - 1)
    {
      if (tmp_time + b[b_index] > k)
        break;
      tmp_time += b[b_index];
      b_index++;
      ans++;
      continue;
    }
    else
    {
      break;
    }
  }

  cout << ans << endl;
  return 0;
}
