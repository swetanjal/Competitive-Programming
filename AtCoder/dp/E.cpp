#include "bits/stdc++.h"
using namespace std;
const long long inf = 1e18;
const int MAXN = 105;
const int MAXV = 1e3 + 5;
long long DP[MAXN][MAXN * MAXV];
int N;
long long W;
long long V[MAXN];
long long wt[MAXN];
long long rec(int idx, int value)
{
    if(idx == N){
        if(value == 0)
            return 0;
        return inf;
    }
    if(DP[idx][value] != -1)
        return DP[idx][value];
    return DP[idx][value] = min(wt[idx] + rec(idx + 1, value - V[idx]), rec(idx + 1, value));
}

int main()
{
    cin >> N >> W;
    for(int i = 0; i < N; ++i)
        cin >> wt[i] >> V[i];
    for(int j = 0; j < MAXN; ++j)
        for(int i = 0; i < MAXN * MAXV; ++i)
            DP[j][i] = -1;
    for(int i = 1; i < MAXN * MAXV; ++i)
        rec(0, i);
    for(int i = (MAXN * MAXV) - 1; i >= 0; --i)
    {
        if(DP[0][i] <= W)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}