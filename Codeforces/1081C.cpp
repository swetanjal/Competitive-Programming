#include "bits/stdc++.h"
using namespace std;
const long long MOD = 998244353;
const int MAXN = 2e3 + 5;
long long int N, M, K;
long long DP[MAXN][MAXN];

long long power(long long A, long long B)
{
    long long p = 1;
    for(int i = 1; i <= B; ++i)
        p = (p * A) % MOD;
    return p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < MAXN; ++i)
        DP[i][0] = 1;
    cin >> N >> M >> K;

    for(int i = 1; i < MAXN; ++i)
    {
        for(int j = 1; j < MAXN; ++j)
            DP[i][j] = (DP[i - 1][j] + DP[i - 1][j - 1]) % MOD;
    }
    cout << (((M * power(M - 1, K)) % MOD) * DP[N - 1][K]) % MOD << endl; 
    return 0;
}