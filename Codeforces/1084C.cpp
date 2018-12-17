#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
const long long MOD = 1e9 + 7;
string S;
int L;
int next_a[MAXN];
int next_b[MAXN];
int main()
{
    cin >> S;
    L = S.size();
    int posa = -1;
    int posb = -1;
    for(int i = L - 1; i >= 0; i--)
    {
        if(S[i] == 'a')
        {
            posa = i;
            break;
        }
    }
    for(int i = L - 1; i >= 0; i --)
    {
        if(S[i] == 'b')
        {
            posb = i;
            break;
        }
    }
    if(posa == -1)
    {
        cout << "0\n";
        return 0;
    }
    for(int i = 0; i < L; ++i)
        next_a[i] = next_b[i] = -1;
    int idx = posa;
    for(int i = posa - 1; i >= 0; i--)
    {
        next_a[i] = idx;
        if(S[i] == 'a')
            idx = i;
    }    
    idx = posb;
    for(int i = posb - 1; i >= 0; i--)
    {
        next_b[i] = idx;
        if(S[i] == 'b')
            idx = i;
    }
    long long DP[L];
    long long cum[L];
    if(S[L - 1] == 'a'){
        DP[L - 1] = 1;
        cum[L - 1] = 1;
    }
    else{
        DP[L - 1] = 0;
        cum[L - 1] = 0;
    }
    for(int i = L - 2; i >= 0; i--)
    {
        if(S[i] == 'a')
        {
            DP[i] = 1;
            if(next_b[i] != -1)
                DP[i] = (DP[i] + cum[next_b[i]]) % MOD;
            cum[i] = (cum[i + 1] + DP[i]) % MOD;
        }
        else{
            DP[i] = DP[i + 1];
            cum[i] = cum[i + 1];
        }
    }
    long long sum = 0;
    for(int i = 0; i < L; ++i)
    {
        if(S[i] == 'a')
            sum  = (sum + DP[i]) % MOD;
    }
    cout << sum << endl;
    return 0;
}