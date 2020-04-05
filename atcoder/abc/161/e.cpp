#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long mod = 1e9 + 7;
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
  int k;
  cin >> k;

  queue<string> q;
  q.push("0");
  string ans = "";
  int count = 0;
  int keta = 1;

  while (count < k)
  {
    string tmp = q.front();
    ans = tmp;
    q.pop();

    if (tmp != "0")
      count++;

    if (keta == 1)
    {
      q.push("1");
      q.push("2");
      q.push("3");
      q.push("4");
      q.push("5");
      q.push("6");
      q.push("7");
      q.push("8");
      q.push("9");
      keta++;
      continue;
    }

    if (tmp[tmp.size() - 1] == '0')
    {
      q.push(tmp + '0');
      q.push(tmp + '1');
      continue;
    }

    if (tmp[tmp.size() - 1] == '9')
    {
      q.push(tmp + '8');
      q.push(tmp + '9');
      continue;
    }

    char last = tmp[tmp.size() - 1];
    int lasti = last - '0';

    for (int i = -1; i <= 1; i++)
    {
      char nextc = '0' + (lasti + i);
      q.push(tmp + nextc);
    }
  }

  cout << ans << endl;

  return 0;
}
