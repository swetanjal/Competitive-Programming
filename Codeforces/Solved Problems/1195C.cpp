#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int N;
long long H1[MAXN];
long long H2[MAXN];
long long DP[MAXN][3];
long long rec(int idx, int lst){
    if(idx == N)
        return 0;
    if(DP[idx][lst] != -1)
        return DP[idx][lst];
    if(lst == 2)
        return DP[idx][lst] = max(rec(idx + 1, 1) + H2[idx], rec(idx + 1, 0) + H1[idx]);
    else if(lst == 1)
        return DP[idx][lst] = max(rec(idx + 1, 1 - lst) + H1[idx], rec(idx + 1, lst));
    else if(lst == 0)
        return DP[idx][lst] = max(rec(idx + 1, 1 - lst) + H2[idx], rec(idx + 1, lst));
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> H1[i];
    for(int i = 0; i < N; ++i)
        cin >> H2[i];
    for(int i = 0; i < MAXN; ++i)
        for(int j = 0; j <= 2; ++j)
            DP[i][j] = -1;
    cout << rec(0, 2) << endl;    
    return 0;
}