#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1e9 + 7;
const int MAXN = 7.5e5 + 5;
int A[MAXN];
int N, T;
int exists[MAXN];
vector <int> edges[MAXN];
bool visited[MAXN];
long long DP[MAXN];
bool prime[MAXN];
long long dfs(int node)
{
    if(DP[node] != -1)
        return DP[node];
    DP[node] = 1;
    int L = edges[node].size();
    visited[node] = true;
    for(int i = 0; i < L; ++i){
        if(exists[edges[node][i]])
            DP[node] = (DP[node] + dfs(edges[node][i])) % MOD;
    }
    return DP[node];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for(int i = 1; i < MAXN; ++i){
        for(int j = i + i; j < MAXN; j += i)
            edges[j].push_back(i);
    }
    while(T--){
        cin >> N;
        for(int i = 0; i < MAXN; ++i)
            exists[i] = 0, DP[i] = -1;
        for(int i = 0; i < N; ++i)
        {
            cin >> A[i];
            exists[A[i]] = 1;
        }
        for(int i = 0; i < MAXN; ++i)
            visited[i] = false;
        long long ans = 0;
        for(int i = 1; i < MAXN; ++i){
            if(exists[i] && visited[i] == false)
                ans = (ans + dfs(i)) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}