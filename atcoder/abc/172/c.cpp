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

ll n, m, k;

ll a[200005], b[200005];
ll tmp_time = 0;
int ans = 0;

int dfs1(int a_index, int b_index, ll tmp_time, int tmp_ans)
{
  if (a_index <= n - 1)
  {
    if (tmp_time + a[a_index] <= k)
    {
      tmp_time += a[a_index];
      a_index++;

      if (ans < ++tmp_ans)
      {
        ans = tmp_ans;
      }

      dfs1(a_index, b_index, tmp_time, tmp_ans);
    }
  }

  if (b_index <= m - 1)
  {
    if (tmp_time + b[b_index] <= k)
    {
      tmp_time += b[b_index];
      b_index++;

      if (ans < ++tmp_ans)
      {
        ans = tmp_ans;
      }

      chmax(ans, tmp_ans);
      dfs1(a_index, b_index, tmp_time, tmp_ans);
    }
  }
  return tmp_ans;
}

int dfs2(int a_index, int b_index, int tmp_time, int tmp_ans)
{
  if (b_index <= m - 1)
  {
    if (tmp_time + b[b_index] <= k)
    {
      tmp_time += b[b_index];
      b_index++;

      if (ans < ++tmp_ans)
      {
        ans = tmp_ans;
      }
      dfs2(a_index, b_index, tmp_time, tmp_ans);
    }
  }

  if (a_index <= n - 1)
  {
    if (tmp_time + a[a_index] <= k)
    {
      tmp_time += a[a_index];
      a_index++;

      if (ans < ++tmp_ans)
      {
        ans = tmp_ans;
      }

      dfs2(a_index, b_index, tmp_time, tmp_ans);
    }
  }

  return tmp_ans;
}

int main()
{

  cin >> n >> m >> k;
  rep(i, n)
  {
    cin >> a[i];
  }

  rep(i, m)
  {
    cin >> b[i];
  }

  int a_index = 0;
  int b_index = 0;
  dfs1(0, 0, 0, 0);
  dfs2(0, 0, 0, 0);

  cout << ans << endl;
  return 0;
}
