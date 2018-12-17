#include "bits/stdc++.h"
using namespace std;
const int MAXN = 3e5 + 5;
vector <int> edges[MAXN];
vector <long long> cost[MAXN];
long long A[MAXN];
int N;
long long DP[MAXN];
long long DP2[MAXN];
void dfs(int node, int parent)
{
    int L = edges[node].size();
    DP[node] = A[node];
    long long int max_best = 0;
    vector <long long> tmp;
    for(int i = 0; i < L; ++i)
    {
        if(edges[node][i] != parent){
            dfs(edges[node][i], node);
            if(DP[edges[node][i]] - cost[node][i] > 0){
                max_best = max(max_best, DP[edges[node][i]] - cost[node][i]);
                tmp.push_back(DP[edges[node][i]] - cost[node][i]);
            }
        }
    }
    sort(tmp.begin(), tmp.end());
    int sz = tmp.size();
    if(sz == 0)
    {
        DP2[node] = A[node];
    }
    else if(sz >= 2)
        DP2[node] = tmp[sz - 1] + tmp[sz - 2] + A[node];
    else
        DP2[node] = tmp[sz - 1] + A[node];
    DP[node] = DP[node] + max_best;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; ++i)
        cin >> A[i];
    for(int i = 1; i < N; ++i)
    {
        int u, v;
        cin >> u >> v;
        long long c;
        cin >> c;
        edges[u].push_back(v); cost[u].push_back(c);
        edges[v].push_back(u); cost[v].push_back(c);
    }
    dfs(1, -1);
    long long res = 0;
    for(int i = 1; i <= N; ++i)
        res = max(res, DP[i]);
    for(int i = 1; i <= N; ++i)
        res = max(res, DP2[i]);
    cout << res << endl;
    return 0;
}