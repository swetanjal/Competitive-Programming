#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
int N, u, v;
vector <int> edges[MAXN];
int comp[MAXN];
long long ans;
long long res;
void dfs1(int node, int parent){
    int L = edges[node].size();
    comp[node] = 1;
    for(int i = 0; i < L; ++i){
        if(edges[node][i] != parent){
            dfs1(edges[node][i], node);
            comp[node] += comp[edges[node][i]];
        }
    }
}

void dfs(int node, int parent)
{
    int L = edges[node].size();
    int prev_node = comp[node];
    int prev_parent = comp[parent];
    comp[parent] = comp[parent] - comp[node];
    ans = ans - comp[node];
    ans = ans - comp[node] + N;
    res = max(res, ans);
    comp[node] = N;
    for(int i = 0; i < L; ++i){
        if(edges[node][i] != parent)
            dfs(edges[node][i], node);
    }
    comp[node] = prev_node;
    comp[parent] = prev_parent;
    ans = ans - N + comp[node];
    ans = ans + comp[node];
}

int main()
{
    cin >> N;
    for(int i = 1; i < N; ++i){
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs1(1, -1);
    for(int i = 1; i <= N; ++i)
        ans += comp[i];
    int L = edges[1].size();
    res = ans;
    for(int i = 0; i < L; ++i)
        dfs(edges[1][i], 1);
    cout << res << endl;
    return 0;
}