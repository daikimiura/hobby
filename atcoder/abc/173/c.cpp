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

int main()
{
  int h, w, k;
  cin >> h >> w >> k;
  char c[10][10];

  rep(i, h) rep(j, w)
  {
    cin >> c[i][j];
  }

  int ans = 0;

  for (int bit = 0; bit < (1 << (h + w)); ++bit)
  {
    char d[10][10];
    rep(i, h) rep(j, w)
        d[i][j] = c[i][j];

    vector<int> S;
    for (int i = 0; i < (h + w); ++i)
    {
      if (bit & (1 << i))
      { // 列挙に i が含まれるか
        S.push_back(i);
      }
    }

    // cout << "{";
    for (int i = 0; i < (int)S.size(); ++i)
    {
      // cout << S[i] << " ";
      if (S[i] <= (h - 1))
      {
        rep(j, w)
        {
          d[S[i]][j] = '.';
        }
      }
      else
      {
        rep(j, h)
        {
          d[j][S[i] - h] = '.';
        }
      }
    }
    // cout << "}" << endl;

    // チェック
    int count = 0;
    rep(i, h) rep(j, w)
    {
      if (d[i][j] == '#')
        count++;
    }

    if (count == k)
      ans++;
  }

  cout << ans << endl;
  return 0;
}
