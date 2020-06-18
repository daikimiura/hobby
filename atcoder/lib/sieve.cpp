#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int SIEVE_N = pow(10, 5);
vector<bool> isp(SIEVE_N + 1, true);

void sieve()
{
    isp[0] = false;
    isp[1] = false;
    for (int i = 2; pow(i, 2) <= SIEVE_N; i++)
    {
        if (isp[i])
            for (int j = 2; i * j <= SIEVE_N; j++)
                isp[i * j] = false;
    }
}

// int main()
// {
//     // N以下の整数に対して素数判定をしてくれます。
//     // nが素数ならば isp(n)=true、そうでなければ isp(n)=false
//     sieve();
//     // ex. 51から80までの素数を出力
//     for (int i = 51; i <= 80; i++)
//         if (isp[i])
//             cout << i << endl;
//     return 0;
// }