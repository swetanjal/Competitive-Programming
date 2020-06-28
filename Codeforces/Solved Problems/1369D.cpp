#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1e9 + 7;
const int MAXN = 2e6 + 5;
long long int Z[MAXN];
long long int O[MAXN];
long long int G[MAXN];
int T, N;
int main()
{
    Z[1] = 1; O[1] = 0; G[1] = 0;
    Z[2] = 1; O[2] = 1; G[2] = 0;
    Z[3] = 3; O[3] = 1; G[3] = 1;
    Z[4] = 5; O[4] = 3; G[4] = 1;
    for(int i = 5; i < MAXN; ++i){
        Z[i] = (Z[i - 1] + ((2 * O[i - 1])%MOD) )%MOD;
        O[i] = Z[i - 1];
        G[i] = (G[i - 3] + O[i - 1])%MOD;
    }
    cin >> T;
    while(T--)
    {
        cin >> N;
        cout << (4*G[N])%MOD << endl;
    }
    return 0;
}