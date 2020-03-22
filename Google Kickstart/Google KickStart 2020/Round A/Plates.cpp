#include "bits/stdc++.h"
using namespace std;
const long long inf = -1e6;
const int MAXN = 50;
int A[MAXN][MAXN];
int T, N, K, P;
long long int DP[MAXN][MAXN * MAXN];
long long int rec(int idx, int rem){
    if(rem < 0)
        return inf;
    if(idx == N && rem == 0)
        return 0;
    if(idx == N)
        return inf;
    if(DP[idx][rem] != -1000000000000000)
        return DP[idx][rem];
    long long s = 0;
    DP[idx][rem] = rec(idx + 1, rem);
    for(int i = 0; i < K; ++i){
        s += A[idx][i];
        DP[idx][rem] = max(DP[idx][rem], s + rec(idx + 1, rem - (i + 1)));
    }
    return DP[idx][rem];
}

int main()
{
    cin >> T;
    for(int cases = 1; cases <= T; ++cases){
        cin >> N >> K >> P;
        for(int i = 0; i <= N; ++i)
            for(int j = 0; j <= P; ++j)
                DP[i][j] = -1000000000000000;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < K; ++j)
                cin >> A[i][j];
        }
        cout << "Case #" << cases << ": " << rec(0, P) << endl;
    }
    return 0;
}