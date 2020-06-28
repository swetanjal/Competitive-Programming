#include "bits/stdc++.h"
using namespace std;
int N;
int A[105];
int S[105];
long long int DP[105][105][105][2];

long long int rec(int idx, int e, int o, int prev)
{
    if(e < 0 || o < 0)
        return INT_MAX;
    if(idx == N)
        return 0;
    if(DP[idx][e][o][prev] != -1)
        return DP[idx][e][o][prev];
    if(S[idx] != 0){
        int add = 0;
        if((S[idx] % 2) != prev)
            add = 1;
        if(idx == 0)
            add = 0;
        return DP[idx][e][o][prev] = add + rec(idx + 1, e, o, S[idx] % 2);
    }
    else{
        if(prev == 0){
            if(idx == 0)
                return DP[idx][e][o][prev] = min(rec(idx + 1, e, o - 1, 1), rec(idx + 1, e - 1, o, 0));
            else    
                return DP[idx][e][o][prev] = min(1 + rec(idx + 1, e, o - 1, 1), rec(idx + 1, e - 1, o, 0));
        }
        else{
            if(idx == 0)
                return DP[idx][e][o][prev] = min(rec(idx + 1, e, o - 1, 1), rec(idx + 1, e - 1, o, 0));
            else
                return DP[idx][e][o][prev] = min(rec(idx + 1, e, o - 1, 1), 1 + rec(idx + 1, e - 1, o, 0));
        }
    }
}

int main()
{
    cin >> N;
    for(int i = 0; i <= N; ++i)
        for(int j = 0; j <= N; ++j)
            for(int k = 0; k <= N; ++k)
                DP[i][j][k][0] = DP[i][j][k][1] = -1;
    for(int i = 0; i < N; ++i){
        cin >> S[i];
        A[S[i]] = 1;
    }
    int odd = 0;
    int even = 0;
    for(int i = 1; i <= N; ++i){
        if(A[i] == 0 && (i % 2) == 0)
            even++;
        if(A[i] == 0 && (i % 2) != 0)
            odd++;
    }
    cout << min(rec(0, even, odd, 0), rec(0, even, odd, 1)) << endl;
    return 0;
}