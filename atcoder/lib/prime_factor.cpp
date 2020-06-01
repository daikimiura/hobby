// https: //ei1333.github.io/luzhiled/snippets/math/prime-factor.html
map<int64_t, int> prime_factor(int64_t n)
{
    map<int64_t, int> ret;
    for (int64_t i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1)
        ret[n] = 1;
    return ret;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=jp
// int main()
// {
//     int N;
//     cin >> N;
//     cout << N << ":";
//     for (auto p : prime_factor(N))
//     {
//         while (p.second--)
//             cout << " " << p.first;
//     }
//     cout << endl;
// }