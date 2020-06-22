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
  int n, q;
  cin >> n >> q;

  // 所属幼稚園とレート
  pint kg[200005];

  // 所属幼稚園ごとのrateの集合
  vector<multiset<int>> rates(200005);

  // 最もrateが高い園児の集合
  multiset<int> max_rate;

  rep(i, n)
  {
    int a, b;
    cin >> a >> b;
    kg[i] = {b, a};
    rates[b].insert(a);
  }

  for (auto r : rates)
  {
    if (r.size() != 0)
      max_rate.insert(*r.rbegin());
  }

  rep(i, q)
  {
    int c, d;
    cin >> c >> d;
    --c;

    max_rate.erase(max_rate.find(*(rates[kg[c].first].rbegin())));

    if (rates[d].size() != 0)
      max_rate.erase(max_rate.find(*(rates[d].rbegin())));

    rates[kg[c].first].erase(rates[kg[c].first].find(kg[c].second));
    rates[d].insert(kg[c].second);

    if (rates[kg[c].first].size() != 0)
      max_rate.insert(*(rates[kg[c].first].rbegin()));

    max_rate.insert(*(rates[d].rbegin()));
    kg[c].first = d;

    cout << *max_rate.begin() << endl;
  }
  return 0;
}
