#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int N;
long long A[MAXN];
long long DP[MAXN][2];

long long rec(int idx, int fl)
{
    if(idx == N)
        return 0;
    if(fl == 0)
        return 0;
    if(DP[idx][fl] != -1)
        return DP[idx][fl];
    return DP[idx][fl] = min(abs(A[idx] + rec(idx + 1, 1)), abs(A[idx] + rec(idx + 1, 0)))
}


int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    for(int i = 0; i < N; ++i)
        DP[i][0] = DP[i][1] = -1;
    cout << min(rec(0, 1), rec(0, 0)) << endl;
    return 0;
}