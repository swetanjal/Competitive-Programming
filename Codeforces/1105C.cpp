#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
long long int DP[MAXN][3];
int N;
long long int L, R;
long long mult1, mult2, mult3;
long long rec(int ind, int mod)
{
    if(ind == N)
    {
        if(mod == 0)
            return 1;
        return 0;
    }
    if(DP[ind][mod] != -1)
        return DP[ind][mod];
    DP[ind][mod] = (mult3 * rec(ind + 1, mod)) % MOD;
    DP[ind][mod] = (DP[ind][mod] + ((mult2 * rec(ind + 1, (mod - 2 + 3) % 3)) % MOD)) % MOD;
    DP[ind][mod] = (DP[ind][mod] + ((mult1 * rec(ind + 1, (mod - 1 + 3) % 3)) % MOD)) % MOD;
    return DP[ind][mod];
}

long long first(int mod)
{
    for(long long i = L; i <= R; ++i){
        if((i % 3) == mod)
            return i;
    }
    return -1;
}
long long second(int mod)
{
    for(long long i = R; i >= L; i--)
    {
        if((i % 3) == mod)
            return i;
    }
    return -1;
}

int main()
{
    cin >> N >> L >> R;
    for(int i = 0; i < MAXN; ++i)
        DP[i][0] = DP[i][1] = DP[i][2] = -1;
    if(first(0) != -1){
        mult3 = (second(0) - first(0)) / 3;
        mult3++;
    }
    if(first(2) != -1){
        mult2 = (second(2) - first(2)) / 3;
        mult2++;
    }
    if(first(1) != -1){
        mult1 = (second(1) - first(1)) / 3;
        mult1++;
    }
    //cout << mult1 << " " << mult2 << " " << mult3 << endl;
    cout << rec(0, 0) << endl;
    return 0;
}