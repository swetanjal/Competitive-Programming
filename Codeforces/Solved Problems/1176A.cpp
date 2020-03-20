#include "bits/stdc++.h"
using namespace std;
const long long INF = 2000000000000000000;
int T;
long long N;
map <long long, long long int > DP;
long long rec(long long N){
    if(N == 1)
        return 0;
    if(DP.find(N) != DP.end())
        return DP[N];
    DP[N] = INF;
    if((N % 2) == 0)
        DP[N] = 1 + rec(N / 2);
    else if((N % 3) == 0)
        DP[N] = min(DP[N], 2 + rec(N / 3));
    else if((N % 5) == 0)
        DP[N] = min(DP[N], 3 + rec(N / 5));
    if(DP[N] >= INF)
        DP[N] = INF;
    return DP[N];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        long long res = rec(N);
        if(res == INF)
            cout << "-1\n";
        else
            cout << res << endl;
    }
    return 0;
}