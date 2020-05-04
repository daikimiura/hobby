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
  int n, m;
  cin >> n >> m;
  ll h[100100];
  set<int> st;
  rep(i, n)
  {
    cin >> h[i];
    st.insert(i);
  }

  vector<vector<int>> g(1001000);
  rep(i, m)
  {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    if (h[a] > h[b])
      st.erase(b);
    else if (h[a] < h[b])
      st.erase(a);
    else
    {
      st.erase(a);
      st.erase(b);
    }
  }

  cout << st.size() << endl;
  return 0;
}
