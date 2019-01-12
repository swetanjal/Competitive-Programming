#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
long long int DP[MAXN];
int N, K;
long long H[MAXN];
long long rec(int idx)
{
    if(idx == (N - 1))
    {
        return 0;
    }
    if(DP[idx] != -1)
        return DP[idx];
    DP[idx] = abs(H[idx] - H[idx + 1]) + rec(idx + 1);
    for(int i = 2; i <= K; ++i)
        if((idx + i) <= (N - 1))
            DP[idx] = min(DP[idx], abs(H[idx] - H[idx + i]) + rec(idx + i));
    return DP[idx];
}

int main()
{
    cin >> N >> K;
    for(int i = 0; i < N; ++i)
        cin >> H[i];
    for(int i = 0; i < N; ++i)
        DP[i] = -1;
    cout << rec(0) << endl;
    return 0;
}