#include "bits/stdc++.h"
using namespace std;
const long long MOD = 998244353;
const int MAXN = 2e5 + 5;
long long int P[MAXN];
int main()
{
    int N;
    cin >> N;
    if(N == 1){
        cout << "10\n";
        return 0;
    }
    P[0] = 1;
    for(int i = 1; i < MAXN; ++i)
        P[i] = (P[i - 1] * 10) % MOD;
    
    for(int i = 1; i <= N; ++i){
        long long a = 0; long long b;
        if((N - i - 1) >= 0)
            a = (((9LL * 9LL * P[N - i - 1]) % MOD) * 1LL * (N - i - 1)) % MOD;
        else
        {
            cout << "10 ";
            continue;
        }
        b = (9LL * P[N - i]) % MOD;
        if((N - i + 1) > 1)
            b = (b * 2) % MOD;
        cout << ((a + b) % MOD) << " ";
    }
    cout << "\n";
    return 0;
}