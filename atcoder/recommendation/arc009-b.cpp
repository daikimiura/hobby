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
  vector<int> vec;
  int ord[10] = {};

  rep(i, 10)
  {
    int b;
    cin >> b;
    ord[b] = i;
  }

  int n;
  cin >> n;
  rep(i, n)
  {
    string a;
    cin >> a;

    int keta = 1;
    int tmp = 0;
    for (int j = a.size() - 1; j >= 0; j--)
    {
      tmp += ord[a[j] - '0'] * keta;
      keta *= 10;
    }
    vec.push_back(tmp);
    mp[tmp] = stoi(a);
  }

  sort(vec.begin(), vec.end());

  for (auto i : vec)
  {
    cout << mp[i] << endl;
  }

  return 0;
}
