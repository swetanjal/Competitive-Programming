#include "bits/stdc++.h"
using namespace std;
const long long MOD = 998244353;
const int MAXN = 3e5 + 5;
int T, N, M;
vector <long long int> odd;
vector <long long int> even;
vector <int> edges[MAXN];
int color[MAXN];
long long int dfs(int node, int parity)
{
    int L = edges[node].size();
    color[node] = parity;
    long long int p = 1;
    for(int i = 0; i < L; ++i)
    {
        if(color[edges[node][i]] == -1)
        {
            p = (p * dfs(edges[node][i], 1 - parity)) % MOD;
        }
        else{
            if(parity == color[edges[node][i]])
            {
                return 0;
            }
        }
    }
    if(parity == 0)
        return p;
    return (2 * p) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        odd.clear();
        even.clear();
        for(int i = 1; i <= N; ++i){
            edges[i].clear();
            color[i] = -1;
        }
        for(int i = 1; i <= M; ++i)
        {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        for(int i = 1; i <= N; ++i)
        {
            if(color[i] == -1)
                odd.push_back(dfs(i, 1));
        }        
        for(int i = 1; i <= N; ++i)
            color[i] = -1;
        for(int i = 1; i <= N; ++i)
        {
            if(color[i] == -1)
                even.push_back(dfs(i, 0));
        }
        int sz = even.size();
        long long DP[sz];
        DP[sz - 1] = (even[sz - 1] + odd[sz - 1]) % MOD;
        for(int i = sz - 2; i >= 0; i--)
            DP[i] = ((even[i] * DP[i + 1]) % MOD + (odd[i] * DP[i + 1])) % MOD;
        cout << DP[0] << endl;
        //for(int i = 0; i < even.size(); ++i)
        //    cout << even[i] << " " << odd[i] << endl;
    }
    return 0;
}