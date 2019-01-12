#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
long long int DP[MAXN];
int N;
long long H[MAXN];
long long rec(int idx)
{
    if(idx == (N - 1))
    {
        return 0;
    }
    if(DP[idx] != -1)
        return DP[idx];
    if(idx == (N - 2))
        DP[idx] = rec(idx + 1) + abs(H[idx] - H[idx + 1]);
    else
        DP[idx] = min(rec(idx + 1) + abs(H[idx] - H[idx + 1]), rec(idx + 2) + abs(H[idx] - H[idx + 2]));
    return DP[idx];
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> H[i];
    for(int i = 0; i < N; ++i)
        DP[i] = -1;
    cout << rec(0) << endl;
    return 0;
}