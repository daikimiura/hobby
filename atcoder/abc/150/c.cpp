#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long MOD = 1e9 + 7;
const long long INF = 1LL << 60;
using namespace std;

template <class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<int> p, q, v;

  rep(i, n) {
    int p_i;
    cin >> p_i;
    p.push_back(p_i);
  }

  rep(i, n) {
    int q_i;
    cin >> q_i;
    q.push_back(q_i);
  }

  rep(i, n) { v.push_back(i + 1); }

  int p_count = 0;
  int q_count = 0;

  int p_val = 0;
  int q_val = 0;

  rep(i, n) {
    p_val += p[i] * pow(10, n - 1 - i);
    q_val += q[i] * pow(10, n - 1 - i);
  }

  do {
    int val = 0;
    rep(i, n) { val += v[i] * pow(10, n - 1 - i); }

    if (p_val > val)
      p_count++;
    if (q_val > val)
      q_count++;
  } while (next_permutation(v.begin(), v.end()));

  cout << abs(q_count - p_count) << endl;
  return 0;
}
