#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
const long long MOD = 1e9 + 7;
int N, K;
bool visited[MAXN];
vector <int> edges[MAXN];
vector <int> color[MAXN];

long long power(long long a, long long b)
{
    long long prod = 1;
    for(int i = 1; i <= b; ++i)
        prod = (prod * a) % MOD;
    return prod;
}

long long dfs(int node)
{
    if(visited[node])
        return 0;
    visited[node] = true;
    int L = edges[node].size();
    long long tmp = 0;
    for(int i = 0; i < L; ++i){
        if(visited[edges[node][i]] == false && color[node][i] == 0)
            tmp = tmp + dfs(edges[node][i]);
    }
    return (tmp + 1);
}

int main()
{
    cin >> N >> K;
    for(int i = 1; i < N; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edges[u].push_back(v); color[u].push_back(c);
        edges[v].push_back(u); color[v].push_back(c);
    }
    long long res = power(N, K);
    for(int i = 1; i <= N; ++i){
        if(visited[i] == false){
            res = res -  power(dfs(i), K);
            while(res < 0)
                res += MOD;
        }
    }
    //while(res < 0)
    //    res += MOD;
    cout << res << endl;
    return 0;
}