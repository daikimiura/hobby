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
  int H, W, N, sr, sc;
  cin >> H >> W >> N >> sr >> sc;
  --sr;
  --sc;

  string S, T;
  cin >> S >> T;

  bool ok = true;
  int w_min, w_max, h_min, h_max;

  w_min = h_min = 0;
  w_max = W - 1;
  h_max = H - 1;

  if (S[N - 1] == 'L')
    w_min++;
  if (S[N - 1] == 'R')
    w_max--;
  if (S[N - 1] == 'U')
    h_min++;
  if (S[N - 1] == 'D')
    h_max--;

  // 横方向
  for (int i = N - 2; i >= 0; i--)
  {
    if (!ok)
      continue;

    if (T[i] == 'L')
    {
      w_max = min(w_max + 1, W - 1);
    }
    if (T[i] == 'R')
    {
      w_min = max(w_min - 1, 0);
    }

    if (S[i] == 'L')
    {
      w_min++;
    }

    if (S[i] == 'R')
    {
      w_max--;
    }

    if (w_min < 0 || w_max < 0 || w_max < w_min)
      ok = false;

    if (!ok)
    {
      cout << "NO" << endl;
      return 0;
    }
  }
  // 縦方向
  for (int i = N - 2; i >= 0; i--)
  {

    if (!ok)
      continue;

    if (T[i] == 'U')
    {
      h_max = min(h_max + 1, H - 1);
    }
    if (T[i] == 'D')
    {
      h_min = max(h_min - 1, 0);
    }

    if (S[i] == 'U')
    {
      h_min++;
    }
    if (S[i] == 'D')
    {
      h_max--;
    }

    if (h_min < 0 || h_max < 0 || h_max < h_min)
      ok = false;
  }

  if (!ok)
  {
    cout << "NO" << endl;
    return 0;
  }

  cout << h_min << h_max << w_min << w_max << endl;
  cout << sr << sc << endl;
  // if スタートが範囲内
  if (h_min <= sr && sr <= h_max && w_min <= sc && sc <= w_max)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
