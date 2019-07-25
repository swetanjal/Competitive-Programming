#include "bits/stdc++.h"
using namespace std;
const int MAXN = 3e5 + 5;
const int MAXM = 15;
long long int N, M, K;
long long int A[MAXN];
long long DP[MAXN][MAXM];
long long int rec(int idx, int rem)
{
    if(idx == N)
        return 0;
    if(DP[idx][rem] != -1)
        return DP[idx][rem];
    long long tmp = A[idx];
    if(rem == 0)
        DP[idx][rem] = max(0LL, rec(idx + 1, (rem + 1) % M) + tmp - K);
    else
        DP[idx][rem] = max(0LL, rec(idx + 1, (rem + 1) % M) + tmp);
    return DP[idx][rem];
}


int main()
{
    cin >> N >> M >> K;
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    for(int i = 0; i < MAXN; ++i)
        for(int j = 0; j < MAXM; ++j)
            DP[i][j] = -1;
    long long ans = 0;
    for(int i = 0; i < N; ++i)
        ans = max(ans, rec(i, 0));
    cout << ans << endl;
    return 0;
}