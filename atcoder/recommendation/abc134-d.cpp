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

int modo[200200] = {};
bool ans[200200] = {};

void update(int num)
{
  for (int i = 1; i * i <= num; i++)
  {
    if (num % i == 0)
    {
      if (i == 1)
      {
        if (modo[i] == 1)
          modo[i] = 0;
        else
          modo[i] = 1;
      }
      else if (i * i == num)
      {
        if (modo[i] == 1)
          modo[i] = 0;
        else
          modo[i] = 1;
      }
      else
      {
        if (modo[i] == 1)
          modo[i] = 0;
        else
          modo[i] = 1;

        if (modo[num / i] == 1)
          modo[num / i] = 0;
        else
          modo[num / i] = 1;
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;
  int a[200200];
  repi(i, 1, n + 1)
  {
    cin >> a[i];
  }

  rep(i, n)
  {
    modo[i] = -1;
    ans[i] = false;
  }

  for (int i = n; i >= 1; i--)
  {
    if (modo[i] == -1)
    {
      if (a[i] == 0)
      {
        ans[i] = false;
        continue;
      }
      else
      {
        ans[i] = true;
        update(i);
        continue;
      }
    }
    else if (a[i] == 0)
    {
      if (modo[i] == 0)
      {
        ans[i] = false;
        continue;
      }
      else
      {
        ans[i] = true;
        update(i);
        continue;
      }
    }
    else if (a[i] == 1)
    {
      if (modo[i] == 0)
      {
        ans[i] = true;
        update(i);
        continue;
      }
      else
      {
        ans[i] = false;
        continue;
      }
    }
  }

  int count = 0;
  repi(i, 1, n + 1)
  {
    if (ans[i])
      count++;
  }

  cout << count << endl;
  repi(i, 1, n + 1)
  {
    if (ans[i])
      cout << i << " ";
  }
  return 0;
}
