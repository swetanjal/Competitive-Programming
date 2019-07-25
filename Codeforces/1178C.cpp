#include "bits/stdc++.h"
using namespace std;
const long long MOD = 998244353;
int main()
{
    long long int R, C;
    cin >> R >> C;
    long long p = 2;
    for(int i = 1; i <= C; ++i)
        p = (p * 2) % MOD;
    for(int i = 1; i < R; ++i)
        p = (p * 2) % MOD;
    cout << p << endl;
    return 0;
}