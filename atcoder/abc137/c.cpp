#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

using namespace std;

int main() {
  int N;
  cin >> N;

  unordered_map<string, int> mp;
  rep(i, N) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    mp[s]++;
  }

  ll ans = 0;

  for (auto &p : mp) {
    int s = p.second;
    ans += (ll)s * (s - 1) / 2;
  }

  cout << ans << endl;
  return 0;
}
