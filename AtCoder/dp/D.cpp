#include "bits/stdc++.h"
using namespace std;
const int MAXN = 105;
const int MAXW = 1e5 + 5;
const long long int neg_inf = -1e18;
int N, W;
long long int DP[MAXN][MAXW];
long long wt[MAXN];
long long V[MAXN];

long long rec(int idx, int weight)
{
    if (idx == N)
    {
        if (weight <= W)
            return 0;
        return neg_inf;
    }
    if (weight > W)
        return neg_inf;
    if (DP[idx][weight] != -1)
        return DP[idx][weight];
    return DP[idx][weight] = max(V[idx] + rec(idx + 1, weight + wt[idx]), rec(idx + 1, weight));
}

int main()
{
    cin >> N >> W;
    for (int i = 0; i < N; ++i)
        cin >> wt[i] >> V[i];
    for (int i = 0; i < MAXN; ++i)
        for (int j = 0; j < MAXW; ++j)
            DP[i][j] = -1;
    cout << rec(0, 0) << endl;
    return 0;
}