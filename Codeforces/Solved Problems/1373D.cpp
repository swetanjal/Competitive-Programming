/*
def rec(int idx, int lst, int done)
{
    
}
*/
#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
long long DP[MAXN][2][3];
int N, T;
long long A[MAXN];
long long int rec(int idx, int lst, int done)
{
    if(idx >= N)
    {
        return 0;
    }
    if(idx == (N - 1))
        return A[idx];
    if(DP[idx][lst][done] != -1)
        return DP[idx][lst][done];
    if(lst == 1){
        // Two options
        DP[idx][lst][done] = A[idx + 1] + rec(idx + 2, 1, done);
        DP[idx][lst][done] = max(DP[idx][lst][done], A[idx] + rec(idx + 2, 0, 1));
        return DP[idx][lst][done];
    }
    if(done){
        DP[idx][lst][done] = A[idx] + rec(idx + 2, lst, done);
        return DP[idx][lst][done];
    }
    if(done == 0 && lst == 0){
        DP[idx][lst][done] = A[idx + 1] + rec(idx + 2, 1, done);
        DP[idx][lst][done] = max(DP[idx][lst][done], A[idx] + rec(idx + 2, 0, 0));
        return DP[idx][lst][done];
    }
    assert(false);
}

long long int rec2(int idx, int lst, int done)
{
    if(idx >= N)
    {
        // cout << idx << endl;
        return 0;
    }
    if(DP[idx][lst][done] != -1)
        return DP[idx][lst][done];
    if(idx == 0)
    {
        DP[idx][lst][done] = A[idx] + rec2(idx + 2, lst, done);
        return DP[idx][lst][done];
    }
    if(lst == 1){
        // Two options
        DP[idx][lst][done] = A[idx - 1] + rec2(idx + 2, 1, done);
        DP[idx][lst][done] = max(DP[idx][lst][done], A[idx] + rec2(idx + 2, 0, 1));
        return DP[idx][lst][done];
    }
    if(done){
        DP[idx][lst][done] = A[idx] + rec2(idx + 2, lst, done);
        return DP[idx][lst][done];
    }
    if(done == 0 && lst == 0){
        DP[idx][lst][done] = A[idx - 1] + rec2(idx + 2, 1, done);
        DP[idx][lst][done] = max(DP[idx][lst][done], A[idx] + rec2(idx + 2, 0, 0));
        return DP[idx][lst][done];
    }
    assert(false);
}

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i = 0; i < N; ++i)
            cin >> A[i];
        for(int i = 0; i < N; ++i){
            for(int j = 0; j <= 1; ++j)
                for(int k = 0; k <= 1; ++k)
                    DP[i][j][k] = -1;
        }
        long long int a1 = rec(0, 0, 0);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j <= 1; ++j)
                for(int k = 0; k <= 1; ++k)
                    DP[i][j][k] = -1;
        }
        long long int a2 = rec2(0, 0, 0);
        cout << max(a1, a2) << endl;
    }
    return 0;
}