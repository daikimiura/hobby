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

vector<int> IntegerToVector(int bit, int N)
{
    vector<int> S;
    for (int i = 0; i < N; ++i)
    {
        if (bit & (1 << i))
        {
            S.push_back(i);
        }
    }
    return S;
}

int main()
{
    int n, q;
    cin >> n;
    int a[n];
    rep(i, n)
    {
        cin >> a[i];
    }

    set<int> s;
    for (int bit = 0; bit < (1 << n); ++bit)
    {
        vector<int> S = IntegerToVector(bit, n);
        int sum = 0;
        for (int i : S)
            sum += a[i];

        s.insert(sum);
    }

    cin >> q;
    rep(i, q)
    {
        int qq;
        cin >> qq;
        if (s.find(qq) != s.end())
            cout << "yes" << endl;
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}
