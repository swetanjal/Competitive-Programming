#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e6 + 5;
int N, K;
string S;
long long int cost[MAXN];
long long int DP[MAXN];
long long int rec(int idx){
    if(idx >= N)
        return (cost[N - 1] - cost[idx - K]);
    if(DP[idx] != -1)
        return DP[idx];
    if(S[idx] == '1')
        return DP[idx] = min((cost[idx] - cost[idx - K]) + rec(idx + K) - 1, cost[idx] - cost[idx - K] - 1 + cost[N - 1] - cost[idx]);
    else
        return DP[idx] = min((cost[idx] - cost[idx - K]) + rec(idx + K) + 1, cost[idx] - cost[idx - K] + 1 + cost[N - 1] - cost[idx]);
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N >> K;
        cin >> S;
        long long int res = 1e18;
        for(int i = 0; i < N; ++i)
            cost[i] = 0;
        if(S[0] == '1')
            cost[0] = 1;
        for(int i = 1; i < N; ++i)
            cost[i] = cost[i - 1] + ((S[i] == '1') ? 1 : 0);
        for(int i = 0; i < N; ++i)
            DP[i] = -1;
        res = cost[N - 1];
        for(int i = 0; i < N; ++i){
            // Putting a 1 at ith location
            if(S[i] == '1'){
                res = min(res, cost[i] + rec(i + K) - 1);
                res = min(res, cost[i] + cost[N - 1] - cost[i] - 1);
            }
                
            else
            {
                res = min(res, 1 + cost[i] + rec(i + K));
                res = min(res, cost[i] + cost[N - 1] - cost[i] + 1);
            }
        }
        cout << res << endl;
    }
    return 0;
}