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

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f)
{
  if (rest == 0)
  {
    f(indexes);
  }
  else
  {
    if (s < 0)
      return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f)
{
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

int n, m, q;

ll a[100] = {};
ll b[100] = {};
ll c[100] = {};
ll d[100] = {};
ll ans = 0;

void dfs(vector<int> vec)
{
  ll last = vec[vec.size() - 1];
  if (vec.size() == n)
  {
    // rep(i, vec.size())
    // {
    //   cout << vec[i] << ",";
    // }
    // cout << endl;
    ll tmp = 0;
    rep(i, q)
    {
      if (vec[b[i] - 1] - vec[a[i] - 1] == c[i])
      {
        tmp += d[i];
      }
    }
    // cout << tmp << endl;
    ans = max(ans, tmp);
    return;
  }

  if (last == m)
  {
    vec.push_back(m);
    dfs(vec);
  }
  else
  {
    for (ll i = last; i <= m; i++)
    {
      vector<int> vec_a;
      vec_a = vec;
      vec_a.push_back(i);
      dfs(vec_a);
    }
  }
  return;
}

int main()
{

  cin >> n >> m >> q;

  rep(i, q)
  {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  vector<int> vec;
  vec.push_back(1);
  dfs(vec);
  cout << ans << endl;
  return 0;
}
